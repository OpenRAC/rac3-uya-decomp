#include "common.h"

/* localdecomp:start func_00465410 */
typedef int s128 __attribute__((mode(TI)));

extern u8 *D_002211A4[];
extern u8 *func_0045E438(s32);
extern f32 func_004408C0(f32, f32);

u8 *func_00465410(s128 *pos, s128 *vec, s32 kind, s32 a3) {
    u8 *p = func_0045E438(35);
    u8 *q;

    if (p != 0) {
        *(s128 *)(p + 16) = *pos;
        *(u32 *)(p + 4) = 0x80808080;
        p[9] = 18;
        p[3] = 68;
        p[1] = 0;
        q = p + 32;
        *(f32 *)(p + 12) = func_004408C0(10500.0f, 16800.0f);
        p[2] = *D_002211A4[0];
        *(s128 *)(p + 32) = *vec;
        *(s32 *)(q + 20) = a3;
        *(s32 *)(q + 16) = kind;
        *(f32 *)(q + 24) = *(f32 *)(p + 24);
        if (kind == 2) {
            *(s32 *)(q + 24) = 0;
        }
        *(f32 *)(q + 28) = func_004408C0(0.00291666668f, 0.005f);
    }
    return p;
}
/* localdecomp:end func_00465410 */
