#include "common.h"

/* localdecomp:start func_00313400 */
typedef int Q_313400 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_313400;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V2_313400;
typedef struct { u8 pad0[0x40]; u32 c0, c1, c2, c3; u8 pad1[0x20]; unsigned long f70, f78, f80, f88; f32 m[12]; V_313400 o; } P_313400;
extern V_313400 D_001E2AC0;
extern void func_00313310(P_313400 *);
extern unsigned long func_00401CD0(s32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040BFE8(V_313400 *, V_313400 *);
extern void func_0040C658(void *, V_313400 *);
extern void func_0040C0F0(f32, V_313400 *, V_313400 *);
extern void func_00313398(f32, void *);
extern void func_00405A58(void *, void *, s32);
void func_00313400(V_313400 *p, s32 a1, s32 a2, s32 a3, s32 a4, f32 fa, f32 fb, f32 fc) {
    P_313400 pk;
    V_313400 v, e;
    f32 d;
    u32 c;
    func_00313310(&pk);
    pk.f78 = func_00401CD0(a3);
    pk.f70 = 0;
    pk.f80 = 0xFF9000000260UL;
    pk.f88 = ((unsigned long)a4 << 2) | 0x8000000040UL;
    c = a1 + (a2 << 24);
    pk.c3 = c;
    pk.c2 = c;
    pk.c1 = c;
    pk.c0 = c;
    v.w = 0.0f;
    v.z = func_0040C490(D_001E2AC0.x - p->x, D_001E2AC0.y - p->y);
    d = func_0040BFE8(p, &D_001E2AC0);
    v.y = -func_0040C490(d, D_001E2AC0.z - p->z);
    v.x = fb;
    func_0040C658(pk.m, &v);
    {
        Q_313400 q1, q2, q3;
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*p));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(D_001E2AC0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(q3) : "j"(q2), "j"(q1));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(q3));
    }
    func_0040C0F0(fc, &e, &e);
    pk.o.x = p->x + e.x;
    pk.o.y = p->y + e.y;
    pk.o.z = p->z + e.z;
    pk.o.w = 1.0f;
    func_00313398(fa, &pk);
    func_00405A58(&pk, pk.m, 0);
}
/* localdecomp:end func_00313400 */
