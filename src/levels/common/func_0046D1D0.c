#include "common.h"

/* localdecomp:start func_0046D1D0 */
typedef int Q_46D1D0 __attribute__((mode(TI)));
extern u8 *D_00221284[];
extern u8 *func_0045E438(s32);
extern s32 func_0013D3E0(void);

u8 *func_0046D1D0(Q_46D1D0 *a0, Q_46D1D0 *a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, f32 f12, f32 f13, s32 stk) {
    u8 *p;
    u8 *q;
    if (t0 == 0) {
        return 0;
    }
    p = func_0045E438(0x5B);
    if (p != 0) {
        *(Q_46D1D0 *)(p + 0x10) = *a0;
        *(s32 *)(p + 4) = a2;
        *(f32 *)(p + 0x1C) = (f32)stk;
        p[9] = 0xA4;
        if (t3 != -1) {
            p[3] = t3;
        } else {
            p[3] = 0x48;
        }
        p[1] = 0;
        *(f32 *)(p + 0xC) = f12;
        p[8] = func_0013D3E0();
        if (t2 == -1) {
            p[2] = D_00221284[0][0];
        } else {
            p[2] = D_00221284[0][t2];
        }
        *(s16 *)(p + 0xA) = t0;
        q = p + 0x20;
        *(s16 *)(q + 0x18) = t0;
        *(f32 *)(q + 0x1C) = f12;
        *(s32 *)(q + 0x10) = a2;
        *(s32 *)(q + 0x14) = a3;
        *(s16 *)(q + 0x1A) = t1;
        *(Q_46D1D0 *)(p + 0x20) = *a1;
        *(f32 *)(q + 0xC) = f13 * 0.00027777778f;
    }
    return p;
}
/* localdecomp:end func_0046D1D0 */
