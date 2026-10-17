#include "common.h"

extern void func_00477F28(f32 *, f32);

void func_00477F28(f32 *p, f32 a) {
    *p = (a < *p) ? a : *p;
}
