#include "common.h"

extern s32 D_001E10E8;

typedef int u128_387A00 __attribute__((mode(TI)));
extern s32 D_001E10E8;
extern u8 D_001DA230[];
void func_00404BA0(long *a, s32 *b, s32 *c, long d, s32 e) {
    u8 *r;
    u8 *p;
    u8 *q;
    *(s32 *)(D_001E10E8 + 0) = 0x10000009;
    *(s32 *)(D_001E10E8 + 4) = 0;
    *(s32 *)(D_001E10E8 + 8) = 0;
    *(s32 *)(D_001E10E8 + 0xC) = 0x50000009;
    r = (u8 *)D_001E10E8;
    D_001E10E8 = (s32)r + 0x10;
    *(u128_387A00 *)(r + 0x10) = *(u128_387A00 *)D_001DA230;
    p = (u8 *)D_001E10E8;
    q = p + 0x10;
    D_001E10E8 = (s32)q;
    if (e) {
        *(long *)(p + 0x10) = 5;
    } else {
        *(long *)(p + 0x10) = 0;
    }
    *(long *)(q + 8) = d;
    *(long *)(q + 0x10) = 0x154;
    *(long *)(q + 0x18) = c[0];
    *(long *)(q + 0x20) = b[0];
    *(long *)(q + 0x28) = a[0];
    *(long *)(q + 0x30) = c[1];
    *(long *)(q + 0x38) = b[1];
    *(long *)(q + 0x40) = a[1];
    *(long *)(q + 0x48) = c[2];
    *(long *)(q + 0x50) = b[2];
    *(long *)(q + 0x58) = a[2];
    *(long *)(q + 0x60) = c[3];
    *(long *)(q + 0x68) = b[3];
    *(long *)(q + 0x70) = a[3];
    *(long *)(q + 0x78) = 0;
    D_001E10E8 = D_001E10E8 + 0x80;
}
