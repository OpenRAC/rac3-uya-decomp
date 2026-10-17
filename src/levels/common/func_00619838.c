#include "common.h"
extern s32 *D_0024CF20[];
s32 *func_00619838(s32 a0) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 *q = D_0024CF20[i];
        if (q && *q == a0) {
            return q;
        }
    }
    return 0;
}
