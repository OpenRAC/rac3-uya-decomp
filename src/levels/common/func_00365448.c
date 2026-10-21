#include "common.h"

extern void func_00451098(u8 *, s32, s32, s32);
extern void func_004513D8(u8 *, s32, s32);

s32 func_00365448(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    if (o[0x60] & 2) {
        func_004513D8(o, 1, 1);
        if (o[0x43] != 0) {
            func_00451098(o, 0, 0, 0);
        }
        if (*(long *)(s + 0x310) != -1) {
            func_004513D8(o, 5, 6);
        } else if (*(s32 *)(s + 0x300) != -1) {
            func_004513D8(o, 2, -1);
        } else if (*(s32 *)(s + 0x318) == 0) {
            func_004513D8(o, 4, -1);
        }
        return 1;
    }
    return 0;
}
