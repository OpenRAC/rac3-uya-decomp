#include "common.h"

/* localdecomp:start func_0044DBC8 */
typedef int Q_0044DBC8 __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_0044DBC8;
typedef struct {
    u8 pad[0xC0];
    float w[4];
} S_0044DBC8;
extern void func_0040C2D0(V4_0044DBC8 *, V4_0044DBC8 *, float *);
void func_0044DBC8(S_0044DBC8 *p, V4_0044DBC8 *d, float x, float y, float z) {
    V4_0044DBC8 t;
    Q_0044DBC8 a, b, r;
    t.x = x;
    t.y = y;
    t.z = z;
    func_0040C2D0(&t, &t, p->w);
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*d));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(t));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(r));
}
/* localdecomp:end func_0044DBC8 */
