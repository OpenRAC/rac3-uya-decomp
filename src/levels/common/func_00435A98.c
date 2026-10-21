#include "common.h"

/* localdecomp:start func_00435A98 */
extern void func_0040BCB8();
typedef struct { s16 f0; u8 p0[0x16]; u16 f18; u8 p1[0x12]; s16 f2c; u8 p2[2]; } E39A040;
extern E39A040 *D_002E9A30_0039A040[];
extern s32 func_00435A98(u8 *, s32, s32);

extern s32 func_00434A28(u8 *);
extern s32 func_00435A50(u8 *, s32, s32, s32);
extern void func_0040BCB8(u8 *, u8 *, s32);
s32 func_00435A98(u8 *p, s32 a, s32 b) {
    s32 i;
    s32 j;
    u8 *q;
    for (i = 0; i < 0x5F && !(p[i * 2] - 1 == a && p[i * 2 + 1] == b); i++) {
        j = i * 2;
        q = p + j;
        if (func_00434A28(q) == 0) {
            if (func_00434A28(q) != 0) continue;
            if ((D_002E9A30_0039A040[q[0] - 1][q[1]].f0 & 0xFF) < (D_002E9A30_0039A040[a][b].f0 & 0xFF)) continue;
        }
        if (func_00435A50(p, a, b, i) != -1) continue;
        func_0040BCB8((u8 *)0x70000000, q, (0x5F - i) * 2);
        q[1] = b;
        q[0] = a + 1;
        func_0040BCB8(&p[j + 2], (u8 *)0x70000000, (0x5F - i) * 2);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00435A98 */
