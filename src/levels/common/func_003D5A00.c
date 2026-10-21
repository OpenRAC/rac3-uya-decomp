#include "common.h"

typedef int Q_3D5A00 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3D5A00;
typedef struct {
    u8 pad0[0xB4];
    s32 fB4;
    u8 padB8[6];
    u8 bBE;
} S_3D5A00;
typedef struct {
    u8 pad0[0x68];
    S_3D5A00 *f68;
} O_3D5A00;

extern f32 func_004408C0(f32, f32);
extern void func_00440B30(V_3D5A00 *, f32, f32);
extern void func_0040BE90(V_3D5A00 *, V_3D5A00 *, f32);
extern void func_003D5778(O_3D5A00 *, V_3D5A00 *, s32, s32, s32, V_3D5A00 *, f32, f32, f32, f32, f32);

/* localdecomp:start func_003D5A00 */
void func_003D5A00(O_3D5A00 *o, V_3D5A00 *p, s32 a, s32 b, s32 c, V_3D5A00 *d, f32 f0, f32 f1, f32 f2, f32 x, f32 y, f32 g, f32 h)
{
    V_3D5A00 v;
    V_3D5A00 w;
    S_3D5A00 *s;
    Q_3D5A00 q1, q2, r;

    __asm__("sq $0, %0" : "=m"(*(Q_3D5A00 *)&v));
    s = o->f68;
    if (s->bBE == 0) {
        v.x = func_004408C0(-x, x);
        v.y = func_004408C0(-x, x);
        v.z = func_004408C0(0.0f, y);
        if (s->fB4 & 0x80) {
            v.y = v.y * 0.2625f;
        }
    } else {
        func_00440B30(&v, -x, x);
        func_0040BE90(&w, d, func_004408C0(0.0f, y));
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(w));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(v));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(r));
    }
    __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(*p));
    __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(q1), "j"(q2));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(r));
    func_003D5778(o, &v, a, b, c, d, f0, f1, f2, g, h);
}
/* localdecomp:end func_003D5A00 */
