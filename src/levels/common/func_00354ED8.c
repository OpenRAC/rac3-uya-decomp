#include "common.h"
extern void func_0042A3E0(u8 *);
extern s32 func_004466C0(u8 *, u8 *, u8 *, s32);
extern void func_00435D78(u8 *, s32, s32);
void func_00354ED8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (a0[32] == 0) {
        if (p == 0) {
            func_0042A3E0(a0);
        } else {
            *(s32 *)(p + 1152) = func_004466C0(a0, p, p + 128, 32);
            func_00435D78(a0, 1, -1);
        }
    }
}
