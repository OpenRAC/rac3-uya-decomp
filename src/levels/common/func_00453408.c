#include "common.h"

typedef struct {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    u8 pad18[0xAA - 0x18];
    s16 h170;
    u8 padAC[0xF8 - 0xAC];
    f32 f248;
} M_453408;

typedef struct {
    u8 pad0[0x2F];
    u8 b47;
} V_453408;

extern s32 D_001D673C;
extern M_453408 *D_001A71A0[];
extern f32 func_0040BFE8(void *a, void *b);
extern f32 func_0040BFB0(void *a, void *b);
extern f32 func_0040C490(f32 x, f32 y);
extern f32 func_0040CFB0(f32 a, f32 b);
extern V_453408 *func_00440728(M_453408 *m);
extern s32 func_003F8448(void *a, void *b, s32 c, M_453408 *m, s32 e);

f32 func_00453408(M_453408 *a, M_453408 *b, s32 c, s32 d, s32 e, s32 g, f32 scale) {
    f32 dist;
    f32 r;
    V_453408 *v;

    r = func_0040BFE8(&a->x, &b->x);
    if (D_001D673C != 0) {
        r = func_0040BFB0(&a->x, &b->x);
    }
    dist = r;
    if (D_001D673C == 0) {
        dist += func_0040CFB0(func_0040C490(b->x - a->x, b->y - a->y), a->f248) * dist * scale;
    }
    if (b == D_001A71A0[0]) {
        v = func_00440728(a);
        if (c != 0) {
            dist = 9999999.0f;
        } else if ((v != 0 && v->b47 != 0) || d != 0) {
            dist = 999999.0f;
        } else {
            if (!(a->h170 >= 6503 && a->h170 <= 6505) && g == 0) {
                dist -= 20.0f;
                if (dist < 0.0f) {
                    dist = 0.0f;
                }
            }
        }
        if (a->h170 == 6598) {
            dist += 900.0f;
        }
    }
    if (e != 0 && func_003F8448(&a->x, &b->x, 2, a, 0) != 0) {
        dist = 999999.0f;
    }
    if (b->h170 == 6598 && a->h170 == b->h170) {
        dist += 10000.0f;
    }
    return dist;
}
