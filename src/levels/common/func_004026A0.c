#include "common.h"

extern s32 D_001DFA0C_00385840;
extern s32 D_001E8800[];
extern s32 D_001E8700_00385840[];
void func_004026A0(s32 a, s32 b) {
    s32 n = D_001DFA0C_00385840;
    if (n < 0x40) {
        D_001E8700_00385840[n] = a;
        D_001E8800[n] = b;
        D_001DFA0C_00385840 = n + 1;
    }
}
