#include "common.h"

/* localdecomp:start func_003DDB38 */
typedef int Q_3DDB38 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DDB38;
typedef struct {
    V4_3DDB38 v0;
    V4_3DDB38 v10;
    s32 f20;
    s32 pad24;
    f32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    f32 f40;
    f32 f44;
    f32 f48;
    s32 pad4C;
} S_3DDB38;
extern S_3DDB38 D_002A3AC0[];
extern V4_3DDB38 D_001E2A40;
extern void func_00440B30(void *, f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
void func_003DDB38(s32 a, V4_3DDB38 *pos, s32 b, s32 c, s32 d, s32 e, s32 g, f32 f1, f32 f2, f32 f3, f32 f4) {
    S_3DDB38 *p;
    s32 i;
    V4_3DDB38 v;
    Q_3DDB38 x, y, z;
    for (i = 0; i < 24; i++) {
        p = &D_002A3AC0[i];
        if (p->f20 == 0) {
            p->f20 = a;
            p->f28 = f1;
            p->f30 = c;
            p->f34 = d;
            p->f38 = e;
            p->f3C = g;
            p->f40 = f2;
            p->f44 = f3;
            p->f2C = b;
            p->f48 = f4;
            func_00440B30(p, 1.0f, 1.0f);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(v) : "j"(z));
            func_0040C0F0(&v, &v, 1.0f);
            func_0040BF20(&p->v10, p, &v);
            func_0040C0F0(&p->v10, &p->v10, f4);
            return;
        }
    }
}
/* localdecomp:end func_003DDB38 */
