#include "common.h"

typedef int Q_003E19F0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E19F0;

extern void func_003FB748(s32 a0, V4_003E19F0 *v);
extern void func_003FB7B8(s32 a0, V4_003E19F0 *v);
extern f32 func_0041CCE0(f32);
extern f32 func_0041CCF8(f32);
extern f32 func_0041D7E0(f32, f32);
extern f32 func_00445940(void *a0);
extern u8 D_001A4BE0[];

void func_003E19F0(u8 *a0) {
    V4_003E19F0 v;
    V4_003E19F0 u;
    f32 f;
    f32 s;
    f32 ang;
    f32 k;
    f32 z;
    u8 *g;
    Q_003E19F0 x, y, r;

    if (a0[0x42] == 1) {
        f = func_00445940(a0);
    } else {
        f = 170.0f;
    }
    s = f / 170.0f;
    g = D_001A4BE0;
    k = 5.0f;
    ang = func_0041D7E0(s * 0.6981317f - 0.34906584f, *(f32 *)(g + 0x98));
    v.x = func_0041CCE0(ang) * k;
    v.y = func_0041CCF8(ang) * k;
    v.z = 0.0f;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_003E19F0 *)(g + 0x80)));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(r));
    z = v.z;
    __asm__("sq $0, %0" : "=m"(u));
    v.z = z + 1.0f;
    u.z = func_0041D7E0(ang, 3.1415927f);
    u.y = s * -0.17f;
    func_003FB748(0, &v);
    func_003FB7B8(0, &u);
}
