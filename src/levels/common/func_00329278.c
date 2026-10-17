#include "common.h"
extern u16 D_001A7466[];
extern void func_003291E0(s32, char *);
void func_00329278(s32 a0, char *a1) {
    func_003291E0(a0, a1);
    D_001A7466[0] = *(u16 *)(a1 + 124);
}
