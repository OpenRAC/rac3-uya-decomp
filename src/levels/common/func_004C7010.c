#include "common.h"

/* localdecomp:start func_004C7010 */
typedef int Q_4C7010 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4C7010;
extern V4_4C7010 D_001A6230;
extern f32 func_0040BF38(void *);
extern void func_0040C0F0(void *, void *, f32);
extern f32 func_0040BEF8(void *, void *);
extern f32 func_0040C3C8(f32);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040CCA0(void *, void *, void *, f32);

void func_004C7010(V4_4C7010 *out, V4_4C7010 *b, f32 a, f32 unused, f32 c)
{
    V4_4C7010 t;
    u8 *p;
    f32 r;
    {
        Q_4C7010 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001A6230));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
    }
    p = (u8 *)&D_001A6230;
    if (func_0040BF38(out) < 4.0f) {
        c = c * 0.1f;
        func_0040C0F0(out, out, 1.0f);
        p = p - 0xF60;
        r = func_0040BEF8(out, p);
        if (r < func_0040C3C8(c)) goto L;
        func_0040BE90(out, out, a);
    } else {
        func_0040C0F0(out, out, 1.0f);
        p = p - 0xF60;
        r = func_0040BEF8(out, p);
        if (r < func_0040C3C8(c)) {
L:
            func_0040BF20(&t, out, p);
            func_0040CCA0(out, p, &t, c);
            func_0040C0F0(out, out, a);
        } else {
            func_0040BE90(out, out, a);
        }
    }
}
/* localdecomp:end func_004C7010 */
