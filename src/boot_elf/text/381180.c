#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00381180 */
extern void func_00398040(s32, s32);

void func_00381180(void) {
    func_00398040(0, 0);
}
/* localdecomp:end func_00381180 */

/* localdecomp:start func_003811A0 */
extern void func_003BBA90(s32);
extern void func_003B3440(void *);
extern s32 func_003A1180(s32, s32, s32, s32, u8 *);
extern u8 D_001E2340[];

void func_003811A0(void) {
    func_003BBA90(1);
    func_003B3440(D_001E2340);
    func_003A1180(0x12, 1, 7, 0, 0);
}
/* localdecomp:end func_003811A0 */

/* localdecomp:start func_003811E0 */
extern void func_003BBA90(s32);
extern s32 func_003A1180(s32, s32, s32, s32, u8 *);

void func_003811E0(void) {
    func_003BBA90(1);
    func_003A1180(0x12, 1, 8, 0, 0);
}
/* localdecomp:end func_003811E0 */

/* localdecomp:start func_00381218 */
s32 func_00381218(void) {
}
/* localdecomp:end func_00381218 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00381220);

extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003F2580(s32, s32);
extern void * func_003AF2D0();
extern s32 D_001D5C78;

typedef struct {
    u8 pad[0x84];
    s32 f84;
} Struct227600;
extern Struct227600 D_00227600;

/* localdecomp:start func_00381228 */
extern s32 D_00227600_00381228[];
extern s32 D_001D5C78_00381228[];
extern void func_11A264(s32, s32, s32);
extern s32 func_003F2580(s32, s32);
extern void * func_003AF2D0();
void func_00381228(void) {
    s32 *p = D_00227600_00381228;
    func_11A264(p[0x84/4], 0xCD, 0x40000);
    D_001D5C78_00381228[0] = func_003AF2D0(func_003F2580(0x24F10, p[0x84/4]), 0x40000);
}
/* localdecomp:end func_00381228 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00381280);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031BFE0);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C000);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C050);

/* localdecomp:start func_00381BC0 */
s32 func_00381BC0(void) {
    return 0;
}
/* localdecomp:end func_00381BC0 */

/* localdecomp:start func_00381BC8 */
s32 func_00381BC8(void) {
}
/* localdecomp:end func_00381BC8 */

/* localdecomp:start func_00381BD0 */
s32 func_00381BD0(void) {
}
/* localdecomp:end func_00381BD0 */

/* localdecomp:start func_00381BD8 */
s32 func_00381BD8(void) {
}
/* localdecomp:end func_00381BD8 */

/* localdecomp:start func_00381BE0 */
s32 func_00381BE0(void) {
}
/* localdecomp:end func_00381BE0 */

/* localdecomp:start func_00381BE8 */
extern u8 D_001427AB[];
u8 func_00381BE8(void) {
    return D_001427AB[0];
}
/* localdecomp:end func_00381BE8 */

