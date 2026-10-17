#include "common.h"
extern void *func_0061B038(void *);
extern void *func_0065FDA0(void *, s32, s32);
void *func_0066B428(void *a, s32 b, s32 c) {
    void *v = func_0061B038(a);
    if (v != 0) {
        return func_0065FDA0(v, b, c);
    }
    return 0;
}
