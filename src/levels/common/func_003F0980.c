#include "common.h"

/* localdecomp:start func_003F0980 */
extern void func_003F0FA0(void *, s32, s32, f32, f32, f32, f32);

void func_003F0980(void *a0, u8 *a1) {
    a1[29] = 0;
    if (*(f32 *)(a1 + 16) >= 0.0f) {
        func_003F0FA0(a0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
    }
}
/* localdecomp:end func_003F0980 */
