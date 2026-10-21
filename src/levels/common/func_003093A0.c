#include "common.h"

/* localdecomp:start func_003093A0 */
extern u8 D_001A4C60[];
extern s32 func_00440760(void *, s32, s32);
extern s32 func_00442998(s32, s32, s32);
extern s32 func_003F08D8(s32, s32);
extern void func_003F0980(s32, s32);
extern void func_00309218(u8 *);

void func_003093A0(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 104);
    if (func_00440760(D_001A4C60, p[0], 0) != 0 && p[10] == 0) {
        if (func_00442998(p[16], -1, 0) != 0) {
            p[11] = func_003F08D8(0, 5);
            p[10] = 1;
            func_00309218(a0);
            return;
        }
    }
    if (p[10] != 0) {
        if (func_00440760(D_001A4C60, p[0], 0) == 0 || func_00442998(p[16], -1, 0) == 0) {
            func_003F0980(0, p[11]);
            p[10] = 0;
        }
    }
}
/* localdecomp:end func_003093A0 */
