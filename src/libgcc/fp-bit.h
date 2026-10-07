/* This is a software floating point library which can be used instead of
   the floating point routines in libgcc1.c for targets without hardware
   floating point. 
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

/* decomp: the shared opening part (everything before pack_d) of GCC
   2.95.2's gcc/config/fp-bit.c, for the dp-bit.c (double) and fp-bit.c
   (-DFLOAT) module files (src/<target>/.../libgcc/), which hold the
   functions of Sony's dp-bit.o and fp-bit.o. The text is GCC's; the changes
   are marked "decomp:". See src/libgcc/README.md.  */

#ifndef DECOMP_FP_BIT_H
#define DECOMP_FP_BIT_H


/* This implements IEEE 754 format arithmetic, but does not provide a
   mechanism for setting the rounding mode, or for generating or handling
   exceptions.

   The original code by Steve Chamberlain, hacked by Mark Eichin and Jim
   Wilson, all of Cygnus Support.  */

/* The intended way to use this file is to make two copies, add `#define FLOAT'
   to one copy, then compile both copies and add them to libgcc.a.  */

/* Defining FINE_GRAINED_LIBRARIES allows one to select which routines
   from this file are compiled via additional -D options.

   This avoids the need to pull in the entire fp emulation library
   when only a small number of functions are needed.

   If FINE_GRAINED_LIBRARIES is not defined, then compile every 
   suitable routine.  */
#ifndef FINE_GRAINED_LIBRARIES
#define L_pack_df
#define L_unpack_df
#define L_pack_sf
#define L_unpack_sf
#define L_addsub_sf
#define L_addsub_df
#define L_mul_sf
#define L_mul_df
#define L_div_sf
#define L_div_df
#define L_fpcmp_parts_sf
#define L_fpcmp_parts_df
#define L_compare_sf
#define L_compare_df
#define L_eq_sf
#define L_eq_df
#define L_ne_sf
#define L_ne_df
#define L_gt_sf
#define L_gt_df
#define L_ge_sf
#define L_ge_df
#define L_lt_sf
#define L_lt_df
#define L_le_sf
#define L_le_df
#define L_si_to_sf
#define L_si_to_df
#define L_sf_to_si
#define L_df_to_si
#define L_f_to_usi
#define L_df_to_usi
#define L_negate_sf
#define L_negate_df
#define L_make_sf
#define L_make_df
#define L_sf_to_df
#define L_df_to_sf
#endif

/* The following macros can be defined to change the behaviour of this file:
   FLOAT: Implement a `float', aka SFmode, fp library.  If this is not
     defined, then this file implements a `double', aka DFmode, fp library.
   FLOAT_ONLY: Used with FLOAT, to implement a `float' only library, i.e.
     don't include float->double conversion which requires the double library.
     This is useful only for machines which can't support doubles, e.g. some
     8-bit processors.
   CMPtype: Specify the type that floating point compares should return.
     This defaults to SItype, aka int.
   US_SOFTWARE_GOFAST: This makes all entry points use the same names as the
     US Software goFast library.  If this is not defined, the entry points use
     the same names as libgcc1.c.
   _DEBUG_BITFLOAT: This makes debugging the code a little easier, by adding
     two integers to the FLO_union_type.  
   NO_NANS: Disable nan and infinity handling
   SMALL_MACHINE: Useful when operations on QIs and HIs are faster
     than on an SI */

/* We don't currently support extended floats (long doubles) on machines
   without hardware to deal with them.

   These stubs are just to keep the linker from complaining about unresolved
   references which can be pulled in from libio & libstdc++, even if the
   user isn't using long doubles.  However, they may generate an unresolved
   external to abort if abort is not used by the function, and the stubs
   are referenced from within libc, since libgcc goes before and after the
   system library.  */

#ifdef EXTENDED_FLOAT_STUBS
__truncxfsf2 (){ abort(); }
__extendsfxf2 (){ abort(); }
__addxf3 (){ abort(); }
__divxf3 (){ abort(); }
__eqxf2 (){ abort(); }
__extenddfxf2 (){ abort(); }
__gtxf2 (){ abort(); }
__lexf2 (){ abort(); }
__ltxf2 (){ abort(); }
__mulxf3 (){ abort(); }
__negxf2 (){ abort(); }
__nexf2 (){ abort(); }
__subxf3 (){ abort(); }
__truncxfdf2 (){ abort(); }

