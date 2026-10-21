#include "common.h"

/* localdecomp:start func_003B5A90 */
typedef struct {
    u8 p0[0x3C];
    s32 w3C;
    u8 p40[0x0C];
    s32 w4C;
} T_3B5A90;

typedef struct {
    u8 p0[0x68];
    T_3B5A90 *t;
} R_3B5A90;

typedef struct {
    u8 p0[0x24];
    s32 w24;
    s32 w28;
    u8 p2C[0x4C];
    s32 w78;
    u8 p7C[0x74];
    s32 arr[13];
    s32 w124;
} S_3B5A90;

typedef struct {
    u8 p0[4];
    f32 (*fn4)(void);
    u8 p8[0x10];
    void (*fn18)(void *, void *, s32);
} C_3B5A90;

extern C_3B5A90 *func_00326878(s32);
extern R_3B5A90 *func_003B4CF0(S_3B5A90 *, f32, f32, s32 *);
extern void *func_003B52B0(s32, S_3B5A90 *, R_3B5A90 *, s32, C_3B5A90 *);
extern s32 func_003B51E0(s32, S_3B5A90 *, void *, s32, s32);
extern void func_003B51A0(s32, S_3B5A90 *, void *);
extern void func_003B5280(s32, S_3B5A90 *, void *, s32, s32);
extern s32 func_003B5368(s32, S_3B5A90 *, s32, s32, f32, s32);

void func_003B5A90(s32 a0, S_3B5A90 *s, s32 n, f32 f) {
    s32 i;
    C_3B5A90 *c1;
    C_3B5A90 *c2;
    f32 g1;
    f32 g2;
    s32 res;
    s32 idx;
    s32 idx2;
    R_3B5A90 *r;
    T_3B5A90 *t;
    s32 v;
    s32 v2;
    void *o;
    void *o2;
    s32 x;

    c1 = func_00326878(6317);
    if (c1->fn4) {
        g1 = c1->fn4();
    } else {
        g1 = 0.0f;
    }
    g2 = 0.0f;
    c2 = func_00326878(5860);
    if (c2 && c2->fn4) {
        g2 = c2->fn4();
    }
    res = 255;
    for (i = 0; i < n; i++) {
        r = func_003B4CF0(s, f, g1, &idx);
        if (r == 0) {
            s->w24 = 1;
            break;
        }
        t = r->t;
        if (idx < 0) {
            v = s->w124;
        } else {
            v = s->arr[idx];
        }
        o = func_003B52B0(a0, s, r, 6317, c1);
        if (o == 0) {
            break;
        }
        if ((s->w28 != 0 && n >= 2) || v >= 0) {
            res = func_003B51E0(a0, s, o, res, v);
        }
        o2 = 0;
        if (t->w3C) {
            if (func_003B4CF0(s, 0.0f, g2, &idx2)) {
                if (idx2 < 0) {
                    v2 = s->w124;
                } else {
                    v2 = s->arr[idx2];
                }
                o2 = func_003B52B0(a0, s, r, 5860, c2);
                if (o2) {
                    if ((s->w28 != 0 && n >= 2) || v >= 0) {
                        res = func_003B51E0(a0, s, o2, res, v2);
                    }
                    func_003B51A0(a0, s, o2);
                }
            }
        }
        s->w78 = 2;
        x = 255;
        if (t->w4C) {
            x = func_003B5368(a0, s, 5821, t->w4C, 0.0f, 0);
        }
        s->w78 = 0;
        c1->fn18(o, o2, x);
        func_003B51A0(a0, s, o);
        func_003B5280(a0, s, o, 0, 0);
    }
}
/* localdecomp:end func_003B5A90 */
