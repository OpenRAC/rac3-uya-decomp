#include "common.h"

extern s32 D_001A5E58[];

typedef struct {
    u8 pad0[728];
    s32 unk2D8;
    s32 unk2DC;
    u8 pad2E0[760 - 736];
    u32 unk2F8;
} Obj665B20;

typedef struct {
    u8 pad0[9512];
    Obj665B20 *obj;
    u8 pad[9548 - 9516];
    s32 state;
} Ctx665B20;

void func_00665B20(Ctx665B20 *p, s32 n) {
    Obj665B20 *obj;
    s32 st;

    n++;
    if (n >= 8) {
        n = 0;
    }
    obj = p->obj;
    if (obj == 0) {
        return;
    }
    st = p->state;
    if (st == 5 || st == 3) {
        obj->unk2D8 = 0;
        if (D_001A5E58[0] == n) {
            p->obj->unk2F8 |= 4;
            p->obj->unk2F8 |= 2;
            p->obj->unk2F8 &= 0xFFFFFFDF;
        }
    } else if (st == 6 || st == 4) {
        obj->unk2DC = 0;
    }
    p->obj = 0;
    p->state = 0;
}
