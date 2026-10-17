#include "common.h"

extern void func_00422328();

extern void func_004AF4D8(s32, s32, s32);
extern s32 func_004B46F0(s32, s32, s32);
extern s32 func_004A44A8(s32, s32, s32);
extern u8 D_001F1CC0[];
void func_00422328(s32 arg0) {
    s32 temp_2;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    void *temp_16;

    temp_16 = (arg0 * 0x30) + D_001F1CC0;
    temp_2 = (*(s32 *)((u8 *)temp_16 + 0xC));
    if (temp_2 != 0) {
        temp_4 = temp_2 + ((*(s16 *)((u8 *)temp_16 + 0)) * 2);
        func_004B46F0(temp_4, temp_4 + ((*(s16 *)((u8 *)temp_16 + 2)) * 2), arg0);
        temp_4_2 = (*(s32 *)((u8 *)temp_16 + 0xC)) + ((*(s16 *)((u8 *)temp_16 + 4)) * 2);
        (*(s16 *)((u8 *)temp_16 + 0)) = 0;
        (*(s16 *)((u8 *)temp_16 + 2)) = 0;
        func_004A44A8(temp_4_2, temp_4_2 + ((*(s16 *)((u8 *)temp_16 + 6)) * 2), arg0);
        temp_4_3 = (*(s32 *)((u8 *)temp_16 + 0xC)) + ((*(s16 *)((u8 *)temp_16 + 8)) * 2);
        (*(s16 *)((u8 *)temp_16 + 4)) = 0;
        (*(s16 *)((u8 *)temp_16 + 6)) = 0;
        func_004AF4D8(temp_4_3, temp_4_3 + ((*(s16 *)((u8 *)temp_16 + 0xA)) * 2), arg0);
        (*(s16 *)((u8 *)temp_16 + 8)) = 0;
        (*(s16 *)((u8 *)temp_16 + 0xA)) = 0;
    }
}
