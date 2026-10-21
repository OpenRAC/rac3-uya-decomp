#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_357778;

typedef struct {
    V4_357778 r[4];
} M4_357778;

typedef struct {
    u8 pad0[0x10];
    V4_357778 pos;
    u8 pad20[0x14];
    u16 h34;
    u8 pad36[0x8A];
    V4_357778 vC0;
    V4_357778 vD0;
    V4_357778 vE0;
    f32 fF0;
    f32 fF4;
    f32 fF8;
} O_357778;

typedef struct {
    V4_357778 v0;
    u8 pad10[0x10];
    s32 f20;
    u8 pad24[0xC];
    s32 f30;
} T_357778;

typedef struct {
    u8 pad0[0x68];
    T_357778 *f68;
} A_357778;

typedef struct {
    u8 pad0[0x368];
    s16 h368;
    u8 pad36A[0x16B0 - 0x36A];
    s32 f16B0;
    u8 pad16B4[0x25C4 - 0x16B4];
    s32 f25C4;
    u8 pad25C8[0x25ED - 0x25C8];
    u8 b25ED;
} G_357778;

typedef struct {
    u8 pad0[0x10];
    V4_357778 v10;
} P_357778;

extern s32 D_001D673C;
extern s32 D_001D6740;
extern s32 D_001D6694;
extern s32 D_001DD6C0;
extern G_357778 D_001A4BE0;
extern P_357778 *D_001E1AA0;

extern void func_00437600(O_357778 *, void *, M4_357778 *);
extern void func_004389D8(O_357778 *);
extern void func_00439610(O_357778 *);
extern void func_004C41E8(V4_357778 *, V4_357778 *);
extern void func_0040C0F0(V4_357778 *, V4_357778 *, f32);
extern void func_0040BF20(V4_357778 *, V4_357778 *, V4_357778 *);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040BFE8(V4_357778 *, V4_357778 *);
extern void func_0040C638(V4_357778 *, f32 *);
extern void func_004397B0(O_357778 *);
extern s32 func_0050DA08(s32);
extern s32 func_0040BA90(s32 *);

/* localdecomp:start func_00357778 */
void func_00357778(O_357778 *q, O_357778 *o, void *a2, V4_357778 v, s32 n, A_357778 *arg5) {
    M4_357778 m;
    V4_357778 old;
    V4_357778 a;
    V4_357778 b;
    V4_357778 c;
    T_357778 *t;
    V4_357778 *pa;
    V4_357778 *pb;
    V4_357778 *pc;
    f32 ang;
    f32 k;
    f32 one;
    f32 r;

    t = arg5->f68;
    func_00437600(q, a2, &m);
    old = o->pos;
    o->pos = v;
    func_004389D8(o);
    if (!(o->h34 & 4)) {
        func_00439610(o);
    }
    if (D_001D673C || D_001D6740 || D_001A4BE0.h368) {
        pa = &a;
        one = 1.0f;
        func_004C41E8(&o->pos, pa);
        __asm__ __volatile__(
            "lqc2 $vf2, %0\n"
            "lqc2 $vf1, %1\n"
            : : "m"(m.r[3]), "m"(o->pos));
        pc = &c;
        __asm__ __volatile__(
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "=m"(c));
        func_0040C0F0(pc, pc, one);
        pb = &b;
        func_0040BF20(pb, pc, pa);
        func_0040C0F0(pb, pb, one);
        func_0040BF20(pa, pb, pc);
        func_0040C0F0(pa, pa, one);
        o->vC0 = c;
        o->vD0 = b;
        o->vE0 = a;
    } else {
        ang = func_0040CEC8(func_0040C490(m.r[3].x - o->pos.x, m.r[3].y - o->pos.y), 3.1415927f);
        if (D_001A4BE0.f25C4 == 19) {
            s32 d = 2 / n;
            __asm__(
                "lqc2 $vf1, %1\n"
                "lqc2 $vf2, %2\n"
                "vsub.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, %0\n"
                : "=m"(a) : "m"(D_001E1AA0->v10), "m"(t->v0));
            k = d;
            r = func_0040C490(a.x, a.y);
            if (n < 5) {
                r = r * (k + k);
            } else if (n > 5) {
                r = 0.0f;
            }
            ang = func_0040CEC8(r, ang);
        }
        o->fF8 = ang;
        o->fF4 = func_0040C490(func_0040BFE8(&o->pos, &m.r[3]), m.r[3].z - o->pos.z);
        if (D_001A4BE0.f25C4 == 19) {
            o->fF4 = 0.0f;
        }
        o->fF0 = 1.5707964f;
        if (D_001A4BE0.f25C4 == 19) {
            o->fF0 = 0.0f;
        }
        func_0040C638(&o->vC0, &o->fF0);
    }
    func_004397B0(o);
    if ((q && (q->h34 & 1)) || D_001A4BE0.b25ED || D_001A4BE0.f25C4 == 29 || D_001A4BE0.f16B0 == 2 ||
        D_001D6694 || D_001A4BE0.f25C4 == 116) {
        o->h34 |= 0x41;
    } else if (func_0050DA08(-1)) {
        o->h34 &= ~0x41;
    }
    if (D_001A4BE0.f16B0 || D_001A4BE0.f25C4 == 29) {
        if (t->f20) {
            o->h34 &= ~0x41;
        }
    }
    if (func_0050DA08(-1) == 0 && t->f20 == 0) {
        if (func_0040BA90(&t->f30)) {
            o->h34 |= 0x41;
        }
    } else {
        t->f30 = D_001DD6C0;
    }
    o->h34 |= 6;
}
/* localdecomp:end func_00357778 */
