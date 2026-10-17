#include "common.h"
extern f32 D_001D5FE8[2];
f32 *func_003F1200(int i, f32 v) {
    f32 *p = &D_001D5FE8[i];
    *p = v;
    return p;
}
