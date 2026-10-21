#include "common.h"

/* localdecomp:start func_0030A148 */
typedef int Q_30A148 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_30A148;
typedef struct {
    Q_30A148 q0;
    Q_30A148 q16;
    Q_30A148 pos;
    V4_30A148 v48;
    f32 a[3];
    f32 b[3];
    f32 c[3];
    f32 a2[3];
    f32 b2[3];
    f32 c2[3];
    s32 i136;
    void *owner;
    void *src;
    s32 i148;
    s32 i152;
    s32 i156;
} P_30A148;
typedef struct {
    u8 pad0[84];
    s32 count;
} C_30A148;
typedef struct {
    u8 pad0[16];
    Q_30A148 pos;
    u8 pad32[72];
    C_30A148 *c;
} O_30A148;
typedef struct {
    u8 pad0[16];
    f32 f16;
} R_30A148;
extern P_30A148 D_0026FDB0[];
extern f32 func_004408C0(f32, f32);
extern f32 func_00440918(f32, f32);
extern R_30A148 *func_00440728(void *);
extern void func_0044E010(void *, void *, s32);
extern void func_0040BE90(void *, void *, f32);
void func_0030A148(O_30A148 *obj, O_30A148 *src, s32 n) {
    s32 i;
    P_30A148 *p;
    R_30A148 *r;
    C_30A148 *c = obj->c;
    V4_30A148 t;
    Q_30A148 x, y;

    for (i = 0; i < 30; i++) {
        if (D_0026FDB0[i].owner == 0) {
            p = &D_0026FDB0[i];
            p->owner = obj;
            c->count++;
            p->pos = obj->pos;
            p->a[0] = func_004408C0(-3.1415927f, 3.1415927f);
            p->a[1] = func_004408C0(-3.1415927f, 3.1415927f);
            p->a[2] = func_004408C0(-3.1415927f, 3.1415927f);
            p->a2[0] = func_004408C0(-3.1415927f, 3.1415927f);
            p->a2[1] = func_004408C0(-3.1415927f, 3.1415927f);
            p->a2[2] = func_004408C0(-3.1415927f, 3.1415927f);
            p->b[0] = func_00440918(0.001f, 0.005f);
            p->b[1] = func_00440918(0.001f, 0.005f);
            p->b[2] = func_00440918(0.001f, 0.005f);
            p->b2[0] = func_00440918(0.001f, 0.005f);
            p->b2[1] = func_00440918(0.001f, 0.005f);
            p->b2[2] = func_00440918(0.001f, 0.005f);
            p->c[0] = func_004408C0(3.25f, 4.75f);
            p->c[1] = func_004408C0(3.25f, 4.75f);
            p->c[2] = func_004408C0(3.25f, 4.75f);
            p->c2[0] = func_004408C0(3.25f, 4.75f);
            p->c2[1] = func_004408C0(3.25f, 4.75f);
            p->c2[2] = func_004408C0(3.25f, 4.75f);
            p->i148 = n;
            p->i152 = n;
            __asm__("sq $0, %0" : "=m"(p->q0));
            __asm__("sq $0, %0" : "=m"(p->q16));
            p->i136 = 20;
            p->src = src;
            p->i156 = 0;
            r = func_00440728(src);
            if (r != 0) {
                func_0044E010(src, &t, 1);
                func_0040BE90(&t, &t, r->f16);
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(src->pos));
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(p->v48) : "j"(x));
            } else {
                *(Q_30A148 *)&p->v48 = src->pos;
            }
            return;
        }
    }
}
/* localdecomp:end func_0030A148 */
