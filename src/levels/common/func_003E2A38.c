#include "common.h"

/* localdecomp:start func_003E2A38 */
typedef int Q_3E2A38 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3E2A38;
extern void func_0040BE90();
extern f32 func_0040BEF8(void *, void *);
extern void func_003E23A8(void *, void *, s32);
extern void func_003E2238(s32, void *);
void func_003E2A38(u8 *a, void *dst, s32 flag) {
    V4_3E2A38 v, w;
    Q_3E2A38 x, y;
    u8 *b = a + 0x60;
    u8 *c;
    func_0040BE90(&v, a + 0x80);
    if (flag) {
        func_003E23A8(a, &w, 1);
    } else {
        func_003E2238(*(s32 *)(a + 0x50), &w);
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(w));
    c = b + 0x30;
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(x));
    ((void (*)(void *, void *, f32))func_0040BE90)(dst, c, func_0040BEF8(c, &v));
}
/* localdecomp:end func_003E2A38 */
