#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern u8 D_00142CAE[];
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];

extern s32 func_004E4E00(s128 *, s32 *, s128 *, s32 *, f32 *, s32 *, s32, s32, s32);

void func_004E5118(void) {
    u8 *d;
    u8 *e;
    u8 *q;
    s32 v;
    s128 vec[2];
    s32 w48;
    s32 w52;
    f32 f56;
    s32 w60;
    f32 dz;

    if (D_00142CAE[0] == 0) {
        return;
    }
    d = D_001A4BE0;
    *(s32 *)(d + 1500) = 0;
    if (*(s16 *)(d + 500) != 0) {
        return;
    }
    v = *(s32 *)(d + 9676);
    if (v == 2 || v == 0 || v == 1 || v == 6) {
        goto go;
    }
    if (*(s32 *)(d + 9668) == 1) {
        goto go;
    }
    if ((u32)(*(s32 *)(d + 9668) - 40) < 2) {
        if (*(s32 *)(d + 1504) != 0 || *(s32 *)(d + 1588) != 0) {
            goto go;
        }
    }
    if (v != 4) {
        return;
    }
    if (d[1134] == 0 && *(s16 *)(d + 502) == 0) {
        return;
    }
go:
    q = D_001A4C60;
    vec[1] = *(s128 *)q;
    if (func_004E4E00(&vec[1], &w48, &vec[0], &w52, &f56, &w60, 0, 0, 0) == 0) {
        return;
    }
    d = q - 0x80;
    if (*(s32 *)(d + 9668) == 40 && *(s32 *)(d + 1588) != 0 && w48 == *(s32 *)(d + 1488)) {
        return;
    }
    e = D_001A4BE0;
    dz = *(f32 *)(e + 136) - ((f32 *)&vec[0])[2];
    if (!(-0.5f < dz)) {
        return;
    }
    if (!(dz < 0.57f) && *(s16 *)(e + 502) == 0) {
        return;
    }
    *(s128 *)(e + 1392) = vec[0];
    *(s32 *)(e + 1488) = w48;
    *(s32 *)(e + 1492) = w52;
    *(f32 *)(e + 1496) = f56;
    *(s32 *)(e + 1524) = w60;
    *(s32 *)(e + 1500) = 1;
}
