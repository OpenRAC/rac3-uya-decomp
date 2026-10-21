#include "common.h"
typedef int Q_3D4420 __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_3D4420;
extern void func_0040C2D0(float *, float *, void *);
/* localdecomp:start func_003D4420 */
void func_003D4420(V4_3D4420 *o, void *m, V4_3D4420 *out, float x, float y, float z) {
    Q_3D4420 a, b;
    out->x = x;
    out->y = y;
    out->z = z;
    func_0040C2D0((float *)out, (float *)out, m);
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*o));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*out));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(b) : "j"(b), "j"(a));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(b));
}
/* localdecomp:end func_003D4420 */
