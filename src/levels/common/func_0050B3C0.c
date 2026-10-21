#include "common.h"

/* localdecomp:start func_0050B3C0 */
extern u8 D_001A4BE0[];
extern s32 func_0050B678(s32, s32 *, s32 *);
extern void func_00441C78(u8 *, s32, s32, s32);

void func_0050B3C0(void) {
    u8 *p;
    u8 *a;
    u8 *b;
    s32 x[2];

    p = D_001A4BE0;
    a = *(u8 **)(p + 4848);
    b = *(u8 **)(p + 4852);
    if (a != 0 && b != 0 && a[67] == 1) {
        if (func_0050B678(0, &x[0], &x[1]) != 0) {
            func_00441C78(a, x[0], 0, 7);
            func_00441C78(b, x[1], 0, 7);
        }
    }
}
/* localdecomp:end func_0050B3C0 */
