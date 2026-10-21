#include "common.h"

/* localdecomp:start func_0052C920 */
extern f32 D_001DF360;
extern u8 *D_002417C0[];
extern void func_005A98E8(u8 *, s32, s32 *);
extern u8 *func_00541A58(u8 *, s32, s32 *, s32, s32, s32, s32, f32);

void func_0052C920(u8 *o, s32 a, s32 b, s16 kind, s32 c, u32 id) {
    u8 *s = *(u8 **)(o + 0x68);
    s32 buf[4];
    u8 *r;
    if (kind == 10) {
        *(s32 *)(s + 0x1D8) = 0;
    } else {
        *(s32 *)(s + 0x1D8) = 1;
    }
    func_005A98E8(o, *(s32 *)(s + 0x1D8), buf);
    r = func_00541A58(o, a, buf, 0x10001, b, 1, (*(s32 *)(D_002417C0[0] + 0x180) != 2) ? c : 0, D_001DF360);
    if (r != 0 && id != 0xFFFFFFFF) {
        *(u32 *)(r + 0x90) = id;
    }
    *(s32 *)(s + 0x1D8) ^= 1;
}
/* localdecomp:end func_0052C920 */
