#include "common.h"

/* localdecomp:start func_0030D680 */
extern void func_004C1FE8(s32, unsigned long);
extern void func_0030CC18(void *);
extern void func_0030CFE8(void *);
extern s32 func_00440878(s32, s32);
extern f32 func_00440978(void);
extern void func_0030D828(void *, s32, f32, s32, f32, s32, s32);

void func_0030D680(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    u8 *q;
    f32 s;

    if (p == 0) {
        return;
    }
    func_004C1FE8(71, 0x53001);
    func_0030CC18(a0);
    func_0030CFE8(a0);
    q = a0 + 16;
    s = *(f32 *)(p + 24);
    s *= 0.5f;
    func_0030D828(q, 0x103080, s, func_00440878(80, 96), func_00440978(), 49, 2);
    s = *(f32 *)(p + 24);
    s *= 0.3f;
    func_0030D828(q, 0xFFFFFF, s, func_00440878(80, 96), func_00440978(), 49, 2);
    s = *(f32 *)(p + 24);
    s *= 0.7f;
    func_0030D828(q, 0x803010, s, func_00440878(8, 22), func_00440978(), 11, 2);
    s = *(f32 *)(p + 24);
    s *= 0.45f;
    func_0030D828(q, 0x803010, s, func_00440878(32, 64), func_00440978(), 11, 2);
    func_004C1FE8(71, 0x5360B);
}
/* localdecomp:end func_0030D680 */
