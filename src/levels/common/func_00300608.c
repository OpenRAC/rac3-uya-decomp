#include "common.h"
extern s32 D_001A71A4[];
extern void func_00441C78(u8 *a0, s32 a1, s32 a2, s32 a3);
void func_00300608(u8 *a0) {
    if (D_001A71A4[0] == 8 && a0[67] != 6) {
        func_00441C78(a0, 6, 0, 10);
    }
}
