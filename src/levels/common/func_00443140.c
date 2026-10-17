#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
extern V_3BE7F0 D_001EAAA0;
s32 func_003F8448(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);
f32 func_00443140(V_3BE7F0 *p, s32 flags, s32 c, f32 dz) {
    V_3BE7F0 a = *p;
    V_3BE7F0 b = *p;
    a.z = 0.01f;
    b.z += dz;
    if (func_003F8448(&b, &a, flags | 2, c, 0)) return D_001EAAA0.z;
    return 0.0f;
}
