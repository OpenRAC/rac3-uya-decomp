#include "common.h"
typedef struct S_351E18o {
    u8 pad0[0x10];
    s32 x10;
} S_351E18o;
typedef struct S_351E18m {
    u8 pad0[0x10];
    f32 x10;
    f32 x14;
    f32 x18;
    u8 pad1c[4];
    u8 x20;
    u8 pad21[3];
    S_351E18o *x24;
    u8 pad28[8];
    u8 x30;
    u8 x31;
    u8 pad32[2];
    u8 x34;
    u8 pad35[0x33];
    struct S_351E18v *x68;
    u8 pad6c[3];
    u8 x6F;
    u8 pad70[0x25];
    u8 x95;
    u8 pad96[2];
    s32 x98;
    u8 pad9c[0x16];
    s16 xB2;
} S_351E18m;
typedef struct S_351E18v {
    u8 pad0[0x30];
    f32 x30;
    u8 pad34[0x0A];
    u8 x3E;
    u8 pad3f[0x1F];
    u8 x5E;
    u8 x5F;
    u8 pad60[0x1E0];
    s32 x240;
    u8 pad244[0x8C];
    s32 x2D0;
    f32 x2D4;
    s32 x2D8;
    f32 x2DC;
    u8 pad2e0[0x30];
    u8 x310[0x30];
    unsigned long x340;
    u8 pad348[0x9C];
    s32 x3E4;
    u8 pad3e8[8];
    S_351E18m *x3F0[8];
    u8 pad410[0x1D4];
    s32 x5E4;
} S_351E18v;
extern s32 func_00352328(S_351E18m *m);
extern void func_00439610(S_351E18m *m);
extern f32 func_0040C018(void *a, void *b);
extern void func_00444188(S_351E18m *m);
extern void func_00352978(S_351E18m *m);
extern void func_00352D38(void);
extern void func_003154D8(S_351E18m *m, s32 a, void *b);
extern void func_0044F5E8(S_351E18m *m, void *a, s32 b);
extern s32 func_0044FC98(S_351E18m *m, s32 a, s32 b, s32 c);
extern void func_00352B58(S_351E18m *m);
extern void func_004538E0(S_351E18m *m, s32 a);
extern void func_004539A8(S_351E18m *m, s32 a1, f32 f12, f32 f13, void *a2, s32 a3, s32 t0, s32 t1, f32 f14, s32 t2, s32 t3, s32 s0, s32 s8);
extern s32 D_001D545C;
extern s32 D_001DFBC0;
extern u8 D_001E2AC0[];
s32 func_00351E18(S_351E18m *m) {
    S_351E18v *v = m->x68;
    s32 i;
    s32 j;

    if (m->x20 == 0 && func_00352328(m) != 0) {
        return 1;
    }
    if (v->x30 > 0.0f) {
        for (i = 0; i < 8; i++) {
            if (v->x3F0[i] != 0) {
                v->x3F0[i]->x98 = v->x3F0[i]->x24->x10;
                func_00439610(v->x3F0[i]);
            }
        }
    }
    if ((m->x34 ^ 1) & 1) {
        if (m->x31 != 0 && func_0040C018(D_001E2AC0, &m->x10) < 576.0f) {
            func_00444188(m);
            m->x6F = 22;
        }
    }
    if (v->x3E == 2) {
        func_00352978(m);
        return 1;
    }
    if (m->x18 <= 79.0f && v->x240 != 0 && D_001D545C == 1) {
        func_00352978(m);
        func_003154D8(m, 0, func_00352D38);
        return 1;
    }
    if (m->x10 < 2.0f || m->x10 > 1021.0f || m->x14 < 2.0f || m->x14 > 1021.0f || m->x18 < 2.0f || m->x18 > 1021.0f) {
        return 1;
    }
    func_0044F5E8(m, &v->x30, 0);
    if (func_0044FC98(m, 0, 0, 0) != 0) {
        for (j = 0; j < 8; j++) {
            if (v->x3F0[j] != 0) {
                v->x3F0[j]->x98 = 0;
                func_00439610(v->x3F0[j]);
            }
        }
        func_00352B58(m);
    }
    if (v->x5E != 0) {
        func_00352978(m);
        return 1;
    }
    if (((*(unsigned long *)&m->x30 & 0x104100000000UL) != 0x4100000000UL || m->x98 != 0) && v->x30 > 0.0f && m->x95 != 0) {
        if (v->x5F != 0) {
            func_004538E0(m, 5);
        } else if (D_001D545C != 9 || (u8)(m->x95 - 3) < 2) {
            func_004538E0(m, 3);
        }
    }
    if ((m->xB2 + 8) % 8 != D_001DFBC0 % 8) {
        return 0;
    }
    if (v->x5F != 0) {
        if (m->x95 == 1) {
            func_004539A8(m, v->x2D0, v->x2D4, 10.0f, v->x310, 0, 0, 0, 1.0f, 3, 0, 0, 0);
        } else {
            func_004539A8(m, v->x2D8, v->x2DC, 10.0f, v->x310, 0, 0, 0, 1.0f, 3, 0, 0, 0);
        }
    } else if (m->x95 == 1 || (m->x95 == 7 && (v->x340 & 0xFFFFFFFF00000000UL))) {
        if (v->x3E4 != 0) {
            func_004539A8(m, v->x2D0, v->x2D4, 10.0f, v->x310, 0, 0, 0, 1.0f, 2, 0, 0, 0);
        } else {
            func_004539A8(m, v->x2D0, v->x2D4, 10.0f, v->x310, 0, 0, 0, 1.0f, 1, v->x5E4 != 0, 0, 0);
        }
    } else {
        if (v->x3E4 != 0) {
            func_004539A8(m, v->x2D8, v->x2DC, 10.0f, v->x310, 0, 0, 0, 1.0f, 2, 0, 0, 0);
        } else {
            func_004539A8(m, v->x2D8, v->x2DC, 10.0f, v->x310, 0, 0, 0, 1.0f, 1, v->x5E4 != 0, 0, 0);
        }
    }
    return 0;
}
