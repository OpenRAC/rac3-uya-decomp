#include "common.h"
typedef int u128_3B1528 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B1528;
typedef struct { u8 pad[2]; s16 x2; s32 x4; s32 x8; u8 xC; u8 xD; u8 xE; u8 xF; } V_3B1528;
typedef struct { u8 pad[0x10]; V4_3B1528 pos; u8 pad20[0x10]; u8 x30; u8 pad31; s16 x32; u8 pad34[0x68 - 0x34]; V_3B1528 *x68; } O_3B1528;
extern f32 D_001DEC6C;
extern u8 D_001DEC70;
extern u8 D_001DEC71;
extern u8 D_001DEC72;
extern u8 D_001DEC73;
extern O_3B1528 *func_004083B0(s32, s32);
extern void func_004140C0(O_3B1528 *, s32, s32);
O_3B1528 *func_003B1528(V4_3B1528 *a0, s32 a1) {
    O_3B1528 *o = func_004083B0(7537, 16);
    if (o == 0) {
        return 0;
    } else {
        V_3B1528 *v;
        o->x30 = 255;
        o->x32 = 255;
        v = o->x68;
        *(u128_3B1528 *)&o->pos = *(u128_3B1528 *)a0;
        o->pos.y -= D_001DEC6C;
        v->xC = D_001DEC70;
        v->xD = D_001DEC71;
        v->xE = D_001DEC72;
        v->xF = D_001DEC73;
        v->x2 = a1;
        v->x4 = 0;
        v->x8 = 0;
        func_004140C0(o, 0, -1);
    }
    return o;
}
