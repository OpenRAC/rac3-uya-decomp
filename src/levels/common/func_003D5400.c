#include "common.h"

/* localdecomp:start func_003D5400 */
typedef int Q_3D5400 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D5400;
typedef struct {
    u8 pad0[12];
    f32 f12;
    V4_3D5400 v16;
    V4_3D5400 vtx[8];
    f32 f160;
    u8 pad164[26];
    u8 b190;
} E_3D5400;
typedef struct {
    u8 pad0[16];
    V4_3D5400 pos;
    u8 pad32[72];
    E_3D5400 *e;
} O_3D5400;
extern V4_3D5400 D_001EAAC0[];
extern V4_3D5400 D_001D66B0[];
extern f32 func_00443140(void *, s32, s32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440978(void);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040CCA0(void *, void *, void *, f32);

void func_003D5400(O_3D5400 *o) {
    E_3D5400 *e = o->e;
    V4_3D5400 tmp, pos, tmp2;
    Q_3D5400 x, y;
    V4_3D5400 *s0;
    s32 i, j;
    V4_3D5400 *s2;
    f32 half = e->f160 * 0.5f;
    f32 f20, f21, a, b;

    if (e->b190 == 0) {
        f20 = func_00443140(&o->pos, 0, 0, 3.0f);
        i = 0;
        func_0040C0F0(e, D_001EAAC0, 1.0f);
        s0 = e->vtx;
        e->f12 = f20;
        do {
            if (i < 3) {
                a = 0.0f;
                b = half;
            } else {
                a = half;
                b = e->f160;
            }
            i++;
            f21 = func_004408C0(a, b);
            f20 = func_00440978();
            __asm__ __volatile__("sq $0,0(%0)" : : "r"(&tmp));
            tmp.x = func_0040C3C8(f20) * f21;
            tmp.y = func_0040C3E0(f20) * f21;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->pos));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(tmp));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(*s0) : "j"(y));
            s0->z = e->f12;
            s0->w = f21;
            s0++;
        } while (i < 8);
    } else {
        pos = o->pos;
        __asm__("lqc2 %0, D_001D66B0" : "=j"(x));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pos));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(tmp2) : "j"(x));
        func_0040BE90(&tmp2, e, func_0040BEF8(e, &tmp2));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(tmp2));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pos));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(tmp2) : "j"(y));
        __asm__("lqc2 %0, D_001D66B0" : "=j"(x));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(tmp2));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(tmp2) : "j"(x));
        func_0040C0F0(&tmp2, &tmp2, 1.0f);
        e->v16 = tmp2;
        j = 0;
        s2 = e->vtx;
        do {
            __asm__ __volatile__("sq $0,0(%0)" : : "r"(&tmp));
            func_0040CCA0(&tmp, &tmp2, e, func_00440978());
            if (j < 3) {
                a = 0.0f;
                b = half;
            } else {
                a = half;
                b = e->f160;
            }
            j++;
            f21 = func_004408C0(a, b);
            func_0040BE90(&tmp, &tmp, f21);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(tmp));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->pos));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(*s2) : "j"(y));
            s2->w = f21;
            s2++;
        } while (j < 8);
    }
}
/* localdecomp:end func_003D5400 */
