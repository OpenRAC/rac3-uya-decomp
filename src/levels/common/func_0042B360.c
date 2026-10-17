#include "common.h"

typedef struct {
    s32 a[5];
    s32 b[5];
} Slots_42B360;

extern Slots_42B360 D_001F4488;

s32 func_0042B360(s32 rev)
{
    s32 *a = D_001F4488.a;
    s32 *b = D_001F4488.b;
    s32 j;
    s32 k;

    for (j = 0; j < 5; j++) {
        k = rev ? 4 - j : j;
        if (a[k] != 0 && b[k] == -1) {
            return k;
        }
    }
    return -1;
}
