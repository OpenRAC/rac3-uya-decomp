#include "common.h"

/* localdecomp:start func_003AC458 */
typedef int Q_3AC458 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3AC458;
typedef struct {
    s32 p0;
    u8 pad4[12];
    u8 v16[16];
    f32 f32_;
} E_3AC458;
typedef struct {
    u8 pad0[52];
    s32 n52;
    E_3AC458 *p56;
} T_3AC458;
typedef struct {
    u8 pad0[100];
    s32 p100;
    T_3AC458 *t104;
    u8 pad108[3212];
    s32 i3320;
} A_3AC458;
typedef struct {
    u8 pad0[192];
    u8 v192[16];
    u8 pad208[40];
    f32 f248;
} O_3AC458;
typedef struct {
    u8 pad0[170];
    s16 h170;
} B_3AC458;
typedef struct {
    s32 f0;
    void (*fn)(void *, void *, s32, f32);
} VT_3AC458;
extern void func_0040C2D0(void *, void *, void *);
extern void func_00437698(s32, s32, void *);
extern f32 func_0040CEC8(f32, f32);
extern VT_3AC458 *func_00438488(s32, s32, s32);
void func_003AC458(O_3AC458 *o, A_3AC458 *a, B_3AC458 *b) {
    T_3AC458 *t = a->t104;
    E_3AC458 *e = (E_3AC458 *)((u8 *)t->p56 + a->i3320 * 48);
    V4_3AC458 r;
    V4_3AC458 v;
    Q_3AC458 x, y;
    f32 f;
    func_0040C2D0(&v, e->v16, o->v192);
    v.x = v.x * 0.5f;
    v.y = v.y * 0.5f;
    func_00437698(a->p100, e->p0, &r);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(r));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(r) : "j"(x));
    f = func_0040CEC8(e->f32_, o->f248);
    func_00438488(b->h170, 2, 12)->fn(b, &r, a->p100, f);
    a->i3320 = (a->i3320 + 1) % t->n52;
}
/* localdecomp:end func_003AC458 */
