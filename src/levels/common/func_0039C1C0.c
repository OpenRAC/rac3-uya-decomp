#include "common.h"

typedef int Q_39C1C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_39C1C0;

extern f32 func_00440978(void);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440878(s32, s32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern u8 *func_00467BD8(void *, s32, s32, f32, f32, s32);

/* localdecomp:start func_0039C1C0 */
void func_0039C1C0(V_39C1C0 *c) {
    s32 i = 0;
    do {
        V_39C1C0 v;
        Q_39C1C0 a, b;
        s32 n;
        f32 ang, r, h, s;
        u8 *p;
        i--;
        ang = func_00440978();
        r = func_004408C0(0.0f, 0.6f);
        h = func_004408C0(0.0f, 1.5f);
        s = func_004408C0(1.0f, 5.0f);
        n = func_00440878(100, 160);
        v.x = func_0040C3C8(ang) * r;
        v.y = func_0040C3E0(ang) * r;
        v.z = 0.0f;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*c));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(v));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(b) : "j"(b), "j"(a));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(b) : "memory");
        p = func_00467BD8(&v, 0x5005C162, 0x5C162, h, s, n);
        if (p != 0) {
            p[3] = 0x44;
        }
    } while (i >= 0);
}
/* localdecomp:end func_0039C1C0 */
