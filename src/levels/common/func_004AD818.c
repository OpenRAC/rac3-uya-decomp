#include "common.h"

/* localdecomp:start func_004AD818 */
extern f32 D_001E0F20[];
extern s32 D_001E0F30[];
extern f32 D_001E7830[];
extern f32 D_002EEBF0[];
extern void func_0040BBD0();
void func_004AD818(void) {
    f32 *v = D_001E0F20;
    f32 s = D_001E7830[0];
    f32 a, ar1, b, c, r1, r2;
    b = v[1] * s;
    a = v[0] * s;
    r1 = 1.0f / (a - b);
    ar1 = a * r1;
    D_001E0F30[0] = (s32)(v[0] * 1024.0f);
    D_001E0F30[1] = (s32)(v[1] * 1024.0f);
    c = v[2] * s;
    D_001E0F30[2] = (s32)(v[2] * 1024.0f);
    r2 = 1.0f / (b - c);
    func_0040BBD0(D_002EEBF0, 0x40);
    D_002EEBF0[13] = b * r2;
    D_002EEBF0[3] = a;
    D_002EEBF0[9] = ar1;
    D_002EEBF0[0] = r1 * 0.5f;
    D_002EEBF0[1] = -r1;
    D_002EEBF0[8] = b * r1 * -0.5f;
    D_002EEBF0[4] = r2 * 0.5f;
    D_002EEBF0[7] = b;
    D_002EEBF0[5] = -r2;
    D_002EEBF0[12] = c * r2 * -0.5f;
}
/* localdecomp:end func_004AD818 */
