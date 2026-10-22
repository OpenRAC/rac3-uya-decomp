#include "common.h"

/* localdecomp:start func_0033A860 */
typedef int Q_0033A860 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0033A860;
typedef struct { V4_0033A860 r[4]; } M4_0033A860;

extern void func_0041C768(V4_0033A860 *, V4_0033A860 *, f32);
extern void func_0041CF50(void *, void *);
extern void func_0041CF70(M4_0033A860 *, void *);
extern f32 func_0041D7E0(f32, f32);
extern f32 func_0041D870(f32);
extern void func_004513D8(void *, s32, s32);
extern void func_0045B028(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_0045B6F0(void *, void *);
extern u8 D_001BBC40[];
extern s32 D_001D545C;

void func_0033A860(u8 *o, u8 *b) {
    M4_0033A860 m;
    V4_0033A860 d;
    Q_0033A860 x, y;
    u8 *r40;
    u8 *pc0;
    u8 *pf0;
    f32 k;

    r40 = b + 0x40;
    pf0 = o + 0xF0;
    pc0 = o + 0xC0;
    *(s32 *)(b + 0xC) = 0;
    *(Q_0033A860 *)(b + 0x30) = *(Q_0033A860 *)(o + 0x10);
    *(Q_0033A860 *)r40 = *(Q_0033A860 *)(o + 0xF0);
    func_0041CF50(pc0, pf0);
    func_0045B028(o, b + 0x50, 8, *(s32 *)(b + 4), *(s32 *)(b + 8), -1, 7, 0);
    if (o[0xB0] != 0xFF && (D_001BBC40[o[0xB0] + D_001D545C * 16] & 0x80)) {
        func_0041CF70(&m, r40);
        k = 0.017453292f;
        func_0041C768(&d, &m.r[0], *(f32 *)(b + 0x10));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_0033A860 *)(o + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_0033A860 *)(o + 0x10)) : "j"(x));
        func_0041C768(&d, &m.r[1], *(f32 *)(b + 0x14));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_0033A860 *)(o + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_0033A860 *)(o + 0x10)) : "j"(x));
        func_0041C768(&d, &m.r[2], *(f32 *)(b + 0x18));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_0033A860 *)(o + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_0033A860 *)(o + 0x10)) : "j"(x));
        *(f32 *)(o + 0xF0) = func_0041D7E0(*(f32 *)(b + 0x40), func_0041D870(*(f32 *)(b + 0x1C) * k));
        *(f32 *)(o + 0xF4) = func_0041D7E0(*(f32 *)(b + 0x44), func_0041D870(*(f32 *)(b + 0x20) * k));
        *(f32 *)(o + 0xF8) = func_0041D7E0(*(f32 *)(b + 0x48), func_0041D870(*(f32 *)(b + 0x24) * k));
        func_0041CF50(pc0, pf0);
        func_0045B6F0(o, b + 0x50);
        *(f32 *)(b + 0xC) = 1.0f;
    }
    func_004513D8(o, 1, -1);
}
/* localdecomp:end func_0033A860 */
