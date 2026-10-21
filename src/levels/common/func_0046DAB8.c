#include "common.h"

/* localdecomp:start func_0046DAB8 */
typedef int Q_46DAB8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_46DAB8;
typedef struct {
    u8 pad0[4];
    s32 i4;
    u8 b8, b9;
    s16 hA;
    s32 iC;
    V_46DAB8 v10;
    V_46DAB8 v20;
    V_46DAB8 v30;
} S_46DAB8;
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern f32 func_0040BF38(void *);
extern void func_0040C0F0(void *, void *, f32);
void func_0046DAB8(S_46DAB8 *o) {
    V_46DAB8 t0, t1;
    Q_46DAB8 x, y;
    V_46DAB8 *q;
    s32 c;
    f32 f;
    q = &o->v30;
    if (func_0040BAC0(&o->hA)) {
        func_0045E580(o);
        return;
    }
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v30));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v10));
    t0 = o->v10;
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(x));
    q->z = q->z - q->w;
    f = func_0040BF38(q);
    func_0040C0F0(&t1, q, f * 0.4f);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v10));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t1));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(o->v20) : "j"(x));
    o->v20.w = 1.0f;
    if (o->hA < o->b8) {
        c = ((s32)((f32)o->hA / (f32)o->b8 * 127.0f) << 24) | 0xFFFFFF;
        o->iC = c;
        o->i4 = c;
    }
}
/* localdecomp:end func_0046DAB8 */
