#include "common.h"

/* localdecomp:start func_00413408 */
extern s32 D_001E10E8;
extern void func_004C1FA0(s32);
extern void func_004C1FE8(s32, unsigned long);
void func_00413408(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, u32 a6) {
    s32 p, q;
    s32 x0, y0, x1, y1;
    func_004C1FA0(0x13000000);
    func_004C1FE8(0x42, 0x64);
    *(s32 *)(D_001E10E8 + 0) = 0x10000006;
    y0 = a1 << 4;
    y1 = a3 << 4;
    *(s32 *)(D_001E10E8 + 4) = 0;
    x0 = a0 << 4;
    x1 = a2 << 4;
    y1 += 0x8000;
    y0 += 0x8000;
    *(s32 *)(D_001E10E8 + 8) = 0;
    x1 += 0x8000;
    x0 += 0x8000;
    *(s32 *)(D_001E10E8 + 0xC) = 0x50000006;
    y1 -= a5 << 3;
    y0 -= a5 << 3;
    x0 -= a4 << 3;
    x1 -= a4 << 3;
    p = D_001E10E8;
    q = p + 0x10;
    D_001E10E8 = q;
    *(long *)(p + 0x10) = 0x1000000000000001UL;
    *(long *)(q + 8) = 0xE;
    *(long *)(q + 0x10) = 0x33003;
    *(long *)(q + 0x18) = 0x47;
    *(long *)(q + 0x20) = 0x2400000000000001UL;
    *(long *)(q + 0x28) = 0x10;
    *(long *)(q + 0x30) = 0x106;
    *(long *)(q + 0x38) = a6;
    *(long *)(q + 0x40) = 0x2400000000008001UL;
    *(long *)(q + 0x48) = 0x44;
    *(long *)(q + 0x50) = (long)x0 | ((long)y0 << 16);
    *(long *)(q + 0x58) = (long)x1 | ((long)y1 << 16);
    D_001E10E8 = D_001E10E8 + 0x60;
    func_004C1FE8(0x42, 0x8000000044UL);
    func_004C1FA0(0x13000000);
}
/* localdecomp:end func_00413408 */
