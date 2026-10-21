#include "common.h"

/* localdecomp:start func_004445E0 */
typedef int Q_4445E0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4445E0;
typedef struct {
    u8 pad0[16];
    f32 x, y;
} O_4445E0;
typedef struct {
    f32 a, b, c, d;
    void *e;
    s32 f;
    u8 g, h;
    u16 i;
    f32 j;
    s32 k;
    s32 pad;
    s32 m;
} L_4445E0;
extern f32 func_0040C490(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_00443840(void *, void *);

void func_004445E0(u8 *a0, Q_4445E0 *a1, O_4445E0 **a2, s32 n, void *t0, s32 t1, s32 t2, s32 t3, f32 f12, f32 f13, f32 f14, s32 stk) {
    V4_4445E0 v;
    L_4445E0 l;
    f32 *vp = (f32 *)&v;
    *(Q_4445E0 *)&v = *a1;
    if (n > 0) {
        O_4445E0 **p = a2;
        s32 i = n;
        do {
            if ((void *)*p != t0) {
                f32 ang;
                l.e = a0;
                l.i = *(u16 *)(a0 + 0xAA);
                l.f = t1;
                l.j = f12;
                l.k = t1;
                l.g = t2;
                l.h = t3;
                l.m = stk;
                ang = func_0040C490((*p)->x - vp[0], (*p)->y - vp[1]);
                l.a = func_0040C3C8(ang) * f13;
                l.b = func_0040C3E0(ang) * f13;
                l.c = f14;
                l.d = 5627.9248f;
                func_00443840(*p, &l);
            }
            p++;
        } while (--i != 0);
    }
}
/* localdecomp:end func_004445E0 */
