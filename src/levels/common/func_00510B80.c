#include "common.h"
extern void func_00512020_00510B80(void *);
void func_00510B80(s32 *owner) {
    s32 offset;
    s32 address;
    s32 index;
    void *entry;
    index = 0;
    do {
        offset = index * 4;
        address = *(s32 *)((u8 *)(*owner + offset) + 0xDC);
        if (address != 0) {
            func_00512020_00510B80((void *)address);
        }
        *(s32 *)((u8 *)(*owner + offset) + 0xDC) = 0;
        *(s32 *)((u8 *)(*owner + offset) + 0x11C) = 0;
        *(s32 *)((u8 *)(*owner + offset) + 0x15C) = 0;
        *(s8 *)((u8 *)(*owner + index) + 0x1AC) = 0;
        entry = (void *)(*owner + index);
        index += 1;
        *(s8 *)((u8 *)entry + 0x19C) = 0;
    } while (index < 0x10);
}
