#include "common.h"

/* localdecomp:start func_0047A350 */
extern void func_004C1E50(s32);
extern s32 func_0012C908(s32);
extern void func_0012C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_0011F0A0(s32);
extern void func_0012CCC8(void *, s32);
extern s32 func_0012A9F0(s32, s32);
typedef struct { u8 p0[0x20]; s32 x20; u8 p24[0x60]; s32 x84; } S_2E9FD8;
extern S_2E9FD8 D_002E9FD8;
extern s32 D_001DF9C8;
extern s32 D_001D4BC4;
extern s32 D_001D4BB4;

void func_0047A350(s32 a0) {
    u8 buf[0x60];
    s32 n, off, d;
    D_002E9FD8.x84 = a0 ? 2 : 1;
    func_004C1E50(1);
    func_0012C908(0);
    D_001DF9C8 = D_001DF9C8 + 1;
    n = D_001D4BC4 * 0x600;
    off = D_002E9FD8.x20;
    d = D_001D4BB4;
    if (a0) d = 0x3FB000 - n;
    for (; n >= 0; n -= 0x4000) {
        func_0012C9A0(buf, d >> 8, 1, 0, 0, 0, 0x40, 0x40);
        d += 0x4000;
        func_0011F0A0(0);
        func_0012CCC8(buf, off);
        off += 0x4000;
        func_0012A9F0(0, 0);
    }
}
/* localdecomp:end func_0047A350 */
