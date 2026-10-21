#include "common.h"

/* localdecomp:start func_00402248 */
extern void func_0040BCB8();
extern s32 D_001D4BB0;

extern s32 D_001D4BB0;
extern s32 D_001E10E8;
extern u8 D_002EF000[];
extern u8 D_002EF070[];
extern void func_0040BCB8();
extern void func_004C21C0();
s32 func_00402248(s32 a, s32 p, s32 q, s32 type) {
    s32 e = p - 6;
    s32 v;
    s32 h;
    s32 r;
    u8 *d;
    if (e < 0) e = 0;
    v = (1 << (p + q)) >> 4;
    e = 1 << e;
    if (type == 0x14) {
        v = (1 << (p + q)) >> 5;
        func_0040BCB8(D_001E10E8, D_002EF000, 0x70);
    } else {
        func_0040BCB8(D_001E10E8, D_002EF070, 0x70);
    }
    h = D_001D4BB0;
    r = h >> 8;
    D_001D4BB0 = h + (v << 4);
    d = (u8 *)D_001E10E8;
    *(u8 *)(d + 0x26) = e;
    *(s32 *)(d + 0x64) = a;
    *(s16 *)(d + 0x24) = r;
    *(s32 *)(d + 0x30) = 1 << p;
    *(s32 *)(d + 0x34) = 1 << q;
    *(s32 *)(d + 0x50) = v | 0x8000;
    *(s32 *)(d + 0x60) = v | 0x30000000;
    *(s32 *)(d + 0x6C) = v | 0x50000000;
    D_001E10E8 = D_001E10E8 + 0x70;
    func_004C21C0();
    return r;
}
/* localdecomp:end func_00402248 */
