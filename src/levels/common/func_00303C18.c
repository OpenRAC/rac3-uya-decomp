#include "common.h"

/* localdecomp:start func_00303C18 */
typedef int Q_303C18 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_303C18;
extern u8 D_001E2AC0[];
extern f32 func_0040BEF8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern f32 func_0040BF38(void *);
extern f32 func_0040CFB0(f32, f32);
#define F_(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define M_(e) (*(u8 **)((e) + 0x240) + 0xE0)
void func_00303C18(u8 *p) {
    V4_303C18 t0, t1;
    Q_303C18 a, b, c, d, e, g, h, k, l;
    u8 *ent, *q, *pv, *ev;
    f32 d20, f, fa;
    ent = D_001E2AC0 + p[0xBC] * 0x460;
    q = *(u8 **)(ent + 0x50);
    if (q != 0) {
        *(V4_303C18 *)(p + 0x10) = *(V4_303C18 *)(q + 0x30);
        pv = p + 0x10;
        ev = ent + 0x190;
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_303C18 *)(ent + 0x190)));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V4_303C18 *)(p + 0x10)));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(c));
        d20 = func_0040BEF8(&t0, M_(ent));
        func_0040BE90(&t1, M_(ent), d20);
        __asm__("lqc2 %0, %1" : "=j"(d) : "m"(t0));
        __asm__("lqc2 %0, %1" : "=j"(e) : "m"(t1));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(g) : "j"(d), "j"(e));
        __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(g));
        __asm__("abs.s %0, %1" : "=f"(fa) : "f"(d20));
        if (fa < 2.5f) {
            if (func_0040BF38(&t0) < 0.1f || func_0040CFB0(F_(ent, 0x1A8), F_(ent, 0x18)) < 2.3561945f || F_(ent, 0x260) < 0.0016666668f) {
                f = 15.0f;
                F_(p, 0x10) = f;
            } else {
                f = func_0040BEF8(pv, M_(ent));
                func_0040BE90(&t1, M_(ent), f);
                __asm__("lqc2 %0, %1" : "=j"(h) : "m"(t1));
                __asm__("lqc2 %0, %1" : "=j"(k) : "m"(*(V4_303C18 *)(p + 0x10)));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(l) : "j"(k), "j"(h));
                __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(l));
                f = func_0040BEF8(ev, M_(ent));
                func_0040BE90(&t1, M_(ent), f);
                {
                    Q_303C18 m, n, o;
                    __asm__("lqc2 %0, %1" : "=j"(m) : "m"(t0));
                    __asm__("lqc2 %0, %1" : "=j"(n) : "m"(t1));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(o) : "j"(m), "j"(n));
                    __asm__("sqc2 %1, %0" : "=m"(*(V4_303C18 *)(p + 0x10)) : "j"(o));
                }
                return;
            }
        } else {
            return;
        }
    } else {
        f = 5.0f;
        F_(p, 0x10) = f;
    }
    F_(p, 0x14) = f;
    F_(p, 0x18) = f;
}
/* localdecomp:end func_00303C18 */
