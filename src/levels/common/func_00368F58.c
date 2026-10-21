#include "common.h"

/* localdecomp:start func_00368F58 */
extern s32 func_00440878(s32, s32);
extern void func_0040BE90(void *, void *, f32);
extern u8 *func_003DE3A8(void *, void *, s32);
void func_00368F58(u8 *a0, void *a1, void *a2) {
    u8 *s = *(u8 **)(a0 + 104);
    u8 *r;
    *(s32 *)(s + 28) = func_00440878(15, 45);
    func_0040BE90(a2, a2, 0.2f);
    r = func_003DE3A8(a1, a2, 0);
    if (r != 0) {
        *(s32 *)(r + 184) = *(s32 *)(a0 + 184);
    }
}
/* localdecomp:end func_00368F58 */
