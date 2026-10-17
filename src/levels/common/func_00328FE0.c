#include "common.h"
extern s32 func_00328AA8(u8 *);
void func_00328FE0(void *a0, u8 *a1) {
    s32 n = 0;
    u8 *p = *(u8 **)(a1 + 4);
    while (p != 0 && !func_00328AA8(p)) {
        n++;
        p = *(u8 **)(*(u8 **)(p + 104) + 108);
    }
    *(u8 **)(a1 + 8) = p;
    *(s32 *)(a1 + 12) = n;
}
