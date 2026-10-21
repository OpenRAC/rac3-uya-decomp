#include "common.h"

/* localdecomp:start func_00462CD8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_462CD8;
typedef int Q_462CD8 __attribute__((mode(TI)));
typedef struct { Q_462CD8 r[3]; } M_462CD8;
typedef struct { Q_462CD8 r[4]; } M4_462CD8;
typedef struct {
    u8 pad0[0xC0];
    u8 fC0;
} B_462CD8;
typedef struct {
    M_462CD8 *f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    B_462CD8 *f18;
    f32 f1C;
} S_462CD8;
typedef struct {
    u8 pad0[4];
    u32 f4;
    u8 f8;
    u8 pad9;
    s16 fA;
    f32 fC;
    V_462CD8 f10;
    S_462CD8 f20;
} O_462CD8;

extern f32 func_0040C3E0(f32);
extern f32 func_0040C3C8(f32);
extern void func_0040C2F8(void *, void *, void *);
extern void func_00437698(B_462CD8 *, s32, void *);
extern void func_0040C0F0(void *, void *, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_00445D88(void *, void *, void *, s32);
extern s32 func_0040BAC0(s16 *);
extern void func_0045E580(O_462CD8 *);

void func_00462CD8(O_462CD8 *self) {
    V_462CD8 v;
    V_462CD8 tmp;
    V_462CD8 out;
    M4_462CD8 mtx;
    S_462CD8 *st;
    V_462CD8 *pos;
    Q_462CD8 a0, b0, r0, a1, b1, r1, a2, b2, r2, a3, b3, r3;

    st = &self->f20;
    if (st->f10 != 0.0f) {
        pos = &self->f10;
        mtx.r[0] = st->f0->r[0];
        mtx.r[1] = st->f0->r[1];
        mtx.r[2] = st->f0->r[2];
        tmp.y = func_0040C3E0(st->f14) * st->f10;
        tmp.z = func_0040C3C8(st->f14) * st->f10;
        tmp.x = 0.0f;
        tmp.w = 0.0f;
        func_0040C2F8(&out, &tmp, &mtx);
        __asm__("lqc2 %0, %1" : "=j"(b0) : "m"(out));
        __asm__("lqc2 %0, %1" : "=j"(a0) : "m"(self->f10));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r0) : "j"(a0), "j"(b0));
        __asm__("sqc2 %1, %0" : "=m"(self->f10) : "j"(r0));
        st->f1C += 0.06001f;
        func_00437698(st->f18, 0, &v);
        __asm__("lqc2 %0, %1" : "=j"(a1) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(b1) : "m"(self->f10));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(a1), "j"(b1));
        __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(r1));
        func_0040C0F0(&tmp, &tmp, st->f1C);
        __asm__("lqc2 %0, %1" : "=j"(b2) : "m"(tmp));
        __asm__("lqc2 %0, %1" : "=j"(a2) : "m"(self->f10));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r2) : "j"(a2), "j"(b2));
        __asm__("sqc2 %1, %0" : "=m"(self->f10) : "j"(r2));
        st->f14 = func_0040CEC8(st->f14, 0.52359879f);
        st->f10 *= 0.9f;
        tmp.y = func_0040C3E0(st->f14) * st->f10;
        tmp.z = func_0040C3C8(st->f14) * st->f10;
        tmp.x = 0.0f;
        tmp.w = 0.0f;
        func_0040C2F8(&out, &tmp, &mtx);
        __asm__("lqc2 %0, %1" : "=j"(a3) : "m"(self->f10));
        __asm__("lqc2 %0, %1" : "=j"(b3) : "m"(out));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r3) : "j"(a3), "j"(b3));
        __asm__("sqc2 %1, %0" : "=m"(self->f10) : "j"(r3));
        if (func_00445D88(&v, &st->f18->fC0, pos, 1) > 0.0f) {
            func_0045E580(self);
            return;
        }
    }
    st->f4 += st->fC * 0.011f;
    if (st->f4 <= 0.0f || func_0040BAC0(&self->fA)) {
        func_0045E580(self);
        return;
    }
    if (st->f4 >= 1.0f) {
        st->fC = -st->fC;
        st->f4 += st->fC * 0.011f;
    }
    self->fC += -2940.0f;
    self->f4 = (self->f4 & 0xFFFFFF) | ((s32)(st->f4 * 255.0f) << 24);
    st->f8 += 0.006f;
    if (st->f8 > 1.0f) st->f8 -= 1.0f;
    self->f8 = st->f8 * 255.0f;
}
/* localdecomp:end func_00462CD8 */
