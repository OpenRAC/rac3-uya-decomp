#include "common.h"
extern u8 D_001A4BE0[];
extern s32 D_001D6694;
extern s32 D_001DF9C0;
extern f32 func_0041C888(u8 *a0, u8 *a1);
s32 func_0046C8D0(u8 *a0, s32 a1, f32 r) {
    u8 *g = D_001A4BE0;
    if (*(s32 *)(g + 9668) == 28) {
        return 0;
    }
    if (*(s32 *)(g + 9668) == 49) {
        return 0;
    }
    if (*(s32 *)(g + 10320) == 0) {
        return 0;
    }
    if (*(s32 *)(g + 864) == 0) {
        return 0;
    }
    if (*(s16 *)(g + 878) != 0) {
        return 0;
    }
    if (*(s32 *)(g + 9676) == 3) {
        return 0;
    }
    if (D_001D6694 != 0) {
        return 0;
    }
    if (func_0041C888(a0 + 16, g + 128) > r * 2.0f) {
        return 0;
    }
    return D_001DF9C0 >= a1;
}
