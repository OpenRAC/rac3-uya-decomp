#include "common.h"

extern s32 func_00354AF8(u8 *a0);
extern void func_0043A7B8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_00359930(u8 *a0, s32 a1, s32 a2, s32 a3);

void func_00354EB0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    if (func_00354AF8(a0) == 0) {
        if (*(s16 *)(v + 1012) != 0) {
            func_00359930(a0, 5, 0, 10);
        } else {
            func_00359930(a0, 6, 0, 10);
        }
    } else {
        func_0043A7B8(*(s32 *)(v + 1004), 5, 0, 10);
    }
}
