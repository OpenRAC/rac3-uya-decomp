#include "common.h"

typedef int s128_3D41E8 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x3C4];
    s16 x3C4;
    s16 x3C6;
    u8 p3C8[8];
    u8 x3D0;
    u8 x3D1;
    u8 x3D2;
    u8 p3D3;
    f32 x3D4;
    f32 x3D8;
    f32 x3DC;
    u8 p3E0[0xC];
    s32 x3EC;
} V_3D41E8;
typedef struct {
    u8 p0[0x10];
    s128_3D41E8 x10;
    u8 p20[3];
    u8 x23;
    u8 p24[0xC];
    u8 x30;
    u8 x31;
    u16 x32;
    u16 x34;
    u8 p36[0x32];
    V_3D41E8 *x68;
    u8 p6C[0x10];
    u16 x7C;
    u8 p7E[0x42];
    u8 xC0[1];
} M_3D41E8;
extern M_3D41E8 *func_00435E70(s32, s32);
extern void func_00441FB8(M_3D41E8 *, s32, s32);
extern f32 func_00443140(void *, s32, s32, f32);
extern s32 func_00440848(s32);
extern void func_003D3F18(M_3D41E8 *, s32, void *, void *, f32, f32, f32, f32, f32);
extern f32 func_004408C0(f32, f32);

M_3D41E8 *func_003D41E8(M_3D41E8 *o, s128_3D41E8 *pos, s32 n, s32 mode, s32 a, s32 b, u8 c,
                        f32 f0, f32 f1, f32 f2, f32 f3, f32 f4) {
    M_3D41E8 *m = func_00435E70(7181, 1008);
    if (m) {
        V_3D41E8 *v;
        s32 i;
        v = m->x68;
        m->x30 = o->x30;
        m->x32 = o->x30;
        m->x10 = *pos;
        func_00441FB8(m, 0, -1);
        v->x3D1 = c;
        v->x3D0 = mode;
        v->x3D2 = n;
        v->x3D4 = func_00443140(pos, 0, 0, 0.5f) + 0.1f;
        if (v->x3D0 == 1) {
            v->x3EC = func_00440848(2) ? 0x7F205050 : 0x7F50A0A0;
        }
        for (i = 0; i < n && i < 10; i++) {
            func_003D3F18(m, i, pos, o->xC0, f3, f4, f0, f1, f2);
        }
        if (mode == 0) {
            m->x23 = 127;
            m->x31 = 1;
            m->x34 &= ~1;
            m->x7C = (1 << func_00440848(4)) - 0x8000;
        } else {
            m->x31 = 0;
            m->x34 |= 1;
            v->x3C4 = a;
            v->x3C6 = b;
            v->x3D8 = func_004408C0(0.06f, 0.1f) * f3;
            v->x3DC = func_004408C0(0.06f, 0.1f) * f3;
        }
    }
    return m;
}
