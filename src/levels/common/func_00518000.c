#include "common.h"

extern s32 func_00518000(u8 *p, f32 a);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001DC1F0[];

extern s32 D_001DC1F0[];
s32 func_00518000(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC1F0[0])) {
        *(f32 *)(p + 0x2C) = a;
        return 1;
    }
    return 0;
}
