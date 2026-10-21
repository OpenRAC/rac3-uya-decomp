#include "common.h"

/* localdecomp:start func_00461E08 */
typedef int s128 __attribute__((mode(TI)));
extern u8 *D_0022114C[];
extern u8 *func_0045E438(s32);
extern f32 func_00440918(f32, f32);
extern s32 func_00440848(s32);
extern f32 func_004408C0(f32, f32);
u8 *func_00461E08(u8 *q, s32 speed, s32 color, f32 range, f32 lo, f32 hi, f32 size, f32 scale) {
    u8 *p;
    p = func_0045E438(13);
    if (p) {
        *(s128 *)(p + 16) = *(s128 *)q;
        p[9] = 68;
        *(f32 *)(p + 12) = scale;
        p[3] = 72;
        q = p + 32;
        *(s32 *)(p + 4) = color;
        p[1] = 0;
        p[8] = 0;
        p[2] = *D_0022114C[0];
        *(f32 *)(p + 16) += func_00440918(0.0f, range);
        *(f32 *)(p + 20) += func_00440918(0.0f, range);
        *(f32 *)(p + 24) += func_00440918(0.0f, range);
        *(s16 *)(p + 10) = 10;
        *(s32 *)(q + 4) = 0;
        if (func_00440848(2)) {
            *(s32 *)(q + 8) = speed;
        } else {
            *(s32 *)(q + 8) = -speed;
        }
        *(s32 *)(q + 20) = color & 0xFFFFFF;
        *(f32 *)(q + 12) = func_004408C0(lo, hi);
        *(f32 *)(q + 16) = size;
    }
    return p;
}
/* localdecomp:end func_00461E08 */
