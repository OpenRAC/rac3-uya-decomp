/* i5bootn: libgcc, dp-bit.o: fp-bit.c built for double. The linker dead-
   stripped dptoli (its last word is func_00804C00) and __negdf2 (nothing
   left).
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
   the US Software GOFAST names (dpadd, ...), little-endian bitfields, and
   no denormals on the EE (unpack_d).  */
#define US_SOFTWARE_GOFAST
#define FLOAT_BIT_ORDER_MISMATCH
#define NO_DENORMALS
/* i5bootn: nan()'s static object, in .bss (see fp-bit.h) */
#define FP_THENAN D_008C5ED8
/* the names the functions call each other by (see fp-bit.h) */
#define FP_NAME_pack_d func_00804100
#define FP_NAME_unpack_d func_00804230
#define FP_NAME__fpadd_parts func_008042D0
#define FP_NAME___fpcmp_parts func_008049E0
#define FP_NAME___make_dp func_00804CA8
#define FP_NAME___make_fp func_00804F00
#include "src/libgcc/fp-bit.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00804100 */
/* pack_d (__pack_d) */
FLO_type func_00804100 ( fp_number_type *  src)
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
/* localdecomp:end func_00804100 */

/* localdecomp:start func_00804230 */
extern void unpack_d (FLO_union_type *, fp_number_type *);

/* unpack_d (__unpack_d) */
void func_00804230 (FLO_union_type * src, fp_number_type * dst)
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
/* localdecomp:end func_00804230 */

/* localdecomp:start func_008042D0 */
/* _fpadd_parts */
static fp_number_type * func_008042D0 (fp_number_type * a,
	      fp_number_type * b,
	      fp_number_type * tmp)
{
  intfrac tfraction;

  /* Put commonly used fields in local variables.  */
  int a_normal_exp;
  int b_normal_exp;
  fractype a_fraction;
  fractype b_fraction;

  if (isnan (a))
    {
      return a;
    }
  if (isnan (b))
    {
      return b;
    }
  if (isinf (a))
    {
      /* Adding infinities with opposite signs yields a NaN.  */
      if (isinf (b) && a->sign != b->sign)
	return nan ();
      return a;
    }
  if (isinf (b))
    {
      return b;
    }
  if (iszero (b))
    {
      if (iszero (a))
	{
	  *tmp = *a;
	  tmp->sign = a->sign & b->sign;
	  return tmp;
	}
      return a;
    }
  if (iszero (a))
    {
      return b;
    }

  /* Got two numbers. shift the smaller and increment the exponent till
     they're the same */
  {
    int diff;

    a_normal_exp = a->normal_exp;
    b_normal_exp = b->normal_exp;
    a_fraction = a->fraction.ll;
    b_fraction = b->fraction.ll;

    diff = a_normal_exp - b_normal_exp;

    if (diff < 0)
      diff = -diff;
    if (diff < FRAC_NBITS)
      {
	/* ??? This does shifts one bit at a time.  Optimize.  */
	while (a_normal_exp > b_normal_exp)
	  {
	    b_normal_exp++;
	    LSHIFT (b_fraction);
	  }
	while (b_normal_exp > a_normal_exp)
	  {
	    a_normal_exp++;
	    LSHIFT (a_fraction);
	  }
      }
    else
      {
	/* Somethings's up.. choose the biggest */
	if (a_normal_exp > b_normal_exp)
	  {
	    b_normal_exp = a_normal_exp;
	    b_fraction = 0;
	  }
	else
	  {
	    a_normal_exp = b_normal_exp;
	    a_fraction = 0;
	  }
      }
  }

  if (a->sign != b->sign)
    {
      if (a->sign)
	{
	  tfraction = -a_fraction + b_fraction;
	}
      else
	{
	  tfraction = a_fraction - b_fraction;
	}
      if (tfraction >= 0)
	{
	  tmp->sign = 0;
	  tmp->normal_exp = a_normal_exp;
	  tmp->fraction.ll = tfraction;
	}
      else
	{
	  tmp->sign = 1;
	  tmp->normal_exp = a_normal_exp;
	  tmp->fraction.ll = -tfraction;
	}
      /* and renormalize it */

      while (tmp->fraction.ll < IMPLICIT_1 && tmp->fraction.ll)
	{
	  tmp->fraction.ll <<= 1;
	  tmp->normal_exp--;
	}
    }
  else
    {
      tmp->sign = a->sign;
      tmp->normal_exp = a_normal_exp;
      tmp->fraction.ll = a_fraction + b_fraction;
    }
  tmp->class = CLASS_NUMBER;
  /* Now the fraction is added, we have to shift down to renormalize the
     number */

  if (tmp->fraction.ll >= IMPLICIT_2)
    {
      LSHIFT (tmp->fraction.ll);
      tmp->normal_exp++;
    }
  return tmp;

}
/* localdecomp:end func_008042D0 */

