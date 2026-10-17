#include "common.h"

void func_004D09B8(unsigned long *p, unsigned long a, unsigned long b, unsigned long c) {
    *p = (a << 32) | ((b << 32) >> 4) | ((c << 32) >> 32);
}
