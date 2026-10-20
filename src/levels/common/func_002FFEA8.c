#include "common.h"

extern s32 D_001DB02C;
extern f32 D_001DFBD0;
extern void func_002FFF98(u8 *, s32);
extern s32 func_003F5D40(u8 *);
extern s32 func_00440848(s32);
extern void func_00441FB8(u8 *, s32, s32);
extern void func_00436220(u8 *);

void func_002FFEA8(u8 *a0) {
    if (D_001DB02C != 0) {
        func_002FFF98(a0, D_001DB02C);
    }
    switch (a0[32]) {
    case 0:
        if (func_003F5D40(a0) == 0) {
            if (!(D_001DFBD0 > 0.95f)) {
                return;
            }
            if (func_00440848(10) != 0) {
                return;
            }
        }
        func_00441FB8(a0, 1, -1);
        *(u16 *)(a0 + 52) |= 0x2800;
        break;
    case 1:
        func_003F5D40(a0);
        if (a0[35] < 2) {
            func_00436220(a0);
        } else {
            a0[35] -= 2;
        }
        break;
    }
}
