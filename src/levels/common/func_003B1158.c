#include "common.h"

extern u8 *D_001E009C;
extern void func_003B1B70(u8 *a0);
extern u8 *func_003B1C38(u8 *a0);

void func_003B1158(u8 *moby) {
    s32 idx = *(s32 *)(*(u8 **)(moby + 104) + 24);
    u8 *p;

    if (idx != -1) {
        p = D_001E009C + idx * 256;
        while (p != 0 && *(s16 *)(p + 170) != 6628) {
            func_003B1B70(p);
            p = func_003B1C38(p);
        }
    }
}
