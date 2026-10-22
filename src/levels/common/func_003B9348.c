#include "common.h"

/* localdecomp:start func_003B9348 */
typedef int Q_003B9348 __attribute__((mode(TI)));
extern f32 func_0041C8F0(void *, void *);
extern f32 func_00452500(void *, s32, s32, f32);
extern f32 func_00452680(void *);

void func_003B9348(u8 *o, u8 *c) {
    f32 d;
    f32 k;
    if (func_0041C8F0(o + 0x10, c + 0x90) < 0.001f) {
        return;
    }
    if (*(f32 *)(o + 0xF0) == 3.1415927f) {
        d = (*(f32 *)(o + 0x18) - func_00452680(o + 0x10)) - *(f32 *)(c + 8);
    } else {
        d = (func_00452500(o + 0x10, 0, 0, 0.5f) - *(f32 *)(o + 0x18)) - *(f32 *)(c + 8);
    }
    if (d > 3.0f) {
        d = 3.0f;
    } else if (d < -3.0f) {
        d = -3.0f;
    }
    k = d * (1024.0f / *(f32 *)(o + 0x2C));
    *(f32 *)(c + 0xC) = k;
    *(f32 *)(c + 0x88) = k;
    *(Q_003B9348 *)(c + 0x90) = *(Q_003B9348 *)(o + 0x10);
}
/* localdecomp:end func_003B9348 */
