#include "common.h"

extern u8 *D_001E009C[];
extern void func_003B19C0(s32, u8 *);
extern void func_003B3CC0(u8 *, s32);
extern void func_003B18A0(u8 *);

void func_003B29E8(s32 a0, s32 *a1) {
    u8 *p = D_001E009C[0] + (*a1 << 8);
    func_003B19C0(a0, p);
    if (*(s16 *)(p + 170) == 6628) {
        func_003B3CC0(p, 1);
    } else {
        func_003B18A0(p);
    }
}
