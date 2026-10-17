#include "common.h"

extern s32 D_0024D58C[];

void func_0051DDD8(void) {
    s32 i;
    for (i = 15; i >= 0; i--) {
        D_0024D58C[i - 15] = 0;
    }
}
