#include "common.h"
typedef struct {
    u8 pad0[16];
    f32 x;
    f32 y;
    f32 z;
    u8 pad1C[20];
    u8 b30;
    u8 pad31[3];
    u16 h34;
    u8 pad36[98];
    s32 f98;
} Obj_4C5DE0;
extern Obj_4C5DE0 *D_001E11B8;
extern void func_004C5C88(Obj_4C5DE0 *, s32);
void func_004C5DE0(void) {
    Obj_4C5DE0 *o;
    func_004C5C88(D_001E11B8, 1007);
    o = D_001E11B8;
    o->b30 = 255;
    o->h34 |= 0x43;
    o->f98 = 0;
    o->z = 5.0f;
    o->y = 5.0f;
    o->x = 5.0f;
}
