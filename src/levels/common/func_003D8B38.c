#include "common.h"

/* localdecomp:start func_003D8B38 */
extern u8 *D_00221118[];
extern s32 func_00440878(s32, s32);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440848(s32);
extern void func_00437698(u8 *, s32, f32 *);
extern void func_004C41E8(u8 *, f32 *);
extern void func_0040BE90(f32 *, f32 *, f32);
extern void func_0040C0F0(f32 *, f32 *, f32);
extern u8 *func_0046DCB8(f32 *, f32 *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_004633E8(f32 *, s32, f32 *, u32, s32, f32, f32, f32, f32);
extern void func_003D9640(u8 *, f32 *);
extern s32 func_0013D3E0(void);
extern void func_00463938(f32 *, f32 *, s32, f32, f32);

void func_003D8B38(u8 *moby)
{
    f32 pos[4];
    f32 vel[4];
    f32 tmp[4];
    s32 i;
    u32 color;
    s32 n;
    f32 scale;
    u8 *p;
    u8 *q;

    for (i = 0; i < 8; i++) {
        func_00437698(moby, func_00440878(1, 13), pos);
        pos[0] += func_004408C0(-0.02f, 0.02f);
        pos[1] += func_004408C0(-0.02f, 0.02f);
        pos[2] += func_004408C0(-0.02f, 0.02f);
        func_004C41E8(moby + 16, vel);
        func_0040BE90(vel, vel, func_004408C0(0.4f, 1.0f) * 0.016666668f);
        if (func_00440848(4) != 0) {
            color = func_00440878(64, 100) | 0x5f404000;
        } else {
            color = (func_00440878(150, 100) << 16) | 0x5f002c2c;
        }
        q = func_0046DCB8(pos, vel, func_00440878(10, 15), color, 1, 79, 0, 0, 58800.0f, 27299.998046875f, 0.0f);
        if (q != 0) {
            q[2] = *D_00221118[91];
        }
    }
    func_004C41E8(moby + 16, vel);
    func_0040BE90(vel, vel, func_004408C0(0.4f, 1.0f) * 0.016666668f);
    pos[0] += func_004408C0(-0.02f, 0.02f);
    pos[1] += func_004408C0(-0.02f, 0.02f);
    pos[2] += func_004408C0(-0.02f, 0.02f);
    n = func_00440848(5) + 1;
    scale = func_004408C0(0.25f, 0.4f) * 210000.0f;
    p = func_004633E8(pos, n, vel, func_00440878(64, 80) | 0x404000, 0, 0.0f, 0.99f, 0.995f, scale);
    if (p != 0) {
        p[3] = func_00440848(2) != 0 ? 68 : 72;
        *(s16 *)(p + 10) = 3;
    }
    if (moby[32] == 2) {
        func_00437698(moby, 0, tmp);
        func_003D9640(moby, tmp);
    }
    func_00437698(moby, 17, tmp);
    func_0040C0F0(vel, vel, func_004408C0(0.0025f, 0.01f));
    if (func_0013D3E0() % 15 == 0) {
        func_00463938(tmp, vel, 0, -1.0f, 0.0f);
    }
}
/* localdecomp:end func_003D8B38 */
