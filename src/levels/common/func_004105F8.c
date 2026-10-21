#include "common.h"

/* localdecomp:start func_004105F8 */
extern void func_0040EE10(s32, long, s32, s32, unsigned long, s32, f32, f32);

extern void func_0040EE10(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_004105F8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0040EE10(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_004105F8 */
