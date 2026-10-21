#include "common.h"

/* localdecomp:start func_004FB518 */
typedef struct {
    u8 pad0[0x80];
    f32 f80;
    f32 f84;
    u8 pad88[0x98 - 0x88];
    f32 f98;
    u8 pad9C[0xF0 - 0x9C];
    f32 vF0[4];
    f32 f100;
    f32 f104;
    f32 f108;
    u8 pad10C[0x170 - 0x10C];
    f32 f170;
    u8 pad174[0x20A - 0x174];
    s16 h20A;
    u8 pad20C[0x260 - 0x20C];
    f32 f260;
    f32 f264;
    u8 pad268[0x284 - 0x268];
    f32 f284;
    u8 pad288[0x294 - 0x288];
    f32 f294;
    u8 pad298[0x2A7 - 0x298];
    u8 b2A7;
    u8 pad2A8[0x33C - 0x2A8];
    f32 f33C;
    u8 pad340[0x25CC - 0x340];
    int i25CC;
    u8 pad25D0[0x2838 - 0x25D0];
    f32 f2838;
} P_4FB518;

extern P_4FB518 D_001A4BE0;
extern f32 func_0040BF38(f32 *);
extern f32 func_0040BFE8(f32 *, f32 *);
extern f32 func_0040C490(f32, f32);
extern void func_00445168(f32 *, f32 *, f32, f32, f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);

void func_004FB518(void) {
    f32 d;
    f32 lim;
    f32 ang;
    f32 tmp;

    if (D_001A4BE0.b2A7 != 0 && D_001A4BE0.f33C > 0.0f && D_001A4BE0.f170 < 0.0500000045f
        && func_0040BF38(D_001A4BE0.vF0) < 0.0500000045f && D_001A4BE0.f2838 < 0.2f
        && (D_001A4BE0.i25CC == 0 || D_001A4BE0.i25CC == 2 || D_001A4BE0.i25CC == 4
            || D_001A4BE0.i25CC == 10 || D_001A4BE0.i25CC == 1)) {
        D_001A4BE0.h20A = 5;
    }
    if (D_001A4BE0.h20A != 0) {
        d = func_0040BFE8(&D_001A4BE0.f80, &D_001A4BE0.f260);
        lim = D_001A4BE0.f284 * 0.9f;
        if (d < lim) {
            ang = func_0040C490(D_001A4BE0.f80 - D_001A4BE0.f260, D_001A4BE0.f84 - D_001A4BE0.f264);
            if (d < D_001A4BE0.f284 * 0.05f) {
                ang = D_001A4BE0.f98;
            }
            tmp = d - lim;
            func_00445168(&tmp, &D_001A4BE0.f294, 0.0f, 0.03f, 0.3f, 0.046666667f);
            D_001A4BE0.f100 = func_0040C3C8(ang) * D_001A4BE0.f294;
            D_001A4BE0.f104 = func_0040C3E0(ang) * D_001A4BE0.f294;
            D_001A4BE0.f108 = 0.0f;
        }
    } else {
        D_001A4BE0.f294 = 0.0f;
    }
}
/* localdecomp:end func_004FB518 */
