#include "common.h"

/* localdecomp:start func_0050D2A8 */
typedef int Q_50D2A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_50D2A8;
typedef struct {
    u8 pad0[0x25C0];
    u8 *f25C0;
    u8 pad25C4[0x25F4 - 0x25C4];
    u8 f25F4;
} G_50D2A8;
extern G_50D2A8 D_001A4BE0;
extern void func_0040C658(void *, void *);
extern void func_0040C2F8(void *, void *, void *);
void func_0050D2A8(V_50D2A8 *out, V_50D2A8 *in, f32 h) {
    struct { V_50D2A8 m[4]; } r;
    V_50D2A8 t;
    Q_50D2A8 x, y;
    s32 c = D_001A4BE0.f25F4;
    if (c == 0) {
        *(Q_50D2A8 *)out = *(Q_50D2A8 *)in;
        out->z += h;
    } else if (c >= 0) { if (c < 3) {
        __asm__("sq $0, %0" : "=m"(t));
        t.z = h;
        func_0040C658(&r, D_001A4BE0.f25C0 + 240);
        func_0040C2F8(&t, &t, &r);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*in));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
    } }
}
/* localdecomp:end func_0050D2A8 */
