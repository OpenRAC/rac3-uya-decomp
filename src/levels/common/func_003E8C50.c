#include "common.h"

typedef int s128_003E8C50 __attribute__((mode(TI)));

typedef struct {
    u8 pad[512];
    u8 data[48];
    s128_003E8C50 q;
    u8 pad2[1120 - 576];
} Slot_003E8C50;

typedef struct {
    u8 pad[56];
    u8 a38[4];
    u8 a3C[4];
} Base_003E8C50;

typedef struct {
    u8 pad[28];
    Base_003E8C50 *p;
} Ent_003E8C50;

typedef struct {
    u8 pad[48];
    s128_003E8C50 q30;
    u8 pad2[112 - 64];
    s32 *f70;
    u8 pad3[10];
    s16 h7E;
    u8 pad4[4];
    s16 h84;
    u8 pad5[14];
    s32 f94;
} Obj_003E8C50;

extern Slot_003E8C50 D_001E2AC0[];
extern Ent_003E8C50 *D_001DF884;
extern void func_0040BCB8(Obj_003E8C50 *, void *, s32);
extern void func_003E8B30(Obj_003E8C50 *);

void func_003E8C50(Obj_003E8C50 *obj) {
    Slot_003E8C50 *s = (Slot_003E8C50 *)(obj->f94 * 1120 + (u8 *)D_001E2AC0);
    Base_003E8C50 *base = D_001DF884[obj->h84].p;
    if (base->a3C[obj->f94]) {
        base->a3C[obj->f94] = 0;
        obj->q30 = s->q;
        func_0040BCB8(obj, s->data, 48);
    } else {
        s32 *z = obj->f70;
        z[0] = 0;
        z[2] = 0;
        z[1] = 0;
        z[3] = 0;
        z[4] = 0;
        z[5] = 0;
        z[6] = 0;
        func_003E8B30(obj);
    }
    base->a38[obj->f94] = 0;
    obj->h7E = 0;
}
