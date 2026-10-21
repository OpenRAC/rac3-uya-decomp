#include "common.h"

/* localdecomp:start func_003A4E70 */
typedef int s128_3A4E70 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x24]; f32 x24; } O_3A4E70;
typedef struct { void (*x0)(struct M_3A4E70 *m); } F_3A4E70;
typedef struct M_3A4E70 {
    u8 pad0[0x10];
    f32 x10[4];
    u8 pad20[0x4];
    O_3A4E70 *x24;
    u8 pad28[0x4];
    f32 x2C;
    u8 pad30[0x13];
    u8 x43;
    u8 pad44[0x24];
    struct V_3A4E70 *x68;
    u8 pad6c[0x8C];
    f32 xF8;
} M_3A4E70;
typedef struct V_3A4E70 {
    u8 pad0[0x30];
    f32 x30;
    s16 x34;
    u8 pad36[0x2];
    u8 x38;
    u8 x39;
    u8 pad3a[0x4];
    u8 x3E;
    u8 x3F;
    f32 x40;
    u8 pad44[0x14];
    u8 x58;
    u8 pad59[0x1];
    u8 x5A;
    u8 pad5b[0x3];
    u8 x5E;
    u8 x5F;
    u8 pad60[0x10];
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    f32 x80;
    u8 pad84[0x18];
    f32 x9C;
    f32 xA0;
    u8 pada4[0x4];
    s32 xA8;
    u8 padac[0xC4];
    u8 x170;
    u8 x171;
    u8 x172;
    u8 pad173[0x1D];
    f32 x190;
    f32 x194;
    u8 pad198[0x4];
    f32 x19C;
    u8 pad1a0[0x8];
    u8 x1A8;
    u8 pad1a9[0x2E];
    u8 x1D7;
    u8 x1D8;
    u8 x1D9;
    u8 x1DA;
    u8 x1DB;
    u8 pad1dc[0x64];
    s32 x240;
    u8 pad244[0xA];
    u8 x24E;
    u8 x24F;
    u8 pad250[0x90];
    s32 x2E0;
    s16 x2E4;
    u8 pad2e6[0x2];
    s32 x2E8;
    f32 x2EC;
    u8 pad2f0[0x10];
    s32 x300;
    u8 pad304[0x4];
    s32 x308;
    s32 x30C;
    s32 x310;
    u8 pad314[0x8];
    s32 x31C;
    s128_3A4E70 x320;
    u8 pad330[0x28];
    s32 x358;
    u8 pad35c[0x2C];
    s32 x388;
    u8 pad38c[0x1C];
    s32 x3A8;
    f32 x3AC;
} V_3A4E70;
extern f32 func_00440978(void);
extern void func_00458A70(M_3A4E70 *m, f32 a, f32 b, f32 c, f32 d);
extern F_3A4E70 *func_00438468(s32 a, s32 b);
extern void func_00441C78(M_3A4E70 *m, s32 a, s32 b, s32 c);
extern void func_00441FB8(M_3A4E70 *m, s32 a, s32 b);
extern void func_003A5800(M_3A4E70 *m);
s32 func_003A4E70(M_3A4E70 *m) {
    V_3A4E70 *v = m->x68;
    F_3A4E70 *f;

    m->x2C = m->x24->x24;
    v->x320 = *(s128_3A4E70 *)m->x10;
    v->x3AC = m->xF8;
    v->x2EC = func_00440978();
    v->x190 = 0.5f;
    v->x194 = 0.5f;
    v->x1D7 = 1;
    v->x170 = 17;
    v->x1A8 = 4;
    v->x19C = 0.15f;
    v->x171 = 4;
    v->x172 = 4;
    v->xA8 |= 4;
    v->x1D8 = 2;
    v->x1D9 = 2;
    v->x1DB = 255;
    v->x1DA = 0;
    v->x70 = 1.1f;
    v->x74 = 0.05f;
    v->x78 = 0.5f;
    v->x7C = 1.0f;
    v->x80 = 0.7853982f;
    v->xA0 = 0.34906584f;
    v->x9C = 0.0027222224f;
    func_00458A70(m, 0.0016666667f, 0.13333334f, 0.0069813174f, 0.20943953f);
    v->x58 = 20;
    v->x5A = 14;
    if (v->x34 == 0) {
        v->x34 = 4;
        v->x30 = 4.0f;
    }
    v->x40 = 0.75f;
    v->x38 = 1;
    v->x3E = 1;
    v->x39 = 0;
    v->x3F = 0;
    v->x31C = 0;
    v->x358 = -1;
    v->x388 = 0;
    v->x5E = 0;
    v->x5F = 0;
    v->x2E0 = 0;
    v->x2E4 = 0;
    v->x2E8 = 0;
    v->x308 = 0;
    v->x30C = 0;
    if (v->x240 > 0) {
        f = func_00438468(6625, 108);
        v->x240 = -1;
        if (m->x43 != 0) {
            func_00441C78(m, 0, 0, 0);
        }
        v->x24E = 15;
        v->x24F = 5;
        f->x0(m);
    } else if (v->x3A8 != 0) {
        func_003A5800(m);
    } else {
        func_00441FB8(m, 2, 0);
        if (m->x43 != 0) {
            func_00441C78(m, 0, 0, 0);
        }
        if (v->x310 != 0) {
            func_00441FB8(m, 1, -1);
        }
        if (v->x300 != -1) {
            func_00441FB8(m, 3, -1);
        }
    }
    return 0;
}
/* localdecomp:end func_003A4E70 */
