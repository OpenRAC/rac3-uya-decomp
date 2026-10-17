#include "common.h"
extern u8 *D_001E009C[];
extern void func_00438760(s32, u8 *);
extern void func_003B4A50(u8 *, u8 *, s32);
void func_003B49A0(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a0 + 104);
    if (*(s32 *)(s + 108) != -1) {
        if (a1 == D_001E009C[0] + (*(s32 *)(s + 108) << 8)) {
            *(s32 *)(s + 140) += 1;
            return;
        }
    }
    if (a1[33] != 255) {
        func_00438760(a1[33], a1);
    }
    func_003B4A50(a0, a1, 0);
    if (*(s16 *)(a1 + 170) == *(s32 *)s) {
        *(s32 *)(s + 196) += 1;
    }
}
