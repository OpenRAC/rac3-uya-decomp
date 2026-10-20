#include "common.h"

typedef struct {
    u8 p0[4];
    s32 w4;
    u8 b8;
    u8 p9;
    s16 h10;
    f32 f12;
    f32 f16;
    s32 w20;
    f32 f24;
    u8 p1C[4];
} P_461F70;

extern s32 func_0040BAC0(s16 *t);
extern void func_0045E580(P_461F70 *p);

void func_00461F70(P_461F70 *p) {
    P_461F70 *q = p + 1;

    p->b8 += q->b8;
    p->f24 += q->f16;
    p->f12 *= q->f12;
    if (q->w4 == 0) {
        if (func_0040BAC0(&p->h10)) {
            q->w4 = 1;
            p->h10 = 30;
            p->w4 = q->w20 | 0x7F000000;
        } else {
            p->w4 = (((s32)((10 - p->h10) * 9.6f) + 32) << 24) | q->w20;
        }
    } else {
        if (func_0040BAC0(&p->h10)) {
            func_0045E580(p);
            return;
        }
        p->w4 = ((s32)(p->h10 * 4.2333331f) << 24) | q->w20;
    }
}
