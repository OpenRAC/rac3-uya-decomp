#include "common.h"
extern s32 D_001D4CF0;
extern s32 D_001D545C;
extern void func_00420328(s32, s32);
extern void func_0042F238(u8 *, s32, s32);
extern void func_004238A0(u8 *);
void func_0034A3D8(u8 *a0) {
    a0[48] = 255;
    func_00420328(0, D_001D4CF0);
    if (D_001D545C == 1337 || D_001D545C == 24) {
        func_0042F238(a0, 1, -1);
    } else {
        func_004238A0(a0);
    }
}
