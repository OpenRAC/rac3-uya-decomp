#include "common.h"

typedef struct {
    u8 pad0[8128];
    f32 hist[224];
    s32 head;
    s32 count;
} S_0062F240;

f32 func_0062F240(S_0062F240 *a0, int a1)
{
    int n;
    if (a1 >= 32) {
        a1 = 31;
    }
    n = a0->count;
    if (n < a1) {
        a1 = n;
    }
    return a0->hist[(a0->head - a1 + 31) % 32];
}
