#include "common.h"
typedef int u128_34D450 __attribute__((mode(TI)));
typedef struct { u8 pad[0x14]; s32 x14; s32 x18; s32 x1C; u8 pad20[4]; s32 x24; } V_34D450;
typedef struct { u8 pad[0x10]; u128_34D450 pos; u8 x20; u8 pad21[0x30 - 0x21]; u8 x30; u8 pad31; s16 x32; u8 pad34[0x68 - 0x34]; V_34D450 *x68; } O_34D450;
extern O_34D450 *func_0040C9B0(s32, s32);
extern void func_004749F8(s32, s32, O_34D450 *, s32);
O_34D450 *func_0034D450(u128_34D450 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    O_34D450 *o = func_0040C9B0(5751, 48);
    if (o == 0) {
        return 0;
    } else {
        V_34D450 *v;
        o->x30 = 255;
        o->x32 = 64;
        v = o->x68;
        o->pos = *a0;
        v->x14 = a1;
        v->x18 = a2;
        v->x1C = a3;
        v->x24 = a4;
        o->x20 = 0;
        func_004749F8(1, 0, o, 5751);
    }
    return o;
}
