#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_0011F848 */
extern void func_0011F720(void *, void *);
void func_0011F848(void *start, void *end) {
    func_0011F720((void *)((u32)start & ~0x3F), (void *)((u32)end & ~0x3F));
}
/* localdecomp:end func_0011F848 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0011F85C);
