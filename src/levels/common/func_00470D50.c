#include "common.h"

typedef int Q_470D50 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_470D50;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    s16 hC;
} S_470D50;
typedef struct {
    u8 pad0[4];
    u32 f4;
    u8 b8;
    u8 pad9;
    s16 hA;
    u32 fC;
    V_470D50 v10;
    V_470D50 v20;
    S_470D50 s;
} O_470D50;

extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern void func_0040C0F0(V_470D50 *, V_470D50 *, f32);
extern void func_004C6EC8(V_470D50 *, V_470D50 *);

/* localdecomp:start func_00470D50 */
void func_00470D50(O_470D50 *o)
{
    V_470D50 t;
    V_470D50 *p1, *p2;
    Q_470D50 x1, x2, r1, y1, r2;
    S_470D50 *s;
    f32 a;
    s32 al;

    s = &o->s;
    if (func_0040BAC0(&o->hA)) {
        func_0045E580(o);
        return;
    }
    if (o->hA < 10) {
        o->s.f0 = o->s.f0 - 0.069444448f;
    }
    __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(o->v20));
    __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(o->v10));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(x1), "j"(x2));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(r1));
    t.w = 0.0f;
    func_0040C0F0(&t, &t, o->s.f0);
    p1 = &o->v10;
    __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(t));
    __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(o->v10));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(x1), "j"(x2));
    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(r1));
    func_0040C0F0(&t, &t, o->s.f0);
    p2 = &o->v20;
    __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(t));
    __asm__("lqc2 %0, %1" : "=j"(y1) : "m"(o->v20));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r2) : "j"(y1), "j"(x2));
    __asm__("sqc2 %1, %0" : "=m"(o->v20) : "j"(r2));
    func_004C6EC8(p1, p1);
    func_004C6EC8(p2, p2);
    a = (f32)o->hA;
    o->v10.w = s->f4 * ((s->f8 - 1.0f) * (a / (f32)s->hC) + 1.0f);
    if (o->hA < o->b8) {
        al = (s32)(a / (f32)o->b8 * 127.0f);
        o->f4 = (al << 24) | (o->f4 & 0xFFFFFF);
        o->fC = (al << 24) | (o->fC & 0xFFFFFF);
    }
}
/* localdecomp:end func_00470D50 */
