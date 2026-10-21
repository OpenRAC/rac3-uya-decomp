#include "common.h"

/* localdecomp:start func_00473938 */
typedef int Q_473938 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_473938;
typedef struct {
    s32 count;
    u8 pad4[12];
    V4_473938 pts[1];
} P_473938;
extern P_473938 *D_0021F740[];
extern V4_473938 D_001A4EC0;
extern f32 func_0040BEF8(V4_473938 *, V4_473938 *);
extern void func_0040C0F0(V4_473938 *, V4_473938 *, f32);
extern void func_0040BF20(V4_473938 *, V4_473938 *, V4_473938 *);
extern f32 func_0040BF38(V4_473938 *);

s32 func_00473938(s32 idx, V4_473938 *in, V4_473938 *out, f32 r) {
    V4_473938 d;
    V4_473938 res;
    V4_473938 pos;
    V4_473938 e;
    V4_473938 n;
    V4_473938 c;
    V4_473938 proj;
    P_473938 *p;
    V4_473938 *a;
    f32 base;
    f32 len;
    f32 t;
    s32 hit;
    s32 i;

    p = D_0021F740[idx];
    hit = 0;
    pos = *in;
    base = func_0040BEF8(&pos, &D_001A4EC0);
    for (i = 0; i < p->count - 1; i++) {
        if (p->pts[i].w == 0.0f && p->pts[i + 1].w == 0.0f) {
            continue;
        }
        a = &p->pts[i - 1];
        {
        Q_473938 x_, y_;
        __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(a[1]));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x_) : "j"(x_), "j"(y_));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x_));
    }
        {
        Q_473938 x_, y_;
        __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(a[1]));
        __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(a[2]));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x_) : "j"(x_), "j"(y_));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(x_));
    }
        t = func_0040BEF8(&d, &D_001A4EC0);
        func_0040C0F0(&proj, &D_001A4EC0, t);
        {
        Q_473938 x_, y_;
        __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(proj));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x_) : "j"(x_), "j"(y_));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x_));
    }
        t = func_0040BEF8(&e, &D_001A4EC0);
        func_0040C0F0(&proj, &D_001A4EC0, t);
        {
        Q_473938 x_, y_;
        __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(e));
        __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(proj));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x_) : "j"(x_), "j"(y_));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(x_));
    }
        func_0040C0F0(&n, &e, 1.0f);
        func_0040BF20(&c, &d, &n);
        if (r < __builtin_fabsf(func_0040BEF8(&c, &D_001A4EC0))) {
            continue;
        }
        len = func_0040BF38(&e);
        t = func_0040BEF8(&d, &n);
        if (len < t || t < 0.0f) {
            if (!(func_0040BF38(&d) < r)) {
                continue;
            }
            func_0040C0F0(&res, &d, r);
            hit = 1;
        } else {
            hit = 1;
            func_0040C0F0(&proj, &n, t);
            {
        Q_473938 x_, y_;
        __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(proj));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x_) : "j"(x_), "j"(y_));
        __asm__("sqc2 %1, %0" : "=m"(res) : "j"(x_));
    }
            func_0040C0F0(&res, &res, r);
            {
        Q_473938 x_, y_;
        __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(proj));
        __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(res));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x_) : "j"(x_), "j"(y_));
        __asm__("sqc2 %1, %0" : "=m"(res) : "j"(x_));
    }
        }
        {
        Q_473938 x_, y_;
        __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(res));
        __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(a[1]));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x_) : "j"(x_), "j"(y_));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(x_));
    }
    }
    if (hit) {
        t = base - func_0040BEF8(&pos, &D_001A4EC0);
        func_0040C0F0(&e, &D_001A4EC0, t);
        {
        Q_473938 x_, y_;
        __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(e));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x_) : "j"(x_), "j"(y_));
        __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x_));
    }
    }
    return hit;
}
/* localdecomp:end func_00473938 */
