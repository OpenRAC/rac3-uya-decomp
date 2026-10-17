#include "common.h"

extern u8 D_001425C0[];

typedef struct {
    u8 pad[0x84];
    u16 f84;
    u8 pad2[0xF0 - 0x86];
} S_391E30;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern S_391E30 D_002C5640[];
s32 func_0041D558(void) {
    u8 *b = D_001A4BE0;
    s32 r = *(s32 *)(b + 0x1228);
    u8 f = b[0x25E4];
    u8 *q = (u8 *)D_001425C0 + r;
    S_391E30 *t = D_002C5640;
    if (t[*q].f84 == 0) {
        r = 0;
    }
    if (f != 0) {
        r = 0;
    }
    return r;
}
