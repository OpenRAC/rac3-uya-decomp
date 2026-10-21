#include "common.h"

/* localdecomp:start func_00402BF0 */
extern f32 func_0040C3C8(f32);
extern void func_0040D020(s32, s32, f32);
extern u8 D_001439FD[];

extern s32 D_001D4D40_00385CE0;
extern s32 D_001E6E34_00385CE0[];
extern s32 D_001D55E8_00385CE0;
extern u8 D_001439FD[];
extern f32 func_0040C3C8(f32);
extern void func_0040D020(s32, s32, f32);
extern void func_0040D548(s32);
extern s32 func_004181A0(s32);
extern void func_0040DBE0_00385CE0(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
void func_00402BF0(void) {
    f32 f, y;
    s32 old, n;
    if (D_001D4D40_00385CE0 == 1) {
        n = D_001439FD[0] ? 0x30 : 0x5A;
        f = (f32)(D_001E6E34_00385CE0[0] % 100) / 50.0f - 1.0f;
        if (f < -1.0f) f = -1.0f;
        if (1.0f < f) f = 1.0f;
        y = n;
        f = func_0040C3C8(f * 3.1415927f);
        n = ((s32 (*)(s32, s32, f32))func_0040D020)(0x7FE0E0E0, 0x5F66CCFF, (f + 1.0f) * 0.5f);
        old = D_001D55E8_00385CE0;
        func_0040D548(0);
        func_0040DBE0_00385CE0(480.0f, y, 1.0f, n, func_004181A0(0x244), -1, 1.0f, 2, 1, 0x80000000, 1.0f, 1.0f);
        func_0040D548(old);
    }
}
/* localdecomp:end func_00402BF0 */
