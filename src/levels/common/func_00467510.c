#include "common.h"

/* localdecomp:start func_00467510 */
typedef int s128_467510 __attribute__((mode(TI)));

typedef struct {
    s128_467510 q0;
    f32 f10;
    f32 f14;
    int f18;
} P_467510;

extern u8 *func_0045E438(s32);
extern s32 func_00440848(s32);
extern f32 func_004408C0(f32, f32);
extern u8 *D_002211D0[];

u8 *func_00467510(s128_467510 *pos, s128_467510 *dir, int life, f32 scale, f32 g) {
    u8 *m = func_0045E438(46);
    P_467510 *p;

    if (m != 0) {
        *(s128_467510 *)(m + 0x10) = *pos;
        p = (P_467510 *)(m + 0x20);
        *(u32 *)(m + 4) = ((func_00440848(10) + 38) << 24) | 0x808080;
        m[9] = 33;
        m[3] = 72;
        m[1] = 1;
        m[2] = *D_002211D0[0];
        *(s16 *)(m + 10) = 5;
        *(f32 *)(m + 12) = scale * 210000.0f;
        p->q0 = *dir;
        p->f10 = func_004408C0(0.0f, 256.0f);
        m[8] = (int)p->f10;
        p->f14 = g;
        p->f18 = life;
    }
    return m;
}
/* localdecomp:end func_00467510 */
