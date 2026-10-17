#include "common.h"
extern u8 D_001E1CD0[];
extern s32 func_00405420(s32);
extern void func_0044A4C8(u8 *, s32, s32, s32, s32);
void func_003ACED8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 n = *(s32 *)(p + 80);
    p = p + 496 + *(s32 *)(p + 44) * 32;
    if (p[26] < n) {
        n = p[26];
    }
    func_0044A4C8(D_001E1CD0, func_00405420(4269), n, p[26], -1);
}
