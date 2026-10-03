#include "common.h"

void func_004CF7D0(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3, void *arg4, s32 arg5) {
    s32 temp_11;
    s32 temp_12;
    s32 temp_hi;
    temp_11 = (*(s32 *)((u8 *)arg4 + 0x4C));
    temp_12 = (*(s32 *)((u8 *)arg4 + 0x58));
    temp_hi = (((arg5 + temp_11) - temp_12) - 0x400) % temp_11;
    if ((u32)(arg5 - temp_12) < 0x400U) {
        *arg0 = (*(s32 *)((u8 *)arg4 + 0x48));
        *arg1 = 0;
        *arg2 = (*(s32 *)((u8 *)arg4 + 0x48));
        *arg3 = 0;
        return;
    }
    temp_hi = ((temp_hi / 1024) * 1024);
    if ((temp_11 - temp_12) >= temp_hi) {
        *arg0 = (*(s32 *)((u8 *)arg4 + 0x48)) + temp_12;
        *arg1 = temp_hi;
        *arg2 = 0;
        *arg3 = 0;
        return;
    }
    *arg0 = (*(s32 *)((u8 *)arg4 + 0x48)) + temp_12;
    *arg1 = (*(s32 *)((u8 *)arg4 + 0x4C)) - (*(s32 *)((u8 *)arg4 + 0x58));
    *arg2 = (*(s32 *)((u8 *)arg4 + 0x48));
    *arg3 = temp_hi - ((*(s32 *)((u8 *)arg4 + 0x4C)) - (*(s32 *)((u8 *)arg4 + 0x58)));
}
