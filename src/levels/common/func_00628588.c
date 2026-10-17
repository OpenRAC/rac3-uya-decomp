#include "common.h"

typedef int q128 __attribute__((mode(TI)));

typedef struct {
    char pad0[0xA0];
    q128 cur;
    char padB0[0x1DC0 - 0xB0];
    q128 hist[32];
    char pad1FC0[0x2348 - 0x1FC0];
    s32 pos;
    s32 count;
} Obj;

extern s32 func_00628638(Obj *, s32);

void func_00628588(Obj *o) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (func_00628638(o, i) == 1) {
            return;
        }
        if (o->count >= 2) {
            o->count--;
            o->pos = (o->pos + 31) % 32;
        }
        o->cur = ((Obj *)((char *)o + o->pos * 16))->hist[0];
    }
}
