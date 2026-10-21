#include "common.h"

/* localdecomp:start func_003E2378 */
typedef int q128 __attribute__((mode(TI)));
extern s32 func_003F51A8(q128 *, f32);

s32 func_003E2378(q128 *a0) {
    q128 v = *a0;
    return func_003F51A8(&v, 0.0f) != 0;
}
/* localdecomp:end func_003E2378 */
