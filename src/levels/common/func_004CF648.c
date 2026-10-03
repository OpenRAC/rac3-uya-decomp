#include "common.h"

void func_004CF648(void *arg0, s32 arg1) {
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_4;
    s32 temp_4_2;
    s32 var_8;

    var_8 = arg1;
    if ((*(s32 *)((u8 *)arg0 + 0)) == 0) {
        if ((*(s32 *)((u8 *)arg0 + 4)) != 4) {
            temp_4 = (*(s32 *)((u8 *)arg0 + 0x30));
            temp_2 = 0x28 - temp_4;
            temp_2_2 = (temp_2 >= var_8) ? var_8 : temp_2;
            temp_4_2 = temp_4 + temp_2_2;
            (*(s32 *)((u8 *)arg0 + 0x30)) = temp_4_2;
            if (temp_4_2 >= 0x28) {
                (*(s32 *)((u8 *)arg0 + 0)) = 1;
            }
            var_8 -= temp_2_2;
        } else {
            (*(s32 *)((u8 *)arg0 + 0)) = 1;
        }
    }
    if ((*(s32 *)((u8 *)arg0 + 4)) == 3) {
        (*(s32 *)((u8 *)arg0 + 0x40)) = ((*(s32 *)((u8 *)arg0 + 0x40)) / 256) * 256;
    }
    (*(s32 *)((u8 *)arg0 + 0x3C)) = (*(s32 *)((u8 *)arg0 + 0x3C)) + var_8;
    (*(s32 *)((u8 *)arg0 + 0x44)) = (*(s32 *)((u8 *)arg0 + 0x44)) + var_8;
    (*(s32 *)((u8 *)arg0 + 0x38)) = ((*(s32 *)((u8 *)arg0 + 0x38)) + var_8) % (*(s32 *)((u8 *)arg0 + 0x40));
}