__trunctfsf2 (){ abort(); }
__extendsftf2 (){ abort(); }
__addtf3 (){ abort(); }
__divtf3 (){ abort(); }
__eqtf2 (){ abort(); }
__extenddftf2 (){ abort(); }
__gttf2 (){ abort(); }
__letf2 (){ abort(); }
__lttf2 (){ abort(); }
__multf3 (){ abort(); }
__negtf2 (){ abort(); }
__netf2 (){ abort(); }
__subtf3 (){ abort(); }
__trunctfdf2 (){ abort(); }
__gexf2 (){ abort(); }
__fixxfsi (){ abort(); }
__floatsixf (){ abort(); }
#else	/* !EXTENDED_FLOAT_STUBS, rest of file */


typedef float SFtype __attribute__ ((mode (SF)));
typedef float DFtype __attribute__ ((mode (DF)));

typedef int HItype __attribute__ ((mode (HI)));
typedef int SItype __attribute__ ((mode (SI)));
typedef int DItype __attribute__ ((mode (DI)));

/* The type of the result of a fp compare */
#ifndef CMPtype
#define CMPtype SItype
#endif

typedef unsigned int UHItype __attribute__ ((mode (HI)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));

#define MAX_SI_INT   ((SItype) ((unsigned) (~0)>>1))
#define MAX_USI_INT  ((USItype) ~0)


#ifdef FLOAT_ONLY
#define NO_DI_MODE
#endif

#ifdef FLOAT
#	define NGARDS    7L
#	define GARDROUND 0x3f
#	define GARDMASK  0x7f
#	define GARDMSB   0x40
#	define EXPBITS 8
#	define EXPBIAS 127
#	define FRACBITS 23
#	define EXPMAX (0xff)
#	define QUIET_NAN 0x100000L
#	define FRAC_NBITS 32
#	define FRACHIGH  0x80000000L
#	define FRACHIGH2 0xc0000000L
#	define pack_d __pack_f
#	define unpack_d __unpack_f
#	define __fpcmp_parts __fpcmp_parts_f
	typedef USItype fractype;
	typedef UHItype halffractype;
	typedef SFtype FLO_type;
	typedef SItype intfrac;

#else
#	define PREFIXFPDP dp
#	define PREFIXSFDF df
#	define NGARDS 8L
#	define GARDROUND 0x7f
#	define GARDMASK  0xff
#	define GARDMSB   0x80
#	define EXPBITS 11
#	define EXPBIAS 1023
#	define FRACBITS 52
#	define EXPMAX (0x7ff)
#	define QUIET_NAN 0x8000000000000LL
#	define FRAC_NBITS 64
#	define FRACHIGH  0x8000000000000000LL
#	define FRACHIGH2 0xc000000000000000LL
#	define pack_d __pack_d
#	define unpack_d __unpack_d
#	define __fpcmp_parts __fpcmp_parts_d
	typedef UDItype fractype;
	typedef USItype halffractype;
	typedef DFtype FLO_type;
	typedef DItype intfrac;
#endif

#ifdef US_SOFTWARE_GOFAST
#	ifdef FLOAT
#		define add 		fpadd
#		define sub 		fpsub
#		define multiply 	fpmul
#		define divide 		fpdiv
#		define compare 		fpcmp
#		define si_to_float 	sitofp
#		define float_to_si 	fptosi
#		define float_to_usi 	fptoui
#		define negate 		__negsf2
#		define sf_to_df		fptodp
#		define dptofp 		dptofp
#else
#		define add 		dpadd
#		define sub 		dpsub
#		define multiply 	dpmul
#		define divide 		dpdiv
#		define compare 		dpcmp
#		define si_to_float 	litodp
#		define float_to_si 	dptoli
#		define float_to_usi 	dptoul
#		define negate 		__negdf2
#		define df_to_sf 	dptofp
#endif
#else
#	ifdef FLOAT
#		define add 		__addsf3
#		define sub 		__subsf3
#		define multiply 	__mulsf3
#		define divide 		__divsf3
#		define compare 		__cmpsf2
#		define _eq_f2 		__eqsf2
#		define _ne_f2 		__nesf2
#		define _gt_f2 		__gtsf2
#		define _ge_f2 		__gesf2
#		define _lt_f2 		__ltsf2
#		define _le_f2 		__lesf2
#		define si_to_float 	__floatsisf
#		define float_to_si 	__fixsfsi
#		define float_to_usi 	__fixunssfsi
#		define negate 		__negsf2
#		define sf_to_df		__extendsfdf2
#else
#		define add 		__adddf3
#		define sub 		__subdf3
#		define multiply 	__muldf3
#		define divide 		__divdf3
#		define compare 		__cmpdf2
#		define _eq_f2 		__eqdf2
#		define _ne_f2 		__nedf2
#		define _gt_f2 		__gtdf2
#		define _ge_f2 		__gedf2
#		define _lt_f2 		__ltdf2
#		define _le_f2 		__ledf2
#		define si_to_float 	__floatsidf
#		define float_to_si 	__fixdfsi
#		define float_to_usi 	__fixunsdfsi
#		define negate 		__negdf2
#		define df_to_sf		__truncdfsf2
#	endif
#endif


