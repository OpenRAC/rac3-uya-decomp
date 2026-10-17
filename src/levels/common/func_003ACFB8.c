#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern void func_003FDB28(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3,
                          f32 f0, f32 f1, f32 f2);
extern void func_003FD928(void *p, s32 a, u32 color, s32 b, f32 f0, f32 f1, f32 f2);

void func_003ACFB8(u8 *moby) {
    u128_t v[2];
    u8 *pvars = *(u8 **)(moby + 104);
    v[0] = *(u128_t *)(moby + 16);
    v[1] = *(u128_t *)(pvars + 96);
    func_003FDB28(&v[0], &v[1], 14, 1, 0x401010FF, 0x401010FF, 0x401010FF, 0x401010FF, 0.05f, 1.0f, 0.5f);
    func_003FD928(pvars + 96, 6, 0x401010FF, 1, 0.175f, 0.08f, 0.0f);
}
