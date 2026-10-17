#include "common.h"

extern s32 func_004D1FC8(void *);
extern s32 func_004D2050();

s32 func_004D2050(s32 *p) {
    if (func_004D1FC8(p)) return 0;
    return p[0] + p[2] * 0xD0000;
}
