#include "common.h"

/* localdecomp:start func_00305AD0 */
typedef int Q_305AD0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_305AD0;
typedef struct {
    V_305AD0 rows[4];
    u32 c0, c1, c2, c3;
    V_305AD0 a, b;
    unsigned long f70, f78, f80, f88;
    f32 m[12];
    V_305AD0 o;
} P_305AD0;
typedef struct { u8 pad[0x140]; V_305AD0 v; } G_305AD0;
extern G_305AD0 D_001E2900;
extern void func_003059F0(P_305AD0 *);
extern unsigned long func_00401CD0(s32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040BFE8(V_305AD0 *, V_305AD0 *);
extern f32 func_00440978(void);
extern void func_0040C658(void *, V_305AD0 *);
extern void func_0040C0F0(f32, V_305AD0 *, V_305AD0 *);
extern void func_0040BE90(f32, V_305AD0 *, V_305AD0 *);
extern void func_00405A58(void *, void *, s32);
void func_00305AD0(s32 unused, V_305AD0 *p, s32 col, f32 sc) {
    P_305AD0 pk;
    V_305AD0 v, e;
    f32 d;
    func_003059F0(&pk);
    pk.a.x = 0.0f;
    pk.a.w = 1.0f;
    pk.b.x = 1.0f;
    pk.b.z = 1.0f;
    pk.b.w = 1.0f;
    pk.a.y = 0.0f;
    pk.a.z = 0.0f;
    pk.b.y = 0.0f;
    pk.f78 = func_00401CD0(0x2C);
    pk.f80 = 0xFF9000000260UL;
    pk.f88 = 0x8000000048UL;
    pk.c3 = col;
    pk.c2 = col;
    pk.c1 = col;
    pk.c0 = col;
    pk.f70 = 0;
    v.w = 0.0f;
    v.z = func_0040C490(D_001E2900.v.x - p->x, D_001E2900.v.y - p->y);
    d = func_0040BFE8(p, &D_001E2900.v);
    v.y = -func_0040C490(d, D_001E2900.v.z - p->z);
    v.x = func_00440978();
    func_0040C658(pk.m, &v);
    {
        Q_305AD0 q1, q2, q3;
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*p));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(D_001E2900.v));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(q3) : "j"(q2), "j"(q1));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(q3));
    }
    func_0040C0F0(0.25f, &e, &e);
    pk.o.x = p->x + e.x;
    pk.o.y = p->y + e.y;
    pk.o.z = p->z + e.z;
    pk.o.w = 1.0f;
    func_0040BE90(sc, &pk.rows[0], &pk.rows[0]);
    func_0040BE90(sc, &pk.rows[1], &pk.rows[1]);
    func_0040BE90(sc, &pk.rows[2], &pk.rows[2]);
    func_0040BE90(sc, &pk.rows[3], &pk.rows[3]);
    func_00405A58(&pk, pk.m, 0);
}
/* localdecomp:end func_00305AD0 */
