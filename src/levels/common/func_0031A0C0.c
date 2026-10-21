#include "common.h"

/* localdecomp:start func_0031A0C0 */
typedef int u128_31A0C0 __attribute__((mode(TI)));
void func_0031A0C0(u128_31A0C0 *a0, s32 *a1, u128_31A0C0 *a2, s32 *a3, s32 *cnt) {
    if (*cnt < 70) {
        a2[*cnt] = *a0;
        a3[*cnt] = *a1;
        (*cnt)++;
    }
}
/* localdecomp:end func_0031A0C0 */
