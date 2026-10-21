#include "common.h"

/* localdecomp:start func_003DC848 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_003DC7D8(u8 *, u128_t *);
extern void func_003DC8D0(u128_t *, u8 *, s32, s32, f32, f32, f32);
extern void func_004076F8(u128_t *, s32, s32);

void func_003DC848(u8 *m) {
    u128_t a;
    u128_t b;
    u8 *t;

    t = *(u8 **)(m + 104);
    if (t != 0) {
        func_003DC7D8(m, &a);
        b = *(u128_t *)(m + 16);
        func_003DC8D0(&b, t + 16, 0x1030FF, 4, 0.0f, 0.85f, 0.25f);
        func_004076F8(&a, 0x2040FF, 0);
    }
}
/* localdecomp:end func_003DC848 */
