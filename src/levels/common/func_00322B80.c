#include "common.h"

/* localdecomp:start func_00322B80 */
typedef int Q_322B80 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_322B80;
extern void func_00440B30(void *, f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0046FE70(void *, void *, s32, f32);
void func_00322B80(V_322B80 *p) {
    V_322B80 a, b;
    Q_322B80 x, y, z, w, r;
    func_00440B30(&a, 0.025f, 0.15f);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*p));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("lqc2 %0, %1" : "=j"(z) : "m"(*p));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
    __asm__("lqc2 %0, %1" : "=j"(w) : "m"(a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(z), "j"(w));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(r));
    func_0040C0F0(&b, &b, 0.0125000011f);
    func_0046FE70(&a, &b, 15, 1.0f);
}
/* localdecomp:end func_00322B80 */
