#include "common.h"
typedef struct E_5A8E28 E_5A8E28;
typedef struct { u8 pad[0x1C]; u8 **x1C; } T_5A8E28;
typedef struct { u8 pad[0x24]; T_5A8E28 *x24; u8 pad28[0x50 - 0x28]; E_5A8E28 *x50; } O_5A8E28;
struct E_5A8E28 { s16 x0; s16 x2; u8 x4; u8 pad5[7]; u8 *xC; s32 x10; T_5A8E28 *x14; u8 pad18[4]; E_5A8E28 *x1C; u8 pad20[0x20]; };
extern E_5A8E28 D_00269000[];
E_5A8E28 *func_005A8E28(O_5A8E28 *a0, s32 a1, s32 a2) {
    s32 i;
    E_5A8E28 *e;
    u8 *p;
    for (i = 0; i < 24; i++) {
        if (D_00269000[i].x4 == 0) {
            break;
        }
    }
    if (i == 24) {
        return 0;
    }
    e = &D_00269000[i];
    e->x4 = 2;
    e->x10 = a2;
    e->x0 = a1;
    e->x14 = a0->x24;
    p = a0->x24->x1C[(s16)a1 + 1];
    e->x2 = p[2];
    e->xC = p + (p[0] + 4);
    e->x1C = a0->x50;
    a0->x50 = e;
    return e;
}
