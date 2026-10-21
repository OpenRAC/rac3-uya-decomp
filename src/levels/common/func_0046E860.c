#include "common.h"

typedef int Q_46E860 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_46E860;
typedef struct {
    V_46E860 v0;
    s32 f10;
    s32 f14;
} P_46E860;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 b8;
    u8 pad9;
    s16 hA;
    u8 padC[4];
    V_46E860 v10;
    P_46E860 p;
} O_46E860;

extern V_46E860 D_001E2A40;
extern f32 D_001E0340;
extern V_46E860 D_001E2A70;
extern s32 D_001E0334;
extern s32 D_001DFBC0;
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern void func_004C6EC8(V_46E860 *, V_46E860 *);
extern f32 func_0040C3E0(f32);
extern void func_0040BE90(V_46E860 *, V_46E860 *, f32);

/* localdecomp:start func_0046E860 */
void func_0046E860(O_46E860 *o)
{
    P_46E860 *p;
    V_46E860 t;
    Q_46E860 x1, x2, r1, y1, y2, r2, z1, z2, r3;
    s32 n;
    s32 c;
    s32 h;
    f32 ang;
    f32 d;

    d = *(f32 *)((u8 *)o + 0x18) - D_001E2A40.z;
    p = &o->p;
    if (d < -7.0f || (p->f14 != 0 && func_0040BAC0((u8 *)o + 0xA) != 0)) {
        n = p->f10 - 1;
        p->f10 = n;
        if (n <= 0) {
            func_0045E580(o);
            D_001E0334 = D_001E0334 - 1;
            return;
        }
        o->f4 = (o->f4 & 0xFFFFFF) + (n << 24);
    } else {
        c = o->f4;
        if ((c >> 24) < p->f10) {
            o->f4 = c + 0x1000000;
        }
    }
    if (((s32)o & 0x80) == 0) {
        o->b8 = o->b8 + 2;
    } else {
        o->b8 = o->b8 - 2;
    }
    __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(p->v0));
    __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(o->v10));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(x1), "j"(x2));
    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(r1));
    __asm__("lqc2 %0, %1" : "=j"(y1) : "m"(o->v10));
    __asm__("lqc2 %0, %1" : "=j"(y2) : "m"(D_001E0340));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r2) : "j"(y1), "j"(y2));
    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(r2));
    func_004C6EC8(&o->v10, &o->v10);
    if (p->f14 == 0) {
        h = o->hA;
        ang = (f32)(D_001DFBC0 & (h - 1)) / (f32)h * 6.2831855f;
        d = func_0040C3E0(ang) * 0.016666668f;
        func_0040BE90(&t, &D_001E2A70, d);
        __asm__("lqc2 %0, %1" : "=j"(z2) : "m"(o->v10));
        __asm__("lqc2 %0, %1" : "=j"(z1) : "m"(t));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r3) : "j"(z1), "j"(z2));
        __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(r3));
    }
}
/* localdecomp:end func_0046E860 */
