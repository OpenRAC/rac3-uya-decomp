#include "common.h"
void func_003AD2C8(u8 *a0, float a, float b, float c) {
    float v = *(float *)(a0 + 180);
    *(float *)(a0 + 20) = b;
    *(float *)(a0 + 24) = c;
    *(float *)(a0 + 28) = a;
    if (v > a) {
        *(float *)(a0 + 180) = a;
    } else if (v < -a) {
        *(float *)(a0 + 180) = -a;
    }
}
