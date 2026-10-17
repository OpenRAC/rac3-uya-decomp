#include "common.h"
extern s32 D_0024D85C[];
extern u8 *D_001DAC20;
extern u8 *func_0061AB60(s32, s32, s32);
void func_0066A498(void) {
    u8 *v = func_0061AB60(7, D_0024D85C[0], -2);
    D_001DAC20 = v;
    v[44] = 0;
}
