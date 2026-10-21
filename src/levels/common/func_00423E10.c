#include "common.h"

/* localdecomp:start func_00423E10 */
extern void func_00423700();
extern void func_004239F8();
void func_00423E10(s32 *a0, u8 *b, u8 *c, s32 n) {
    s32 i, j, cnt, lo, idx;
    s32 *e, *nx;
    s32 *p = a0;
    for (i = 0; i < n; i++) {
        nx = p + 4;
        cnt = p[1] >> 16;
        lo = p[1] & 0xFFFF;
        p[1] = lo;
        e = (s32 *)((u8 *)p[0] + ((lo - cnt) << 4));
        for (j = 0; j < cnt; j += 4) {
            idx = e[8];
            if (idx >= 0) idx = c[idx];
            if (b) {
                func_00423700(e, b + (idx << 4), e[0], e[1], e[4], e[5], idx);
            } else {
                func_004239F8((unsigned long *)e, e[0], e[1], e[4], e[5], idx);
            }
            e += 16;
        }
        p = nx;
    }
}
/* localdecomp:end func_00423E10 */
