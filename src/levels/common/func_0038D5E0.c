#include "common.h"

/* localdecomp:start func_0038D5E0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q[5];
} S_2BEE10;

extern S_2BEE10 D_002BEE10;
extern void func_00300650(S_2BEE10 *, u8 *, s32, s32);

void func_0038D5E0(u8 *a0) {
    S_2BEE10 m = D_002BEE10;

    func_00300650(&m, a0 + 16, 0, 0);
}
/* localdecomp:end func_0038D5E0 */
