#include "common.h"

extern u8 *D_001EA758[];
extern void func_004305D8(s32, s32, void *);
extern s32 func_003F1D60(void *, void *, s32, void *, s32);

s32 func_00359BA0(u8 *arg0)
{
    u8 *v;
    u8 *o;
    s32 buf[4];

    v = *(u8 **)(arg0 + 104);
    func_004305D8(*(s32 *)(v + 1004), 0, buf);
    if (func_003F1D60(buf, v + 544, 0, arg0, 0)) {
        o = D_001EA758[0];
        if (o != 0 && *(s16 *)(o + 170) == 5669) {
            return o == *(u8 **)(v + 560);
        }
    }
    return 1;
}
