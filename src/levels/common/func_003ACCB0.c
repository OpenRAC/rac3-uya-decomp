#include "common.h"

extern f32 D_001DE6E4;
extern f32 func_003ED340(void *, void *);
extern void func_004220E8(u8 *, s32, s32, s32);
extern void func_00422428(u8 *, s32, s32);

void func_003ACCB0(u8 *self) {
    if (func_003ED340(self + 16, *(u8 **)(self + 104) + 304) < D_001DE6E4 * D_001DE6E4) {
        if (self[67] != 13) {
            func_004220E8(self, 13, 0, 4);
        }
        func_00422428(self, 33, -1);
    } else {
        if (self[67] != 9) {
            func_004220E8(self, 9, 3, 16);
        }
        func_00422428(self, 28, -1);
    }
}
