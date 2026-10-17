#include "common.h"

extern u8 D_001D5473[];
extern void func_00437C10(void);
extern void func_00437C98(s32, u8 *);

void func_0044F0E8(s32 a0, s32 a1, u8 *a2, f32 f) {
    if (D_001D5473[0] != 0) {
        if (a2[1] == 0) {
            func_00437C10();
        }
        *(f32 *)(a2 + 32) = f;
        *(f32 *)(a2 + 36) = f;
        *(f32 *)(a2 + 40) = f;
    } else if (a2[1] != 0) {
        func_00437C98(a0, a2);
    }
}
