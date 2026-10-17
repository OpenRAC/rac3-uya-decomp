#include "common.h"

extern u8 D_001A4BE0[];
extern u8 D_001E9000[];

extern s32 func_004B05A0(f32 *, f32, f32);
extern s32 func_004CB550(s32, s32);
extern f32 func_003DFEF8(f32, f32);
extern f32 func_003E0A18(f32, f32);

s32 func_004E1ED8(void) {
    f32 v[4];
    f32 r;
    u8 *p = D_001A4BE0;
    u8 *q;
    u8 *c;

    if (*(f32 *)(p + 828) < 0.5f) {
        return 0;
    }
    if (!func_004B05A0(v, 0.3f, 2.0f)) {
        return 0;
    }
    r = 4.0f;
    if (*(s32 *)(p + 9668) == 167 || func_004CB550(167, 90)) {
        r = 2.0f;
    }
    if (func_004CB550(169, 10)) {
        r = 2.0f;
    }
    if (!func_004B05A0(v, r, 2.0f)) {
        return 0;
    }
    if (0.1f < v[0]) {
        return 0;
    }
    c = D_001E9000;
    r = func_003DFEF8(*(f32 *)(c + 64), *(f32 *)(c + 68));
    q = D_001A4BE0;
    if (func_003E0A18(r, *(f32 *)(q + 152)) < 1.5707964f) {
        return 0;
    }
    return 1;
}
