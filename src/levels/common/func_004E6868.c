#include "common.h"

typedef struct {
    u8 pad0[3704];
    u8 *arr3704[2];
    u8 pad3712[4];
    s32 w3716;
    u8 pad3720[5944];
    u8 *obj;
    u8 pad9668[32];
    u8 b9700;
    u8 pad9701[4];
    u8 b9705;
    u8 pad9706;
    u8 b9707;
    u8 b9708;
} S_001A4BE0;

typedef struct {
    u8 pad0[40];
    s32 w40;
    u8 pad44[196];
} S_002C5640;

extern S_001A4BE0 D_001A4BE0;
extern u8 D_001425C0[];
extern S_002C5640 D_002C5640[];
extern s32 D_001DBD88[2];
extern s32 D_001DBDE0[2];
extern u8 D_00255900[];
extern s32 func_004E5470(s32);
extern u8 *func_00436BD8(u8 *, s32, s32, s32);
extern void func_00437108(u8 *, u8 *, s32, s32, s32, s32);

void func_004E6868(s32 a0, s32 a1) {
    s32 i;
    s32 m;
    u8 *r;

    if (D_001A4BE0.b9700 != 0 || D_001A4BE0.b9705 == 0 || D_001A4BE0.b9707 == 0) {
        return;
    }
    if (a0 != 0 || a1 == 0) {
        return;
    }
    m = func_004E5470(0);
    m = (D_002C5640 + D_001425C0[m])->w40;
    if (m == -1) {
        return;
    }
    i = 0;
    if (D_001A4BE0.arr3704[0] != 0) {
        goto next;
    }
    do {
        r = func_00436BD8(D_001A4BE0.obj, D_001DBD88[i], D_001DBDE0[i], 960);
        D_001A4BE0.arr3704[i] = r;
        if (r != 0) {
            D_001A4BE0.w3716 = 0;
            *(s32 *)(r + 8) = 0;
            *(u8 **)(r + 56) = &D_00255900[i * 3072];
            *(u8 **)(r + 60) = &D_00255900[i * 3072 + 1536];
            func_00437108(D_001A4BE0.obj, r, m, 0, 15, 1);
            *(f32 *)(r + 40) = 1.0f;
        }
    next:
        i++;
        if (i >= 2) {
            return;
        }
        if (D_001A4BE0.arr3704[i] != 0) {
            goto next;
        }
    } while (i != 1 || D_001A4BE0.b9708 == 2);
}
