#include "common.h"

/* localdecomp:start func_00454448 */
extern void func_00454448();

typedef int Q_3C1130 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C1130;
typedef struct { f32 v[3]; } F3_3C1130;
typedef struct { u8 p0[0x10]; V_3C1130 f10; u8 p20[0x14]; u16 f34; u8 p36[0x8A]; u8 fC0[0x30]; V_3C1130 fF0; } O_3C1130;
typedef struct {
    V_3C1130 f0; V_3C1130 f10; V_3C1130 f20; u8 p30[0x18];
    f32 f48[3]; f32 f54[3]; f32 f60[3]; f32 f6C[3]; f32 f78[3]; f32 f84[3]; f32 f90[3]; f32 f9C[3];
} C_3C1130;
extern const F3_3C1130 D_001D7CC0;
extern const F3_3C1130 D_001D7CD0;
extern const F3_3C1130 D_001D7CE0;
extern const F3_3C1130 D_001D7CF0;
extern const F3_3C1130 D_001D7D00;
extern const F3_3C1130 D_001D7D10;
extern void func_0040C2D0(void *, void *, void *);
extern f32 func_00440978(void);
void func_00454448(O_3C1130 *o, C_3C1130 *c, V_3C1130 *pos, V_3C1130 *dir, f32 *amp, f32 *rate, f32 *k48, f32 *k54, f32 *k6C, f32 *k60, f32 *k78) {
    F3_3C1130 l0, l10, l20, l30, l40, l50, l60;
    s32 i;
    l0 = D_001D7CC0;
    l10 = D_001D7CD0;
    l20 = D_001D7CE0;
    l30 = D_001D7CF0;
    l40 = D_001D7D00;
    l50 = D_001D7CF0;
    l60 = D_001D7D10;
    o->f34 |= 0x100;
    if (pos != 0) {
        func_0040C2D0(c, pos, o->fC0);
        __asm__(
            "lqc2 $vf1, %1\n"
            "lqc2 $vf2, %2\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "=m"(c->f0) : "m"(c->f0), "m"(o->f10));
        *(Q_3C1130 *)&c->f10 = *(Q_3C1130 *)pos;
    } else {
        *(Q_3C1130 *)&c->f0 = *(Q_3C1130 *)&o->f10;
    }
    if (dir != 0) {
        *(Q_3C1130 *)&c->f20 = *(Q_3C1130 *)dir;
    } else {
        *(Q_3C1130 *)&c->f20 = *(Q_3C1130 *)&o->fF0;
    }
    if (amp == 0) amp = l50.v;
    if (rate == 0) rate = l60.v;
    if (k78 == 0) k78 = l30.v;
    if (k60 == 0) k60 = l40.v;
    if (k48 == 0) k48 = l0.v;
    if (k54 == 0) k54 = l10.v;
    if (k6C == 0) k6C = l20.v;
    for (i = 0; i < 3; i++) {
        c->f78[i] = k78[i];
        c->f48[i] = k48[i];
        c->f60[i] = k60[i];
        c->f54[i] = k54[i];
        c->f6C[i] = k6C[i];
        c->f84[i] = func_00440978();
        c->f9C[i] = amp[i];
        c->f90[i] = rate[i] * 0.017453292f * 0.016666668f;
    }
}
/* localdecomp:end func_00454448 */
