#include "common.h"

extern s32 func_0051DC38();

extern u8 D_001DC2E8_g;
extern s32 func_0051DC38();
void func_0051DBE0(u8 *p, s32 f) {
    *(u8 **)p = &D_001DC2E8_g;
    if (f & 1) func_0051DC38(p);
}
