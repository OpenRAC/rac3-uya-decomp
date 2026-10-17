#include "common.h"

extern s32 D_001DAC20;
extern u32 *func_0065FCD0(s32, s32, s32, s32);
extern void func_006601C8(void *, void *, s32);

void func_0066B188(s32 *a0, s32 a1, u8 a2, u8 a3) {
    u8 b[2];
    s32 w;
    u32 *s;

    s = func_0065FCD0(D_001DAC20, 1, 0, 0);
    s[20] = a1;
    w = *a0;
    func_006601C8(s, &w, 4);
    b[0] = a2;
    func_006601C8(s, b, 1);
    b[0] = a3;
    func_006601C8(s, b, 1);
    a0[12] = s[1] + (s[0] >> 13);
}
