#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern u8 *D_00221250[];
extern u8 *func_0045E438(s32);
extern s32 func_00440848(s32);
extern u8 *func_00440728(s32);

#define U8(p, o) (*(u8 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))

u8 *func_0046AED8(s128 *a0, s32 a1, s32 a2, s32 a3, s32 t0, f32 *t1, s32 t2, f32 f12, f32 f13) {
    u8 *p = func_0045E438(78);
    u8 *q;
    u8 *r;
    f32 *v;
    if (p != 0) {
        *(s128 *)(p + 16) = *a0;
        U8(p, 3) = 72;
        U8(p, 9) = 36;
        q = p + 32;
        S32(p, 4) = a2;
        U8(p, 1) = 0;
        U8(p, 2) = *D_00221250[0];
        S16(p, 10) = a1;
        F32(p, 12) = f12 * 210000.0f;
        if (a3 == 0) {
            U8(p, 8) = 0;
        } else if (a3 == 1) {
            U8(p, 8) = 32;
        } else {
            U8(p, 8) = func_00440848(255);
        }
        F32(q, 0) = F32(p, 12);
        F32(q, 4) = f13 * 210000.0f;
        S16(q, 8) = a1;
        U8(q, 10) = t0;
        U8(q, 11) = a2 >> 24;
        S32(q, 24) = t2;
        S32(q, 28) = 0;
        if (t2 != 0) {
            r = func_00440728(t2);
            if (r != 0) {
                F32(q, 28) = F32(r, 16);
            }
        }
        v = (f32 *)(q + 12);
        v[0] = t1[0];
        v[1] = t1[1];
        v[2] = t1[2];
    }
    return p;
}
