#include "common.h"

/* localdecomp:start func_00310170 */
extern f32 D_0026EC00[][7];
extern f32 *D_001E0140;
extern f32 D_001E0138;
extern f32 func_0030F820(f32 a);
extern f32 func_003E4B30(f32 a);
extern f32 func_003E4B48(f32 a);

void func_00310170(f32 *a, f32 *b, f32 *c, f32 t) {
    s32 i;
    f32 ph, kx, ky, amp, ang;
    f32 s0, c0, s1, c1, s2, c2, s3, c3;
    for (i = 0; i < 8; i++) {
        ph = D_0026EC00[i][3];
        kx = D_0026EC00[i][4];
        ky = D_0026EC00[i][5];
        amp = D_0026EC00[i][0];
        ang = func_0030F820(kx * a[0] + ky * a[1] + D_0026EC00[i][6] * t + ph);
        s0 = amp * func_003E4B30(ang);
        c0 = amp * func_003E4B48(ang);
        ang = func_0030F820(kx * b[0] + ky * b[1]);
        s1 = func_003E4B30(ang);
        c1 = func_003E4B48(ang);
        ang = func_0030F820(kx * c[0] + ky * c[1]);
        s2 = func_003E4B30(ang);
        c2 = func_003E4B48(ang);
        ang = func_0030F820(D_001E0138 * (kx * b[0] + ky * b[1]));
        s3 = func_003E4B30(ang);
        c3 = func_003E4B48(ang);
        D_001E0140[i] = s0;
        D_001E0140[i + 8] = c0;
        D_001E0140[i + 16] = s1;
        D_001E0140[i + 24] = c1;
        D_001E0140[i + 32] = s2;
        D_001E0140[i + 40] = c2;
        D_001E0140[i + 48] = -kx;
        D_001E0140[i + 56] = -ky;
        D_001E0140[i + 116] = s3;
        D_001E0140[i + 124] = c3;
    }
}
/* localdecomp:end func_00310170 */
