#include "common.h"

typedef struct {
    u8 pad0[208];
    s32 table[35];
    s32 index;
} Obj329158;

extern void func_00447E88(s32, s32, s32, s32, s32, s32, s32);
extern s32 D_001DC8E0[2];

void func_00329158(s32 a0, Obj329158 *obj) {
    func_00447E88(0, 9, D_001DC8E0[obj->table[obj->index]], 1, 0, 0, 0);
}
