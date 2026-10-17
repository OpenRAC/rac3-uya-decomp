#include "common.h"

extern void func_00423F28();

typedef struct { s32 pad[2]; s32 f8; s32 pad2[8]; } S_227600_00394B38;
extern S_227600_00394B38 D_001EA9C0_00394B38;
extern void func_00423E10();
void func_00423F28(u8 *a, s32 b, u8 *tab) {
    s32 n, i;
    s32 *p, *q, *r, *r0;
    u8 *s;
    n = a[0] + a[1] + a[2];
    p = (s32 *)(a + *(s32 *)(a + 4));
    r0 = (s32 *)(a + *(s32 *)(a + 8));
    q = p;
    for (i = 0; i < n; i++) {
        if (q[0] < D_001EA9C0_00394B38.f8) {
            q[0] = q[0] + (s32)a;
            q[2] = q[2] + (s32)a;
        }
        q += 4;
    }
    r = r0;
    for (;;) {
        r[3] = r[3] + (s32)a;
        s = (u8 *)r;
        if (*s != 0xFF) {
            do {
                *s = tab[*s];
                s++;
            } while (*s != 0xFF);
        }
        if (r[3] < 0) break;
        r += 4;
    }
    func_00423E10(p, b, tab, n);
}
