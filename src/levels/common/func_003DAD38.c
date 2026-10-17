#include "common.h"
extern s32 func_0044BA68(u8 *);
extern s32 func_00405140(u8 *);
extern void func_003DAAE8(u8 *);
void func_003DAD38(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (func_0044BA68(a0)) {
        *(s32 *)(p + 4) = 10;
    }
    if (func_00405140(p) && a0[49] && *(s32 *)(p + 4) > 0) {
        func_003DAAE8(a0);
    }
}
