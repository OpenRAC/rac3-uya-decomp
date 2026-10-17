#include "common.h"
typedef s32 (*Fn_00619D10)(void *);
extern Fn_00619D10 *func_005BF058(void);
s32 func_00619D10(void *a0) {
    s32 r;
    if (a0) {
        r = func_005BF058()[0](a0);
    } else {
        r = 0;
    }
    return r;
}
