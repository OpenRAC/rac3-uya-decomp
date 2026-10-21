#include "common.h"

/* localdecomp:start func_00407240 */
typedef int Q_407240 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_407240;
typedef struct { V_407240 v[4]; s32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } B_407240;
extern V_407240 D_001E2A40;
extern void func_004075A8(void *, s32, s32, long);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_00405A58(void *, s32, s32);
#define VADD(dst, x, y) { Q_407240 ya, xa;     __asm__("lqc2 %0, %1" : "=j"(ya) : "m"(y));     __asm__("lqc2 %0, %1" : "=j"(xa) : "m"(x));     __asm__("vadd.xyz %0, %1, %2" : "=j"(xa) : "j"(xa), "j"(ya));     __asm__("sqc2 %1, %0" : "=m"(dst) : "j"(xa)); }
#define VSUB(dst, x, y) { Q_407240 ya, xa, ra;     __asm__("lqc2 %0, %1" : "=j"(xa) : "m"(x));     __asm__("lqc2 %0, %1" : "=j"(ya) : "m"(y));     __asm__("vsub.xyz %0, %1, %2" : "=j"(ra) : "j"(xa), "j"(ya));     __asm__("sqc2 %1, %0" : "=m"(dst) : "j"(ra)); }
void func_00407240(V_407240 *pts, s32 tex1, s32 tex2, s32 n, s32 col1, s32 col2, s32 closed, f32 unused, f32 w, f32 v) {
    B_407240 b0;
    B_407240 b1;
    V_407240 cr;
    V_407240 r;
    V_407240 A;
    V_407240 B;
    V_407240 p0, p1, q0, q1;
    s32 i;

    func_004075A8(&b0, tex1, 1, 128);
    b0.c[3] = col1;
    b0.c[2] = col1;
    b0.c[1] = col1;
    b0.c[0] = col1;
    b0.uv[0] = 0.0f;
    b0.uv[1] = 0.0f;
    b0.uv[2] = 0.0f;
    b0.uv[3] = 1.0f;
    b0.uv[4] = 1.0f;
    b0.uv[5] = 0.0f;
    b0.uv[6] = 1.0f;
    b0.uv[7] = 1.0f;
    b0.uv[2] += v;
    b0.uv[0] += v;
    b0.uv[6] += v;
    b0.uv[4] += v;
    func_004075A8(&b1, tex2, 1, 128);
    b1.c[3] = col2;
    b1.c[2] = col2;
    b1.c[1] = col2;
    b1.c[0] = col2;
    b1.uv[0] = 0.0f;
    b1.uv[1] = 0.0f;
    b1.uv[2] = 0.0f;
    b1.uv[3] = 1.0f;
    b1.uv[4] = 1.0f;
    b1.uv[5] = 0.0f;
    b1.uv[6] = 1.0f;
    b1.uv[7] = 1.0f;
    b1.uv[2] += v;
    b1.uv[0] += v;
    b1.uv[6] += v;
    b1.uv[4] += v;
    {
        Q_407240 a, c, d, e, g, f;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(pts[0]));
        __asm__("lqc2 %0, %1" : "=j"(c) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(d) : "j"(a), "j"(c));
        __asm__("lqc2 %0, %1" : "=j"(e) : "m"(pts[1]));
        __asm__("lqc2 %0, %1" : "=j"(g) : "m"(pts[0]));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(f) : "j"(e), "j"(g));
        __asm__("sqc2 %1, %0" : "=m"(A) : "j"(d));
        __asm__("sqc2 %1, %0" : "=m"(B) : "j"(f));
    }
    func_0040BF20(&cr, &B, &A);
    func_0040C0F0(&r, &cr, pts[0].w);
    VADD(b0.v[0], pts[0], r);
    VSUB(b0.v[1], pts[0], r);
    p0 = b0.v[0];
    p1 = b0.v[1];
    func_0040BE90(&r, &r, w);
    VADD(b1.v[0], pts[0], r);
    VSUB(b1.v[1], pts[0], r);
    q0 = b1.v[0];
    q1 = b1.v[1];
    for (i = 1; i < n; i++) {
        if (i < n - 1 || closed) {
            {
                Q_407240 a, c, d, e, g, f;
                __asm__("lqc2 %0, %1" : "=j"(a) : "m"(pts[i]));
                __asm__("lqc2 %0, %1" : "=j"(c) : "m"(D_001E2A40));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(d) : "j"(a), "j"(c));
                __asm__("lqc2 %0, %1" : "=j"(g) : "m"(pts[i]));
                __asm__("lqc2 %0, %1" : "=j"(e) : "m"(pts[i - 1]));
                __asm__("sqc2 %1, %0" : "=m"(A) : "j"(d));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(g) : "j"(g), "j"(e));
                __asm__("sqc2 %1, %0" : "=m"(B) : "j"(g));
            }
            func_0040BF20(&cr, &B, &A);
            func_0040C0F0(&r, &cr, pts[i].w);
            VADD(b0.v[2], pts[i], r);
            VSUB(b0.v[3], pts[i], r);
            func_0040BE90(&r, &r, w);
            VADD(b1.v[2], pts[i], r);
            VSUB(b1.v[3], pts[i], r);
            if (i == n - 1) {
                b0.v[2] = p0;
                b0.v[3] = p1;
                b1.v[2] = q0;
                b1.v[3] = q1;
            }
            func_00405A58(&b0, 0, 0);
            func_00405A58(&b1, 0, 0);
            b0.v[0] = b0.v[2];
            b0.v[1] = b0.v[3];
            b1.v[0] = b1.v[2];
            b1.v[1] = b1.v[3];
        }
    }
}
/* localdecomp:end func_00407240 */
