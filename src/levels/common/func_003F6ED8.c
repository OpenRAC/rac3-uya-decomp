#include "common.h"

/* localdecomp:start func_003F6ED8 */
typedef struct {
    f32 x, y, z, w;
} V_003F6ED8;
extern void func_0040BE90(V_003F6ED8 *, V_003F6ED8 *, f32);
s32 func_003F6ED8(u8 *m, V_003F6ED8 *out, s32 max) {
    u8 *p;
    s16 *src;
    s32 n;
    s32 i;
    f32 scale;
    p = *(u8 **)(*(u8 **)(m + 36) + 16);
    if (p == 0) {
        return 0;
    }
    n = *(s32 *)(p + 12) / 8;
    src = (s16 *)(p + *(s32 *)(p + 4) + 16);
    if (max < n) {
        n = max;
    }
    scale = *(f32 *)(m + 44) * 0.0009765625f;
    for (i = 0; i < n; i++) {
        out[i].x = src[0];
        out[i].y = src[1];
        out[i].z = src[2];
        src += 4;
        func_0040BE90(&out[i], &out[i], scale);
        out[i].w = 1.0f;
    }
    return n;
}
/* localdecomp:end func_003F6ED8 */
