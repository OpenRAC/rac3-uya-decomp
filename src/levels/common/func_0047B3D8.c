#include "common.h"
typedef struct { s32 x0; s32 x4; s32 x8; u8 pad[228]; } Struct002C5640;
typedef struct { u8 pad[80]; s32 arr[1]; } Struct002E9FD8_0047B3D8;
extern u8 D_001425C0[];
extern Struct002C5640 D_002C5640[];
extern Struct002E9FD8_0047B3D8 D_002E9FD8;
void func_0047B3D8(s32 a0) {
    if (a0 != 0) {
        Struct002C5640 *s = D_001425C0[a0] + D_002C5640;
        D_002E9FD8.arr[s->x8] = a0;
    }
}
