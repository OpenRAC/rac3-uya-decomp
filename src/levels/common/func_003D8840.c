#include "common.h"

/* localdecomp:start func_003D8840 */
typedef int Q_3D8840 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D8840;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 padC[0x20 - 0xC];
    s32 w20;
    s32 w24;
    s32 w28;
    u8 pad2C[0x30 - 0x2C];
    s32 w30;
    u8 pad34[0x3C - 0x34];
    s32 w3C;
    u8 pad40[0x48 - 0x40];
    s32 w48;
    s32 w4C;
} P_3D8840;

typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x24 - 0x14];
    f32 f24;
} C_3D8840;

typedef struct {
    u8 pad0[0x10];
    V4_3D8840 pos;
    u8 pad20[0x24 - 0x20];
    C_3D8840 *cls;
    u8 pad28[0x2C - 0x28];
    f32 f2C;
    u8 b30;
    u8 b31;
    s16 h32;
    u16 h34;
    u8 pad36[0x43 - 0x36];
    u8 b43;
    u8 pad44[0x68 - 0x44];
    P_3D8840 *pv;
    u8 pad6C[0x78 - 0x6C];
    u32 w78;
    u8 pad7C[0x98 - 0x7C];
    s32 w98;
    u8 pad9C[0xAA - 0x9C];
    s16 hAA;
    u8 padAC[0xC0 - 0xAC];
    V4_3D8840 m[4];
} O_3D8840;

typedef struct {
    u8 pad0[0xE];
    u8 bE;
} T_3D8840;

extern V4_3D8840 D_001E2A40;
extern s32 D_001E24B0;
extern s32 D_001DDBF0;
extern s32 D_001D545C;
extern s32 D_001D67B0;
extern s32 D_001D6740;
extern s32 D_001D673C;
extern O_3D8840 *func_00435E70(s32, s32);
extern f32 func_004408C0(f32, f32);
extern void func_003D9828(void);
extern void func_003D9AB0(void *);
extern void func_00456960(s32);
extern void func_004C41E8(void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040C8A0(void *, void *);
extern void func_00447748(void *, void *);
extern void func_004412D0(O_3D8840 *, s32, s32);
extern T_3D8840 *func_00440728(O_3D8840 *);
extern void func_00436220(O_3D8840 *);
extern void func_00441FB8(O_3D8840 *, s32, s32);
extern void func_00441C78(O_3D8840 *, s32, s32, s32);
extern void func_00439610(O_3D8840 *);

O_3D8840 *func_003D8840(O_3D8840 *src) {
    V4_3D8840 v;
    V4_3D8840 a;
    V4_3D8840 b;
    V4_3D8840 m[4];
    O_3D8840 *o;
    P_3D8840 *pv;
    T_3D8840 *t;
    Q_3D8840 x, y;
    s32 i;
    V4_3D8840 *p;

    o = func_00435E70(7486, 256);
    if (o != 0) {
        o->b30 = 127;
        o->h32 = 127;
        o->b31 = 1;
        o->pos = src->pos;
        pv = o->pv;
        pv->f0 = func_004408C0(4.0f, 5.5f);
        pv->f4 = func_004408C0(5.5f, 6.5f);
        o->w78 = 0x80808080;
        o->f2C = o->cls->f24 * 0.7f;
        pv->f8 = func_004408C0(0.021816616f, 0.058177646f);
        pv->w24 = -1;
        pv->w30 = -1;
        pv->w3C = 0;
        D_001E24B0 = 60;
        D_001DDBF0 = 0;
        func_003D9828();
        for (i = 0; i < 64; i++) {
            func_003D9AB0(&v);
        }
        if (D_001D545C == 5 && src->hAA == 6619) {
            if (++D_001D67B0 >= 15) {
                func_00456960(7);
            }
        }
        if (D_001D6740 != 0 || D_001D673C != 0) {
            func_004C41E8(&o->pos, &v);
            p = &o->m[3];
            func_0040C0F0(&v, &v, -1.0f);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->pos));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E2A40));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
            func_0040C0F0(&a, &a, 1.0f);
            func_0040BF20(&a, &a, &v);
            func_0040BF20(&b, &a, &v);
            o->m[0] = b;
            o->m[1] = a;
            o->m[2] = v;
            o->m[3] = o->pos;
            func_0040C8A0(m, o->m);
            func_00447748(m, p);
        }
        pv->w48 = 0;
        pv->w4C = 10;
        if (o->h34 & 0x1000) {
            func_004412D0(src, 0, 3);
        }
        t = func_00440728(src);
        if (t != 0 && t->bE == 1) {
            t->bE = 2;
        } else {
            func_00436220(src);
        }
        pv->w28 = 0;
        pv->w20 = 3000;
        o->w98 = o->cls->w10;
        func_00441FB8(o, 0, -1);
        if (o->b43 != 1) {
            func_00441C78(o, 1, 0, 0);
        }
        func_00439610(o);
    }
    return o;
}
/* localdecomp:end func_003D8840 */
