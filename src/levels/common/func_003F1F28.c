#include "common.h"

extern void func_0040C0F0(s32 a, s32 b, f32 x);

typedef int u128_37F420 __attribute__((mode(TI)));
extern void func_0040C0F0(s32 a, s32 b, f32 x);
extern void func_003F1D30();
extern u8 D_001E2AC0_0037F420[];
void func_003F1F28(s32 idx) {
    u128_37F420 v[3];
    u8 *p = D_001E2AC0_0037F420 + idx * 0x460;
    u8 *q = p + 0x150;
    func_0040C0F0((s32)&v[0], *(s32 *)(q + 0xF0) + 0xC0, 1.0f);
    func_0040C0F0((s32)&v[1], *(s32 *)(q + 0xF0) + 0xD0, 1.0f);
    func_0040C0F0((s32)&v[2], *(s32 *)(q + 0xF0) + 0xE0, 1.0f);
    *(u128_37F420 *)(p + 0x330) = v[0];
    *(u128_37F420 *)(p + 0x340) = v[2];
    func_003F1D30(p + 0x310, p + 0x360, p + 0x190, &v[0], &v[1], &v[2]);
    *(u128_37F420 *)(p + 0x350) = *(u128_37F420 *)(p + 0x370);
}
