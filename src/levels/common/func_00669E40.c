#include "common.h"

typedef struct {
    int w[18];
} S_00669E40;

extern S_00669E40 D_00343418[];

void func_00669E40(S_00669E40 *a0) {
    a0->w[17] = -1;
    a0->w[7] = 0;
    a0->w[8] = 0;
    a0->w[6] = a0 - D_00343418;
}
