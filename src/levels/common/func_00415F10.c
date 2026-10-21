#include "common.h"

/* localdecomp:start func_00415F10 */
typedef int Q_415F10 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_415F10;
extern V4_415F10 D_001E2A40[];
extern V4_415F10 D_001EA810;
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
void func_00415F10(V4_415F10 *v) {
    V4_415F10 tmp __attribute__((aligned(16)));
    Q_415F10 a, b, c;
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(D_001E2A40[0]));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*v));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(c));
    func_0040C0F0(&D_001E2A40[2], &tmp, 1.0f);
    func_0040BF20(&D_001E2A40[3], &D_001E2A40[2], &D_001EA810);
    func_0040C0F0(&D_001E2A40[3], &D_001E2A40[3], 1.0f);
    func_0040BF20(&D_001E2A40[4], &D_001E2A40[2], &D_001E2A40[3]);
    func_0040C0F0(&D_001E2A40[4], &D_001E2A40[4], -1.0f);
}
/* localdecomp:end func_00415F10 */
