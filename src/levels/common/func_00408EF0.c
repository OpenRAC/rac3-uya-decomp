#include "common.h"
extern u8 D_001DFAE0[];
extern u8 D_001DFB10[];
extern u8 D_001DFB20[];
extern f32 func_00408CA0(s32 a0, f32 f12, f32 *a1, s32 a2);
extern void func_004C1FE8(s32 a0, long a1);
extern void func_004066DC(s32 a0, u8 *a1, u8 *a2, u8 *a3, s32 t0);
void func_00408EF0(s32 a0, f32 *a1, f32 *a2, s32 a3, s32 t0, s32 t1, f32 f12) {
    f32 f;
    f = func_00408CA0(a0, f12, a1, t0);
    if (a3 != 0) {
        *a1 = f;
    }
    func_004C1FE8(66, 0x8000000048UL);
    f = func_00408CA0(a0, f12, a2, t1);
    if (a3 != 0) {
        *a2 = f;
    }
    func_004066DC(4, D_001DFAE0, D_001DFB10, D_001DFB20, 1);
}
