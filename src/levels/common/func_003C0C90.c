#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u128_t D_001E1CD0;
extern u128_t D_001E1CC0;
extern void func_003DFB58(u8 *, u8 *, f32);
extern void func_003DF988(u8 *, u8 *, u8 *);

void func_003C0C90(u8 *m) {
    u8 *p;

    *(u128_t *)m = D_001E1CD0;
    func_003DFB58(m, m, 1.0f);
    p = m + 32;
    *(u128_t *)p = D_001E1CC0;
    func_003DFB58(p, p, 1.0f);
    func_003DF988(m + 16, m, p);
}
