#include "common.h"
extern u8 D_001D7F40[8];
extern f32 D_001D7F48[2];
extern s32 D_001D7F58[2];
void func_005D8B38(s32 a0, s32 a1, f32 a2) {
    f32 *p;
    D_001D7F40[a1] = 1;
    p = &D_001D7F48[a1];
    *p = 1.0f - a2;
    if (*p > 1.0f) {
        *p = 1.0f;
    }
    if (*p < 0.0f) {
        *p = 0.0f;
    }
    D_001D7F58[a1] = a0;
}
