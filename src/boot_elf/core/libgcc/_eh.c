/* boot_elf: libgcc, _eh.o, the C++ exception runtime: GCC 2.95.2's
   gcc/libgcc2.c built with -DL_eh, the way Sony's prebuilt libgcc.a was:
   with Sony's ee-gcc 2.9-ee-991111 (@ee29 in
   targets/boot_elf/text_parts.txt). Changes from GCC's text are marked
   "boot_elf:". GCC's build compiles this module with -fexceptions, and so
   does this range (targets/boot_elf/text_parts.txt). Its first function,
   __default_terminate, is in func_001267DC (the end of _divdi3.c). Still
   assembly: copy_reg, throw_helper, __throw and __rethrow (the Windows
   2.9-ee builds them differently; __rethrow crashes its cc1). See
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

#define L_eh
#include "src/libgcc/libgcc2.h"

/* boot_elf: what GCC's build tree gives this code through tconfig.h (the
   EE port's tm.h) and system headers. FIRST_PSEUDO_REGISTER sizes
   frame.h's frame_state; 79 gives retail's offsets in it.  */
#define FIRST_PSEUDO_REGISTER 79
#define STACK_GROWS_DOWNWARD
#define DWARF2_UNWIND_INFO 1
#define PROTO(ARGS) ARGS
#define NULL ((void *) 0)
typedef unsigned int size_t;

/* boot_elf: the repo's names (func_XXXXXXXX, D_XXXXXXXX) for what this
   module's functions refer to. __terminate_func and get_eh_context are
   initialized variables, in .data.  */
#define __terminate func_001267F0
#define new_eh_context func_00126850
#define __get_eh_info func_001268D0
#define __sjthrow func_001269B0
#define eh_context_initialize func_001268F8
#define eh_context_static func_00126920
#define old_find_exception_handler func_00126C98
#define find_exception_handler func_00126D70
#define get_reg_addr func_00126EB8
#define copy_reg func_00126F40
#define next_stack_level func_00126FC0
#define __unwinding_cleanup func_00127050
#define throw_helper func_00127058
#define __frame_state_for func_0012A5F0
#define __terminate_func D_0013F2B4
#define get_eh_context D_0013F2B8

#include "src/libgcc/gthr.h"
#include "src/libgcc/eh-common.h"
#include "src/libgcc/frame.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_001267F0 */
/* boot_elf: `= __default_terminate`; retail has it in .data */
extern void (*__terminate_func)();

/* __terminate */
void func_001267F0 ()
{
  (*__terminate_func)();
}
/* localdecomp:end func_001267F0 */

/* localdecomp:start func_00126818 */
/* __throw_type_match */
void * func_00126818 (void *catch_type, void *throw_type, void *obj)
{
#if 0
 printf ("__throw_type_match (): catch_type = %s, throw_type = %s\n",
	 catch_type, throw_type);
#endif
 if (strcmp ((const char *)catch_type, (const char *)throw_type) == 0)
   return obj;
 return 0;
}
/* localdecomp:end func_00126818 */

/* localdecomp:start func_00126848 */
/* __empty */
void func_00126848 ()
{
}
/* localdecomp:end func_00126848 */

/* localdecomp:start func_00126850 */
/* Allocate and return a new EH context structure. */

extern void __throw ();

/* new_eh_context */
static void * func_00126850 ()
{
  struct eh_full_context {
    struct eh_context c;
    void *top_elt[2];
  } *ehfc = (struct eh_full_context *) malloc (sizeof *ehfc);

  if (! ehfc)
    __terminate ();

  memset (ehfc, 0, sizeof *ehfc);

  ehfc->c.dynamic_handler_chain = (void **) ehfc->top_elt;

  /* This should optimize out entirely.  This should always be true,
     but just in case it ever isn't, don't allow bogus code to be
     generated.  */

  if ((void*)(&ehfc->c) != (void*)ehfc)
    __terminate ();

  return &ehfc->c;
}
/* localdecomp:end func_00126850 */

