#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u8 p0[0x24]; f32 f24;
} S_Class3D3430;

typedef struct {
    u128_t q0;
    u8 p10[0x20 - 0x10];
    f32 f20;
    s32 i24;
    s32 i28;
    s32 i2C;
    u8 p30[0x38 - 0x30];
    f32 f38;
    s32 i3C;
} S_Vars3D3430;

typedef struct {
    u8 p0[0x10];
    u128_t q10;
    u8 p20[0x24 - 0x20];
    S_Class3D3430 *cls;
    s32 p28;
    f32 f2C;
    u8 b30;
    u8 b31;
    s16 h32;
    u8 p34[0x68 - 0x34];
    S_Vars3D3430 *vars;
    u8 p6C[0xB8 - 0x6C];
    s32 iB8;
    u8 pBC[0xC0 - 0xBC];
    u8 vC0[0x30];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} S_Moby3D3430;

typedef struct { f32 x, y, z, w; } V4_3D3430;

extern s32 D_001A65C0[];
extern S_Moby3D3430 *func_00436FB0(s32, s32);
extern f32 func_0040D7F0(V4_3D3430 *);
extern f32 func_0040DD18(f32, f32);
extern void func_0040DEC0(void *, f32 *);
extern f32 func_0040D7C0(V4_3D3430 *);
extern void func_004430D8(S_Moby3D3430 *, s32, s32);
extern void func_0043A730(S_Moby3D3430 *);

S_Moby3D3430 *func_003D3430(s32 a0, s32 a1, u128_t *pos, V4_3D3430 *dir, f32 f) {
    S_Moby3D3430 *o;
    S_Vars3D3430 *v;

    o = func_00436FB0(7191, 128);

    if (o != 0) {
        v = o->vars;
        o->iB8 = a0;
        v->i28 = a1;
        o->b30 = 255;
        o->h32 = 64;
        o->b31 = 1;
        o->f2C = o->cls->f24 * 0.75f;
        o->q10 = *pos;
        o->fF4 = -func_0040DD18(func_0040D7F0(dir), dir->z);
        o->fF8 = func_0040DD18(dir->x, dir->y);
        func_0040DEC0(o->vC0, &o->fF0);
        v->q0 = *(u128_t *)dir;
        v->f38 = func_0040D7C0(dir);
        v->f20 = f;
        if (D_001A65C0[0] != 0) {
            v->i24 = 420;
        } else {
            v->i24 = 160;
        }
        v->i2C = 0;
        v->i3C = -1;
        func_004430D8(o, 1, -1);
        func_0043A730(o);
    }
    return o;
}
