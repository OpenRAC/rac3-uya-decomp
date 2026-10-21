#include "common.h"

/* localdecomp:start func_003AC110 */
typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[8];
    u8 unk10[16];
    f32 unk20;
    f32 unk24;
    u8 pad28[8];
} S_003AC110_B;

typedef struct {
    u8 pad0[36];
    s32 unk24;
    S_003AC110_B *unk28;
    u8 pad2C[4];
} S_003AC110_A;

extern f32 func_0040C3E0(f32);
extern void func_0040BE90(u8 *, u8 *, f32);
extern void func_0044B5C8(s32, u8 *, s32, f32, f32);

void func_003AC110(s32 arg0, u8 *obj) {
    u8 *pv;
    s32 i;
    S_003AC110_A *a;
    S_003AC110_B *b;
    u8 *m;
    s32 j;
    f32 f;

    pv = *(u8 **)(obj + 104);
    switch (*(s32 *)(obj + 3136)) {
    case 3:
        *(f32 *)(obj + 3324) -= *(f32 *)(pv + 64);
        if (*(f32 *)(obj + 3324) <= 0.0f) {
            *(s32 *)(obj + 3136) = 0;
        }
        if (*(f32 *)(obj + 3324) < 0.0f) {
            *(f32 *)(obj + 3324) = 0.0f;
        }
        break;
    case 1:
        *(f32 *)(obj + 3324) += *(f32 *)(pv + 60);
        if (1.0f <= *(f32 *)(obj + 3324)) {
            *(s32 *)(obj + 3136) = 2;
        }
        if (1.0f < *(f32 *)(obj + 3324)) {
            *(f32 *)(obj + 3324) = 1.0f;
        }
        break;
    case 2:
        break;
    case 0:
        break;
    }
    a = *(S_003AC110_A **)(pv + 56);
    for (i = 0; i < *(s32 *)(pv + 52); i++, a++) {
        if (a->unk24 != 0) {
            b = a->unk28;
            for (j = 0; j < a->unk24; j++, b++) {
                m = obj + (b->unk4 * 128 + 160);
                f = func_0040C3E0(*(f32 *)(obj + 3328) + b->unk20);
                func_0040BE90(m + 96, b->unk10, *(f32 *)(obj + 3324) * (f * b->unk24 + 1.0f));
                func_0044B5C8(*(s32 *)(obj + 100), m, b->unk0, 0.03f, 0.3f);
            }
        }
    }
}
/* localdecomp:end func_003AC110 */
