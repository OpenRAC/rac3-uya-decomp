#include "common.h"

/* localdecomp:start func_003D5778 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3D5778;
typedef int Q_3D5778 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0xB8];
    f32 fB8;
    u8 fBC;
    u8 fBD;
    u8 fBE;
} T_3D5778;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x68 - 0x21];
    T_3D5778 *f68;
} S_3D5778;
typedef struct {
    u8 pad0[2];
    u8 f2;
    u8 f3;
} P_3D5778;
typedef struct {
    u8 pad0[0x10];
    u8 *f10;
    u8 pad14[0x184 - 0x14];
    u8 *f184;
} G_3D5778;

extern G_3D5778 D_00221118;
extern s32 func_00440848(s32);
extern s32 func_00440878(s32, s32);
extern f32 func_004408C0(f32, f32);
extern void func_003D5658(s32 *, s32 *, s32 *, s32 *);
extern void func_0040C0F0(void *, s32, f32);
extern void func_0040BE90(void *, void *, f32);
extern P_3D5778 *func_00472438(s32, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_003D5778(S_3D5778 *obj, s32 a1, s32 a2, s32 n, s32 c0, s32 dir, f32 ang, f32 sx, f32 sy, f32 sz, f32 spd) {
    V_3D5778 pos, up, d;
    s32 col[4];
    s32 alpha;
    T_3D5778 *t;
    s32 lo, i;
    u32 b;
    s32 low;
    P_3D5778 *p;

    col[0] = c0;
    t = obj->f68;
    b = t->fBD;
    low = func_00440848(3) == 0;
    alpha = 127;
    if (low) {
        col[0] = 4;
        sx *= 0.7f;
        sy *= 0.7f;
        alpha = 48;
    }
    func_003D5658(&col[0], &col[1], &col[2], &col[3]);
    if (t->fBE == 0) {
        func_0040C0F0(&pos, dir, ang * 0.016666668f);
    } else {
        sz = 0.0f;
        __asm__ __volatile__("sq $0, %0" : "=m"(pos));
    }
    *(Q_3D5778 *)&up = 0;
    up.x = 1.0f;
    for (i = 0; i < n; i++) {
        if (t->fBE == 0) {
            func_0040BE90(&d, &up, func_004408C0(0.2f, spd) * 0.016666668f);
            __asm__ __volatile__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %1" : : "m"(d), "m"(pos));
        }
        lo = func_00440848(2) ? col[2] : col[1];
        if (low) {
            lo |= alpha << 24;
        } else {
            lo |= t->fBC << 24;
        }
        if (obj->f20 == 2) {
            b = 0;
        }
        p = func_00472438(a1, &pos, a2, func_00440878(-2, 2), lo, lo & ((b << 24) | 0xFFFFFF),
                          sx * t->fB8 * 210000.0f, sy * t->fB8 * 210000.0f, sz, 0);
        if (p != 0) {
            p->f2 = low ? D_00221118.f184[4] : D_00221118.f10[0];
            p->f3 = 68;
        }
    }
}
/* localdecomp:end func_003D5778 */
