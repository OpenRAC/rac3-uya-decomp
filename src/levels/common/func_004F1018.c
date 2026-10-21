#include "common.h"

/* localdecomp:start func_004F1018 */
extern u8 D_001A4C20[];
extern void func_0040C2F8(f32 *out, void *a, void *b);
extern f32 func_0040C490(f32 a, f32 b);
extern void func_004454A8(void *p, f32 a, f32 b);

void func_004F1018(void *a0, void *a1)
{
    f32 v[4];
    func_0040C2F8(v, a0, D_001A4C20);
    func_004454A8(a1, func_0040C490(v[0], v[1]), 0.0f);
}
/* localdecomp:end func_004F1018 */
