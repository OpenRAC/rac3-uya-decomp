#include "common.h"

/* localdecomp:start func_003E5198 */
typedef int Q_3E5198 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3E5198;
typedef struct {
    u8 pad0[0x460];
} E_3E5198;
typedef struct {
    u8 pad0[0x30];
    V_3E5198 v30;
    u8 pad40[0x70 - 0x40];
    u8 *p70;
    u8 pad74[0x86 - 0x74];
    s16 s86;
    u8 pad88[0x94 - 0x88];
    s32 i94;
} O_3E5198;
typedef struct {
    Q_3E5198 q0;
    u8 pad10[0x60 - 0x10];
    Q_3E5198 q60;
    V_3E5198 v70;
    u8 pad80[0xA0 - 0x80];
    Q_3E5198 qA0;
    V_3E5198 vB0;
    Q_3E5198 qC0;
    u8 padD0[0xF0 - 0xD0];
    Q_3E5198 qF0;
    u8 pad100[0x100 - 0x100];
    Q_3E5198 q100;
    V_3E5198 v110;
    Q_3E5198 q120;
    u8 pad130[0x180 - 0x130];
    V_3E5198 v180;
    Q_3E5198 q190;
    u8 pad1A0[0x230 - 0x1A0];
    V_3E5198 v230;
    u8 pad240[0x260 - 0x240];
    s32 i260;
} P_3E5198;
extern u8 D_001E2C10[];
extern void func_0040BE90(void *, void *, f32);
extern f32 func_0040BEF8(void *, void *);

void func_003E5198(O_3E5198 *o) {
    P_3E5198 *p;
    u8 *e;
    V_3E5198 t0, t1;
    Q_3E5198 a;
    f32 f0;
    u8 *a60;
    u8 *a180;
    if (o->s86 == 0) {
        e = D_001E2C10 + o->i94 * 0x460;
        p = (P_3E5198 *)o->p70;
        a60 = (u8 *)p + 0x60;
        a180 = (u8 *)p + 0x180;
        func_0040BE90(&t0, e + 0x80, -1.0f);
        a = *(Q_3E5198 *)(e + 0x40);
        p->q60 = a;
        p->qC0 = a;
        f0 = func_0040BEF8(a60, &t0);
        func_0040BE90(&p->v70, &t0, f0);
        __asm__("sq $0,%0" : "=m"(p->qF0));
        __asm__("sq $0,%0" : "=m"(p->q100));
        __asm__("sq $0,%0" : "=m"(p->q120));
        func_0040BE90(&t1, &t0, *(f32 *)(a180 + 0x30));
        {
            Q_3E5198 b, c, d;
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(p->q60));
            __asm__("lqc2 %0, %1" : "=j"(c) : "m"(t1));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(d) : "j"(c), "j"(b));
            __asm__("sqc2 %1, %0" : "=m"(p->vB0) : "j"(d));
        }
        func_0040BE90(&t1, &t0, *(f32 *)(a60 + 0xD0));
        {
            Q_3E5198 b, c, d;
            __asm__ __volatile__("lqc2 %0, %1" : "=j"(b) : "m"(p->q60));
            __asm__("lqc2 %0, %1" : "=j"(c) : "m"(t1));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(d) : "j"(c), "j"(b));
            __asm__("sqc2 %1, %0" : "=m"(p->v110) : "j"(d));
        }
        p->qA0 = *(Q_3E5198 *)&p->v110;
        {
            Q_3E5198 b, c, d;
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(p->vB0));
            __asm__("lqc2 %0, %1" : "=j"(c) : "m"(o->v30));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(d) : "j"(c), "j"(b));
            __asm__("sqc2 %1, %0" : "=m"(p->v180) : "j"(d));
        }
        p->q190 = *(Q_3E5198 *)&p->v180;
        p->q0 = *(Q_3E5198 *)&o->v30;
        {
            Q_3E5198 b, c, d;
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(p->vB0));
            __asm__("lqc2 %0, %1" : "=j"(c) : "m"(p->v180));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(d) : "j"(b), "j"(c));
            __asm__("sqc2 %1, %0" : "=m"(p->v230) : "j"(d));
        }
        p->i260 = 0;
    }
}
/* localdecomp:end func_003E5198 */
