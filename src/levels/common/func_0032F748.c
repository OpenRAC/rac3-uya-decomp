#include "common.h"

/* localdecomp:start func_0032F748 */
typedef int Q_32F748 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_32F748;
typedef struct {
    V_32F748 rows[4];
    u32 c0, c1, c2, c3;
    V_32F748 a, b;
    unsigned long f70, f78, f80, f88;
    f32 m[12];
    V_32F748 o;
} P_32F748;
typedef struct { u8 pad[0x140]; V_32F748 v; } G_32F748;
extern G_32F748 D_001E2900;
extern void func_0032F6B8(P_32F748 *);
extern unsigned long func_00401CD0(s32);
extern s32 func_00440878(s32, s32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040BFE8(V_32F748 *, V_32F748 *);
extern f32 func_00440978(void);
extern f32 func_004408C0(f32, f32);
extern void func_0040C658(void *, V_32F748 *);
extern void func_0040C0F0(f32, V_32F748 *, V_32F748 *);
extern void func_0040BE90(V_32F748 *, V_32F748 *, f32);
extern void func_00405A58(void *, void *, s32);
void func_0032F748(s32 unused, V_32F748 *p) {
    P_32F748 pk;
    V_32F748 v, e;
    f32 d, sc;
    s32 col;
    func_0032F6B8(&pk);
    pk.f78 = func_00401CD0(0x2C);
    pk.f80 = 0xFF9000000260UL;
    pk.f88 = 0x8000000048UL;
    pk.f70 = 0;
    col = (func_00440878(48, 64) << 24) + 0x8183F;
    pk.c3 = col;
    pk.c2 = col;
    pk.c1 = col;
    pk.c0 = col;
    v.w = 0.0f;
    v.z = func_0040C490(D_001E2900.v.x - p->x, D_001E2900.v.y - p->y);
    d = func_0040BFE8(p, &D_001E2900.v);
    v.y = -func_0040C490(d, D_001E2900.v.z - p->z);
    v.x = func_00440978();
    func_0040C658(pk.m, &v);
    {
        Q_32F748 q1, q2, q3;
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
    sc = func_004408C0(0.3f, 0.4f);
    func_0040BE90(&pk.rows[0], &pk.rows[0], sc);
    func_0040BE90(&pk.rows[1], &pk.rows[1], sc);
    func_0040BE90(&pk.rows[2], &pk.rows[2], sc);
    func_0040BE90(&pk.rows[3], &pk.rows[3], sc);
    func_00405A58(&pk, pk.m, 0);
    func_0040BE90(&pk.rows[0], &pk.rows[0], 0.5f);
    func_0040BE90(&pk.rows[1], &pk.rows[1], 0.5f);
    func_0040BE90(&pk.rows[2], &pk.rows[2], 0.5f);
    func_0040BE90(&pk.rows[3], &pk.rows[3], 0.5f);
    col = (func_00440878(64, 127) << 24) + 0x103080;
    pk.c3 = col;
    pk.c2 = col;
    pk.c1 = col;
    pk.c0 = col;
    func_00405A58(&pk, pk.m, 0);
    func_0040BE90(&pk.rows[0], &pk.rows[0], 0.5f);
    func_0040BE90(&pk.rows[1], &pk.rows[1], 0.5f);
    func_0040BE90(&pk.rows[2], &pk.rows[2], 0.5f);
    func_0040BE90(&pk.rows[3], &pk.rows[3], 0.5f);
    col = (func_00440878(64, 127) << 24) + 0x7F7F7F;
    pk.c3 = col;
    pk.c2 = col;
    pk.c1 = col;
    pk.c0 = col;
    func_00405A58(&pk, pk.m, 0);
}
/* localdecomp:end func_0032F748 */
