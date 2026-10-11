/* boot_elf: libgcc, L_moddi3 module (__moddi3). From GCC 2.95.2's
   gcc/libgcc2.c, built the way Sony's prebuilt libgcc.a was: with Sony's ee-
   gcc 2.9-ee-991111 (@ee29 in targets/boot_elf/text_parts.txt). Changes from
   GCC's text are marked "boot_elf:". See src/libgcc/README.md.  */

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

#define L_moddi3
/* boot_elf: this module's copy of libgcc2.c's static __clz_tab, in .rodata */
#define __clz_tab D_00150EE8
/* boot_elf: see src/libgcc/libgcc2.h (__udivmoddi4) */
#define DECOMP_UDIVMODDI4_CLEAR_RR
#include "src/libgcc/libgcc2.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_001278E0 */
UDItype __udivmoddi4 ();
/* __moddi3 */
DItype func_001278E0 (DItype u, DItype v)
{
  word_type c = 0;
  DIunion uu, vv;
  /* boot_elf: as in __umoddi3 (_umoddi3.c): Sony's build left 40 bytes of
     dead stack after w (slots of the inlined __udivmoddi4's locals), the
     Windows 2.9-ee-991111 frees them, so w gets this padding to give the
     same 0x40 frame with w at 0($sp).  */
  struct { DItype w; DItype pad[5]; } s;

  uu.ll = u;
  vv.ll = v;

  if (uu.s.high < 0)
    c = ~c,
    uu.ll = __negdi2 (uu.ll);
  if (vv.s.high < 0)
    vv.ll = __negdi2 (vv.ll);

  (void) __udivmoddi4 (uu.ll, vv.ll, &s.w);
  if (c)
    s.w = __negdi2 (s.w);

  return s.w;
}
/* localdecomp:end func_001278E0 */
