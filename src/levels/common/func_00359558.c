#include "common.h"
extern s32 D_001DF9C0;
void func_00359558(char *a0, char *a1) {
    if (*(s32 *)(a0 + 32) == 1) {
        s32 t = D_001DF9C0;
        *(s32 *)(a0 + 32) = 2;
        *(s32 *)(a0 + 36) = t;
        *(s32 *)(a1 + 0) = 0;
        *(s32 *)(a1 + 8) = 0;
        *(s32 *)(a1 + 12) = 0;
    }
}
