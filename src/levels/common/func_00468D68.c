#include "common.h"

/* localdecomp:start func_00468D68 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_468D68;
typedef int Q_468D68 __attribute__((mode(TI)));
typedef struct { u8 pad0[10]; u8 fA[6]; V_468D68 f10; V_468D68 f20; s32 f30; } S_468D68;
extern V_468D68 D_001A4C60;
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
void func_00468D68(S_468D68 *o) {
    Q_468D68 x, y;
    if (o->f30 == 1) {
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->f20));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001A4C60));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(o->f10) : "j"(x));
    }
    if (func_0040BAC0(&o->fA) != 0) {
        func_0045E580(o);
    }
}
/* localdecomp:end func_00468D68 */
