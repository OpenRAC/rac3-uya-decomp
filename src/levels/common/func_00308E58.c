#include "common.h"

/* localdecomp:start func_00308E58 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_308E58;
typedef struct {
    V4_308E58 v0;
    void *p10;
    u32 f14;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 i20;
} R_308E58;
typedef struct {
    V4_308E58 v0;
    u8 pad10[28];
    f32 f2C;
    f32 f30;
} B_308E58;
typedef struct {
    u8 pad0[0xAA];
    u16 hAA;
} O_308E58;
extern void *D_001A71A0[];
extern void func_0040C140(void *, void *, f32);
extern s32 func_003FB1D0(void *, s32, void *, void *, f32);
void func_00308E58(O_308E58 *o, B_308E58 *b, void *c) {
    R_308E58 r;
    r.p10 = o;
    r.f14 = 0x10000;
    r.f1C = b->f2C;
    r.i20 = 1;
    r.v0 = b->v0;
    func_0040C140(&r.v0, &r.v0, 1.0f);
    r.v0.z = 1.0f;
    r.v0.w = 5627.9248f;
    r.b18 = 3;
    r.b19 = 2;
    r.h1A = o->hAA;
    func_003FB1D0(c, 1, D_001A71A0[0], &r, b->f30);
}
/* localdecomp:end func_00308E58 */
