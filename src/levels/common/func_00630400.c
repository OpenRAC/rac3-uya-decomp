#include "common.h"

s32 func_00630400(u8 *a, f32 t) {
    f32 v = *(f32 *)(a + 1576);
    if (t < v) {
        if (v - t <= *(f32 *)(a + 1580)) {
            return 1;
        }
    }
    return 0;
}
