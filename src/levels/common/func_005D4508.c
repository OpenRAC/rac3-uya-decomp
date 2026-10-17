#include "common.h"
typedef struct { s32 w0; s32 w4; s32 w8; u8 pad[0x10]; } E_5D4508;
extern E_5D4508 D_00484160[];
extern u8 *func_006197C0(s32);
void func_005D4508(s32 a, s32 b) {
    s32 i = *(s32 *)(func_006197C0(a) + 9540);
    D_00484160[i].w0 = 5;
    D_00484160[i].w8 = b;
}
