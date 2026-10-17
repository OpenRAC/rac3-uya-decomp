#include "common.h"

extern void func_004A6DF8(u8 *, s32);
extern void func_00303440(u8 *);

void func_0033C9F8(u8 *p) {
    u8 *q;
    u8 *m;

    *(s32 *)(p + 152) = 0;
    q = *(u8 **)(p + 104);
    *(u16 *)(p + 52) = (*(u16 *)(p + 52) | 0x41) & ~0x1000;
    func_004A6DF8(p, 1);
    p[32] = 6;
    q[248] = 1;
    q[249] = 255;
    m = *(u8 **)(q + 300);
    if (m != 0) {
        if (*(s16 *)(m + 170) == 806) {
            func_00303440(m);
        }
        *(u8 **)(q + 300) = 0;
    }
}
