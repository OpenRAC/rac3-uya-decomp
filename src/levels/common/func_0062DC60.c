#include "common.h"

/* localdecomp:start func_0062DC60 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_62DC60;
typedef int Q_62DC60 __attribute__((mode(TI)));
extern void func_0058FB48(V_62DC60 *, void *);
extern void func_0058FDD0(V_62DC60 *, V_62DC60 *);
extern void func_0058F7B8(V_62DC60 *, V_62DC60 *, V_62DC60 *);
extern f32 func_0058F980(f32, f32);

void func_0062DC60(u8 *self, V_62DC60 *in, f32 *out) {
    V_62DC60 m[4];
    V_62DC60 inv[4];
    V_62DC60 p;
    f32 len;

    *(Q_62DC60 *)&p = *(Q_62DC60 *)in;
    func_0058FB48(m, *(u8 **)(self + 0x2524) + 0xF0);
    func_0058FDD0(inv, m);
    func_0058F7B8(&p, &p, inv);
    __asm__("sqrt.s %0, %1" : "=f"(len) : "f"(p.x * p.x + p.z * p.z));
    out[0] = func_0058F980(len, p.y);
    out[1] = -func_0058F980(p.z, p.x);
}
/* localdecomp:end func_0062DC60 */
