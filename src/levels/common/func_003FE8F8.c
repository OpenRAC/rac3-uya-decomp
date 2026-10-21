#include "common.h"

/* localdecomp:start func_003FE8F8 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_0040BE90(f32 *, void *, f32);
extern void func_0040C9B0();

typedef struct { f32 x, y, z, w; } V_381F18;
typedef union { u128_t q; V_381F18 v; } Q_381F18;
extern u8 D_001E7880[];
extern u8 D_001E2A60[];
extern u8 D_001E2A70[];
extern u8 D_001E76C0[];
extern u8 D_001D5477_00381F18;
extern void func_0040BF20();
extern void func_0040BEC0_00381F18(void *, void *, f32);
void func_003FE8F8(void) {
    Q_381F18 r[4];
    f32 *m;
    f32 sx, sy, sz;
    u8 *s;
    if (D_001D5477_00381F18 != 0) {
        func_0040BF20(D_001E2A70, D_001E2A70 + 0x10, D_001E2A70 - 0x10);
    }
    r[0].q = *(u128_t *)(D_001E2A60);
    r[1].q = *(u128_t *)(D_001E2A60 + 0x10);
    r[2].q = *(u128_t *)(D_001E2A60 + 0x20);
    m = (f32 *)(D_001E2A60 - 0x160);
    m[0] = -r[1].v.x;
    m[4] = -r[1].v.y;
    m[8] = -r[1].v.z;
    m[1] = -r[2].v.x;
    m[5] = -r[2].v.y;
    m[9] = -r[2].v.z;
    m[2] = r[0].v.x;
    m[6] = r[0].v.y;
    m[10] = r[0].v.z;
    m[15] = 1.0f;
    m[12] = 0;
    m[13] = 0;
    m[14] = 0;
    m[3] = 0;
    m[7] = 0;
    m[11] = 0;
    func_0040C9B0((u8 *)m + 0x40, D_001E76C0, m);
    func_0040C9B0((u8 *)m + 0x80, D_001E76C0 + 0x40, m);
    s = D_001E76C0 - 0xC0;
    sx = *(f32 *)(s + 0x1A0);
    sy = *(f32 *)(s + 0x1A4);
    sz = *(f32 *)(s + 0x1A8);
    m[32] += m[35] * sx;
    m[33] += m[35] * sy;
    m[34] += m[35] * sz;
    m[36] += m[39] * sx;
    m[37] += m[39] * sy;
    m[38] += m[39] * sz;
    m[40] += m[43] * sx;
    m[41] += m[43] * sy;
    m[42] += m[43] * sz;
    m[44] += m[47] * sx;
    m[45] += m[47] * sy;
    m[46] += m[47] * sz;
    func_0040C9B0((u8 *)m + 0xC0, D_001E76C0 + 0x80, m);
    func_0040BEC0_00381F18((u8 *)m + 0x100, D_001E76C0 + 0x80, *(f32 *)(s + 0x1C0));
    func_0040BEC0_00381F18((u8 *)m + 0x110, D_001E76C0 + 0x90, *(f32 *)(s + 0x1C4));
    *(u128_t *)((u8 *)m + 0x120) = *(u128_t *)(s + 0x160);
    *(u128_t *)((u8 *)m + 0x130) = *(u128_t *)(s + 0x170);
    func_0040C9B0((u8 *)m + 0x100, (u8 *)m + 0x100, m);
    *(u128_t *)(D_001E7880 + 0x00) = *(u128_t *)((u8 *)m);
    *(u128_t *)(D_001E7880 + 0x10) = *(u128_t *)((u8 *)m + 0x10);
    *(u128_t *)(D_001E7880 + 0x20) = *(u128_t *)((u8 *)m + 0x20);
    func_0040BE90((f32 *)(D_001E7880 + 0x30), (u8 *)m + 0x140, 1024.0f);
    *(f32 *)(D_001E7880 + 0x3C) = 1024.0f;
}
/* localdecomp:end func_003FE8F8 */
