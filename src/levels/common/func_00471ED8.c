#include "common.h"

/* localdecomp:start func_00471ED8 */
extern s32 func_0040BAC0(u8 *);
extern void func_0045E580(u8 *);
extern s32 func_0040D020(s32, s32, f32);
extern f32 D_001D7FC4;

void func_00471ED8(u8 *a0) {
    if (func_0040BAC0(a0 + 10) != 0 || *(f32 *)(a0 + 12) < D_001D7FC4 * 210000.0f) {
        func_0045E580(a0);
    } else {
        u8 *p = a0 + 32;
        *(s32 *)(a0 + 4) = func_0040D020(*(s32 *)(p + 8), *(s32 *)(p + 4),
                                         (f32)*(s16 *)(a0 + 10) * *(f32 *)(p + 12));
        *(f32 *)(a0 + 12) = *(f32 *)(a0 + 12) + *(f32 *)(a0 + 32);
    }
}
/* localdecomp:end func_00471ED8 */
