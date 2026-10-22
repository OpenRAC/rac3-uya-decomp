#include "common.h"

/* localdecomp:start func_003A2DA8 */
typedef int u128_t __attribute__((mode(TI)));

extern f32 func_004183E0(void);
extern f32 func_0041A898(void *pos, s32 a, f32 c, s32 b);
extern f32 func_00418380(f32 lo, f32 hi);
extern void func_0042F498(u8 *m, f32 a, f32 b, f32 c, f32 d);
extern void func_00419970(u8 *m, s32 a, s32 b);
extern void func_00419630(u8 *m, s32 a, s32 b, s32 c);
extern s32 D_001D67B0;
extern s32 D_001D545C;

s32 func_003A2DA8(u8 *m) {
    u8 *v;
    f32 x;
    u8 *pos;

    pos = m + 0x10;
    v = *(u8 **)(m + 0x68);
    *(u128_t *)(v + 0x2E0) = *(u128_t *)(m + 0x10);
    D_001D67B0 = 0;
    *(f32 *)(v + 0x308) = func_004183E0();
    x = func_0041A898(pos, 0, 0.5f, 0) + 0.5f;
    *(f32 *)(m + 0x18) = x;
    if (x < 2.0f) {
        *(f32 *)(m + 0x18) = *(f32 *)(v + 0x2E8);
    }
    if (*(f32 *)(v + 0x2C4) < 1.0f && D_001D545C == 2) {
        return 1;
    }
    *(f32 *)(v + 0x310) = func_00418380(15.0f, 35.0f) * 0.017453292f;
    v[0x170] = 6;
    v[0x176] = 0;
    v[0x1D6] = 1;
    *(f32 *)(v + 0x184) = 0.0069444445f;
    *(f32 *)(v + 0x190) = 0.5f;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    v[0x1DA] = 0;
    v[0x1A8] = 3;
    v[0x1D3] = 15;
    v[0x1D2] = 6;
    *(f32 *)(v + 0x17C) = 0.25f;
    *(f32 *)(v + 0x180) = 0.016666668f;
    *(f32 *)(v + 0x188) = 0.0069444445f;
    *(f32 *)(v + 0x18C) = 0.00027777778f;
    *(f32 *)(v + 0x194) = 0.5f;
    *(f32 *)(v + 0x19C) = 0.15f;
    v[0x1D7] = 1;
    v[0x1DB] = 255;
    if (*(f32 *)(v + 0x2E8) > 310.0f) {
        if (D_001D545C == 2) {
            *(f32 *)(v + 0x1A0) = 310.0f;
        }
    } else if (D_001D545C == 2) {
        *(f32 *)(v + 0x1A0) = 25.0f;
    }
    if (D_001D545C == 5) {
        *(f32 *)(v + 0x1A0) = *(f32 *)(m + 0x18) - 25.0f;
    }
    *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 4.0f;
    *(s32 *)(v + 0xA8) |= 4;
    *(f32 *)(v + 0x7C) = 1.0f;
    *(f32 *)(v + 0x70) = 0.45f;
    *(f32 *)(v + 0x74) = 0.05f;
    *(f32 *)(v + 0x78) = 0.5f;
    *(f32 *)(v + 0x80) = 0.7853982f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.0027222224f;
    func_0042F498(m, 0.0044444446f, 0.10000001f, 0.0069813174f, 0.20943953f);
    v[0x58] = 20;
    v[0x5A] = 14;
    if (*(s16 *)(v + 0x34) == 0) {
        *(f32 *)(v + 0x30) = 1.0f;
        *(s16 *)(v + 0x34) = 1;
    }
    v[0x39] = 1;
    v[0x3E] = 1;
    *(f32 *)(v + 0x40) = 0.3f;
    func_00419970(m, 1, 0);
    if (m[0x43] != 1) {
        func_00419630(m, 1, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_003A2DA8 */
