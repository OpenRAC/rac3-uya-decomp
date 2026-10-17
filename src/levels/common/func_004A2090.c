#include "common.h"

extern void func_004A2090(void);

typedef struct { s16 h0; s16 h2; } S_98T;
extern s32 D_00239F70_003D98D0[];
extern u8 *D_002384F0_003D98D0[];
extern S_98T D_00239A70_003D98D0[];
void func_004A2090(void) {
    s32 *ip = D_00239F70_003D98D0;
    u8 *obj;
    u8 *sub;
    u8 *e;
    u8 *q; u8 *tab;
    s32 j, k, off;
    S_98T *t;
    while (*ip >= 0) {
        obj = D_002384F0_003D98D0[*ip];
        j = 0;
        if (*(s16 *)(obj + 0x28) > 0) {
            tab = obj + 0x40;
            do {
                off = j * 8;
                sub = *(u8 **)(tab + off);
                e = sub + 0x10;
                q = e + *(s32 *)(e + 4) * 16 + 0x10;
                for (k = 0; k < *(s32 *)e; k++, q += 0x40) {
                    t = &D_00239A70_003D98D0[q[0x13]];
                    if (t->h0 != 0) *(u32 *)(q + 0x30) = (*(u32 *)(q + 0x30) & 0xFFFFC000) | t->h0;
                    if (t->h2 != 0) *(u32 *)(q + 0x20) = (*(u32 *)(q + 0x20) & 0xFFFFC000) | t->h2;
                }
                j++;
            } while (j < *(s16 *)(obj + 0x28));
        }
        ip++;
    }
}
