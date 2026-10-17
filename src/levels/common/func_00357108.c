#include "common.h"
extern void func_004CB6E0(s32, s32);
extern void func_004140C0(void *, s32, s32);
void func_00357108(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    *(s32 *)(v + 220) = 0;
    *(s32 *)(v + 216) = 0;
    func_004CB6E0(154, 1);
    func_004140C0(a0, 6, -1);
}
