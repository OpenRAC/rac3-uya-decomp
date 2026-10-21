#include "common.h"

/* localdecomp:start func_003F35A0 */
typedef int u128_t __attribute__((mode(TI)));

void func_0040BD58(void *, void *, s32);

typedef struct { u128_t q0; u128_t q1; u8 pad[0x360]; f32 f380[4]; f32 f390[4]; f32 f3a0[4]; f32 f3b0[4]; f32 f3c0[4]; f32 f3d0[4]; u128_t q3e0; u8 pad2[0x70]; } E_003809F0;
extern E_003809F0 D_001E2AC0_003809F0[];
extern u128_t D_001E2A40[];
void func_003F35A0(s32 idx) {
    E_003809F0 *e = &D_001E2AC0_003809F0[idx];
    u128_t v;
    e->f3b0[0] = -e->f390[0];
    e->f3c0[0] = -e->f390[1];
    e->f3d0[0] = -e->f390[2];
    e->f3b0[1] = -e->f3a0[0];
    e->f3c0[1] = -e->f3a0[1];
    e->f3d0[1] = -e->f3a0[2];
    e->f3b0[2] = e->f380[0];
    e->f3c0[2] = e->f380[1];
    e->f3d0[2] = e->f380[2];
    v = e->q0;
    e->q3e0 = v;
    D_001E2A40[0] = v;
    D_001E2A40[1] = D_001E2AC0_003809F0[idx].q1;
    func_0040BD58(&D_001E2A40[2], D_001E2AC0_003809F0[idx].f380, 0x30);
}
/* localdecomp:end func_003F35A0 */
