#include "common.h"
extern u8 *D_001DFE1C;
u8 *func_003595C8(u8 *a0, u8 *a1) {
    u8 *p = *(u8 **)(a0 + 104);
    if ((*(s32 *)(p + 36) != -1 && a1 == D_001DFE1C + (*(s32 *)(p + 36) << 8)) ||
        (*(s32 *)(p + 40) != -1 && a1 == D_001DFE1C + (*(s32 *)(p + 40) << 8))) {
        return a1;
    }
    return 0;
}
