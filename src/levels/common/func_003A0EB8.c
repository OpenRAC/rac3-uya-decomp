#include "common.h"

/* localdecomp:start func_003A0EB8 */
typedef struct { f32 x, y; } UV_3A0EB8;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0xC];
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 pad34[0x20];
    f32 f54;
    f32 f58;
    u8 pad5C[4];
    UV_3A0EB8 uv[1];
} S_3A0EB8;
extern f32 D_001D5324[];
extern UV_3A0EB8 D_001DC9A8[];
extern UV_3A0EB8 D_001DC9C8[];
extern f32 func_003E5630(f32 a, f32 b);
extern f32 func_003E4B30(f32 a);
extern f32 func_003E4B48(f32 a);

void func_003A0EB8(void *o, S_3A0EB8 *s) {
    UV_3A0EB8 *tab;
    UV_3A0EB8 *p;
    s32 i;
    f32 x, y, ang, c, d;
    if (s->f10 == 0 || (tab = D_001DC9C8, s->f14 < 3)) {
        tab = D_001DC9A8;
    }
    for (i = 0; i < s->f14; i++, tab++) {
        p = &s->uv[i];
        ang = D_001D5324[0] * s->f24;
        {
            f32 nx = p->x + tab->x * ang;
            f32 ny = p->y + tab->y * ang;
            y = ny - (s32)ny;
            x = nx - (s32)nx;
        }
        p->y = y;
        p->x = x;
        if (s->f54 != 0.0f || s->f58 != 0.0f) {
            f32 nx = x + s->f54;
            f32 ny = y + s->f58;
            p->x = nx - (s32)nx;
            p->y = ny - (s32)ny;
        }
        if (s->f28 != 0.0f) {
            ang = s->f30 = func_003E5630(s->f30, s->f2C);
            if (i & 1) {
                ang = -ang;
            }
            c = tab->x * s->f28 * func_003E4B30(ang);
            d = tab->y * s->f28 * func_003E4B48(ang);
            {
                f32 nx = p->x + c;
                f32 ny = p->y + d;
                p->x = nx - (s32)nx;
                p->y = ny - (s32)ny;
            }
        }
    }
}
/* localdecomp:end func_003A0EB8 */
