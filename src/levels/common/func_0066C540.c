#include "common.h"

typedef struct {
    char pad0[0x8];
    char head[0x19 - 0x8];
    char bits[0x1DC - 0x19];
    s32 count;
} Obj;

extern void func_0058F1B0(char *, char *, s32);
extern f32 func_001369D0(f32);

s32 func_0066C540(Obj *o, char *dst) {
    s32 ret;

    if (o->count == -1) {
        ret = 0;
    } else {
        func_0058F1B0(dst, o->head, 8);
        dst += 8;
        func_0058F1B0(dst, o->bits, (s32)func_001369D0(o->count * 0.125f));
        ret = (s32)func_001369D0(o->count * 0.125f) + 8;
    }
    return ret;
}
