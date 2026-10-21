#include "common.h"

/* localdecomp:start func_00334240 */
typedef struct { u8 p0[0x20]; u8 b20; } M_334240;
typedef struct { u8 p0[0x10]; f32 pos[4]; u8 p20[0xE0]; } O_334240;
typedef struct { u8 p0[0x30]; f32 pos[4]; u8 p40[0x40]; } P_334240;
typedef struct { M_334240 *p; u8 b4; u8 type; u8 p6[2]; } S_334240;
typedef struct { S_334240 s[28]; } G_334240;
typedef struct { u8 p0[0x5C]; s8 b5C; u8 b5D; u8 b5E; } A_334240;
typedef struct { u8 p0[0x10]; f32 pos[4]; u8 p20[0x11]; u8 b31; } B_334240;
typedef struct { u8 p0[0x6C]; s32 (*fn6C)(B_334240 *); } T_334240;
typedef struct { s32 (*fn0)(O_334240 *); } F_334240;
typedef struct {
    u8 p0[0x10];
    u8 b10;
    u8 b11;
    u8 p12[0x1E];
    s8 flags[0x10];
    s32 i40;
    f32 f44;
    s32 i48;
    s32 i4C;
    s32 i50;
    f32 f54;
    s32 i58;
    f32 f5C;
    s32 i60;
    s32 i64;
    s32 i68;
    s32 i6C;
    s32 i70;
    s32 i74;
    u8 p78[0x21];
    u8 b99;
} C_334240;

extern O_334240 *D_001E009C;
extern O_334240 *D_001A71A0[];
extern s32 D_001E00D8;
extern s16 *D_0021DEA0[];
extern G_334240 *D_001DFCC8;
extern s32 D_001D6774;
extern s32 D_001F0268[];
extern M_334240 *D_001F0068[];
extern P_334240 *D_001E0180;
extern u32 D_00142BA0[];
extern s32 D_001D545C;
extern u8 D_001BBC40[];

extern s32 func_00453210(f32 *pos, s32 id);
extern f32 func_0040BFE8(f32 *a, f32 *b);
extern void func_00329C70(void *t, M_334240 *m, s32 idx);
extern void func_00329CC0(void *t, M_334240 *m, s32 idx);
extern void func_00452F80(s32 id);
extern s32 func_00453850(M_334240 *m, f32 *pos, f32 r, f32 r2);
extern s32 func_00442998(s32 a, s32 b, s32 c);
extern s32 func_00452F60(O_334240 *o);
extern F_334240 *func_00438488(s32 a, s32 b, s32 c);
extern s32 func_00452EC8(M_334240 *m);
extern void func_003338F0(M_334240 *m);

