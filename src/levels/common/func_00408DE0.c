#include "common.h"

/* localdecomp:start func_00408DE0 */
extern u8 D_001DFAE0[8];
extern u8 D_001DFB10[8];
extern u8 D_001DFB20[8];
extern void func_004C1FE8(s32, unsigned long);
extern f32 func_00408CA0(s32, f32 *, f32, s32);
extern void func_004066DC(s32, void *, void *, void *, s32);
void func_00408DE0(s32 a0, f32 *a1, f32 *a2, s32 a3, f32 f, s32 a4, s32 a5) {
    f32 r;
    func_004C1FE8(0x42, 0x800000006AUL);
    r = func_00408CA0(a0, a1, f, a4);
    if (a3 != 0) {
        *a1 = r;
    }
    func_004066DC(4, D_001DFAE0, D_001DFB10, D_001DFB20, 1);
    func_004C1FE8(0x42, 0x8000000058UL);
    r = func_00408CA0(a0, a2, f, a5);
    if (a3 != 0) {
        *a2 = r;
    }
    func_004066DC(4, D_001DFAE0, D_001DFB10, D_001DFB20, 1);
}
/* localdecomp:end func_00408DE0 */
