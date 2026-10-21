#include "common.h"

/* localdecomp:start func_003788A8 */
typedef int Q_3788A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3788A8;

extern f32 func_00378850(void *a);
extern void func_0041C768(void *a, void *b, f32 f);

void func_003788A8(u8 *a, V4_3788A8 *b) {
    Q_3788A8 x, y, r;
    f32 f = func_00378850(a);
    func_0041C768(b, a + 0xC0, f);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3788A8 *)(a + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*b) : "j"(r));
}
/* localdecomp:end func_003788A8 */
