#include "common.h"

extern s32 D_001DF1BC;
extern s32 func_00425240(u8 *);
extern void func_00346630(u8 *);
extern s32 func_003E4770(u8 *);
extern void func_00419340(u8 *, s32, s32);

void func_003BBAF8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    if (func_00425240(a0)) {
        *(s32 *)(v + 20) = D_001DF1BC;
        func_00346630(v + 8);
    }
    if (func_003E4770(v + 20)) {
        func_00419340(a0, 1, -1);
    }
}
