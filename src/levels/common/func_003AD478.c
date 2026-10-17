#include "common.h"

extern u8 *D_001DF61C;
extern s32 func_00422DC0(s32, s32, s32);

s32 func_003AD478(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 104);
    u8 *m;

    if (*(s32 *)(p + 996) != 0) {
        *(s32 *)(p + 996) = 0;
        return 1;
    }
    if (*(s16 *)(p + 324) != 1) {
        return 0;
    }
    if (*(s32 *)(p + 924) != -1) {
        m = D_001DF61C + (*(s32 *)(p + 924) << 8);
        if (m != 0 && m[32] != 254 && m[32] != 253) {
            return 0;
        }
    }
    if (*(s32 *)(p + 920) != -1 && func_00422DC0(*(s32 *)(p + 920), -1, 0) != 0) {
        return 0;
    }
    return 1;
}
