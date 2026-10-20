#include "common.h"

typedef struct {
    u8 pad0[0x20];
    u8 b32;
    u8 pad21[0x34 - 0x21];
    u16 h52;
    u8 pad36[0xAA - 0x36];
    s16 h170;
} M_50C8E8;

typedef struct {
    M_50C8E8 *p[3];
    u8 padC[0x28 - 0xC];
    s32 w40;
    u8 pad2C[0x50 - 0x2C];
} E_50C8E8;

typedef struct {
    u8 pad0[0xBF8];
    M_50C8E8 *p3064;
    u8 padBFC[0x1200 - 0xBFC];
    E_50C8E8 e[1];
    u8 pad1250[0x12FC - 0x1250];
    M_50C8E8 *p4860;
    u8 pad1300[0x1A24 - 0x1300];
    M_50C8E8 *p6692;
    u8 pad1A28[0x25E4 - 0x1A28];
    u8 b9700;
} G_50C8E8;

typedef struct {
    u8 pad0[0x44];
    s16 h68;
    u8 pad46[0x1A0 - 0x46];
    M_50C8E8 *arr[1];
} H_50C8E8;

typedef struct {
    u8 pad0[0x20];
    s16 h32;
} K_50C8E8;

extern G_50C8E8 D_001A4BE0;
extern H_50C8E8 D_001E6E00;
extern K_50C8E8 D_0016C580;
extern s32 D_001D6694;
extern s32 func_0050FF18(void);

void func_0050C8E8(s32 a0) {
    s32 i;
    s32 j;
    s32 mode;
    s32 found;
    M_50C8E8 *q;
    G_50C8E8 *g;
    G_50C8E8 *base;

    D_001A4BE0.p3064->h52 |= 1;
    for (i = 0; i < 7; i++) {
        if (i == 0 && func_0050FF18() == 2 && a0 == 0) {
            continue;
        }
        mode = D_001D6694;
        if (mode == 2) {
            found = 0;
            for (j = 0; j < D_001E6E00.h68; j++) {
                if (D_001E6E00.arr[j] != 0 && D_001E6E00.arr[j]->h170 == 0) {
                    found = 1;
                }
            }
            if (found) {
                continue;
            }
        }
        if (mode == 6 && (D_0016C580.h32 == 0 || D_0016C580.h32 == 3) && (i == 1 || i == 2)) {
            continue;
        }
        base = &D_001A4BE0;
        base = &D_001A4BE0;
        g = (G_50C8E8 *)((u8 *)base + i * 80);
        if (g->e[0].p[0] != 0) {
            g->e[0].p[0]->h52 |= 1;
        }
        if (g->e[0].p[1] != 0) {
            g->e[0].p[1]->h52 |= 1;
        }
        if (g->e[0].p[2] != 0) {
            g->e[0].p[2]->h52 |= 1;
        }
    }
    if (D_001A4BE0.p4860 != 0) {
        D_001A4BE0.p4860->h52 |= 1;
    }
    if (D_001A4BE0.b9700 == 1 && D_001A4BE0.p6692 != 0) {
        D_001A4BE0.p6692->h52 |= 1;
    }
    if (D_001A4BE0.e[0].w40 == 9) {
        q = D_001A4BE0.e[0].p[0];
        if (q != 0 && D_001D6694 == 0 && q->b32 != 0) {
            q->h52 &= ~0x41;
        }
    }
}
