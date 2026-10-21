#include "common.h"

/* localdecomp:start func_002FB318 */
typedef int Q_2FB318 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_2FB318;
typedef struct {
    u8 pad0[16];
    V4_2FB318 pos;
    u8 pad32[72];
    void *p104;
} O_2FB318;
extern s32 D_001DFBC0[];
extern void func_0040BE90(void *, void *, f32);
extern void func_00440A88(void *, f32, f32);
extern f32 func_004408C0(f32, f32);
extern s32 func_0040D020(s32, s32, f32);
extern void func_0044E088(void *, void *, void *, f32);
extern void func_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_002FB318(O_2FB318 *o) {
    void *p = o->p104;
    V4_2FB318 *q;
    V4_2FB318 *r;
    V4_2FB318 t0, t1, t2;
    Q_2FB318 x, y;
    s32 i;
    s32 c1, c2, n2, n1, n0;

    if (D_001DFBC0[0] & 7) {
        return;
    }
    r = &t2;
    q = &t0;
    for (i = 0; i < 1; i++) {
        func_0040BE90(&t0, p, 0.5f);
        func_00440A88(r, 0.0f, 0.016666668f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t2));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t0));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(y));
        __asm__("sq $0,%0" : "=m"(t1));
        t0.w = func_004408C0(0.25f, 0.15f);
        t1.w = func_004408C0(0.15f, 0.05f);
        c1 = func_0040D020(0x804080FF, 0x8040FFFF, func_004408C0(0.0f, 1.0f));
        c2 = func_0040D020(0x80104040, 0x80002080, func_004408C0(0.0f, 1.0f));
        n2 = func_004408C0(0.0f, 1.0f) + 1.0f;
        n1 = (func_004408C0(-0.5f, 0.5f) + 1.0f) * 30.0f;
        n0 = (func_004408C0(-0.5f, 0.5f) + 1.0f) * 10.0f;
        func_0044E088(&o->pos, &t1, &t1, (f32)n1 * 0.0011111111f);
        func_0045FEC8(&o->pos, q, &t1, c1, c2, n2, n1, n0, 0x10019);
    }
}
/* localdecomp:end func_002FB318 */
