# This file is used by modern gas.
# Defines the expected assembly macros
#
# PATCHED for this project's SN Systems ee-as.exe (circa ee-gcc 2.95.3 /
# late-1990s binutils-era MIPS toolchain). Two incompatibilities found and
# fixed here, confirmed against real assembler output on 2026-09-22:
#
# 1. `.internal` (modern-binutils-only symbol-visibility pseudo-op) is
#    unsupported ("Unknown pseudo-op: `.internal'") -- removed; it was
#    only ever decorating the include-guard variable, not doing anything
#    load-bearing.
#
# 2. This assembler's macro engine does NOT do \param substitution INSIDE
#    double-quoted strings -- it parses the string char-by-char first and
#    treats \l, \a, \b, \( etc. as (unrecognized, silently-dropped) string
#    escape sequences, so "\label" never becomes the real symbol name at
#    all ("Unknown escape '\l' in string: Ignored", then every directive
#    using that mangled empty string fails downstream: "no such section",
#    "ignoring unrecognized symbol type", broken .size directives -- this
#    was the actual cause of that whole error cascade, not a section or
#    .size problem in isolation). \param substitution DOES work outside
#    quotes on this assembler, so every macro below drops the quotes
#    around \label and uses the bare substituted identifier instead. The
#    \() empty-substitution operator (used to glue \label directly against
#    literal text, e.g. \label\().NON_MATCHING) is replaced with \label
#    followed by a literal ".NON_MATCHING" suffix with no separator needed
#    -- gas's normal token-boundary rules already stop the substitution at
#    the first non-identifier character, so \() was only ever needed for
#    the quoted-string form this assembler can't do anyway.

# Evaluate this file only once in case it's included more than once
.ifndef _MACRO_INC_GUARD
.set _MACRO_INC_GUARD, 1

# A function symbol.
.macro glabel label, visibility=global
    .\visibility \label
    .type \label, @function
    \label:
        .ent \label
.endm

# The end of a function symbol.
.macro endlabel label
    .size \label, . - \label
    .end \label
.endm

# An alternative entry to a function.
# .aent removed: this ee-as rejects it ("Unknown pseudo-op: `.aent'"). It only
# records an alternate entry point in debug info and emits no instruction
# bytes, so dropping it doesn't affect matching (see test_aent.s).
.macro alabel label, visibility=global
    .\visibility \label
    .type \label, @function
    \label:
.endm

# A label referenced by an error handler table.
.macro ehlabel label, visibility=global
    .\visibility \label
    \label:
.endm


# A label referenced by a jumptable.
.macro jlabel label, visibility=global
    .\visibility \label
    \label:
.endm


# A data symbol.
.macro dlabel label, visibility=global
    .\visibility \label
    .type \label, @object
    \label:
.endm

# End of a data symbol.
.macro enddlabel label
    .size \label, . - \label
.endm


# Label to signal the symbol haven't been matched yet.
.macro nonmatching label, size=1
    .global \label.NON_MATCHING
    .type \label.NON_MATCHING, @object
    .size \label.NON_MATCHING, \size
    \label.NON_MATCHING:
.endm

.endif
