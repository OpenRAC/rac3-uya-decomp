#include "common.h"

/* localdecomp:start func_0044C000 */
typedef int Q_44C000 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_44C000;
typedef struct {
    u8 pad0[48];
    V4_44C000 v48;
    u8 *p64;
    u8 pad68[8];
    u8 b76;
} O_44C000;
extern void func_0040C2D0(V4_44C000 *, void *, s32);
void func_0044C000(V4_44C000 *out, O_44C000 *o, V4_44C000 *base, s32 a, s32 b) {
    V4_44C000 t;
    Q_44C000 y, x;

    func_0040C2D0(&t, &o->v48, a);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*base));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
    __asm__("vadd.wxyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
    if (o->p64) {
        switch (o->b76 & 0x30) {
        case 0x10:
            func_0040C2D0(&t, o->p64 + 16, a);
            __asm__ __volatile__("lqc2 %0, %2\n\tlqc2 %1, %3" : "=j"(x), "=j"(y) : "m"(*out), "m"(t));
            break;
        case 0x20:
            func_0040C2D0(&t, o->p64 + 16, b);
            __asm__ __volatile__("lqc2 %0, %2\n\tlqc2 %1, %3" : "=j"(x), "=j"(y) : "m"(*out), "m"(t));
            break;
        default:
            __asm__ __volatile__("lqc2 %0, %2\n\tlqc2 %1, %3" : "=j"(x), "=j"(y) : "m"(*out), "m"(*(V4_44C000 *)(o->p64 + 16)));
            break;
        }
        __asm__("vadd.wxyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
    }
}
/* localdecomp:end func_0044C000 */
