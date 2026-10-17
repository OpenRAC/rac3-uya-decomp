#include "common.h"
extern s32 D_002C2940[][4];
void func_00554440(s32 a0, s32 a1) {
    s32 *p = D_002C2940[a1];
    s32 i;
    for (i = 0; i < 4; i++, p++) {
        if (*p == 0) {
            *p = a0;
            return;
        }
    }
}
