#include "common.h"
void func_005B84D0(f32 *v, u32 *out) {
    *out = ((s32)(v[0] + v[0]) << 21) | (((s32)(v[1] + v[1]) & 0x7FF) << 10) | ((s32)v[2] & 0x3FF);
}
