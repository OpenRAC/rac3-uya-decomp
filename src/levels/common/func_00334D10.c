#include "common.h"

/* localdecomp:start func_00334D10 */
extern s32 *D_0021F740[];
extern f32 func_0040BFE8(void *, void *);
extern void func_00458E48(void *, void *, s32, s32);

s32 func_00334D10(u8 *a0, u8 *a1, u8 *a2, s32 a3, s32 t0, u8 *t1) {
    s32 i = *(s32 *)(t1 + 108);
    if (i != -1) {
        s32 *s = D_0021F740[i];
        f32 d = func_0040BFE8(a2 + 16, s + 4);
        if (func_0040BFE8(a2 + 16, s + s[0] * 4) < d) {
            func_00458E48(a2, s, 0, 0);
        } else {
            func_00458E48(a2, s, s[0] - 1, 0);
        }
    }
    a0[188] = 0;
    a1[94] = 0;
    return 0;
}
/* localdecomp:end func_00334D10 */
