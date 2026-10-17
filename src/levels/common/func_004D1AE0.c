#include "common.h"

extern s32 func_004D1AE0(void *);

extern s32 func_00135CF0(void *);
s32 func_004D1AE0(void *p) {
    s32 r = 0;
    if (func_004D19E8(p) == 0) r = func_00135CF0(p) != 0;
    return r;
}
