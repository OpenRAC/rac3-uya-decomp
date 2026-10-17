#include "common.h"

extern f32 func_0040C3E0(f32);

/* MATCH */
typedef int u128_3B8440 __attribute__((mode(TI)));
extern s32 D_001E1350_003B8440[2];
extern f32 D_001E136C;
extern s32 D_001E1360_003B8440;
extern f32 D_001E1364_003B8440;
extern f32 D_001E1368_003B8440;
extern void func_004D4108(void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00437698_003B8440(void *, s32, void *);
extern void func_0040CEC8(f32, f32);
extern f32 func_0040C3E0(f32);
extern void func_00402498(void (*)(), s32);
extern void func_004D40C8(void);
void func_004D4288(u8 *p) {
    u128_3B8440 v;
    s32 k;
    s32 m;
    f32 f;
    *(u16 *)(p + 0x34) |= 0x10;
    func_004D4108(p, 0x38, 0x88, 0x40, 0x80, 0x18, 0x40, 0x18, 0x64);
    k = *(s16 *)(p + 0xAA);
    if (k == 10) m = 1; else { s32 e = k ^ 0x259; m = e ? 0 : 8; }
    func_00437698_003B8440(p, m, &v);
    f = ((f32 (*)(f32, f32))func_0040CEC8)(D_001E136C, 0.06690429151058197f);
    D_001E136C = f;
    f = (func_0040C3E0(f) * 0.5f + 0.5f) * 13.0f;
    *(u128_3B8440 *)D_001E1350_003B8440 = v;
    D_001E1364_003B8440 = 0.04f;
    D_001E1368_003B8440 = 0.07f;
    D_001E1360_003B8440 = (((s32)f + 0x17) << 24) | 0xC0;
    func_00402498(func_004D40C8, (s32)p);
}
