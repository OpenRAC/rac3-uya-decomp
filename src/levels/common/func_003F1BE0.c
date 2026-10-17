#include "common.h"

typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_001E2AC0[];
typedef struct { s32 a, b, c, d, e; } S_37D000;
extern S_37D000 D_002F7700[];

extern u8 D_001E3050_0037F0D8[];
extern u8 D_001DF910_0037F0D8[8];
extern void func_003F1B98(u8 *);
extern s32 func_003F1988(s32, u8 *, u8 *);
extern void func_003F1670(u8 *, s32);
extern void func_003F1550(s32, void *);
extern void func_003F12C0(s32);
s32 func_003F1BE0(s32 a) {
    s32 found = 0;
    s32 i;
    u8 *cur = (u8 *)((S_00222500_0037E7D8 *)(a * 0x460 + (s32)D_001E2AC0))->f50;
    u8 *p;
    u8 *q;
    void (*f)(u8 *);
    f32 *src;
    f32 *dst;
    func_003F1B98(cur);
    p = (u8 *)(a * 0x2100 + (s32)D_001E3050_0037F0D8);
    q = (u8 *)(a * 0x30 + (s32)D_001DF910_0037F0D8);
    for (i = 0; i < 48; i++) {
        if (*q != 0 && p != cur && func_003F1988(a, p, cur) != 0) {
            cur = p;
            found = 1;
        }
        p += 0xB0;
        q++;
    }
    if (found != 0) {
        func_003F1670(cur, 0);
    }
    f = (void (*)(u8 *))D_002F7700[*(s16 *)(cur + 0x8C)].d;
    func_003F1550(a, cur);
    if (f != 0) {
        f(cur);
    }
    src = (f32 *)(cur + 0x30);
    dst = (f32 *)(cur + 0x64);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    func_003F12C0(a);
    return -1;
}
