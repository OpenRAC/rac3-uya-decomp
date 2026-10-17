#include "common.h"
extern u8 *func_00445F18(void *);
extern f32 *func_00440728(void *);
s32 func_003293A0(void *a0) {
    u8 *p = func_00445F18(a0);
    f32 *f;
    if (p[13] != 255) {
        return p[13];
    }
    f = func_00440728(a0);
    if (f == 0) {
        return 2;
    }
    if (*f <= 0.0f) {
        return 0;
    }
    return 2;
}
