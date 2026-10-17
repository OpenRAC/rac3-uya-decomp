#include "common.h"
extern u32 D_00240640;
extern u8 *func_00619838(u32);
void func_006719D8(u8 *a0) {
    if (a0[6676] == 0) {
        u32 v = *(u32 *)(*(u8 **)(*(u8 **)(a0 + 9560) + 4) + 80) ^ D_00240640;
        if (v != 0xFFFFFFFF) {
            u8 *r = func_00619838(v);
            if (r != 0) {
                *(s32 *)(a0 + 4216) = *(s32 *)(r + 9508);
            }
        }
    }
}
