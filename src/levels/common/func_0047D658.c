#include "common.h"

extern s32 D_001D83C0_g;

extern s32 func_0042FE88(s32, void *);
extern void func_0047D320();
extern s32 D_001D83C0_g;
s32 func_0047D658(void) {
    s32 r = func_0042FE88(0, func_0047D320);
    D_001D83C0_g = 1;
    return r;
}
