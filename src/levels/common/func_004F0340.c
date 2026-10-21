#include "common.h"

/* localdecomp:start func_004F0340 */
typedef int u128_4F0340 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4F0340;
typedef struct { u128_4F0340 r[4]; } X_4F0340;
extern X_4F0340 D_001A4BE0;
extern u8 D_001A4C84[];
extern V_4F0340 D_001A4C70;
extern f32 func_0040BEF8(V_4F0340 *, u128_4F0340 *);
extern f32 func_0040C490(f32, f32);
extern void func_0040BF20(V_4F0340 *, V_4F0340 *, u128_4F0340 *);
extern void func_0040C678(X_4F0340 *, V_4F0340 *);
extern void func_0040C9B0(X_4F0340 *, X_4F0340 *, X_4F0340 *);
extern void func_0040C2F8(V_4F0340 *, V_4F0340 *, X_4F0340 *);
extern f32 func_004455F0(f32 *, void *, s32, f32, f32, f32, f32);
extern void func_00447748(X_4F0340 *, V_4F0340 *);
void func_004F0340(V_4F0340 *a, X_4F0340 *m, V_4F0340 *t, f32 p, f32 q, f32 r) {
    X_4F0340 m0;
    X_4F0340 m1;
    V_4F0340 ang;
    V_4F0340 v;
    f32 out;
    f32 zero;
    f32 d;
    f32 pitch;
    f32 yaw;
    f32 roll;
    f32 s;
    f32 c;
    zero = 0.0f;
    out = zero;
    *m = D_001A4BE0;
    d = func_0040BEF8(a, &m->r[2]);
    s = 1.0f - d * d;
    __asm__("nop\n\tnop\n\tsqrt.s %0, %1" : "=f"(c) : "f"(s));
    pitch = func_0040C490(d, c);
    func_0040BF20(&v, a, &m->r[2]);
    if (v.z < 0.99f) {
        roll = func_0040C490(v.x, v.y);
        ang.x = zero;
        ang.y = zero;
        ang.z = -roll;
        func_0040C678(&m1, &ang);
        func_0040C9B0(m, &m1, m);
        func_0040C2F8(&v, &v, &m1);
        yaw = func_0040C490(v.z, v.x);
        ang.x = zero;
        ang.z = zero;
        ang.y = -yaw;
        func_0040C678(&m0, &ang);
        func_0040C9B0(m, &m0, m);
        func_0040C2F8(&v, &v, &m0);
    } else {
        roll = zero;
        yaw = roll;
    }
    if (t != 0) {
        ang.z = pitch;
        ang.x = 0.0f;
    } else {
        func_004455F0(&out, D_001A4C84, 0, pitch, p, q, r);
        ang.x = 0.0f;
        ang.z = out;
    }
    ang.y = 0.0f;
    func_0040C678(&m1, &ang);
    func_0040C9B0(m, &m1, m);
    ang.y = yaw;
    ang.z = 0.0f;
    func_0040C678(&m0, &ang);
    func_0040C9B0(m, &m0, m);
    ang.z = roll;
    ang.y = 0.0f;
    func_0040C678(&m1, &ang);
    func_0040C9B0(m, &m1, m);
    if (t != 0) {
        func_00447748(m, t);
    } else {
        func_00447748(m, &D_001A4C70);
    }
}
/* localdecomp:end func_004F0340 */
