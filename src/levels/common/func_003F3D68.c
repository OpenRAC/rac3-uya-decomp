#include "common.h"

/* localdecomp:start func_003F3D68 */
typedef int Q_3F3D68 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3F3D68;
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
void func_003F3D68(V4_3F3D68 *o, f32 *p, V4_3F3D68 *v) {
    Q_3F3D68 x, y;
    o->x = p[2] * func_0040C3C8(p[1]) * func_0040C3C8(p[0]);
    o->y = p[2] * func_0040C3C8(p[1]) * func_0040C3E0(p[0]);
    o->z = p[2] * func_0040C3E0(p[1]);
    o->w = 0;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*v));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*o));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*o) : "j"(x));
}
/* localdecomp:end func_003F3D68 */