s32 func_00334240(M_334240 *m, A_334240 *a, B_334240 *b, s32 unused, void *t, C_334240 *c, T_334240 *tf) {
    s8 *flags;
    s32 res;
    O_334240 *o;
    M_334240 *mo;
    s16 *p;
    s32 j;
    s32 n;
    G_334240 *g;
    S_334240 *s;
    F_334240 *f;
    u32 r;
    s32 res4;
    s32 res8;

    if (a->b5C != -1) {
        return 1;
    }
    flags = c->flags;

    if (flags[0]) {
        res = 0;
        if (c->i4C == -1) {
            if (c->i48 != -1) {
                o = D_001E009C + c->i48;
            } else {
                o = D_001A71A0[0];
            }
            if (c->i40 != -1) {
                res = func_00453210(o->pos, c->i40) != 0;
            } else if (0.0f < c->f44) {
                if (func_0040BFE8(b->pos, o->pos) < c->f44) {
                    res = 1;
                }
            }
        } else {
            for (p = D_0021DEA0[c->i4C];
                 (c->i4C & 0xFF) != 0xFF && c->i4C <= D_001E00D8 && p != 0 &&
                 (p[-1] >= 0 || p == D_0021DEA0[c->i4C]);
                 p++) {
                o = D_001E009C + (p[0] & 0x7FFF);
                if (o == 0) {
                    break;
                }
                if (c->i40 != -1 && func_00453210(o->pos, c->i40) != 0) {
                    break;
                }
                if (0.0f < c->f44 && func_0040BFE8(b->pos, o->pos) < c->f44) {
                    break;
                }
            }
        }
        if (res) {
            func_00329C70(t, m, 0);
        } else {
            func_00329CC0(t, m, 0);
        }
    }

    if (flags[1]) {
        mo = 0;
        if (c->i50 != -1) {
            func_00452F80(c->i50);
            g = D_001DFCC8 + c->i50;
            n = g->s[0].b4;
            for (j = 0, s = g->s; j < n; j++, s++) {
                if (s->type == 3 && s->p != 0 && s->p->b20 != 0xFE && s->p->b20 != 0xFD) {
                    mo = s->p;
                    break;
                }
            }
        } else if (0.0f < c->f54) {
            for (res = 0; res < D_001D6774; res++) {
                mo = D_001F0068[res];
                if (D_001F0268[res] == 3 && func_00453850(mo, b->pos, c->f54, 10.0f) && mo != 0 &&
                    mo->b20 != 0xFE && mo->b20 != 0xFD) {
                    break;
                }
                mo = 0;
            }
        }
        if (mo) {
            func_00329C70(t, m, 1);
        } else {
            func_00329CC0(t, m, 1);
        }
    }

    if (flags[2]) {
        mo = 0;
        if (c->i58 != -1) {
            func_00452F80(c->i58);
            g = D_001DFCC8 + c->i58;
            n = g->s[0].b4;
            for (j = 0, s = g->s; j < n; j++, s++) {
                if (s->type == 3 && s->p != 0 && s->p->b20 != 0xFE && s->p->b20 != 0xFD) {
                    mo = s->p;
                    break;
                }
            }
        } else if (0.0f < c->f5C) {
            for (res = 0; res < D_001D6774; res++) {
                mo = D_001F0068[res];
                if (D_001F0268[res] == 3 && func_00453850(mo, b->pos, c->f5C, 10.0f) && mo != 0 &&
                    mo->b20 != 0xFE && mo->b20 != 0xFD) {
                    break;
                }
                mo = 0;
            }
        }
        if (mo) {
            func_00329C70(t, m, 2);
        } else {
            func_00329CC0(t, m, 2);
        }
    }

    if (flags[3]) {
        if (tf->fn6C != 0 && tf->fn6C(b) != 0) {
            func_00329C70(t, m, 3);
        } else {
            func_00329CC0(t, m, 3);
        }
    }

    if (flags[4]) {
        res4 = 0;
        if (c->i64 != -1 && c->b10 != 2 && c->b11 != 2) {
            if (func_0040BFE8(b->pos, D_001E0180[c->i64].pos) < 2.0f) {
                res4 = 1;
            }
        } else if (c->i60 != -1 && c->b10 != 2 && c->b11 != 2) {
            if (func_0040BFE8(b->pos, D_001E009C[c->i60].pos) < 5.0f) {
                res4 = 1;
            }
        } else if (c->i6C != -1 && c->b99 == 0) {
            res4 = a->b5E != 0;
        }
        if (res4) {
            func_00329C70(t, m, 4);
        } else {
            func_00329CC0(t, m, 4);
        }
    }

    if (flags[5]) {
        if (c->i68 != -1 && func_00442998(c->i68, -1, 0) == 0) {
            func_00329C70(t, m, 5);
        } else {
            func_00329CC0(t, m, 5);
        }
    }

    if (flags[7]) {
        if (a->b5D != 0) {
            func_00329C70(t, m, 7);
        } else {
            func_00329CC0(t, m, 7);
        }
    }

    if (flags[8]) {
        res8 = 0;
        if (c->i60 != -1) {
            res8 = func_00452F60(D_001E009C + c->i60) != 0;
        } else if (c->i48 != -1) {
            res8 = func_00452F60(D_001E009C + c->i48) != 0;
        }
        if (res8) {
            func_00329C70(t, m, 8);
        } else {
            func_00329CC0(t, m, 8);
        }
    }

    if (flags[9] && c->i60 != -1) {
        f = func_00438488(3950, 0, 4);
        if (f != 0 && (r = f->fn0(D_001E009C + c->i60),
                       D_00142BA0[r >> 2] & (1 << (r & 0x1F)))) {
            func_00329C70(t, m, 9);
        } else {
            func_00329CC0(t, m, 9);
        }
    }

    if (flags[10] && c->i74 != -1) {
        if (D_001BBC40[c->i74 + D_001D545C * 16] & 0x80) {
            func_00329C70(t, m, 10);
        } else {
            func_00329CC0(t, m, 10);
        }
    }

    if (flags[11]) {
        if (b->b31 != 0) {
            func_00329C70(t, m, 11);
        } else {
            func_00329CC0(t, m, 11);
        }
    }

    if (m->b20 != 25) {
        return 0;
    }
    if (func_00452EC8(m) == 0) {
        func_00329C70(t, m, 7);
    } else {
        func_00329CC0(t, m, 7);
    }
    if (a->b5C != -1) {
        func_003338F0(m);
    }
    return 0;
}
/* localdecomp:end func_00334240 */
