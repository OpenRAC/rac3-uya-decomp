#include "common.h"

extern s32 func_0044B4B8(void *);
extern s32 func_004006D8(void *);
extern f32 func_00434788(f32, f32);
extern f32 func_00434730(f32, f32);
extern s32 func_004346B8(s32);
extern s32 func_004346E8(s32, s32);
extern void func_003330A8(void *, void *);
extern u8 D_001A4CC0[];

void func_00333288(u8 *arg0) {
    u8 *s0;
    s32 a0;
    s32 a1;
    f32 f20;
    f32 x;
    f32 y;

    s0 = *(u8 **)(arg0 + 104);
    func_0044B4B8(arg0);
    if (arg0[49] == 0) {
        return;
    }
    if (func_004006D8(s0 + 884) != 0) {
        if (arg0[149] == 2) {
            *(f32 *)(s0 + 888) = func_00434788(0.08726646f, 1.0471976f);
            *(f32 *)(s0 + 892) = func_00434730(-0.34906584f, 0.0f);
            a0 = 30;
            a1 = 45;
        } else if (func_004346B8(4) == 0) {
            *(s32 *)(s0 + 896) = 1;
            *(s32 *)(s0 + 884) = func_004346E8(180, 300);
            goto check;
        } else {
            f20 = 0.08726646f;
            *(f32 *)(s0 + 888) = func_00434788(f20, 0.34906584f);
            *(f32 *)(s0 + 892) = func_00434730(-0.2617994f, f20);
            a0 = 60;
            a1 = 120;
        }
        *(s32 *)(s0 + 884) = func_004346E8(a0, a1);
        *(s32 *)(s0 + 896) = 0;
    }
check:
    if (*(s32 *)(s0 + 896) != 0) {
        func_003330A8(arg0, D_001A4CC0);
    } else {
        x = *(f32 *)(s0 + 892);
        y = *(f32 *)(s0 + 888);
        *(f32 *)(s0 + 788) = x;
        *(f32 *)(s0 + 792) = y;
        *(f32 *)(s0 + 660) = x;
        *(f32 *)(s0 + 664) = y;
    }
}
