#include "common.h"

extern s32 func_0051DC38();

extern u8 D_001DB1D8[];
void func_004C87A0(u8 *p, s32 f) { *(u8 **)p = D_001DB1D8; if (f & 1) func_0051DC38(p); }
