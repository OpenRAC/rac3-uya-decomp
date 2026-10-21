#include "common.h"

/* localdecomp:start func_003F6DA0 */
typedef int u128_3F6DA0 __attribute__((mode(TI)));
extern void func_0040C0F0(void *a0, u8 *a1, f32 f12);
extern f32 func_0040BEF8(void *a0, u8 *a1);
extern void func_00448FB8(u8 *a0, void *a1, f32 f12);
void func_003F6DA0(s32 a0, u8 *a1, u8 *a2) {
    u128_3F6DA0 tmp;
    func_0040C0F0(&tmp, a2, 1.0f);
    func_00448FB8(a1, &tmp, func_0040BEF8(&tmp, a1));
}
/* localdecomp:end func_003F6DA0 */
