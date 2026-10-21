#include "common.h"

/* localdecomp:start func_003E2790 */
typedef int Q_3E2790 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3E2790;

extern u8 D_001E2AC0[];
extern s32 D_001D673C;
extern f32 func_0040BEF8(V4_3E2790 *, V4_3E2790 *);
extern void func_0040BE90(V4_3E2790 *, V4_3E2790 *, f32);

static __inline__ void vadd_3E2790(V4_3E2790 *out, V4_3E2790 *a, V4_3E2790 *b) {
    Q_3E2790 x, y, r;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(r));
}

static __inline__ void vsub_3E2790(V4_3E2790 *out, V4_3E2790 *a, V4_3E2790 *b) {
    Q_3E2790 x, y, r;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(r));
}

#define F_(T, p, o) (*(T *)((u8 *)(p) + (o)))
#define V_(p, o) ((V4_3E2790 *)((u8 *)(p) + (o)))

void func_003E2790(u8 *obj, V4_3E2790 *in) {
    V4_3E2790 v;
    V4_3E2790 *pv;
    u8 *p2;
    V4_3E2790 t1;
    V4_3E2790 t2;
    V4_3E2790 t3;
    u8 *base;
    u8 *s3;
    u8 *s6;
    u8 *p;
    u8 *q;
    u8 *x;
    f32 d;

    pv = &v;
    v = *in;
    base = D_001E2AC0 + F_(s32, obj, 148) * 1120;
    p = F_(u8 *, obj, 112);
    q = p + 96;
    s3 = base + 336;
    s6 = base + 96;
    x = F_(u8 *, s3, 248);
    if (x != 0 && D_001D673C == 0 && F_(s16, s3, 292) == 0) {
        if (x == F_(u8 *, q, 280)) {
            d = F_(f32, x, 24) - F_(f32, q, 284);
            if (d > 0.0f && d > v.z) {
                v.z = d;
            }
            F_(f32, q, 284) = F_(f32, F_(u8 *, s3, 248), 24);
        } else {
            F_(u8 *, q, 280) = x;
            F_(f32, q, 284) = F_(f32, F_(u8 *, s3, 248), 24);
        }
    } else {
        F_(u8 *, q, 280) = 0;
    }
    vadd_3E2790(V_(obj, 48), pv, V_(obj, 48));
    vadd_3E2790(V_(q, 96), pv, V_(q, 96));
    vadd_3E2790(V_(q, 0), pv, V_(q, 0));
    vadd_3E2790(V_(q, 176), pv, V_(q, 176));
    vadd_3E2790(V_(q, 48), pv, V_(q, 48));
    vadd_3E2790(V_(p, 0), pv, V_(p, 0));
    d = func_0040BEF8(pv, V_(s6, 48));
    func_0040BE90(&t1, V_(s6, 48), d);
    vadd_3E2790(V_(q, 16), V_(q, 16), &t1);
    if (F_(s16, s3, 292) == 0) {
        if (F_(u8 *, s3, 248) == 0 || F_(s16, F_(u8 *, s3, 248), 170) != 557 || F_(s32, base, 1108) >= 31) {
            F_(f32, F_(u8 *, obj, 112), 512) = pv->w;
        }
    }
    if ((u32)(F_(s32, s3, 256) - 11) < 2) {
        p2 = F_(u8 *, obj, 112);
        F_(s16, p2, 16) = 0;
        func_0040BE90(&t2, V_(s6, 128), F_(f32, s6, 164));
        d = func_0040BEF8(V_(s6, 48), pv);
        func_0040BE90(&t3, V_(s6, 48), d);
        vsub_3E2790(&t3, pv, &t3);
        vsub_3E2790(&t2, &t2, &t3);
        vadd_3E2790(V_(obj, 48), &t2, V_(obj, 48));
        vadd_3E2790(V_(q, 96), &t2, V_(q, 96));
        vadd_3E2790(V_(q, 0), &t2, V_(q, 0));
        vadd_3E2790(V_(q, 176), &t2, V_(q, 176));
        vadd_3E2790(V_(p2, 0), &t2, V_(p2, 0));
    }
}
/* localdecomp:end func_003E2790 */
