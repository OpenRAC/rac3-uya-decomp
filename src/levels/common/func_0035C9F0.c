#include "common.h"

/* localdecomp:start func_0035C9F0 */
typedef struct S_35C9F0vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} S_35C9F0vec __attribute__((aligned(16)));
typedef struct S_35C9F0v {
    u8 pad0[0x10];
    S_35C9F0vec x10;
    s32 x20;
    s32 x24;
    s32 x28;
    s32 x2C;
    s32 x30;
} S_35C9F0v;
typedef struct S_35C9F0m {
    u8 pad0[0x20];
    u8 x20;
    u8 pad21[0x10];
    u8 x31;
    u8 pad32[0x36];
    S_35C9F0v *x68;
} S_35C9F0m;
typedef struct S_35C9F0r {
    u8 pad0[0xB8];
    S_35C9F0m *xB8;
} S_35C9F0r;
typedef struct S_35C9F0g {
    u8 pad0[0x1210];
    s32 x1210;
    u8 pad1214[0x49C];
    s32 x16B0;
    u8 pad16b4[0xF10];
    s32 x25C4;
    u8 pad25c8[0x25];
    u8 x25ED;
    u8 pad25ee[0x2CE];
    s32 x28BC;
} S_35C9F0g;
typedef struct S_35C9F0l {
    u8 pad0;
    u8 x1;
    u8 pad2[0xEE];
} S_35C9F0l;
typedef struct S_35C9F0p {
    u8 pad0[0x1A4];
    s32 x1A4;
} S_35C9F0p;

extern void func_00437698(S_35C9F0m *m, s32 a, S_35C9F0vec *b);
extern void func_004C3888(S_35C9F0vec *a, S_35C9F0vec *b, s32 c, s32 d, f32 e, f32 f, f32 g, f32 h);
extern s32 func_004C3E68(S_35C9F0vec *a, S_35C9F0vec *b, S_35C9F0v *c, S_35C9F0vec *d, S_35C9F0m *e, s32 f, s32 *g, f32 h);
extern s32 func_0040BA90(s32 *a);
extern s32 func_0050D8F8(s32 a, s32 b);
extern s32 func_0050DA08(s32 a);
extern void func_004E6A08(s32 a);
extern void func_004A7200(s32 a, s32 b, S_35C9F0m *c);
extern s32 func_003C15A8(void);
extern s32 func_003C0F78(S_35C9F0m *m, void *a);
extern f32 func_0040BF38(S_35C9F0vec *a);
extern void func_0040C0F0(S_35C9F0vec *a, S_35C9F0vec *b, f32 c);
extern S_35C9F0r *func_0035D178(S_35C9F0vec *a, S_35C9F0vec *b);
extern void func_004E6CB0(void);
extern void func_0035CDA0(void);
extern void func_004026A0(void *a, S_35C9F0m *m);
extern S_35C9F0g D_001A4BE0;
extern u8 D_001A4C60[];
extern f32 D_002F4DBC[];
extern u8 D_00142617[];
extern S_35C9F0l D_002C5640[];
extern S_35C9F0p *D_001D52FC;
extern s32 D_001DD728;

void func_0035C9F0(S_35C9F0m *m) {
    S_35C9F0v *v = m->x68;
    S_35C9F0vec a;
    S_35C9F0vec b;
    s32 ok;
    s32 t;
    s32 i;

    func_00437698(m, 0, &a);
    func_004C3888(&b, &a, 0, 0, 1.5f, D_001A4BE0.x16B0 == 2 ? 11.0f : 4.5f, 0.25f, 0.0030555557f);
    ok = 1;
    v->x24 = func_004C3E68(&a, &b, v, &v->x10, m, 0, &v->x2C, 0.0030555557f);
    if (D_001A4BE0.x25C4 == 29) {
        if (func_0040BA90(&D_001A4BE0.x28BC) == 0) {
            ok = 0;
        }
    } else {
        D_001A4BE0.x28BC = 40;
    }
    t = (D_002C5640 + D_00142617[0])->x1;
    if (m->x31 != 0) {
        D_002F4DBC[0] = 0.1f;
    }
    func_0040BA90(&v->x30);
    switch (m->x20) {
    case 0:
        do {
            m->x20 = 1;
            v->x28 = 1;
            v->x24 = 0;
        } while (0);
    case 1:
        if (((D_001D52FC->x1A4 & D_001A4BE0.x1210) != 0
             || ((D_001D52FC->x1A4 & 8) && D_001A4BE0.x25C4 == 29))
            && D_001A4BE0.x25ED == 0 && ok != 0 && v->x28 != 0 && D_001DD728 < 8 && v->x30 == 0) {
            if (func_0050DA08(-1) != 0) {
                func_004E6A08(-1);
                m->x20 = 2;
                v->x20 = 20;
                v->x30 = 45;
            } else {
                func_004A7200(0, 0, m);
            }
        } else if (func_0050DA08(-1) == 0 || D_001DD728 >= 8) {
            if ((D_001D52FC->x1A4 & D_001A4BE0.x1210) != 0) {
                func_004A7200(0, 0, m);
            }
        }
        break;
    case 2:
        if (func_0040BA90(&v->x20) != 0) {
            func_0050D8F8(-1, 1);
            if (t >= 3 && func_003C15A8() != 0) {
                for (i = 3; i >= 0; i--) {
                    if (func_003C15A8() != 0) {
                        func_003C0F78(m, D_001A4C60);
                        D_001DD728++;
                    }
                }
            } else {
                if (func_0040BF38(&b) > 0.33333334f) {
                    func_0040C0F0(&b, &b, 0.33333334f);
                }
                func_0035D178(&a, &b)->xB8 = m;
            }
            func_004E6CB0();
            m->x20 = 3;
            v->x20 = 10;
        }
        break;
    case 3:
        if (func_0040BA90(&v->x20) != 0) {
            m->x20 = 1;
        }
        break;
    }
    func_004026A0(func_0035CDA0, m);
}
/* localdecomp:end func_0035C9F0 */
