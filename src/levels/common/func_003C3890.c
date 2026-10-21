#include "common.h"

/* localdecomp:start func_003C3890 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_00439610(u8 *a0);

void func_003C3890(void *a0, u8 *a1) {
    s32 i;
    u8 **pp = (u8 **)(a1 + 64);
    for (i = 4; i >= 0; i--) {
        u8 *m = *pp++;
        if (m != 0) {
            u8 *v = *(u8 **)(m + 104);
            func_00439610(m);
            *(u128_t *)(v + 112) = *(u128_t *)(m + 16);
            *(u128_t *)(v + 128) = *(u128_t *)(m + 240);
        }
    }
}
/* localdecomp:end func_003C3890 */
