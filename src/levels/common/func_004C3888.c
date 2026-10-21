#include "common.h"

/* localdecomp:start func_004C3888 */
typedef int Q_4C3888 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4C3888;
typedef struct {
    u8 pad0[872];
    s16 s368;
    u8 pad1[1728 - 874];
    V4_4C3888 m6C0[3];
    u8 pad2[9664 - 1776];
    u8 *p25C0;
    s32 x25C4;
    u8 pad3[9709 - 9672];
    u8 b25ED;
} S_4C3888;

extern S_4C3888 D_001A4BE0;
extern s32 D_001D6740;
extern s32 D_001D673C;
extern u8 *D_001D52FC;
extern V4_4C3888 D_001E2A60;

extern void func_0040BE90(void *, void *, f32);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern f32 func_0040C3E0(f32);
extern f32 func_0040C3C8(f32);
extern void func_0040CB80(void *, void *);
extern void func_0040C960(void *, void *, void *);
extern f32 func_0040BF38(void *);
extern f32 func_00442070(f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0044DF40(void *, void *, s32);
extern void func_004FC518(s32, s32);
extern s32 func_0045E3B8(s32, s32);
extern f32 *func_00440728(void *);

#define Q_(p) (*(Q_4C3888 *)(p))
#define VSUBA(d, a, b) { Q_4C3888 x_, y_, r_; __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(a)); __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(b)); __asm__("vsub.xyz %0, %1, %2" : "=j"(r_) : "j"(x_), "j"(y_)); __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r_)); }
#define VSUBB(d, a, b) { Q_4C3888 x_, y_, r_; __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(b)); __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(a)); __asm__("vsub.xyz %0, %1, %2" : "=j"(r_) : "j"(x_), "j"(y_)); __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r_)); }
#define VADDA(d, a, b) { Q_4C3888 x_, y_, r_; __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(a)); __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(b)); __asm__("vadd.xyz %0, %1, %2" : "=j"(r_) : "j"(x_), "j"(y_)); __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r_)); }
#define VADDB(d, a, b) { Q_4C3888 x_, y_, r_; __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(b)); __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(a)); __asm__("vadd.xyz %0, %1, %2" : "=j"(r_) : "j"(x_), "j"(y_)); __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r_)); }

void func_004C3888(V4_4C3888 *out, V4_4C3888 *pos, u8 *target, u8 *cam, f32 fmin, f32 fmax, f32 f14, f32 f15) {
    V4_4C3888 t0;
    V4_4C3888 t16;
    V4_4C3888 up;
    V4_4C3888 tp;
    V4_4C3888 t64;
    V4_4C3888 t80;
    V4_4C3888 t96;
    V4_4C3888 t112;
    V4_4C3888 t128;
    V4_4C3888 t144;
    V4_4C3888 m[4];
    V4_4C3888 q;
    V4_4C3888 axis;
    V4_4C3888 dir;
    V4_4C3888 rot[3];
    V4_4C3888 mat[3];
    V4_4C3888 t368;
    V4_4C3888 *u;
    V4_4C3888 *w;
    V4_4C3888 *c;
    S_4C3888 *h;
    f32 dist, a, b, s, inv, k;
    f32 *p;

    if (cam != 0) {
        Q_(&m[0]) = Q_(cam + 16);
        Q_(&m[1]) = Q_(cam + 192);
        Q_(&m[2]) = Q_(cam + 208);
        Q_(&m[3]) = Q_(cam + 224);
    } else {
        h = &D_001A4BE0;
        Q_(&m[0]) = Q_(h->p25C0 + 16);
        Q_(&m[1]) = Q_(&h->m6C0[0]);
        Q_(&m[2]) = Q_(&h->m6C0[1]);
        Q_(&m[3]) = Q_(&h->m6C0[2]);
    }
    out->x = 1.0f;
    out->y = 0.0f;
    out->z = 0.0f;
    out->w = 0.0f;
    if (D_001A4BE0.s368 != 0 && D_001D6740 == 0) {
        func_0040BE90(&up, D_001A4BE0.p25C0 + 224, -1.0f);
        u = &up;
    } else {
        func_0044DF40(&m[0], &up, 0);
        u = &up;
    }
    dist = fmax;
    if (target == 0) {
        if (D_001A4BE0.x25C4 == 1) {
            func_004FC518(29, 1);
        }
        if ((*(s32 *)(D_001D52FC + 416) & func_0045E3B8(4, 0)) != 0 && D_001A4BE0.b25ED == 0) {
            c = &D_001E2A60;
            func_0040C0F0(&dir, c, 1.0f);
            a = func_0040BEF8(&dir, u);
            func_0040BE90(&t16, u, a);
            w = &t16;
            VSUBA(t0, dir, t16);
            func_0040C0F0(&t0, &t0, 1.0f);
            func_0040BF20(&axis, &dir, &t0);
            a = func_0040BEF8(&dir, &t0) * 0.5f;
            func_0040BE90(&q, &axis, func_0040C3E0(a));
            q.w = func_0040C3C8(a);
            func_0040CB80(&q, mat);
            func_0040C960(rot, mat, c);
            b = -func_0040BEF8(&m[0], u);
            func_0040C0F0(&t368, c, 1.0f);
            s = func_0040BEF8(u, &t368);
            if (0.0f < s) {
                func_0040BE90(&t368, &t368, (func_0040BEF8(u, (V4_4C3888 *)((u8 *)c - 32)) + b) / s);
                {
                    Q_4C3888 a1, b1, r1, a2, b2, r2;
                    __asm__("lqc2 %0, %1" : "=j"(b1) : "m"(t368));
                    __asm__("lqc2 %0, %1" : "=j"(a1) : "m"(*(V4_4C3888 *)((u8 *)c - 32)));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(a1), "j"(b1));
                    __asm__("lqc2 %0, %1" : "=j"(b2) : "m"(*(V4_4C3888 *)((u8 *)c - 32)));
                    __asm__("sqc2 %1, %0" : "=m"(t368) : "j"(r1));
                    __asm__("lqc2 %0, %1" : "=j"(a2) : "m"(t368));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(r2) : "j"(a2), "j"(b2));
                    __asm__("sqc2 %1, %0" : "=m"(t368) : "j"(r2));
                }
                func_0040BE90(w, u, func_0040BEF8(&t368, u));
                VSUBA(t0, t368, t16);
                dist = func_0040BF38(&t0);
                if (fmax < dist) {
                    dist = fmax;
                } else if (dist < fmin) {
                    dist = fmin;
                }
            }
            dist = fmax * func_00442070(dist / fmax);
            func_0040C2D0(out, out, rot);
        } else {
            func_0040C2D0(out, out, &m[1]);
            w = &t16;
        }
        func_0040C0F0(out, out, dist);
        VADDB(tp, *out, m[0]);
    } else {
        if ((u16)(*(u16 *)(target + 170) - 2701) < 2) {
            p = func_00440728(target);
            if (p != 0 && 0.0f < p[0]) {
                if (D_001D673C != 0 || D_001A4BE0.s368 != 0) {
                    func_0040BE90(&q, target + 224, p[4]);
                    {
                        Q_4C3888 x_, y_, r_;
                        __asm__("lqc2 %0, %1" : "=j"(x_) : "m"(*(V4_4C3888 *)(target + 16)));
                        __asm__("lqc2 %0, %1" : "=j"(y_) : "m"(q));
                        __asm__("vadd.xyz %0, %1, %2" : "=j"(r_) : "j"(x_), "j"(y_));
                        w = &t16;
                        __asm__("sqc2 %1, %0" : "=m"(tp) : "j"(r_));
                    }
                } else {
                    Q_(&tp) = Q_(target + 16);
                    w = &t16;
                    tp.z = tp.z + p[4];
                }
            } else {
                Q_(&tp) = Q_(target + 16);
                w = &t16;
            }
        } else {
            Q_(&tp) = Q_(target + 16);
            w = &t16;
        }
    }
    VSUBA(t64, tp, *pos);
    func_0040BE90(w, u, func_0040BEF8(&t64, u));
    VSUBB(t0, t64, t16);
    func_0040C0F0(out, &t0, f14);
    k = func_0040BF38(&t0) / f14;
    inv = 1.0f / k;
    a = func_0040BEF8(pos, u);
    func_0040BE90(&t96, u, a);
    a = func_0040BEF8(&tp, u);
    func_0040BE90(&t112, u, a);
    func_0040BE90(&t128, u, f15 * (k * k) * 0.5f);
    VSUBB(t144, t96, t112);
    VADDB(t144, t144, t128);
    func_0040BE90(&t144, &t144, -1.0f);
    func_0040BE90(&t80, &t144, inv);
    VADDA(*out, *out, t80);
}
/* localdecomp:end func_004C3888 */
