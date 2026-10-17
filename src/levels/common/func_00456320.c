#include "common.h"

extern s32 func_004A7200();

typedef struct { u16 id; u16 t; } E_C1950;
typedef struct { u8 p0[0x10]; u8 k; u8 p11; u8 n; u8 p13[9]; E_C1950 e[1]; } Y_C1950;
typedef struct { u8 p0[0xC]; u8 cnt; u8 pD[0x3B]; Y_C1950 *y[1]; } X_C1950;
typedef struct { u8 p0[0x24]; X_C1950 *x; } O_C1950;
void func_00456320(O_C1950 *o, s32 idx, u16 t) {
    X_C1950 *x = o->x;
    Y_C1950 *y;
    E_C1950 *e;
    s32 i;
    if (x != 0 && idx < x->cnt) {
        y = x->y[idx];
        if (y->n != 0) {
            e = (E_C1950 *)((u8 *)y + (y->k * 4 + 0x1C));
            for (i = 0; i < y->n && (t << 4) >= e[i].t; i++) {
                func_004A7200(e[i].id, 0, o);
            }
        }
    }
}
