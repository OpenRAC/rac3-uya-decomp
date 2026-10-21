#include "common.h"

/* localdecomp:start func_00432850 */
extern void func_0040BBA8(void *, s32, s32);
extern void func_0040BCB8();
extern s32 func_00432850();

extern void func_0040BBA8(void *, s32, s32);
extern void func_0040BCB8();
extern u16 func_00432768(u8 *p, u32 n);
s32 func_00432850(u8 *dst, s32 n, s32 *e) {
    s32 off = 0;
    u8 *p = dst + 8;
    s32 *q;
    s32 t, u, w;
    if (e[0] != 0) {
        q = e;
        do {
            off += 8;
            w = n * q[1];
            u = q[0];
            t = u + w;
            *(s32 *)p = q[2];
            *(s32 *)(p + 4) = q[1];
            p += 8;
            if (q[2] == 0x1770) {
                func_0040BBA8(p, 0, q[1]);
            } else {
                func_0040BCB8(p, t, q[1]);
            }
            p += q[1];
            off += q[1];
            q += 4;
            p = (u8 *)((s32)p + 3 & ~3);
            off = (off + 3) & ~3;
        } while (q[0] != 0);
    }
    off += 8;
    *(s32 *)(p + 4) = 0;
    *(s32 *)p = -1;
    *(s32 *)(dst + 4) = func_00432768(dst + 8, off);
    *(s32 *)dst = off;
    return off + 8;
}
/* localdecomp:end func_00432850 */
