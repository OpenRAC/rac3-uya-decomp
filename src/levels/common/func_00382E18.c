#include "common.h"

/* localdecomp:start func_00382E18 */
typedef int Q_382E18 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_382E18;
typedef struct {
    V4_382E18 r0;
    V4_382E18 r1;
    V4_382E18 r2;
} M_382E18;
typedef struct {
    f32 f0, f4, f8;
    void *pC;
    void *p10;
    u8 pad14[0x18 - 0x14];
    f32 f18;
    f32 f1C;
    f32 f20;
    s16 h24;
    u8 b26;
    u8 b27;
    f32 f28;
    u8 pad2C[0x30 - 0x2C];
    V4_382E18 v30;
    V4_382E18 v40;
    s32 w50;
    s32 w54;
} S_382E18;
typedef struct O_382E18 {
    u8 pad0[0x10];
    V4_382E18 v10;
    u8 b20;
    u8 pad21[0x2C - 0x21];
    f32 f2C;
    u8 b30;
    u8 b31;
    s16 h32;
    u16 h34;
    u8 pad36[0x68 - 0x36];
    S_382E18 *p68;
    u8 pad6C[0xBC - 0x6C];
    u8 bBC;
    u8 padBD[0xC0 - 0xBD];
    M_382E18 m;
} O_382E18;
typedef struct {
    u8 pad0[0x6E0];
    V4_382E18 v6E0;
    V4_382E18 v6F0;
    u8 pad700[0x16B0 - 0x700];
    s32 w16B0;
    u8 pad16B4[0x25C0 - 0x16B4];
    u8 *p25C0;
    s32 w25C4;
    u8 pad25C8[0x2874 - 0x25C8];
    s16 h2874;
} G_382E18;
typedef struct {
    u8 pad0[0x4C];
    f32 f4C;
    u8 pad50[0xF0 - 0x50];
} T_382E18;
extern G_382E18 D_001A4BE0;
extern f32 D_001E2A40;
extern M_382E18 D_001E2A60;
extern V4_382E18 D_001EAAA0;
extern u8 D_00142657[];
extern T_382E18 D_002C5640[];
extern s32 D_001E01C0;
extern O_382E18 *func_00435E70(s32, s32);
extern void func_004C74C0(void *, void *, s32);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern f32 func_004408C0(f32, f32);
extern f32 func_00440918(f32, f32);
extern f32 func_00440978(void);
extern void func_00439610(O_382E18 *);
extern void func_00448BD8(O_382E18 *, void *, s32);
extern s32 func_004C4A18(O_382E18 *, s32, f32, f32, f32);
O_382E18 *func_00382E18(O_382E18 *src, V4_382E18 *pos, O_382E18 *tgt, V4_382E18 *a3) {
    V4_382E18 t;
    V4_382E18 v16;
    V4_382E18 v32;
    V4_382E18 v48;
    V4_382E18 v64;
    V4_382E18 v80;
    O_382E18 *o;
    S_382E18 *s;
    Q_382E18 x, y, z;

    o = func_00435E70(0x1873, 0x80);
    if (o != 0) {
        s = o->p68;
        o->v10 = *pos;
        o->b30 = 0xFF;
        o->h32 = 0xFF;
        o->b31 = 1;
        o->h34 |= 0x100;
        o->b20 = 0;
        s->w50 = -1;
        if (tgt != 0) {
            func_004C74C0(&t, tgt, 0);
            s->p10 = tgt;
        } else {
            __asm__("sq $0, %0" : "=m"(t));
        }
        if (D_001A4BE0.w25C4 == 29) {
            M_382E18 *cm = &D_001E2A60;
            void *cp = &D_001E2A40;
            V4_382E18 *c1 = &cm->r1;
            V4_382E18 *r0 = &o->m.r0;
            V4_382E18 *r1 = &o->m.r1;
            V4_382E18 *r2 = &o->m.r2;
            o->m = *cm;
            o->v10 = *(V4_382E18 *)((u8 *)cm - 0x20);
            func_0040BE90(&v16, &cm->r2, -0.2f);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v16));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v10));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(z));
            func_0040BE90(&v32, c1, -0.25f);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v32));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v10));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(x));
            func_0040BE90(&v48, &cm->r0, 0.0f);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v10));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v48));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(x));
            if (tgt != 0) {
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(*r0) : "j"(z));
                func_0040C0F0(r0, r0, 1.0f);
                func_0040BF20(r1, r0, D_001A4BE0.p25C0 + 0xE0);
                func_0040C0F0(r1, r1, 1.0f);
                func_0040BF20(r2, r1, r0);
            } else {
                func_0040BE90(&v64, &cm->r0, 30.0f);
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_382E18 *)((u8 *)cm - 0x20)));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v64));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(v64) : "j"(z));
                if (func_003F8448(cp, &v64, 0, D_001A4BE0.p25C0, 0)) {
                    v64 = D_001EAAA0;
                }
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v64));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(v80) : "j"(z));
                func_0040C0F0(r0, &v80, 1.0f);
                func_0040BF20(r1, r0, D_001A4BE0.p25C0 + 0xE0);
                func_0040C0F0(r1, r1, 1.0f);
                func_0040BF20(r2, r1, r0);
            }
        } else if (D_001A4BE0.h2874 == 1) {
            func_0040C0F0(&o->m.r0, &src->m.r1, -1.0f);
            func_0040BE90(&o->m.r1, &src->m.r0, -1.0f);
            o->m.r2 = src->m.r2;
        } else if (D_001A4BE0.w16B0 == 1 && tgt == 0) {
            M_382E18 *cm = &D_001E2A60;
            o->m = *cm;
        } else if (tgt != 0) {
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(o->m.r0) : "j"(z));
            func_0040C0F0(&o->m.r0, &o->m.r0, 1.0f);
            func_0040BF20(&o->m.r1, &o->m.r0, D_001A4BE0.p25C0 + 0xE0);
            func_0040C0F0(&o->m.r1, &o->m.r1, 1.0f);
            func_0040BF20(&o->m.r2, &o->m.r1, &o->m.r0);
        } else {
            o->m.r0 = D_001A4BE0.v6F0;
            func_0040BF20(&o->m.r1, &o->m.r0, &D_001A4BE0.v6E0);
            func_0040C0F0(&o->m.r1, &o->m.r1, 1.0f);
            func_0040BF20(&o->m.r2, &o->m.r1, &o->m.r0);
        }
        o->m.r0.w = o->m.r1.w = o->m.r2.w = 0.0f;
        s->pC = src;
        s->f1C = func_004408C0(4.0f, 10.0f);
        s->f20 = func_00440918(6.0f, 10.0f);
        s->f18 = (D_002C5640 + D_00142657[0])->f4C * 0.016666668f;
        s->f28 = func_00440978();
        s->b27 = 1;
        s->b26 = 1;
        s->v30 = o->m.r0;
        s->v40 = *a3;
        s->h24 = 300;
        if (tgt != 0) {
            V4_382E18 *p = &tgt->v10;
            s->f0 = p->x;
            s->f4 = p->y;
            s->f8 = p->z;
        }
        v16 = src->v10;
        v16.z = pos->z;
        if (func_003F8448(&v16, pos, 0, D_001A4BE0.p25C0, 0)) {
            o->bBC = 1;
            o->v10 = D_001EAAA0;
        }
        func_00439610(o);
        func_00448BD8(o, &D_001E01C0, 31);
        s->w54 = func_004C4A18(o, 0, 0.6f, 1.0f, 1.0f);
        o->f2C *= 2.5f;
    }
    return o;
}
/* localdecomp:end func_00382E18 */
