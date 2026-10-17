#include "common.h"

extern s32 D_001D4CEC_g;

extern void func_0042FF20();
extern s32 D_001D4CEC_g;
void func_0042FFA8(void *a, s32 b, void *c) {
    func_0042FF20(a, b, c);
    D_001D4CEC_g |= 0x4000;
}
