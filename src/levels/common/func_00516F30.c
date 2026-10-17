#include "common.h"

extern s32 func_00516F30(u8 *p, s32 a);
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
extern s32 D_001DC250_g;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;

extern s32 D_001DC250_g;
extern void func_0051C2C0(void *, s32);
s32 func_00516F30(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_001DC250_g)) {
        func_0051C2C0(p, a);
        return 1;
    }
    return 0;
}
