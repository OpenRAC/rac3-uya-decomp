#include "common.h"

/* localdecomp:start func_00424E20 */
typedef int Q_424E20 __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_424E20;
extern void func_003E4A38(float *, float *, void *);
extern void func_003E45B8(float *, float *, float);
void func_00424E20(u8 *o, float *v, float x, float y, float z) {
    Q_424E20 a, b, r;
    v[1] = y;
    v[2] = z;
    v[0] = x;
    func_003E4A38(v, v, o + 0xC0);
    func_003E45B8(v, v, *(float *)(o + 0x2C));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_424E20 *)(o + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V4_424E20 *)v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_424E20 *)v) : "j"(r));
}
/* localdecomp:end func_00424E20 */
