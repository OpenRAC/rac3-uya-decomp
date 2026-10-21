#include "common.h"

/* localdecomp:start func_00333D30 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_333D30;
typedef int Q_333D30 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    V4_333D30 pos;
} O_333D30;
typedef struct {
    u8 pad0[0x198];
    f32 f198;
    u8 pad19C[0x3F0 - 0x19C];
    V4_333D30 v3F0;
    V4_333D30 v400;
    u8 pad410[0x10];
    V4_333D30 v420;
    u8 pad430[4];
    f32 f434;
    u8 pad438[8];
    s32 i440;
} D_333D30;
typedef struct {
    u8 pad0[0xD0];
    V4_333D30 vD0;
    u8 padE0[0x25C0 - 0xE0];
    s32 i25C0;
} G_333D30;
typedef struct {
    u8 pad0[0x18];
    s32 i18;
} H_333D30;
typedef struct {
    u8 pad0[0x10];
    f32 f10;
} M_333D30;

extern G_333D30 D_001A4BE0;
extern H_333D30 D_001EAA80;
extern V4_333D30 D_001EAAA0;
extern M_333D30 *func_00440728(s32);
extern s32 func_003F8448(V4_333D30 *, V4_333D30 *, s32, O_333D30 *, s32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040BF68(V4_333D30 *);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern f32 func_0040BFE8(V4_333D30 *, V4_333D30 *);

void func_00333D30(O_333D30 *obj, D_333D30 *d, f32 minr) {
    V4_333D30 a, b, c, dir, dir2;
    M_333D30 *m;
    f32 ang, heading, r, dist;
    f32 zero;
    f32 t;
    Q_333D30 x, y;

    b = d->v400;
    d->v3F0 = b;
    a = obj->pos;
    b.z += d->f198;
    a.z += d->f198;
    m = func_00440728(d->i440);
    if (d->i440 == D_001A4BE0.i25C0) {
        b = D_001A4BE0.vD0;
    } else if (m) {
        b.z += m->f10;
    }
    if (!func_003F8448(&a, &b, 16, obj, 0)) {
        return;
    }
    if (D_001EAA80.i18 != 0 && D_001EAA80.i18 == d->i440) {
        return;
    }
    for (ang = 10.0f; ang <= 100.0f; ang += 10.0f) {
        __asm__ __volatile__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(dir) : "m"(b), "m"(a));
        heading = func_0040C490(dir.x, dir.y);
        r = func_0040BF68(&dir);
        if (r < minr) {
            r = minr;
        }
        t = ang * 0.017453292f;
        c.x = func_0040C3C8(func_0040CEC8(t, heading)) * r;
        c.y = func_0040C3E0(func_0040CEC8(t, heading)) * r;
        zero = 0.0f;
        c.z = zero;
        __asm__ __volatile__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(c) : "m"(a), "m"(c));
        if (c.x < zero) c.x = 0.5f;
        if (c.y < zero) c.y = 0.5f;
        if (c.z < zero) c.z = 0.5f;
        if (!func_003F8448(&a, &c, 16, obj, 0)) {
            d->v3F0 = c;
            return;
        }
        if (D_001EAA80.i18 != 0 && D_001EAA80.i18 == d->i440) {
            d->v3F0 = c;
        }
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001EAAA0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(dir2) : "j"(x));
        dist = func_0040BF68(&dir2);
        if (d->f434 < dist && ang < 60.0f) {
            if (func_0040BFE8(&D_001EAAA0, &d->v400) < func_0040BFE8(&d->v420, &d->v400)) {
                d->f434 = dist;
                d->v420 = D_001EAAA0;
            }
        }

        t = -(ang * 0.017453292f);
        c.x = func_0040C3C8(func_0040CEC8(t, heading)) * r;
        c.y = func_0040C3E0(func_0040CEC8(t, heading)) * r;
        zero = 0.0f;
        c.z = zero;
        __asm__ __volatile__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(c) : "m"(a), "m"(c));
        if (c.x < zero) c.x = 0.5f;
        if (c.y < zero) c.y = 0.5f;
        if (c.z < zero) c.z = 0.5f;
        if (!func_003F8448(&a, &c, 16, obj, 0)) {
            d->v3F0 = c;
            return;
        }
        if (D_001EAA80.i18 != 0 && D_001EAA80.i18 == d->i440) {
            d->v3F0 = c;
        }
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(obj->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001EAAA0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(dir2) : "j"(x));
        dist = func_0040BF68(&dir2);
        if (d->f434 < dist && ang < 60.0f) {
            d->f434 = dist;
            d->v420 = D_001EAAA0;
        }
    }
}
/* localdecomp:end func_00333D30 */
