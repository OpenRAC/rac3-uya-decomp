#include "common.h"
typedef s32 (*Fn_0061B038)(void *);
extern Fn_0061B038 *func_005BF058(void);
s32 func_0061B038(void *a0) {
    s32 r;
    if (a0) {
        r = func_005BF058()[1](a0);
    } else {
        r = 0;
    }
    return r;
}
