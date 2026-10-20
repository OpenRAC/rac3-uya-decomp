#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_004C4AD8;

typedef struct {
    u8 p0[0x10];
    Vec4_004C4AD8 x10;
} O_004C4AD8;

typedef struct {
    u8 p0[0xE0];
    Vec4_004C4AD8 xE0;
} P_004C4AD8;

typedef struct {
    Vec4_004C4AD8 x0;
    f32 x10;
    f32 x14;
    f32 x18;
    O_004C4AD8 *x1C;
} T_004C4AD8;

typedef struct {
    u8 p0[0x368];
    s16 x368;
    u8 p36A[0x25C0 - 0x36A];
    P_004C4AD8 *x25C0;
} S_004C4AD8;

extern f32 func_0040BF38(Vec4_004C4AD8 *);
extern void func_0044DF40(Vec4_004C4AD8 *, T_004C4AD8 *, s32);
extern void func_0040C0F0(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
extern void func_0040BF20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, T_004C4AD8 *);
extern f32 func_0040BEF8(Vec4_004C4AD8 *, T_004C4AD8 *);
extern f32 func_0040C3E0(f32);
extern f32 func_0040C3C8(f32);
extern void func_0040BE90(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
extern void func_0040C9F8(Vec4_004C4AD8 *, Vec4_004C4AD8 *, Vec4_004C4AD8 *);
extern s32 D_001D673C;
extern s32 D_001D6740;
extern s16 D_001A4F48[];
extern s32 D_001A6290[];
extern T_004C4AD8 D_00250180[];
extern S_004C4AD8 D_001A4BE0;

void func_004C4AD8(s32 idx, Vec4_004C4AD8 *r, Vec4_004C4AD8 *target) {
    Vec4_004C4AD8 q;
    Vec4_004C4AD8 d;
    Vec4_004C4AD8 a;
    Vec4_004C4AD8 b;
    Vec4_004C4AD8 c;
    Vec4_004C4AD8 tgt;
    T_004C4AD8 *t;
    f32 k;
    f32 len;
    f32 w;
    f32 h;
    f32 s;

    if (idx < 0) {
        return;
    }
    if (D_001D673C == 0) {
        if (D_001D6740 == 0 && D_001A4F48[0] == 0) {
            return;
        }
    } else if (D_001A6290[0] > 0) {
        return;
    }
    t = &D_00250180[idx];
    k = 1.0f;
    if (target != 0) {
        tgt = *target;
    } else {
        if (t->x1C == 0) {
            return;
        }
        tgt = t->x1C->x10;
    }
    if (D_001A4BE0.x368 != 0) {
        if (D_001D6740 != 0) {
            k = t->x14;
        } else {
            k = t->x18;
        }
    } else if (D_001D6740 != 0) {
        k = t->x14;
    }
    if (D_001D673C != 0) {
        k = t->x10;
    }
    q = t->x0;
    w = r->w;
    r->w = 0.0f;
    len = func_0040BF38(r);
    if (D_001A4BE0.x368 != 0 && D_001D6740 == 0) {
        t->x0 = D_001A4BE0.x25C0->xE0;
    } else {
        func_0044DF40(&tgt, t, 1);
    }
    func_0040C0F0(r, r, 1.0f);
    func_0040BF20(&d, &q, t);
    h = -func_0040BEF8(&q, t) * 0.5f * k;
    func_0040BE90(&a, &d, func_0040C3E0(h));
    s = func_0040C3C8(h);
    a.w = s;
    b.x = -a.x;
    b.y = -a.y;
    b.z = -a.z;
    b.w = s;
    func_0040C9F8(&c, &a, r);
    func_0040C9F8(r, &c, &b);
    func_0040C0F0(r, r, len);
    r->w = w;
}
