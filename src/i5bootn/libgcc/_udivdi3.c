/* i5bootn: libgcc, L_udivdi3 module (__udivdi3).
   From GCC 2.95.2's gcc/libgcc2.c, built the way Sony's prebuilt
   libgcc.a was: with Sony's ee-gcc 2.9-ee-991111 (@ee29 in
   targets/i5bootn/text_parts.txt). Changes from GCC's text are marked
   "i5bootn:". See src/libgcc/README.md.  */

/* More subroutines needed by GCC output code on some machines.  */
/* Compile this one with gcc.  */
/* Copyright (C) 1989, 92-98, 1999 Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* As a special exception, if you link this library with other files,
   some of which are compiled with GCC, to produce an executable,
   this library does not by itself cause the resulting executable
   to be covered by the GNU General Public License.
   This exception does not however invalidate any other reasons why
   the executable file might be covered by the GNU General Public License.  */

#include "common.h"

#define L_udivdi3
/* i5bootn: this module's copy of libgcc2.c's static __clz_tab, in .rodata */
#define __clz_tab D_00805E58
/* i5bootn: see src/libgcc/libgcc2.h (__udivmoddi4) */
#define DECOMP_UDIVMODDI4_WW_HIGH_TWICE
#include "src/libgcc/libgcc2.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_008035F0 */
UDItype __udivmoddi4 ();
/* __udivdi3 */
UDItype func_008035F0 (UDItype n, UDItype d)
{
  /* i5bootn: Sony's prebuilt libgcc.a was compiled by a 2.9-ee build that
     left a 16-byte dead stack slot here (a spilled register of the inlined
     __udivmoddi4 that no instruction uses). The Windows 2.9-ee-991111 has no
     such slot; an unused addressable local gives the same 0x10 frame.
     Every instruction is GCC's own.  */
  UDItype pad[2];

  (void) &pad;
  return __udivmoddi4 (n, d, (UDItype *) 0);
}
/* localdecomp:end func_008035F0 */
