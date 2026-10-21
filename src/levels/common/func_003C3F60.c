#include "common.h"

/* localdecomp:start func_003C3F60 */
extern u8 D_001A4BE0[];
extern s32 func_00440760(u8 *, s32, s32);
extern void func_00452F40(u8 *o, s32 a);

void func_003C3F60(u8 *a0, u8 *a1) {
    u8 *p = D_001A4BE0;
    s32 v = *(s32 *)(p + 9668);
    if (v == 116 || v == 49 || v == 101) {
        return;
    }
    if (*(s32 *)(p + 860) == *(s32 *)(a1 + 72) ||
        (*(s32 *)(a1 + 204) != -1 && func_00440760(p + 128, *(s32 *)(a1 + 204), 0) != 0)) {
        func_00452F40(a0, 1);
        a1[259] = 1;
    } else {
        func_00452F40(a0, 0);
    }
}
/* localdecomp:end func_003C3F60 */
