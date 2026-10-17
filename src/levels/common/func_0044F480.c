#include "common.h"

extern s32 func_0044F4C8(void);
extern s32 func_0044F470(void);

s32 func_0044F480(void) {
    s32 v = func_0044F4C8();
    v -= func_0044F470();
    if (v < 0) {
        v = 0;
    }
    if (v > 40) {
        v = 40;
    }
    return v;
}
