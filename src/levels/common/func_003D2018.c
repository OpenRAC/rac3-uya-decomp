#include "common.h"

extern f32 D_001DEC44;
extern f32 D_001DEC38;
extern void func_0051DAA8(s32 a0, f32 a1, f32 a2);

void func_003D2018(void *a0, u8 *a1)
{
    f32 t = *(f32 *)(a1 + 48) / (f32)*(s16 *)(a1 + 52);

    func_0051DAA8(0x490004, D_001DEC44 * t, D_001DEC38);
    func_0051DAA8(0x490005, D_001DEC44 * t, D_001DEC38);
}
