#include "common.h"

extern s32 D_001D545C[];
extern u8 *func_003B8D10(u8 *);
extern u8 *func_003B91D0(u8 *);
extern u8 *func_003B9558(u8 *);
extern void func_004B6470(u8 *, s32);

void func_00378710(u8 *o, s32 *a) {
    u8 *m;
    if (D_001D545C[0] == 11) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
    } else {
        o[0x30] = 0x28;
        *(s16 *)(o + 0x32) = 0x28;
    }
    a[0] = 0;
    o[0x20] = 1;
    m = 0;
    if (a[1] != -1 || a[2] != -1) {
        if (a[1] != 0) {
            m = func_003B8D10(o);
        } else if (a[2] != 0) {
            m = func_003B91D0(o);
        } else {
            m = func_003B9558(o);
        }
    }
    if (a[1] == 6) {
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_004B6470(m, 1);
        *(s32 *)(o + 0x98) = 0;
        *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
        func_004B6470(o, 1);
    }
    if (a[1] == 5) {
        *(u16 *)(m + 0x34) |= 0x41;
    }
    *(u16 *)(o + 0x34) |= 0x41;
}
