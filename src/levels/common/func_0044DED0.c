#include "common.h"

/* localdecomp:start func_0044DED0 */
extern void func_0040C0F0(s32 a, s32 b, f32 x);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFBA8;
typedef int Q_3BFBA8 __attribute__((mode(TI)));
extern f32 D_001D6750;
extern void func_0040BE90(f32 *, void *, f32);
void func_0044DED0(void *a, f32 *out, s32 f) {
    Q_3BFBA8 p, q, r;
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(D_001D6750));
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(V4_3BFBA8 *)a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(p), "j"(q));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFBA8 *)out) : "j"(r));
    out[2] = 0;
    ((void (*)(void *, f32))func_0040C0F0)(out, 1.0f);
    if (f == 0) {
        func_0040BE90(out, out, -1.0f);
    }
}
/* localdecomp:end func_0044DED0 */
