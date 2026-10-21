#include "common.h"

/* localdecomp:start func_00366290 */
typedef int u128_t __attribute__((mode(TI)));

extern u128_t D_001E1CB0;
extern f32 D_001E1CA8[];
extern s32 func_00366240(u128_t *, f32 *);

s32 func_00366290(u128_t *a, f32 *b) {
    if (func_00366240(a, b) == 0) return 0;
    *a = D_001E1CB0;
    *b = D_001E1CA8[0];
    return 1;
}
/* localdecomp:end func_00366290 */
