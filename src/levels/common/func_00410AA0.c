#include "common.h"

/* localdecomp:start func_00410AA0 */
extern f32 func_0040BF68(void *v);
extern f32 func_0040C490(f32 a, f32 b);

void func_00410AA0(u8 *a0)
{
    if (!(*(u16 *)(a0 + 224) & 2)) {
        *(u16 *)(a0 + 224) |= 2;
        *(f32 *)(a0 + 96) = -func_0040C490(func_0040BF68(a0 + 240), *(f32 *)(a0 + 248));
        *(f32 *)(a0 + 64) = func_0040C490(*(f32 *)(a0 + 240), *(f32 *)(a0 + 244));
    }
}
/* localdecomp:end func_00410AA0 */
