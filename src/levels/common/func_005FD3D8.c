#include "common.h"

/* localdecomp:start func_005FD3D8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_5FD3D8;
typedef int Q_5FD3D8 __attribute__((mode(TI)));
extern void func_0058F5B0(V_5FD3D8 *, V_5FD3D8 *, f32);
extern f32 func_0058F3C0(V_5FD3D8 *, V_5FD3D8 *);
extern f32 func_0058F8B8(f32);
extern void func_0058F3E8(V_5FD3D8 *, V_5FD3D8 *, V_5FD3D8 *);
extern void func_005900F0(V_5FD3D8 *, V_5FD3D8 *, V_5FD3D8 *, f32);
extern void func_0058F358(V_5FD3D8 *, V_5FD3D8 *, f32);

void func_005FD3D8(u8 *self, V_5FD3D8 *out, V_5FD3D8 *in, f32 len, f32 unused, f32 ang) {
    V_5FD3D8 axis;
    V_5FD3D8 *fwd = (V_5FD3D8 *)(self + 0x3B0);
    Q_5FD3D8 x, y;
    f32 d;

    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*in));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V_5FD3D8 *)(self + 0x12B0)));
    __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
    func_0058F5B0(out, out, 1.0f);
    d = func_0058F3C0(out, fwd);
    if (d < func_0058F8B8(ang)) {
        func_0058F3E8(&axis, out, fwd);
        func_005900F0(out, fwd, &axis, ang);
        func_0058F5B0(out, out, len);
    } else {
        func_0058F358(out, out, len);
    }
}
/* localdecomp:end func_005FD3D8 */
