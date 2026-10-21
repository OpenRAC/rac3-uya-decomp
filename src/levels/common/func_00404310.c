#include "common.h"
extern s32 D_001D6C50;
extern u8 D_001EE490[];
extern void func_003ED958(u8 *, s32);
void func_00404310(s32 a0) {
    s32 i;
    u8 *p;
    if (D_001D6C50 != 0 && a0 != 0) {
        for (i = 0; i < 3; i++) {
            p = D_001EE490 + i * 176;
            *(u32 *)(p + 32) = 0x7F7F7F7F;
            *(u32 *)(p + 36) = 0x7F7F7F7F;
            *(u32 *)(p + 40) = 0x7F7F2000;
            *(u32 *)(p + 44) = 0x7F7F2000;
            func_003ED958(p, D_001D6C50);
        }
    }
}
