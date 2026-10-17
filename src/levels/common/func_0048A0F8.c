#include "common.h"

extern s32 D_001D8CA8;
extern s32 D_001D8C64;
extern s32 D_001D8CB4;
extern s32 func_0047A2D8(s32);
extern s32 func_00434AA8(s32, s32 *, s32, s32);

void func_0048A0F8(void) {
    s32 v;
    D_001D8CA8 = 0;
    v = func_0047A2D8(0);
    D_001D8CB4 = v;
    if (func_00434AA8(v, &D_001D8CA8, 409, D_001D8C64) == 0) {
        D_001D8CA8 = 0;
    }
}
