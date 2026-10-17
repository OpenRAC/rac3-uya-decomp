#include "common.h"

extern void func_0043B6B0(void *, f32, f32, f32, f32);
extern void func_00350D70(void *, void *, s32);
extern void func_00350CA8(void *, void *, s32, s32, s32);

void func_00350AC8(u8 *a0, void *a1, s32 a2)
{
    if (a0[67] == a2) {
        return;
    }
    switch (a2) {
    case 5:
        func_0043B6B0(a0, 0.00416666688f, 0.166666672f, 0.00698131742f, 0.209439531f);
        func_00350D70(a0, a1, 5);
        break;
    case 20:
        func_0043B6B0(a0, 0.00388888898f, 0.0833333358f, 0.00698131742f, 0.209439531f);
        func_00350CA8(a0, a1, 20, 0, 10);
        break;
    case 21:
        func_0043B6B0(a0, 0.00388888898f, -0.0833333358f, 0.00698131742f, 0.209439531f);
        func_00350CA8(a0, a1, 21, 0, 10);
        break;
    }
}
