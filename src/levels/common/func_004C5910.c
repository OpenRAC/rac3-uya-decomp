#include "common.h"

extern s16 D_001E1188[];
extern s16 D_001E118A[];
extern void func_00457288(s32, s32, s32, s32, s32);

void func_004C5910(s16 a0, s16 a1) {
    D_001E1188[0] = a0;
    D_001E118A[0] = a1;
    func_00457288(8, 2, 0, 0, 0);
}
