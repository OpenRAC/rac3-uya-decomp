#include "common.h"

/* localdecomp:start func_00630140 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_630140;
typedef int Q_630140 __attribute__((mode(TI)));
extern void func_0058FB48(V_630140 *, void *);
extern void func_0058F7B8(V_630140 *, V_630140 *, void *);

void func_00630140(u8 *self, V_630140 *out, V_630140 *in, f32 h) {
    V_630140 m[4];
    V_630140 off;
    Q_630140 x, y;

    switch (self[0x1A06]) {
    case 0:
        *(Q_630140 *)out = *(Q_630140 *)in;
        out->z += h;
        break;
    case 1:
    case 2:
        __asm__("sq $0,%0" : "=m"(off));
        off.z = h;
        func_0058FB48(m, *(u8 **)(self + 0x2524) + 0xF0);
        func_0058F7B8(&off, &off, m);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*in));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(off));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
        break;
    }
}
/* localdecomp:end func_00630140 */
