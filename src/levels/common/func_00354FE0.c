#include "common.h"
extern s32 D_001DFC58;
extern s32 D_0021DB60[];
extern void func_0043B590(s32, s32);
void func_00354FE0(u8 *a0) {
    if (a0[188] == 0) {
        u8 i = a0[33];
        if (i < D_001DFC58 && D_0021DB60[i] != 0) {
            func_0043B590(i, 0);
        }
    }
}
