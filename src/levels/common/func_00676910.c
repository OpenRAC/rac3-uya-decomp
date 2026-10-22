#include "common.h"

extern f32 D_001DAF54;
extern f32 D_001DAF58;
extern f32 D_001DAF5C;
extern f32 D_001DAF60;
extern s32 D_00240480;
extern s32 D_00240484;
extern u8 D_00353380[];
extern s32 func_00120884(u8 *);
extern void func_00593620(s32, s32, s32, s32, unsigned long, u8 *, s32);

void func_00676910(void) {
    f32 w = D_00240480;
    f32 h = D_00240484;
    s32 x0 = D_001DAF54 * w;
    s32 x1 = D_001DAF58 * h;
    s32 x2 = D_001DAF5C * w;
    s32 x3 = D_001DAF60 * h;
    func_00593620(x0, x1, x2, x3, 0x8066CCFF, D_00353380, func_00120884(D_00353380));
}
