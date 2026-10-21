#include "common.h"

/* localdecomp:start func_003D3468 */
typedef int Q_003D3468 __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_003D3468;
typedef struct {
    u8 pad0[0x10];
    V4_003D3468 v;
    u8 pad1[0x48];
    u8 *q;
    u8 pad2[0x54];
    float w[4];
} S_003D3468;
extern void func_0040C2D0(V4_003D3468 *, u8 *, float *);
void func_003D3468(V4_003D3468 *d, S_003D3468 *p) {
    Q_003D3468 a, b, r;
    func_0040C2D0(d, p->q + 0x20, p->w);
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(p->v));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*d));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(r));
}
/* localdecomp:end func_003D3468 */
