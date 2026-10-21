#include "common.h"

/* localdecomp:start func_00403120 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_00403120(void);
extern s32 D_001E10E8;

extern s32 D_001DF9E0_00386210;
extern s32 D_001DF9DC_00386210;
extern s32 D_001D4BD0_00386210;
extern s32 D_001D4BD4_00386210;
extern s32 D_001D4BD8;
extern s32 D_001D4BDC;
extern u8 D_001439FD[];
extern u8 D_001DA160[];
extern u8 D_001DA170[];
void func_00403120(void) {
    s32 n, t, n4;
    u8 *r;
    u8 *p;
    u8 *q0;
    u8 *s;
    u8 *u;
    u8 *q;
    if (D_001DF9DC_00386210 != 0) {
        if (D_001DF9E0_00386210 < 0x34) D_001DF9E0_00386210 = D_001DF9E0_00386210 + 1;
    } else {
        if (D_001DF9E0_00386210 == 0) return;
        D_001DF9E0_00386210 = D_001DF9E0_00386210 - 1;
    }
    n = D_001DF9E0_00386210;
    if (n == 0) return;
    if (D_001439FD[0] != 0) return;
    *(s32 *)(D_001E10E8 + 0) = 0x10000007;
    *(s32 *)(D_001E10E8 + 4) = 0;
    *(s32 *)(D_001E10E8 + 8) = 0;
    *(s32 *)(D_001E10E8 + 0xC) = 0x50000007;
    r = (u8 *)D_001E10E8;
    D_001E10E8 = (s32)r + 0x10;
    *(u128_t *)(r + 0x10) = *(u128_t *)D_001DA160;
    *(s16 *)D_001E10E8 = -0x7FFF;
    p = (u8 *)D_001E10E8;
    q0 = p + 0x10;
    D_001E10E8 = (s32)q0;
    *(long *)(p + 0x10) = 0x104;
    *(long *)(q0 + 8) = 0x80000000UL;
    s = (u8 *)D_001E10E8;
    D_001E10E8 = (s32)s + 0x10;
    *(u128_t *)(s + 0x10) = *(u128_t *)D_001DA170;
    *(s16 *)D_001E10E8 = -0x7FF8;
    n4 = n << 4;
    u = (u8 *)D_001E10E8;
    q = u + 0x10;
    D_001E10E8 = (s32)q;
    *(long *)(u + 0x10) = D_001D4BD0_00386210 | ((long)D_001D4BD4_00386210 << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 8) = D_001D4BD0_00386210 | ((long)(D_001D4BD4_00386210 + n4) << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x10) = D_001D4BD8 | ((long)D_001D4BD4_00386210 << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x18) = D_001D4BD8 | ((long)(D_001D4BD4_00386210 + n4) << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x20) = D_001D4BD8 | ((long)D_001D4BDC << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x28) = D_001D4BD8 | ((long)(D_001D4BDC - n4) << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x30) = D_001D4BD0_00386210 | ((long)D_001D4BDC << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x38) = D_001D4BD0_00386210 | ((long)(D_001D4BDC - n4) << 16) | 0xFFFFF300000000UL;
    D_001E10E8 = D_001E10E8 + 0x40;
}
/* localdecomp:end func_00403120 */
