#include "common.h"

typedef struct {
    u8 pad0[16];
    s16 n0;
    s16 n1;
    s16 n2;
    s16 n3;
    u8 pad18[4];
    s32 *a0;
    s32 *a1;
    s32 *a2;
    s32 *a3;
    u8 pad2C[4];
} Ent_00453210;

typedef struct {
    s32 count;
    u8 pad[28];
    Ent_00453210 ent[1];
} Hdr_00453210;

extern Hdr_00453210 *D_001DFCCC;
extern u8 *D_0021F740[];
extern s32 func_0040C060(void *, Ent_00453210 *);
extern s32 func_00440760(void *, s32, s32);
extern s32 func_00448E00(void *, s32);
extern s32 func_00448D50(void *, s32);
extern s32 func_004432C0(void *, u8 *, s32);

s32 func_00453210(void *a0, s32 a1) {
    Ent_00453210 *e;
    s32 i;

    if (a1 < 0 || a1 >= D_001DFCCC->count) {
        return 0;
    }
    if (func_0040C060(a0, &D_001DFCCC->ent[a1]) == 0) {
        return 0;
    }
    e = &D_001DFCCC->ent[a1];
    for (i = 0; i < e->n1; i++) {
        if (func_00440760(a0, e->a1[i], 0) != 0) {
            return 1;
        }
    }
    for (i = 0; i < e->n2; i++) {
        if (func_00448E00(a0, e->a2[i]) != 0) {
            return 1;
        }
    }
    for (i = 0; i < e->n3; i++) {
        if (func_00448D50(a0, e->a3[i]) != 0) {
            return 1;
        }
    }
    for (i = 0; i < e->n0; i++) {
        u8 *p = D_0021F740[e->a0[i]];
        if (func_004432C0(a0, p + 16, *(s32 *)p) != 0) {
            return 1;
        }
    }
    return 0;
}
