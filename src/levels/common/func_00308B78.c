#include "common.h"

/* localdecomp:start func_00308B78 */
typedef int Q_308B78 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_308B78;
extern void func_0043CE28(void *, s32, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2D0(void *, void *, void *);
void func_00308B78(u8 *obj, s32 a1, V4_308B78 *dst, V4_308B78 *src) {
    V4_308B78 t0[3] __attribute__((aligned(16)));
    V4_308B78 t1 __attribute__((aligned(16)));
    s32 t2;
    Q_308B78 a, b, c, d, e, f;
    f32 s;
    s = *(f32 *)(obj + 0x2C) * 0.0009765625f;
    t2 = a1;
    func_0043CE28(obj, 1, &t2, t0);
    func_0040BE90(dst, &t1, s);
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*src));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*dst));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*dst) : "j"(c));
    func_0040C2D0(dst, dst, obj + 0xC0);
    __asm__("lqc2 %0, %1" : "=j"(d) : "m"(*(V4_308B78 *)(obj + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(e) : "m"(*dst));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(f) : "j"(e), "j"(d));
    __asm__("sqc2 %1, %0" : "=m"(*dst) : "j"(f));
}
/* localdecomp:end func_00308B78 */
