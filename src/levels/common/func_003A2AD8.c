#include "common.h"

/* localdecomp:start func_003A2AD8 */
typedef struct { u8 pad0[0xAA]; s16 fAA; } M_3A2AD8;
typedef struct { u8 pad0[0x20]; M_3A2AD8 *f20; } P_3A2AD8;
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    u8 pad34[0xA];
    u8 f3E;
    u8 pad3F[0x1F];
    u8 f5E;
    u8 f5F;
    u8 pad60[0x100];
    u8 f160[0x160];
    s32 f2C0;
    f32 f2C4;
    s32 f2C8;
    f32 f2CC;
    u8 pad2D0[0x10];
    u8 f2E0[0x10];
} S_3A2AD8;
typedef struct { u8 pad0[0x20]; u8 f20; u8 pad21[0x47]; S_3A2AD8 *f68; u8 pad6C[0x29]; u8 f95; u8 pad96[0x1C]; s16 fB2; } O_3A2AD8;
extern s32 D_001D545C;
extern s32 D_001D67B0;
extern s32 D_001DE540;
extern s32 func_003A2DA8(O_3A2AD8 *o);
extern void func_003A30F0(O_3A2AD8 *o);
extern void func_003A3218(O_3A2AD8 *o);
extern P_3A2AD8 *func_0041BAB0(O_3A2AD8 *o, s32 a, s32 b);
extern s32 func_00426E90(O_3A2AD8 *o, void *p, s32 a, s32 b, s32 c);
extern s32 func_004267D8(O_3A2AD8 *o, void *p, s32 a);
extern void func_0042D2A8(s32 a);
extern void func_0042AA80(O_3A2AD8 *o, s32 a);
extern void func_0042AB48(O_3A2AD8 *o, s32 a, f32 x, f32 y, f32 z, void *b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);

s32 func_003A2AD8(O_3A2AD8 *o) {
    S_3A2AD8 *s = o->f68;
    M_3A2AD8 *m;
    P_3A2AD8 *p;
    if (o->f20 == 0 && func_003A2DA8(o) != 0) {
        return 1;
    }
    if (s->f3E == 2) {
        func_003A30F0(o);
        return 1;
    }
    m = 0;
    if (D_001D545C == 5) {
        p = func_0041BAB0(o, 0x10000, 1);
        if (p != 0) {
            m = p->f20;
        }
    }
    if (func_00426E90(o, s->f160, 0, 0, 0) != 0) {
        func_003A3218(o);
        if (D_001D545C == 5 && s->f30 <= 0.0f && m != 0 &&
            (m->fAA == 0x189B || m->fAA == 0x1BC3 || m->fAA == 0x1D3E)) {
            if (++D_001D67B0 >= 0xF) {
                func_0042D2A8(7);
            }
        }
    }
    func_004267D8(o, &s->f30, 0);
    if (s->f5E != 0) {
        func_003A30F0(o);
        return 1;
    }
    if ((o->fB2 + 8) % 8 != D_001DE540 % 8) {
        return 0;
    }
    if (s->f5F != 0) {
        func_0042AA80(o, 3);
        if (o->f95 == 0) {
            func_0042AB48(o, s->f2C0, s->f2C4, 10.0f, 1.0f, 0, 0, 0, 0, 3, 0, 0, 0);
        } else {
            func_0042AB48(o, s->f2C8, s->f2CC, 10.0f, 1.0f, 0, 0, 0, 0, 3, 0, 0, 0);
        }
    } else {
        if (s->f2CC > 0.0f) {
            func_0042AA80(o, 3);
        }
        if (o->f95 == 0) {
            func_0042AB48(o, s->f2C0, s->f2C4, 10.0f, 1.0f, s->f2E0, 0, 0, 0, 1, 0, 0, 0);
        } else {
            func_0042AB48(o, s->f2C8, s->f2CC, 10.0f, 1.0f, s->f2E0, 0, 0, 0, 1, 0, 0, 0);
        }
    }
    return 0;
}
/* localdecomp:end func_003A2AD8 */
