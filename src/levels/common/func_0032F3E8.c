#include "common.h"
void func_0032F3E8(s32 a0, s32 *a1, s32 *a2) {
    s32 t = (a0 + 59) / 60;
    *a2 = t;
    *a1 = t / 60;
    *a2 = *a2 - *a1 * 60;
}
