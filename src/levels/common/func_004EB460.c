#include "common.h"
extern char D_001A4CD0[];
extern void func_0040C0F0(void *, s32, float);
void func_004EB460(s32 a0) {
    char *p = D_001A4CD0;
    func_0040C0F0(p, a0, *(float *)(p + 196));
}
