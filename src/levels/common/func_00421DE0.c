#include "common.h"

/* localdecomp:start func_00421DE0 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 p0[0xC];
    void *buf;
    s32 used;
    u8 p14[0x1C];
} E_421DE0;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 f12;
    s128 q16;
} C_421DE0;

typedef struct {
    u8 b[1024];
} B_421DE0;

extern E_421DE0 D_001F1CC0[];
extern C_421DE0 D_001F1BC0[];
extern B_421DE0 D_001F1E40[];
extern void func_0040BBD0(void *p, s32 n);

s32 func_00421DE0(s128 *p, s32 color, f32 x, f32 y) {
    s32 i;
    C_421DE0 *c;
    E_421DE0 *e;

    for (i = 0; i < 8 && D_001F1CC0[i].used != 0; i++) {
    }
    if (i == 8) {
        return -1;
    }
    c = &D_001F1BC0[i];
    c->q16 = *p;
    ((f32 *)c)[7] = x;
    c->f0 = (s32)(color & 0xFF) * 0.0078125f;
    c->f4 = (s32)((color >> 8) & 0xFF) * 0.0078125f;
    c->f8 = (s32)((color >> 16) & 0xFF) * 0.0078125f;
    c->f12 = y;
    e = &D_001F1CC0[i];
    func_0040BBD0(e, 48);
    e->used = 1;
    e->buf = &D_001F1E40[i];
    return i;
}
/* localdecomp:end func_00421DE0 */
