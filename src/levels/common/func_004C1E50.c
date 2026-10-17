#include "common.h"

extern void func_004C1E50();
extern void func_004C1E50(s32);
extern void func_0040BB80();

extern s32 D_001DAE90;
extern void func_0040BB80(s32);
void func_004C1E50(s32 a) {
    while (D_001DAE90 & a) {
        func_0040BB80(0x400);
    }
}
