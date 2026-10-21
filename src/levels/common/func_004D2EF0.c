#include "common.h"

/* localdecomp:start func_004D2EF0 */
extern void func_00433EA0(u8 *, u32);
void func_00433EA0(u8 *, u32);
extern void func_00433EA0();
extern void func_0011F0A0();

typedef struct { u8 p0[0xC]; s32 fC; } P_3B70A8;
extern P_3B70A8 *D_001EA9D8[];
extern s32 D_002F4188[];
extern void func_0011F0A0();
void func_004D2EF0(s32 a, s32 *out, s32 c) {
    u8 *base;
    s32 n;
    s32 *tbl;
    s32 idx;
    base = (u8 *)D_001EA9D8[0] + D_001EA9D8[0]->fC;
    n = *(s32 *)base;
    tbl = (s32 *)(base + 0x10);
    if (a < 0x1E && (idx = D_002F4188[a]) != -1 && idx < n && tbl[idx] != 0) {
    } else {
        a = 0;
    }
    func_0011F0A0(0);
    *out = ((s32 (*)(u8 *, u32))func_00433EA0)(base + tbl[D_002F4188[a]], c);
    func_0011F0A0(0);
}
/* localdecomp:end func_004D2EF0 */
