#include "common.h"

extern s16 *D_0021CA20[];
extern void func_003C6BB8(s32, s32, s32);

void func_003C6F78(s32 a0, s32 a1, s32 a2, s32 a3) {
    s16 *p = D_0021CA20[a2];
    if (p != 0) {
        do {
            func_003C6BB8(*p & 0x7fff, a1, a3);
        } while (*p++ >= 0);
    }
}
