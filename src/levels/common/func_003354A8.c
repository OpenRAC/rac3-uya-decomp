#include "common.h"

typedef void (*Fn003354A8)(u8 *, s32, s32);

extern void func_00457590(u8 *, u8 *, f32);
extern f32 func_0040C490(f32, f32);
extern void func_00445758(u8 *, u8 *, s32, f32, f32, f32, f32);
extern f32 func_0040BFE8(u8 *, u8 *);
extern void func_00334DF0(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
extern s32 func_0040BA90(u8 *);
extern s32 func_00440878(s32, s32);

s32 func_003354A8(u8 *a0, u8 *a1, u8 *a2, u8 *a3, u8 *a4, u8 *a5, u8 *a6) {
    f32 *rot;
    f32 angle;

    rot = (f32 *)(a2 + 248);
    func_00457590(a2, a3 + 1184, *rot);
    angle = func_0040C490(*(f32 *)(a3 + 1184) - *(f32 *)(a2 + 16),
                          *(f32 *)(a3 + 1188) - *(f32 *)(a2 + 20));
    func_00445758((u8 *)rot, a1 + 116, 0, angle,
                  *(f32 *)(a3 + 420) * 0.2f, *(f32 *)(a3 + 424) * 0.2f,
                  *(f32 *)(a3 + 428) * 0.2f);
    if (func_0040BFE8(a2 + 16, a3 + 1184) < 2.0f) {
        func_00334DF0(a0, a1, a2, a3, a4, a5);
    }
    if (func_0040BA90(a1 + 104)) {
        a0[188] = 1;
        *(s32 *)(a1 + 104) = func_00440878(300, 530);
    }
    if (a5[151] == 0) {
        (*(Fn003354A8 *)(a6 + 36))(a2, 0, 10);
    } else {
        (*(Fn003354A8 *)(a6 + 32))(a2, 0, 10);
    }
    return 0;
}