/* localdecomp:start func_00804510 */
/* add (dpadd) */
FLO_type func_00804510 (FLO_type arg_a, FLO_type arg_b)
{
  fp_number_type a;
  fp_number_type b;
  fp_number_type tmp;
  fp_number_type *res;

  unpack_d ((FLO_union_type *) & arg_a, &a);
  unpack_d ((FLO_union_type *) & arg_b, &b);

  res = _fpadd_parts (&a, &b, &tmp);

  return pack_d (res);
}
/* localdecomp:end func_00804510 */

/* localdecomp:start func_00804568 */
/* sub (dpsub) */
FLO_type func_00804568 (FLO_type arg_a, FLO_type arg_b)
{
  fp_number_type a;
  fp_number_type b;
  fp_number_type tmp;
  fp_number_type *res;

  unpack_d ((FLO_union_type *) & arg_a, &a);
  unpack_d ((FLO_union_type *) & arg_b, &b);

  b.sign ^= 1;

  res = _fpadd_parts (&a, &b, &tmp);

  return pack_d (res);
}
/* localdecomp:end func_00804568 */

/* localdecomp:start func_008045D0 */
static INLINE fp_number_type *
_fpmul_parts ( fp_number_type *  a,
	       fp_number_type *  b,
	       fp_number_type * tmp)
{
  fractype low = 0;
  fractype high = 0;

  if (isnan (a))
    {
      a->sign = a->sign != b->sign;
      return a;
    }
  if (isnan (b))
    {
      b->sign = a->sign != b->sign;
      return b;
    }
  if (isinf (a))
    {
      if (iszero (b))
	return nan ();
      a->sign = a->sign != b->sign;
      return a;
    }
  if (isinf (b))
    {
      if (iszero (a))
	{
	  return nan ();
	}
      b->sign = a->sign != b->sign;
      return b;
    }
  if (iszero (a))
    {
      a->sign = a->sign != b->sign;
      return a;
    }
  if (iszero (b))
    {
      b->sign = a->sign != b->sign;
      return b;
    }

  /* Calculate the mantissa by multiplying both 64bit numbers to get a
     128 bit number */
  {
#if defined(NO_DI_MODE)
    {
      fractype x = a->fraction.ll;
      fractype ylow = b->fraction.ll;
      fractype yhigh = 0;
      int bit;

      /* ??? This does multiplies one bit at a time.  Optimize.  */
      for (bit = 0; bit < FRAC_NBITS; bit++)
	{
	  int carry;

	  if (x & 1)
	    {
	      carry = (low += ylow) < ylow;
	      high += yhigh + carry;
	    }
	  yhigh <<= 1;
	  if (ylow & FRACHIGH)
	    {
	      yhigh |= 1;
	    }
	  ylow <<= 1;
	  x >>= 1;
	}
    }
#elif defined(FLOAT) 
    {
      /* Multiplying two 32 bit numbers to get a 64 bit number  on 
        a machine with DI, so we're safe */

      DItype answer = (DItype)(a->fraction.ll) * (DItype)(b->fraction.ll);
      
      high = answer >> 32;
      low = answer;
    }
#else
    /* Doing a 64*64 to 128 */
    {
      UDItype nl = a->fraction.ll & 0xffffffff;
      UDItype nh = a->fraction.ll >> 32;
      UDItype ml = b->fraction.ll & 0xffffffff;
      UDItype mh = b->fraction.ll >>32;
      UDItype pp_ll = ml * nl;
      UDItype pp_hl = mh * nl;
      UDItype pp_lh = ml * nh;
      UDItype pp_hh = mh * nh;
      UDItype res2 = 0;
      UDItype res0 = 0;
      UDItype ps_hh__ = pp_hl + pp_lh;
      if (ps_hh__ < pp_hl)
	res2 += 0x100000000LL;
      pp_hl = (ps_hh__ << 32) & 0xffffffff00000000LL;
      res0 = pp_ll + pp_hl;
      if (res0 < pp_ll)
	res2++;
      res2 += ((ps_hh__ >> 32) & 0xffffffffL) + pp_hh;
      high = res2;
      low = res0;
    }
#endif
  }

  tmp->normal_exp = a->normal_exp + b->normal_exp;
  tmp->sign = a->sign != b->sign;
#ifdef FLOAT
  tmp->normal_exp += 2;		/* ??????????????? */
#else
  tmp->normal_exp += 4;		/* ??????????????? */
#endif
  while (high >= IMPLICIT_2)
    {
      tmp->normal_exp++;
      if (high & 1)
	{
	  low >>= 1;
	  low |= FRACHIGH;
	}
      high >>= 1;
    }
  while (high < IMPLICIT_1)
    {
      tmp->normal_exp--;

      high <<= 1;
      if (low & FRACHIGH)
	high |= 1;
      low <<= 1;
    }
  /* rounding is tricky. if we only round if it won't make us round later. */
#if 0
  if (low & FRACHIGH2)
    {
      if (((high & GARDMASK) != GARDMSB)
	  && (((high + 1) & GARDMASK) == GARDMSB))
	{
	  /* don't round, it gets done again later. */
	}
      else
	{
	  high++;
	}
    }
#endif
  if ((high & GARDMASK) == GARDMSB)
    {
      if (high & (1 << NGARDS))
	{
	  /* half way, so round to even */
	  high += GARDROUND + 1;
	}
      else if (low)
	{
	  /* but we really weren't half way */
	  high += GARDROUND + 1;
	}
    }
  tmp->fraction.ll = high;
  tmp->class = CLASS_NUMBER;
  return tmp;
}

