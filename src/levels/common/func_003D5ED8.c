#include "common.h"

typedef int u128_3D5ED8 __attribute__((mode(TI)));
typedef struct { s32 w0; u32 w4; u8 p8[0xC]; s32 w14; s32 w18; } V_3D5ED8;
typedef struct { s32 w0; u8 p4[0x9C]; u8 xA0[0x10]; } O_3D5ED8;
typedef struct {
    u8 p0[0x10]; u128_3D5ED8 pos; u8 b20; u8 p21[0x47]; V_3D5ED8 *w68;
} M_3D5ED8;
extern O_3D5ED8 *D_002494B0[] __attribute__((section(".sdata")));
extern f32 D_001DB274;
extern s32 D_001A5F78[];
extern f32 func_0045C850(void *, void *);
extern s32 func_003D56A8(O_3D5ED8 *, M_3D5ED8 *);
extern void func_003D5610(M_3D5ED8 *, s32);
extern s32 func_003D5658(M_3D5ED8 *);
extern void func_003D5680(M_3D5ED8 *);

s32 func_003D5ED8(M_3D5ED8 *m, s32 flag) {
    V_3D5ED8 *v;
    O_3D5ED8 **t;
    O_3D5ED8 *o;
    s32 i;
    v = m->w68;
    if (flag != 0) {
        v->w0 = -1;
        v->w4 = 0xFFFFFFFF;
        return 0;
    }
    switch (m->b20) {
    case 0:
        break;
    case 1:
    case 2:
        i = 0;
        t = D_002494B0;
        goto test;
    next:
        while (1) {
            t++;
            i++;
        test:
            if (i >= 8) goto out;
            o = *t;
            if (o == 0) goto next;
            if (func_0045C850(o->xA0, &m->pos) < D_001DB274) {
                if (func_003D56A8(o, m) != 0) {
                    func_003D5610(m, o->w0);
                    return 0;
                }
                continue;
            }
            goto next;
        }
    out:
        break;
    case 3:
        if (v->w14 > 0 && v->w18 > 0 && v->w14 < D_001A5F78[0] - v->w18) {
            if (func_003D5658(m) == 0) func_003D5680(m);
        }
        break;
    }
    return 0;
}
