#include "common.h"

/* localdecomp:start func_003FE7B0 */
extern void func_0040BE90(f32 *, void *, f32);
extern void func_003FE7B0(f32 *, void *);

typedef struct { u8 p0[0x140]; f32 f140, f144, f148; } S_222340_381DD0;
typedef struct { u8 p0[0x1A0]; f32 f1A0, f1A4; u8 p1A8[0x220 - 0x1A8]; f32 f220; } S_225980_381DD0;
extern S_222340_381DD0 D_001E2900_00381DD0;
extern S_225980_381DD0 D_001E7600_00381DD0;
extern void func_0040C5D0();
extern void func_0040C9B0();
extern void func_0040BE90(f32 *, void *, f32);
extern void func_0040C2F8();
void func_003FE7B0(f32 *out, void *arg1) {
    f32 m[16];
    f32 r[16];
    f32 v[4];
    f32 w[4];
    f32 t;
    func_0040C5D0(m);
    m[12] = -D_001E2900_00381DD0.f140 * 1024.0f;
    m[13] = -D_001E2900_00381DD0.f144 * 1024.0f;
    m[14] = -D_001E2900_00381DD0.f148 * 1024.0f;
    func_0040C9B0(r, (u8 *)&D_001E2900_00381DD0 + 0x40, m);
    func_0040BE90(v, arg1, 1024.0f);
    v[3] = 1.0f;
    func_0040C2F8(w, v, r);
    t = D_001E7600_00381DD0.f220 / w[3];
    w[0] = w[0] * t + D_001E7600_00381DD0.f1A0;
    w[1] = w[1] * t + D_001E7600_00381DD0.f1A4;
    out[2] = w[2] * 0.0009765625f;
    out[1] = w[1] * 16.0f;
    out[0] = w[0] * 16.0f;
}
/* localdecomp:end func_003FE7B0 */