/* localdecomp:start func_001268A8 */
/* Pointer to function to return EH context. */

static struct eh_context *eh_context_initialize ();
static struct eh_context *eh_context_static ();
#if __GTHREADS
static struct eh_context *eh_context_specific ();
#endif

/* boot_elf: `static ... = &eh_context_initialize`; retail has it in .data */
extern struct eh_context *(*get_eh_context) ();

/* Routine to get EH context.
   This one will simply call the function pointer. */

/* __get_eh_context */
void * func_001268A8 ()
{
  return (void *) (*get_eh_context) ();
}
/* localdecomp:end func_001268A8 */

/* localdecomp:start func_001268D0 */
/* Get and set the language specific info pointer. */

/* __get_eh_info */
void ** func_001268D0 ()
{
  struct eh_context *eh = (*get_eh_context) ();
  return &eh->info;
}
/* localdecomp:end func_001268D0 */

/* localdecomp:start func_001268F8 */
/* Initialize EH context.
   This will be called only once, since we change GET_EH_CONTEXT
   pointer to another routine. */

/* eh_context_initialize */
static struct eh_context * func_001268F8 ()
{
#if __GTHREADS

  static __gthread_once_t once = __GTHREAD_ONCE_INIT;
  /* Make sure that get_eh_context does not point to us anymore.
     Some systems have dummy thread routines in their libc that
     return a success (Solaris 2.6 for example). */
  if (__gthread_once (&once, eh_threads_initialize) != 0
      || get_eh_context == &eh_context_initialize)
    {
      /* Use static version of EH context. */
      get_eh_context = &eh_context_static;
    }

#else /* no __GTHREADS */

  /* Use static version of EH context. */
  get_eh_context = &eh_context_static;

#endif /* no __GTHREADS */

  return (*get_eh_context) ();
}
/* localdecomp:end func_001268F8 */

/* localdecomp:start func_00126920 */
/* Return a static EH context. */

/* eh_context_static */
static struct eh_context * func_00126920 ()
{
  /* boot_elf: three statics, `eh`, `initialized` and `top_elt[2]`;
     retail has them in .bss */
  extern struct eh_context D_15A0D0;
  extern int D_15A0E0;
  extern void *D_15A0E8[2];

  if (! D_15A0E0)
    {
      D_15A0E0 = 1;
      memset (&D_15A0D0, 0, sizeof D_15A0D0);
      D_15A0D0.dynamic_handler_chain = D_15A0E8;
    }
  return &D_15A0D0;
}
/* localdecomp:end func_00126920 */

/* localdecomp:start func_00126988 */
/* Routine to get the head of the current thread's dynamic handler chain
   use for exception handling. */

/* __get_dynamic_handler_chain */
void *** func_00126988 ()
{
  struct eh_context *eh = (*get_eh_context) ();
  return &eh->dynamic_handler_chain;
}
/* localdecomp:end func_00126988 */

/* localdecomp:start func_001269B0 */
/* This is used to throw an exception when the setjmp/longjmp codegen
   method is used for exception handling.

   We call __terminate if there are no handlers left.  Otherwise we run the
   cleanup actions off the dynamic cleanup stack, and pop the top of the
   dynamic handler chain, and use longjmp to transfer back to the associated
   handler.  */

extern void __sjthrow (void) __attribute__ ((__noreturn__));

/* __sjthrow, then __sjpopnthrow and __eh_rtime_match, which follow it in
   retail (splat sees the three as one function) */
