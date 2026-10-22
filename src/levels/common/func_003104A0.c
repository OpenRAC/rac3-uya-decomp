#include "common.h"

typedef int Q_3104A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3104A0;

extern void func_003E45B8(void *out, void *v, f32 s);

void func_003104A0(V4_3104A0 *out, V4_3104A0 *a, V4_3104A0 *b, f32 t) {
    V4_3104A0 tmp;
    Q_3104A0 x, y, r;
    func_003E45B8(&tmp, b, (t - a->z) / b->z);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(tmp));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(r));
}
