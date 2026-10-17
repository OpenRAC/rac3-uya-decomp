#include "common.h"
typedef int u128_3C9E88 __attribute__((mode(TI)));
typedef struct { u8 pad[0x10]; u128_3C9E88 pos; u8 pad20[0xE0]; } M_3C9E88;
typedef struct { u8 pad[0x30]; u128_3C9E88 x30; u8 pad40[0x40]; } E_3C9E88;
typedef struct { u8 pad[0x60]; s32 x60; s32 x64; } T_3C9E88;
typedef struct { u8 pad[0x47C]; s32 x47C; u8 pad480[0x10]; u8 x490; u8 x491; u8 pad492[0x4A0 - 0x492]; u128_3C9E88 x4A0; } V_3C9E88;
typedef struct O_3C9E88 O_3C9E88;
struct O_3C9E88 { u8 pad[0x20]; u8 x20; u8 pad21[0x68 - 0x21]; void *x68; u8 pad6C[0xB8 - 0x6C]; O_3C9E88 *xB8; u8 xBC; };
extern M_3C9E88 *D_001E009C;
extern E_3C9E88 *D_001E0180;
extern void func_00441FB8(O_3C9E88 *, s32, s32);
s32 func_003C9E88(O_3C9E88 *a0, s32 a1, s32 a2) {
    V_3C9E88 *v = a0->x68;
    T_3C9E88 *t = a0->xB8->xB8->x68;
    u8 old = a0->x20;

    if (v->x491) {
        return 0;
    }
    v->x490 = a1;
    v->x47C = a2;
    if (a0->x20 != 24) {
        if (t->x60 != -1) {
            v->x4A0 = *(u128_3C9E88 *)((u8 *)D_001E009C + (t->x60 << 8) + 0x10);
        } else if (t->x64 != -1) {
            v->x4A0 = *(u128_3C9E88 *)((u8 *)D_001E0180 + (t->x64 << 7) + 0x30);
        }
        a0->xBC = 0;
        func_00441FB8(a0, 24, -1);
    }
    return a0->x20 != old;
}
