#include "common.h"
extern s32 D_001E0CB0[2];
extern s32 D_001E0CC8;
extern void func_005DC270(void);
extern void func_005DC7A0(void);
extern u8 func_005DC758[];
extern s32 func_0060DD48(void *, void *, void *, void *, s32, s32);
void *func_005DC7C0(s32 a0) {
    void *tbl[1];
    if (D_001E0CC8 == 0) {
        func_0060DD48(D_001E0CB0, func_005DC270, func_005DC7A0, func_005DC758 + 16, 0, 0);
        D_001E0CC8 = 1;
    }
    tbl[0] = D_001E0CB0;
    return tbl[a0];
}
