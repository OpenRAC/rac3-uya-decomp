#include "common.h"
extern void func_0045E580(u8 *a0);
void func_0046A538(u8 *a0) {
    if (--*(s16 *)(a0 + 10) == 0) { *(s16 *)(a0 + 10) = 2; *(s32 *)(a0 + 4) += 0xFF000000; }
    if ((*(u32 *)(a0 + 4) & 0xFF000000) == 0) {
        func_0045E580(a0);
    }
}
