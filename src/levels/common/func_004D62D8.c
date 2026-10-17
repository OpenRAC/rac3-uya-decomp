#include "common.h"

extern f32 func_004408C0(f32, f32);
extern s32 func_00440878(s32, s32);

typedef int u128_3BA490 __attribute__((mode(TI)));
typedef struct {
    u128_3BA490 a;
    u128_3BA490 b;
    f32 f20, f24, f28;
    s32 x2C, x30, x34, x38, x3C, x40, x44, x48, x4C;
} P_3BA490;
extern void func_004AD2A8(s32, s32);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440878(s32, s32);
extern f32 func_00440978(void);
extern s32 func_0040D020(s32, s32, f32);
void func_004D62D8(s32 a0, u128_3BA490 *a, u128_3BA490 *b) {
    P_3BA490 s;
    func_004AD2A8(a0, 0x502020);
    s.x30 = s.x2C = func_0040D020(0x7F2F00, 0x800000, func_004408C0(0.0f, 1.0f));
    s.x38 = s.x34 = func_00440878(0x1F, 0x3F);
    s.f28 = func_004408C0(0.1f, 0.8f);
    s.a = *a;
    s.b = *b;
    s.f24 = func_00440978();
    s.f20 = func_004408C0(90.0f, 180.0f) * 0.017453292f * 0.016666668f;
    s.x40 = s.x44 = func_00440878(0x96, 0xB4);
    s.x4C = 5;
    s.x3C = 1;
    func_004D6230(a0, (u8 *)&s);
}
