#include "common.h"
extern s32 D_001DF3C0;
extern void func_003457C8(s32 a0, f32 *a1, f32 *a2, f32 *a3, f32 *t0);
s32 func_003A4008(u8 *a0, f32 r) {
    f32 b[4];
    func_003457C8(*(s32 *)(*(u8 **)(a0 + 104) + 436), &b[0], &b[1], &b[2], &b[3]);
    if (b[1] + r < *(f32 *)(a0 + 16) || *(f32 *)(a0 + 16) < b[0] - r
        || b[3] + r < *(f32 *)(a0 + 24) || *(f32 *)(a0 + 24) < b[2] - r) {
        if (D_001DF3C0 >= 6) {
            return 1;
        }
    }
    return 0;
}
