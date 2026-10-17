#include "common.h"
extern s32 D_0024D85C[];
extern s32 D_001E1FC8;
extern void func_0061AF30(void);
void func_0061AA38(s32 a0, s32 a1) {
    D_0024D85C[0] = a0;
    D_001E1FC8 = a1;
    func_0061AF30();
}