/* multiply (dpmul) */
FLO_type func_008045D0 (FLO_type arg_a, FLO_type arg_b)
{
  fp_number_type a;
  fp_number_type b;
  fp_number_type tmp;
  fp_number_type *res;

  unpack_d ((FLO_union_type *) & arg_a, &a);
  unpack_d ((FLO_union_type *) & arg_b, &b);

  res = _fpmul_parts (&a, &b, &tmp);

  return pack_d (res);
}
/* localdecomp:end func_008045D0 */

/* localdecomp:start func_00804878 */
static INLINE fp_number_type *
_fpdiv_parts (fp_number_type * a,
	      fp_number_type * b)
{
  fractype bit;
  fractype numerator;
  fractype denominator;
  fractype quotient;

  if (isnan (a))
    {
      return a;
    }
  if (isnan (b))
    {
      return b;
    }

  a->sign = a->sign ^ b->sign;

  if (isinf (a) || iszero (a))
    {
      if (a->class == b->class)
	return nan ();
      return a;
    }

  if (isinf (b))
    {
      a->fraction.ll = 0;
      a->normal_exp = 0;
      return a;
    }
  if (iszero (b))
    {
      a->class = CLASS_INFINITY;
      return a;
    }

  /* Calculate the mantissa by multiplying both 64bit numbers to get a
     128 bit number */
  {
    /* quotient =
       ( numerator / denominator) * 2^(numerator exponent -  denominator exponent)
     */

    a->normal_exp = a->normal_exp - b->normal_exp;
    numerator = a->fraction.ll;
    denominator = b->fraction.ll;

    if (numerator < denominator)
      {
	/* Fraction will be less than 1.0 */
	numerator *= 2;
	a->normal_exp--;
      }
    bit = IMPLICIT_1;
    quotient = 0;
    /* ??? Does divide one bit at a time.  Optimize.  */
    while (bit)
      {
	if (numerator >= denominator)
	  {
	    quotient |= bit;
	    numerator -= denominator;
	  }
	bit >>= 1;
	numerator *= 2;
      }

    if ((quotient & GARDMASK) == GARDMSB)
      {
	if (quotient & (1 << NGARDS))
	  {
	    /* half way, so round to even */
	    quotient += GARDROUND + 1;
	  }
	else if (numerator)
	  {
	    /* but we really weren't half way, more bits exist */
	    quotient += GARDROUND + 1;
	  }
      }

    a->fraction.ll = quotient;
    return (a);
  }
}

