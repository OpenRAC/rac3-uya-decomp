#include "common.h"

/* localdecomp:start func_002FD258 */
typedef int Q_2FD258 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_2FD258;
typedef struct {
    V4_2FD258 v0;
    V4_2FD258 v16;
    V4_2FD258 v32;
    V4_2FD258 v48;
    f32 f64[3];
    f32 f76[3];
    f32 f88[3];
    f32 f100[3];
    f32 f112[3];
    f32 f124[3];
    s32 i136;
    s32 i140;
    void *p144;
    s32 i148;
    s32 i152;
    s32 i156;
} E_2FD258;
typedef struct {
    u8 pad[16];
    V4_2FD258 v16;
} O_2FD258;
typedef struct {
    u8 pad[16];
    f32 f16;
} R_2FD258;
extern E_2FD258 D_0026EB30[3];
extern s32 D_001E1740[2];
extern f32 func_004408C0(f32, f32);
extern f32 func_00440918(f32, f32);
extern R_2FD258 *func_00440728(O_2FD258 *);
extern void func_0044E010(O_2FD258 *, V4_2FD258 *, s32);
extern void func_0040BE90(V4_2FD258 *, V4_2FD258 *, f32);
void func_002FD258(s32 a0, O_2FD258 *o, s32 a2) {
    s32 i;
    E_2FD258 *p;
    R_2FD258 *r;
    V4_2FD258 tmp;
    Q_2FD258 x, y;

    V4_2FD258 *src;
    E_2FD258 *base = D_0026EB30;
    i = 0;
    src = (V4_2FD258 *)D_001E1740;
    for (; i < 3; i++) {
        p = &base[i];
        if (p->i140 == 0) {
            p->i140 = a0;
            p->v32 = *src;
            p->f64[0] = func_004408C0(-3.1415927f, 3.1415927f);
            p->f64[1] = func_004408C0(-3.1415927f, 3.1415927f);
            p->f64[2] = func_004408C0(-3.1415927f, 3.1415927f);
            p->f100[0] = func_004408C0(-3.1415927f, 3.1415927f);
            p->f100[1] = func_004408C0(-3.1415927f, 3.1415927f);
            p->f100[2] = func_004408C0(-3.1415927f, 3.1415927f);
            p->f76[0] = func_00440918(0.001f, 0.005f);
            p->f76[1] = func_00440918(0.001f, 0.005f);
            p->f76[2] = func_00440918(0.001f, 0.005f);
            p->f112[0] = func_00440918(0.001f, 0.005f);
            p->f112[1] = func_00440918(0.001f, 0.005f);
            p->f112[2] = func_00440918(0.001f, 0.005f);
            p->f88[0] = func_004408C0(3.25f, 4.75f) * 0.5f;
            p->f88[1] = func_004408C0(3.25f, 4.75f) * 0.5f;
            p->f88[2] = func_004408C0(3.25f, 4.75f) * 0.5f;
            p->f124[0] = func_004408C0(3.25f, 4.75f) * 0.5f;
            p->f124[1] = func_004408C0(3.25f, 4.75f) * 0.5f;
            p->f124[2] = func_004408C0(3.25f, 4.75f) * 0.5f;
            __asm__("sq $0,%0" : "=m"(*(Q_2FD258 *)&p->v0));
            __asm__("sq $0,%0" : "=m"(*(Q_2FD258 *)&p->v16));
            p->i136 = 15;
            p->p144 = o;
            p->i148 = a2;
            p->i152 = a2;
            p->i156 = 0;
            r = func_00440728(o);
            if (r != 0) {
                func_0044E010(o, &tmp, 1);
                func_0040BE90(&tmp, &tmp, r->f16);
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(tmp));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v16));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(p->v48) : "j"(x));
            } else {
                p->v48 = o->v16;
            }
            return;
        }
    }
}
/* localdecomp:end func_002FD258 */
