#include "common.h"

void func_004D8DF0(s32 *p, s32 n) { s32 t = *p; t = (t + 0x1FFF) & -0x2000; *p = t + n; }
