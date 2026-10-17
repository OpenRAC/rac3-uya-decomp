#include "common.h"
typedef int u128_4B75B0 __attribute__((mode(TI)));
typedef struct { u8 a; u8 pad[3]; u16 id; u8 pad2[58]; u128_4B75B0 v0; u128_4B75B0 v1; } Ent_004B75B0;
extern Ent_004B75B0 D_002393F0[];
s32 func_004B75B0(u32 a0, u128_4B75B0 *a1, u128_4B75B0 *a2) {
    u32 idx = a0 >> 16;
    Ent_004B75B0 *e = 0;
    if (idx < 12) {
        Ent_004B75B0 *p = &D_002393F0[idx];
        if (p->a != 0 && p->id == (a0 & 0xFFFF)) e = p;
    }
    if (e) {
        e->v0 = *a1;
        e->v1 = *a2;
        return 1;
    }
    return 0;
}
