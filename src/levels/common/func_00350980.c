#include "common.h"

extern f32 func_003F0C10(void *, void *);
extern void func_003F0638(void *);

void func_00350980(u8 *moby, u8 *vars) {
    f32 r = 7.0f;
    f32 x = *(f32 *)(vars + 784);
    if (x < r) {
        r = x;
    } else if (r < x * 0.5f) {
        r = x * 0.5f;
    }
    r = r * r;
    if (func_003F0C10(moby + 16, vars + 544) < r) {
        func_003F0638(vars + 632);
    } else {
        *(int *)(vars + 632) = 150;
    }
}
