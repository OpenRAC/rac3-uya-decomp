/* boot_elf: libgcc, frame.o: GCC 2.95.2's gcc/frame.c (the DWARF2 frame
   unwinder), built the way Sony's prebuilt libgcc.a was: with Sony's
   ee-gcc 2.9-ee-991111 (@ee29 in targets/boot_elf/text_parts.txt). Changes
   from GCC's text are marked "boot_elf:". The linker dead-stripped the
   __register_frame* and __deregister_frame* functions (nothing left).
   execute_cfa_insn is still assembly (its switch table is in .rdata).
   Ends with linker fill and a 2-instruction remnant (func_0012A93C).
   See src/libgcc/README.md.  */

/* Subroutines needed for unwinding stack frames for exception handling.  */
/* Compile this one with gcc.  */
/* Copyright (C) 1997, 1998 Free Software Foundation, Inc.
   Contributed by Jason Merrill <jason@cygnus.com>.

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

/* boot_elf: the repo's names (func_XXXXXXXX, D_XXXXXXXX) for this file's
   functions and data, and for the libc functions it calls.  */
#define objects D_15A118
#define decode_uleb128 func_00129A58
#define decode_sleb128 func_00129AA0
#define fde_merge func_00129AF0
#define end_fde_sort func_00129BF0
#define count_fdes func_00129E58
#define add_fdes func_00129EA0
#define frame_init func_00129F28
#define find_fde func_0012A068
#define extract_cie_info func_0012A150
#define execute_cfa_insn func_0012A258
#define fde_split func_0012A7C8

/* It is incorrect to include config.h here, because this file is being
   compiled for the target, and hence definitions concerning only the host
   do not apply.  */

/* boot_elf: what GCC's build tree gives this file through tconfig.h (the
   EE port's tm.h) and system headers.  */
#define FIRST_PSEUDO_REGISTER 79
#define STACK_GROWS_DOWNWARD
#define DWARF2_UNWIND_INFO 1
#define inhibit_libc
#define SUPPORTS_WEAK 0
#define PROTO(ARGS) ARGS
#define NULL ((void *) 0)
typedef unsigned int size_t;

/* We disable this when inhibit_libc, so that gcc can still be built without
   needing header files first.  */
/* ??? This is not a good solution, since prototypes may be required in
   some cases for correct code.  See also libgcc2.c.  */
#ifndef inhibit_libc
/* fixproto guarantees these system headers exist. */
#include <stdlib.h>
#include <unistd.h>
#endif

/* decomp: defaults.h left out (nothing here uses it) */

#include "src/libgcc/dwarf2.h"
#include "src/libgcc/frame.h"
#include "src/libgcc/gthr.h"

/* boot_elf: `static __gthread_mutex_t object_mutex = __GTHREAD_MUTEX_INIT;`
   here; nothing uses it in a single-threaded build (gthr-single.h), and
   the repo's sources define no variables.  */
extern __gthread_mutex_t object_mutex;

/* Don't use `fancy_abort' here even if config.h says to use it.  */
#ifdef abort
#undef abort
#endif

/* Some types used by the DWARF 2 spec.  */

typedef          int  sword __attribute__ ((mode (SI)));
typedef unsigned int  uword __attribute__ ((mode (SI)));
typedef unsigned int  uaddr __attribute__ ((mode (pointer)));
typedef          int  saddr __attribute__ ((mode (pointer)));
typedef unsigned char ubyte;

/* Terminology:
   CIE - Common Information Element
   FDE - Frame Descriptor Element

   There is one per function, and it describes where the function code
   is located, and what the register lifetimes and stack layout are
   within the function.

   The data structures are defined in the DWARF specfication, although
   not in a very readable way (see LITERATURE).

   Every time an exception is thrown, the code needs to locate the FDE
   for the current function, and starts to look for exception regions
   from that FDE. This works in a two-level search:
   a) in a linear search, find the shared image (i.e. DLL) containing
      the PC
   b) using the FDE table for that shared object, locate the FDE using
      binary search (which requires the sorting).  */   

/* The first few fields of a CIE.  The CIE_id field is 0 for a CIE,
   to distinguish it from a valid FDE.  FDEs are aligned to an addressing
   unit boundary, but the fields within are unaligned.  */

struct dwarf_cie {
  uword length;
  sword CIE_id;
  ubyte version;
  char augmentation[0];
} __attribute__ ((packed, aligned (__alignof__ (void *))));

