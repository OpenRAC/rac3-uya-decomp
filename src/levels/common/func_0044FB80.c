#include "common.h"

typedef int s128_44FB80 __attribute__((mode(TI)));

typedef union {
    s128_44FB80 q;
    f32 f[4];
} Vec_0044FB80;

extern s32 func_003F8448(Vec_0044FB80 *, Vec_0044FB80 *, s32, u8 *, s32);
extern u16 func_003FC730(void);

void func_0044FB80(u8 *m, u8 *o) {
    Vec_0044FB80 top;
    Vec_0044FB80 bot;
    u8 *p;

    *(s16 *)(o + 58) = -1;
    if (o[73] == 0) {
        return;
    }
    p = *(u8 **)(*(u8 **)(m + 104) + 28);
    if (p != 0) {
        if (*(f32 *)(m + 24) - *(f32 *)(p + 144) < 0.5f) {
            *(s16 *)(o + 58) = *(u16 *)(p + 216);
        }
        return;
    }
    bot.q = top.q = *(s128_44FB80 *)(m + 16);
    top.f[2] += 1.0f;
    bot.f[2] -= 0.5f;
    if (func_003F8448(&top, &bot, 31, m, 0) != 0) {
        *(s16 *)(o + 58) = func_003FC730();
    }
}
