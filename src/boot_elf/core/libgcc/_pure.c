/* boot_elf: libgcc, _pure.o (__pure_virtual). From GCC 2.95.2's
   gcc/libgcc2.c, built the way Sony's prebuilt libgcc.a was: with Sony's
   ee-gcc 2.9-ee-991111 (@ee29 in targets/boot_elf/text_parts.txt), without
   libc (inhibit_libc, so no message is written). See
   src/libgcc/README.md.  */

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

#define L_pure
#include "src/libgcc/libgcc2.h"

/* boot_elf: the repo's name for __terminate (in _eh.c) */
#define __terminate func_001267F0

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00127FA8 */
#define MESSAGE "pure virtual method called\n"

/* __pure_virtual */
void func_00127FA8 ()
{
#ifndef inhibit_libc
  write (2, MESSAGE, sizeof (MESSAGE) - 1);
#endif
  __terminate ();
}
/* localdecomp:end func_00127FA8 */
