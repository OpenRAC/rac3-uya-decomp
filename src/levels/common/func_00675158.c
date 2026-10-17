#include "common.h"
extern void func_0058F1B0(void *a0, s32 a1, s32 a2);
extern void func_00665BC8(void *a0);
s32 func_00675158(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 buf[36];
    func_0058F1B0(buf, a3, 36);
    if ((buf[31] & 0xF) == 3) {
        func_00665BC8(buf);
    }
    return 36;
}
