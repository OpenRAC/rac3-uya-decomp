#include "common.h"
typedef struct S_343088vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} S_343088vec __attribute__((aligned(16)));
typedef struct S_343088v {
    u8 pad0[0x10];
    S_343088vec x10;
    s32 x20;
    s32 x24;
} S_343088v;
typedef struct S_343088m {
    u8 pad0[0x20];
    u8 x20;
    u8 pad21[0x47];
    S_343088v *x68;
} S_343088m;
typedef struct S_343088g {
    u8 pad0[0x1210];
    s32 x1210;
    u8 pad1214[0x13B0];
    s32 x25C4;
    u8 pad25c8[0x25];
    u8 x25ED;
    u8 pad25ee[0x2CE];
    s32 x28BC;
} S_343088g;
typedef struct S_343088p {
    u8 pad0[0x1A4];
    s32 x1A4;
} S_343088p;
extern void func_00437698(S_343088m *m, s32 a, S_343088vec *b);
extern void func_004C3888(S_343088vec *a, S_343088vec *b, s32 c, s32 d, f32 e, f32 f, f32 g, f32 h);
extern s32 func_004C3E68(S_343088vec *a, S_343088vec *b, S_343088v *c, S_343088vec *d, S_343088m *e, s32 f, s32 g, f32 h);
extern s32 func_0040BA90(s32 *a);
extern s32 func_0050D8F8(s32 a, s32 b);
extern s32 func_0050DA08(s32 a);
extern void func_004E6A08(s32 a);
extern void func_004A7200(s32 a, s32 b, S_343088m *c);
extern void func_0032F3D8(S_343088m *m, S_343088vec *a, S_343088vec *b);
extern void func_004E6CB0(void);
extern void func_003432F8(void);
extern void func_004026A0(void *a, S_343088m *m);
extern S_343088g D_001A4BE0;
extern S_343088p *D_001D52FC;
extern s32 D_00278C30[];
void func_00343088(S_343088m *m) {
    S_343088v *v = m->x68;
    S_343088vec a;
    S_343088vec b;
    s32 ok;

    ok = 1;
    func_00437698(m, 0, &a);
    func_004C3888(&b, &a, 0, 0, 1.5f, 11.0f, 0.25f, 0.0030555557f);
    v->x24 = func_004C3E68(&a, &b, v, &v->x10, m, 0, 0, 0.0030555557f);
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
        v->x24 = 0;
    case 1:
        if ((D_001D52FC->x1A4 & D_001A4BE0.x1210) != 0 && D_001A4BE0.x25ED == 0 && ok != 0 && D_00278C30[0] < 6) {
            if (func_0050D8F8(-1, 1) != 0) {
                func_004E6A08(-1);
                m->x20 = 2;
                v->x20 = 20;
            } else {
                func_004A7200(2, 0, m);
            }
        } else if (func_0050DA08(-1) == 0 || D_00278C30[0] >= 7) {
            if ((D_001D52FC->x1A4 & D_001A4BE0.x1210) != 0) {
                func_004A7200(2, 0, m);
            }
        }
        break;
    case 2:
        if (func_0040BA90(&v->x20) != 0) {
            func_004A7200(0, 0, m);
            func_0032F3D8(m, &a, &b);
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
    func_004026A0(func_003432F8, m);
}
