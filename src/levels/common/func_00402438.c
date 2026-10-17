#include "common.h"

unsigned long func_00402438(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 w = c - 6;
    if (w < 0) w = 0;
    w = 1 << w;
    return ((unsigned long)(a) | ((unsigned long)(w) << 14) | ((unsigned long)(e) << 20) | ((unsigned long)(c) << 26) |
        ((unsigned long)(d) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(b) << 37) |
        ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(4) << 61));
}
