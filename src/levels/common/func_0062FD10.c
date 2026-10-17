#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

typedef struct {
    u8 pad[32];
    u8 m20[64];
    u8 m60[6662 - 96];
    u8 mode;
} S_62FD10;

extern void func_0058F7B8(Vec4 *, Vec4 *, void *);

void func_0062FD10(S_62FD10 *s, Vec4 *out, Vec4 *in, f32 z) {
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
        func_0058F7B8(out, in, s->m60);
        out->f[2] = z;
        func_0058F7B8(out, out, s->m20);
    }
}
