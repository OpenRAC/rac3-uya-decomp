#include "common.h"

/* localdecomp:start func_004E1C58 */
typedef struct {
    u8 pad0[128];
    f32 f128;
    f32 f132;
    u8 pad88[272 - 136];
    f32 f272;
    f32 f276;
    u8 pad118[848 - 280];
    f32 f848;
    u8 pad354[2502 - 852];
    s16 h2502;
    u8 pad9C8[10312 - 2504];
    f32 f10312;
} P004E1C58;

extern P004E1C58 D_001A4BE0;
extern f32 func_004408C0(f32, f32);
extern f32 func_00440978(void);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern s32 func_00440878(s32, s32);
extern void func_00465410(f32 *, f32 *, s32, s32);
extern s16 func_00440848(s32);

void func_004E1C58(s32 a, s32 n) {
    P004E1C58 *p = &D_001A4BE0;
    f32 pos[4];
    f32 vel[4];
    f32 ang;
    f32 spd;
    s32 col;

    if (n < ++p->h2502) {
        pos[0] = p->f128 + func_004408C0(-0.15f, 0.15f) + p->f272 * 8.0f;
        pos[1] = p->f132 + func_004408C0(-0.15f, 0.15f) + p->f276 * 8.0f;
        pos[2] = p->f848 + 0.1f;
        ang = func_00440978();
        spd = func_004408C0(0.0f, 0.0500000045f);
        vel[0] = func_0040C3C8(ang) * spd + p->f272 * 0.75f;
        vel[1] = func_0040C3E0(ang) * spd + p->f276 * 0.75f;
        vel[2] = func_004408C0(0.0500000045f, 0.108333342f);
        col = func_00440878(90, 120);
        if (p->f10312 < 0.25f) {
            func_00465410(pos, vel, 3, col);
        } else {
            func_00465410(pos, vel, 1, col);
        }
        D_001A4BE0.h2502 = func_00440848(a);
    }
}
/* localdecomp:end func_004E1C58 */
