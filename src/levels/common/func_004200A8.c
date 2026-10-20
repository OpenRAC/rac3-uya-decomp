#include "common.h"

extern u8 D_00142CA0[];
extern u8 D_00142D40[];
extern s32 D_001D4C48;
extern s32 D_001D545C;
extern void func_00416B38(s32 a0);
extern void func_004344A0(void);
extern void func_0041FF98(void);
extern void func_00420180(s32 a0);

void func_004200A8(void) {
    if (D_00142CA0[23] == 0) {
        func_00416B38(23);
        D_001D4C48 = 23;
    }
    if (D_00142CA0[6] == 0) {
        D_00142D40[6] = 1;
        D_00142CA0[6] = 1;
        func_004344A0();
    }
    if (D_00142CA0[36] == 0) {
        D_00142CA0[36] = 1;
        D_00142D40[36] = 1;
        func_004344A0();
        D_00142CA0[37] = 1;
        D_00142D40[37] = 1;
        func_004344A0();
        D_00142D40[38] = 1;
        D_00142CA0[38] = 1;
        func_004344A0();
    }
    func_0041FF98();
    D_00142CA0[3] = 1;
    D_00142D40[3] = 1;
    func_004344A0();
    func_00420180(D_001D545C);
}
