#include "common.h"
extern s32 D_001DF71C[];
extern void func_00355038(s32);
void func_00355010(s32 a0) {
    func_00355038(D_001DF71C[0] + (a0 << 8));
}
