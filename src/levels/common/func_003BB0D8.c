#include "common.h"
extern u8 D_001E2A40[];
extern f32 D_001DE9F8;
extern f32 D_001DE9FC;
extern f32 D_001DEA00;
extern f32 func_0040BFB0(u8 *, u8 *);
extern s32 func_0040D0C0(u8 *, f32);
s32 func_003BB0D8(s32 a0, u8 *a1) {
    f32 r = func_0040BFB0(a1, D_001E2A40);
    f32 c = D_001DEA00;
    *(f32 *)(a1 + 12) = D_001DE9F8 + r * D_001DE9FC;
    return func_0040D0C0(a1, c) == 1;
}
