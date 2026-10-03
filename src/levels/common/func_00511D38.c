#include "common.h"
extern s32 func_00511910_00511D38(s32);
extern void func_0051DAA0_00511D38(s32 *, s32, s32, s32);
s32 func_00511D38(void *object, s32 index, s32 code, s32 enabled, s32 amount) {
    s32 table_offset;
    if (enabled != 0 && amount < 0x190) {
        if (code <= 0x31FFF) {
            table_offset = index * 4;
            if (*(s32 *)((u8 *)(*(s32 *)((u8 *)object + 4) + table_offset) + 0x18) == 0) {
                *(s32 *)((u8 *)(*(s32 *)((u8 *)object + 4) + table_offset) + 0x18) = func_00511910_00511D38(index);
                func_0051DAA0_00511D38((s32 *)func_00511910_00511D38(index), amount, enabled, code);
                return 1;
            }
            goto done;
        }
        return 0;
    }
done:
    return 0;
}
