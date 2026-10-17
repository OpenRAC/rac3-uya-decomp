#include "common.h"

extern s32 D_00143950[];
extern s8 D_001E6E61[];
extern s32 D_001DF9C8;
extern void func_0045E370(void);
extern void func_004B66E0(void);
extern void func_003F07A0(void);
extern s32 func_0012C908(s32);

s32 func_003EF6C0(void) {
    s32 limit = 9600;
    s32 r;

    if (D_00143950[0] != 0) {
        limit = 11520;
    }
    if (limit < *(volatile s32 *)0x10000800 && D_001E6E61[0] == 0) {
        func_0045E370();
        func_004B66E0();
    }
    func_003F07A0();
    r = func_0012C908(0);
    D_001DF9C8++;
    return r;
}
