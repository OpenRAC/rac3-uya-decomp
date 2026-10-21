#include "common.h"

/* localdecomp:start func_004D1640 */
extern s32 func_0011EE60(s32);
extern void func_0011EE40(s32);

typedef struct { long f0; long f8; s32 f10; s32 f14; } E_3ACD38;
typedef struct { u8 *f0; u8 p4[4]; s32 f8; u8 pC[0x2C]; s32 f38; u8 p3C[4]; s32 f40; u8 p44[0xC]; E_3ACD38 *f50; s32 f54; s32 f58; s32 f5C; } S_3ACD38;
typedef struct { long a, b; } R_3ACD38;
extern s32 func_0011EE60(s32);
extern void func_0011EE40(s32);
s32 func_004D1640(S_3ACD38 *p, R_3ACD38 *out) {
    s32 found = 0;
    u32 pos;
    s32 size;
    s32 n, i, idx;
    u32 st;
    s32 off;
    s32 rem, head;
    pos = *(volatile u32 *)0x1000B410;
    st = *(volatile u32 *)0x10002020;
    off = p->f38 & 0x7F;
    size = p->f8 << 11;
    pos -= (((st >> 16) & 3) + ((st >> 8) & 0xF)) << 4;
    func_0011EE60(p->f40);
    out->a = -1;
    out->b = -1;
    rem = (pos + (off >> 3) + size - (u32)p->f0) % size;
    n = p->f58;
    head = p->f5C;
    for (i = 0; i < n && !found; i++) {
        idx = (head - n + p->f54 + i) % p->f54;
        if ((rem + size - p->f50[idx].f10) % size < p->f50[idx].f14) {
            found = 1;
            out->a = p->f50[idx].f0;
            out->b = p->f50[idx].f8;
            p->f50[idx].f0 = -1;
            p->f50[idx].f8 = -1;
            p->f58 -= p->f58 < 2 ? p->f58 : 1;
        }
    }
    func_0011EE40(p->f40);
    return 1;
}
/* localdecomp:end func_004D1640 */
