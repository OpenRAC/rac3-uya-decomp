#include "common.h"

extern u8 D_00142732[];
extern s32 func_00425240(void);

void func_003BBAC8(void) {
    if (func_00425240()) {
        D_00142732[0] = 1;
    }
}
