#include "common.h"

#define TEX1(lcm, mxl, mmag, mmin, mtba, l, k) \
    ((unsigned long)(lcm) | ((unsigned long)(mxl) << 2) | ((unsigned long)(mmag) << 5) | ((unsigned long)(mmin) << 6) \
    | ((unsigned long)(mtba) << 9) | ((unsigned long)(l) << 19) | ((unsigned long)(k) << 32))
#define TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((unsigned long)(tbp) | ((unsigned long)(tbw) << 14) | ((unsigned long)(psm) << 20) | ((unsigned long)(tw) << 26) \
    | ((unsigned long)(th) << 30) | ((unsigned long)(tcc) << 34) | ((unsigned long)(tfx) << 35) | ((unsigned long)(cbp) << 37) \
    | ((unsigned long)(cpsm) << 51) | ((unsigned long)(csm) << 55) | ((unsigned long)(csa) << 56) | ((unsigned long)(cld) << 61))
#define MIPTBP1(tbp1, tbw1, tbp2, tbw2, tbp3, tbw3) \
    ((unsigned long)(tbp1) | ((unsigned long)(tbw1) << 14) | ((unsigned long)(tbp2) << 20) | ((unsigned long)(tbw2) << 34) \
    | ((unsigned long)(tbp3) << 40) | ((unsigned long)(tbw3) << 54))
typedef struct { s32 w0; u16 h4; s16 h6; s16 h8; s16 hA; s16 hC; s16 hE; } T_394368;
typedef struct { u8 p0[0x20]; s32 x20; u8 p24[0x10]; s32 x34; } S_1A1ED0_00394368;
extern S_1A1ED0_00394368 D_001A1ED0_00394368;
extern unsigned long D_001DFF10[];
extern unsigned long D_001DFF28[];
void func_00423700(unsigned long *p, T_394368 *t, s32 a, s32 b, s32 c, s32 d, s32 idx) {
    s32 h8, hA, lh, hC, hE, base, w;
    S_1A1ED0_00394368 *g;
    s32 tw, th, lw;
    s32 one = 1;
    g = &D_001A1ED0_00394368;
    base = g->x20;
    h8 = t->h8;
    w = (s16)t->h4;
    th = w >> 6;
    if (th <= 0) th = one;
    { s32 r; __asm__("plzcw %0, %1" : "=r"(r) : "r"(w)); lw = 30 - r; }
    { s32 r; __asm__("plzcw %0, %1" : "=r"(r) : "r"((s32)t->h6)); lh = 30 - r; }
    base >>= 8;
    hA = t->hA + base;
    hC = t->hC + base;
    hE = t->hE + base;
    tw = w >> 7;
    if (tw <= 0) tw = one;
    if (idx >= 0) {
        if (h8 == 0) {
            s32 tbp = t->w0;
            tbp = (g->x34 + tbp * 4) >> 8;
            p[0] = TEX1(0, 0, 1, b, 0, 0, a);
            p += 2;
            p[0] = c | ((unsigned long)d << 2) | ((unsigned long)idx << 24);
            p += 2;
            p[0] = TEX0(tbp, th, 0x1B, lw, lh, 1, 0, hA, 0, 0, 0, 4);
            p[2] = MIPTBP1(0, 1, 0, 1, 0, 1);
        } else {
            p[0] = TEX1(0, h8 - 1, 1, b, 0, 0, a);
            p += 2;
            p[0] = c | ((unsigned long)d << 2) | ((unsigned long)idx << 24);
            p += 2;
            p[0] = TEX0(0, th, 0x13, lw, lh, 1, 0, hA, 0, 0, 0, 4);
            p[2] = MIPTBP1(0, tw, hC, 1, hE, 1);
        }
        return;
    }
    if (idx < -1) {
        unsigned long *q = D_001DFF10;
        if (idx == -3) q = D_001DFF28;
        p[0] = TEX1(0, 0, 1, b, 0, 0, a);
        p += 2;
        p[0] = 5;
        p += 2;
        p[0] = q[0];
        p[2] = q[2];
    } else {
        p[0] = TEX1(0, 0, 1, b, 0, 0, a);
        p += 2;
        p[0] = 5;
        p += 2;
        p[0] = 0x80000004CC007FFBUL;
        p[2] = 0;
    }
}
