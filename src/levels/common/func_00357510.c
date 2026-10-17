#include "common.h"
extern void func_004140C0(void *, s32, s32);
extern u8 D_001426E0[];
void func_00357510(void *a0) {
    u8 *p = D_001426E0;
    if (p[82] == 1) {
        func_004140C0(a0, 5, -1);
    }
    if (p[82] == 2) {
        func_004140C0(a0, 4, -1);
    }
    if (p[82] == 3) {
        func_004140C0(a0, 2, -1);
    }
    p[82] = 0;
}
