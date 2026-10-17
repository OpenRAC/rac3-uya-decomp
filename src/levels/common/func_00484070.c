#include "common.h"
extern s16 D_001A7464[];
extern s32 func_00483D68(s32 a0);
extern s32 func_00483C98(s32 a0);
extern void func_005130C8(s32 a0, u32 a1);
void func_00484070(void) {
    if (D_001A7464[0] != 0) {
        func_005130C8(func_00483C98(func_00483D68(3)), 0x80808080);
        func_005130C8(func_00483C98(func_00483D68(2)), 0x80808080);
    }
}
