#include "common.h"

typedef struct {
    u8 pad0[12];
    u16 flags;
    u8 pad1[18];
} Slot354F48;

typedef struct {
    u8 pad0[128];
    Slot354F48 slots[32];
    s32 count;
} Vars354F48;

extern u8 *D_001DF71C[];
extern void func_00354ED8(u8 *);
extern s32 func_00446FA0(s32, Slot354F48 *, s32, s32 *);

void func_00354F48(s32 idx, s32 arg, s32 on) {
    u8 *m = D_001DF71C[0] + (idx << 8);
    Vars354F48 *v;
    s32 slot;

    v = *(Vars354F48 **)(m + 104);
    if (m[32] == 0) {
        func_00354ED8(m);
    }
    slot = -1;
    if (func_00446FA0(arg, v->slots, v->count, &slot) != 0) {
        if (on != 0) {
            *(u16 *)((u8 *)v + (slot << 5) + 140) &= ~1;
        } else {
            *(u16 *)((u8 *)v + (slot << 5) + 140) |= 1;
        }
    }
}
