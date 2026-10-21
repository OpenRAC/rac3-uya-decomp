#include "common.h"

/* localdecomp:start func_0046E638 */
typedef int Q_46E638 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_46E638;
extern s32 D_001DFBC0;
extern V4_46E638 D_001E2900;
extern void func_0040BE90(void *, void *, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3E0(f32);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_003F8448(void *, void *, s32, s32, s32);
extern f32 func_00443140(void *, s32, s32, f32);
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
#define F_(p, o) (*(f32 *)((u8 *)(p) + (o)))
void func_0046E638(u8 *p) {
    V4_46E638 tmp;
    Q_46E638 a, b, c, d, e, g;
    u8 *r = p + 0x20;
    u8 *v = p + 0x10;
    s32 col;
    func_0040BE90(r, r, 0.9f);
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V4_46E638 *)(p + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V4_46E638 *)(p + 0x20)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_46E638 *)(p + 0x10)) : "j"(c));
    if (F_(r, 0x10) + 0.25f < F_(p, 0x18)) {
        F_(r, 8) -= F_(r, 0xC);
        p[8] += r[0x16];
        if (D_001DFBC0 % 10 == 0) {
            f32 f = func_0040CEC8(F_(r, 0x1C), 1.0f);
            F_(r, 0x1C) = f;
            f = func_0040C3E0(f);
            func_0040C0F0(&tmp, &D_001E2900, f * 0.0075f);
            __asm__("lqc2 %0, %1" : "=j"(d) : "m"(*(V4_46E638 *)(p + 0x20)));
            __asm__("lqc2 %0, %1" : "=j"(e) : "m"(tmp));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(g) : "j"(d), "j"(e));
            __asm__("sqc2 %1, %0" : "=m"(*(V4_46E638 *)(p + 0x20)) : "j"(g));
        }
    } else {
        tmp = *(V4_46E638 *)(p + 0x10);
        tmp.z -= 0.35f;
        if (func_003F8448(v, &tmp, 2, 0, 0) == 0) {
            F_(r, 0x10) = func_00443140(v, 0, 0, 0.5f);
        }
    }
    if (*(s16 *)(p + 0xA) < *(s16 *)(r + 0x14)) {
        col = ((s32)((f32)*(s16 *)(p + 0xA) / (f32)*(s16 *)(r + 0x14) * 128.0f) << 24) | 0x50505;
    } else {
        col = 0x9F050505;
    }
    *(s32 *)(p + 4) = col;
    if (func_0040BAC0(p + 0xA)) {
        func_0045E580(p);
    }
}
/* localdecomp:end func_0046E638 */
