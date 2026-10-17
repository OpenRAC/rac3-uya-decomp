#include "common.h"

extern s32 func_0058EF88(s32 *);
extern void func_00609988(f32);
extern s32 D_00352DE0[];

s32 func_00675F10(s32 arg0) {
    s32 *p;
    s32 ret;

    p = D_00352DE0;
    ret = 0;
    switch (p[5]) {
    case 0:
        if (func_0058EF88(&p[4]) != 0) {
            p[5] = 1;
            p[4] = 30;
        }
        func_00609988(1.0f);
        break;
    case 1:
        if (func_0058EF88(&p[4]) != 0) {
            p[5] = 2;
            p[4] = 300;
        }
        func_00609988((f32)p[4] / 30.0f);
        break;
    case 2:
        if (func_0058EF88(&p[4]) != 0) {
            p[5] = 3;
            p[4] = 30;
        }
        func_00609988(0.0f);
        break;
    case 3:
        if (arg0 != 0 && func_0058EF88(&p[4]) != 0) {
            ret = 1;
        }
        func_00609988(1.0f - (f32)p[4] / 30.0f);
        break;
    }
    return ret;
}
