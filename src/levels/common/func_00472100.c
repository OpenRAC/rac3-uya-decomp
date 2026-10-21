#include "common.h"

/* localdecomp:start func_00472100 */
typedef struct {
    f32 x, y, z, w;
    f32 f10;
    f32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 f1D;
} S_472100;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[2];
    s16 hA;
    u8 padC[4];
    f32 x, y, z, w;
    S_472100 s;
} O_472100;
typedef struct {
    u8 pad[2];
    u8 b2;
    u8 b3;
} P_472100;
typedef struct { f32 x, y, z, w; } V_472100;
typedef struct { u8 pad[0x140]; f32 x; f32 y; } G1_472100;
typedef struct { u8 pad[0x80]; f32 x; f32 y; } G2_472100;
extern G1_472100 D_001E2900;
extern G2_472100 D_001A4BE0;
extern u8 *D_00221174[];
extern void func_004C6EC8(f32 *, f32 *);
extern s32 func_0040D020(f32, s32, s32);
extern f32 func_0040C490(f32, f32);
extern f32 func_00440918(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern s32 func_00440878(s32, s32);
extern P_472100 *func_0046DCB8(V_472100 *, V_472100 *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_00440848(s32);
extern s32 func_0040BAC0(s16 *);
extern void func_0045E580(O_472100 *);
void func_00472100(O_472100 *o) {
    S_472100 *s = &o->s;
    V_472100 pos, vel;
    V_472100 *pv;
    f32 ang, a;
    s32 n, m;
    P_472100 *p;
    func_004C6EC8(&o->x, &o->x);
    if (s->f1C == 0) {
        o->f4 = func_0040D020((f32)o->hA * s->f10, 0x7F232323, 0x7F373737);
    } else if (s->f1C == 1) {
        if (o->z > s->f14) {
            __asm__ __volatile__(
                "lqc2 $vf1, 0x10(%0)\n"
                "lqc2 $vf2, 0x20(%1)\n"
                "vadd.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, 0x10(%0)\n"
                : : "r"(o), "r"(o) : "memory");
            s->z = s->z - s->w;
        } else if (s->f1D != 0) {
            G2_472100 *g2 = &D_001A4BE0;
            G1_472100 *g1 = &D_001E2900;
            ang = func_0040C490(g2->x - g1->x, g2->y - g1->y);
            func_00440918(1.0f, 2.0f);
            pos.x = o->x + func_00440918(0.0f, 0.15f);
            pos.y = o->y + func_00440918(0.0f, 0.15f);
            pos.z = o->z + 0.1f;
            a = func_0040CEC8(ang, func_00440918(0.0f, -6.2831855f));
            vel.x = func_0040C3C8(a) * 0.033333335f;
            vel.y = func_0040C3E0(a) * 0.033333335f;
            pv = &vel;
            vel.z = 0.0f;
            n = func_00440878(10, 30);
            m = func_00440878(-2, -4);
            p = func_0046DCB8(&pos, pv, n, 0x202020, m, 127, 0, 0, 189000.0f, 84000.0f, 0.0f);
            if (p != 0) {
                p->b2 = *D_00221174[0];
                p->b3 = func_00440848(6) ? 72 : 68;
            }
            s->f1D = 0;
        }
    } else if (s->f1C == 2) {
        o->f4 = func_0040D020((f32)o->hA * s->f10, 0x232323, 0x7F232323);
    }
    if (func_0040BAC0(&o->hA) && s->f1C == 0) {
        s->f1C = 1;
        o->hA = 300;
    } else if (func_0040BAC0(&o->hA) && s->f1C == 1) {
        s->f1C = 2;
        o->hA = 150;
        s->f10 = 0.006666667f;
    } else if (func_0040BAC0(&o->hA) && s->f1C == 2) {
        func_0045E580(o);
    }
}
/* localdecomp:end func_00472100 */