void func_001269B0 ()
{
  struct eh_context *eh = (*get_eh_context) ();
  void ***dhc = &eh->dynamic_handler_chain;
  void *jmpbuf;
  void (*func)(void *, int);
  void *arg;
  void ***cleanup;

  /* The cleanup chain is one word into the buffer.  Get the cleanup
     chain.  */
  cleanup = (void***)&(*dhc)[1];

  /* If there are any cleanups in the chain, run them now.  */
  if (cleanup[0])
    {
      double store[200];
      void **buf = (void**)store;
      buf[1] = 0;
      buf[0] = (*dhc);

      /* try { */
#ifdef DONT_USE_BUILTIN_SETJMP
      if (! setjmp (&buf[2]))
#else
      if (! __builtin_setjmp (&buf[2]))
#endif
	{
	  *dhc = buf;
	  while (cleanup[0])
	    {
	      func = (void(*)(void*, int))cleanup[0][1];
	      arg = (void*)cleanup[0][2];

	      /* Update this before running the cleanup.  */
	      cleanup[0] = (void **)cleanup[0][0];

	      (*func)(arg, 2);
	    }
	  *dhc = buf[0];
	}
      /* catch (...) */
      else
	{
	  __terminate ();
	}
    }
  
  /* We must call terminate if we try and rethrow an exception, when
     there is no exception currently active and when there are no
     handlers left.  */
  if (! eh->info || (*dhc)[0] == 0)
    __terminate ();
    
  /* Find the jmpbuf associated with the top element of the dynamic
     handler chain.  The jumpbuf starts two words into the buffer.  */
  jmpbuf = &(*dhc)[2];

  /* Then we pop the top element off the dynamic handler chain.  */
  *dhc = (void**)(*dhc)[0];

  /* And then we jump to the handler.  */

#ifdef DONT_USE_BUILTIN_SETJMP
  longjmp (jmpbuf, 1);
#else
  __builtin_longjmp (jmpbuf, 1);
#endif
}

/* Run cleanups on the dynamic cleanup stack for the current dynamic
   handler, then pop the handler off the dynamic handler stack, and
   then throw.  This is used to skip the first handler, and transfer
   control to the next handler in the dynamic handler stack.  */

extern void __sjpopnthrow (void) __attribute__ ((__noreturn__));

void
__sjpopnthrow ()
{
  struct eh_context *eh = (*get_eh_context) ();
  void ***dhc = &eh->dynamic_handler_chain;
  void (*func)(void *, int);
  void *arg;
  void ***cleanup;

  /* The cleanup chain is one word into the buffer.  Get the cleanup
     chain.  */
  cleanup = (void***)&(*dhc)[1];

  /* If there are any cleanups in the chain, run them now.  */
  if (cleanup[0])
    {
      double store[200];
      void **buf = (void**)store;
      buf[1] = 0;
      buf[0] = (*dhc);

      /* try { */
#ifdef DONT_USE_BUILTIN_SETJMP
      if (! setjmp (&buf[2]))
#else
      if (! __builtin_setjmp (&buf[2]))
#endif
	{
	  *dhc = buf;
	  while (cleanup[0])
	    {
	      func = (void(*)(void*, int))cleanup[0][1];
	      arg = (void*)cleanup[0][2];

	      /* Update this before running the cleanup.  */
	      cleanup[0] = (void **)cleanup[0][0];

	      (*func)(arg, 2);
	    }
	  *dhc = buf[0];
	}
      /* catch (...) */
      else
	{
	  __terminate ();
	}
    }

  /* Then we pop the top element off the dynamic handler chain.  */
  *dhc = (void**)(*dhc)[0];

  __sjthrow ();
}

/* Support code for all exception region-based exception handling.  */

int
__eh_rtime_match (void *rtime)
{
  void *info;
  __eh_matcher matcher;
  void *ret;

  info = *(__get_eh_info ());
  matcher = ((__eh_info *)info)->match_function;
  if (! matcher)
    {
#ifndef inhibit_libc
      fprintf (stderr, "Internal Compiler Bug: No runtime type matcher.");
#endif
      return 0;
    }
  ret = (*matcher) (info, rtime, (void *)0);
  return (ret != NULL);
}
/* localdecomp:end func_001269B0 */

