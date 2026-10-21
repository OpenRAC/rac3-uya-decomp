#include "common.h"

/* localdecomp:start func_00437780 */
typedef int Q_437780 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_437780;
typedef struct {
    u8 pad0[0x10];
    V_437780 f10;
    u8 pad20[0x2C - 0x20];
    f32 f2C;
    u8 pad30[0xC0 - 0x30];
    V_437780 fC0;
} S_437780;
extern void func_0043CCD0(S_437780 *, s32, s32, V_437780 *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2D0(void *, void *, void *);
void func_00437780(S_437780 *obj, s32 n, s32 a2, V_437780 *out) {
    f32 s = obj->f2C * 0.0009765625f;
    Q_437780 x, y;
    func_0043CCD0(obj, n, a2, out);
    if (n > 0) do {
        func_0040BE90(out, out, s);
        func_0040C2D0(out, out, &obj->fC0);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*out));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(obj->f10));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
        out++;
    } while (--n);
}
/* localdecomp:end func_00437780 */
