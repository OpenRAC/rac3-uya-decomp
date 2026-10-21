#include "common.h"

/* localdecomp:start func_004CB6F8 */
f32 func_004CB6F8(char *a0) {
    f32 old = *(f32 *)(a0 + 24);
    *(f32 *)(a0 + 24) = 1.0f;
    *(s8 *)(a0 + 40) = 1;
    return old;
}
/* localdecomp:end func_004CB6F8 */
