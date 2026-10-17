#include "common.h"

typedef struct {
    u8 p0[552];
    s32 w228;
    f32 f22C;
    u8 p230[568 - 560];
    f32 f238;
    f32 f23C;
    u8 p240[592 - 576];
    s32 w250;
    s32 w254;
    s32 w258;
} G_0034B8A8;

extern G_0034B8A8 D_001E7600[];
extern void func_003FFAC8(u8 *);

void func_0034B8A8(u8 *obj, f32 x) {
    G_0034B8A8 *g;
    *(s32 *)(obj + 76) = 30;
    *(f32 *)(obj + 72) = x;
    g = D_001E7600;
    g->f238 = 255.0f;
    g->f22C = x * 1024.0f * 0.4f;
    g->f23C = 100.0f;
    g->w228 = 0;
    g->w250 = 255;
    g->w254 = 255;
    g->w258 = 255;
    func_003FFAC8(obj);
}
