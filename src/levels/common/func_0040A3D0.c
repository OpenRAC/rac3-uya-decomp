#include "common.h"

typedef struct {
    f32 x, y, z, w;
} V40A3D0;

typedef struct {
    u8 pad0[48];
    V40A3D0 out;
    V40A3D0 pad40;
    V40A3D0 ang;
    V40A3D0 pad60;
    V40A3D0 tgt;
    V40A3D0 pad80;
    V40A3D0 scale;
} S40A3D0;

extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);

void func_0040A3D0(S40A3D0 *s) {
    s32 i;

    for (i = 1; i >= 0; i--) {
        s->ang.x = func_0040CEC8(s->ang.x, s->tgt.x);
        s->ang.y = func_0040CEC8(s->ang.y, s->tgt.y);
        s->ang.z = func_0040CEC8(s->ang.z, s->tgt.z);
        s->out.x = func_0040C3C8(s->ang.x) * s->scale.x;
        s->out.y = func_0040C3E0(s->ang.y) * s->scale.y;
        s->out.z = -func_0040C3E0(s->ang.z) * s->scale.z;
        s = (S40A3D0 *)((u8 *)s + 16);
    }
}
