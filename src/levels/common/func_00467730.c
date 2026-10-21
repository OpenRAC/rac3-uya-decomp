#include "common.h"

/* localdecomp:start func_00467730 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *D_002211D4[];
extern u8 *func_0045E438(s32);
extern s32 func_00440848(s32);

u8 *func_00467730(u128_t *a, u128_t *b, f32 size) {
    u8 *r;

    r = func_0045E438(47);
    if (r != 0) {
        *(u128_t *)(r + 16) = *a;
        *(u32 *)(r + 4) = ((func_00440848(8) + 40) << 24) | 0x808080;
        r[9] = 34;
        r[3] = 72;
        r[1] = 0;
        r[2] = *D_002211D4[0];
        *(f32 *)(r + 12) = size;
        *(u128_t *)(r + 32) = *b;
        r[8] = func_00440848(256);
    }
    return r;
}
/* localdecomp:end func_00467730 */
