#include "common.h"
extern u8 D_00143950[];
extern void func_004A7368(s32, s32, s32);
void func_0048DB60(s32 a0) {
    if (a0 & 0xA040) {
        u8 *p;
        func_004A7368(4, 0, 0);
        p = D_00143950;
        p[5] = p[5] == 0;
    }
}
