#include "common.h"

/* localdecomp:start func_0046A9C8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_46A9C8;
typedef int Q_46A9C8 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    V_46A9C8 v10;
    u8 pad20[0xA0];
    u8 mC0[0x40];
} O_46A9C8;
typedef struct {
    s32 w0;
    u8 pad4[8];
    u16 hC;
} A_46A9C8;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    u16 hA;
    s32 wC;
    V_46A9C8 v10;
} S_46A9C8;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    O_46A9C8 *wC;
    f32 f10;
    f32 f14;
    f32 f18;
    A_46A9C8 *w1C;
} E_46A9C8;
extern u8 *D_00221240[];
extern S_46A9C8 *func_0045E438(s32);
extern u8 func_0013D3E0(void);
extern void func_0040C8E0(void *, void *);
extern void func_0040C2F8(void *, void *, void *);
S_46A9C8 *func_0046A9C8(O_46A9C8 *a0, V_46A9C8 *a1, f32 *a2, A_46A9C8 *a3, s32 t0) {
    S_46A9C8 *p = func_0045E438(0x4A);
    E_46A9C8 *e;
    if (p != 0) {
        p->b9 = 0xA0;
        p->b3 = t0 ? 0x48 : 0x44;
        p->b1 = 0;
        p->b2 = *D_00221240[0];
        p->b8 = func_0013D3E0();
        p->wC = 0;
        p->v10 = *a1;
        e = (E_46A9C8 *)((u8 *)p + 0x20);
        e->f0 = a2[0];
        e->f4 = a2[1];
        e->f8 = a2[2];
        if (a0 != 0) {
            V_46A9C8 v;
            V_46A9C8 m[4];
            Q_46A9C8 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a0->v10));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a1));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(v) : "j"(x));
            __asm__("sq $0,%0" : "=m"(m[0]));
            __asm__("sq $0,%0" : "=m"(m[1]));
            __asm__("sq $0,%0" : "=m"(m[2]));
            __asm__("sq $0,%0" : "=m"(m[3]), "+r"(a0));
            func_0040C8E0(m, a0->mC0);
            func_0040C2F8(&v, &v, m);
            e->f10 = v.x;
            e->f14 = v.y;
            e->f18 = v.z;
        }
        e->wC = a0;
        e->w1C = a3;
        p->hA = a3->hC;
        p->w4 = a3->w0;
    }
    return p;
}
/* localdecomp:end func_0046A9C8 */
