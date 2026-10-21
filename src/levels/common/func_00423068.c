#include "common.h"

/* localdecomp:start func_00423068 */
extern void func_004C1E50(s32);
extern s32 func_0045CA60(s32);
extern s32 func_0045CA00(s32, s32, s32);
extern void func_0012C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_0011F0A0(s32);
extern void func_0012CCC8(void *, void *);
extern s32 func_0012A9F0(s32, s32);

/* MATCH */
typedef struct { u8 p0[0x30]; s32 x30; u8 p34[4]; unsigned long x38; } S_16C580_00393E90;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAF0]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393E90;
typedef struct { u8 p0[0x18]; s32 x18; u8 p1c[0x10]; s32 x2C; } S_1A1ED0_00393E90;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393E90;
extern S_16C580_00393E90 D_0016C580_00393E90;
extern S_160C40_00393E90 D_00160C40_00393E90;
extern S_1A1ED0_00393E90 D_001A1ED0_00393E90;
extern s32 D_001E10F4;
extern s32 D_001E10E0[];
extern s32 func_0045CA60(s32);
extern s32 func_0045CA00(s32, s32, s32);
extern void func_0012C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_0011F0A0(s32);
extern void func_0012CCC8(void *, void *);
extern s32 func_0012A9F0(s32, s32);
void func_00423068(s32 n) {
    u8 buf[0x60];
    S_16C580_00393E90 *g = &D_0016C580_00393E90;
    S_160C40_00393E90 *b;
    S_1A1ED0_00393E90 *r;
    u8 *t;
    u8 *q;
    s32 w, h, k, lz;
    g->x30 = n;
    func_004C1E50(1);
    t = (u8 *)D_001E10E0[1 - D_001E10F4];
    func_0045CA60(1);
    b = &D_00160C40_00393E90;
    q = t + 0x20;
    func_0045CA00((s32)t, b->e[n].a + b->f1284, b->e[n].b);
    r = &D_001A1ED0_00393E90;
    func_0012C9A0(buf, r->x18 >> 8, 1, 0, 0, 0, 0x10, 0x10);
    func_0011F0A0(0);
    func_0012CCC8(buf, q);
    func_0012A9F0(0, 0);
    w = *(s32 *)(t + 8);
    __asm__("plzcw %0, %1" : "=r"(lz) : "r"(w));
    k = 30 - lz;
    h = w >> 6;
    if (h <= 0) h = 1;
    func_0012C9A0(buf, r->x2C >> 8, h, 0x1B, 0, 0, ((T_00393E90 *)t)->h8, ((T_00393E90 *)t)->hC);
    func_0011F0A0(0);
    func_0012CCC8(buf, t + 0x420);
    func_0012A9F0(0, 0);
    g->x38 = (unsigned long)(r->x2C >> 8) | ((unsigned long)h << 14) | ((unsigned long)0x1B << 20)
           | ((unsigned long)k << 26) | ((unsigned long)k << 30) | ((unsigned long)1 << 34)
           | ((unsigned long)(r->x18 >> 8) << 37) | ((unsigned long)4 << 61);
}
/* localdecomp:end func_00423068 */
