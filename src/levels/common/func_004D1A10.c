#include "common.h"

/* localdecomp:start func_004D1A10 */
extern s32 func_004D1A10();

typedef struct { char c[4]; } S4_3AD108;
typedef struct { u8 p0[0x48]; u8 p48[0x60]; s32 fA8; } S_3AD108;
extern S4_3AD108 D_001DB890[];
extern s32 D_001E1264_003AD108;
extern void func_004D1900();
extern s32 func_004D1E28();
extern void func_004D1920();
extern void func_004D13B0();
s32 func_004D1A10(S_3AD108 *a) {
    S4_3AD108 buf;
    s32 r0;
    s32 r1;
    s32 r2;
    s32 r3;
    s32 v;
    buf = D_001DB890[0];
    func_004D1900(a, &r0, &r1, &r2, &r3);
    if (r1 + r3 < 4) return 0;
    v = func_004D1E28((r0 & 0xFFFFFFF) | 0x20000000, r1, (r2 & 0xFFFFFFF) | 0x20000000, r3, &buf, 4, 0, 0);
    func_004D1920(D_001E1264_003AD108, v);
    func_004D13B0((u8 *)a + 0x48);
    if (a->fA8 == 0) {
        a->fA8 = 2;
    }
    return 1;
}
/* localdecomp:end func_004D1A10 */
