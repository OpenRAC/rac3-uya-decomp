#include "common.h"

/* localdecomp:start func_00448FB8 */
extern void func_0040C0F0(s32 a, s32 b, f32 x);

extern void func_0040C0F0(s32 a, s32 b, f32 x);
void func_00448FB8(void *a, f32 f) {
    f32 r;
    ((void (*)(void *, f32))func_0040C0F0)(a, f);
    r = 1.0f - f * f;
    __asm__("nop\n\tnop\n\tsqrt.s %0, %1" : "=f"(r) : "f"(r));
    *(f32*)((u8*)a + 0xC) = r;
}
/* localdecomp:end func_00448FB8 */
