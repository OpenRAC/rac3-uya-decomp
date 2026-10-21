#include "common.h"

/* localdecomp:start func_004A4C98 */
extern u8 D_001E2900[];
extern u8 D_001E7600[];
extern u8 D_001E0E90[];
extern u8 D_001D97A0[];
void func_004A4C98(void) {
    __asm__ __volatile__(
        "lui $at, %%hi(D_001E2900)\n\t"
        "addiu $at, $at, %%lo(D_001E2900)\n\t"
        "lui $2, %%hi(D_001E7600)\n\t"
        "addiu $2, $2, %%lo(D_001E7600)\n\t"
        "lqc2 $vf10, 0x100($at)\n\t"
        "lqc2 $vf11, 0x110($at)\n\t"
        "lqc2 $vf12, 0x120($at)\n\t"
        "lqc2 $vf13, 0x130($at)\n\t"
        "lui $at, %%hi(D_001E0E90)\n\t"
        "addiu $at, $at, %%lo(D_001E0E90)\n\t"
        "lqc2 $vf20, 0x0($at)\n\t"
        "lqc2 $vf21, 0x10($at)\n\t"
        "lqc2 $vf22, 0x20($at)\n\t"
        "lqc2 $vf23, 0x30($at)\n\t"
        "vmulax.xyzw ACC, $vf10, $vf20x\n\t"
        "vmadday.xyzw ACC, $vf11, $vf20y\n\t"
        "vmaddaz.xyzw ACC, $vf12, $vf20z\n\t"
        "vmaddw.xyzw $vf20, $vf13, $vf20w\n\t"
        "vmulax.xyzw ACC, $vf10, $vf21x\n\t"
        "vmadday.xyzw ACC, $vf11, $vf21y\n\t"
        "vmaddaz.xyzw ACC, $vf12, $vf21z\n\t"
        "vmaddw.xyzw $vf21, $vf13, $vf21w\n\t"
        "vmulax.xyzw ACC, $vf10, $vf22x\n\t"
        "vmadday.xyzw ACC, $vf11, $vf22y\n\t"
        "vmaddaz.xyzw ACC, $vf12, $vf22z\n\t"
        "vmaddw.xyzw $vf22, $vf13, $vf22w\n\t"
        "vmulax.xyzw ACC, $vf10, $vf23x\n\t"
        "vmadday.xyzw ACC, $vf11, $vf23y\n\t"
        "vmaddaz.xyzw ACC, $vf12, $vf23z\n\t"
        "vmaddw.xyzw $vf23, $vf13, $vf23w\n\t"
        "lqc2 $vf1, 0x1D0($2)\n\t"
        "lqc2 $vf26, 0x190($2)\n\t"
        "lqc2 $vf27, 0x1A0($2)\n\t"
        "vmul.xy $vf26, $vf26, $vf1\n\t"
        "lui $at, %%hi(D_001D97A0)\n\t"
        "addiu $at, $at, %%lo(D_001D97A0)\n\t"
        "lqc2 $vf28, 0x0($at)\n\t"
        "lqc2 $vf29, 0x10($at)\n\t"
        "lqc2 $vf30, 0x20($at)\n\t"
        "lqc2 $vf31, 0x30($at)\n\t"
        "qmtc2.ni $0, $vf24"
        : : : "memory");
}
/* localdecomp:end func_004A4C98 */
