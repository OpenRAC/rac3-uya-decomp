#include "common.h"

extern s32 func_00417EA0(void);

s32 func_0049B190(s32 a0) {
    s32 r = 0;
    if (func_00417EA0() == 0 || a0 != 0) {
        r = 1;
    }
    return r;
}
