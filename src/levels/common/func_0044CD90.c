#include "common.h"
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x20];
    u8 x20;
    u8 pad21[3];
    u8 *x24;
    u8 pad28[0x31 - 0x28];
    u8 x31;
    u8 pad32[2];
    u16 x34;
    u8 pad36[0xAA - 0x36];
    s16 xAA;
} O_44CD90;
extern O_44CD90 *D_0021E8E0[];
extern f32 *func_00440728(O_44CD90 *);
extern f32 func_0044CC18(s128 *, O_44CD90 *, f32, f32, f32, f32, s32 *);

O_44CD90 *func_0044CD90(s128 *v, s32 flag, f32 a, f32 b, f32 c, f32 d) {
    s128 pos;
    s32 hit;
    O_44CD90 *best;
    O_44CD90 *o;
    f32 bestd;
    f32 dist;
    f32 *r;
    s16 id;
    s32 i;
    s128 *pv;

    best = 0;
    pv = &pos;
    pos = *v;
    bestd = 1e8f;
    for (i = 0; (o = D_0021E8E0[i]) != 0; i++) {
        r = func_00440728(o);
        if (r == 0 || *r == 0.0f) {
            continue;
        }
        if (flag) {
            if (o->x34 & 2) {
                continue;
            }
            if (o == 0 || o->x20 == 254 || o->x20 == 253 || o->x31 == 0 || o->x24 == 0 || o->x24[70] != 5) {
                continue;
            }
            id = o->xAA;
            if (id == 6679 || id == 6951 || id == 6886 || id == 4222 || id == 7559) {
                continue;
            }
        }
        dist = func_0044CC18(pv, o, a, b, c, d, &hit);
        if (hit == 0 && dist < bestd) {
            bestd = dist;
            best = o;
        }
    }
    return best;
}
