#include "common.h"
extern u8 *D_001A5F78[];
extern u8 *func_0053CA78(void);
extern s32 func_0053CA40(s32 a0, s32 a1, u8 *a2, s32 a3, u8 *t0);
void func_003ED698(s32 a0, s32 a1, u8 *a2) {
    u8 *s3;
    u8 *s0;
    u8 *p;
    s3 = *(u8 **)(a2 + 104);
    s0 = func_0053CA78();
    if (s0 != 0) {
        p = s0 + func_0053CA40(4, a0, D_001A5F78[0] + 500, a1, s0);
        *(s32 *)p = *(s32 *)(s3 + 620);
        p += 4;
        *(s32 *)s0 = p - s0;
    }
}
