#include "common.h"
extern u8 D_001A4BE0[];
s32 func_003286E8(s32 a0) {
    u8 *p = D_001A4BE0;
    if (*(s32 *)(p + 9676) == 3 || *(s32 *)(p + 9668) == 27) {
        if (*(s32 *)(p + 1336) == a0) {
            return 1;
        }
    } else if (*(s16 *)(p + 878) == 0) {
        if (*(s32 *)(p + 860) == a0) {
            return 1;
        }
    }
    return 0;
}
