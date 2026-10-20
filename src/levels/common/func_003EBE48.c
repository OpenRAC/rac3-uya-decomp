#include "common.h"

typedef struct {
    u8 pad0[80];
    u8 *unk50;
    u8 pad54[252];
    u8 unk150[784];
} S_001E2AC0;

extern S_001E2AC0 D_001E2AC0[];
extern u8 *D_001DF884;
extern u8 *D_001E0180;
extern f32 func_0040BFE8(u8 *, u8 *);
extern s32 func_00440760(u8 *, s32, s32);
extern s32 func_00448D50(u8 *, s32);
extern s32 func_00448E00(u8 *, s32);

s32 func_003EBE48(u8 *obj) {
    u8 *s;
    S_001E2AC0 *p;
    u8 *e;
    u8 *m;
    u8 *a;
    u8 *b;
    s32 r;

    s = *(u8 **)(D_001DF884 + *(s16 *)(obj + 132) * 32 + 28);
    p = &D_001E2AC0[*(s32 *)(obj + 148)];
    m = p->unk50;
    e = p->unk150;
    a = *(u8 **)(m + 112) + 384;
    b = *(u8 **)(m + 112) + 480;
    if (*(s16 *)(m + 134) != 0) {
        goto fail;
    }
    r = e[299] == 1 || e[299] == 2;
    if (*(s16 *)(s + 74) != 0 && !r) {
        return 0;
    }
    if (*(s16 *)(s + 72) != 0 && r) {
        return 0;
    }
    if (*(s32 *)(s + 52) != 0) {
        if (0.01f < __builtin_fabsf(*(f32 *)(a + 52))) {
            return 0;
        }
        if (0.01f < __builtin_fabsf(*(f32 *)(b + 8))) {
            return 0;
        }
    }
    if ((u32)(*(s32 *)(e + 256) - 102) >= 2 && 0.016666668f < *(f32 *)(e + 272)) {
fail:
        return 0;
    }
    if (*(s32 *)(s + 12) >= 0) {
        if (*(s32 *)(e + 256) == 102 &&
            func_0040BFE8(e + 64, D_001E0180 + *(s32 *)(s + 12) * 128 + 48) < 3.0f) {
            return 1;
        }
        if (func_00440760(e + 64, *(s32 *)(s + 12), 0) != 0) {
            return 1;
        }
    }
    if (*(s32 *)(s + 16) >= 0) {
        if (*(s32 *)(e + 256) == 102 &&
            func_0040BFE8(e + 64, D_001E0180 + *(s32 *)(s + 16) * 128 + 48) < 3.0f) {
            return 1;
        }
        if (func_00448D50(e + 64, *(s32 *)(s + 16)) != 0) {
            return 1;
        }
    }
    if (*(s32 *)(s + 8) >= 0) {
        if (*(s32 *)(e + 256) == 102 &&
            func_0040BFE8(e + 64, D_001E0180 + *(s32 *)(s + 8) * 128 + 48) < 3.0f) {
            return 1;
        }
        if (func_00448E00(e + 64, *(s32 *)(s + 8)) != 0) {
            return 1;
        }
    }
    *(s16 *)(s + 38) = 1;
    return 0;
}
