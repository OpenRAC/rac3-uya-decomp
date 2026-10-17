#include "common.h"

extern s32 func_004CF3A0();
extern s32 func_0011EE60(s32);
extern void func_0011EE40(s32);
extern s32 func_004D0890(void *, s32);
extern void func_004D0948(s32);

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; u8 p18[0x28]; s32 f40; s32 f44; } O_3AC3F8;
extern void func_004D09B8_003AC3F8();
extern s32 func_004CF3A0();
extern u8 D_001DB878[];
s32 func_004D0D00(O_3AC3F8 *o) {
    s32 flag = 0;
    u32 reg;
    s32 pos;
    s32 t;
    s32 n;
    s32 cur;
    s32 idx;
    s32 i;
    func_0011EE60(o->f40);
    if (o->f44 == 0) {
        func_004CF3A0(D_001DB878);
        return 0;
    }
    func_004D0948(5);
    reg = *(volatile u32 *)0x1000B400;
    pos = func_004D0890(o, *(volatile u32 *)0x1000B410);
    t = (pos + o->f8 - o->fC) % o->f8;
    n = o->f14 / 0x800;
    o->f14 = o->f14 - n * 0x800;
    o->fC = (o->fC + t) % o->f8;
    o->f10 = o->f10 - t;
    idx = (o->fC + o->f10) % o->f8;
    if (n > 0) {
        s32 m1 = o->f8 - 1;
        s32 k = (o->fC + o->f10 + m1) % o->f8;
        func_004D09B8_003AC3F8(o->f4 + k * 16, o->f0 + k * 0x800, 3, 0x80);
        flag = 1;
    }
    {
        s32 c2 = idx;
        for (i = 0; i < n; i++) {
            s32 m = i != n - 1 ? 3 : 0;
        func_004D09B8_003AC3F8(o->f4 + c2 * 16, o->f0 + c2 * 0x800, m, 0x80);
            c2 = (c2 + 1) % o->f8;
        }
    }
    o->f10 = o->f10 + n;
    if (o->f10 != 0) {
        if (flag) {
            reg = (reg & 0xFFFFFFF) | 0x30000000;
        }
        func_004D0948(reg | 0x100);
    }
    func_0011EE40(o->f40);
    return 1;
}
