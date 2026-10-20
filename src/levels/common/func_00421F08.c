#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    s128 q10;
} S_421F08r;

typedef struct {
    u8 pad0[0xC];
    void *wC;
    s32 w10;
    u8 pad14[0x30 - 0x14];
} S_421F08e;

typedef struct {
    u8 pad0[0x400];
} S_421F08b;

extern S_421F08e D_001F1CC0[];
extern S_421F08r D_001F1BC0[];
extern S_421F08b D_001F1E40[];
extern void func_0040BBD0(S_421F08e *a0, s32 a1);

s32 func_00421F08(s128 *a0, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16) {
    S_421F08r *r;
    S_421F08e *e;
    s32 i;

    for (i = 0; i < 8 && D_001F1CC0[i].w10 != 0; i++) {
    }
    if (i == 8) {
        return -1;
    }
    r = &D_001F1BC0[i];
    r->q10 = *a0;
    *(f32 *)((u8 *)&r->q10 + 12) = f12;
    r->f0 = f14;
    r->f4 = f15;
    r->f8 = f16;
    r->fC = f13;
    e = &D_001F1CC0[i];
    func_0040BBD0(e, 48);
    e->w10 = 1;
    e->wC = &D_001F1E40[i];
    return i;
}
