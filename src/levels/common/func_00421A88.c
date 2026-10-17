#include "common.h"

typedef struct {
    u8 p0[0x20]; u8 state;
    u8 p21[0x68 - 0x21]; u8 *vars;
} S_Moby421A88;

extern S_Moby421A88 *func_00421938(S_Moby421A88 *, s32);

void func_00421A88(S_Moby421A88 *m, s32 x) {
    u8 *mv = m->vars;
    s32 n1 = *(s32 *)(mv + 0x30);
    s32 n3 = *(s32 *)(mv + 0x38);
    s32 n2 = *(s32 *)(mv + 0x34);
    s32 i;
    S_Moby421A88 *o;

    if (n1 > 0) {
        i = 0;
        while (i < n1) {
            o = func_00421938(m, 4255);
            if (o == 0) break;
            {
                S_Moby421A88 *p = o;
                u8 *v;
                p->state = 39;
                v = p->vars;
                *(s32 *)(v + 0x2B8) = x;
                *(s32 *)(v + 0x34C) = *(s32 *)(v + 0x3D8);
            }
            i++;
        }
    }
    if (n3 > 0) {
        i = 0;
        while (i < n3) {
            o = func_00421938(m, 6646);
            if (o == 0) break;
            {
                S_Moby421A88 *p = o;
                u8 *v;
                p->state = 39;
                v = p->vars;
                *(s32 *)(v + 0x1C0) = 500;
                *(s32 *)(v + 0x1A0) = x;
            }
            i++;
        }
    }
    if (n2 > 0) {
        i = 0;
        while (i < n2) {
            o = func_00421938(m, 6683);
            if (o == 0) break;
            {
                S_Moby421A88 *p = o;
                u8 *v;
                p->state = 39;
                v = p->vars;
                *(s32 *)(v + 0x2AC) = x;
                *(s32 *)(v + 0x2E8) = *(s32 *)(v + 0x308);
            }
            i++;
        }
    }
}
