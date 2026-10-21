#include "common.h"

/* localdecomp:start func_00477330 */
extern s32 func_00513548(s32, f32, f32);

extern u8 D_00142CC0[];
extern u8 D_001426E0[];
extern s32 func_00513548(s32, f32, f32);
void func_00477330(void) {
    if (D_00142CC0[0]) {
        u8 *s = D_001426E0;
        f32 r = 0.0f;
        if (s[0xD4]) r = (f32)s[0xD3] / (f32)s[0xD4];
        func_00513548(0x90008, r * 0.0430830009f, 0.0504160002f);
    }
}
/* localdecomp:end func_00477330 */
