#include "common.h"
extern s32 func_003F5D40(u8 *a0);
extern void func_00441FB8(u8 *a0, s32 a1, s32 a2);
extern void func_00436220(u8 *a0);
void func_0031C7F0(u8 *a0) {
    switch (a0[32]) {
    case 0:
        if (func_003F5D40(a0)) {
            func_00441FB8(a0, 1, -1);
            *(u16 *)(a0 + 52) |= 0x2000;
        }
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
