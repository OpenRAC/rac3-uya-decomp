#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003D2ED0 */
void func_003D2ED0(u8 *p) {
    register s32 v __asm__("$9");
    __asm__ __volatile__(
        "lw $8, 0x18($5)\n"
        "nop\n"
        "mfc1 $10, $f12\n"
        "nop\n"
        "pextlb $8, $0, $8\n"
        "lw $9, 0x18($6)\n"
        "pextlh $8, $0, $8\n"
        "qmtc2.ni $10, $vf1\n"
        "qmtc2.ni $8, $vf5\n"
        "pextlb $9, $0, $9\n"
        "pextlh $9, $0, $9\n"
        ".word 0x1400FFF4\n"
        "qmtc2.ni $9, $vf3\n"
        "nop\n"
        "vitof0.xyzw $vf5, $vf5\n"
        "vsubx.w $vf6, $vf0, $vf1x\n"
        "vitof0.xyzw $vf3, $vf3\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "lqc2 $vf2, 0($5)\n"
        "nop\n"
        "vmulaw.xyzw ACC, $vf5, $vf6w\n"
        "vmaddx.xyzw $vf5, $vf3, $vf1x\n"
        "lqc2 $vf3, 0($6)\n"
        "nop\n"
        "vmulaw.xyzw ACC, $vf2, $vf6w\n"
        "vmaddx.xyzw $vf2, $vf3, $vf1x\n"
        "vftoi4.xyzw $vf5, $vf5\n"
        "nop\n"
        "lqc2 $vf3, 16($5)\n"
        "nop\n"
        "lqc2 $vf4, 16($6)\n"
        "nop\n"
        "vmulaw.xy ACC, $vf3, $vf6w\n"
        "ori $8, $0, 0x2\n"
        "vmaddx.xy $vf3, $vf4, $vf1x\n"
        "nop\n"
        "pcpyh $8, $8\n"
        "qmfc2.ni $9, $vf5\n"
        "ppach $9, $0, $9\n"
        "paddh $9, $9, $8\n"
        "psrlh $9, $9, 4\n"
        "sqc2 $vf3, 16($4)\n"
        "ppacb $9, $0, $9\n"
        "sqc2 $vf2, 0($4)\n"
        : "=r"(v) : : "memory"
    );
    *(s32 *)(p + 0x18) = v;
}
/* localdecomp:end func_003D2ED0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D2F90);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D2FEC);
