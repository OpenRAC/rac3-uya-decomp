#include "common.h"

typedef int Q_3103F8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3103F8;

extern void func_003E45B8(void *out, void *v, f32 s);
extern f32 func_003E4620(void *a, void *b);

void func_003103F8(V4_3103F8 *out, V4_3103F8 *base, V4_3103F8 *dir, V4_3103F8 *p, void *n) {
    V4_3103F8 d;
    V4_3103F8 tmp;
    f32 f;
    {
        Q_3103F8 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*p));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*base));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
    }
    f = func_003E4620(n, &d);
    f = f / func_003E4620(n, dir);
    func_003E45B8(&tmp, dir, f);
    {
        Q_3103F8 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*base));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(tmp));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(r));
    }
}