/* divide (dpdiv) */
FLO_type func_00804878 (FLO_type arg_a, FLO_type arg_b)
{
  fp_number_type a;
  fp_number_type b;
  fp_number_type *res;

  unpack_d ((FLO_union_type *) & arg_a, &a);
  unpack_d ((FLO_union_type *) & arg_b, &b);

  res = _fpdiv_parts (&a, &b);

  return pack_d (res);
}
/* localdecomp:end func_00804878 */

/* localdecomp:start func_008049E0 */
int __fpcmp_parts (fp_number_type * a, fp_number_type *b);

/* according to the demo, fpcmp returns a comparison with 0... thus
   a<b -> -1
   a==b -> 0
   a>b -> +1
 */

/* __fpcmp_parts (__fpcmp_parts_d) */
int func_008049E0 (fp_number_type * a, fp_number_type * b)
{
#if 0
  /* either nan -> unordered. Must be checked outside of this routine. */
  if (isnan (a) && isnan (b))
    {
      return 1;			/* still unordered! */
    }
#endif

  if (isnan (a) || isnan (b))
    {
      return 1;			/* how to indicate unordered compare? */
    }
  if (isinf (a) && isinf (b))
    {
      /* +inf > -inf, but +inf != +inf */
      /* b    \a| +inf(0)| -inf(1)
       ______\+--------+--------
       +inf(0)| a==b(0)| a<b(-1)
       -------+--------+--------
       -inf(1)| a>b(1) | a==b(0)
       -------+--------+--------
       So since unordered must be non zero, just line up the columns...
       */
      return b->sign - a->sign;
    }
  /* but not both... */
  if (isinf (a))
    {
      return a->sign ? -1 : 1;
    }
  if (isinf (b))
    {
      return b->sign ? 1 : -1;
    }
  if (iszero (a) && iszero (b))
    {
      return 0;
    }
  if (iszero (a))
    {
      return b->sign ? 1 : -1;
    }
  if (iszero (b))
    {
      return a->sign ? -1 : 1;
    }
  /* now both are "normal". */
  if (a->sign != b->sign)
    {
      /* opposite signs */
      return a->sign ? -1 : 1;
    }
  /* same sign; exponents? */
  if (a->normal_exp > b->normal_exp)
    {
      return a->sign ? -1 : 1;
    }
  if (a->normal_exp < b->normal_exp)
    {
      return a->sign ? 1 : -1;
    }
  /* same exponents; check size. */
  if (a->fraction.ll > b->fraction.ll)
    {
      return a->sign ? -1 : 1;
    }
  if (a->fraction.ll < b->fraction.ll)
    {
      return a->sign ? 1 : -1;
    }
  /* after all that, they're equal. */
  return 0;
}
/* localdecomp:end func_008049E0 */

