#include "common.h"

/* localdecomp:start func_00465BB8 */
typedef int s128_465BB8 __attribute__((mode(TI)));
extern u8 *D_00221148[];
extern u8 *func_0045E438(s32 a0);
extern s32 func_00445B88(f32 a, f32 b, f32 c, f32 d);
extern f32 func_00440978(void);
extern s32 func_0013D3E0(void);
extern f32 func_004408C0(f32 a, f32 b);
u8 *func_00465BB8(s128_465BB8 *pos, s128_465BB8 *vel, u8 kind, s32 a3, u8 size, s32 t1) {
    u8 *p;
    u8 *q;
    f32 f;

    p = func_0045E438(40);
    if (p != 0) {
        q = p + 32;
        *(s128_465BB8 *)(p + 16) = *pos;
        *(s128_465BB8 *)(p + 32) = *vel;
        *(s32 *)(p + 4) = func_00445B88(0.7f, 0.7f, 0.7f, 0.08f);
        p[1] = 0;
        p[9] = ((t1 >> 5) << 4) + 4;
        p[3] = 68;
        f = func_00440978();
        *(f32 *)(q + 16) = f;
        p[8] = (s32)(f * 256.0f);
        p[2] = D_00221148[0][func_0013D3E0() & 7];
        q[25] = size;
        q[24] = kind;
        *(s16 *)(q + 20) = 0;
        *(s16 *)(q + 22) = 0;
        if (kind < 5) {
            *(f32 *)(p + 12) = func_004408C0(q[25] * 0.03125f * 21000.0f, q[25] * 0.03125f * 30000.0f);
            *(s16 *)(p + 10) = 18 - func_0013D3E0() % 15;
        } else {
            *(f32 *)(p + 12) = q[25] * 0.03125f * 30000.0f;
            *(s16 *)(p + 10) = 18;
        }
        *(s32 *)(q + 28) = a3;
    }
    return p;
}
/* localdecomp:end func_00465BB8 */
