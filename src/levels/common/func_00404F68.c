#include "common.h"

extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040CEC8(f32, f32);
extern long func_00401CD0(s32);
extern void func_00404F68(s32, s32, s32, s32, s32 *, s32 *, s32, s32, f32, f32);

typedef struct { f32 x, y, z, w; } V_387DC8;
extern void func_00404BA0(long *, s32 *, s32 *, long, s32);
void func_00404F68(s32 x, s32 y, s32 rx, s32 ry, s32 *a4, s32 *a5, s32 col, s32 n, f32 a0, f32 a1) {
    long base = 0xFFFFF000000000;
    long pts[4];
    V_387DC8 v0, v1;
    long c;
    f32 step, ang, ang2;
    s32 i;
    c = func_00401CD0(col);
    step = (a1 - a0) / (f32)n;
    ang = ((f32 (*)(f32, f32))func_0040CEC8)(a0, 1.5707964f);
    ang2 = ((f32 (*)(f32, f32))func_0040CEC8)(ang, step);
    for (i = 15; i >= 0; i--) {
        v0.x = func_0040C3C8(ang);
        v0.y = func_0040C3E0(ang);
        v0.z = 0.0f;
        v1.x = func_0040C3C8(ang2);
        v1.y = func_0040C3E0(ang2);
        v1.z = 0.0f;
        ang = ang2;
        pts[0] = ((long)(s32)(v0.x * (f32)rx) + x) + (((long)(s32)(v0.y * (f32)rx) + y) << 16) + base;
        pts[1] = ((long)(s32)(v0.x * (f32)ry) + x) + (((long)(s32)(v0.y * (f32)ry) + y) << 16) + base;
        pts[2] = ((long)(s32)(v1.x * (f32)rx) + x) + (((long)(s32)(v1.y * (f32)rx) + y) << 16) + base;
        pts[3] = ((long)(s32)(v1.x * (f32)ry) + x) + (((long)(s32)(v1.y * (f32)ry) + y) << 16) + base;
        func_00404BA0(pts, a5, a4, c, 1);
        ang2 = ((f32 (*)(f32, f32))func_0040CEC8)(ang, step);
    }
}
