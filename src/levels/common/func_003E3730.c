#include "common.h"
typedef struct { u8 pad[0x120]; f32 x120[3]; } V_3E3730;
typedef struct { u8 pad[0x70]; V_3E3730 *x70; } O_3E3730;
extern f32 func_003F13A8(f32 *, f32, f32, f32, f32, f32);
void func_003E3730(O_3E3730 *a0, f32 *a1, f32 *a2, f32 b, f32 c, f32 d) {
    V_3E3730 *v = a0->x70;
    a1[0] = func_003F13A8(&v->x120[0], a1[0], a2[0], b, c, d);
    a1[1] = func_003F13A8(&v->x120[1], a1[1], a2[1], b, c, d);
    a1[2] = func_003F13A8(&v->x120[2], a1[2], a2[2], b, c, d);
}
