#include "common.h"

typedef int Q_46DE20 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_46DE20;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 b14;
    u8 b15;
} E_46DE20;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 b8;
    u8 pad9[7];
    V_46DE20 v10;
    E_46DE20 e20;
} O_46DE20;

extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern void func_004C6EC8(void *, void *);
extern void func_004C41E8(void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern s32 D_001D673C[];

/* localdecomp:start func_0046DE20 */
void func_0046DE20(O_46DE20 *o) {
    if (func_0040BAC0((u8 *)o + 0xA) != 0) {
        func_0045E580(o);
        return;
    }
    {
        E_46DE20 *e = &o->e20;
        V_46DE20 t;
        V_46DE20 t2;
        Q_46DE20 a, b;
        o->f4 = (o->f4 & 0xFFFFFF) | (((o->f4 >> 24) + e->b14) << 24);
        t.x = e->f0;
        t.w = 0.0f;
        t.y = e->f4;
        t.z = e->f8;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(o->v10));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(t));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(a) : "memory");
        func_004C6EC8(&o->v10, &o->v10);
        if (D_001D673C[0] == 0) {
            e->f8 = e->f8 - e->fC;
        } else {
            Q_46DE20 c, d;
            func_004C41E8(&o->v10, &t2);
            func_0040C0F0(&t2, &t2, -e->fC);
            __asm__("lqc2 %0, %1" : "=j"(c) : "m"(o->v10));
            __asm__("lqc2 %0, %1" : "=j"(d) : "m"(t2));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(c), "j"(d));
            __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(c));
        }
        o->b8 = o->b8 + e->b15;
        *(f32 *)((u8 *)o + 0xC) = *(f32 *)((u8 *)o + 0xC) + e->f10;
    }
}
/* localdecomp:end func_0046DE20 */
