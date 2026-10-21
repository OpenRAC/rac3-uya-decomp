#include "common.h"

/* localdecomp:start func_003F52E8 */
typedef int Q_3F52E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3F52E8;
typedef struct {
    V4_3F52E8 v0;
    u8 pad10[32];
    V4_3F52E8 pos;
    u8 mtx[64];
} A_3F52E8;
typedef struct {
    V4_3F52E8 v0;
    u8 pad10[32];
    V4_3F52E8 pos;
    u8 mtx[64];
    f32 rad;
    u8 pad84[12];
} B_3F52E8;
typedef struct {
    u8 pad0[16];
    s32 type;
    s32 idx;
} T_3F52E8;
extern void func_0040C2D0(void *, void *, void *);
extern f32 func_0040BF68(void *);
extern f32 func_0040BF38(void *);
extern f32 func_0040BFB0(void *, void *);
extern A_3F52E8 *D_001E0180[];
extern A_3F52E8 *D_001E01A4[];
extern A_3F52E8 *D_001E01AC[];
extern B_3F52E8 *D_001E019C[];
s32 func_003F52E8(V4_3F52E8 pos, T_3F52E8 *t, f32 r) {
    V4_3F52E8 v;
    V4_3F52E8 d;
    V4_3F52E8 out;
    s32 ret;

    switch (t->type) {
    case 3: {
        A_3F52E8 *e = &D_001E0180[0][t->idx];
        Q_3F52E8 a, b;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(e->pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(a));
        d.w = 0.0f;
        func_0040C2D0(&out, &d, e->mtx);
        return -1.0f <= out.x && out.x <= 1.0f && -1.0f <= out.y && out.y <= 1.0f && -1.0f <= out.z && out.z <= 1.0f;
    }
    case 6: {
        A_3F52E8 *e = &D_001E01AC[0][t->idx];
        Q_3F52E8 a, b;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(e->pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(a));
        ret = 0;
        d.w = 0.0f;
        func_0040C2D0(&out, &d, e->mtx);
        if (func_0040BF68(&out) < 1.0f) {
            if (-1.0f <= out.z && out.z <= 1.0f) {
                ret = 1;
            }
        }
        return ret;
    }
    case 5: {
        A_3F52E8 *e = &D_001E01A4[0][t->idx];
        {
            f32 len = func_0040BF38(e) + r;
            return func_0040BFB0(&pos, &e->pos) < len;
        }
    }
    case 7: {
        B_3F52E8 *e = &D_001E019C[0][t->idx];
        Q_3F52E8 a, b;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(e->pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(a));
        d.w = 0.0f;
        func_0040C2D0(&out, &d, e->mtx);
        if (func_0040BF68(&out) < 1.0f && -1.0f <= out.z && out.z <= 1.0f) {
            return 1;
        }
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 1.0f;
        v.w = 1.0f;
        func_0040C2D0(&out, &v, e);
        {
            Q_3F52E8 p, q, s, u;
            __asm__("lqc2 %0, %1" : "=j"(q) : "m"(out));
            __asm__("lqc2 %0, %1" : "=j"(p) : "m"(e->pos));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(q) : "j"(q), "j"(p));
            __asm__("sqc2 %1, %0" : "=m"(out) : "j"(q));
            __asm__("lqc2 %0, %1" : "=j"(s) : "m"(pos));
            __asm__("lqc2 %0, %1" : "=j"(u) : "m"(out));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(s) : "j"(s), "j"(u));
            __asm__ ("sqc2 %1, %0" : "=m"(v) : "j"(s));
        }
        if (func_0040BF38(&v) < e->rad) {
            return 1;
        }
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = -1.0f;
        v.w = 1.0f;
        func_0040C2D0(&out, &v, e);
        {
            Q_3F52E8 p, q, s, u;
            __asm__("lqc2 %0, %1" : "=j"(q) : "m"(out));
            __asm__("lqc2 %0, %1" : "=j"(p) : "m"(e->pos));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(q) : "j"(q), "j"(p));
            __asm__("sqc2 %1, %0" : "=m"(out) : "j"(q));
            __asm__("lqc2 %0, %1" : "=j"(s) : "m"(pos));
            __asm__("lqc2 %0, %1" : "=j"(u) : "m"(out));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(s) : "j"(s), "j"(u));
            __asm__ ("sqc2 %1, %0" : "=m"(v) : "j"(s));
        }
        if (func_0040BF38(&v) < e->rad) {
            return 1;
        }
        return 0;
    }
    }
    return 0;
}
/* localdecomp:end func_003F52E8 */
