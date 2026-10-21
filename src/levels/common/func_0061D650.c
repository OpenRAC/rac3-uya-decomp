#include "common.h"

/* localdecomp:start func_0061D650 */
typedef int Q_61D650 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_61D650;
extern void func_0058F5B0(void *, void *, f32);
extern f32 func_0058F3C0(void *, void *);
extern f32 func_0058F8E8(f32);

f32 func_0061D650(V4_61D650 *pa, V4_61D650 *pb, V4_61D650 *pc) {
    V4_61D650 u;
    V4_61D650 v;
    Q_61D650 a, b, d, c, e, b2;

    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*pa));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*pb));
    __asm__("lqc2 %0, %1" : "=j"(c) : "m"(*pc));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(d) : "j"(a), "j"(b));
    __asm__("lqc2 %0, %1" : "=j"(b2) : "m"(*pb));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(e) : "j"(c), "j"(b2));
    __asm__("sqc2 %1, %0" : "=m"(u) : "j"(d));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(e));
    func_0058F5B0(&u, &u, 1.0f);
    func_0058F5B0(&v, &v, 1.0f);
    return 1.5707964f - func_0058F8E8(func_0058F3C0(&u, &v));
}
/* localdecomp:end func_0061D650 */