#ifndef INLINE
#define INLINE __inline__
#endif

/* Preserve the sticky-bit when shifting fractions to the right.  */
#define LSHIFT(a) { a = (a & 1) | (a >> 1); }

/* numeric parameters */
/* F_D_BITOFF is the number of bits offset between the MSB of the mantissa
   of a float and of a double. Assumes there are only two float types.
   (double::FRAC_BITS+double::NGARDS-(float::FRAC_BITS-float::NGARDS))
 */
#define F_D_BITOFF (52+8-(23+7))


#define NORMAL_EXPMIN (-(EXPBIAS)+1)
#define IMPLICIT_1 (1LL<<(FRACBITS+NGARDS))
#define IMPLICIT_2 (1LL<<(FRACBITS+1+NGARDS))

/* common types */

typedef enum
{
  CLASS_SNAN,
  CLASS_QNAN,
  CLASS_ZERO,
  CLASS_NUMBER,
  CLASS_INFINITY
} fp_class_type;

typedef struct
{
#ifdef SMALL_MACHINE
  char class;
  unsigned char sign;
  short normal_exp;
#else
  fp_class_type class;
  unsigned int sign;
  int normal_exp;
#endif

  union
    {
      fractype ll;
      halffractype l[2];
    } fraction;
} fp_number_type;

typedef union
{
  FLO_type value;
  fractype value_raw;

#ifndef FLOAT
  halffractype words[2];
#endif

#ifdef FLOAT_BIT_ORDER_MISMATCH
  struct
    {
      fractype fraction:FRACBITS __attribute__ ((packed));
      unsigned int exp:EXPBITS __attribute__ ((packed));
      unsigned int sign:1 __attribute__ ((packed));
    }
  bits;
#endif

#ifdef _DEBUG_BITFLOAT
  struct
    {
      unsigned int sign:1 __attribute__ ((packed));
      unsigned int exp:EXPBITS __attribute__ ((packed));
      fractype fraction:FRACBITS __attribute__ ((packed));
    }
  bits_big_endian;

  struct
    {
      fractype fraction:FRACBITS __attribute__ ((packed));
      unsigned int exp:EXPBITS __attribute__ ((packed));
      unsigned int sign:1 __attribute__ ((packed));
    }
  bits_little_endian;
#endif
}
FLO_union_type;


/* end of header */

/* IEEE "special" number predicates */

#ifdef NO_NANS

#define nan() 0
#define isnan(x) 0
#define isinf(x) 0
#else

INLINE
static fp_number_type *
nan ()
{
  /* decomp: `static fp_number_type thenan;` here; retail has it in .bss,
     which is not built from C, so the module file names it FP_THENAN (the
     code that takes its address is the same).  */
  extern fp_number_type FP_THENAN;

  return &FP_THENAN;
}

INLINE
static int
isnan ( fp_number_type *  x)
{
  return x->class == CLASS_SNAN || x->class == CLASS_QNAN;
}

INLINE
static int
isinf ( fp_number_type *  x)
{
  return x->class == CLASS_INFINITY;
}

#endif

INLINE
static int
iszero ( fp_number_type *  x)
{
  return x->class == CLASS_ZERO;
}

INLINE 
static void
flip_sign ( fp_number_type *  x)
{
  x->sign = !x->sign;
}

/* decomp: the repo names every function by its address (func_XXXXXXXX),
   and the module files define them under those names. A module file sets
   FP_NAME_<name> for the names fp-bit.c's functions call each other by,
   and these point them at its func_ names.  */
#ifdef FP_NAME_pack_d
#undef pack_d
#define pack_d FP_NAME_pack_d
#endif
#ifdef FP_NAME_unpack_d
#undef unpack_d
#define unpack_d FP_NAME_unpack_d
#endif
#ifdef FP_NAME__fpadd_parts
#define _fpadd_parts FP_NAME__fpadd_parts
#endif
#ifdef FP_NAME___fpcmp_parts
#undef __fpcmp_parts
#define __fpcmp_parts FP_NAME___fpcmp_parts
#endif
#ifdef FP_NAME___make_dp
#define __make_dp FP_NAME___make_dp
#endif
#ifdef FP_NAME___make_fp
#define __make_fp FP_NAME___make_fp
#endif

extern FLO_type pack_d ( fp_number_type * );

/* decomp: this closes fp-bit.c's `#ifdef EXTENDED_FLOAT_STUBS ... #else`,
   which in fp-bit.c runs to the end of the file (the module file holds the
   rest of it).  */
#endif /* !EXTENDED_FLOAT_STUBS */

#endif /* DECOMP_FP_BIT_H */
