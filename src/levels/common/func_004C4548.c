#include "common.h"

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    s32 w8;
    s32 w12;
    s32 w16;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w32;
    s32 w36;
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w52;
    s32 w56;
    s32 w60;
    s32 owner;
    char pad44[0x50 - 0x44];
} Slot;

extern Slot D_0024E660[];
extern void func_00437350(s32, s32, Slot *);

s32 func_004C4548(s32 owner, s32 arg1) {
    Slot *e;
    s32 i;

    for (i = 0; i < 64; i++) {
        e = &D_0024E660[i];
        if (e->owner == 0) {
            e->w4 = -1;
            e->owner = owner;
            e->b3 = 0;
            e->b0 = 0;
            e->w12 = 0;
            e->w8 = 0;
            e->w16 = 0;
            e->w20 = 0;
            e->w24 = 0;
            e->w28 = 0;
            e->w48 = 0;
            e->w52 = 0;
            e->w56 = 0;
            e->w60 = 0;
            e->b2 = 0;
            e->w32 = 0;
            e->w36 = 0;
            e->w40 = 0;
            e->w44 = 0;
            e->b1 = 0;
            func_00437350(owner, arg1, e);
            goto out;
        }
    }
out:
    return i;
}