/* The first few fields of an FDE.  */

struct dwarf_fde {
  uword length;
  sword CIE_delta;
  void* pc_begin;
  uaddr pc_range;
} __attribute__ ((packed, aligned (__alignof__ (void *))));

typedef struct dwarf_fde fde;

/* Objects to be searched for frame unwind info.  */

/* boot_elf: a static, in .bss in retail.  */
extern struct object *objects;

/* The information we care about from a CIE.  */

struct cie_info {
  char *augmentation;
  void *eh_ptr;
  int code_align;
  int data_align;
  unsigned ra_regno;
};

/* The current unwind state, plus a saved copy for DW_CFA_remember_state.  */

struct frame_state_internal
{
  struct frame_state s;
  struct frame_state_internal *saved_state;
};

/* This is undefined below if we need it to be an actual function.  */
#define init_object_mutex_once()

#if __GTHREADS
#ifdef __GTHREAD_MUTEX_INIT_FUNCTION

/* Helper for init_object_mutex_once.  */

static void
init_object_mutex (void)
{
  __GTHREAD_MUTEX_INIT_FUNCTION (&object_mutex);
}

/* Call this to arrange to initialize the object mutex.  */

#undef init_object_mutex_once
static void
init_object_mutex_once (void)
{
  static __gthread_once_t once = __GTHREAD_ONCE_INIT;
  __gthread_once (&once, init_object_mutex);
}

#endif /* __GTHREAD_MUTEX_INIT_FUNCTION */
#endif /* __GTHREADS */

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00129A58 */
/* Decode the unsigned LEB128 constant at BUF into the variable pointed to
   by R, and return the new value of BUF.  */

/* decode_uleb128 */
static void * func_00129A58 (unsigned char *buf, unsigned *r)
{
  unsigned shift = 0;
  unsigned result = 0;

  while (1)
    {
      unsigned byte = *buf++;
      result |= (byte & 0x7f) << shift;
      if ((byte & 0x80) == 0)
	break;
      shift += 7;
    }
  *r = result;
  return buf;
}
/* localdecomp:end func_00129A58 */

/* localdecomp:start func_00129AA0 */
/* Decode the signed LEB128 constant at BUF into the variable pointed to
   by R, and return the new value of BUF.  */

/* decode_sleb128 */
static void * func_00129AA0 (unsigned char *buf, int *r)
{
  unsigned shift = 0;
  unsigned result = 0;
  unsigned byte;

  while (1)
    {
      byte = *buf++;
      result |= (byte & 0x7f) << shift;
      shift += 7;
      if ((byte & 0x80) == 0)
	break;
    }
  if (shift < (sizeof (*r) * 8) && (byte & 0x40) != 0)
    result |= - (1 << shift);

  *r = result;
  return buf;
}
/* localdecomp:end func_00129AA0 */

/* localdecomp:start func_00129AF0 */
/* Read unaligned data from the instruction buffer.  */

union unaligned {
  void *p;
  unsigned b2 __attribute__ ((mode (HI)));
  unsigned b4 __attribute__ ((mode (SI)));
  unsigned b8 __attribute__ ((mode (DI)));
} __attribute__ ((packed));
static inline void *
read_pointer (void *p)
{ union unaligned *up = p; return up->p; }
static inline unsigned
read_1byte (void *p)
{ return *(unsigned char *)p; }
static inline unsigned
read_2byte (void *p)
{ union unaligned *up = p; return up->b2; }
static inline unsigned
read_4byte (void *p)
{ union unaligned *up = p; return up->b4; }
static inline unsigned long
read_8byte (void *p)
{ union unaligned *up = p; return up->b8; }

/* Ordering function for FDEs.  Functions can't overlap, so we just compare
   their starting addresses.  */

static inline saddr
fde_compare (fde *x, fde *y)
{
  return (saddr)x->pc_begin - (saddr)y->pc_begin;
}

/* Return the address of the FDE after P.  */

static inline fde *
next_fde (fde *p)
{
  return (fde *)(((char *)p) + p->length + sizeof (p->length));
}

/* Sorting an array of FDEs by address.
   (Ideally we would have the linker sort the FDEs so we don't have to do
   it at run time. But the linkers are not yet prepared for this.)  */

