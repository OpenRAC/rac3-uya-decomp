#include "common.h"

typedef struct O_003B5D68 O_003B5D68;

typedef struct {
    u8 p0[0x24];
    s32 w24;
    s32 w28;
    u8 p2C[0xC4];
    s32 arr[10];
    s32 w118;
    u8 p11C[4];
    s32 w120;
    s32 w124;
} S_003B5D68;

typedef struct {
    u8 p0[4];
    f32 (*fn4)(void);
    u8 p8[0x10];
    void (*fn18)(O_003B5D68 *, O_003B5D68 *, s32);
} C_003B5D68;

extern s16 *D_0021DEA0[];
extern s32 D_001E00D8;
extern s32 D_001E009C;

extern C_003B5D68 *func_00326878(s32);
extern s32 func_003B4CF0(S_003B5D68 *, f32, f32, s32 *);
extern O_003B5D68 *func_003B52B0(s32, S_003B5D68 *, s32, s32, C_003B5D68 *);
extern s32 func_003B51E0(s32, S_003B5D68 *, O_003B5D68 *, s32, s32);
extern void func_003B51A0(s32, S_003B5D68 *, O_003B5D68 *);
extern void func_003B5280(s32, S_003B5D68 *, O_003B5D68 *, s32, s32);
extern s32 func_003B5368(s32, S_003B5D68 *, s32, s32, f32, s32);

void func_003B5D68(s32 a0, S_003B5D68 *s, s32 n, f32 f) {
    s32 res;
    C_003B5D68 *c1;
    C_003B5D68 *c2;
    f32 g1;
    f32 g2;
    s32 i;
    s32 r;
    s32 v;
    s32 k;
    s32 idx2;
    s32 idx;
    s16 *p;
    O_003B5D68 *o;
    O_003B5D68 *o2;

    c1 = func_00326878(6836);
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
        if (idx < 0) {
            v = s->w124;
        } else {
            v = s->arr[idx];
        }
        o = func_003B52B0(a0, s, r, 6836, c1);
        if (o == 0) {
            break;
        }
        s->w118 = ((s32)o - D_001E009C) >> 8;
        if ((s->w28 != 0 && n >= 2) || v >= 0) {
            res = func_003B51E0(a0, s, o, res, v);
        }
        r = func_003B4CF0(s, 0.0f, g2, &idx2);
        o2 = 0;
        if (r) {
            if (idx2 < 0) {
                v = s->w124;
            } else {
                v = s->arr[idx2];
            }
            o2 = func_003B52B0(a0, s, r, 5860, c2);
            if (o2) {
                if ((s->w28 != 0 && n >= 2) || v >= 0) {
                    res = func_003B51E0(a0, s, o2, res, v);
                }
                func_003B51A0(a0, s, o2);
            }
        }
        k = func_003B5368(a0, s, 5821, 4, 0.0f, 0);
        func_003B51A0(a0, s, o);
        c1->fn18(o, o2, k);
        if (s->w120) {
            if (o2) {
                func_003B5280(a0, s, o2, 0, 0);
            }
            if (k != -1) {
                for (p = D_0021DEA0[k];
                     (k & 0xFF) != 0xFF && k <= D_001E00D8 && p != 0 &&
                     (p[-1] >= 0 || p == D_0021DEA0[k]); p++) {
                    o = (O_003B5D68 *)(D_001E009C + ((*p & 0x7FFF) << 8));
                    if (o == 0) {
                        break;
                    }
                    func_003B5280(a0, s, o, 0, 0);
                }
            }
        }
    }
}
