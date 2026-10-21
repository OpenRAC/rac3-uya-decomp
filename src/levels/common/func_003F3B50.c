#include "common.h"

/* localdecomp:start func_003F3B50 */
typedef int Q_003F3B50 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003F3B50;
typedef struct {
    u8 pad0[0x80];
    V4_003F3B50 v80;
    u8 pad90[0x98 - 0x90];
    f32 f98;
} G_003F3B50;

extern G_003F3B50 D_001A4BE0;
extern void func_003FB748(s32, V4_003F3B50 *);
extern void func_003FB7B8(s32, V4_003F3B50 *);
extern f32 func_0041CCE0(f32);
extern f32 func_0041CCF8(f32);
extern f32 func_0041D7E0(f32, f32);
extern f32 func_00445940(void *);

void func_003F3B50(u8 *o) {
    V4_003F3B50 a;
    V4_003F3B50 b;
    Q_003F3B50 x, y, r;
    f32 t;
    f32 s;
    f32 ang;
    f32 five;

    if (o[0x42] == 1) {
        t = func_00445940(o);
    } else {
        t = 170.0f;
    }
    s = t / 170.0f;
    five = 5.0f;
    ang = func_0041D7E0(s * 0.6981317f - 0.34906584f, D_001A4BE0.f98);
    a.x = func_0041CCE0(ang) * five;
    a.y = func_0041CCF8(ang) * five;
    a.z = 0.0f;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001A4BE0.v80));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(r));
    t = a.z;
    __asm__("sq $0, %0" : "=m"(b));
    t += 1.0f;
    a.z = t;
    b.z = func_0041D7E0(ang, 3.14159f);
    b.y = s * -0.17f;
    func_003FB748(0, &a);
    func_003FB7B8(0, &b);
}
/* localdecomp:end func_003F3B50 */
