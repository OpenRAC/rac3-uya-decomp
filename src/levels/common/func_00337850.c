#include "common.h"
extern void *D_001EAA98[];
extern u8 *func_00440728(void *);
s32 func_00337850(void) {
    s32 r = 0;
    u8 *v = 0;
    if (D_001EAA98[0] != 0) {
        v = func_00440728(D_001EAA98[0]);
    }
    if (v != 0) {
        r = v[9] == 1;
    }
    return r;
}
