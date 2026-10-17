#include "common.h"
typedef int u128_3A3890 __attribute__((mode(TI)));
extern f32 func_003E4018(void *, void *);
void func_003A3890(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    f32 d = func_003E4018(s1 + 384, s1 + 400);
    if (d < func_003E4018(s1 + 384, s1 + 416)) {
        *(u128_3A3890 *)(s1 + 384) = *(u128_3A3890 *)(s1 + 416);
    } else {
        *(u128_3A3890 *)(s1 + 384) = *(u128_3A3890 *)(s1 + 400);
    }
}