/* This is a special mix of insertion sort and heap sort, optimized for
   the data sets that actually occur. They look like
   101 102 103 127 128 105 108 110 190 111 115 119 125 160 126 129 130.
   I.e. a linearly increasing sequence (coming from functions in the text
   section), with additionally a few unordered elements (coming from functions
   in gnu_linkonce sections) whose values are higher than the values in the
   surrounding linear sequence (but not necessarily higher than the values
   at the end of the linear sequence!).
   The worst-case total run time is O(N) + O(n log (n)), where N is the
   total number of FDEs and n is the number of erratic ones.  */

typedef struct fde_vector
{
  fde **array;
  size_t count;
} fde_vector;

typedef struct fde_accumulator
{
  fde_vector linear;
  fde_vector erratic;
} fde_accumulator;

static inline void
start_fde_sort (fde_accumulator *accu, size_t count)
{
  accu->linear.array = (fde **) malloc (sizeof (fde *) * count);
  accu->erratic.array = (fde **) malloc (sizeof (fde *) * count);
  accu->linear.count = 0;
  accu->erratic.count = 0;
}

static inline void
fde_insert (fde_accumulator *accu, fde *this_fde)
{
  accu->linear.array[accu->linear.count++] = this_fde;
}


/* boot_elf: fde_split is `static inline` in frame.c, defined here. It is
   never inlined, and gcc writes such a function out last, after
   __frame_state_for, which is where retail has it; so it is defined at
   that place below, without `inline` (a deferred function would land
   after the asm that follows it in this file).  */
static void fde_split (fde_vector *linear, fde_vector *erratic);

/* This is O(n log(n)).  BSD/OS defines heapsort in stdlib.h, so we must
   use a name that does not conflict.  */
static inline void
frame_heapsort (fde_vector *erratic)
{
  /* For a description of this algorithm, see:
     Samuel P. Harbison, Guy L. Steele Jr.: C, a reference manual, 2nd ed.,
     p. 60-61. */
  fde ** a = erratic->array;
  /* A portion of the array is called a "heap" if for all i>=0:
     If i and 2i+1 are valid indices, then a[i] >= a[2i+1].
     If i and 2i+2 are valid indices, then a[i] >= a[2i+2]. */
#define SWAP(x,y) do { fde * tmp = x; x = y; y = tmp; } while (0)
  size_t n = erratic->count;
  size_t m = n;
  size_t i;

  while (m > 0)
    {
      /* Invariant: a[m..n-1] is a heap. */
      m--;
      for (i = m; 2*i+1 < n; )
        {
          if (2*i+2 < n
              && fde_compare (a[2*i+2], a[2*i+1]) > 0
              && fde_compare (a[2*i+2], a[i]) > 0)
            {
              SWAP (a[i], a[2*i+2]);
              i = 2*i+2;
            }
          else if (fde_compare (a[2*i+1], a[i]) > 0)
            {
              SWAP (a[i], a[2*i+1]);
              i = 2*i+1;
            }
          else
            break;
        }
    }
  while (n > 1)
    {
      /* Invariant: a[0..n-1] is a heap. */
      n--;
      SWAP (a[0], a[n]);
      for (i = 0; 2*i+1 < n; )
        {
          if (2*i+2 < n
              && fde_compare (a[2*i+2], a[2*i+1]) > 0
              && fde_compare (a[2*i+2], a[i]) > 0)
            {
              SWAP (a[i], a[2*i+2]);
              i = 2*i+2;
            }
          else if (fde_compare (a[2*i+1], a[i]) > 0)
            {
              SWAP (a[i], a[2*i+1]);
              i = 2*i+1;
            }
          else
            break;
        }
    }
#undef SWAP
}

/* Merge V1 and V2, both sorted, and put the result into V1. */
/* fde_merge */
static void func_00129AF0 (fde_vector *v1, const fde_vector *v2)
{
  size_t i1, i2;
  fde * fde2;

  i2 = v2->count;
  if (i2 > 0)
    {
      i1 = v1->count;
      do {
        i2--;
        fde2 = v2->array[i2];
        while (i1 > 0 && fde_compare (v1->array[i1-1], fde2) > 0)
          {
            v1->array[i1+i2] = v1->array[i1-1];
            i1--;
          }
        v1->array[i1+i2] = fde2;
      } while (i2 > 0);
      v1->count += v2->count;
    }
}
/* localdecomp:end func_00129AF0 */

