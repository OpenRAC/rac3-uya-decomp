#include "common.h"

/* localdecomp:start func_004CF3D0 */
extern s32 func_0013D080();
typedef struct { s32 f0; s32 f4; u8 pad8[0x28]; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; s32 f44; s32 f48; s32 f4C; s32 f50; u8 pad54[4]; s32 f58; s32 f5C; } S_3AAAC8;
s32 func_004CF3D0(S_3AAAC8 *p, s32 a, s32 b, s32 c) {
    s32 r;
    p->f34 = a;
    p->f40 = b;
    p->f0 = 0;
    p->f4 = c;
    p->f30 = 0;
    p->f38 = 0;
    p->f3C = 0;
    p->f44 = 0;
    p->f50 = 0;
    p->f58 = 0;
    p->f5C = 0;
    if (c == 2) p->f4C = 0x6000;
    else if (c == 3) p->f4C = 0x400;
    else p->f4C = 0xC000;
    r = func_0013D080(p->f4C, 0x1000, 0x400, 0, 2, p->f4);
    p->f48 = r;
    if (r < 0) return 0;
    return 1;
}
/* localdecomp:end func_004CF3D0 */
