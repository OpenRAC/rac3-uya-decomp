#include "common.h"

typedef struct { f32 *p0; f32 *p4; u8 p8[4]; s32 *pC; f32 *p10; u8 p14[0x1C]; u32 f30; u8 p34[4]; s32 f38; } O_3A5FC8;
extern s32 D_001DB208;
extern void func_00404D78(s32, s32, s32, s32, unsigned long, s32);
void func_004C9208(O_3A5FC8 *o) {
    f32 x; f32 y; f32 w; f32 h; unsigned long e; s32 buf[2]; s32 y2;
    f32 *pos; f32 *sz;
    if (*o->p10 != 0.0f) {
        pos = o->p0;
        sz = o->p4;
        x = pos[0];
        y = pos[1];
        e = D_001DB208;
        sz[0] = ((f32)o->f30 < sz[0]) ? (f32)o->f30 : o->p4[0];
        w = o->p4[0];
        h = o->p4[1];
        buf[0] = o->f38;
        buf[1] = o->f38;
        func_00404D78((s32)x, (s32)y, (s32)(x + (f32)o->f30), y2 = (s32)(y + h), e, (s32)buf);
        buf[0] = o->pC[0];
        buf[1] = o->pC[1];
        func_00404D78((s32)x, (s32)y, (s32)(x + w), y2, e, (s32)buf);
    }
}
