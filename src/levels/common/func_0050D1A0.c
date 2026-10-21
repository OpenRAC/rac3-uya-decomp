#include "common.h"

/* localdecomp:start func_0050D1A0 */
typedef int Q_50D1A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_50D1A0;
typedef struct { V_50D1A0 m[4]; } M_50D1A0;
typedef struct {
    u8 pad[0xF0];
    M_50D1A0 mF0;
} C_50D1A0;
typedef struct {
    u8 pad[0xF8];
    f32 fF8;
} C2_50D1A0;
typedef struct {
    u8 pad[0x25C0];
    C2_50D1A0 *f25C0;
    u8 pad25C4[0x25F4 - 0x25C4];
    u8 b25F4;
} G_50D1A0;
extern G_50D1A0 D_001A4BE0;
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040C658(M_50D1A0 *, void *);
extern void func_0040C2F8(V_50D1A0 *, V_50D1A0 *, M_50D1A0 *);
void func_0050D1A0(V_50D1A0 *out, V_50D1A0 *in, f32 k) {
    M_50D1A0 m;
    V_50D1A0 t;
    Q_50D1A0 x, y;
    f32 z;
    s32 b = D_001A4BE0.b25F4;
    if (b == 0) {
        *out = *in;
        out->x = out->x + func_0040C3C8(D_001A4BE0.f25C0->fF8) * k;
        out->y = out->y + func_0040C3E0(D_001A4BE0.f25C0->fF8) * k;
    } else if (b < 0) {
    } else if (b < 3) {
        z = 0.0f;
        t.x = func_0040C3C8(z) * k;
        t.y = func_0040C3E0(z) * k;
        t.z = z;
        func_0040C658(&m, (u8 *)D_001A4BE0.f25C0 + 0xF0);
        func_0040C2F8(&t, &t, &m);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*in));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
    }
}
/* localdecomp:end func_0050D1A0 */
