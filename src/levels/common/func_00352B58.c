#include "common.h"

typedef struct {
    u8 pad0[0x2E8];
    s32 x2E8;
    u8 pad2EC[0x2F8 - 0x2EC];
    s32 x2F8;
} V_00352B58;

typedef struct {
    u8 pad0[33];
    u8 x21;
    u8 pad22[104 - 34];
    V_00352B58 *x68;
    u8 pad6C[170 - 108];
    s16 xAA;
} M_00352B58;

extern u16 *D_0021DEA0[];
extern u8 *D_001E009C;
extern s32 D_001E00D8;

extern void func_00452F40(M_00352B58 *, s32);

void func_00352B58(M_00352B58 *o) {
    u16 *p;
    M_00352B58 *m;

    if (o->x21 == 255) {
        return;
    }
    func_00452F40(o, 1);
    p = D_0021DEA0[o->x21];
    while (o->x21 != 255 && o->x21 <= D_001E00D8 && p != 0
           && ((s16)p[-1] >= 0 || p == D_0021DEA0[o->x21])) {
        m = (M_00352B58 *)(D_001E009C + ((*p & 0x7FFF) << 8));
        if (m == 0) {
            return;
        }
        if (m->xAA == o->xAA) {
            m->x68->x2E8 = 1;
        } else if (m->xAA == 5861) {
            m->x68->x2F8 = 1;
        } else if (m->xAA == 5860) {
            m->x68->x2F8 = 1;
        }
        p++;
    }
}
