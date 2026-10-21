#include "common.h"

/* localdecomp:start func_00437698 */
extern void func_0040BE90(f32 *, void *, f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0043CE28();

typedef struct { f32 x, y, z, w; } V4_3BDA38;
typedef int Q_3BDA38 __attribute__((mode(TI)));
extern void func_0043CE28();
extern void func_0040BE90(f32 *, void *, f32);
extern void func_0040C2D0(void *, void *, void *);
void func_00437698(u8 *a, s32 b, f32 *out) {
    s32 loc;
    f32 buf[12];
    f32 v[4];
    f32 scale;
    Q_3BDA38 x, y;
    loc = b;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_0043CE28(a, 1, &loc, buf);
    func_0040BE90(out, v, scale);
    func_0040C2D0(out, out, a + 0xC0);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BDA38 *)(a + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BDA38 *)out));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3BDA38 *)out) : "j"(x));

}
/* localdecomp:end func_00437698 */
