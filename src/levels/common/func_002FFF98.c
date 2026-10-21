#include "common.h"

/* localdecomp:start func_002FFF98 */
typedef int Q_2FFF98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_2FFF98;
typedef struct { V_2FFF98 m[4]; } M_2FFF98;
typedef struct {
    u8 pad[0x10];
    V_2FFF98 v10;
    u8 pad20[0x3C - 0x20];
    s32 f3C;
} R_2FFF98;
typedef struct {
    u8 pad[0x10];
    V_2FFF98 v10;
    u8 pad20[0xC0 - 0x20];
    M_2FFF98 mC0;
} O_2FFF98;
extern R_2FFF98 *func_00449388(O_2FFF98 *);
extern void func_0040C658(M_2FFF98 *, void *);
extern void func_0040C8E0(M_2FFF98 *, M_2FFF98 *);
extern void func_0040C2D0(V_2FFF98 *, V_2FFF98 *, M_2FFF98 *);
extern void func_0040C960(M_2FFF98 *, M_2FFF98 *, M_2FFF98 *);
void func_002FFF98(O_2FFF98 *o, O_2FFF98 *p) {
    R_2FFF98 *r;
    V_2FFF98 *v;
    M_2FFF98 m0, m40, m80;
    Q_2FFF98 as, ao, ad, bs, bo, bd, cs, co, cd;
    r = func_00449388(p);
    if (r != 0) {
        func_0040C658(&m0, r);
        v = &o->v10;
        __asm__("lqc2 %0, %1" : "=j"(as) : "m"(o->v10));
        __asm__("lqc2 %0, %1" : "=j"(ao) : "m"(r->v10));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(as) : "j"(ao));
        __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(as));
        __asm__("lqc2 %0, %1" : "=j"(bs) : "m"(o->v10));
        __asm__("lqc2 %0, %1" : "=j"(bo) : "m"(p->v10));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(bs) : "j"(bo));
        __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(bs));
        if ((r->f3C & 2) != 0) {
            func_0040C658(&m80, (u8 *)r + 0x20);
            func_0040C8E0(&m40, &m80);
            func_0040C2D0(v, v, &m40);
            func_0040C2D0(v, v, &p->mC0);
        } else {
            func_0040C2D0(v, v, &m0);
        }
        __asm__("lqc2 %0, %1" : "=j"(cs) : "m"(o->v10));
        __asm__("lqc2 %0, %1" : "=j"(co) : "m"(p->v10));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(cs) : "j"(co));
        __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(cs));
        func_0040C960(&o->mC0, &m0, &o->mC0);
    }
}
/* localdecomp:end func_002FFF98 */
