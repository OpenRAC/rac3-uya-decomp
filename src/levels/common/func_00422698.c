#include "common.h"

/* localdecomp:start func_00422698 */
typedef struct { unsigned long z; s16 h8; s16 hA; s16 hC; s16 hE; } E_393878;
typedef struct { s16 h0; s16 h2; s16 h4; u8 p6[0x1A]; s32 f20; } F_393878;
typedef struct { u8 p0[4]; s16 h4; s16 h6; u8 p8[4]; s16 hC; u8 pE[2]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20[1]; } H_393878;
extern H_393878 *D_001E0E70;
void func_00422698(H_393878 *p) {
    H_393878 *q;
    s32 i, k;
    D_001E0E70 = p;
    p->h4 = 1;
    p->f10 += (s32)p;
    p->f14 += (s32)p;
    p->f18 += (s32)p;
    if (p->f1C) p->f1C += (s32)p;
    q = D_001E0E70;
    {
        s32 *src = (s32 *)q->f10;
        for (i = 0; i < q->hC; i++) {
            s32 a = *src++ >> 4;
            s32 b = *src++ >> 4;
            s32 c, d;
            { s32 r; __asm__("plzcw %0, %1" : "=r"(r) : "r"(*src++)); c = 30 - r; }
            { s32 r; __asm__("plzcw %0, %1" : "=r"(r) : "r"(*src++)); d = 30 - r; }
            ((E_393878 *)q->f10)[i].hA = a;
            ((E_393878 *)q->f10)[i].h8 = b;
            ((E_393878 *)q->f10)[i].hC = c;
            ((E_393878 *)q->f10)[i].hE = d;
            ((E_393878 *)q->f10)[i].z = 0;
        }
    }
    for (k = 0; k < D_001E0E70->h6; k++) {
        F_393878 *e = (F_393878 *)(D_001E0E70->f20[k] + (s32)p);
        s32 j;
        if (!(e->h2 & 1)) {
            if (e->h4) {
                e->h2 = e->h4;
                e->h4 = 0;
            }
        }
        D_001E0E70->f20[k] = (s32)e;
        for (j = 0; j < e->h0; j++) {
            ((F_393878 *)((u8 *)e + j * 0x20))->f20 += (s32)p;
        }
    }
}
/* localdecomp:end func_00422698 */
