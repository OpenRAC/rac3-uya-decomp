#include "common.h"

void func_00644110(u8 *a, s32 v) {
    s32 i;
    s16 *p = (s16 *)(a + 7600);
    for (i = 0; i < 2; i++) {
        if (p[i] == -1) {
            p[i] = v;
            return;
        }
    }
    *(s16 *)(a + 7602) = v;
}
