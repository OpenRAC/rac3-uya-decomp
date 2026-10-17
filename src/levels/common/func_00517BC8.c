#include "common.h"

extern s32 func_00517BC8(u8 *p, s32 a, s32 b);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern void func_005193E8(void *, s32, s32);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
extern s32 D_001DC1F0_g;

extern s32 D_001DC1F0_g;
extern void func_005193E8(void *, s32, s32);
s32 func_00517BC8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC1F0_g)) {
        func_005193E8(p, a, b != 0);
        return 1;
    }
    return 0;
}
