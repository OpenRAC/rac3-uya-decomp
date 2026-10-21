#include "common.h"

/* localdecomp:start func_0044EBF8 */
extern u8 D_001A4C60[];
extern u32 D_001D545C;
extern s32 D_002BBDE0[];
extern u8 D_001426BA[];
extern f32 func_0040BFB0(void *, void *);
extern void func_0044A0E8(void *, s32, s32, s32, s32, s32, f32);

void func_0044EBF8(u8 *a0, s32 a1, f32 f) {
    u8 *g = D_001A4C60;
    s32 k = 1;
    u32 lvl;
    s32 n;
    if (func_0040BFB0(a0 + 16, g) < 7.0f) {
        k = 3;
    }
    lvl = D_001D545C;
    if (lvl >= 60) {
        lvl = 59;
    }
    n = (D_002BBDE0[lvl] * a1 - 1) * ((D_001426BA[0] + 1) << g[10312]);
    func_0044A0E8(a0, n, n, k, -1, 0, f);
}
/* localdecomp:end func_0044EBF8 */
