#include "common.h"

extern void func_004CF490();

extern void func_0013D120(s32, s32, s32, s32, s32);
typedef struct { s32 f0, f4; s32 f8, fC, f10; s32 f14, f18; u8 p1C[0x2C]; s32 f48, f4C; u8 p50[0xC]; s32 f5C; } T;
void func_004CF490(T *a) {
    if (a->f4 != 3) {
        func_0013D120(a->f48, (a->f4C / 1024) * 1024, a->f48 + a->f5C, 0, 0);
    } else {
        func_0013D120(a->f48, (a->f4C / 1024) * 1024, a->f5C, a->f14, a->f18);
    }
    a->f0 = 2;
}
