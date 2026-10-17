#include "common.h"
extern s32 D_001A5E58[];
extern s32 func_0066AF80(u8 *, u8, u8);
extern void func_0061BB00(u8 *);
void func_0066B0A0(u8 *a0, u8 a1, u8 a2) {
    if (func_0066AF80(a0, a1, a2) != 0) {
        a0[80] = a1;
        if (*(s32 *)(a0 + 52) == D_001A5E58[0]) {
            func_0061BB00(a0);
        }
        *(s32 *)(a0 + 52) = -1;
        *(s32 *)(a0 + 4) = -1;
    }
}
