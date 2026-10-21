#include "common.h"

/* localdecomp:start func_0045FD70 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *D_0022111C[];
extern u8 *func_0045E438(s32);

void func_0045FD70(f32 *pos, s32 color) {
    u8 *r;

    r = func_0045E438(1);
    if (r == 0) {
        return;
    }
    pos[2] += 0.2f;
    *(u128_t *)(r + 16) = *(u128_t *)pos;
    *(u32 *)(r + 4) = (color << 24) | 0x907070;
    r[9] = 66;
    r[3] = 68;
    r[1] = 0;
    r[2] = *D_0022111C[0];
    *(f32 *)(r + 12) = 63000.00390625f;
    r[8] = 160;
    *(s16 *)(r + 10) = 27;
    *(s32 *)(r + 32) = color;
}
/* localdecomp:end func_0045FD70 */
