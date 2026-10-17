#include "common.h"

extern u8 D_001A4BE0[];
extern void func_0040C2F8(f32 *, f32 *, void *);

void func_0050D6D0(f32 *v, f32 *out, f32 s) {
    u8 *p = D_001A4BE0;

    switch (p[9716]) {
    case 0:
        v[0] = v[0] * s;
        v[1] = v[1] * s;
        break;
    case 1:
    case 2:
        func_0040C2F8(v, out, p + 64);
        v[0] = v[0] * s;
        v[1] = v[1] * s;
        func_0040C2F8(v, v, p);
        break;
    }
}