/* localdecomp:start func_00804AF8 */
/* compare (dpcmp) */
CMPtype func_00804AF8 (FLO_type arg_a, FLO_type arg_b)
{
  fp_number_type a;
  fp_number_type b;

  unpack_d ((FLO_union_type *) & arg_a, &a);
  unpack_d ((FLO_union_type *) & arg_b, &b);

  return __fpcmp_parts (&a, &b);
}
/* localdecomp:end func_00804AF8 */

/* localdecomp:start func_00804B48 */
/* si_to_float (litodp) */
FLO_type func_00804B48 (SItype arg_a)
{
  fp_number_type in;

  in.class = CLASS_NUMBER;
  in.sign = arg_a < 0;
  if (!arg_a)
    {
      in.class = CLASS_ZERO;
    }
  else
    {
      in.normal_exp = FRACBITS + NGARDS;
      if (in.sign) 
	{
	  /* Special case for minint, since there is no +ve integer
	     representation for it */
	  if (arg_a == (SItype) 0x80000000)
	    {
	      return -2147483648.0;
	    }
	  in.fraction.ll = (-arg_a);
	}
      else
	in.fraction.ll = arg_a;

      while (in.fraction.ll < (1LL << (FRACBITS + NGARDS)))
	{
	  in.fraction.ll <<= 1;
	  in.normal_exp -= 1;
	}
    }
  return pack_d (&in);
}
/* localdecomp:end func_00804B48 */

LINKER_REMNANT("asm/i5bootn/remnants", func_00804C00);

/* localdecomp:start func_00804C08 */
/* While libgcc2.c defines its own __fixunssfsi and __fixunsdfsi routines,
   we also define them for GOFAST because the ones in libgcc2.c have the
   wrong names and I'd rather define these here and keep GOFAST CYG-LOC's
   out of libgcc2.c.  We can't define these here if not GOFAST because then
   there'd be duplicate copies.  */

/* float_to_usi (dptoul) */
USItype func_00804C08 (FLO_type arg_a)
{
  fp_number_type a;

  unpack_d ((FLO_union_type *) & arg_a, &a);
  if (iszero (&a))
    return 0;
  if (isnan (&a))
    return 0;
  /* it is a negative number */
  if (a.sign)
    return 0;
  /* get reasonable MAX_USI_INT... */
  if (isinf (&a))
    return MAX_USI_INT;
  /* it is a number, but a small one */
  if (a.normal_exp < 0)
    return 0;
  if (a.normal_exp > 31)
    return MAX_USI_INT;
  else if (a.normal_exp > (FRACBITS + NGARDS))
    return a.fraction.ll << (a.normal_exp - (FRACBITS + NGARDS));
  else
    return a.fraction.ll >> ((FRACBITS + NGARDS) - a.normal_exp);
}
/* localdecomp:end func_00804C08 */

/* localdecomp:start func_00804CA8 */
/* __make_dp */
DFtype func_00804CA8 (fp_class_type class, unsigned int sign, int exp, UDItype frac)
{
  fp_number_type in;

  in.class = class;
  in.sign = sign;
  in.normal_exp = exp;
  in.fraction.ll = frac;
  return pack_d (&in);
}
/* localdecomp:end func_00804CA8 */

/* localdecomp:start func_00804CD8 */
extern SFtype __make_fp (fp_class_type, unsigned int, int, USItype);

/* df_to_sf (dptofp) */
SFtype func_00804CD8 (DFtype arg_a)
{
  fp_number_type in;
  USItype sffrac;

  unpack_d ((FLO_union_type *) & arg_a, &in);

  sffrac = in.fraction.ll >> F_D_BITOFF;

  /* We set the lowest guard bit in SFFRAC if we discarded any non
     zero bits.  */
  if ((in.fraction.ll & (((USItype) 1 << F_D_BITOFF) - 1)) != 0)
    sffrac |= 1;

  return __make_fp (in.class, in.sign, in.normal_exp, sffrac);
}
/* localdecomp:end func_00804CD8 */
