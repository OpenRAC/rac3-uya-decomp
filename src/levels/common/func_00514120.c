#include "common.h"

extern s32 func_005139B0(void *a0, void *a1);

s32 func_00514120(void *a0, void *a1, void *a2, void *a3) {
    s32 r = func_005139B0(a0, a1) != 0;
    s32 t = func_005139B0(a0, a2) != 0;
    r = r & t;
    t = func_005139B0(a0, a3) != 0;
    return r & t;
}
