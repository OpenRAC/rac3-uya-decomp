#include "common.h"

extern void func_0011EE40(s32);
extern void func_0011EE60(s32);

extern void func_0011EE60(s32);
extern void func_0011EE40(s32);
s32 func_004D1360(u8 *p) {
    s32 r;
    func_0011EE60(*(s32 *)(p + 0x40));
    r = (*(s32 *)(p + 0x10) << 11) + *(s32 *)(p + 0x14);
    func_0011EE40(*(s32 *)(p + 0x40));
    return r;
}
