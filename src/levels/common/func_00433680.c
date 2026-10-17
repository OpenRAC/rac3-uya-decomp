#include "common.h"
extern s32 func_004488E0(s32 a0, u8 *a1);
extern s32 func_00449620(s32 a0, u8 *a1);
s32 func_00433680(u8 *a0) {
    s32 r;
    if (*(s32 *)(a0 + 4) != 0) {
        if (a0[10] == 0) {
            r = func_004488E0(*(s16 *)(a0 + 8), a0);
        } else {
            r = func_00449620(*(s16 *)(a0 + 8), a0);
        }
        if (r != 0) {
            *(s32 *)(a0 + 4) = 0;
        }
    }
    return *(s32 *)(a0 + 4) == 0;
}
