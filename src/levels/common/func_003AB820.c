#include "common.h"
void func_003AB820(void *a0, void *a1, f32 *a2, f32 *a3) {
    *(s32 *)a3 = 0;
    if (a3[1] > a2[3]) {
        a3[1] = a2[3];
    } else if (a3[1] < a2[2]) {
        a3[1] = a2[2];
    }
    if (a3[2] > a2[5]) {
        a3[2] = a2[5];
    } else if (a3[2] < a2[4]) {
        a3[2] = a2[4];
    }
}
