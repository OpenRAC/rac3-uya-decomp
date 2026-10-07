/* i5bootn: libgcc, fp-bit.o: fp-bit.c built with -DFLOAT. The linker
   dead-stripped everything but __pack_f, __unpack_f, __make_fp and fptodp;
   func_00804ED0 and func_00804EF8 are the last words of the stripped ones.
   From GCC 2.95.2's gcc/config/fp-bit.c, built the way Sony's prebuilt
   libgcc.a was: with Sony's ee-gcc 2.9-ee-991111 (@ee29 in
   targets/i5bootn/text_parts.txt). Changes from GCC's text are marked
   "i5bootn:". See src/libgcc/README.md.  */

/* GCC 2.95.2 gcc/config/fp-bit.c:
   Copyright (C) 1994, 1995, 1996, 1997, 1998 Free Software Foundation, Inc.

This file is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file with other programs, and to distribute
those programs without any restriction coming from the use of this
file.  (The General Public License restrictions do apply in other
respects; for example, they cover modification of the file, and
distribution when not linked into another program.)

This file is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* As a special exception, if you link this library with other files,
   some of which are compiled with GCC, to produce an executable,
   this library does not by itself cause the resulting executable
   to be covered by the GNU General Public License.
   This exception does not however invalidate any other reasons why
   the executable file might be covered by the GNU General Public License.  */

#include "common.h"

/* Sony's libgcc.a builds fp-bit.c with these (docs/compiler_matrix_i5bootn.md):
   the US Software GOFAST names (fpadd, ...), little-endian bitfields, and
   no denormals on the EE (unpack_d).  */
#define FLOAT
#define US_SOFTWARE_GOFAST
#define FLOAT_BIT_ORDER_MISMATCH
#define NO_DENORMALS
/* (if a function here needs nan(), define FP_THENAN as the D_ name of its
   static object first; see fp-bit.h) */
/* the names the functions call each other by (see fp-bit.h) */
#define FP_NAME_pack_d func_00804D30
#define FP_NAME_unpack_d func_00804E40
#define FP_NAME___make_dp func_00804CA8
#define FP_NAME___make_fp func_00804F00
#include "src/libgcc/fp-bit.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00804D30 */
/* pack_d (__pack_f) */
FLO_type func_00804D30 ( fp_number_type *  src)
{
  FLO_union_type dst;
  fractype fraction = src->fraction.ll;	/* wasn't unsigned before? */
  int sign = src->sign;
  int exp = 0;

  if (isnan (src))
    {
      exp = EXPMAX;
      if (src->class == CLASS_QNAN || 1)
	{
	  fraction |= QUIET_NAN;
	}
    }
  else if (isinf (src))
    {
      exp = EXPMAX;
      fraction = 0;
    }
  else if (iszero (src))
    {
      exp = 0;
      fraction = 0;
    }
  else if (fraction == 0)
    {
      exp = 0;
    }
  else
    {
      if (src->normal_exp < NORMAL_EXPMIN)
	{
	  /* This number's exponent is too low to fit into the bits
	     available in the number, so we'll store 0 in the exponent and
	     shift the fraction to the right to make up for it.  */

	  int shift = NORMAL_EXPMIN - src->normal_exp;

	  exp = 0;

	  if (shift > FRAC_NBITS - NGARDS)
	    {
	      /* No point shifting, since it's more that 64 out.  */
	      fraction = 0;
	    }
	  else
	    {
	      /* Shift by the value */
	      fraction >>= shift;
	    }
	  fraction >>= NGARDS;
	}
      else if (src->normal_exp > EXPBIAS)
	{
	  exp = EXPMAX;
	  fraction = 0;
	}
      else
	{
	  exp = src->normal_exp + EXPBIAS;
	  /* IF the gard bits are the all zero, but the first, then we're
	     half way between two numbers, choose the one which makes the
	     lsb of the answer 0.  */
	  if ((fraction & GARDMASK) == GARDMSB)
	    {
	      if (fraction & (1 << NGARDS))
		fraction += GARDROUND + 1;
	    }
	  else
	    {
	      /* Add a one to the guards to round up */
	      fraction += GARDROUND;
	    }
	  if (fraction >= IMPLICIT_2)
	    {
	      fraction >>= 1;
	      exp += 1;
	    }
	  fraction >>= NGARDS;
	}
    }

  /* We previously used bitfields to store the number, but this doesn't
     handle little/big endian systems conveniently, so use shifts and
     masks */
#ifdef FLOAT_BIT_ORDER_MISMATCH
  dst.bits.fraction = fraction;
  dst.bits.exp = exp;
  dst.bits.sign = sign;
#else
  dst.value_raw = fraction & ((((fractype)1) << FRACBITS) - (fractype)1);
  dst.value_raw |= ((fractype) (exp & ((1 << EXPBITS) - 1))) << FRACBITS;
  dst.value_raw |= ((fractype) (sign & 1)) << (FRACBITS | EXPBITS);
#endif

#if defined(FLOAT_WORD_ORDER_MISMATCH) && !defined(FLOAT)
  {
    halffractype tmp = dst.words[0];
    dst.words[0] = dst.words[1];
    dst.words[1] = tmp;
  }
#endif

  return dst.value;
}
/* localdecomp:end func_00804D30 */

