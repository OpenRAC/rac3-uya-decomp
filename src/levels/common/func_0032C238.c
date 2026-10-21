#include "common.h"
typedef int Q_32C238 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32C238;
extern u8 *func_004C4520(void *);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040C0F0(void *, f32, void *);
extern void func_00447580(void *, void *);
extern void func_00437698(void *, int, void *);
extern void func_0040C2D0(void *, void *, void *);

/* localdecomp:start func_0032C238 */
void func_0032C238(u8 *obj, V4_32C238 *vec) {
    V4_32C238 a, b, c, d, e, f, g;
    Q_32C238 p, q, r;
    u8 *o;
    o = func_004C4520(*(void **)(*(u8 **)(obj + 104) + 72));
    *(Q_32C238 *)&e = 0;
    e.z = 1.0f;
    *(Q_32C238 *)&d = *(Q_32C238 *)vec;
    *(Q_32C238 *)&a = *(Q_32C238 *)vec;
    func_0040BF20(&b, &a, &e);
    func_0040C0F0(&b, 1.0f, &b);
    func_0040BF20(&c, &b, &a);
    func_00447580(o + 16, &a);
    func_00437698(obj, 0, &f);
    func_0040C2D0(&d, vec, obj + 192);
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(d));
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(f));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(p), "j"(q));
    __asm__("sqc2 %1, %0" : "=m"(g) : "j"(r));
}
/* localdecomp:end func_0032C238 */