/* localdecomp:start func_00126C88 */
/* Return the table version of an exception descriptor */

/* __get_eh_table_version */
short func_00126C88 (exception_descriptor *table) 
{
  return table->lang.version;
}
/* localdecomp:end func_00126C88 */

/* localdecomp:start func_00126C90 */
/* Return the originating table language of an exception descriptor */

/* __get_eh_table_language */
short func_00126C90 (exception_descriptor *table)
{
  return table->lang.language;
}
/* localdecomp:end func_00126C90 */

/* localdecomp:start func_00126C98 */
/* This routine takes a PC and a pointer to the exception region TABLE for
   its translation unit, and returns the address of the exception handler
   associated with the closest exception table handler entry associated
   with that PC, or 0 if there are no table entries the PC fits in.

   In the advent of a tie, we have to give the last entry, as it represents
   an inner block.  */

/* old_find_exception_handler */
static void * func_00126C98 (void *pc, old_exception_table *table)
{
  if (table)
    {
      int pos;
      int best = -1;

      /* We can't do a binary search because the table isn't guaranteed
         to be sorted from function to function.  */
      for (pos = 0; table[pos].start_region != (void *) -1; ++pos)
        {
          if (table[pos].start_region <= pc && table[pos].end_region > pc)
            {
              /* This can apply.  Make sure it is at least as small as
                 the previous best.  */
              if (best == -1 || (table[pos].end_region <= table[best].end_region
                        && table[pos].start_region >= table[best].start_region))
                best = pos;
            }
          /* But it is sorted by starting PC within a function.  */
          else if (best >= 0 && table[pos].start_region > pc)
            break;
        }
      if (best != -1)
        return table[best].exception_handler;
    }

  return (void *) 0;
}
/* localdecomp:end func_00126C98 */

/* localdecomp:start func_00126D70 */
/* find_exception_handler finds the correct handler, if there is one, to
   handle an exception.
   returns a pointer to the handler which controlled should be transferred
   to, or NULL if there is nothing left.
   Parameters:
   PC - pc where the exception originates. If this is a rethrow, 
        then this starts out as a pointer to the exception table
	entry we wish to rethrow out of.
   TABLE - exception table for the current module.
   EH_INFO - eh info pointer for this exception.
   RETHROW - 1 if this is a rethrow. (see incoming value of PC).
   CLEANUP - returned flag indicating whether this is a cleanup handler.
*/
/* find_exception_handler */
static void * func_00126D70 (void *pc, exception_descriptor *table, 
                        __eh_info *eh_info, int rethrow, int *cleanup)
{

  void *retval = NULL;
  *cleanup = 1;
  if (table)
    {
      int pos = 0;
      /* The new model assumed the table is sorted inner-most out so the
         first region we find which matches is the correct one */

      exception_table *tab = &(table->table[0]);

      /* Subtract 1 from the PC to avoid hitting the next region */
      if (rethrow) 
        {
          /* pc is actually the region table entry to rethrow out of */
          pos = ((exception_table *) pc) - tab;
          pc = ((exception_table *) pc)->end_region - 1;

          /* The label is always on the LAST handler entry for a region, 
             so we know the next entry is a different region, even if the
             addresses are the same. Make sure its not end of table tho. */
          if (tab[pos].start_region != (void *) -1)
            pos++;
        }
      else
        pc--;
      
      /* We can't do a binary search because the table is in inner-most
         to outermost address ranges within functions */
      for ( ; tab[pos].start_region != (void *) -1; pos++)
        { 
          if (tab[pos].start_region <= pc && tab[pos].end_region > pc)
            {
              if (tab[pos].match_info)
                {
                  __eh_matcher matcher = eh_info->match_function;
                  /* match info but no matcher is NOT a match */
                  if (matcher) 
                    {
                      void *ret = (*matcher)((void *) eh_info, 
                                             tab[pos].match_info, table);
                      if (ret) 
                        {
                          if (retval == NULL)
                            retval = tab[pos].exception_handler;
                          *cleanup = 0;
                          break;
                        }
                    }
                }
              else
                {
                  if (retval == NULL)
                    retval = tab[pos].exception_handler;
                }
            }
        }
    }
  return retval;
}
/* localdecomp:end func_00126D70 */

