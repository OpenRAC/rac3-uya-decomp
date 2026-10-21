#include "common.h"

/* localdecomp:start func_003085E0 */
extern s32 func_00440878(s32, s32);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440978(void);
extern void func_004082B0(s32, s32, s32, s32, f32, f32, f32);

void func_003085E0(s32 unused, s32 target, u32 color, s32 n, f32 scale) {
    f32 size;
    color |= func_00440878(n >> 1, n) << 24;
    size = func_004408C0(scale * 0.75f, scale);
    size = size + size;
    func_004082B0(target, 44, color, 1, size, 0.08f, func_00440978());
}
/* localdecomp:end func_003085E0 */
