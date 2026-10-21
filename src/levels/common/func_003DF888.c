#include "common.h"

/* localdecomp:start func_003DF888 */
typedef int Q_003DF888 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003DF888;
extern u8 *D_00221174[];
extern u8 *D_002212BC[];
extern u8 *D_002211A0[];
extern s32 func_00440848(s32);
extern s32 func_00440878(s32, s32);
extern f32 func_004408C0(f32, f32);
extern void func_00440B30(V_003DF888 *, f32, f32);
extern void func_0040BE90(V_003DF888 *, V_003DF888 *, f32);
extern void func_0040C0F0(V_003DF888 *, V_003DF888 *, f32);
extern void func_004C41E8(void *, V_003DF888 *);
extern u8 *func_0046DCB8(V_003DF888 *, V_003DF888 *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern void func_00463938(V_003DF888 *, V_003DF888 *, s32, f32, f32);

void func_003DF888(u8 *moby)
{
    V_003DF888 pos;
    V_003DF888 a;
    V_003DF888 b;
    V_003DF888 c;
    Q_003DF888 x, y, r;
    s32 n;
    u8 *p;

    if (func_00440848(3) == 0) {
        func_00440B30(&a, 0.035f, 0.05f);
        func_0040BE90(&b, &a, 10.0f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_003DF888 *)(moby + 16)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(x));
        n = func_00440878(10, 30);
        p = func_0046DCB8(&pos, &a, n, 0x5a182, func_00440878(-1, -3), 64, 0, 0, 126000.0078f, 231000.0f, 0.006666667f);
        if (p != 0) {
            p[3] = func_00440848(2) ? 72 : 68;
            p[2] = *D_00221174[0];
        }
    }
    if (func_00440848(3) == 0) {
        func_00440B30(&a, 0.01f, 0.04f);
        func_0040BE90(&b, &a, 10.0f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_003DF888 *)(moby + 16)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(x));
        n = func_00440878(10, 30);
        p = func_0046DCB8(&pos, &a, n, 0x5a182, func_00440878(-1, -3), 64, 0, 0, 105000.0f, 84000.0f, 0.006666667f);
        if (p != 0) {
            p[3] = func_00440848(2) ? 72 : 68;
            p[2] = *D_002212BC[0];
        }
    }
    if (func_00440848(3) == 0) {
        func_00440B30(&a, 0.01f, 0.03f);
        func_0040BE90(&b, &a, 10.0f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_003DF888 *)(moby + 16)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(x));
        n = func_00440878(10, 30);
        p = func_0046DCB8(&pos, &a, n, 0x5a182, func_00440878(-1, -3), 64, 0, 0, 84000.0f, 42000.0f, 0.006666667f);
        if (p != 0) {
            p[3] = func_00440848(2) ? 72 : 68;
            p[2] = *D_002211A0[0];
        }
    }
    if (func_00440848(3) == 0) {
        func_00440B30(&a, 0.01f, 0.03f);
        func_0040BE90(&b, &a, 20.0f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_003DF888 *)(moby + 16)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(x));
        func_004C41E8(moby + 16, &c);
        func_0040C0F0(&c, &c, -func_004408C0(0.01f, 0.05f));
        func_00463938(&pos, &c, 0x4005a182, -1.0f, -0.004166667f);
    }
}
/* localdecomp:end func_003DF888 */
