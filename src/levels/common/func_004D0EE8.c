#include "common.h"

extern s32 func_0011EE60(s32);
extern void func_0011EE40(s32);

extern s32 func_0011EE60(s32);
extern void func_0011EE40(s32);
extern void func_004D0948(s32);
extern void func_004D08D8(s32);
s32 func_004D0EE8(s32 *p) {
    func_0011EE60(p[0x10]);
    p[0x11] = 0;
    func_004D0948(5);
    p[7] = *(volatile s32 *)0x1000B410;
    p[8] = *(volatile s32 *)0x1000B430;
    p[9] = *(volatile s32 *)0x1000B420;
    p[10] = *(volatile s32 *)0x1000B400;
    if (*(volatile s32 *)0x10002010 & 0xF0) { do {} while (*(volatile s32 *)0x10002010 & 0xF0); }
    func_004D08D8(0);
    p[11] = *(volatile s32 *)0x1000B010;
    p[12] = *(volatile s32 *)0x1000B020;
    p[13] = *(volatile s32 *)0x1000B000;
    p[14] = *(volatile s32 *)0x10002020;
    p[15] = *(volatile s32 *)0x10002010;
    func_0011EE40(p[0x10]);
    return 1;
}
