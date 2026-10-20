#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern u8 *func_00435E70(s32, s32);

u8 *func_00303B18(f32 *pos, s32 b) {
    u8 *m = func_00435E70(1007, 128);

    if (m != 0) {
        m[48] = 255;
        *(u16 *)(m + 52) |= 0x41;
        if (pos[0] < 2.0f || 1021.0f < pos[0] || pos[1] < 2.0f || 1021.0f < pos[1] ||
            pos[2] < 2.0f || 1021.0f < pos[2]) {
            *(f32 *)(m + 28) = 0.0f;
            *(f32 *)(m + 16) = 10.0f;
            *(f32 *)(m + 20) = 10.0f;
            *(f32 *)(m + 24) = 10.0f;
        } else {
            *(s128 *)(m + 16) = *(s128 *)pos;
        }
        m[188] = b;
    }
    return m;
}
