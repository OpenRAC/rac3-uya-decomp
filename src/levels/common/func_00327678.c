#include "common.h"

extern u8 *func_00445F18(void);
extern u8 *func_003252E8(void);
extern s32 func_003B1C78(s32, s32);

s32 func_00327678(void) {
    u8 *p = func_00445F18();

    if (p == 0) return 0;
    if (*(s32 *)(*(u8 **)(func_003252E8() + 104) + 48) == 0) return 0;
    return func_003B1C78(*(s32 *)(p + 8), 1);
}
