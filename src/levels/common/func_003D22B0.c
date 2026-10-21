#include "common.h"

/* localdecomp:start func_003D22B0 */
typedef int Q_3D22B0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D22B0;
typedef struct {
    u8 pad0[396];
    s32 i396;
} T_3D22B0;
typedef struct {
    u8 pad0[16];
    V4_3D22B0 pos;
    u8 pad32[72];
    T_3D22B0 *t;
    u8 pad108[76];
    s32 i184;
    u8 pad188[60];
    f32 f248;
} O_3D22B0;
typedef struct {
    u8 pad0[184];
    s32 i184;
} R_3D22B0;
extern void func_004C41E8(void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern f32 func_004408C0(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern void func_00440CF8(void *, f32, f32, f32);
extern void func_0040C2D0(void *, void *, void *);
extern s32 func_00440878(s32, s32);
extern R_3D22B0 *func_003D4768(void *, void *, s32, s32, s32);

void func_003D22B0(O_3D22B0 *o) {
    V4_3D22B0 a, b, v;
    f32 w[4] __attribute__((aligned(16)));
    V4_3D22B0 c, d;
    T_3D22B0 *t = o->t;
    f32 f20, f22, f0;
    R_3D22B0 *r;
    Q_3D22B0 qa, qb;

    func_004C41E8(&o->pos, &v);
    w[0] = v.z;
    w[1] = v.z;
    w[2] = -(v.x + v.y);
    func_0040C0F0(&a, w, 1.0f);
    func_0040BF20(&b, &a, &v);
    a.w = b.w = v.w = 0.0f;
    f22 = func_0040CEC8(o->f248, func_004408C0(160.0f, 200.0f) * 0.017453292f);
    f20 = func_004408C0(0.17453292f, 0.87266463f);
    f0 = func_004408C0(2.0f, 5.0f);
    func_00440CF8(&c, f0 * 0.016666668f, f22, f20);
    c.w = 0.0f;
    func_0040C2D0(&c, &c, &a);
    t->i396 = func_00440878(60, 120);
    func_004C41E8(&o->pos, &d);
    func_0040C0F0(&d, &d, 0.75f);
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(d));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(o->pos));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(qb) : "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qb));
    r = func_003D4768(&d, &c, 0, 0, 0);
    if (r != 0) {
        r->i184 = o->i184;
    }
}
/* localdecomp:end func_003D22B0 */
