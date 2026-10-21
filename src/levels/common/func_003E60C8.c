#include "common.h"

/* localdecomp:start func_003E60C8 */
typedef int Q_003E60C8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E60C8;
extern V4_003E60C8 D_001EAAA0;
extern f32 func_0040BEF8(V4_003E60C8 *, s32);
s32 func_003E60C8(u8 *obj, s32 mode, V4_003E60C8 *vec) {
    if (mode == 1) {
        V4_003E60C8 t;
        Q_003E60C8 a, b, r;
        f32 f;
        s32 p = *(s32 *)(obj + 0x70);
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(D_001EAAA0));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*vec));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(t) : "j"(r));
        f = func_0040BEF8(&t, p + 0x180);
        if (f < 0.0f) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E60C8 */
