#include "common.h"

/* localdecomp:start func_00469EF8 */
typedef int Q_469EF8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_469EF8;
typedef struct {
    f32 v[3];
    u8 *x0C;
    f32 x10;
    f32 x14;
    s16 x18;
    s16 x1A;
    s16 x1C;
} S_469EF8_Q;
typedef struct S_469EF8 {
    u8 x0;
    u8 x1;
    u8 x2;
    u8 x3;
    u8 x4[3];
    s8 x7;
    u8 x8;
    u8 x9;
    s16 xA;
    f32 xC;
    Q_469EF8 x10;
    S_469EF8_Q q;
} S_469EF8;
extern s32 func_00442D70(u8 *, s32);
extern s32 func_0040BAC0(s16 *);
extern void func_0045E580(S_469EF8 *);
extern S_469EF8 *func_00469D90(u8 *, Q_469EF8 *, f32, f32, s32, s32, s32, V4_469EF8 *);
extern void func_0040BE90(V4_469EF8 *, V4_469EF8 *, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040C658(void *, V4_469EF8 *);
extern void func_0040C2F8(V4_469EF8 *, V4_469EF8 *, void *);
extern void func_0040C2D0(V4_469EF8 *, V4_469EF8 *, void *);
extern f32 func_0040CEC8(f32, f32);
void func_00469EF8(S_469EF8 *p) {
    S_469EF8_Q *q = &p->q;
    V4_469EF8 v;
    V4_469EF8 w;
    V4_469EF8 u;
    V4_469EF8 m[4];
    S_469EF8 *r;
    f32 c, a, s;
    Q_469EF8 x, y, z;

    if (q->x1C == 0) {
        if (func_00442D70(p->x4, q->x1A)) {
            goto kill;
        }
        if (q->x0C == 0) {
            return;
        }
        v.x = q->v[0];
        v.y = q->v[1];
        v.z = q->v[2];
        func_0040BE90(&v, &v, q->x18);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_469EF8 *)(q->x0C + 16)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(p->x10) : "j"(z));
        return;
    }
    if (func_0040BAC0(&p->xA) || (p->xA < 10 && func_00442D70(p->x4, 16))) {
kill:
        func_0045E580(p);
        return;
    }
    if (q->x1C == 1) {
        func_00469D90(0, &p->x10, 0.0f, 0.0f, 10, 0, p->x7, 0);
    } else {
        v.x = q->v[0];
        v.y = q->v[1];
        v.z = q->v[2];
        r = func_00469D90(q->x0C, &p->x10, 0.0f, 0.0f, 10, 0, p->x7, &v);
        if (r) {
            r->q.x18 = q->x18;
        }
    }
    if (q->x1C == 1) {
        p->x10 = *(Q_469EF8 *)(q->x0C + 16);
        v.x = func_0040C3C8(q->x10) * 2.25f;
        v.y = func_0040C3E0(q->x10) * 2.25f;
        v.z = v.x;
        v.x = 0.0f;
        w.x = func_0040C3C8(q->x14) * 0.28f;
        c = func_0040C3E0(q->x14) * 0.28f;
        a = q->x10;
        s = w.x;
        __asm__("sq $0, %0" : "=m"(u));
        w.z = s;
        w.y = c;
        u.y = a;
        w.x = 0.0f;
        func_0040C658(m, &u);
        func_0040C2F8(&w, &w, m);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(w));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(z));
        func_0040C2D0(&v, &v, q->x0C + 192);
        {
            Q_469EF8 x2, y2, z2;
            __asm__("lqc2 %0, %1" : "=j"(y2) : "m"(v));
            __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(p->x10));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(z2) : "j"(x2), "j"(y2));
            __asm__("sqc2 %1, %0" : "=m"(p->x10) : "j"(z2));
        }
        q->x10 = func_0040CEC8(q->x10, 0.015998852f);
        q->x14 = func_0040CEC8(q->x14, 0.072722055f);
    }
}
/* localdecomp:end func_00469EF8 */
