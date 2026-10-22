#include "common.h"

/* localdecomp:start func_00630320 */
typedef int Q_630320 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_630320;
extern void func_0058F5B0(void *, void *, f32);
extern f32 func_0058F3C0(void *, void *);
extern void func_0058F358(void *, void *, f32);
static __inline__ void vsub_630320(V4_630320 *out, V4_630320 *in, V4_630320 *t) {
    Q_630320 a, b, r;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*in));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*t));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(r));
}

void func_00630320(u8 *o, V4_630320 *out, V4_630320 *in) {
    V4_630320 t;

    switch (o[0x1A06]) {
    case 0:
        *(Q_630320 *)out = *(Q_630320 *)in;
        *(s32 *)&out->z = 0;
        break;
    case 1:
        func_0058F5B0(&t, o + 0x230, 1.0f);
        func_0058F358(&t, &t, func_0058F3C0(&t, in));
        vsub_630320(out, in, &t);
        break;
    case 2:
        func_0058F358(&t, o + 0x250, func_0058F3C0(o + 0x250, in));
        vsub_630320(out, in, &t);
        break;
    }
}
/* localdecomp:end func_00630320 */
