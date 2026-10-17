#include "common.h"

extern s32 func_0040BAC0(void *);
extern s32 func_0040D020(s32, s32, f32);

void func_003B9A10(u8 *arg0)
{
    u8 *v = *(u8 **)(arg0 + 104);

    if (*(s16 *)(arg0 + 170) == 2480) {
        if (func_0040BAC0(v + 132)) {
            *(s16 *)(v + 132) = 50;
            *(s32 *)(v + 156) = *(s32 *)(v + 156) == 0;
        }
        *(s32 *)(arg0 + 120) = func_0040D020(*(s32 *)(arg0 + 120),
                                             *(s32 *)(v + 156) ? 0x50787878 : 0x50141414, 0.15f);
    }
}
