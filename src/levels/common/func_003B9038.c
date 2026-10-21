#include "common.h"

/* localdecomp:start func_003B9038 */
typedef int Q_3B9038 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3B9038;
typedef struct { V_3B9038 a; V_3B9038 b; u8 pad20[8]; f32 f28; f32 f2C; } O_3B9038;
extern f32 func_00418328(f32 lo, f32 hi);
extern f32 func_0041C6B8(f32 a, f32 b, f32 t);
extern f32 func_003E56C0(f32 a);
extern void func_0041C6C8(V_3B9038 *out, V_3B9038 *a, V_3B9038 *b, f32 t);
extern void func_003E4648(V_3B9038 *out, V_3B9038 *a, V_3B9038 *b);
extern f32 func_003E4B30(f32 a);
extern f32 func_003E4B48(f32 a);
extern void func_003E4858(V_3B9038 *out, V_3B9038 *in, f32 s);

void func_003B9038(O_3B9038 *o, V_3B9038 *out, f32 *frac, f32 x) {
    V_3B9038 dir;
    V_3B9038 p1;
    V_3B9038 p2;
    V_3B9038 off;
    V_3B9038 a;
    V_3B9038 b;
    Q_3B9038 q1, q2, q3, q4, q5, q6;
    f32 t, len, d, ang;
    t = func_00418328(0.0f, 1.0f);
    len = func_0041C6B8(o->f28, o->f2C, t);
    d = func_00418328(x * len, len);
    if (frac != 0 && len != 0.0f) {
        *frac = d / len;
    }
    ang = func_003E56C0(func_00418328(0.0f, 6.2831855f));
    a = o->a;
    b = o->b;
    func_0041C6C8(out, &a, &b, t);
    __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(o->a));
    __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(o->b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
    __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(q1));
    p1.x = -dir.y - dir.z;
    p1.y = dir.x;
    p1.z = dir.x;
    p1.w = 1.0f;
    func_003E4648(&p2, &p1, &dir);
    off.x = func_003E4B30(ang) * d;
    off.y = func_003E4B48(ang) * d;
    off.z = 0.0f;
    func_003E4858(&p1, &p1, off.x);
    func_003E4858(&p2, &p2, off.y);
    __asm__("lqc2 %0, %1" : "=j"(q6) : "m"(p2));
    __asm__("lqc2 %0, %1" : "=j"(q5) : "m"(p1));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(q5) : "j"(q5), "j"(q6));
    __asm__("sqc2 %1, %0" : "=m"(off) : "j"(q5));
    __asm__("lqc2 %0, %1" : "=j"(q3) : "m"(*out));
    __asm__("lqc2 %0, %1" : "=j"(q4) : "m"(off));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(q3) : "j"(q3), "j"(q4));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(q3));
}
/* localdecomp:end func_003B9038 */
