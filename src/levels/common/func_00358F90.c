#include "common.h"
void func_00358F90(s32 a0, s32 a1) {
    s32 *p = (s32 *)(a0 + 76);
    s32 i;
    for (i = 3; i >= 0; i--) {
        *p-- = a1;
    }
}
