#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3_0035C9C0;

extern f32 D_001E20D8[];
extern void func_003019A8(void);
extern f32 func_0042B148(f32, f32);
extern f32 func_003F7958(f32, f32);
extern f32 func_0042B0F0(f32, f32);
extern f32 func_003F6E18(f32);
extern f32 func_003F6E30(f32);
extern u8 *func_003E0230(u8 *, s32, s32, s32, u8 *, u8 *, V3_0035C9C0 *, s32, s32, s32, s32, f32, f32);

void func_0035C9C0(u8 *m, s32 idx)
{
    V3_0035C9C0 v;
    f32 a;
    f32 s;
    u8 *r;

    *(u16 *)(m + 124) &= ~(1 << idx);
    *(u16 *)(*(u8 **)(m + 104) + 54) -= 1;
    a = func_003F7958(func_0042B148(90.0f, 120.0f) * 0.017453292f, D_001E20D8[0]);
    s = func_0042B0F0(2.0f, 4.0f) * 0.016666668f;
    v.x = func_003F6E18(a) * s;
    v.y = func_003F6E30(a) * s;
    v.z = 0.0f;
    v.z = func_0042B0F0(5.0f, 8.0f) * 0.016666668f;
    r = func_003E0230(m, 1, *(s16 *)(m + 170), idx, m + 16, m + 240, &v, 255, 80, 0, 128, 10.0f, 15.0f);
    if (r != 0) {
        *(void (**)(void))(r + 100) = func_003019A8;
    }
}
