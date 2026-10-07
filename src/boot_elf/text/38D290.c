#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void func_0038D290(s32 a, s32 b, f32 x);
extern void func_0038D350();
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_0038D290 */
/* func_0038D2DC (4 bytes, the sqc2 in this function's jr delay slot) was a split artifact. */
void func_0038D290(s32 a, s32 b, f32 x) {
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2 $vf1, 0($5)\n"
        "vaddw.xyz $vf3, $vf0, $vf0w\n"
        "vmul.xyz $vf2, $vf1, $vf1\n"
        "vadday.x ACC, $vf2, $vf2y\n"
        "vmaddz.x $vf2, $vf3, $vf2z\n"
        "mfc1 $at, $f12\n"
        "qmtc2.ni $at, $vf3\n"
        "vrsqrt Q, $vf3x, $vf2x\n"
        "qmfc2.ni $at, $vf2\n"
        "dsll32 $at, $at, 0\n"
        "beqz $at, .L00388870_0038D290\n"
        "nop\n"
        "vwaitq\n"
        "vmulq.xyz $vf1, $vf1, Q\n"
        "jr $31\n"
        "sqc2 $vf1, 0($4)\n"
        ".L00388870_0038D290:\n"
        ".set reorder\n"
        "vadd.xyz $vf1, $vf0, $vf0\n"
        "nop\n"
        "sqc2 $vf1, 0($4)\n"
    );
}
/* localdecomp:end func_0038D290 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D2E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D324);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D328);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D34C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D350);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D37C);

ASM_FUNC("asm/boot_elf/handwritten", func_0038D380);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D3A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D3BC);
