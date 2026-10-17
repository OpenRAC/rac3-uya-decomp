#include "common.h"
extern u8 *D_0024C068;
extern f32 func_0058F478(u8 *, u8 *);
u8 *func_005573D0(u8 *a0) {
    u8 *best = 0;
    f32 min = 9999.0f;
    u8 *p;
    f32 d;
    for (p = D_0024C068; p != 0; p = *(u8 **)(p + 40)) {
        if (*(s16 *)(p + 170) == 5743) {
            d = func_0058F478(a0 + 16, p + 16);
            if (d < min) {
                min = d;
                best = p;
            }
        }
    }
    return best;
}
