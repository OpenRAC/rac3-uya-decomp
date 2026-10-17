#include "common.h"

typedef struct {
    s32 id;
    s32 pad[3];
} Ent_497BC8;

extern u8 D_001426E0[];
extern Ent_497BC8 D_002EBE3C[];

s32 func_00497BC8(s32 cur)
{
    s32 j;
    s32 k;

    for (j = 1; j < 15; j++) {
        k = cur - j;
        if (k < 0) {
            k += 15;
        }
        if (D_001426E0[D_002EBE3C[k].id] != 0) {
            return k;
        }
    }
    return cur;
}
