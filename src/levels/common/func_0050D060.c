#include "common.h"

/* localdecomp:start func_0050D060 */
typedef int Q_50D060 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_50D060;
extern V4_50D060 D_001A4BE0;
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040C2F8(f32 *, f32 *, void *);
void func_0050D060(f32 *out, s32 flag, f32 r, f32 ang, f32 z) {
    Q_50D060 a, b, c;
    out[0] = func_0040C3C8(ang) * r;
    out[1] = func_0040C3E0(ang) * r;
    out[2] = z;
    func_0040C2F8(out, out, &D_001A4BE0);
    if (flag) {
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_50D060 *)((u8 *)&D_001A4BE0 + 0x80)));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V4_50D060 *)out));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_50D060 *)out) : "j"(c));
    }
}
/* localdecomp:end func_0050D060 */
