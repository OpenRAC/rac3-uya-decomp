#include "common.h"

/* localdecomp:start func_00346078 */
typedef struct S_346078vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} S_346078vec __attribute__((aligned(16)));
typedef struct S_346078v {
    u8 pad0[0x10];
    S_346078vec x10;
    s32 x20;
    s32 x24;
    s32 x28;
    s32 x2C;
} S_346078v;
typedef struct S_346078m {
    u8 pad0[0x20];
    u8 x20;
    u8 pad21[0x47];
    S_346078v *x68;
} S_346078m;
typedef struct S_346078r {
    u8 pad0[0xB8];
    S_346078m *xB8;
} S_346078r;
typedef struct S_346078g {
    u8 pad0[0x170];
    f32 x170;
    u8 pad174[0x109C];
    s32 x1210;
    u8 pad1214[0x13B0];
    s32 x25C4;
    u8 pad25c8[0x25];
    u8 x25ED;
    u8 pad25ee[0x2CE];
    s32 x28BC;
} S_346078g;
typedef struct S_346078p {
    u8 pad0[0x1A4];
    s32 x1A4;
} S_346078p;
extern void func_00437698(S_346078m *m, s32 a, S_346078vec *b);
extern void func_004C3888(S_346078vec *a, S_346078vec *b, s32 c, s32 d, f32 e, f32 f, f32 g, f32 h);
extern s32 func_004C3E68(S_346078vec *a, S_346078vec *b, S_346078v *c, S_346078vec *d, S_346078m *e, s32 f, s32 *g, f32 h);
extern s32 func_0040BA90(s32 *a);
extern s32 func_0050D8F8(s32 a, s32 b);
extern s32 func_0050DA08(s32 a);
extern void func_004E6A08(s32 a);
extern void func_004A7200(s32 a, s32 b, S_346078m *c);
extern S_346078r *func_0032C320(S_346078vec *a, S_346078vec *b);
extern void func_004E6CB0(void);
extern void func_003462F0(void);
extern void func_004026A0(void *a, S_346078m *m);
extern S_346078g D_001A4BE0;
extern S_346078p *D_001D52FC;
void func_00346078(S_346078m *m) {
    S_346078v *v = m->x68;
    S_346078vec a;
    S_346078vec b;
    s32 ok;

    ok = 1;
    func_00437698(m, 0, &a);
    func_004C3888(&b, &a, 0, 0, 1.5f, 11.0f, 0.25f, 0.0030555557f);
    v->x24 = func_004C3E68(&a, &b, v, &v->x10, m, 0, &v->x2C, 0.0030555557f);
    if (D_001A4BE0.x25C4 == 29) {
        if (func_0040BA90(&D_001A4BE0.x28BC) == 0) {
            ok = 0;
        }
    } else {
        D_001A4BE0.x28BC = 40;
    }
    switch (m->x20) {
    case 0:
        m->x20 = 1;
        v->x28 = 1;
        v->x24 = 0;
    case 1:
        if ((D_001D52FC->x1A4 & D_001A4BE0.x1210) != 0 && D_001A4BE0.x25ED == 0 && ok != 0 && v->x28 != 0) {
            if (func_0050D8F8(-1, 1) != 0) {
                func_004E6A08(-1);
                m->x20 = 2;
                v->x20 = 20;
            } else {
                func_004A7200(2, 0, m);
            }
        } else if (func_0050DA08(-1) == 0) {
            if ((D_001D52FC->x1A4 & D_001A4BE0.x1210) != 0) {
                func_004A7200(2, 0, m);
            }
        }
        break;
    case 2:
        if (func_0040BA90(&v->x20) != 0 || D_001A4BE0.x170 > 0.0f) {
            func_004A7200(0, 0, m);
            func_0032C320(&a, &b)->xB8 = m;
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
    func_004026A0(func_003462F0, m);
}
/* localdecomp:end func_00346078 */
