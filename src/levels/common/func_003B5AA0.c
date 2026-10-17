#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern void func_003B5698(u8 *a0, s32 a1);
extern void func_00447118(u8 *a0, s32 a1, s32 a2);

void func_003B5AA0(u8 *moby, Vec4 *pos, s32 force, f32 value) {
    Vec4 v;
    u8 *vars;

    v = *pos;
    vars = *(u8 **)(moby + 104);
    if (force != 0 || moby[149] == 1) {
        func_003B5698(moby, 0);
        *(Vec4 *)(vars + 1296) = v;
        *(f32 *)(vars + 1320) = value;
        func_00447118(moby, 30, 6);
    }
}
