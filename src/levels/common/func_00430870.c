#include "common.h"

extern u8 *func_0053EDD8(s32, s32, s32);
extern void func_00532398(u8 *, void *, s32);

f32 func_00430870(s32 a0, void *a1) {
    f32 v = 0.0f;
    u8 *o = func_0053EDD8(a0, 1, 1);
    if (o != 0) {
        o[84] = 0;
        func_00532398(o, &v, 4);
        func_00532398(o, a1, 8);
    }
    return v;
}
