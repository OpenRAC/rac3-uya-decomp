#include "common.h"

/* localdecomp:start func_003E24F8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3E24F8;
typedef int Q_3E24F8 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x80];
    V_3E24F8 v80;
    V_3E24F8 v90;
    u8 padA0[0x460 - 0xA0];
} E_3E24F8;
typedef struct {
    u8 pad0[0x60];
    V_3E24F8 v60;
    V_3E24F8 v70;
    u8 pad80[0x20];
    V_3E24F8 vA0;
    V_3E24F8 vB0;
    V_3E24F8 vC0;
    u8 padD0[0x20];
    V_3E24F8 vF0;
    V_3E24F8 v100;
    V_3E24F8 v110;
    V_3E24F8 v120;
} P_3E24F8;
typedef struct {
    u8 pad0[0xD0];
    f32 fD0;
    u8 pad4[0x10];
    u8 bE4;
    u8 bE5;
    s16 hE6;
    f32 fE8;
} A_3E24F8;
typedef struct {
    u8 pad0[0x30];
    f32 f30;
} B_3E24F8;
typedef struct {
    u8 pad0[0x70];
    P_3E24F8 *p70;
    u8 pad74[0x20];
    s32 w94;
} O_3E24F8;
extern E_3E24F8 D_001E2AC0[];
extern void func_003E23A8(void *, void *, s32);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
void func_003E24F8(O_3E24F8 *o) {
    E_3E24F8 *q = &D_001E2AC0[o->w94];
    P_3E24F8 *p = o->p70;
    A_3E24F8 *g = (A_3E24F8 *)((u8 *)p + 0x60);
    B_3E24F8 *h = (B_3E24F8 *)((u8 *)p + 0x180);
    V_3E24F8 a, b, c;
    Q_3E24F8 x, y;
    f32 f;
    func_003E23A8(q, &a, 0);
    f = func_0040BEF8(&a, &q->v90);
    func_0040BE90(&b, &q->v90, f);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(p->v60) : "j"(x));
    p->v70 = b;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->v70));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->v60));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(p->v60) : "j"(x));
    func_0040BE90(&c, &q->v80, g->fD0);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->v60));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(c));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(p->vA0) : "j"(x));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->v60));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(c));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(p->v110) : "j"(x));
    __asm__("sq $0,%0" : "=m"(p->v120));
    g->bE5 = 0;
    g->fE8 = 1.0f;
    g->hE6 = 0;
    g->bE4 = 0;
    __asm__("sq $0,%0" : "=m"(p->vF0));
    __asm__("sq $0,%0" : "=m"(p->v100));
    p->vC0 = p->v60;
    func_0040BE90(&c, &q->v80, h->f30);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->v60));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(c));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(p->vB0) : "j"(x));
}
/* localdecomp:end func_003E24F8 */
