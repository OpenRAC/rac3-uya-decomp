#include "common.h"

extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern s32 func_003268D0(s32, s32);

typedef struct {
    s32 f0;
    u8 p4[0x18 - 0x4];
    s32 f18;
    s32 f1C;
    u8 p20[0x30 - 0x20];
    s32 f30;
    u8 p34[0x88 - 0x34];
    s32 f88;
    s32 f8C;
    u8 p90[0xBC - 0x90];
    s32 fBC;
    s32 fC0;
    s32 fC4;
    u8 pC8[0x110 - 0xC8];
    s32 f110;
    s32 f114;
} Obj_3B62A8;

s32 func_003B62A8(s32 unused, Obj_3B62A8 *p) {
    s32 n, max, t, r, min;

    if (p->f110 != -1 && !(D_001BBC40[D_001D545C][p->f110] & 0x80)) return 0;
    if (p->f114 != -1 && (D_001BBC40[D_001D545C][p->f114] & 0x80)) return 0;
    max = p->f18;
    if (max <= 0) return 0;
    if (p->f30 == 0) return 0;
    if (p->f88 != 0 && p->f8C >= p->f88) return 0;
    t = p->fC0 - p->fC4;
    if (t >= max) return 0;
    n = max - t;
    if (n < p->f1C) return 0;
    r = func_003268D0(p->f0, n);
    if (r < n) n = r;
    if (n == 0) return 0;
    min = p->f1C;
    if (min < n) n = min;
    if (p->f30 > 0) {
        s32 u = p->fBC - p->fC0;
        if (u <= 0) return 0;
        if (u < n) n = u;
        if (n < min) return 0;
    }
    return n;
}
