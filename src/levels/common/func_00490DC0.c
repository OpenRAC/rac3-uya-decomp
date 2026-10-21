#include "common.h"

/* localdecomp:start func_00490DC0 */
extern s32 func_00514A38(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_005148E8(s32, s32, s32, f32, f32, f32, f32);
extern void func_00512AB0(s32, s32, s32);
extern void func_00512BA0(s32, s32, s32);
extern s32 func_004181A0(s32);
extern void func_00514120(u8 *, s32, s32, s32);

void func_00490DC0(u8 *a0, f32 *r) {
    f32 x;
    f32 one;

    one = 1.0f;
    x = r[0] + (r[2] - r[3]) * 0.5f + 0.0078125f;
    func_00514A38(0x1A0015, 0x706EC8FF, 0xED26, x, r[1], r[3] - 0.0234375f, r[3] - 0.012019231f);
    func_005148E8(0x1A0016, 0, 0x8066CCFF, x - r[3] * 0.5f, r[1], one, one);
    func_00512AB0(0x1A0016, 64, 1);
    func_00512BA0(0x1A0016, 2, 3);
    func_005148E8(0x1A0017, func_004181A0(3239), 0x8066CCFF, r[0] - r[2] * 0.5f, r[1], one, one);
    func_00512AB0(0x1A0017, 64, 1);
    func_00512BA0(0x1A0017, 1, 3);
    func_00514120(a0, 0x1A0015, 0x1A0016, 0x1A0017);
}
/* localdecomp:end func_00490DC0 */
