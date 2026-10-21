#include "common.h"

/* localdecomp:start func_00403708 */
typedef int u128_t __attribute__((mode(TI)));

extern s32 D_001E10E8;
extern u8 D_001DA160[];
extern u8 D_001DA170[];
extern void func_00403708(s32, s32, s32, s32, unsigned long);

extern s32 D_001D4BD0_003867F8;
extern s32 D_001D4BD4_003867F8;
extern u8 D_001DA160[];
extern u8 D_001DA170[];
void func_00403708(s32 y0, s32 y1, s32 x0, s32 x1, unsigned long c) {
    u8 *r;
    u8 *p;
    u8 *q;
    u8 *s;
    u8 *t;
    u8 *q0;
    *(s32 *)(D_001E10E8 + 0) = 0x10000005;
    *(s32 *)(D_001E10E8 + 4) = 0;
    *(s32 *)(D_001E10E8 + 8) = 0;
    *(s32 *)(D_001E10E8 + 0xC) = 0x50000005;
    r = (u8 *)D_001E10E8;
    D_001E10E8 = (s32)r + 0x10;
    *(u128_t *)(r + 0x10) = *(u128_t *)D_001DA160;
    *(s16 *)D_001E10E8 = -0x7FFF;
    p = (u8 *)D_001E10E8;
    q0 = p + 0x10;
    D_001E10E8 = (s32)q0;
    *(long *)(p + 0x10) = 0x144;
    *(unsigned long *)(q0 + 8) = c;
    s = (u8 *)D_001E10E8;
    D_001E10E8 = (s32)s + 0x10;
    *(u128_t *)(s + 0x10) = *(u128_t *)D_001DA170;
    *(s16 *)D_001E10E8 = -0x7FFC;
    t = (u8 *)D_001E10E8;
    q = t + 0x10;
    D_001E10E8 = (s32)q;
    *(long *)(t + 0x10) = ((x0 << 4) + D_001D4BD0_003867F8 - 8) | ((long)((y0 << 4) + D_001D4BD4_003867F8 - 8) << 16) | 0xFFFFF000000000UL;
    *(long *)(q + 8) = ((x1 << 4) + D_001D4BD0_003867F8 - 8) | ((long)((y0 << 4) + D_001D4BD4_003867F8 - 8) << 16) | 0xFFFFF000000000UL;
    *(long *)(q + 0x10) = ((x0 << 4) + D_001D4BD0_003867F8 - 8) | ((long)((y1 << 4) + D_001D4BD4_003867F8 - 8) << 16) | 0xFFFFF000000000UL;
    *(long *)(q + 0x18) = ((x1 << 4) + D_001D4BD0_003867F8 - 8) | ((long)((y1 << 4) + D_001D4BD4_003867F8 - 8) << 16) | 0xFFFFF000000000UL;
    D_001E10E8 = D_001E10E8 + 0x20;
}
/* localdecomp:end func_00403708 */
