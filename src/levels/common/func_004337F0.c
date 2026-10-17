#include "common.h"

extern s32 D_001D67C8;

extern s32 D_001D67C8;
extern s32 D_002D1630[];
extern void func_0041D430();
extern void func_004331A8();
void func_004337F0(void) {
    if (D_001D67C8 != 0 && D_002D1630[0] == 0) {
        func_0041D430(1);
        func_004331A8();
    }
}
