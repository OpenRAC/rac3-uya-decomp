#include "common.h"

/* localdecomp:start func_003E73D0 */
extern u8 D_001E2AC0[];
extern void func_003E7168(u8 *a0, f32 f12);
void func_003E73D0(s32 a0, f32 a, f32 b) {
    u8 *e = D_001E2AC0 + a0 * 1120; u8 *o = *(u8 **)(e + 80);
    if (*(s16 *)(o + 134) == 0 && a != 0.0f) {
        *(f32 *)(*(u8 **)(o + 112) + 500) = a;
        func_003E7168(o, b);
    }
}
/* localdecomp:end func_003E73D0 */
