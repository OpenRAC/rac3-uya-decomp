#include "common.h"

/* localdecomp:start func_00460C20 */
extern s32 func_0040BA90(u8 *a0);
extern void func_0045E580(u8 *a0);
void func_00460C20(u8 *a0) {
    u8 *s1 = a0 + 32;
    s32 n;
    if (func_0040BA90(s1)) {
        func_0045E580(a0);
    } else {
        *(f32 *)(a0 + 12) += *(f32 *)(s1 + 4);
        n = *(s32 *)(a0 + 32);
        if (n < 6) {
            *(u32 *)(a0 + 4) = (*(u32 *)(a0 + 4) & 0xFFFFFF) | ((n * 127 / 6) << 24);
        }
    }
}
/* localdecomp:end func_00460C20 */
