#include "common.h"

/* localdecomp:start func_0051AB80 */
extern f32 D_0024BC4C[];
extern s32 func_0057CB70(u8 *);
extern s32 func_005B2498(s32);
extern void func_005B2F10(u8 *, s32, s32);
extern void func_005A8630(void *);

void func_0051AB80(u8 *o) {
    switch (o[0x20]) {
    case 0:
        if (func_0057CB70(o) == 0) {
            if (!(D_0024BC4C[0] > 0.95f)) {
                return;
            }
            if (func_005B2498(10) != 0) {
                return;
            }
        }
        func_005B2F10(o, 1, -1);
        *(u16 *)(o + 0x34) |= 0x2800;
        break;
    case 1:
        func_0057CB70(o);
        if (o[0x23] < 2) {
            func_005A8630(o);
            return;
        }
        o[0x23] -= 2;
        break;
    }
}
/* localdecomp:end func_0051AB80 */
