#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern u8 D_001A50CE[];
typedef struct {
    u8 pad[1260];
    s16 h1260;
} func_004E2320_P;

extern func_004E2320_P D_001A4BE0;
extern s32 func_0040BAC0(void *a0);
extern f32 func_0040CEC8(f32 a, f32 b);
extern f32 func_00440918(f32 a, f32 b);
extern f32 func_0040C3C8(f32 a);
extern f32 func_0040C3E0(f32 a);
extern void func_00463938(void *a, void *b, s32 c, f32 d, f32 e);
extern s32 func_00440878(s32 lo, s32 hi);
extern f32 func_004408C0(f32 lo, f32 hi);
extern f32 func_00440978(void);
extern void func_00440CF8(void *a0, f32 a, f32 b, f32 c);
extern void func_00460318(void *a0, void *a1, u32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3);

void func_004E2320(void) {
    s128 pos[1];
    f32 vel[4];
    u8 *q;
    u8 *P;
    f32 ang;
    f32 spd;
    f32 t;
    s32 c;
    u32 col;
    s32 i;
    s128 *src;
    f32 *vp;
    s32 a;
    s32 b;
    f32 x;
    f32 y;

    q = D_001A50CE;
    if (func_0040BAC0(q) != 0) {
        P = q - 1262;
        pos[0] = *(s128 *)(q - 1134);
        ang = func_0040CEC8(*(f32 *)(P + 152), 1.5707963705062866f);
        spd = func_00440918(0.0033333336468786f, 0.011666666716337204f);
        vel[0] = func_0040C3C8(ang) * spd;
        vel[1] = func_0040C3E0(ang) * spd;
        vel[2] = 0.0f;
        vel[3] = -0.002222222276031971f;
        func_00463938(pos, vel, 0, -1.0f, vel[2]);
        *(s16 *)(P + 1262) = func_00440878(2, 3);
    }
    if (func_0040BAC0(q - 2) != 0) {
        t = (f32)(40 - *(s32 *)(q - 822)) / 40.0f;
        if (1.0f < t) {
            t = 1.0f;
        }
        if (t < 0.0f) {
            t = 0.0f;
        }
        c = (s32)(t * 240.0f);
        if (c > 160) {
            c = 160;
        }
        if (c < 32) {
            c = 32;
        }
        col = (c << 24) | 0xC0F0;
        src = (s128 *)(q - 1134);
        vp = vel;
        for (i = 56; i >= 0; i--) {
            a = (s32)(func_004408C0(4200.0f, 7350.0f) / 1000.0f);
            b = (s32)(func_004408C0(21000.0f, 31500.001953125f) / 1000.0f);
            x = func_004408C0(0.002500000176951289f, 0.00950000062584877f);
            pos[0] = *src;
            y = func_00440978();
            func_00440CF8(vp, x, y, func_00440978());
            func_00460318(pos, vp, col, 28912, 40, a, b, 1);
        }
        D_001A4BE0.h1260 = func_00440878(3, 7);
    }
}
