#include "common.h"

/* localdecomp:start func_004E20F0 */
typedef int s128_4E20F0 __attribute__((mode(TI)));
typedef union {
    s128_4E20F0 q;
    f32 f[4];
} Q_4E20F0;
typedef struct {
    u8 p0[0x80];
    f32 x80;
    f32 x84;
    u8 p88[0x2C8];
    f32 x350[1];
} G_4E20F0;
typedef struct {
    s128_4E20F0 x0;
    u8 p10[0x2C0];
    f32 x2D0;
} H_4E20F0;
extern void func_00301508(Q_4E20F0 *, s32, f32, f32);
extern f32 func_004408C0(f32, f32);
extern void func_00467288(Q_4E20F0 *, f32 *, s32, f32, f32);
extern f32 func_00440978(void);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern s32 func_00440848(s32);
extern s32 func_00440878(s32, s32);
extern void func_00465410(Q_4E20F0 *, Q_4E20F0 *, s32, s32);
extern H_4E20F0 D_001A4C60;
extern G_4E20F0 D_001A4BE0;

void func_004E20F0(s32 n, s32 m, s32 flag) {
    Q_4E20F0 a;
    s32 i;
    if (flag) {
        a.q = D_001A4C60.x0;
        a.f[2] = D_001A4C60.x2D0;
        func_00301508(&a, 3, 2.25f, 1.025f);
    }
    if (n > 0) do {
        a.f[0] = D_001A4BE0.x80 + func_004408C0(-0.3f, 0.3f);
        a.f[1] = D_001A4BE0.x84 + func_004408C0(-0.3f, 0.3f);
        a.f[2] = D_001A4BE0.x350[0];
        func_00467288(&a, D_001A4BE0.x350, -1, func_004408C0(0.3f, 0.6f), 5250.0f);
    } while (--n);
    for (i = 0; i < m; i++) {
        Q_4E20F0 b;
        f32 ang = func_00440978();
        f32 r = func_004408C0(0.0f, 0.0500000045f);
        s32 k, j;
        a.f[0] = func_0040C3C8(ang) * r;
        a.f[1] = func_0040C3E0(ang) * r;
        a.f[2] = func_004408C0(0.0500000045f, 0.13333334f);
        b.f[0] = D_001A4BE0.x80 + a.f[0] * 8.0f;
        b.f[1] = D_001A4BE0.x84 + a.f[0] * 8.0f;
        b.f[2] = D_001A4BE0.x350[0] - func_004408C0(0.0f, 0.2f);
        k = func_00440848(2);
        j = func_00440878(90, 120);
        func_00465410(&b, &a, k, j);
    }
}
/* localdecomp:end func_004E20F0 */
