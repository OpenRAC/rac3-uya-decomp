#include "common.h"
extern s32 D_00271B70[];
extern s32 D_001DC690;
void func_0030D3E0(void) {
    s32 i;
    for (i = 4; i >= 0; i--) {
        D_00271B70[i * 4] = 0;
    }
    D_001DC690 = 0;
}
