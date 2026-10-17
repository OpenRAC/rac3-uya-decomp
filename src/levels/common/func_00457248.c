#include "common.h"

extern s32 D_001D7DB8;

void func_00457248(void) {
    s32 v = D_001D7DB8 - 1;
    D_001D7DB8 = v;
    if (v < 0) {
        D_001D7DB8 = 0;
    }
}
