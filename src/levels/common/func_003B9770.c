#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern void func_0041C590(u8 *, u8 *, s32);
extern void func_00451098(u8 *, s32, s32, s32);

void func_003B9770(u8 *m) {
    u8 *o;

    if (*(u16 *)(m + 52) & 0x80) {
        return;
    }
    o = *(u8 **)(m + 184);
    *(u128_t *)(m + 16) = *(u128_t *)(o + 16);
    *(u128_t *)(m + 240) = *(u128_t *)(o + 240);
    func_0041C590(m + 192, o + 192, 48);
    if (*(s32 *)(*(u8 **)(*(u8 **)(m + 184) + 104) + 24) != 0) {
        if (m[67] != 1) {
            func_00451098(m, 1, 0, 10);
        }
    } else {
        if (m[67] != 0) {
            func_00451098(m, 0, 0, 10);
        }
    }
}
