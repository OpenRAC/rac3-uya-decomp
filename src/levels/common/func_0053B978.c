#include "common.h"

/* localdecomp:start func_0053B978 */
typedef int Q_53B978 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_53B978;
extern s32 D_001DF628;
extern Q_53B978 D_0025F860[];
extern void func_0058F358(void *, void *, f32);
extern s32 func_0057F278(void *, void *, s32, s32, s32);

s32 func_0053B978(u8 *o, Q_53B978 *out, V4_53B978 *pos) {
    V4_53B978 a;
    V4_53B978 b;
    V4_53B978 d;

    *(Q_53B978 *)&d = *(Q_53B978 *)(*(u8 **)(o + 0x68) + 0x20);
    func_0058F358(&a, &d, -30.0f);
    {
        Q_53B978 p, q, r;
        __asm__("lqc2 %0, %1" : "=j"(p) : "m"(*pos));
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(q), "j"(p));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(r));
    }
    func_0058F358(&b, &d, 0.5f);
    {
        Q_53B978 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(b) : "j"(r));
    }
    if (func_0057F278(&b, &a, D_001DF628 | 2, 0, 0) != 0) {
        *out = D_0025F860[0];
        return 1;
    }
    *out = *(Q_53B978 *)pos;
    return 0;
}
/* localdecomp:end func_0053B978 */
