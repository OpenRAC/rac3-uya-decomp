#include "common.h"
typedef int Q_44DB68 __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_44DB68;
extern void func_0040C2D0(float *, float *, void *);
/* localdecomp:start func_0044DB68 */
void func_0044DB68(char *obj, V4_44DB68 *out, float x, float y, float z) {
    V4_44DB68 *o = (V4_44DB68 *)(obj + 16);
    Q_44DB68 a, b;
    out->x = x;
    out->y = y;
    out->z = z;
    func_0040C2D0((float *)out, (float *)out, obj + 192);
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*o));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*out));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(b) : "j"(b), "j"(a));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(b));
}
/* localdecomp:end func_0044DB68 */
