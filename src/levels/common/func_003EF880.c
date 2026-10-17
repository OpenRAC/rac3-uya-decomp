#include "common.h"

extern float D_001DF808[];

void func_003EF880(void *unused, int *out) {
    int i, j, best;
    float min;

    for (j = 0; j < 4; j++) {
        min = 1000000.0f;
        best = -1;
        for (i = 0; i < 4; i++) {
            if (D_001DF808[i] < min) {
                min = D_001DF808[i];
                best = i;
            }
        }
        out[j] = best;
        D_001DF808[best] = 1000000.0f;
    }
}
