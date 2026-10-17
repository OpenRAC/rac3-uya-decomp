#include "common.h"

extern void func_0045CDF8(s32, long);

typedef struct { u8 pad[0x10]; s16 h10; u8 pad2[6]; s32 x18; } S_39DA60;
typedef struct { u8 pad[0x2C]; s16 h2C; s16 pad2; s32 x30; s32 x34; } S2_39DA60;
extern S2_39DA60 D_001CCFD0_0039DA60[];
void func_0045CDF8(s32 a, long b) {
    S_39DA60 *p = (S_39DA60 *)(s32)b;
    if (p) {
        p->x18 = a;
        if (p->h10) {
            S2_39DA60 *d = D_001CCFD0_0039DA60;
            if (d->h2C == 1 && a != 0) {
                d->h2C = 2;
                d->x30 = p->x18;
                d->x34 = p->x18 / 4;
            }
        }
    }
}
