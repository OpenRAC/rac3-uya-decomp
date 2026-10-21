#include "common.h"

/* localdecomp:start func_0053B2D0 */
extern s32 D_001D5A08;
extern u8 *D_0024CF20[8];
extern void func_005FBBC0(u8 *, u8 *, s32, s32, f32);

void func_0053B2D0(u8 *a) {
    u8 *m;
    u8 *pl;
    u16 k;

    if (a == 0) {
        return;
    }
    if (a[0x20] == 0xFE) {
        return;
    }
    if (a[0x20] == 0xFD) {
        return;
    }
    m = *(u8 **)(a + 0x68);
    if (m == 0) {
        return;
    }
    k = *(u16 *)(m + 0x7C);
    pl = 0;
    if (k < 8) {
        pl = D_0024CF20[(s16)k];
    }
    if (pl == 0) {
        return;
    }
    if (pl[0x24C9] != D_001D5A08) {
        return;
    }
    if (*(s16 *)(m + 0x36) == 0) {
        func_005FBBC0(m + 0x10, m + 0x20, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_0053B2D0 */
