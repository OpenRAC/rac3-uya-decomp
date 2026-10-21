#include "common.h"

/* localdecomp:start func_00455A60 */
typedef int Q_455A60 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_455A60;
typedef struct {
    u8 pad0[12];
    f32 f12;
    u8 pad16[128];
    f32 f144;
} S_455A60;
typedef struct {
    u8 pad0[28];
    S_455A60 *s;
} T_455A60;
typedef struct {
    u8 pad0[16];
    V4_455A60 pos;
    u8 pad32[72];
    T_455A60 *t;
    u8 pad108[140];
    f32 f248;
} O_455A60;
typedef struct {
    u8 pad0[76];
    f32 f76;
    u8 pad80[12];
    s32 i92;
    V4_455A60 v96;
} R_455A60;
extern s32 D_001EAA98[];
extern V4_455A60 D_001EAAC0;
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern f32 func_00443140(f32, void *, s32, s32);
extern f32 func_0040BF68(void *);
extern f32 func_0040C490(f32, f32);
s32 func_00455A60(O_455A60 *o, R_455A60 *out) {
    S_455A60 *s = o->t->s;
    V4_455A60 a, b, d, c, e;
    f32 f21, f20, f1;
    Q_455A60 x, y;
    if (s == 0) {
        return 0;
    }
    if (s->f144 == 0.0f) {
        return 0;
    }
    a = o->pos;
    b.x = func_0040C3C8(o->f248);
    b.y = func_0040C3E0(o->f248);
    b.z = 0.0f;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
    c = o->pos;
    d = o->pos;
    c.z = c.z + 3.0f;
    d.z = 0.01f;
    if (func_003F8448(&c, &d, 0, o, 0)) {
        out->i92 = D_001EAA98[0];
    }
    f21 = func_00443140(0.5f, &a, 34, 0);
    if (f21 < o->pos.z && s->f12 < __builtin_fabsf(f21 - o->pos.z)) {
    b.x = func_0040C3C8(o->f248) * 9.0f;
    b.y = func_0040C3E0(o->f248) * 9.0f;
    b.z = 0.0f;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->pos));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(y));
    out->v96 = a;
    f21 = func_00443140(6.0f, &a, 34, 0);
    f20 = o->pos.z - 2.0f;
    e = D_001EAAC0;
    f1 = func_0040C490(e.z, func_0040BF68(&e));
    if (f20 < f21) {
        if (f1 < 0.17453292f) {
            out->f76 = f21;
            return 1;
        }
    }
    return 2;
    }
    return 0;
}
/* localdecomp:end func_00455A60 */
