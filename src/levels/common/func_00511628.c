#include "common.h"

extern void func_0040BBA8();
extern void func_0040BBA8(void *, s32, s32);
extern void func_0040BBA8(void *, int, int);
extern void func_00511628();

void func_00511628(u8 *p) {
    func_0040BBA8((s32)(p + 8), 0, 0x2000);
    *(s32 *)(p + 4) = 0;
}
