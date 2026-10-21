#include "common.h"

/* localdecomp:start func_0050B518 */
typedef struct {
    u8 p0[4848];
    u8 *w12F0;
    u8 *w12F4;
    u8 p12F8[4884 - 4856];
    s32 w1314;
    u8 p1318[9676 - 4888];
    s32 w25CC;
    s32 w25D0;
} G_50B518;
extern G_50B518 D_001A4BE0;
extern s32 func_0050B678(s32, s32 *, s32 *);
extern s32 func_0050B448(s32, s32 *);
extern s32 func_004E5470(s32);
extern void func_00441C78(u8 *a0, s32 a1, s32 a2, s32 a3);

void func_0050B518(s32 a0, s32 a1, f32 f12) {
    s32 x;
    s32 y;
    G_50B518 *g;
    u8 *o1;
    u8 *o2;
    s32 flag;
    s32 k;

    g = &D_001A4BE0;
    if (g->w1314 != 2) {
        return;
    }
    o1 = g->w12F0;
    o2 = g->w12F4;
    if (o1 == 0) {
        return;
    }
    if (o2 == 0) {
        return;
    }
    if (func_0050B678(a0, &x, &y) != 0 && a0 != 0) {
        if (o1[67] != x) {
            k = (s32)f12;
            func_00441C78(o1, x, a1, k);
            func_00441C78(o2, y, a1, k);
        }
        return;
    }
    flag = 1;
    if (D_001A4BE0.w25CC == 0) {
        if (func_0050B448(o1[67], &a0) != 0 && a0 == 0) {
            flag = 0;
        }
    }
    if (flag == 0) {
        return;
    }
    k = 7;
    if (D_001A4BE0.w25D0 == 8) {
        if (func_004E5470(3) == 2) {
            k = 19;
        }
    }
    if (o1[67] != 1) {
        func_00441C78(o1, 1, 0, k);
    }
    if (o2[67] != 1) {
        func_00441C78(o2, 1, 0, k);
    }
}
/* localdecomp:end func_0050B518 */
