#include "common.h"

/* localdecomp:start func_0045A8E8 */
typedef int Q_45A8E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_45A8E8;
typedef struct {
    u8 pad0[16];
    V4_45A8E8 pos;
    u8 pad32[138];
    s16 h170;
} O_45A8E8;
typedef struct {
    u8 pad0[8];
    f32 f8;
    f32 f12;
    f32 f16;
    u8 pad20[32];
    f32 f52;
    u8 b56;
    u8 pad57[23];
    V4_45A8E8 v80;
    u8 pad96[48];
    f32 f144;
    s32 i148;
    u8 pad152[8];
    V4_45A8E8 v160;
    u8 pad176[16];
    s16 h192;
    s16 h194;
    u8 pad196[8];
    f32 f204;
    u8 pad208[8];
    s32 i216;
} S_45A8E8;
typedef struct {
    u8 pad0[73];
    u8 b73;
    u16 h74;
} P_45A8E8;
extern s32 D_001D545C;
extern V4_45A8E8 D_001EAAA0;
extern void func_0045A2B8(O_45A8E8 *, S_45A8E8 *);
extern f32 func_0045A420(O_45A8E8 *, V4_45A8E8 *);
extern P_45A8E8 *func_00445EB8(O_45A8E8 *);
extern void func_004585E8(O_45A8E8 *, S_45A8E8 *);
extern void func_0045A1B0(O_45A8E8 *, V4_45A8E8 *, s32);
extern void func_0040C0F0(V4_45A8E8 *, V4_45A8E8 *, f32);
extern s32 func_003F8448(V4_45A8E8 *, V4_45A8E8 *, s32, O_45A8E8 *, s32);
extern f32 func_0040BEF8(V4_45A8E8 *, V4_45A8E8 *);
extern f32 func_0044DEA8(O_45A8E8 *, V4_45A8E8 *, s32);
extern void func_0044DBC8(O_45A8E8 *, V4_45A8E8 *, f32, f32, f32);
extern f32 func_0040BFB0(V4_45A8E8 *, void *);

void func_0045A8E8(O_45A8E8 *o, S_45A8E8 *s, void *a2, s32 a3) {
    V4_45A8E8 dir;
    V4_45A8E8 p0;
    V4_45A8E8 p1;
    V4_45A8E8 d;
    V4_45A8E8 up;
    Q_45A8E8 x, y;
    s32 changed;
    s32 ok;
    P_45A8E8 *p;
    f32 f;

    changed = 0;
    func_0045A2B8(o, s);
    if (__builtin_fabsf(s->f144) > s->f8 && D_001D545C != 22 && D_001D545C != 13 && o->h170 != 5861) {
        s->i148 |= 2;
        changed = 1;
    }
    if ((s->b56 ^ 1) & 1 && s->h194 < 5 && s->f144 < -s->f12) {
        s->i148 |= 1;
        changed = 1;
    }
    if (s->h192 != 0 && func_0045A420(o, &s->v80) > s->f16) {
        s->i148 |= 4;
        changed = 1;
    }
    if (s->i216 != -1 && s->h192 != 0) {
        p = func_00445EB8(o);
        if (p != 0 && p->b73 != 0 && p->h74 != 0 && ((p->h74 >> s->i216) & 1)) {
            s->i148 |= 0x200;
            changed = 1;
        }
    }
    if (changed) {
        func_004585E8(o, s);
        func_0045A2B8(o, s);
    }
    func_0045A1B0(o, &dir, 1);
    ok = 1;
    func_0040C0F0(&p0, &dir, 0.05f);
    func_0040C0F0(&p1, &dir, -s->f12 - 0.1f);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->pos));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p0));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(y));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p1));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(y));
    if (func_003F8448(&p0, &p1, 0, o, 0) == 0) {
        ok = 0;
    } else {
        func_0040C0F0(&up, &dir, 1.0f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001EAAA0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(y));
        if (func_0040BEF8(&up, &d) != s->f144) {
            ok = 0;
        }
    }
    if (!ok) {
        f = func_0044DEA8(o, &s->v160, a3);
        if (f <= s->f144) {
            func_0044DBC8(o, &o->pos, 0.0f, 0.0f, -s->f144);
        }
        s->h194 = 0;
        s->h192++;
    } else if (s->f144 < -s->f12) {
        s->h192 = 0;
        s->h194++;
    }
    f = func_0040BFB0(&o->pos, a2);
    s->f204 = f;
    if (f <= s->f52) {
        s->i148 |= 0x80;
    }
}
/* localdecomp:end func_0045A8E8 */
