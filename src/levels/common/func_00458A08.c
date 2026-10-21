#include "common.h"

/* localdecomp:start func_00458A08 */
extern u8 *func_00458650(u8 *a0);
extern void func_00445758(u8 *a0, u8 *a1, s32 a2, f32 f12, f32 f13, f32 f14, f32 f15);
s32 func_00458A08(u8 *a0, f32 f) {
    u8 *r = func_00458650(a0);
    if (r == 0) {
        return 0;
    }
    func_00445758(a0 + 248, r + 180, 0, f, *(f32 *)(r + 20), *(f32 *)(r + 24), *(f32 *)(r + 28));
    return 1;
}
/* localdecomp:end func_00458A08 */