/* localdecomp:start func_00129BF0 */
/* end_fde_sort */
static fde ** func_00129BF0 (fde_accumulator *accu, size_t count)
{
  if (accu->linear.count != count)
    abort ();
  fde_split (&accu->linear, &accu->erratic);
  if (accu->linear.count + accu->erratic.count != count)
    abort ();
  frame_heapsort (&accu->erratic);
  fde_merge (&accu->linear, &accu->erratic);
  free (accu->erratic.array);
  return accu->linear.array;
}
/* localdecomp:end func_00129BF0 */

/* localdecomp:start func_00129E58 */
/* count_fdes */
static size_t func_00129E58 (fde *this_fde)
{
  size_t count;

  for (count = 0; this_fde->length != 0; this_fde = next_fde (this_fde))
    {
      /* Skip CIEs and linked once FDE entries.  */
      if (this_fde->CIE_delta == 0 || this_fde->pc_begin == 0)
	continue;

      ++count;
    }

  return count;
}
/* localdecomp:end func_00129E58 */

/* localdecomp:start func_00129EA0 */
/* add_fdes */
static void func_00129EA0 (fde *this_fde, fde_accumulator *accu, void **beg_ptr, void **end_ptr)
{
  void *pc_begin = *beg_ptr;
  void *pc_end = *end_ptr;

  for (; this_fde->length != 0; this_fde = next_fde (this_fde))
    {
      /* Skip CIEs and linked once FDE entries.  */
      if (this_fde->CIE_delta == 0 || this_fde->pc_begin == 0)
	continue;

      fde_insert (accu, this_fde);

      if (this_fde->pc_begin < pc_begin)
	pc_begin = this_fde->pc_begin;
      if (this_fde->pc_begin + this_fde->pc_range > pc_end)
	pc_end = this_fde->pc_begin + this_fde->pc_range;
    }

  *beg_ptr = pc_begin;
  *end_ptr = pc_end;
}
/* localdecomp:end func_00129EA0 */

/* localdecomp:start func_00129F28 */
/* Set up a sorted array of pointers to FDEs for a loaded object.  We
   count up the entries before allocating the array because it's likely to
   be faster.  */

/* frame_init */
static void func_00129F28 (struct object* ob)
{
  size_t count;
  fde_accumulator accu;
  void *pc_begin, *pc_end;

  if (ob->fde_array)
    {
      fde **p = ob->fde_array;
      for (count = 0; *p; ++p)
	count += count_fdes (*p);
    }
  else
    count = count_fdes (ob->fde_begin);

  ob->count = count;

  start_fde_sort (&accu, count);
  pc_begin = (void*)(uaddr)-1;
  pc_end = 0;

  if (ob->fde_array)
    {
      fde **p = ob->fde_array;
      for (; *p; ++p)
	add_fdes (*p, &accu, &pc_begin, &pc_end);
    }
  else
    add_fdes (ob->fde_begin, &accu, &pc_begin, &pc_end);

  ob->fde_array = end_fde_sort (&accu, count);
  ob->pc_begin = pc_begin;
  ob->pc_end = pc_end;
}
/* localdecomp:end func_00129F28 */

/* localdecomp:start func_0012A068 */
/* Return a pointer to the FDE for the function containing PC.  */

/* find_fde */
static fde * func_0012A068 (void *pc)
{
  struct object *ob;
  size_t lo, hi;

  init_object_mutex_once ();
  __gthread_mutex_lock (&object_mutex);

  for (ob = objects; ob; ob = ob->next)
    {
      if (ob->pc_begin == 0)
	frame_init (ob);
      if (pc >= ob->pc_begin && pc < ob->pc_end)
	break;
    }

  __gthread_mutex_unlock (&object_mutex);

  if (ob == 0)
    return 0;

  /* Standard binary search algorithm.  */
  for (lo = 0, hi = ob->count; lo < hi; )
    {
      size_t i = (lo + hi) / 2;
      fde *f = ob->fde_array[i];

      if (pc < f->pc_begin)
	hi = i;
      else if (pc >= f->pc_begin + f->pc_range)
	lo = i + 1;
      else
	return f;
    }

  return 0;
}
/* localdecomp:end func_0012A068 */

/* localdecomp:start func_0012A150 */
/* boot_elf: the strings "" and "eh" below; retail has them in .rdata,
   which is not built from C.  */
extern char D_001511F0[];
extern char D_001511F8[];

