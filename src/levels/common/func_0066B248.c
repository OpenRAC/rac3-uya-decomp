#include "common.h"

/* localdecomp:start func_0066B248 */
typedef struct {
    u32 bits;
    s32 base;
    u8 pad8[0x50 - 8];
    s32 f50;
} P_0066B248;
extern s32 D_001DAC20;
extern P_0066B248 *func_0065FCD0(s32, s32, s32, s32);
extern void func_006601C8(void *, void *, s32);

void func_0066B248(s32 *a0, u8 a1, u8 a2, u8 a3) {
    u8 b[16];
    s32 w[4];
    P_0066B248 *p = func_0065FCD0(D_001DAC20, 3, 0, 0);
    p->f50 = a0[0x48 / 4];
    w[0] = a0[0];
    func_006601C8(p, w, 4);
    b[0] = a1;
    func_006601C8(p, b, 1);
    b[0] = a2;
    func_006601C8(p, b, 1);
    b[0] = a3;
    func_006601C8(p, b, 1);
    a0[0x30 / 4] = p->base + (p->bits >> 13);
}
/* localdecomp:end func_0066B248 */
