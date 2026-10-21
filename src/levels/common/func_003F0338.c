#include "common.h"

/* localdecomp:start func_003F0338 */
extern u8 D_001E2500[];

void func_003F0338(s32 a0, u8 *a1) {
    s32 idx = 0;
    u8 *p;
    s32 i;

    if (a1) {
        s32 slot = a1[1367];
        if (slot == 255) return;
        idx = a1[1356] * 4 + slot;
    }
    p = D_001E2500 + idx * 128;
    for (i = 7; i >= 0; i--) {
        if (p[1]) {
            p[1] = 0;
            *(s16 *)(p + 6) = 0;
        }
        p += 16;
    }
}
/* localdecomp:end func_003F0338 */
