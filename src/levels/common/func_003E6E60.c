#include "common.h"

typedef struct {
    u8 pad0[0x50];
    u8 *p50;
    u8 pad54[1120 - 0x54];
} S_3E6E60;

extern S_3E6E60 D_001E2AC0[];

void func_003E6E60(s32 i, f32 a, f32 b, f32 c) {
    S_3E6E60 *s = &D_001E2AC0[i];
    u8 *p = s->p50;
    u8 *q;
    if (*(s16 *)(p + 134) == 0) {
        q = *(u8 **)(p + 112) + 32;
        *(f32 *)(q + 44) = a;
        *(f32 *)(q + 52) = b * 0.017453292f * 0.00027777778f;
        *(f32 *)(q + 56) = c * 0.017453292f * 0.00027777778f;
    }
}
