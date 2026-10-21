#include "common.h"

/* localdecomp:start func_0046D330 */
typedef int Q_46D330 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_46D330;
typedef struct {
    V4_46D330 v;
    s32 i16;
    s32 i20;
    s16 h24;
    s16 h26;
} P_46D330;
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 b3;
    s32 w4;
    u8 pad8[2];
    s16 h10;
    f32 f12;
    V4_46D330 pos;
    P_46D330 p;
} O_46D330;
extern s32 D_001DFBC0;
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern s32 func_00444338(f32, s32, s32);
extern void func_004C6EC8(void *, void *);
extern f32 func_004408C0(f32, f32);
extern f32 func_0040BF38(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BE90(void *, void *, f32);
extern s32 func_00440878(s32, s32);
extern void func_00462190(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_0046D330(O_46D330 *o) {
    P_46D330 *p = &o->p;
    V4_46D330 old, v, r;
    V4_46D330 *pos;
    Q_46D330 x, y;
    f32 f20;

    if (func_0040BAC0(&o->h10)) {
        func_0045E580(o);
        return;
    }
    pos = &o->pos;
    o->w4 = func_00444338((f32)o->h10 / (f32)p->h24, p->i20, p->i16);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->pos));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->v));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(y));
    p->v.z = p->v.z - p->v.w;
    old = o->pos;
    if (o->pos.w != 0.0f) {
        if (o->pos.w == 2.0f) {
            func_004C6EC8(pos, pos);
        }
        o->pos.w = 2.0f;
    }
    if (p->h26 != 0 && (D_001DFBC0 & 1)) {
        *(Q_46D330 *)&r = 0;
        r.x = func_004408C0(-1.0f, 1.0f);
        r.y = func_004408C0(-1.0f, 1.0f);
        r.z = func_004408C0(-1.0f, 1.0f);
        v = r;
        f20 = func_0040BF38(&p->v);
        func_0040C0F0(&v, &v, f20 * func_004408C0(0.15f, 0.25f));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->v));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(x));
        func_0040BE90(&v, &v, func_004408C0(0.75f, 0.95f));
        func_00462190(pos, &v, o->w4, p->i20, func_00440878(15, 30), 0, o->b2, o->b3, (s32)o->pos.w, o->f12);
    } else {
        func_0040BE90(&p->v, &p->v, 0.96f);
    }
}
/* localdecomp:end func_0046D330 */
