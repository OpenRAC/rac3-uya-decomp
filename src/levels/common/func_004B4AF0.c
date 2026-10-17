#include "common.h"

extern void func_004B4AF0();
extern u8 D_00160C40_003A3368[];
extern u8 D_00142BA0[];
extern u8 D_00143A07[];
extern s32 func_004AD7B0(s32);

extern s32 func_004AD7B0(s32);
extern s32 D_001E0F9C;
extern u8 D_00142BA0[];
extern s32 D_001EA840[];
extern u8 D_00143A07[];
extern u8 D_00160C40_003A3368[];
extern void func_00417B68(s32 *);
extern void func_004B4BB8(s32, s32, s32, s32, s32);
void func_004B4AF0(s32 arg) {
    u32 *p;
    s32 idx;
    s32 v;
    s32 d;
    s32 x;
    s32 arr;
    u8 *q;
    s32 f;
    if (arg < 0) {
        D_001E0F9C = 0;
        return;
    }
    idx = func_004AD7B0(arg);
    p = (u32 *)(D_00142BA0 + (((u32)arg >> 2) << 2));
    *p |= 1 << (arg & 0x1F);
    func_00417B68(D_001EA840);
    q = D_00160C40_003A3368;
    arr = (s32)q + 8;
    x = (idx * 4 + 2) << 2;
    v = *(s32 *)(x + arr);
    d = D_00143A07[0];
    if (D_001EA840[0]) d = 0;
    f = idx == 0x1F;
    func_004B4BB8(v + *(s32 *)(q + 4), *(s32 *)(D_00160C40_003A3368 + x + 0xC), (idx << 4) + arr, d, f);
}
