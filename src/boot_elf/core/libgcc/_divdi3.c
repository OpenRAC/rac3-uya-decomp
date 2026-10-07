/* boot_elf: libgcc, L_divdi3 module (__divdi3), then linker fill
   (func_001267DC also holds the start of _eh.o's __default_terminate). From
   GCC 2.95.2's gcc/libgcc2.c, built the way Sony's prebuilt libgcc.a was:
   with Sony's ee-gcc 2.9-ee-991111 (@ee29 in
   targets/boot_elf/text_parts.txt). Changes from GCC's text are marked
   "boot_elf:". See src/libgcc/README.md.  */

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

#define L_divdi3
/* boot_elf: this module's copy of libgcc2.c's static __clz_tab, in .rodata */
#define __clz_tab D_00150DE8
#include "src/libgcc/libgcc2.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_001260F0 */
UDItype __udivmoddi4 ();

/* __divdi3 */
DItype func_001260F0 (DItype u, DItype v)
{
  word_type c = 0;
  DIunion uu, vv;
  DItype w;

  uu.ll = u;
  vv.ll = v;

  if (uu.s.high < 0)
    c = ~c,
    uu.ll = __negdi2 (uu.ll);
  if (vv.s.high < 0)
    c = ~c,
    vv.ll = __negdi2 (vv.ll);

  w = __udivmoddi4 (uu.ll, vv.ll, (UDItype *) 0);
  if (c)
    w = __negdi2 (w);

  return w;
}
/* localdecomp:end func_001260F0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001267DC);
