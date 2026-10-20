#include "common.h"

typedef struct {
    u8 pad0[0x58];
    s32 x58;
    s16 x5C;
    u8 pad5E[0x68 - 0x5E];
    s32 x68;
} S_004294D0;

extern S_004294D0 D_001E6E00;
extern s32 D_0021F660[];

extern void func_0011F0A0(s32);
extern s32 func_00433EA0(s32, s32);
extern void func_0040BD80(s32, s32, s32);
extern void func_0042A598(s32, s32, s32);

void func_004294D0(void) {
    s32 r, d, n, start;
    s32 *e;
    s32 a, b, c, o;

    func_0011F0A0(0);
    r = func_00433EA0(D_001E6E00.x68, D_001E6E00.x58);
    func_0011F0A0(0);
    d = 0x8E000 - r;
    if (d > 16) {
        n = D_001E6E00.x58 + d;
        func_0040BD80(n, D_001E6E00.x58, r);
        D_001E6E00.x58 = n;
    }
    start = D_0021F660[0];
    e = (s32 *)D_001E6E00.x58;
    while ((a = *e++) >= 0) {
        b = *e++;
        c = *e;
        e += 2;
        o = 0;
        if (b != 0) {
            o = D_001E6E00.x58 + b;
        }
        func_0042A598(a, D_001E6E00.x58 + c, o);
    }
    D_001E6E00.x5C = D_0021F660[0] - start;
}
