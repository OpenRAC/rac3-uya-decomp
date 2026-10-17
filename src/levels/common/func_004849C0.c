#include "common.h"

u8 *func_004849C0(u8 *a0, s32 a1, s32 a2) {
    if (a2 < 2 && a1 < 4) {
        return a0 + a1 + a2 * 4;
    }
    return 0;
}
