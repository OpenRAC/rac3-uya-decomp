#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003C0E08);

INCLUDE_ASM("asm/nonmatchings/text", func_003C0E10);

LINKER_REMNANT("asm/remnants", func_003C1070);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1130);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1440);

LINKER_REMNANT("asm/remnants", func_003C18F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1950);

LINKER_REMNANT("asm/remnants", func_003C1A28);

/* localdecomp:start func_003C1A40 */
unsigned long func_003C1A40(u8 *p, unsigned long a, unsigned long b, unsigned long c, unsigned long d) {
    register unsigned long shifted __asm__("$5") = a << 32;
    __asm__ volatile("" : "+r"(shifted));
    c <<= 8;
    d <<= 16;
    __asm__ volatile("" : "+r"(d));
    return *(unsigned long *)(p + 0x38) = shifted | b | c | d;
}
/* localdecomp:end func_003C1A40 */
