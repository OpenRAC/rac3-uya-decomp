#include "common.h"

/* localdecomp:start func_004CA6C0 */
extern s32 D_001D67C8;
extern void func_004CA6C0(s32, s32, s32, f32, f32, f32, f32);

typedef struct { u8 p0[0xB0]; f32 fB0; } S_225980_3A7090;
extern S_225980_3A7090 D_001E7600_003A7090;
extern s32 D_001D67C8;
extern s32 D_001D52F0;
extern s32 func_004C78E0();
extern void func_004C78D8(s32);
extern s32 func_004C8AC8();
extern void func_003FFAC8();
extern void func_004C7F48_003A7090(s32, f32, f32, s32, f32, f32, f32);
void func_004CA6C0(s32 base, s32 hi, s32 lo, f32 f0, f32 f1, f32 f2, f32 f3) {
    s32 saved;
    f32 old;
    f32 d;
    f32 one;
    f32 e;
    f32 y0;
    f32 y1;
    s32 p1, p2;
    saved = func_004C78E0();
    func_004C78D8(0);
    if (D_001D67C8 != 0) {
        one = 1.0f;
        old = D_001E7600_003A7090.fB0;
        d = one;
        D_001E7600_003A7090.fB0 = 0.62f;
        func_003FFAC8();
        e = ((f1 - f0) - 26.0f) / 112.0f;
        e = e * 0.31100002f + 0.0375f;
        if (func_004C8AC8() == 1) {
            d = 0.9f;
        }
        p1 = base + 0x5100;
        hi <<= 24;
        hi |= lo;
        func_004C7F48_003A7090(*(s32 *)(p1 + (D_001D52F0 << 2)), f2, f0, hi, -1.0f, d, e);
        y0 = f2 + 16.0f;
        func_004C7F48_003A7090(*(s32 *)(p1 + (D_001D52F0 << 2)), f3, f0, hi, one, d, e);
        p2 = base + 0x5110;
        y1 = f3 - 16.0f;
        e = ((f3 - f2) - 150.0f) / 306.0f;
        e = e * 0.43300003f + 0.102f;
        func_004C7F48_003A7090(*(s32 *)(p2 + (D_001D52F0 << 2)), y0, f0, hi, -1.0f, one, e);
        func_004C7F48_003A7090(*(s32 *)(p2 + (D_001D52F0 << 2)), y1, f0, hi, one, one, e);
        func_004C7F48_003A7090(*(s32 *)(p2 + (D_001D52F0 << 2)), y0, f1, hi, -1.0f, -1.0f, e);
        func_004C7F48_003A7090(*(s32 *)(p2 + (D_001D52F0 << 2)), y1, f1, hi, one, -1.0f, e);
        D_001E7600_003A7090.fB0 = old;
        func_003FFAC8();
        func_004C78D8(saved);
    }
}
/* localdecomp:end func_004CA6C0 */
