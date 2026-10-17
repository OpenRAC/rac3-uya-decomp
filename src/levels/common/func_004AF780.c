#include "common.h"
extern u8 *D_001DAAF0;
extern void func_0040C600(void *a0, f32 a1);
void func_004AF780(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        func_0040C600(D_001DAAF0 + i * 64, 1.0f);
    }
}
