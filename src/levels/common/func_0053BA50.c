#include "common.h"

/* localdecomp:start func_0053BA50 */
typedef int Q_0053BA50 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0053BA50;
extern void func_0058F5B0(void *, void *, f32);

void func_0053BA50(u8 *a0, V4_0053BA50 *a1, f32 f) {
    u8 *p = *(u8 **)(a0 + 0x68);
    V4_0053BA50 v;
    Q_0053BA50 x, y;
    if (*(s16 *)(p + 0x36) != -1) {
        a1->z += f;
        return;
    }
    func_0058F5B0(&v, p + 0x20, f);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a1));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*a1) : "j"(x));
}
/* localdecomp:end func_0053BA50 */
