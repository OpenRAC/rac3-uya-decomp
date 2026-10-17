#include "common.h"

extern s32 func_00518590(u8 *p, f32 a, f32 b);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001DC1C0[];

extern s32 D_001DC1C0[];
s32 func_00518590(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC1C0[0])) {
        *(f32 *)(p + 0x34) = a;
        *(f32 *)(p + 0x38) = b;
        return 1;
    }
    return 0;
}
