#include "common.h"

/* localdecomp:start func_004103B0 */
extern void func_0040D940();

extern void func_0040DBE0(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
extern void func_0040D940();
s32 func_004103B0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    ((void (*)(float, float, float, float, float, float, s32, s32, s32, s32, s32, unsigned long))func_0040DBE0)((float)a0, (float)a1, 1.0f, 1.0f, 0.0f, 0.0f, a2, a3, a4, 1, 0, 0x80000000UL);
    return a0 - (((s32 (*)(s32, s32, float))func_0040D940)(a3, a4, 1.0f) >> 1);
}
/* localdecomp:end func_004103B0 */
