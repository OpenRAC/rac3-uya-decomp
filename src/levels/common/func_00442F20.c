#include "common.h"

typedef struct { u8 p0[0x6]; u8 b6; u8 p7[7]; u8 bE; u8 bF; s32 w10; u8 p14[0x2C]; s32 w40; } S_442F20;
typedef struct {
    u8 p0[0x22]; u8 b22; u8 p23; S_442F20 *w24; u8 p28[0xC]; u16 h34; u8 p36[0x2B]; u8 b61; u8 b62; u8 b63;
    u8 p64[0xB]; u8 b6F; u8 p70[4]; s32 w74; s32 w78; u16 h7C; u8 p7E[0x1A]; s32 w98; u8 p9C[0xE]; s16 hAA;
} P_442F20;
extern u8 D_001FDC50[];
extern S_442F20 *D_001FD200[];
extern void func_00440D88(s32, s32);
extern void func_00436350(P_442F20 *);
extern void func_004367A0(P_442F20 *, u16 *, s32 *);
extern void func_00439610(P_442F20 *);

s32 func_00442F20(P_442F20 *p, s32 b, s32 c) {
    struct { u16 h; u16 pad; s32 w; } tmp;
    if (p->hAA == b) {
        return 0;
    }
    p->hAA = b;
    p->b22 = D_001FDC50[(s16)b];
    p->w24 = D_001FD200[p->b22];
    p->b61 = 0xFF;
    func_00440D88(b, c);
    func_00436350(p);
    p->b62 = p->w24->bE;
    if (p->w98 != 0) {
        p->w98 = p->w24->w10;
    }
    if (p->w24 != 0) {
        if (p->w24->w40 != 0) {
            p->h34 |= 0x10;
            p->w78 = p->w24->w40;
        } else {
            p->w78 = 0;
            p->h34 &= ~0x10;
        }
        if (p->w24->bF != 0) {
            p->b6F = 0x18;
            p->h34 |= 0x400;
        } else {
            p->b6F = 0;
            p->h34 &= ~0x400;
            p->w74 = 0;
        }
        if (p->w24->b6 != 0) {
            p->b63 = 0x18;
        } else {
            p->b63 = 0;
        }
        if (p->h7C != 0) {
            func_004367A0(p, &tmp.h, &tmp.w);
            p->h7C = tmp.h;
        }
    }
    func_00439610(p);
    return 1;
}