/* localdecomp:start func_00126EB8 */
/* This type is used in get_reg and put_reg to deal with ABIs where a void*
   is smaller than a word, such as the Irix 6 n32 ABI.  We cast twice to
   avoid a warning about casting between int and pointer of different
   sizes.  */

typedef int ptr_type __attribute__ ((mode (pointer)));

static inline int in_reg_window (int reg, frame_state *udata) { return 0; }

/* Get the address of register REG as saved in UDATA, where SUB_UDATA is a
   frame called by UDATA or 0.  */

/* get_reg_addr */
static word_type * func_00126EB8 (unsigned reg, frame_state *udata, frame_state *sub_udata)
{
  while (udata->saved[reg] == REG_SAVED_REG)
    {
      reg = udata->reg_or_offset[reg];
      if (in_reg_window (reg, udata))
	{
          udata = sub_udata;
	  sub_udata = NULL;
	}
    }
  if (udata->saved[reg] == REG_SAVED_OFFSET)
    return (word_type *)(udata->cfa + udata->reg_or_offset[reg]);
  else
    abort ();
}
/* localdecomp:end func_00126EB8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00126F40);

/* localdecomp:start func_00126FC0 */
/* boot_elf: copy_reg (static in libgcc2.c) is still assembly; this stands
   in for its definition.  */
extern void copy_reg (unsigned reg, frame_state *udata, frame_state *target_udata);

/* Get the value of register REG as saved in UDATA, where SUB_UDATA is a
   frame called by UDATA or 0.  */

static inline void *
get_reg (unsigned reg, frame_state *udata, frame_state *sub_udata)
{
  return (void *)(ptr_type) *get_reg_addr (reg, udata, sub_udata);
}

/* Overwrite the saved value for register REG in frame UDATA with VAL.  */

static inline void
put_reg (unsigned reg, void *val, frame_state *udata)
{
  *get_reg_addr (reg, udata, NULL) = (word_type)(ptr_type) val;
}

/* Retrieve the return address for frame UDATA.  */

static inline void *
get_return_addr (frame_state *udata, frame_state *sub_udata)
{
  return __builtin_extract_return_addr
    (get_reg (udata->retaddr_column, udata, sub_udata));
}

/* Overwrite the return address for frame UDATA with VAL.  */

static inline void
put_return_addr (void *val, frame_state *udata)
{
  val = __builtin_frob_return_addr (val);
  put_reg (udata->retaddr_column, val, udata);
}

/* Given the current frame UDATA and its return address PC, return the
   information about the calling frame in CALLER_UDATA.  */

/* next_stack_level */
static void * func_00126FC0 (void *pc, frame_state *udata, frame_state *caller_udata)
{
  caller_udata = __frame_state_for (pc, caller_udata);
  if (! caller_udata)
    return 0;

  /* Now go back to our caller's stack frame.  If our caller's CFA register
     was saved in our stack frame, restore it; otherwise, assume the CFA
     register is SP and restore it to our CFA value.  */
  if (udata->saved[caller_udata->cfa_reg])
    caller_udata->cfa = get_reg (caller_udata->cfa_reg, udata, 0);
  else
    caller_udata->cfa = udata->cfa;
  caller_udata->cfa += caller_udata->cfa_offset;

  return caller_udata;
}
/* localdecomp:end func_00126FC0 */

/* localdecomp:start func_00127050 */
/* Hook to call before __terminate if only cleanup handlers remain. */
/* __unwinding_cleanup */
void func_00127050 ()
{
}
/* localdecomp:end func_00127050 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00127058);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00127388);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00127568);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012774C);
