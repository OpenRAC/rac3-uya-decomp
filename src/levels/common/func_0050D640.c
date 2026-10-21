#include "common.h"

/* localdecomp:start func_0050D640 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

extern u8 D_001A4BE0[];
extern void func_0040C2F8(Vec4 *, Vec4 *, void *);

void func_0050D640(Vec4 *out, Vec4 *in, f32 scale)
{
    u8 *g = D_001A4BE0;

    switch (g[9716]) {
    case 0:
        *out = *in;
        out->v[2] *= scale;
        break;
    case 1:
    case 2:
        func_0040C2F8(out, in, g + 64);
        out->v[2] *= scale;
        func_0040C2F8(out, out, g);
        break;
    }
}
/* localdecomp:end func_0050D640 */
