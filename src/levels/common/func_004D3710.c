#include "common.h"

extern s32 func_0013B620(void);
extern void func_0040BBA8();
extern void func_0011F0A0();
extern void func_0013CA28();
extern void func_0013BED0();
extern s32 D_001D6694;
extern void func_0011F0A0(s32);

typedef struct { u8 p0[0x18]; s16 f18; u8 p1A[0x142]; s32 f15C; s32 f160; s32 f164; u8 p168[0x14]; s32 f17C; } S_142430_3B78C8;
typedef struct { u8 p0[7]; u8 f7; u8 p8[8]; } S_1CCFD0_3B78C8;
typedef struct { u8 p0[0x10]; u32 f10; } S_2276C0_3B78C8;
typedef struct { u8 p0[0x90]; s32 f90[6]; } S_1A30B0_3B78C8;
extern s32 D_001D6694;
extern s32 D_001DFBEC;
extern s32 D_001D4CEC;
extern s32 D_001D545C;
extern s32 D_001DFBC4;
extern u8 D_001EA8C0[];
extern S_2276C0_3B78C8 D_001EAA80;
extern S_1A30B0_3B78C8 D_001A30B0;
extern S_142430_3B78C8 D_00142430;
extern S_1CCFD0_3B78C8 D_001CCFD0;
extern void func_0040BBA8();
extern void func_004374C8();
extern void func_0011F0A0();
extern void func_0013CF80(s32, s32, s32, s32, s32);
extern void func_0013CA28(void);
extern void func_004A7810(void);
extern void func_0045BEC8(void);
extern void func_0013BF00(s32);
extern void func_0013BED0(void);
extern void func_004304B0(void);
extern void func_0042EFF8(void);
extern s32 func_0013CF40(s32);
extern void func_0045CA60(s32);
extern void func_00402A10(s32);
extern void func_00428008(void);
extern void func_0013CDF0(s32);
extern void func_004C2898(void);
void func_004D3710(void) {
    s32 i;
    func_0040BBA8(D_001EA8C0, -1, 0x80);
    D_001EAA80.f10 |= 0x80000000;
    D_001D6694 = 6;
    func_004374C8();
    func_0011F0A0(0);
    func_0013CF80(2, 0, 0, 0, 0);
    func_0013CA28();
    func_0013B620();
    func_004A7810();
    func_0045BEC8();
    D_001CCFD0.f7 = 1;
    for (i = 0; i < 6; i++) {
        if (D_001A30B0.f90[i] != 0) {
            func_0013BF00(D_001A30B0.f90[i]);
            func_0013BED0();
            D_001DFBEC = 0;
            D_001A30B0.f90[i] = 0;
        }
    }
    while (D_00142430.f15C >= 3 || D_00142430.f164 >= 0) {
        func_004304B0();
        func_0042EFF8();
    }
    if (D_00142430.f17C != 0) D_00142430.f17C = 0;
    if (D_00142430.f18 >= 0) D_00142430.f18 = -1;
    D_001D4CEC &= ~0x200;
    func_0013CF40(0);
    D_001CCFD0.f7 = 0;
    func_0045CA60(1);
    do {} while (((s32 (*)(void))func_0013B620)());
    D_001CCFD0.f7 = 1;
    func_00402A10(6);
    D_001D545C = D_001DFBC4;
    func_00428008();
    func_0013CDF0(0);
    D_001CCFD0.f7 = 0;
    func_004C2898();
}
