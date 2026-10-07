/* i5bootn: libgcc, L__main module (__do_global_ctors, __main;
   __do_global_dtors was dead-stripped by the linker, its last word is
   func_008025F0's end in 8010A8.c).
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

#define L__main
#include "src/libgcc/libgcc2.h"

/* i5bootn: the repo's names (func_XXXXXXXX, D_XXXXXXXX) for what this module
   refers to: __CTOR_LIST__ is the linker's constructor table.  */
#define __CTOR_LIST__ D_008C4A00
#define __do_global_ctors func_00802640

#include "src/libgcc/gbl-ctors.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_008026F0(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00802640 */
/* libgcc2.c: ON_EXIT is empty on a target without atexit (gbl-ctors.h), so
   the constructors never register __do_global_dtors.  */
#ifndef ON_EXIT
#define ON_EXIT(a, b)
#endif

/* __do_global_ctors */
void func_00802640 ()
{
  DO_GLOBAL_CTORS_BODY;
  ON_EXIT (__do_global_dtors, 0);
}
/* localdecomp:end func_00802640 */

/* localdecomp:start func_008026F0 */
/* i5bootn: __main's `static int initialized;` is in .bss, which is not built
   from C; this names it.  */
extern int D_008C5ED4;
#define initialized D_008C5ED4

/* Subroutine called automatically by `main'.
   Compiling a global function named `main'
   produces an automatic call to this function at the beginning.

   For many systems, this routine calls __do_global_ctors.
   For systems which support a .init section we use the .init section
   to run __do_global_ctors, so we need not do anything here.  */

/* __main (SYMBOL__MAIN) */
void func_008026F0 ()
{
  /* Support recursive calls to `main': run initializers just once.  */
  if (! initialized)
    {
      initialized = 1;
      __do_global_ctors ();
    }
}
/* localdecomp:end func_008026F0 */
