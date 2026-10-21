#include "common.h"

/* localdecomp:start func_004A56C0 */
typedef struct { u8 p[0xC]; s32 fC; s32 f10; } T;
extern T D_00143950_b;
extern s32 D_001A30D0[];
extern void func_0040BD58(void *, void *, s32);
void func_004A56C0(void) {
    s32 *s = D_001A30D0;
    s32 *d = s - 8;
    s32 *a, *b, *q;
    s32 i, x, y, t;
    func_0040BD58(s, d, 0x20);
    x = D_00143950_b.f10;
    d[1] = D_00143950_b.fC;
    d[2] = x;
    d[5] = x * 25 / 32;
    s[-8] = x * 7 / 10;
    y = x * 6 / 10;
    d[3] = y;
    d[4] = y;
    a = s;
    b = d;
    q = b;
    for (i = 0; i < 6; i++) {
        t = (*a != *b);
        q[0x6C8] |= t << i;
        a++;
        b++;
    }
}
/* localdecomp:end func_004A56C0 */
