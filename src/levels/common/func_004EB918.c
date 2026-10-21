#include "common.h"

/* localdecomp:start func_004EB918 */
typedef int Q_4EB918 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4EB918;
typedef struct {
    V_4EB918 v0;
    u8 pad10[592];
    V_4EB918 v608;
    u8 pad630[8912];
    s32 f9536;
} G_4EB918;
extern s32 D_001D673C;
extern s32 D_001A71A0[];
extern V_4EB918 D_001A4EC0;
extern G_4EB918 D_001A4C60;
extern void func_0040C0F0(void *, s32, f32);
extern void func_00447650(V_4EB918, V_4EB918 *);
void func_004EB918(V_4EB918 *p0, V_4EB918 *p1, s32 flag, f32 fa, f32 fb) {
    V_4EB918 t, u;
    Q_4EB918 a, b, c, d, e, f;
    if (flag != 0) {
        if (D_001D673C != 0) {
            func_0040C0F0(&t, (s32)&D_001A4EC0, -fb);
        } else {
            func_0040C0F0(&t, D_001A71A0[0] + 224, fb);
        }
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(t));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(D_001A4C60.v0));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(b), "j"(a));
        __asm__("sqc2 %1, %0" : "=m"(*p1) : "j"(c));
        if (D_001D673C != 0) {
            func_0040C0F0(&t, (s32)&D_001A4C60.v608, -fa);
        } else {
            func_0040C0F0(&t, D_001A4C60.f9536 + 224, fa);
        }
        __asm__("lqc2 %0, %1" : "=j"(d) : "m"(t));
        __asm__("lqc2 %0, %1" : "=j"(e) : "m"(D_001A4C60.v0));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(f) : "j"(e), "j"(d));
        __asm__("sqc2 %1, %0" : "=m"(*p0) : "j"(f));
        u = *p0;
        func_00447650(u, p1);
    } else {
        t = D_001A4C60.v0;
        *p1 = t;
        p1->z = p1->z + fb;
        if (p1->z < 0.0f) {
            p1->z = 0.0f;
        }
        *p0 = t;
        p0->z = p0->z + fa;
    }
}
/* localdecomp:end func_004EB918 */
