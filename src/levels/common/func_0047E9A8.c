#include "common.h"

extern s32 func_00512D70(s32, s32);
extern s32 func_00512D70(s32 arg0, s32 arg1);
extern s32 D_001D83C0;
extern s32 D_001D4CE8[];

extern s32 D_001D83C0;
extern s32 D_001D4CE8[];
void func_0047E9A8(void) {
    s32 temp_3;

    if (D_001D83C0 == 0) {
        temp_3 = D_001D4CE8[0];
        switch (temp_3) {                           /* irregular */
        case 18:
            /* fallthrough */
        case 1:
            func_00512D70(0x4C003C, 1);
            func_00512D70(0xD000B, 1);
            return;
        default:
            func_00512D70(0x4C003C, 0);
            func_00512D70(0xD000B, 0);
            D_001D83C0 = 1;
            break;
        }
    }
}
