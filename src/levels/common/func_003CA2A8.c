#include "common.h"

typedef int Q_3CA2A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CA2A8;
typedef struct {
    u8 pad0[16];
    V4_3CA2A8 pos;
    u8 b32;
    u8 pad33[191];
    V4_3CA2A8 v224;
} O_3CA2A8;
typedef struct {
    u8 pad0[544];
    f32 f544;
    u8 pad548[12];
    V4_3CA2A8 vel;
    u8 pad576[584];
    f32 ang;
    f32 rad;
    u8 pad1168[32];
    V4_3CA2A8 v1200;
} S_3CA2A8;
typedef struct {
    u8 pad0[136];
    f32 f136;
    u8 pad140[9528];
    s32 i9668;
} G_3CA2A8;

extern G_3CA2A8 D_001A4BE0;
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern f32 func_0040BEF8(void *, void *);
extern f32 func_0040BF68(void *);
extern void func_004459B0(f32 *, f32, f32, f32, f32);
extern f32 func_00443140(void *, s32, s32, f32);

/* localdecomp:start func_003CA2A8 */
void func_003CA2A8(O_3CA2A8 *obj, S_3CA2A8 *s) {
    V4_3CA2A8 v0;
    V4_3CA2A8 d;
    V4_3CA2A8 n;
    V4_3CA2A8 c;
    f32 t;
    f32 old;
    f32 len;
    f32 dz;
    f32 ad;
    Q_3CA2A8 a, p, b, r;

    v0.x = func_0040C3C8(s->ang) * s->rad;
    v0.y = func_0040C3E0(s->ang) * s->rad;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(s->v1200));
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(obj->pos));
    old = s->vel.z;
    v0.z = 0.0f;
    s->vel.z = 0.0f;
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(v0));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(b) : "j"(b), "j"(a));
    __asm__("sqc2 %1, %0" : "=m"(v0) : "j"(b));
    __asm__("lqc2 %0, %1" : "=j"(r) : "m"(v0));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(r), "j"(p));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
    d.z = 0.0f;
    func_0040C0F0(&n, &d, 1.0f);
    func_0040BF20(&c, &n, &obj->v224);
    func_0040C0F0(&c, &c, 1.0f);
    t = func_0040BEF8(&c, &s->vel);
    if (t > 0.00097222225f) {
        t = 0.00097222225f;
    } else if (t < -0.00097222225f) {
        t = -0.00097222225f;
    }
    func_0040C0F0(&c, &c, t);
    {
        Q_3CA2A8 e, f;
        __asm__("lqc2 %0, %1" : "=j"(e) : "m"(c));
        __asm__("lqc2 %0, %1" : "=j"(f) : "m"(s->vel));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(f) : "j"(f), "j"(e));
        __asm__("sqc2 %1, %0" : "=m"(s->vel) : "j"(f));
    }
    len = func_0040BF68(&d);
    t = func_0040BF68(&s->vel);
    func_004459B0(&t, len, 0.0019444445f, 0.0011111111f, 0.10000001f);
    func_0040C0F0(&n, &d, 0.0019444445f);
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(s->vel));
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(n));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(p));
    __asm__("sqc2 %1, %0" : "=m"(s->vel) : "j"(a));
    if (t < func_0040BF68(&s->vel)) {
        func_0040C0F0(&s->vel, &s->vel, t);
    }
    if (obj->b32 == 19) {
        s->vel.z = old + 0.027777778f;
        if (s->vel.z > -0.083333336f) {
            s->vel.z = -0.083333336f;
        }
    } else {
        s->vel.z = old;
        if (D_001A4BE0.i9668 == 176) {
            dz = D_001A4BE0.f136 - obj->pos.z;
            ad = __builtin_fabsf(dz);
            if (ad < 2.25f) {
                if (!(obj->pos.z < D_001A4BE0.f136)) {
                    s->vel.z = old + 0.013888889f;
                    if (s->vel.z > -0.15f) {
                        s->vel.z = -0.15f;
                    }
                    goto done;
                }
            } else if (ad > 10.0f) {
                if (obj->pos.z < D_001A4BE0.f136) {
                    s->vel.z = old + 0.013888889f;
                    if (s->vel.z > -0.15f) {
                        s->vel.z = -0.15f;
                    }
                    goto done;
                }
            } else {
                goto deflt;
            }
            s->vel.z = old - 0.013888889f;
            if (s->vel.z < -0.21666667f) {
                s->vel.z = -0.21666667f;
            }
        } else {
        deflt:
            s->vel.z = s->vel.z - 0.013888889f;
            if (s->vel.z < -0.18333334f) {
                s->vel.z = -0.18333334f;
            }
        }
    }
done:
    {
        Q_3CA2A8 g, h;
        __asm__("lqc2 %0, %1" : "=j"(g) : "m"(s->vel));
        __asm__("lqc2 %0, %1" : "=j"(h) : "m"(obj->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(h) : "j"(h), "j"(g));
        __asm__("sqc2 %1, %0" : "=m"(obj->pos) : "j"(h));
    }
    s->f544 = func_00443140(&obj->pos, 0, 0, 0.5f);
}
/* localdecomp:end func_003CA2A8 */
