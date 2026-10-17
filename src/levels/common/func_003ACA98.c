#include "common.h"
extern void func_00422428(u8 *, s32, s32);
extern void func_003ACAE0(u8 *);
void func_003ACA98(u8 *a0) {
    if (*(s32 *)(*(u8 **)(a0 + 104) + 896) != -1) {
        func_00422428(a0, 8, -1);
    } else {
        func_003ACAE0(a0);
    }
}
