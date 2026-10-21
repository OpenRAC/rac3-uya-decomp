#include "common.h"

/* localdecomp:start func_0044C1D0 */
typedef int Q_44C1D0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_44C1D0;
typedef struct {
    u8 pad0[0x44];
    void *p44;
    s16 x48;
    u8 b4A;
    u8 b4B;
    u8 b4C;
    u8 b4D;
    u8 b4E;
    u8 b4F;
} E_44C1D0;
typedef struct {
    u8 pad0[0x10];
    V4_44C1D0 v10;
    u8 pad20[0xC0 - 0x20];
    Q_44C1D0 m[3];
    Q_44C1D0 n[3];
} A_44C1D0;

extern void func_0040BD58(void *, void *, s32);
extern void func_0040C638(void *, void *);
extern void func_00437600(void *, s32, void *);
extern void func_0040C8C0(void *, void *);
extern void func_0044C0E8(void *, void *, void *);
extern void func_0040C8A0(void *, void *);
extern void func_00447748(void *, void *);
extern void func_0044C000(void *, void *, void *, void *, void *);
extern void func_00439610(void *);
extern void func_004AF7D0(s32, s32);
extern f32 func_0040BF38(void *);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0040BEC0(void *, void *, f32);
extern u8 *D_001E009C;
extern u8 *D_001E0F5C;
extern u8 *D_001E0E50;
extern u8 *D_001E0E48;
extern s32 D_001DFBC0;
extern void *D_002384F0[];

void func_0044C1D0(A_44C1D0 *a, E_44C1D0 *list) {
    E_44C1D0 *e;
    Q_44C1D0 m[3];
    V4_44C1D0 v;
    f32 sc;
    Q_44C1D0 m2[4];

    if (list->b4A == 0) {
        return;
    }
    if (list->b4D) {
        func_0040BD58(m, a->m, 0x30);
    } else {
        func_0040C638(m, a->n);
    }
    sc = 4096.0f;
    v = a->v10;
    v.w = 0.0f;
    e = list;
    do {
        if (e->p44) {
            func_00437600(e->p44, e->b4B, m2);
            func_0040C8C0(m, m2);
        }
        switch (e->b4C & 3) {
        case 0: {
            u8 *o = D_001E009C + e->x48 * 256;
            if (*(s32 *)(o + 0x24) == 0) {
                func_0040C638(o + 0xC0, o + 0xF0);
            }
            func_0044C0E8(e, m, o + 0xC0);
            if (*(s32 *)(o + 0x24) == 0) {
                func_0040C8A0(m2, o + 0xC0);
                func_00447748(m2, o + 0xF0);
            }
            break;
        }
        case 1:
            func_0044C0E8(e, m, D_001E0F5C + e->x48 * 64);
            break;
        case 2: {
            f32 f = *(f32 *)(D_001E0E50 + e->x48 * 64 + 0x1C);
            func_0044C0E8(e, m, D_001E0E50 + e->x48 * 64);
            *(f32 *)(D_001E0E50 + e->x48 * 64 + 0x1C) = f;
            break;
        }
        }
        switch (e->b4C & 3) {
        case 0: {
            u8 *o = D_001E009C + e->x48 * 256;
            func_0044C000(o + 0x10, e, &v, m, o + 0xC0);
            break;
        }
        case 1: {
            u8 *o = D_001E0F5C + e->x48 * 64;
            func_0044C000(o + 0x30, e, &v, m, o);
            break;
        }
        case 2: {
            u8 *o = D_001E0E50 + e->x48 * 64;
            func_0044C000(o + 0x30, e, &v, m, o);
            break;
        }
        }
        switch (e->b4C & 3) {
        case 0:
            if (*(s32 *)(D_001E009C + e->x48 * 256 + 0x24)) {
                func_00439610(D_001E009C + e->x48 * 256);
            }
            break;
        case 1: {
            s32 k;
            k = 0;
            if (e->b4E == 0) {
                k = 1;
            } else if (e->b4E != 0xFF && D_001DFBC0 % e->b4E == e->b4F) {
                k = 1;
            }
            func_004AF7D0(e->x48, k);
            break;
        }
        case 2: {
            u8 *o = D_001E0E50 + e->x48 * 64;
            u8 *q = D_001E0E48 + e->x48 * 32;
            f32 s, t;
            s32 hi, lo;
            s = func_0040BF38(o) + func_0040BF38(o + 0x10);
            s *= 0.5f;
            t = func_0040BF38(o + 0x20);
            hi = (s32)(t * sc);
            lo = (s32)(s * sc);
            if (hi > 0x10000) hi = 0x10000;
            if (lo > 0x10000) lo = 0x10000;
            *(s32 *)(o + 0x2C) = lo | (hi << 16);
            func_0040C2D0(q, D_002384F0[q[0x1A]], o);
            func_0040BEC0(q, q, *(f32 *)(o + 0x3C));
            __asm__ __volatile__("lqc2 $vf2, 0x30(%0)\n\tlqc2 $vf1, 0x0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0x0(%1)" : : "r"(o), "r"(q) : "memory");
            break;
        }
        }
    } while (e++->b4A != 1);
}
/* localdecomp:end func_0044C1D0 */
