#include "common.h"
extern void func_00409BD8(void *, s32, void *);
void func_0034D538(void *a0, void *a1) {
    u8 *s = *(u8 **)((u8 *)a0 + 104);
    if (*(s32 *)(s + 20) == 1) {
        func_00409BD8(a0, 0, a1);
    }
    if (*(s32 *)(s + 20) == 4) {
        func_00409BD8(a0, 0, a1);
    }
    if (*(s32 *)(s + 20) == 3) {
        func_00409BD8(a0, 1, a1);
    }
    if (*(s32 *)(s + 20) == 2) {
        func_00409BD8(a0, 1, a1);
    }
}
