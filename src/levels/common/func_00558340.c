#include "common.h"

/* localdecomp:start func_00558340 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_558340;
typedef int Q_558340 __attribute__((mode(TI)));
extern f32 D_001DFB8C;
extern f32 func_0058F4B0(u8 *, u8 *);
extern void func_0058F5B0(V_558340 *, V_558340 *, f32);

s32 func_00558340(u8 *self, u8 *pos, V_558340 *out) {
    V_558340 d;
    V_558340 t;
    Q_558340 x, y;

    if (func_0058F4B0(pos + 0x10, *(u8 **)(self + 0x2524) + 0x10) < D_001DFB8C) {
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V_558340 *)(pos + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_558340 *)(*(u8 **)(self + 0x2524) + 0x10)));
        out->z = 0.0f;
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t) : "j"(x));
        *(Q_558340 *)&d = *(Q_558340 *)&t;
        out->x = -d.x;
        out->y = -d.y;
        func_0058F5B0(out, out, 1.0f);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00558340 */
