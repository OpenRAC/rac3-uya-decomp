#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern f32 func_0038D190(void *, void *);
extern void func_0038D148(f32 *, void *, f32);
extern void func_0038D1B8();
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D0E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D0F4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D0F8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D10C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D110);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D11C);

/* localdecomp:start func_0038D120 */
void func_0038D120(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($5)\n"
        "mfc1 $5, $f12\n"
        "lqc2 $vf2, 0($6)\n"
        "qmtc2.ni $5, $vf3\n"
        "vaddax.xyz ACC, $vf1, $vf0x\n"
        "vmsubax.xyz ACC, $vf1, $vf3x\n"
        "vmaddx.xyz $vf1, $vf2, $vf3x\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038D120 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D148);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D15C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D160);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D174);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D178);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D18C);

ASM_FUNC("asm/boot_elf/handwritten", func_0038D190);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D1B8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D1CC);
