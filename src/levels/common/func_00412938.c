#include "common.h"

typedef int u128_412938 __attribute__((mode(TI)));

typedef union {
    f32 v[4];
    u128_412938 q;
} __attribute__((aligned(16))) Vec4;

extern u8 *D_00249978[];
extern void func_00480F60(u8 *, s32, s32, Vec4 *, f32);

void func_00412938(s32 id)
{
    s32 i;
    u8 *p;

    if (id == 0) {
        return;
    }
    for (i = 0; i < 16; i++) {
        p = D_00249978[i];
        if (p != 0 && *(s32 *)(*(u8 **)(p + 104) + 352) == id) {
            Vec4 c;

            c.q = 0;
            c.v[0] = 1.0f;
            c.v[1] = 1.0f;
            c.v[2] = 1.0f;
            c.v[3] = 1.0f;
            func_00480F60(p, id, 0x10000, &c, 5.0f);
            return;
        }
    }
}
