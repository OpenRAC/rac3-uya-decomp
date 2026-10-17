#include "common.h"

extern void func_00436350();
extern u32 D_001E009C;
extern void func_00435F98();
extern void func_0040BBA8();

typedef struct { u8 p0[0x6]; u8 b6; u8 p7[5]; u8 bC; u8 pD; u8 bE; u8 bF; s32 w10; u8 p14[0x10]; f32 f24; u8 p28[0x18]; s32 w40; u16 h44; u8 p46; u8 b47; struct { u8 p[0x10]; u8 b10; s8 b11; } *w48; } S_3BD0D8;
typedef struct {
    u8 p0[0x21]; u8 b21; u8 b22; u8 b23; S_3BD0D8 *w24; u8 p28[4]; f32 f2C; u8 p30[4]; u16 h34; s16 h36; u8 d38[8]; u8 p40[8]; s32 w48; f32 f4C; u8 p50[0x11]; u8 b61; u8 b62; u8 b63; s32 w64; u8 p68[4]; u8 b6C; u8 b6D; u8 b6E; u8 b6F; s32 w70; s32 w74; s32 w78; u8 p7C[2]; u8 b7E; u8 p7F[0x19]; s32 w98; u8 p9C[8]; u8 bA4; u8 bA5; u8 bA6; u8 bA7; u8 bA8; u8 pA9; s16 hAA; s32 wAC; u8 pB0[0xD]; u8 bBD;
} P_3BD0D8;
extern u8 D_001FDC50[];
extern s16 D_001FDA70[];
extern s32 D_001FFC50[];
extern s32 D_001FD5C0[];
extern S_3BD0D8 *D_001FD200[];
extern u32 D_001E009C;
void func_00435F98(P_3BD0D8 *p, s32 b) {
    u8 t;
    S_3BD0D8 *s;
    S_3BD0D8 *r;
    s32 v;
    func_0040BBA8(p, 0, 0x100);
    t = D_001FDC50[b];
    p->b23 = 0x80;
    p->b22 = t;
    p->bA8 = 0xFF;
    p->b21 = 0xFF;
    p->b61 = 0xFF;
    p->b62 = 0xFF;
    p->hAA = b;
    p->wAC = (((s32)p - (s32)D_001E009C) >> 8) << 16;
    p->b6E = 0;
    p->b6C = 0xFF;
    p->bA4 = 0x7F;
    *(unsigned long *)p->d38 = 0x0040404000000000UL;
    p->bA6 = 0x80;
    p->h36 = 0x7F80;
    p->b6D = 0xFF;
    p->bA5 = 0x7F;
    p->bA7 = 0x80;
    if (D_001FDA70[p->b22] != b) {
        p->h34 |= 5;
        p->w24 = 0;
        p->w98 = 0;
        p->w64 = D_001FFC50[p->b22];
        if (p->w64 == 0) p->h34 |= 2;
    } else {
        v = D_001FD5C0[p->b22];
        p->w64 = v;
        if (v == 0) p->h34 |= 2;
        s = D_001FD200[p->b22];
        p->w24 = s;
        p->b62 = s->bE;
        p->h34 = p->h34 | s->h44;
        p->w98 = s->w10;
        p->f2C = s->f24;
        *(f32 *)&p->w48 = 1.0f;
        p->f4C = 1.0f;
        if (s->w40 != 0) {
            p->h34 |= 0x10;
            p->w78 = s->w40;
        }
        if (p->w24->bF != 0) {
            p->b6F = 0x18;
            p->h34 |= 0x400;
            p->w70 = 0;
            p->w74 = 0;
            p->bBD = 0;
        }
        if (p->w24->b6 != 0) p->b63 = 0x18;
        if (p->w24->w48 != 0) {
            func_00436350(p);
            if (p->w24->w48->b10 >= 2) p->h34 &= 0xFFFD;
            r = p->w24;
            if (r->bC == 1) {
                if (r->w48->b10 < 2) {
                    p->w48 = 0;
                    if (r->w48->b11 < 0) p->h34 |= 0x40;
                }
            }
        }
        p->b7E |= p->w24->b47;
    }
}
