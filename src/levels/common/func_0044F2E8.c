#include "common.h"

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    s32 x14;
    s32 x18;
} E_0044F2E8;

extern E_0044F2E8 D_002D1630[];

extern s32 func_004181A0(s32);
extern void func_00433668(s32, s32);

s32 func_0044F2E8(s32 i, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2) {
    E_0044F2E8 *e = &D_002D1630[i];

    if (e->x0 == a1 && e->x14 == t1 && e->x18 == t2 && e->x4 == a2) {
        if (a2 != 0) {
            func_00433668(func_004181A0(a2), a3);
        }
        e->x8 = a3;
        e->x4 = a2;
        e->x14 = t1;
        e->x18 = t2;
        return 2;
    }
    if (e->x0 == 0) {
        if (a2 != 0) {
            func_00433668(func_004181A0(a2), a3);
        }
        e->x8 = a3;
        e->x0 = a1;
        e->x4 = a2;
        return 1;
    }
    return 0;
}
