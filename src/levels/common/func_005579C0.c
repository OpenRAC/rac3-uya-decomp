#include "common.h"

/* localdecomp:start func_005579C0 */
extern s32 func_005573A0(s32);

s32 func_005579C0(u8 *a, s32 unused, u8 *m) {
    s32 id = *(s16 *)(m + 0xAA);
    u8 *s = *(u8 **)(a + 0x68);
    s32 i;

    if (func_005573A0(id) == 0) {
        return 0;
    }
    if (id == 0x109D || id == 0x109F || id == 0x109E) {
        for (i = 0; i < *(s32 *)s; i++) {
            u8 *e = ((u8 **)(s + 0x10))[i];
            if (e == m) {
                return 0;
            }
            if (*(s16 *)(m + 0xAA) == 0x109E && *(s16 *)(e + 0xAA) == 0x109F
                && *(u8 **)(*(u8 **)(e + 0x68) + 0x270) == m) {
                return 0;
            }
        }
    }
    return 1;
}
/* localdecomp:end func_005579C0 */
