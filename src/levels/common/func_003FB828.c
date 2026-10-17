#include "common.h"

typedef struct {
    u8 pad0[80];
    u8 *p50;
    u8 pad54[1120 - 84];
} S_3FB828;

extern S_3FB828 D_001E28C0[];
extern u8 *func_00402308(s32 a0, s32 a1);

void func_003FB828(s32 idx, f32 a, f32 b) {
    S_3FB828 *e = &D_001E28C0[idx];
    u8 *p;

    if (*(s16 *)(e->p50 + 134) != 5) {
        p = func_00402308(idx, 5);
    } else {
        p = e->p50;
    }
    p = *(u8 **)(p + 112) + 224;
    *(f32 *)(p + 68) = a;
    *(f32 *)(p + 72) = b;
}
