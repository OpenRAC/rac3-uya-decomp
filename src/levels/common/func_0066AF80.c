#include "common.h"

typedef struct {
    char pad0[0x44];
    union {
        u8 b;
        s32 w;
    } team;
    char pad48[0x50 - 0x48];
    u8 unk50;
} Obj;

extern s32 func_0061A800(s32);

s32 func_0066AF80(Obj *o, u8 b, u8 c) {
    s32 ret = 0;
    s32 same = 1;

    if (c != o->team.b) {
        same = 0;
        if (func_0061A800(c) != 0) {
            o->team.w = c;
            ret = 1;
        }
    }
    if (same) {
        if (o->unk50 < b) {
            ret = 1;
        } else if (o->unk50 >= 193 && b <= 63) {
            ret = 1;
        }
    }
    return ret;
}
