#include "common.h"

typedef struct {
    char pad0[656];
    f32 a;
    f32 b;
    f32 c;
} Data00351688;

typedef struct {
    char pad0[104];
    Data00351688 *data;
} Moby00351688;

extern u8 D_001A4BE0[];
extern void func_00350D08(Moby00351688 *);

void func_00351688(Moby00351688 *m)
{
    Data00351688 *d = m->data;
    u8 *g;

    d->a -= d->a * 0.050000004f;
    if (__builtin_fabsf(d->a) < 0.001f)
        d->a = 0.0f;
    d->b -= d->b * 0.050000004f;
    if (__builtin_fabsf(d->b) < 0.001f)
        d->b = 0.0f;
    d->c -= 0.0027222224f;
    g = D_001A4BE0;
    if (*(s32 *)(g + 9668) != 49 || *(Moby00351688 **)(g + 6624) != m)
        d->c -= 0.0027222224f;
    func_00350D08(m);
}
