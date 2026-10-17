#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

typedef struct {
    u8 m0[64];
    u8 m40[9716 - 64];
    u8 mode;
} S_50D530;

extern S_50D530 D_001A4BE0;
extern void func_0040C2F8(Vec4 *, Vec4 *, void *);

void func_0050D530(Vec4 *out, Vec4 *in, f32 z) {
    S_50D530 *s = &D_001A4BE0;
    s32 m = s->mode;

    if (m == 0) {
        out->q = in->q;
        out->f[2] = z;
        return;
    }
    if (m < 0) {
        return;
    }
    if (m < 3) {
        func_0040C2F8(out, in, s->m40);
        out->f[2] = z;
        func_0040C2F8(out, out, s->m0);
    }
}
