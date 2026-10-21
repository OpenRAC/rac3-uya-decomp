#include "common.h"

typedef int Q_366808 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_366808;
extern s32 D_001D545C;
extern V_366808 D_001E1D60;
extern V_366808 D_001E1D70;
extern f32 func_0040BFB0(void *a, void *b);
extern void func_0040C0F0(void *a, void *b, f32 x);

/* localdecomp:start func_00366808 */
void func_00366808(void) {
    V_366808 t;
    Q_366808 x, y;
    f32 lim = (D_001D545C == 11) ? 80.0f : 40.0f;
    if (func_0040BFB0(&D_001E1D60, &D_001E1D70) >= lim) {
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E1D70));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E1D60));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t) : "j"(x));
        func_0040C0F0(&t, &t, (D_001D545C == 11) ? 80.0f : 40.0f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E1D60));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(D_001E1D70) : "j"(x));
    }
}
/* localdecomp:end func_00366808 */
