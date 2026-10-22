#include "common.h"

/* localdecomp:start func_00558750 */
typedef int Q_00558750 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00558750;
extern f32 func_0058F8B8(f32);
extern f32 func_0058F8D0(f32);
extern void func_0058F5B0(void *, void *, f32);
extern f32 D_001DFBF4;
extern f32 *D_001DFB74;

void func_00558750(u8 *a0, u8 *a1) {
    f32 v[4] __attribute__((aligned(16)));
    u8 *o = *(u8 **)(a1 + 0x68);
    u8 *t = *(u8 **)(a0 + 0x68);
    f32 s, c;
    Q_00558750 x, y;
    s = func_0058F8B8(*(f32 *)(*(u8 **)(*(u8 **)(o + 8) + 0x2524) + 0xF8)) * D_001DFBF4;
    v[0] = s;
    c = func_0058F8D0(*(f32 *)(*(u8 **)(*(u8 **)(o + 8) + 0x2524) + 0xF8)) * D_001DFBF4;
    *(s32 *)&v[2] = 0;
    v[0] = -v[0];
    v[1] = -c;
    func_0058F5B0(v, v, *D_001DFB74);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_00558750 *)(t + 0x330)));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_00558750 *)v));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_00558750 *)(t + 0x350)) : "j"(x));
}
/* localdecomp:end func_00558750 */
