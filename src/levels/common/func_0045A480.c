#include "common.h"

/* localdecomp:start func_0045A480 */
typedef int Q_45A480 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_45A480;
typedef struct {
    u8 pad0[0x20];
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    s32 f38;
    u8 pad3C[0x90 - 0x3C];
    f32 f90;
    s32 f94;
    u8 pad98[4];
    s32 f9C;
    V4_45A480 fA0;
    f32 fB0;
    u8 padB4[0xC0 - 0xB4];
    s16 fC0;
    u8 padC2[0xCC - 0xC2];
    f32 fCC;
} P_45A480;
extern void func_0045AD08(u8 *, P_45A480 *, void *, void *);
extern f32 func_0044E4B8(u8 *, void *, void *);
extern f32 func_0040BFB0(void *, void *);
extern void func_0044DDA0(u8 *, void *, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0044DE28(u8 *, void *, void *, f32, void *);
extern f32 func_0040BEF8(void *, void *);
extern void func_00448B80(void *, f32);
extern f32 func_0044DE78(u8 *, void *, void *);
extern void func_0044E108(u8 *, void *, void *, f32);
extern f32 func_0044DEA8(u8 *, void *, void *);
extern void func_004459B0(f32 *, f32, f32, f32, f32);

void func_0045A480(u8 *a0, P_45A480 *p, void *a2, void *a3, s32 a4, s32 a5, void *a6) {
    V4_45A480 v;
    V4_45A480 d;
    f32 t;
    f32 h;
    f32 dist;
    f32 s;
    Q_45A480 x, y;

    if (!(p->f38 & 0x10)) {
        func_0045AD08(a0, p, a3, a6);
    }
    h = 0.0f;
    if (!(p->f38 & 0x10)) {
        h = func_0044E4B8(a0, a3, a6);
    }
    if (p->f30 < h) {
        __asm__("sq $0,%0" : "=m"(v));
        p->f9C |= 2;
    } else {
        p->f9C &= ~2;
        dist = func_0040BFB0(a0 + 0x10, a2);
        p->fCC = dist;
        if (dist <= p->f34) {
            __asm__("sq $0,%0" : "=m"(v));
        } else {
            __asm__("nop\n\tnop\n\tsqrt.s %0, %1" : "=f"(s) : "f"((dist - p->f34) * 2.0f * p->f24));
            if (p->f28 < s) {
                s = p->f28;
            }
            func_0044DDA0(a0, &v, s);
        }
        if (p->f38 & 0x10) {
            __asm__("nop\n\tnop\n\tsqrt.s %0, %1" : "=f"(s) : "f"((p->fCC - p->f34) * 2.0f * p->f24));
            func_0040C0F0(&v, a3, s);
        }
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->fA0));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
    func_0044DE28(a0, &d, &d, 0.0f, a6);
    if (0.0f < func_0040BEF8(&v, &p->fA0)) {
        func_00448B80(&d, p->f20);
    } else {
        func_00448B80(&d, p->f24);
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->fA0));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(p->fA0) : "j"(x));
    p->fB0 = func_0044DE78(a0, &p->fA0, a6);
    if (p->f38 & 4) {
        return;
    }
    if (p->f90 < 0.0f) {
        func_0044E108(a0, &p->fA0, &p->fA0, p->f2C);
        if (p->fC0 == 0) {
            p->f94 |= 0x20;
        }
        return;
    }
    t = func_0044DEA8(a0, &p->fA0, a6);
    if (p->f90 < t) {
        t = p->f90;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    func_004459B0(&t, p->f90, 0.011111111f, 0.011111111f, 1.0f);
    func_0044DE28(a0, &p->fA0, &p->fA0, t, a6);
}
/* localdecomp:end func_0045A480 */
