#include "common.h"

typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

extern void func_0058F7B8(Vec4 *, Vec4 *, void *);

void func_0062FAE0(u8 *g, Vec4 *out, Vec4 *in, f32 scale)
{
    switch (g[6662]) {
    case 0:
        *out = *in;
        out->v[2] *= scale;
        break;
    case 1:
    case 2:
        func_0058F7B8(out, in, g + 96);
        out->v[2] *= scale;
        func_0058F7B8(out, out, g + 32);
        break;
    }
}
