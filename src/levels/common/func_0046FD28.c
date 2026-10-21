#include "common.h"

/* localdecomp:start func_0046FD28 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_46FD28;
typedef int Q_46FD28 __attribute__((mode(TI)));
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    V_46FD28 v10;
    V_46FD28 v20;
} S_46FD28;
typedef struct {
    V_46FD28 v;
    s32 i10;
    s32 w14;
    s32 i18;
} E_46FD28;
extern s32 func_0040D020(s32, s32, f32);
extern f32 func_004408C0(f32, f32);
extern void func_0040BE90(void *, void *, f32);
extern void func_004C6EC8(void *, void *);
extern void func_004C6FD8(void *, void *);
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
void func_0046FD28(S_46FD28 *o) {
    s32 n, c;
    f32 r;
    Q_46FD28 x, y;
    V_46FD28 *a = &o->v10;
    E_46FD28 *b = (E_46FD28 *)&o->v20;
    r = (f32)o->hA / (f32)b->i18;
    n = (s32)((f32)b->i10 * r);
    c = func_0040D020(0, b->w14, r * 0.5f);
    o->b8 = o->b8 + 1;
    o->fC += func_004408C0(0.004f, 0.012f) * 210000.0f;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v20));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v10));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(x));
    func_0040BE90(b, b, 0.99f);
    func_004C6EC8(a, a);
    func_004C6FD8(b, b);
    o->w4 = c | (n << 24);
    if (func_0040BAC0(&o->hA)) {
        func_0045E580(o);
    }
}
/* localdecomp:end func_0046FD28 */
