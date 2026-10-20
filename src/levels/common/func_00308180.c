#include "common.h"

extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);

void func_00308180(s32 a0, f32 *e, s32 n)
{
    s32 i;
    f32 *p;

    for (i = 0; i < n; i++) {
        p = &e[i * 32];
        p[0] = func_0040CEC8(p[0], p[3]);
        p[1] = func_0040CEC8(p[1], p[4]);
        p[2] = func_0040CEC8(p[2], p[5]);
        p[9] = func_0040CEC8(p[9], p[12]);
        p[10] = func_0040CEC8(p[10], p[13]);
        p[11] = func_0040CEC8(p[11], p[14]);
        p[20] = func_0040C3C8(p[0]) * p[6];
        p[21] = func_0040C3E0(p[1]) * p[7];
        p[22] = -func_0040C3E0(p[2]) * p[8];
        p[24] = func_0040C3C8(p[9]) * p[15];
        p[25] = func_0040C3E0(p[10]) * p[16];
        p[26] = -func_0040C3E0(p[11]) * p[17];
    }
}