/* localdecomp:start func_00804E40 */
extern void unpack_d (FLO_union_type *, fp_number_type *);

/* unpack_d (__unpack_f) */
void func_00804E40 (FLO_union_type * src, fp_number_type * dst)
{
  /* We previously used bitfields to store the number, but this doesn't
     handle little/big endian systems conveniently, so use shifts and
     masks */
  fractype fraction;
  int exp;
  int sign;

#if defined(FLOAT_WORD_ORDER_MISMATCH) && !defined(FLOAT)
  FLO_union_type swapped;

  swapped.words[0] = src->words[1];
  swapped.words[1] = src->words[0];
  src = &swapped;
#endif
  
#ifdef FLOAT_BIT_ORDER_MISMATCH
  fraction = src->bits.fraction;
  exp = src->bits.exp;
  sign = src->bits.sign;
#else
  fraction = src->value_raw & ((((fractype)1) << FRACBITS) - (fractype)1);
  exp = ((int)(src->value_raw >> FRACBITS)) & ((1 << EXPBITS) - 1);
  sign = ((int)(src->value_raw >> (FRACBITS + EXPBITS))) & 1;
#endif

  dst->sign = sign;
  if (exp == 0)
    {
      /* Hmm.  Looks like 0 */
      /* i5bootn: Sony's no-denormals test (NO_DENORMALS, as later GCC
	 has it): every zero exponent is a zero.  */
      if (fraction == 0
#ifdef NO_DENORMALS
	  || 1
#endif
	  )
	{
	  /* tastes like zero */
	  dst->class = CLASS_ZERO;
	}
      else
	{
	  /* Zero exponent with non zero fraction - it's denormalized,
	     so there isn't a leading implicit one - we'll shift it so
	     it gets one.  */
	  dst->normal_exp = exp - EXPBIAS + 1;
	  fraction <<= NGARDS;

	  dst->class = CLASS_NUMBER;
#if 1
	  while (fraction < IMPLICIT_1)
	    {
	      fraction <<= 1;
	      dst->normal_exp--;
	    }
#endif
	  dst->fraction.ll = fraction;
	}
    }
  else if (exp == EXPMAX)
    {
      /* Huge exponent*/
      if (fraction == 0)
	{
	  /* Attached to a zero fraction - means infinity */
	  dst->class = CLASS_INFINITY;
	}
      else
	{
	  /* Non zero fraction, means nan */
	  if (fraction & QUIET_NAN)
	    {
	      dst->class = CLASS_QNAN;
	    }
	  else
	    {
	      dst->class = CLASS_SNAN;
	    }
	  /* Keep the fraction part as the nan number */
	  dst->fraction.ll = fraction;
	}
    }
  else
    {
      /* Nothing strange about this number */
      dst->normal_exp = exp - EXPBIAS;
      dst->class = CLASS_NUMBER;
      dst->fraction.ll = (fraction << NGARDS) | IMPLICIT_1;
    }
}
/* localdecomp:end func_00804E40 */

LINKER_REMNANT("asm/i5bootn/remnants", func_00804ED0);

LINKER_REMNANT("asm/i5bootn/remnants", func_00804EF8);

/* localdecomp:start func_00804F00 */
/* __make_fp */
SFtype func_00804F00 (fp_class_type class,
	     unsigned int sign,
	     int exp, 
	     USItype frac)
{
  fp_number_type in;

  in.class = class;
  in.sign = sign;
  in.normal_exp = exp;
  in.fraction.ll = frac;
  return pack_d (&in);
}
/* localdecomp:end func_00804F00 */

/* localdecomp:start func_00804F30 */
extern DFtype __make_dp (fp_class_type, unsigned int, int, UDItype frac);

/* sf_to_df (fptodp) */
DFtype func_00804F30 (SFtype arg_a)
{
  fp_number_type in;

  unpack_d ((FLO_union_type *) & arg_a, &in);
  return __make_dp (in.class, in.sign, in.normal_exp,
		    ((UDItype) in.fraction.ll) << F_D_BITOFF);
}
/* localdecomp:end func_00804F30 */
