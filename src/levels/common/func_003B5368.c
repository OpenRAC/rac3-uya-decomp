#include "common.h"

/* localdecomp:start func_003B5368 */
typedef struct {
    u8 p0[0x10];
    s32 w10;
    u8 p14[0x30];
    u16 h44;
} D_3B5368;

typedef struct {
    u8 p0[0x20];
    u8 b20;
    u8 p21[3];
    D_3B5368 *def;
    u8 p28[0x0C];
    u16 h34;
    u8 p36[0x62];
    s32 w98;
} O_3B5368;

typedef struct {
    u8 p0[0x24];
    s32 w24;
    s32 w28;
    s32 w2C;
    u8 p30[0x38];
    s32 w68;
    u8 p6C[0x84];
    s32 arr[13];
    s32 w124;
} S_3B5368;

typedef struct {
    u8 p0[4];
    f32 (*fn4)(void);
} C_3B5368;

extern s16 *D_0021DEA0[];
extern s32 D_001E00D8;
extern s32 D_001E009C;

extern C_3B5368 *func_00326878(s32);
extern s32 func_003B4CF0(S_3B5368 *, f32, f32, s32 *);
extern O_3B5368 *func_003B52B0(s32, S_3B5368 *, s32, s32, C_3B5368 *);
extern s32 func_003B51E0(s32, S_3B5368 *, O_3B5368 *, s32, s32);
extern void func_003B51A0(s32, S_3B5368 *, O_3B5368 *);
extern void func_003B5280(s32, S_3B5368 *, O_3B5368 *, s32, s32);
extern s32 func_00447C90(s32);
extern void func_00439610(O_3B5368 *);

s32 func_003B5368(s32 a0, S_3B5368 *s, s32 a2, s32 n, f32 f, s32 flag) {
    C_3B5368 *c;
    f32 g;
    s32 res;
    s32 i;
    s32 r;
    s32 v;
    s32 idx;
    s16 *p;
    s16 *q;
    O_3B5368 *o;

    c = func_00326878(a2);
    if (c->fn4) {
        g = c->fn4();
    } else {
        g = 0.0f;
    }
    res = 255;
    if (s->w28 && s->w2C) {
        res = s->w68;
    }
    for (i = 0; i < n; i++) {
        r = func_003B4CF0(s, f, g, &idx);
        if (r == 0) {
            s->w24 = 1;
            break;
        }
        if (idx < 0) {
            v = s->w124;
        } else {
            v = s->arr[idx];
        }
        o = func_003B52B0(a0, s, r, a2, c);
        if (o == 0) {
            break;
        }
        if ((s->w28 != 0 && n >= 2) || v >= 0) {
            res = func_003B51E0(a0, s, o, res, v);
        }
        if (res == 255) {
            func_003B51A0(a0, s, o);
        }
        if (flag) {
            func_003B5280(a0, s, o, 0, 0);
        }
    }
    if (res != 255) {
        if (func_00447C90(a2)) {
            for (p = D_0021DEA0[res];
                 (res & 0xFF) != 0xFF && res <= D_001E00D8 && p != 0 &&
                 (p[-1] >= 0 || p == D_0021DEA0[res]); p++) {
                o = (O_3B5368 *)(D_001E009C + ((*p & 0x7FFF) << 8));
                if (o == 0) {
                    break;
                }
                o->h34 &= 0xFFBE;
                o->h34 |= o->def->h44 & 0x1000;
                o->w98 = o->def->w10;
                func_00439610(o);
            }
        }
        for (q = D_0021DEA0[res];
             (res & 0xFF) != 0xFF && res <= D_001E00D8 && q != 0 &&
             (q[-1] >= 0 || q == D_0021DEA0[res]); q++) {
            o = (O_3B5368 *)(D_001E009C + ((*q & 0x7FFF) << 8));
            if (o == 0) {
                break;
            }
            if (o->b20 == 0) {
                func_003B51A0(a0, s, o);
            }
        }
    }
    s->w68 = res;
    return res;
}
/* localdecomp:end func_003B5368 */
