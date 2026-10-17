#include "common.h"
extern s32 D_001DD640;
s32 *func_00355070(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 2) {
        *a2 = 12;
        return &D_001DD640;
    }
    return 0;
}
