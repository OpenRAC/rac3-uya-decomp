#include "common.h"
extern void func_0040A478(u8 *, s32);
void func_003D33F8(u8 *a0) {
    s32 i;
    u8 *p = *(u8 **)(a0 + 104);
    for (i = 0; i < *(s32 *)(p + 676); i++) {
        if (*(s32 *)(p + i * 224 + 192) > 0) {
            func_0040A478(p + i * 224, *(s32 *)(p + 672));
        }
    }
}
