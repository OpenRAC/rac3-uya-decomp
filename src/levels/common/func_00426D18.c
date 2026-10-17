#include "common.h"

typedef struct {
    u8 pad0[0x70];
    s32 x70;
    f32 x74;
} func_00426D18_t;

void func_00426D18(func_00426D18_t *a) {
    a->x70 = 0;
    a->x74 = 0.2f;
}