static inline struct dwarf_cie *
get_cie (fde *f)
{
  return ((void *)&f->CIE_delta) - f->CIE_delta;
}

/* Extract any interesting information from the CIE for the translation
   unit F belongs to.  */

/* extract_cie_info */
static void * func_0012A150 (fde *f, struct cie_info *c)
{
  void *p;
  int i;

  c->augmentation = get_cie (f)->augmentation;

  if (strcmp (c->augmentation, D_001511F0) != 0
      && strcmp (c->augmentation, D_001511F8) != 0
      && c->augmentation[0] != 'z')
    return 0;

  p = c->augmentation + strlen (c->augmentation) + 1;

  if (strcmp (c->augmentation, D_001511F8) == 0)
    {
      c->eh_ptr = read_pointer (p);
      p += sizeof (void *);
    }
  else
    c->eh_ptr = 0;

  p = decode_uleb128 (p, &c->code_align);
  p = decode_sleb128 (p, &c->data_align);
  c->ra_regno = *(unsigned char *)p++;

  /* If the augmentation starts with 'z', we now see the length of the
     augmentation fields.  */
  if (c->augmentation[0] == 'z')
    {
      p = decode_uleb128 (p, &i);
      p += i;
    }

  return p;
}
/* localdecomp:end func_0012A150 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012A258);

/* localdecomp:start func_0012A5F0 */
/* boot_elf: execute_cfa_insn (static here in frame.c) is still assembly:
   its switch table is in .rdata, which is not built from C yet.  */
extern void *execute_cfa_insn (void *p, struct frame_state_internal *state,
			       struct cie_info *info, void **pc);

/* boot_elf: __register_frame_info, __register_frame,
   __register_frame_info_table, __register_frame_table,
   __deregister_frame_info and __deregister_frame come here in frame.c;
   the linker dead-stripped them (nothing left).  */

/* Called from __throw to find the registers to restore for a given
   PC_TARGET.  The caller should allocate a local variable of `struct
   frame_state' (declared in frame.h) and pass its address to STATE_IN.  */

/* __frame_state_for */
struct frame_state * func_0012A5F0 (void *pc_target, struct frame_state *state_in)
{
  fde *f;
  void *insn, *end, *pc;
  struct cie_info info;
  struct frame_state_internal state;

  f = find_fde (pc_target);
  if (f == 0)
    return 0;

  insn = extract_cie_info (f, &info);
  if (insn == 0)
    return 0;

  memset (&state, 0, sizeof (state));
  state.s.retaddr_column = info.ra_regno;
  state.s.eh_ptr = info.eh_ptr;

  /* First decode all the insns in the CIE.  */
  end = next_fde ((fde*) get_cie (f));
  while (insn < end)
    insn = execute_cfa_insn (insn, &state, &info, 0);

  insn = ((fde *)f) + 1;

  if (info.augmentation[0] == 'z')
    {
      int i;
      insn = decode_uleb128 (insn, &i);
      insn += i;
    }

  /* Then the insns in the FDE up to our target PC.  */
  end = next_fde (f);
  pc = f->pc_begin;
  while (insn < end && pc <= pc_target)
    insn = execute_cfa_insn (insn, &state, &info, &pc);

  memcpy (state_in, &state.s, sizeof (state.s));
  return state_in;
}
/* localdecomp:end func_0012A5F0 */

/* localdecomp:start func_0012A7C8 */
/* Split LINEAR into a linear sequence with low values and an erratic
   sequence with high values, put the linear one (of longest possible
   length) into LINEAR and the erratic one into ERRATIC. This is O(N).  */
/* fde_split */
static void func_0012A7C8 (fde_vector *linear, fde_vector *erratic)
{
  size_t count = linear->count;
  size_t linear_max = (size_t) -1;
  size_t previous_max[count];
  size_t i, j;

  for (i = 0; i < count; i++)
    {
      for (j = linear_max;
           j != (size_t) -1
           && fde_compare (linear->array[i], linear->array[j]) < 0;
           j = previous_max[j])
        {
          erratic->array[erratic->count++] = linear->array[j];
          linear->array[j] = (fde *) NULL;
        }
      previous_max[i] = j;
      linear_max = i;
    }

  for (i = 0, j = 0; i < count; i++)
    if (linear->array[i] != (fde *) NULL)
      linear->array[j++] = linear->array[i];
  linear->count = j;
}
/* localdecomp:end func_0012A7C8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012A93C);
