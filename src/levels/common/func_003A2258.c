#include "common.h"
typedef int s128 __attribute__((mode(TI)));
typedef struct S_3A2258o { u8 pad0[0x24]; f32 x24; } S_3A2258o;
typedef struct S_3A2258b { u8 pad0[0x10]; u8 x10[1]; } S_3A2258b;
typedef struct S_3A2258f { void (*x0)(struct S_3A2258m *m); } S_3A2258f;
typedef struct S_3A2258m {
    u8 pad0[0x10];
    f32 x10[4];
    u8 pad20[0x4];
    struct S_3A2258o * x24;
    u8 pad28[0x4];
    f32 x2C;
    u8 pad30[0x4];
    u16 x34;
    u8 pad36[0xD];
    u8 x43;
    u8 pad44[0x24];
    struct S_3A2258v * x68;
    u8 pad6c[0x10];
    s16 x7C;
    u8 pad7e[0x1A];
    s32 x98;
    u8 pad9c[0xE];
    s16 xAA;
    u8 padac[0x4];
    u8 xB0;
    u8 padb1[0x1];
    u16 xB2;
    u8 padb4[0x44];
    f32 xF8;
    u8 padfc[0x4];
} S_3A2258m;
typedef struct S_3A2258v {
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
    u8 x44;
    u8 pad45[0x13];
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
    u8 pada4[0x18];
    void * xBC;
    u8 padc0[0xB0];
    u8 x170;
    u8 x171;
    u8 x172;
    u8 pad173[0x3];
    u8 x176;
    u8 pad177[0x19];
    f32 x190;
    f32 x194;
    u8 pad198[0x4];
    f32 x19C;
    f32 x1A0;
    u8 pad1a4[0x4];
    u8 x1A8;
    u8 x1A9;
    s16 x1AA;
    u8 pad1ac[0x2B];
    u8 x1D7;
    u8 x1D8;
    u8 x1D9;
    u8 x1DA;
    u8 x1DB;
    s32 x1DC;
    u8 pad1e0[0x30];
    f32 x210;
    u8 pad214[0x2C];
    s32 x240;
    u8 pad244[0xA];
    u8 x24E;
    u8 x24F;
    u8 pad250[0x90];
    s32 x2E0;
    s16 x2E4;
    s16 x2E6;
    s32 x2E8;
    u8 pad2ec[0x4];
    s32 x2F0;
    s32 x2F4;
    s32 x2F8;
    u8 pad2fc[0x4];
    u8 x300[128];
    s128 x380;
    u8 pad390[0x14];
    s32 x3A4;
    u8 pad3a8[0x4];
    s32 x3AC;
    u8 pad3b0[0x4];
    s32 x3B4;
    u8 pad3b8[0x8];
    s32 x3C0;
    u8 pad3c4[0x14];
    s32 x3D8;
    s32 x3DC;
    u8 pad3e0[0x10];
    struct S_3A2258m * x3F0[8];
    u8 pad410[0x8];
    s32 x418;
    s32 x41C;
    f32 x420;
} S_3A2258v;
extern s32 D_001D545C;
extern s32 D_001D67AC;
extern u8 D_001BBC40[];
extern S_3A2258m *D_001E009C;
extern S_3A2258m *D_001E00A0;
extern void func_00436220(S_3A2258m *m);
extern s32 func_00440848(s32 a);
extern void func_004A6DF8(S_3A2258m *m, s32 a);
extern void func_00458A70(S_3A2258m *m, f32 a, f32 b, f32 c, f32 d);
extern S_3A2258f *func_00438468(s32 a, s32 b);
extern void func_00441C78(S_3A2258m *m, s32 a, s32 b, s32 c);
extern void func_00441FB8(S_3A2258m *m, s32 a, s32 b);
extern void func_003A30C8(S_3A2258m *m);
s32 func_003A2258(S_3A2258m *m) {
    S_3A2258v *v = m->x68;
    S_3A2258m *p;
    S_3A2258f *f;
    S_3A2258m **pp;
    u8 *q;
    s32 i;
    s32 n;

    if (D_001D545C == 1 && m->xB0 != 255 && (u16)(m->xB2 - 94) < 2 && (D_001BBC40[m->xB0 + 16] & 0x80)) {
        func_00436220(m);
        return 1;
    }
    D_001D67AC = 0;
    if (func_00440848(2) != 0) {
        m->x34 |= 0x8000;
    }
    m->x2C = m->x24->x24;
    v->x3F = 0;
    if (v->x3C0 == 0) {
        m->x7C = 2047;
    } else {
        m->x7C = 0;
    }
    pp = v->x3F0;
    q = v->x300;
    v->x418 = 0;
    v->x2F0 = 0;
    v->x2F4 = 0;
    v->x3DC = 0;
    for (i = 7; i >= 0; i--) {
        v->x3F0[i] = 0;
    }
    n = 0;
    for (p = D_001E009C; p < D_001E00A0; p++) {
        if (p->xAA == 7087 || p->xAA == 7821) {
            pp[n] = p;
            p->x98 = 0;
            p->x34 = (p->x34 | 0x41) & 0xEFFF;
            func_004A6DF8(p, 1);
            n++;
            if (n >= 8) {
                break;
            }
        }
    }
    v->x380 = *(s128 *)m->x10;
    v->x420 = m->xF8;
    v->x190 = 0.5f;
    v->x194 = 0.5f;
    v->x1D7 = 1;
    v->x170 = 15;
    v->x1A8 = 4;
    v->x19C = 0.15f;
    v->x171 = 5;
    v->x172 = 5;
    if (func_00440848(2) != 0) {
        v->x176 = 9;
    }
    v->x1A9 = 1;
    v->x1DB = 255;
    v->x1D8 = 1;
    v->x1D9 = 1;
    v->x1DA = 0;
    v->x1A0 = m->x10[2] - 10.0f;
    v->x1DC = v->x3D8;
    if (D_001D545C == 12) {
        v->x1AA = 10251;
    }
    v->x74 = 0.5f;
    v->xBC = q;
    v->x210 = 1.0f;
    v->x70 = 0.7f;
    v->x78 = 0.65f;
    v->x7C = 1.0f;
    v->x80 = 1.4835298f;
    v->xA0 = 0.34906584f;
    v->x9C = 0.0027222224f;
    func_00458A70(m, 0.007777778f, 0.10000001f, 0.013962635f, 0.41887906f);
    v->x58 = 20;
    v->x5A = 14;
    if (v->x34 == 0) {
        v->x34 = 5;
        v->x30 = 5.0f;
    }
    v->x40 = 2.0f;
    v->x38 = 1;
    v->x39 = 1;
    v->x3E = 1;
    v->x5E = 0;
    v->x5F = 0;
    v->x2E0 = 0;
    v->x2E4 = 0;
    v->x2E6 = 0;
    v->x2E8 = 0;
    v->x3A4 = 0;
    if (v->x240 > 0) {
        f = func_00438468(6625, 108);
        v->x240 = -1;
        if (m->x43 != 0) {
            func_00441C78(m, 0, 0, 0);
        }
        v->x24E = 18;
        v->x24F = 8;
        f->x0(m);
    } else if (v->x3B4 != 0) {
        func_00441FB8(m, 16, 6);
        m->x98 = 0;
        m->x34 = (m->x34 | 0x41) & 0xEFFF;
        func_004A6DF8(m, 1);
    } else if (v->x41C != 0) {
        func_003A30C8(m);
    } else if (v->x3AC != -1 && v->x2F8 == 0) {
        func_00441FB8(m, 1, 5);
        if (m->x43 != 0) {
            func_00441C78(m, 0, 0, 0);
        }
    } else {
        func_00441FB8(m, 2, 0);
        if (m->x43 != 0) {
            func_00441C78(m, 0, 0, 0);
        }
        if (v->x2F8 != -1) {
            func_00441FB8(m, 4, -1);
            if (m->x43 != 8) {
                func_00441C78(m, 8, 0, 0);
            }
        }
    }
    if (v->x3C0 != 0) {
        return 0;
    }
    if (v->x44 < 5) {
        v->x44 = 5;
    }
    return 0;
}
