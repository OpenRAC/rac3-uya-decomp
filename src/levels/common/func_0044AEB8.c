#include "common.h"

/* localdecomp:start func_0044AEB8 */
typedef int Q_44AEB8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_44AEB8;
extern void func_0040C328(void *, s32);
extern void func_0040BE90(void *, void *, f32);
void func_0044AEB8(void *obj, s32 *src) {
    V4_44AEB8 a;
    V4_44AEB8 b;
    Q_44AEB8 x, y;
    f32 w;
    __asm__("por %0, $0, $0" : "=r"(*(Q_44AEB8 *)&b));
    b.x = 127.0f;
    b.y = 127.0f;
    b.z = 127.0f;
    func_0040C328(&a, *src);
    w = a.w;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
    func_0040BE90(obj, &a, w * 0.0001f);
}
/* localdecomp:end func_0044AEB8 */
