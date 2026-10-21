#include "common.h"

/* localdecomp:start func_003443F0 */
typedef int Q_3443F0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3443F0;
extern void func_0040C2D0(void *, void *, void *);
extern void func_004076F8(void *, u32, s32);
extern void func_00407A60(void *, void *, u32, s32, f32, f32);
void func_003443F0(u8 *obj) {
    V4_3443F0 tmp __attribute__((aligned(16)));
    Q_3443F0 a, b, c, z;
    u8 *q;
    u32 col = 0x103080;
    __asm__("por %0, $0, $0" : "=r"(z));
    *(Q_3443F0 *)&tmp = z;
    tmp.x = -0.3f;
    tmp.w = 1.0f;
    q = *(u8 **)(obj + 0x68);
    func_0040C2D0(&tmp, &tmp, obj + 0xC0);
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V4_3443F0 *)(obj + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(tmp));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(b), "j"(a));
    __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(c));
    if (q[0x81]) col = 0x803010;
    func_004076F8(&tmp, col, 0);
    func_00407A60(&tmp, q + 0x10, col, 4, *(f32 *)(q + 0x64), 0.25f);
}
/* localdecomp:end func_003443F0 */
