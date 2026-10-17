#include "common.h"
extern s32 D_001E68B4[];
extern s16 D_001A4DEE[];
void func_0040E698(s32 a, s32 b) {
    s32 v = D_001E68B4[0];
    if (v == a) D_001A4DEE[0] = b - v;
}
