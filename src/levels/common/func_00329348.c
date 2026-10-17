#include "common.h"
extern void func_00329368(s32, u8 *);
void func_00329348(s32 a0, u8 *a1) {
    *(s32 *)(a1 + 128) = 0;
    func_00329368(a0, a1);
}
