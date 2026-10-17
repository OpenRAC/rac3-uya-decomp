#include "common.h"

extern s32 func_00518AB8(u8 *p, f32 a);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001DC280[];

extern s32 D_001DC280[];
s32 func_00518AB8(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC280[0])) {
        *(f32 *)(p + 0x3C) = a;
        return 1;
    }
    return 0;
}
