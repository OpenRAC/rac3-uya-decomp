#include "common.h"

f32 func_004E7B48(f32 a[][4], f32 b[][4]) {
    s32 i, j;
    f32 sum = 0.0f;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sum += __builtin_fabsf(a[i][j] - b[i][j]);
        }
    }
    return sum;
}
