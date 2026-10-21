#include "common.h"

/* localdecomp:start func_003A2BD8 */
typedef struct {
    u8 pad0[0x2E8];
    s32 x2E8;
} V_003A2BD8;

typedef struct {
    u8 pad0[33];
    u8 x21;
    u8 pad22[104 - 34];
    V_003A2BD8 *x68;
    u8 pad6C[170 - 108];
    s16 xAA;
} M_003A2BD8;

extern u16 *D_0021DEA0[];
extern u8 *D_001E009C;
extern s32 D_001E00D8;

extern void func_00442AA8(s32, s32);

void func_003A2BD8(M_003A2BD8 *o) {
    u16 *p;
    M_003A2BD8 *m;

    if (o->x21 == 255) {
        return;
    }
    func_00442AA8(o->x21, 0);
    p = D_0021DEA0[o->x21];
    while (o->x21 != 255 && o->x21 <= D_001E00D8 && p != 0
           && ((s16)p[-1] >= 0 || p == D_0021DEA0[o->x21])) {
        m = (M_003A2BD8 *)(D_001E009C + ((*p & 0x7FFF) << 8));
        if (m == 0) {
            return;
        }
        if (m->xAA == o->xAA) {
            m->x68->x2E8 = 1;
        }
        p++;
    }
}
/* localdecomp:end func_003A2BD8 */
