#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4C42C0;
typedef struct {
    u8 pad0[70];
    u8 b70;
} C_4C42C0;
typedef struct {
    u8 pad0[16];
    V4_4C42C0 v16;
    u8 pad1[4];
    C_4C42C0 *f36;
    u8 pad2[130];
    s16 h170;
    u8 pad3[52];
    V4_4C42C0 v224;
} T_4C42C0;
typedef struct {
    u8 pad0[16];
    V4_4C42C0 pos;
    V4_4C42C0 v32;
    T_4C42C0 *f48;
    s32 *f52;
    s32 f56;
    f32 f60;
    f32 f64;
    f32 f68;
    u8 pad1[4];
    s32 f76;
    s32 f80;
    s32 f84;
    s32 f88;
    f32 f92;
} O_4C42C0;
typedef struct {
    u8 pad0[24];
    T_4C42C0 *f24;
} G_4C42C0;
extern G_4C42C0 D_001EAA80;
extern V4_4C42C0 D_001EAAA0;
extern V4_4C42C0 D_001EAAB0;
extern V4_4C42C0 D_001EAAC0;
extern void func_004C41E8(void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_003F9498(void *, f32, s32, void *);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern s32 func_003FC730(void);
extern void func_0040BE90(void *, void *, f32);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040C260(void *, void *, void *);

/* localdecomp:start func_004C42C0 */
s32 func_004C42C0(O_4C42C0 *obj) {
    V4_4C42C0 base;
    V4_4C42C0 tmp;
    V4_4C42C0 scaled;
    V4_4C42C0 diff;
    s32 ret;
    s32 hit;
    s32 i;
    T_4C42C0 *t;
    V4_4C42C0 *p;
    V4_4C42C0 *q;
    V4_4C42C0 *v;
    V4_4C42C0 *sc;
    f32 f;

    ret = 0;
    func_004C41E8(&obj->f48->v16, &base);
    if (obj->f88) {
        p = &tmp;
        func_0040C0F0(p, &obj->f48->v224, obj->f92);
        __asm__ __volatile__(
            "lqc2 $vf2, %0\n"
            "lqc2 $vf1, %1\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            : : "m"(tmp), "m"(obj->pos));
        q = p;
        __asm__ __volatile__("sqc2 $vf1, %0\n" : "=m"(tmp));
    } else {
        tmp = obj->pos;
        q = &tmp;
    }
    if (func_003F9498(q, obj->f60, obj->f76, obj->f48) != 0) {
        hit = 1;
    } else if (func_003F8448(obj, &obj->pos, obj->f76, obj->f48, 0) != 0) {
        hit = 2;
    } else {
        hit = 0;
    }
    obj->f48 = 0;
    if (hit != 0) {
        obj->f84 = func_003FC730();
        t = D_001EAA80.f24;
        if (t != 0) {
            for (i = 0; i < obj->f56; i++) {
                if (t->h170 == obj->f52[i]) {
                    return 0;
                }
            }
            obj->f48 = D_001EAA80.f24;
        }
        obj->pos = (hit == 1) ? D_001EAAB0 : D_001EAAA0;
        func_0040BE90(obj, &D_001EAAC0, 1.0f / 1024.0f);
        func_0040C0F0(obj, obj, 1.0f);
        if (func_0040BEF8(&base, obj) < obj->f68
            || (obj->f48 != 0 && obj->f48->f36->b70 == 5 && obj->f80 != 0)) {
            v = &obj->v32;
            func_0040C260(v, v, obj);
            ret = 1;
            f = func_0040BEF8(v, obj);
            sc = &scaled;
            func_0040BE90(sc, obj, f);
            __asm__ __volatile__(
                "lqc2 $vf2, %0\n"
                "lqc2 $vf1, %1\n"
                "vsub.xyz $vf1, $vf1, $vf2\n"
                : : "m"(scaled), "m"(obj->v32));
            f = obj->f64;
            __asm__ __volatile__("sqc2 $vf1, %0\n" : "=m"(diff));
            func_0040BE90(v, sc, f);
            __asm__ __volatile__(
                "lqc2 $vf2, %1\n"
                "lqc2 $vf1, %2\n"
                "vadd.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, %0\n"
                : "=m"(obj->v32) : "m"(obj->v32), "m"(diff));
        } else {
            ret = 2;
            obj->pos = D_001EAAA0;
        }
    }
    return ret;
}
/* localdecomp:end func_004C42C0 */
