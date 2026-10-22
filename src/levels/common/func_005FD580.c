#include "common.h"

/* localdecomp:start func_005FD580 */
extern f32 func_00590318(f32, f32);
extern f32 func_0058F8D0(f32);
extern s32 func_00590438(s32, s32, f32);

s32 func_005FD580(f32 *ang, s32 *cnt, s32 flag, f32 speed) {
    s32 c;
    s32 a;
    s32 r;

    (*cnt)++;
    if (*cnt > 20) {
        *cnt = 20;
    }
    *ang = func_00590318(*ang, speed * 0.017453292f * 0.016666668f);
    a = (*cnt * 5) << 24;
    r = func_00590438(a | 0xFF0F, a | 0xFFFFFF, func_0058F8D0(*ang) * 0.5f + 0.5f);
    if (flag != 0) {
        r = 0x600000FF;
    }
    return r;
}
/* localdecomp:end func_005FD580 */
