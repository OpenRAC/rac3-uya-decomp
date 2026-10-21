#include "common.h"
typedef int Q_4677E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4677E8;
extern void func_0040BE90(f32, void *, void *);
extern void func_0045E580(void *);
/* localdecomp:start func_004677E8 */
void func_004677E8(u8 *p) {
    Q_4677E8 x, y, r;
    u8 *q = p + 32;
    s32 w;
    func_0040BE90(0.975f, q, q);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_4677E8 *)(p + 16)));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_4677E8 *)q));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_4677E8 *)(p + 16)) : "j"(r));
    *(f32 *)(p + 12) += 14700.0f;
    p[8] += q[16];
    w = *(s32 *)(p + 4) + 0xFE000000;
    *(s32 *)(p + 4) = w;
    if (w < 0) {
        func_0045E580(p);
    }
}
/* localdecomp:end func_004677E8 */
