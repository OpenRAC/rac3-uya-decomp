#include "common.h"
s32 func_0062F1D8(u8 *a0, s32 a1, f32 *a2) {
    *a2 = 0.0f;
    switch (a1) {
    case 28:
    case 29:
    case 31:
        if (*(f32 *)(a0 + 1576) > 25.0f) {
            *a2 = -1.4835298f;
        }
        return 1;
    }
    return 0;
}
