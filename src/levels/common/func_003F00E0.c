#include "common.h"

typedef struct {
    u8 pad[80];
    u8 *obj;
    u8 pad2[1120 - 84];
} Unk003F00E0;

extern Unk003F00E0 D_001E2B00[];

void func_003F00E0(s32 i, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    Unk003F00E0 *ent = &D_001E2B00[i];
    u8 *p = ent->obj;
    f32 *v = (f32 *)(*(u8 **)(p + 112) + 48);
    f32 *w;
    v[8] = e;
    v[9] = d;
    v[10] = f;
    w = (f32 *)*(u8 **)(p + 112);
    w[4] = b;
    w[5] = a;
    w[6] = c;
}
