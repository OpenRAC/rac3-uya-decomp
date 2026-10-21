#include "common.h"

/* localdecomp:start func_004BFC98 */
extern s32 D_001E1000;
extern s32 D_001E0FFC;
extern u8 D_002F27D8[];

extern void func_00512AB0(s32 a0, s32 a1, s32 a2);
extern f32 func_00442070(f32 f12);
extern void func_004BD808(s32 a0, u8 *a1);

void func_004BFC98(s32 arg0) {
    f32 f;

    D_001E1000 = 1;
    func_00512AB0(0x48000C, 1, 0);
    f = (f32)D_001E0FFC / 15.0f;
    if (arg0 != 0) {
        f = 1.0f - f;
    }
    if (1.0f < f) {
        f = 1.0f;
    } else if (f < 0.0f) {
        f = 0.0f;
    }
    func_004BD808((s32)(func_00442070(f) * 128.0f), D_002F27D8);
}
/* localdecomp:end func_004BFC98 */
