#include "common.h"

/* localdecomp:start func_0031A438 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_31A438;
typedef struct { V_31A438 r[3]; } M_31A438;
typedef struct { u8 pad0[0x4A]; u8 f4A; u8 pad4B[5]; } E_31A438;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s16 fC;
    s16 fE;
    f32 f10;
    f32 f14;
    f32 f18;
    s32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
    E_31A438 f40[1];
} S_31A438;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0xF];
    u8 f30;
    u8 pad31[3];
    u16 f34;
    u8 pad36[0x32];
    S_31A438 *f68;
    u8 pad6C[0x54];
    M_31A438 fC0;
    V_31A438 fF0;
} O_31A438;
extern s32 D_001F1600[];
extern void func_00423188(O_31A438 *o, void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern void func_0040E0A0(O_31A438 *o);
extern void func_003E4DA0(void *a, void *b);
extern f32 func_003E4B48(f32 a);
extern void func_00422EE0(O_31A438 *o, f32 *a, f32 *b, f32 x, f32 y, f32 z);
extern void func_00422FA0(O_31A438 *o, f32 *a, f32 *b, f32 x, f32 y, f32 z);
extern void func_003E50C8(void *a, void *b, void *c);
extern void func_0041EE78(void *a, void *b);
extern void func_00423850(O_31A438 *o, void *a);

void func_0031A438(O_31A438 *o) {
    S_31A438 *s = o->f68;
    V_31A438 rot;
    M_31A438 m;
    E_31A438 *e;
    s32 one;
    switch (o->f20) {
    case 0:
        if (*(long *)&s->f0 == -1) {
            return;
        }
        o->f30 = 0xFF;
        func_00423188(o, s->f40, 0x50, s->f4, s->f0, s->f8, 7, 0);
        if (((u8 *)s)[0x8A] == 0) {
            func_0040E0A0(o);
            return;
        }
        if (s->f1C == 0) {
            ((u8 *)s)[0x8D] = 1;
            o->f34 |= 0x104;
            func_003E4DA0(&o->fC0, &o->fF0);
        }
        if (s->f20 != 0.0f) {
            s->f20 *= 0.0174532924f;
        }
        s->f24 = func_003E4B48(s->f20) * s->f30;
        s->fE = 1;
        o->f20 = 1;
        break;
    case 1:
        if (s->fE == 0) {
            return;
        }
        if (D_001F1600[0] != s->fC) {
            return;
        }
        if (s->f34 > 0.0f) {
            func_00422EE0(o, &s->f20, &s->f24, s->f30, s->f34 * 0.0174532924f * 0.0166666675f, -1.0f);
        }
        if (s->f3C > 0.0f) {
            func_00422FA0(o, &s->f28, &s->f2C, s->f38 * 0.0174532924f, s->f3C * 0.0174532924f * 0.0166666675f, 0.00581776444f);
            if (((u8 *)s)[0x8D] != 0) {
                func_003E4DA0(&o->fC0, &o->fF0);
            }
        }
        if (s->f1C == 0) {
            rot.x = s->f10 * 0.0174532924f * 0.0166666675f;
            rot.y = s->f14 * 0.0174532924f * 0.0166666675f;
            rot.z = s->f18 * 0.0174532924f * 0.0166666675f;
            func_003E4DA0(&m, &rot);
            func_003E50C8(&o->fC0, &o->fC0, &m);
            if (s->f3C > 0.0f) {
                func_0041EE78(&o->fC0, &o->fF0);
            }
        } else {
            rot.x = s->f10 * 0.0174532924f * 0.0166666675f;
            rot.y = s->f14 * 0.0174532924f * 0.0166666675f;
            rot.z = s->f18 * 0.0174532924f * 0.0166666675f;
            func_003E4DA0(&m, &rot);
            one = 1;
            e = s->f40;
            do {
                func_003E50C8(e, e, &m);
            } while ((e++)->f4A != one);
        }
        func_00423850(o, s->f40);
        break;
    }
}
/* localdecomp:end func_0031A438 */
