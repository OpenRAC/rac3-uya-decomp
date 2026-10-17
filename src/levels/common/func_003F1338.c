#include "common.h"

typedef struct M_003F1338 M_003F1338;
typedef struct V_003F1338 {
    u8 p0[0x2FC];
    s32 count;
    u8 p300[0x310 - 0x300];
    M_003F1338 *list[8];
    s32 w330;
} V_003F1338;
struct M_003F1338 {
    u8 p0[0x20];
    u8 b20;
    u8 p21[0x68 - 0x21];
    V_003F1338 *vars;
};

void func_003F1338(M_003F1338 *m) {
    V_003F1338 *v = m->vars;
    s32 n = 1;
    s32 j;
    v->w330 = 0;
    for (j = 0; j < v->count; j++) {
        M_003F1338 *o = v->list[j];
        u8 t = o->b20;
        if ((u8)(t + 3) < 2 || t == 37) {
            continue;
        }
        if (o->vars == v) {
            continue;
        }
        o->vars->w330 = n++;
    }
}
