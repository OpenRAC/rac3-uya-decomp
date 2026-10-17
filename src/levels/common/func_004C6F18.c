#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern void func_004493C0(s32, s32, u128_t *, u128_t *, u128_t *, u128_t *);
extern s32 D_001DB02C;
extern s32 D_001A71A0[];

void func_004C6F18(u128_t *a, u128_t *b, u128_t *c, u128_t *d) {
    if (D_001DB02C) {
        func_004493C0(D_001A71A0[0], D_001DB02C, b, d, a, c);
    } else {
        *a = *b;
        *c = *d;
    }
}
