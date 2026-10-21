#include "common.h"

typedef int Q_421438 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_421438;
extern void func_00437600(s32 a, s32 b, void *c);
extern void func_0040C0F0(void *a, void *b, f32 x);
extern void func_004082B0(void *a, s32 b, u32 c, s32 d, f32 e, f32 f, f32 g);

/* localdecomp:start func_00421438 */
void func_00421438(s32 a0) {
    V_421438 v[5];
    Q_421438 x, y;
    func_00437600(a0, 2, &v[1]);
    func_0040C0F0(&v[0], &v[1], 0.01f);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v[0]));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v[4]));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(v[0]) : "j"(x));
    func_004082B0(&v[0], 11, 0x15103080, 1, 0.1f, 0.08f, 0.0f);
}
/* localdecomp:end func_00421438 */
