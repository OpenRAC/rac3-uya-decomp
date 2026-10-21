#include "common.h"

/* localdecomp:start func_003F51A8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3F51A8;
typedef int Q_3F51A8 __attribute__((mode(TI)));
typedef struct {
    V_3F51A8 v;
    u8 pad[0x20];
} E_3F51A8;
typedef struct {
    s32 n;
    u8 pad[0xC];
    E_3F51A8 e[1];
} T_3F51A8;
extern s32 *D_001DF8C0[];
extern f32 func_0040BF68(void *);
extern s32 func_003F52E8(void *, void *, f32);
E_3F51A8 *func_003F51A8(V_3F51A8 *a0, f32 r) {
    V_3F51A8 t, d;
    V_3F51A8 *tp = &t;
    Q_3F51A8 x, y;
    s32 i, j, k, c;
    T_3F51A8 *q;
    s32 *tbl;
    f32 pf, dl;
    E_3F51A8 *p;
    t = *a0;
    i = (s32)(t.x * 0.0625f);
    j = (s32)(t.y * 0.0625f);
    if (i < 0 || j < 0 || i > 64 || j > 64) {
        return 0;
    }
    tbl = D_001DF8C0[0];
    q = (T_3F51A8 *)tbl[(j << 6) + i];
    if (q == 0) {
        return 0;
    }
    q = (T_3F51A8 *)((s32)q + (s32)tbl);
    for (c = 0; c < q->n; c++) {
        p = &q->e[c];
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->v));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*tp));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
        pf = p->v.w;
        d.w = 1.0f;
        dl = func_0040BF68(&d);
        if (dl < pf + r) {
            if (func_003F52E8(tp, p, r)) {
                return p;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003F51A8 */
