#include "common.h"

/* localdecomp:start func_0042B598 */
extern u8 D_00142CA5[];
extern struct { u8 pad[0x410]; s32 v; } D_001F4020;
extern s32 *D_001D8D80;
extern s32 func_0042B508(s32);
extern s32 func_0042B550(s32);
s32 func_0042B598(void) {
    s32 off;
    s32 p;
    s32 x;
    s32 i;
    s32 d;
    s32 q;
    s32 n;
    s32 *t;
    off = 0x100;
    if (!D_00142CA5[0]) off = 0;
    p = D_001F4020.v + off;
    if (func_0042B508(p) == -1 && func_0042B550(p)) return p;
    x = D_001F4020.v;
    i = 0;
    if (x < 60) {
        t = D_001D8D80;
        while (t[i] != x) i++;
    }
    for (d = 1; d != 4; d = d > 0 ? -d : 1 - d) {
        n = i + d;
        if (n >= 0) {
            if (n < 60) {
                q = D_001D8D80[n];
                if (q != 0) {
                    p = q + off;
                    if (func_0042B508(p) == -1 && func_0042B550(p)) return p;
                }
            }
        }
    }
    return -1;
}
/* localdecomp:end func_0042B598 */
