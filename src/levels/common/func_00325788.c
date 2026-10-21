#include "common.h"

/* localdecomp:start func_00325788 */
typedef struct {
    s32 w0;
    u8 p4[8];
    s32 wC;
    u8 p10[8];
    s32 w18;
    u8 p1C[0x50];
    s32 w6C;
} V_325788;

typedef struct {
    u8 p0[0x68];
    V_325788 *v;
    u8 p6C[0x3E];
    s16 hAA;
    u8 pAC[0x54];
} O_325788;

typedef struct {
    u8 p0[0x60];
    O_325788 *w60;
} S_325788;

extern O_325788 *D_001E009C;
extern s32 D_001E00D8;
extern s16 *D_0021DEA0[];
extern s32 func_00325740(s32, S_325788 *, O_325788 *);
extern O_325788 *func_00445F18(O_325788 *);

void func_00325788(s32 a0, S_325788 *s, O_325788 *a2) {
    V_325788 *v;
    V_325788 *w;
    O_325788 *o;
    O_325788 *m;
    O_325788 *k;
    s16 *q;
    s16 *p;
    s32 x;
    s32 t;

    s->w60 = 0;
    v = a2->v;
    if (v->w18 == -1) {
        return;
    }
    for (o = &D_001E009C[v->w18]; o != 0 && o->hAA != 6628;
         o = &D_001E009C[w->w0]) {
        w = o->v;
        t = w->wC;
        if (t != -1) {
            for (q = D_0021DEA0[t];
                 (w->wC & 0xFF) != 0xFF && w->wC <= D_001E00D8 && q != 0 &&
                 (q[-1] >= 0 || q == D_0021DEA0[w->wC]); q++) {
                t = (s32)&D_001E009C[*q & 0x7FFF];
                if (t == 0) {
                    break;
                }
                t = ((O_325788 *)t)->v->w6C;
                if (t != -1) {
                    *(s32 *)((u8 *)func_00445F18(&D_001E009C[t]) + 4) = 0;
                }
            }
        }
        if (w->w0 == -1) {
            break;
        }
    }
    for (o = &D_001E009C[v->w18]; o != 0 && o->hAA != 6628;
         o = &D_001E009C[w->w0]) {
        w = o->v;
        t = w->wC;
        if (t != -1) {
            for (p = D_0021DEA0[t];
                 (w->wC & 0xFF) != 0xFF && w->wC <= D_001E00D8 && p != 0 &&
                 (p[-1] >= 0 || p == D_0021DEA0[w->wC]); p++) {
                t = (s32)&D_001E009C[*p & 0x7FFF];
                if (t == 0) {
                    break;
                }
                x = ((O_325788 *)t)->v->w6C;
                if (x != -1) {
                    k = &D_001E009C[x];
                    if (func_00325740(a0, s, k) == 0) {
                        *(O_325788 **)((u8 *)func_00445F18(k) + 4) = s->w60;
                        s->w60 = k;
                    }
                }
            }
        }
        if (w->w0 == -1) {
            break;
        }
    }
}
/* localdecomp:end func_00325788 */
