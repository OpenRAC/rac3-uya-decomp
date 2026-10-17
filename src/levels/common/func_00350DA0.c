#include "common.h"
typedef int u128_350DA0 __attribute__((mode(TI)));
typedef struct { u8 pad[0x18]; s32 x18; } V_350DA0;
typedef struct { u8 pad[0x10]; u128_350DA0 pos; u8 pad20[0x10]; u8 x30; u8 pad31[0x68 - 0x31]; V_350DA0 *x68; } O_350DA0;
extern O_350DA0 *func_004083B0(s32, s32);
extern void func_0034FFE0(O_350DA0 *);
O_350DA0 *func_00350DA0(O_350DA0 *a) {
    O_350DA0 *o = func_004083B0(5951, 128);
    if (o != 0) {
        o->x30 = 255;
        o->x68->x18 = 0;
        o->pos = a->pos;
        func_0034FFE0(o);
    }
    return o;
}
