#include "common.h"

extern s32 D_00249B74[];
extern s32 D_001DE2E0;

s32 func_0053EE28(s32 *a) {
    s32 r = 0;
    s32 v = D_00249B74[0];
    if (v != -1) {
        s32 x = a[1];
        if (x == v || (x == -1 && D_001DE2E0 == v)) {
            r = 1;
        }
    }
    return r;
}
