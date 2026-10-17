#include "common.h"
extern float D_001DF9D0[];
extern float D_001D6720;
extern void func_00402A10(s32);
void func_004B6C20(void) {
    D_001D6720 = 1.2f;
    if (D_001DF9D0[0] < 1.0f) {
        func_00402A10(6);
    }
}
