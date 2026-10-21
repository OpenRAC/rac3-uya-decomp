#include "common.h"

/* localdecomp:start func_0044DF40 */
extern void func_0040C0F0(s32 a, s32 b, f32 x);
extern void func_0040BE90(f32 *, void *, f32);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFC18;
typedef int Q_3BFC18 __attribute__((mode(TI)));
extern s32 D_001D673C_003BFC18;
extern s32 D_001D6740;
typedef struct { u8 p0[0xB0]; V4_3BFC18 v; } S_3BFC18;
extern S_3BFC18 D_001A4BE0;
extern void func_0040BE90(f32 *, void *, f32);
extern void func_0044DED0(void *, void *, s32);
void func_0044DF40(void *a, f32 *out, s32 flag) {
    if (D_001D673C_003BFC18 == 0) {
        Q_3BFC18 r;
        __asm__("vmr32.xyzw %0, $vf0" : "=j"(r));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFC18 *)out) : "j"(r));
    } else if (D_001D6740 != 0) {
        func_0044DED0(a, out, 1);
    } else {
        Q_3BFC18 p, q, r;
        S_3BFC18 *d = &D_001A4BE0;
        f32 s = 1.0f;
        if (d->v.w > 0.0f) {
            s = -1.0f;
        }
        __asm__("lqc2 %0, %1" : "=j"(p) : "m"(*(V4_3BFC18 *)a));
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(d->v));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(q), "j"(p));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFC18 *)out) : "j"(r));
        ((void (*)(void *, void *, f32))func_0040C0F0)(out, out, s);
    }
    if (flag == 0) {
        func_0040BE90(out, out, -1.0f);
    }
}
/* localdecomp:end func_0044DF40 */