extern s32 func_003E7210(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

/* localdecomp:start func_00381BF8 */
extern s32 func_003E7210(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001D9918;
extern s32 D_001D9900[2];
s32 *func_00381BF8(void) {
    if (D_001D9918 == 0) {
        func_003E7210(D_001D9900, 0, 0, 0, 0, 0);
        D_001D9918 = 1;
    }
    return D_001D9900;
}
/* localdecomp:end func_00381BF8 */

/* localdecomp:start func_00381C40 */
extern s32 * func_00381BF8();
void func_00381C40(void) {
    func_00381BF8();
}
/* localdecomp:end func_00381C40 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00381C60);

/* localdecomp:start func_00381C68 */
s32 func_00381C68(void) {
}
/* localdecomp:end func_00381C68 */

/* localdecomp:start func_00381C70 */
s32 func_00381C70(void) {
}
/* localdecomp:end func_00381C70 */

/* localdecomp:start func_00381C78 */
s32 func_00381C78(void) {
}
/* localdecomp:end func_00381C78 */

/* localdecomp:start func_00381C80 */
s32 func_00381C80(void) {
    return 0;
}
/* localdecomp:end func_00381C80 */

/* localdecomp:start func_00381C88 */
s32 func_00381C88(void) {
    return 0;
}
/* localdecomp:end func_00381C88 */

/* localdecomp:start func_00381C90 */
s32 func_00381C90(void) {
}
/* localdecomp:end func_00381C90 */

/* localdecomp:start func_00381C98 */
s32 func_00381C98(void) {
}
/* localdecomp:end func_00381C98 */

/* localdecomp:start func_00381CA0 */
s32 func_00381CA0(void) {
}
/* localdecomp:end func_00381CA0 */

/* localdecomp:start func_00381CA8 */
s32 func_00381CA8(void) {
}
/* localdecomp:end func_00381CA8 */

/* localdecomp:start func_00381CB0 */
s32 func_00381CB0(void) {
    return 0;
}
/* localdecomp:end func_00381CB0 */

/* localdecomp:start func_00381CB8 */
s32 func_00381CB8(void) {
    return 1;
}
/* localdecomp:end func_00381CB8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00381CC0);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C080);

LINKER_REMNANT("asm/boot_elf/remnants", func_00382378);

/* localdecomp:start func_00382380 */
extern void *D_001D9A20;
typedef struct { u8 pad0[0x2C]; s32 f2C; } S_00318CC0_0037DF28;
extern S_00318CC0_0037DF28 D_0031CD00[];

s32 func_00382380(s32 arg0) {
    s32 var_a1;
    s32 var_a2;

    var_a2 = -1;
    var_a1 = 0;
    if (D_0031CD00->f2C > 0) {
        if ((*(s32 *)((u8 *)(D_001D9A20) + 4)) == arg0) {
            var_a2 = 0;
        } else {
loop_4:
            var_a1 += 1;
            if (var_a1 < D_0031CD00->f2C) {
                if ((*(s32 *)((u8 *)(((var_a1 * 0x10) + D_001D9A20)) + 4)) == arg0) {
                    var_a2 = var_a1;
                } else {
                    goto loop_4;
                }
            }
        }
    }
    return var_a2;
}
/* localdecomp:end func_00382380 */

/* localdecomp:start func_003823F0 */
extern s32 func_00382380(s32);

s32 func_003823F0(s32 id) {
    register u8 *gp __asm__("gp");
    s32 index;
    s32 fallback;
    s32** basePtr;

    index = func_00382380(id);
    fallback = (s32)(gp - 0x7128);
    
    // Pattern Library Scheduling Fence: Passing both operands forces the 
    // compiler to completely materialize row 14 BEFORE executing the branch check.
    __asm__ volatile("" : : "r"(index), "r"(fallback));

    if (index < 0) {
        return fallback;
    }
    
    basePtr = (s32**)0x1D9A20; // 0x001E0000 - 0x65E0
    return (*basePtr)[index * 4];
}
/* localdecomp:end func_003823F0 */

/* localdecomp:start func_00382430 */
__asm__(".extern D_001D9A20, 16");
__asm__(".extern D_001D52FC, 16");
extern void *D_001D52FC;
s32 func_00382430(fallback)
s32 fallback;
{
    s32 index = func_00382380(fallback);
    register s32 value __asm__("$4") = *(s16 *)((u8 *)D_001D9A20 + (index * 0x10) + 0xC);
    register s32 result __asm__("$2") = fallback;
    if (value > 0) {
        register u8 flag __asm__("$3");
        result = (s32)D_001D52FC;
        flag = *(volatile u8 *)(result + 0x550);
        result = value;
        __asm__ volatile("" : "+r"(result));
        if (flag == 0) {
            result = fallback;
        }
    }
    return result;
}
/* localdecomp:end func_00382430 */

/* localdecomp:start func_00382488 */
extern s32 func_00382430();
void func_00382488(void) {
    func_003823F0(func_00382430());
}
/* localdecomp:end func_00382488 */

/* localdecomp:start func_003824B0 */
extern s32 D_001D5688;
void func_003824B0(void) { D_001D5688 = 0; }
/* localdecomp:end func_003824B0 */

extern s32 D_001D5680;

/* localdecomp:start func_003824B8 */
extern s32 D_001D5680;
void func_003824B8(void) { D_001D5680 = 10; }
/* localdecomp:end func_003824B8 */

/* localdecomp:start func_003824C8 */
extern void func_00397FB8();
extern u8 D_001D5790[];
 
void func_003824C8(void) {
    func_00397FB8(D_001D5790, 0, 0);
}
/* localdecomp:end func_003824C8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003824F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003826C8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00382734);

/* localdecomp:start func_00382748 */
s32 func_00382748(u8 *p) {
    s32 *q;
    if (p == 0 || (q = *(s32 **)(p + 0x68)) == 0 || !(*(u16 *)(p + 0x34) & 0x20)) {
        return 0;
    }
    return *q;
}
/* localdecomp:end func_00382748 */
