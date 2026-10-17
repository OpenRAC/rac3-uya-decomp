#include "common.h"

extern s32 D_0024D648[];

s32 func_00556230(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_0024D648[i] == 0) {
            return 0;
        }
    }
    return 1;
}
