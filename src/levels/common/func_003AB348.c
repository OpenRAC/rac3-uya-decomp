#include "common.h"

typedef void (*F_3AB348)(void *);

typedef struct {
    u8 pad0[0x50];
    int i50;
    u8 pad54[0xC90 - 0x54];
    int list[31];
    int idx;
    u8 padD10[0xD20 - 0xD10];
    int iD20;
} V_3AB348;

typedef struct {
    u8 pad0[0x68];
    V_3AB348 *vars;
} M_3AB348;

extern s16 *D_0021DEA0[];
extern int D_001E00D8;
extern int D_001E009C;
extern void func_003A9AC0(M_3AB348 *, V_3AB348 *, int);
extern F_3AB348 *func_00438468(int, int);
extern void func_003AC560(M_3AB348 *, V_3AB348 *, void *);
extern void *func_003AC2E0(M_3AB348 *, V_3AB348 *);
extern void func_00436220(M_3AB348 *);

void func_003AB348(M_3AB348 *a0, int a1) {
    V_3AB348 *v = a0->vars;
    F_3AB348 *tbl;
    int i;
    int cur;
    s16 *p;
    void *m;

    func_003A9AC0(a0, v, 0);
    if (v->i50 != 0) {
    tbl = func_00438468(6625, 108);
    tbl[0](a0);
    for (i = 0; i < 4; i++) {
        if (v->list[i] == -1) {
            continue;
        }
        p = D_0021DEA0[v->list[i]];
        while ((cur = v->list[i], (cur & 0xFF) != 0xFF) && cur <= D_001E00D8 && p != 0
               && (p[-1] >= 0 || p == D_0021DEA0[v->list[i]])) {
            m = (u8 *)D_001E009C + ((*p & 0x7FFF) << 8);
            if (m == 0) {
                break;
            }
            p++;
            func_003AC560(a0, v, m);
        }
        v->idx = i;
        while ((m = func_003AC2E0(a0, v)) != 0) {
            tbl[4](m);
        }
    }
    if (a1) {
        if (v->iD20) {
            tbl[1](a0);
        } else {
            tbl[3](a0);
        }
    }
    } else {
        func_00436220(a0);
    }
}
