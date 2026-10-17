#include "common.h"

typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1120 - 84];
} Ent_003E6D50;

extern Ent_003E6D50 D_001E2AC0[];

void func_003E6D50(s32 i, s32 flag, f32 a, f32 b) {
    Ent_003E6D50 *ent = &D_001E2AC0[i];
    u8 *e = ent->p50;
    u8 *q;
    if (*(s16 *)(e + 134) == 0) {
        q = *(u8 **)(e + 112) + 384;
        *(s16 *)(q + 60) = 1;
        *(f32 *)(q + 72) = b;
        *(f32 *)(q + 64) = a;
        if (flag != 0) {
            *(f32 *)(q + 88) = a;
        }
    }
}
