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

typedef int Q_424478 __attribute__((mode(TI)));
typedef struct { s32 w0; u16 h4; s16 h6; s16 h8; s16 hA; s16 hC; s16 hE; } T_424478;
typedef struct { u8 p0[0x20]; s32 x20; } G_424478;
typedef struct { s32 x0; u8 p4[12]; } E_424478;
typedef struct {
    s32 x[3];
    u8 cnt[3];
    u8 n;
    f32 f10;
    f32 f14;
    f32 f18;
    s32 x1C;
    s32 x20;
    u8 p24[0x30 - 0x24];
    s32 x30;
    s32 x34;
    u8 p38[0x3E - 0x38];
    s16 h3E;
    u8 p40[0x46 - 0x40];
    u16 h46;
    f32 f48;
} H_424478;

extern G_424478 D_001A1ED0;
extern unsigned long D_001F3E40[];
extern u8 D_0023C880[];
extern s16 D_0023C780[];
extern s32 D_0023C580[];
extern s32 D_00243880[];
extern Q_424478 D_00243C80[];
extern s32 D_001E0F50;

/* localdecomp:start func_00424478 */
void func_00424478(H_424478 *h, T_424478 *tbl, Q_424478 *src, s32 k) {
    s32 i, j, n;
    u8 *ids;
    s32 *p;
    s32 m = D_001E0F50;
    D_0023C880[k] = D_001E0F50;
    D_0023C780[m] = k;
    D_0023C580[m] = (s32)h;
    h->h46 = D_001E0F50;
    D_001E0F50 = m + 1;
    D_00243880[m] = (s32)(h->f48 * 1024.0f);
    h->x20 = -1;
    h->h3E = 0;
    for (i = 0; i < 3; i++) {
        if (h->x[i] != 0) {
            h->x[i] += (s32)h;
            for (j = 0; j < h->cnt[i]; j++) {
                ((E_424478 *)h->x[i])[j].x0 += h->x[i];
            }
        }
    }
    if (h->cnt[1] == 0) h->f14 = 8190.0f;
    if (h->cnt[2] == 0) h->f18 = 8192.0f;
    h->x30 = 0;
    h->x34 += (s32)h;
    h->x1C += (s32)h;
    ids = (u8 *)&D_00243C80[D_0023C880[k]];
    *(Q_424478 *)ids = *src;
    p = (s32 *)h->x1C;
    for (n = 0; n < h->n; n++) {
        s32 idx = ids[n];
        s32 a = p[4];
        s32 b = p[5];
        s32 c = p[12];
        s32 d = p[13];
        unsigned long *q = (unsigned long *)p;
        if (tbl != 0) {
            T_424478 *t = &tbl[idx];
            G_424478 *g = &D_001A1ED0;
            s32 base = g->x20;
            s32 h8 = t->h8;
            s32 th = (s16)t->h4 >> 6;
            s32 tw, lw, lh, hA, hC, hE;
            if (th <= 0) th = 1;
            { s32 r; __asm__("plzcw %0, %1" : "=r"(r) : "r"((s32)(s16)t->h4)); lw = 30 - r; }
            { s32 r; __asm__("plzcw %0, %1" : "=r"(r) : "r"((s32)t->h6)); lh = 30 - r; }
            base >>= 8;
            hA = t->hA + base;
            hC = t->hC + base;
            hE = t->hE + base;
            tw = (s16)t->h4 >> 7;
            if (tw <= 0) tw = 1;
            q[0] = TEX0(0, th, 0x13, lw, lh, 1, 0, hA, 0, 0, 0, 4);
            q[2] = TEX1(0, h8 - 1, 1, b, 0, 0, a);
            q[4] = MIPTBP1(0, tw, hC, 1, hE, 1);
            q[6] = c | ((unsigned long)d << 2) | ((unsigned long)idx << 24);
        } else {
            unsigned long t0 = D_001F3E40[idx * 3];
            unsigned long t1 = D_001F3E40[idx * 3 + 1];
            unsigned long t2 = D_001F3E40[idx * 3 + 2];
            q[0] = t0;
            q[2] = (((t1 & 0x1C) | 0x20) | ((unsigned long)b << 6)) | ((unsigned long)a << 32);
            q[4] = t2;
            q[6] = c | ((unsigned long)d << 2) | ((unsigned long)idx << 24);
        }
        p += 20;
    }
}
/* localdecomp:end func_00424478 */
