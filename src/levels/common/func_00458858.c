#include "common.h"

typedef struct {
    u8 pad0[104];
    f32 f68;
} E_458858;
typedef struct {
    u8 pad0[52];
    u16 f34;
    u8 pad36[0xF8 - 0x36];
    f32 fF8;
} A_458858;
typedef struct {
    u8 pad0[56];
    s32 f38;
    u8 pad3C[0x48 - 0x3C];
    E_458858 *p72;
    E_458858 *p76;
} B_458858;

extern f32 func_0040CF10(f32, f32);
extern f32 func_0040CEC8(f32, f32);

/* localdecomp:start func_00458858 */
void func_00458858(A_458858 *a, B_458858 *b, f32 x)
{
    f32 w0;
    f32 w1;
    f32 r;
    f32 ang;
    f32 lim;

    if (b->p72 == 0 && b->p76 == 0) {
        return;
    }
    if (b->f38 & 0x10) {
        return;
    }
    w0 = 0.0f;
    if (b->p72 != 0) {
        w0 = 1.0f;
    }
    w1 = 0.0f;
    if (b->p76 != 0) {
        w1 = 1.0f;
    }
    r = 1.0f / (w0 + w1);
    w0 *= r;
    w1 *= r;
    lim = 1.5707964f;
    ang = func_0040CF10(x, a->fF8);
    if (ang > lim) {
        ang = lim;
    } else if (ang < -lim) {
        ang = -lim;
    }
    if (a->f34 & 0x8000) {
        ang = -ang;
    }
    if (b->p72 != 0) {
        b->p72->f68 = func_0040CEC8(ang * w0, b->p72->f68);
        if (b->p72->f68 > lim) {
            b->p72->f68 = lim;
        } else if (b->p72->f68 < -lim) {
            b->p72->f68 = -lim;
        }
    }
    if (b->p76 != 0) {
        b->p76->f68 = func_0040CEC8(ang * w1, b->p76->f68);
        if (b->p76->f68 > lim) {
            b->p76->f68 = lim;
        } else if (b->p76->f68 < -lim) {
            b->p76->f68 = -lim;
        }
    }
}
/* localdecomp:end func_00458858 */
