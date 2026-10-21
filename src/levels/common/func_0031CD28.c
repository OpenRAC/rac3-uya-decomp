#include "common.h"

/* localdecomp:start func_0031CD28 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_31CD28;
typedef int Q_31CD28 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x10]; V_31CD28 f10; u8 pad20[0xC0 - 0x20]; } S_31CD28;
extern s32 D_001DC8A0;
extern void func_0040C2D0(void *, void *, void *);
void func_0031CD28(S_31CD28 *obj, V_31CD28 *v) {
    Q_31CD28 x, y;
    func_0040C2D0(v, &D_001DC8A0, (u8 *)obj + 0xC0);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(obj->f10));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*v) : "j"(x));
}
/* localdecomp:end func_0031CD28 */
