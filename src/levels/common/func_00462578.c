#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s128 v;
    s32 w16;
    s32 w20;
    s16 h24;
    s16 h26;
    f32 f28;
} Sub_00462578;

extern f32 D_001DFBCC;
extern u8 *D_00221158[];
extern s32 func_00440848(s32);
extern u8 *func_0045E438(s32);
extern u8 func_0013D3E0(void);

u8 *func_00462578(s128 *a0, s128 *a1, s32 a2, s32 a3, s32 t0, s32 t1, f32 f12) {
    u8 *o;
    Sub_00462578 *e;
    u8 *p;

    if (t0 == 0) {
        return 0;
    }
    {
        if (0.9f < D_001DFBCC) {
            if (func_00440848(3) == 0) {
                return 0;
            }
        }
        if (0.95f < D_001DFBCC) {
            if (func_00440848(2) == 0) {
                return 0;
            }
        }
        if (1.0f < D_001DFBCC) {
            if (func_00440848(1) == 0) {
                return 0;
            }
        }
    }
    o = func_0045E438(16);
    if (o != 0) {
        *(s128 *)(o + 16) = *a0;
        *(s32 *)(o + 4) = a2;
        o[1] = 0;
        *(f32 *)(o + 12) = f12;
        o[9] = 68;
        o[3] = 68;
        o[8] = func_0013D3E0();
        p = D_00221158[0] + t1;
        if (t1 == 3) {
            p = D_00221158[0];
        }
        e = (Sub_00462578 *)(o + 32);
        o[2] = *p;
        *(s16 *)(o + 10) = t0;
        e->h24 = t0;
        e->f28 = f12;
        e->w16 = a2;
        e->w20 = a3;
        e->h26 = t1;
        e->v = *a1;
        ((f32 *)e)[3] = ((f32 *)a0)[2] - 0.5f;
    }
    return o;
}
