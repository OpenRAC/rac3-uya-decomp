#include "common.h"
typedef struct S_3717A8vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} S_3717A8vec __attribute__((aligned(16)));
typedef struct S_3717A8v {
    u8 pad0[0x10];
    S_3717A8vec x10;
    s32 x20;
    s32 x24;
    s32 x28;
} S_3717A8v;
typedef struct S_3717A8m {
    u8 pad0[0x20];
    u8 x20;
    u8 pad21[0x10];
    u8 x31;
    u8 pad32[0x36];
    S_3717A8v *x68;
    u8 pad6c[0x10];
    s16 x7C;
} S_3717A8m;
typedef struct S_3717A8g {
    u8 pad0[0x80];
    f32 x80;
    f32 x84;
    u8 pad88[0x1188];
    s32 x1210;
    u8 pad1214[0x13B0];
    s32 x25C4;
    u8 pad25c8[0x25];
    u8 x25ED;
    u8 pad25ee[0x2CE];
    s32 x28BC;
} S_3717A8g;
typedef struct S_3717A8e {
    u8 pad0[0x140];
    f32 x140;
    f32 x144;
} S_3717A8e;
typedef struct S_3717A8l {
    u8 pad0;
    u8 x1;
    u8 pad2[0xEE];
} S_3717A8l;
typedef struct S_3717A8p {
    u8 pad0[0x1A4];
    s32 x1A4;
} S_3717A8p;
typedef struct S_3717A8r {
    u8 pad0[2];
    u8 x2;
} S_3717A8r;
typedef struct S_3717A8h {
    u8 pad0[0x5C];
    u8 *x5C;
} S_3717A8h;
extern void func_00437698(S_3717A8m *m, s32 a, S_3717A8vec *b);
extern void func_004C3888(S_3717A8vec *a, S_3717A8vec *b, s32 c, s32 d, f32 e, f32 f, f32 g, f32 h);
extern s32 func_0040BA90(s32 *a);
extern s32 func_0037B618(void);
extern s32 func_0050D8F8(s32 a, s32 b);
extern void func_004A7200(s32 a, s32 b, S_3717A8m *c);
extern void func_004E6A08(s32 a);
extern f32 func_0040BF38(S_3717A8vec *a);
extern void func_0040C0F0(S_3717A8vec *a, S_3717A8vec *b, f32 c);
extern void func_00376960(S_3717A8m *m, S_3717A8vec *a, S_3717A8vec *b, f32 c);
extern void func_004E6CB0(void);
extern s32 func_004C3E68(S_3717A8vec *a, S_3717A8vec *b, S_3717A8v *c, S_3717A8vec *d, s32 e, s32 f, s32 g, f32 h);
extern f32 func_0040C490(f32 a, f32 b);
extern f32 func_00440918(f32 a, f32 b);
extern f32 func_004408C0(f32 a, f32 b);
extern f32 func_0040CEC8(f32 a, f32 b);
extern f32 func_0040C3C8(f32 a);
extern f32 func_0040C3E0(f32 a);
extern s32 func_00440878(s32 a, s32 b);
extern S_3717A8r *func_0046DCB8(S_3717A8vec *a, S_3717A8vec *b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, f32 i, f32 j, f32 k);
extern void func_00371CB8(void);
extern void func_004026A0(void *a, S_3717A8m *m);
extern S_3717A8g D_001A4BE0;
extern f32 D_002F4DBC[];
extern u8 D_00142627[];
extern S_3717A8l D_002C5640[];
extern S_3717A8p *D_001D52FC;
extern S_3717A8e D_001E2900;
extern S_3717A8h D_00221118;
void func_003717A8(S_3717A8m *m) {
    S_3717A8v *v = m->x68;
    S_3717A8vec a;
    S_3717A8vec b;
    S_3717A8vec c;
    S_3717A8vec d;
    S_3717A8vec e;
    s32 ok;
    u8 t;
    s32 i;
    f32 ang;
    s32 r1;
    S_3717A8r *r;

    func_00437698(m, 0, &a);
    func_004C3888(&b, &a, 0, 0, 1.5f, D_001A4BE0.x25C4 == 29 ? 8.0f : 5.0f, 0.25f, 0.0030555557f);
    if (m->x31 != 0) {
        D_002F4DBC[0] = 0.1f;
    }
    ok = 1;
    if (D_001A4BE0.x25C4 == 29) {
        if (func_0040BA90(&D_001A4BE0.x28BC) == 0) {
            ok = 0;
        }
    } else {
        D_001A4BE0.x28BC = 40;
    }
    t = (D_002C5640 + D_00142627[0])->x1;
    if (t == 3) {
        m->x7C = 7;
    }
    if (t == 2) {
        m->x7C = 3;
    } else if (t == 1) {
        m->x7C = 1;
    }
    switch (m->x20) {
    case 0:
        m->x20 = 1;
        v->x28 = 1;
        v->x24 = 0;
    case 1:
        if ((D_001D52FC->x1A4 & D_001A4BE0.x1210) == 0) {
            if (!(D_001D52FC->x1A4 & 8) || D_001A4BE0.x25C4 != 29) {
                break;
            }
        }
        if (D_001A4BE0.x25ED != 0 || ok == 0) {
            break;
        }
        if (func_0037B618() != 0 || v->x28 == 0) {
            func_004A7200(3, 0, m);
        } else if (func_0050D8F8(-1, 1) != 0) {
            func_004A7200(2, 0, m);
            func_004E6A08(-1);
            m->x20 = 2;
            v->x20 = 20;
        } else {
            func_004A7200(1, 0, m);
        }
        break;
    case 2:
        if (func_0040BA90(&v->x20) != 0) {
            if (func_0040BF38(&b) > 0.33333334f) {
                func_0040C0F0(&b, &b, 0.33333334f);
            }
            func_00376960(m, &a, &b, 1.0f);
            func_004E6CB0();
            m->x20 = 3;
            v->x20 = 60;
        }
        break;
    case 3:
        if (func_0040BA90(&v->x20) != 0) {
            m->x20 = 1;
        }
        break;
    }
    if (m->x20 == 3) {
        return;
    }
    if (func_0037B618() != 0) {
        return;
    }
    v->x24 = func_004C3E68(&a, &b, v, &v->x10, 0, 0, 0, 0.0030555557f);
    func_00437698(m, 1, &c);
    for (i = 3; i >= 0; i--) {
        ang = func_0040C490(D_001A4BE0.x80 - D_001E2900.x140, D_001A4BE0.x84 - D_001E2900.x144);
        func_00440918(1.0f, 2.0f);
        d.x = c.x + func_004408C0(-0.15f, 0.15f);
        d.y = c.y + func_004408C0(-0.15f, 0.15f);
        d.z = c.z + func_004408C0(-0.15f, 0.15f);
        ang = func_0040CEC8(ang, func_00440918(0.0f, -6.2831855f));
        e.x = func_0040C3C8(ang) * 0.012500001f;
        e.y = func_0040C3E0(ang) * 0.012500001f;
        e.z = 0.0f;
        r1 = func_00440878(10, 30);
        r = func_0046DCB8(&d, &e, r1, 0x804020, func_00440878(-2, -4), 127, 0, 0, 46200.0f, 16800.0f, 0.00055555557f);
        if (r != 0) {
            r->x2 = *D_00221118.x5C;
        }
    }
    func_004026A0(func_00371CB8, m);
}
