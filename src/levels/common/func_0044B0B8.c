#include "common.h"

/* localdecomp:start func_0044B0B8 */
typedef struct {
    u8 p0[0x23];
    u8 b35;
    u8 p24[0xC];
    u8 b48;
    u8 b49;
    u16 h50;
    u16 h52;
    u8 p36[2];
    unsigned long d56;
    u8 p40[0x38];
    s32 w120;
    u16 h124;
    u8 p7E[0x1A];
    s32 w152;
    u8 p9C[0xE];
    s16 h170;
} M_44B0B8;

typedef struct {
    u8 p0[0x2C];
    f32 f44;
} F_44B0B8;

typedef struct {
    u8 p0[0x100];
    s32 a256[4];
    s32 a272[4];
    M_44B0B8 *a288[4];
    f32 a304[4];
    u8 p140[4];
    M_44B0B8 *parent;
    s32 count;
} O_44B0B8;

extern M_44B0B8 *func_00435E70(s32 oClass, s32 flags);

void func_0044B0B8(O_44B0B8 *o, s32 a, s32 b, f32 f) {
    M_44B0B8 *m;

    if (o->count == 4 || b >= 9) {
        return;
    }
    m = func_00435E70(o->parent->h170, 128);
    if (m == 0) {
        return;
    }
    m->h124 = o->parent->h124;
    m->h50 = o->parent->h50;
    m->d56 = o->parent->d56;
    ((F_44B0B8 *)m)->f44 = ((F_44B0B8 *)o->parent)->f44;
    m->w120 = o->parent->w120;
    m->b49 = 1;
    m->h52 = 0x80A;
    m->b48 = 0;
    m->h52 = (o->parent->h52 & 0x8000) | 0x80A;
    m->w152 = 0;
    m->b35 = a;
    o->a272[o->count] = b;
    o->a256[o->count] = a;
    o->a304[o->count] = f;
    o->a288[o->count] = m;
    o->count++;
}
/* localdecomp:end func_0044B0B8 */
