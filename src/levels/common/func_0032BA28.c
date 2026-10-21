#include "common.h"

/* localdecomp:start func_0032BA28 */
extern void func_00437698(u8 *, s32, f32 *);
extern s32 func_003F9498(f32 *, s32, u8 *, f32);
extern s32 D_001EAA9C[];
void func_0032BA28(u8 *p) {
    f32 v[4];
    func_00437698(p, 0, v);
    if (func_003F9498(v, 2, p, 0.2f) && D_001EAA9C[0] > 0) {
        p[0x20] = 8;
    }
}
/* localdecomp:end func_0032BA28 */
