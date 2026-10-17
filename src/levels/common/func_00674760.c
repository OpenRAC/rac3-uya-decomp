#include "common.h"
extern s32 D_001DAE90;
void func_00674760(s32 a0) {
    s32 *p = &(&D_001DAE90)[a0];
    if (*p == 0) {
        *p = 1;
    }
}
