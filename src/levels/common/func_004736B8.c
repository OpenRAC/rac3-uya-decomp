#include "common.h"

/* localdecomp:start func_004736B8 */
typedef int Q_4736B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4736B8;
typedef struct {
    s32 n;
    s32 pad[3];
    V4_4736B8 pts[1];
} T_4736B8;
extern T_4736B8 *D_0021F740[];
extern void func_0040C0F0(V4_4736B8 *, V4_4736B8 *, f32);
extern void func_0040BF20(V4_4736B8 *, V4_4736B8 *, V4_4736B8 *);
extern f32 func_0040BF38(V4_4736B8 *);
extern f32 func_0040BEF8(V4_4736B8 *, V4_4736B8 *);
s32 func_004736B8(s32 idx, V4_4736B8 *pos, V4_4736B8 *out, f32 radius) {
    V4_4736B8 d;
    V4_4736B8 tmp;
    V4_4736B8 cur;
    V4_4736B8 seg;
    V4_4736B8 n;
    V4_4736B8 t;
    V4_4736B8 proj;
    s32 hit;
    s32 i;
    f32 len;
    f32 dot;

    hit = 0;
    *(Q_4736B8 *)&cur = *(Q_4736B8 *)pos;
    for (i = 0; i < D_0021F740[idx]->n - 1; i++) {
        if (D_0021F740[idx]->pts[i].w == 0.0f) {
            continue;
        }
        {
            Q_4736B8 x, y, z;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_0021F740[idx]->pts[i]));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(cur));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(d) : "j"(z));
        }
        d.z = 0.0f;
        {
            Q_4736B8 x, y, z;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"((&D_0021F740[idx]->pts[i])[1]));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_0021F740[idx]->pts[i]));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(seg) : "j"(z));
        }
        seg.z = 0.0f;
        func_0040C0F0(&n, &seg, 1.0f);
        func_0040BF20(&t, &d, &n);
        if (radius < __builtin_fabsf(t.z)) {
            continue;
        }
        len = func_0040BF38(&seg);
        dot = func_0040BEF8(&d, &n);
        if (len < dot || dot < 0.0f) {
            if (func_0040BF38(&d) < radius) {
                hit = 1;
                func_0040C0F0(&tmp, &d, radius);
                {
                    Q_4736B8 x, y, z;
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(tmp));
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_4736B8 *)(i * 16 + (u8 *)&D_0021F740[idx]->pts[0])));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(cur) : "j"(z));
                }
                cur.z = pos->z;
            }
        } else {
            hit = 1;
            func_0040C0F0(&proj, &n, dot);
            {
                Q_4736B8 x, y, z;
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(proj));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(y), "j"(x));
                __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(z));
            }
            func_0040C0F0(&tmp, &tmp, radius);
            {
                Q_4736B8 x, y, z;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(proj));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(tmp));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(y), "j"(x));
                __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(z));
            }
            {
                Q_4736B8 x, y, z;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_4736B8 *)(i * 16 + (u8 *)&D_0021F740[idx]->pts[0])));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(tmp));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(y), "j"(x));
                __asm__("sqc2 %1, %0" : "=m"(cur) : "j"(z));
            }
            cur.z = pos->z;
        }
    }
    if (hit) {
        *(Q_4736B8 *)out = *(Q_4736B8 *)&cur;
    }
    return hit;
}
/* localdecomp:end func_004736B8 */
