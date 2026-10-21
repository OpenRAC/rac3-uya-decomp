#include "common.h"

/* localdecomp:start func_004642F0 */
typedef int Q_4642F0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4642F0;
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
void func_004642F0(u8 *p) {
    f32 *r = (f32 *)(p + 0x20);
    f32 f2 = r[3];
    f32 f3, f1;
    Q_4642F0 a, b, c;
    if (0.0f < f2) {
        r[1] += f2 * 0.007f;
    } else {
        f3 = r[1];
        if (0.0300000f < f3) {
            r[1] = f3 + f2 * 0.007f;
        } else {
            r[1] = f3 + f2 * 0.007f * 0.2f;
            *(f32 *)(p + 0xC) += 5460.0f;
        }
    }
    if (r[1] <= 0.0244f || func_0040BAC0(p + 0xA) != 0) {
        func_0045E580(p);
        return;
    }
    f2 = r[1];
    if (0.12f <= f2) {
        f1 = -r[3];
        r[3] = f1;
        r[1] = f2 + f1 * 0.007f;
    }
    *(f32 *)(p + 0xC) += 5460.0f;
    *(u32 *)(p + 4) = (*(u32 *)(p + 4) & 0xFFFFFF) | ((s32)(r[1] * 255.0f) << 24);
    r[2] += 0.002f;
    if (1.0f < r[2]) r[2] -= 1.0f;
    p[8] = (s32)(r[2] * 255.0f);
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_4642F0 *)(r + 4)));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V4_4642F0 *)(p + 0x10)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_4642F0 *)(p + 0x10)) : "j"(c));
}
/* localdecomp:end func_004642F0 */
