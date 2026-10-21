#include "common.h"

/* localdecomp:start func_004951B8 */
extern void func_004951B8();

typedef struct { u8 p0[0x10]; s32 f10; s32 f14; s32 f18; u8 p1C[4]; f32 a20[4]; f32 a30[4]; f32 a40[4]; f32 f50; f32 f54; u8 p58[4]; f32 f5C; f32 f60; u8 p64[8]; f32 f6C; f32 f70; u8 p74[0x28]; u32 f9C; f32 fA0; f32 fA4; u8 pA8[4]; f32 fAC; } S_3B49E8;
extern void func_00514D50();
extern s32 func_00513548(s32, f32, f32);
extern void func_00514660_003B49E8(s32, s32);
extern s32 func_005139B0(s32, s32);
extern s32 func_005148E8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_00513EA8(s32, f32, f32);
extern s32 func_00514020(s32, s32);
extern s32 func_00512E20(s32, s32);
extern s32 func_00514A38_003B49E8(s32, u32, f32, f32, f32, f32, s32);
extern s32 func_005147F0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_005140D0(s32, s32, s32);
extern s32 func_00512D70(s32, s32);
extern s32 func_005136D8(s32, s32);
void func_004951B8(S_3B49E8 *o) {
    s32 j, i;
    u32 k;
    f32 t;
    func_00495180((u8 *)o);
    func_00514D50(0x4F00A8);
    func_00513548(0x4F00A8, 0.5f, 0.5f);
    func_00514660_003B49E8(0x4F00A8, 1);
    func_00514D50(0x4F00AE);
    func_005139B0(0x4F00A8, 0x4F00AE);
    for (j = 0; j < o->f14; j++) {
        func_00514D50(func_004950F8((s32)o, j));
        func_005139B0(0x4F00A8, func_004950F8((s32)o, j));
        for (i = 0; i < o->f10 + 2; i++) {
            func_005148E8(func_004950C8(o, j, i), func_004950A8(o, j, i), 0x8066CCFF, o->a20[j], o->f50 + (f32)i * o->f54, o->fAC, o->fAC);
            func_00513EA8(func_004950C8(o, j, i), o->a40[j], o->a30[j]);
            func_00514020(func_004950C8(o, j, i), 1);
            func_00512E20(func_004950C8(o, j, i), 1);
            func_005139B0(func_004950F8((s32)o, j), func_004950C8(o, j, i));
        }
    }
    t = o->f60 - o->fA0;
    if (t < 0.0f) t = 0.0f;
    func_00514D50(0x4F00AD);
    func_005139B0(0x4F00A8, 0x4F00AD);
    o->f9C = o->f10 + 3;
    for (k = 0; k < o->f9C; k++) {
        func_00514A38_003B49E8(func_004950E8((s32)o, k), 0x331465B7, o->f5C, o->f50 + (f32)(k - 1) * o->f54 + o->f70, t, o->fA4, 0);
        func_005139B0(0x4F00AD, func_004950E8((s32)o, k));
    }
    func_00514A38_003B49E8(0x4F00AF, 0x706EC8FF, 0.5f, 0.5f, 1.0f, 0.1f, 0);
    func_005139B0(0x4F00AE, 0x4F00AF);
    func_005147F0(0x4F00B0, 0x80, 0x331465B7, 0.5f, 0.5f, 1.0f, 0.6f, o->f6C);
    func_005147F0(0x4F00B1, 0x80, 0x331465B7, 0.5f, 0.5f, 1.0f, -0.6f, o->f6C);
    func_005140D0(0x4F00AE, 0x4F00B0, 0x4F00B1);
    func_00514A38_003B49E8(0x4F00B3, 0x70000000, 0.5f, 0.5f, 0.25f, 0.25f, 0);
    func_00512D70(0x4F00B3, 0);
    func_005139B0(0x4F00A8, 0x4F00B3);
    func_005136D8(o->f18, 0x4F00A8);
}
/* localdecomp:end func_004951B8 */
