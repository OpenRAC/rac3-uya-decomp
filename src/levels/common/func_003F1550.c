#include "common.h"

s32 func_00303B18(void *, s32, s32, s32);           /* extern */
extern void func_00436220(s32 p);
extern u8 D_001E2B20[];

void func_003F1550(s32 arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_a2;
    void *temp_s0;

    temp_a2 = arg0 * 0x460;
    temp_s0 = temp_a2 + D_001E2B20;
    if ((*(s16 *)((u8 *)(arg1) + 0x86)) == 0) {
        if ((*(s32 *)((u8 *)(temp_s0) + 0xC4)) == 0) {
            (*(s32 *)((u8 *)(temp_s0) + 0xC4)) = func_00303B18(temp_a2 + (D_001E2B20 - 0x60), arg0, temp_a2, arg0);
        }
    } else {
        temp_a0 = (*(s32 *)((u8 *)(temp_s0) + 0xC4));
        if (temp_a0 != 0) {
            func_00436220(temp_a0);
            (*(s32 *)((u8 *)(temp_s0) + 0xC4)) = 0;
        }
    }
}
