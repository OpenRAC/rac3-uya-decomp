#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

typedef struct {
    Vec4 v0;
    Vec4 pos;
    Vec4 v32;
    u8 pad48[32];
    s32 w80;
    u8 pad84[20];
    u8 *pvars;
} Moby_4559A8;

extern s32 D_001EAA98[];

extern s32 func_003F8448(Vec4 *a, Vec4 *b, s32 flags, Moby_4559A8 *moby, s32 e);

void func_004559A8(Moby_4559A8 *moby, Moby_4559A8 *other) {
    Vec4 v[2];
    u8 *p = *(u8 **)(moby->pvars + 28);
    if (p == 0) {
        return;
    }
    v[0].q = moby->pos.q;
    v[1].q = other->pos.q;
    v[0].f[2] += 0.1f;
    v[0].f[2] += *(f32 *)(p + 8);
    v[1].f[2] += *(f32 *)(p + 8);
    if (func_003F8448(&v[0], &v[1], 16, moby, 0) != 0) {
        if (D_001EAA98[0] == 0) {
            return;
        }
        if (D_001EAA98[0] != other->w80) {
            return;
        }
    }
    other->v0.q = other->pos.q;
    other->v32.q = other->pos.q;
}
