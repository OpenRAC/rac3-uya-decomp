#include "common.h"

typedef struct {
    s32 a;
    f32 b;
    s32 c;
    f32 d;
} Src_3D1EB8;

extern void func_00442CC0(void *a0, s32 a1, s32 a2);

void func_003D1EB8(u8 *a0, u8 *a1)
{
    Src_3D1EB8 *s = *(Src_3D1EB8 **)(a1 + 104);
    u8 *d = *(u8 **)(a0 + 104);

    *(s32 *)(d + 608) = s->a;
    if (0.0f < s->b) {
        *(f32 *)(d + 612) = s->b;
    }
    *(s32 *)(d + 616) = s->c;
    if (0.0f < s->d) {
        *(f32 *)(d + 620) = s->d;
    }
    func_00442CC0(a0, 0, 0);
}
