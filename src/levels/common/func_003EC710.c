#include "common.h"
extern u8 *D_001DF884[];
void func_003EC710(s32 a0) {
    u8 *p = *(u8 **)(D_001DF884[0] + a0 * 32 + 28);
    *(s16 *)(p + 38) = 0;
    *(s32 *)(p + 32) = 0;
}
