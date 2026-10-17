#include "common.h"

typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p1[0x48]; s32 f58; s32 f5C; s32 f60; u8 p2[0x10]; s32 f74; s32 f78; } S;
void func_0041A6C0(void *arg) {
    S *s = (S *)arg;
    s32 *q;
    s32 n, x, a, t;
    q = s->fC;
    if (q != 0 && ((s32)q & 3) == 0) {
        s->f78 = *q;
        if (s->f8 < s->f78) s->f78 = s->f8;
        s->f74 = s->f78;
    } else {
        s->f78 = 99999;
        s->f74 = 99999;
    }
    n = 0;
    x = s->f8;
    a = s->f60;
    t = s->f5C;
    if (x >= 10) {
        do { x /= 10; n++; } while (x >= 10);
    }
    if ((a & 3) == 0 && (a & 0xC) != 0) {
        s->f5C = t + (n + 1) * 12;
        if (s->f58 < 0xE) s->f58 = 0xE;
    } else {
        if (t < 12) s->f5C = 12;
        s->f58 = s->f58 + (n + 1) * 14;
    }
}
