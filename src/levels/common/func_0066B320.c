#include "common.h"
extern s32 D_001DAC20;
extern s32 func_0065FCD0(s32, s32, s32, s32);
extern void func_006601C8(s32, void *, s32);
void func_0066B320(s32 *a, u8 b, u8 c) {
    u8 tmp[16];
    s32 w[4];
    s32 m = func_0065FCD0(D_001DAC20, 2, 0, 0);
    *(s32 *)(m + 80) = a[18];
    w[0] = a[0];
    func_006601C8(m, w, 4);
    tmp[0] = b;
    func_006601C8(m, tmp, 1);
    tmp[0] = c;
    func_006601C8(m, tmp, 1);
}
