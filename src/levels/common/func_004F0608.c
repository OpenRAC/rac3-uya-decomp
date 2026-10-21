#include "common.h"

/* localdecomp:start func_004F0608 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4F0608;
typedef int Q_4F0608 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x40];
    V_4F0608 v40;
    u8 pad1[0x80 - 0x50];
    V_4F0608 v80;
    u8 pad2[0x218 - 0x90];
    s16 h218;
    u8 pad3[0x2C0 - 0x21A];
    Q_4F0608 q2C0;
    V_4F0608 v2D0;
    V_4F0608 v2E0;
    u8 pad4[0x33C - 0x2F0];
    f32 f33C;
    u8 pad5[0x36E - 0x340];
    s16 h36E;
    u8 pad6[0x16B0 - 0x370];
    s32 w16B0;
    u8 pad7[0x25F4 - 0x16B4];
    u8 b25F4;
} G_4F0608;
extern G_4F0608 D_001A4BE0;
extern void func_0040C2F8(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_004F0340(void *, void *, f32, f32, f32, s32);
void func_004F0608(void) {
    V_4F0608 m[4];
    V_4F0608 a;
    V_4F0608 b;
    V_4F0608 c;
    V_4F0608 d;
    f32 f20;
    f32 f22;
    *(Q_4F0608 *)&a = 0;
    *(Q_4F0608 *)&b = 0;
    *(Q_4F0608 *)&c = 0;
    a.z = 1.0f;
    b.z = 0.8f;
    c.z = 0.8f;
    func_0040C2F8(&b, &b, &D_001A4BE0);
    f22 = 0.035f;
    *(Q_4F0608 *)&a = D_001A4BE0.q2C0;
    f20 = 0.3f;
    if (D_001A4BE0.b25F4 == 2) {
        func_0040BE90(&a, &D_001A4BE0.v2E0, -1.0f);
    }
    if (D_001A4BE0.b25F4 == 1) {
        if (D_001A4BE0.h36E < 10 || D_001A4BE0.f33C < 1.0f) {
            *(Q_4F0608 *)&a = D_001A4BE0.q2C0;
        }
    }
    if (D_001A4BE0.h36E != 0) {
        if (D_001A4BE0.h218 != 0) {
            f20 = 0.001f;
            f22 = f20;
        }
    }
    if (D_001A4BE0.w16B0 != 0) {
        func_0040C2D0((u8 *)&D_001A4BE0 + 0x1630, (u8 *)&D_001A4BE0 + 0x1630, &D_001A4BE0.v40);
    }
    func_004F0340(&a, m, f22, f20, 0.0f, 0);
    if (D_001A4BE0.w16B0 != 0) {
        func_0040C2D0((u8 *)&D_001A4BE0 + 0x1630, (u8 *)&D_001A4BE0 + 0x1630, m);
    }
    if (D_001A4BE0.b25F4 == 1) {
        if (D_001A4BE0.h36E != 0) {
            Q_4F0608 x, y;
            func_0040C2F8(&c, &c, m);
            __asm__ __volatile__("lqc2 %3, %4\n\tlqc2 %2, %1\n\tvsub.xyz %2, %2, %3\n\tlqc2 %3, %5\n\tsqc2 %3, %0\n\tsqc2 %2, %1\n\tlqc2 %3, %1\n\tlqc2 %2, %0\n\tvadd.xyz %3, %3, %2\n\tsqc2 %3, %1"
                                 : "=m"(d), "+m"(D_001A4BE0.v80), "=&j"(x), "=&j"(y) : "m"(c), "m"(b));
        }
    }
}
/* localdecomp:end func_004F0608 */
