#include "common.h"

/* localdecomp:start func_00308F20 */
typedef int Q_308F20 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_308F20;
typedef struct {
    V_308F20 v;
    u8 pad10[4];
    f32 x14;
    f32 x18;
    u8 pad1C[0x26 - 0x1C];
    s16 x26[7];
    s32 x34;
} S_308F20;
typedef struct {
    u8 pad0[0x10];
    V_308F20 pos;
    u8 pad20[0x68 - 0x20];
    S_308F20 *x68;
    u8 pad6C[0xF4 - 0x6C];
    f32 xF4;
    f32 xF8;
} O_308F20;
typedef struct { u8 pad[0x25C0]; s32 x25C0; } G_308F20;
typedef struct { V_308F20 a; V_308F20 b; V_308F20 c; } H_308F20;
extern G_308F20 D_001A4BE0;
extern H_308F20 D_001EAAA0;
extern void func_00440CF8(void *, f32, f32, f32);
extern s32 func_003F8448(void *, void *, s32, s32, s32);
extern s32 func_003F9498(void *, s32, s32, f32);
extern void func_0040C260(void *, void *, void *);
extern void func_0040C0F0(f32, void *, void *);
extern void func_00447D00(void *, void *, void *, f32, f32, s32, s32, s32, f32, f32, f32, f32, s32, f32, s32, s32, s32, s32, s32);
extern void func_00308E58(void *, void *, void *);
extern void func_00436220(void *);
extern s32 func_0040BAC0(void *);
extern void func_00444070(void *, f32);
void func_00308F20(O_308F20 *o) {
    V_308F20 old;
    V_308F20 dir = { 0.0f, 0.0f, 0.13333334f, 0.0f };
    V_308F20 col;
    S_308F20 *s = o->x68;
    V_308F20 *pold = &old;
    old = o->pos;
    func_00440CF8(s, s->x18, o->xF8, -o->xF4);
    {
        Q_308F20 q1, q2;
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(o->pos));
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(s->v));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(q2) : "j"(q1));
        __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(q2));
    }
    if (func_003F8448(pold, &o->pos, 0, D_001A4BE0.x25C0, 0) ||
        func_003F9498(&o->pos, 1, D_001A4BE0.x25C0, 0.3f)) {
        col = D_001EAAA0.a;
        func_0040C260(&dir, s, &D_001EAAA0.c);
        func_0040C0F0(0.033333335f, &dir, &dir);
        func_00447D00(o, &dir, &col, 0.0f, 0.0f, 0, 0, 4, 0.0f, 0.0f, 9.0f, 0.4f, -1, 0.0f, 0, 0, -1, 0, 0x01010001);
        func_00308E58(o, s, &col);
        func_00436220(o);
    } else if (o->pos.x < 2.0f || o->pos.x > 1021.0f || o->pos.y < 2.0f || o->pos.y > 1021.0f ||
               o->pos.z < 2.0f || o->pos.z > 1021.0f) {
        func_00436220(o);
    } else if (s->x34 == 0 && (func_0040BAC0(s->x26) != 0 || s->x14 < 0.0f)) {
        func_00447D00(o, &dir, 0, 0.0f, 0.0f, 0, 0, 4, 0.0f, 0.0f, 9.0f, 0.4f, -1, 0.0f, 0, 0, -1, 0, 0x01010001);
        func_00436220(o);
    } else {
        s->x14 -= s->x18;
        func_00444070(o, 0.2f);
    }
}
/* localdecomp:end func_00308F20 */
