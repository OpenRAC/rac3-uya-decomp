#include "common.h"
typedef struct { u8 p0[8]; f32 f8; u8 pC[0x460 - 0xC]; } E_00380600;
typedef struct { u8 p0[0x40]; f32 f40, f44; u8 p48[0x100 - 0x48]; s32 f100, f104; u8 p108[0x118 - 0x108]; f32 f118; u8 p11C[0x12E - 0x11C]; u8 b12E, b12F, b130, b131, b132; } R_00380600;
typedef struct { u8 p0[0xC0]; s32 fC0; } Q_00380600;
extern E_00380600 D_0024DF80[];
extern s32 D_0024145C;
extern s32 D_0024B958[2];
extern s32 D_0024B968[2];
extern s32 D_0024B978[2];
void func_00579C80(s32 a) {
    E_00380600 *e = (E_00380600 *)(a * 0x460 + (s32)D_0024DF80);
    R_00380600 *r = (R_00380600 *)((u8 *)e + 0x150);
    Q_00380600 *q = (Q_00380600 *)((u8 *)e + 0x60);
    s32 v;
    s32 *t = &D_0024B968[a];

    *t = 0x14;
    if ((u32)(r->f104 - 0x11) < 2 || r->f100 == 0x72) {
        *t = 0x34;
    }
    if (r->f104 != 0x11 && r->f118 < e->f8) {
        D_0024B968[a] = 0x14;
    }
    if (D_0024145C == 6) {
        if (r->f40 > 485.7f && r->f40 < 570.7f) {
            if (r->f44 > 250.0f && r->f44 < 334.5f) {
                D_0024B968[a] = 0x34;
            }
        }
    }
    v = D_0024B968[a];
    D_0024B968[a] = v | 0x80;
    D_0024B978[a] = v;
    D_0024B958[a] = 0xB4;
    if (r->b12E != 0) {
        q->fC0 = 0x100;
        D_0024B958[a] = 0x100 | 0xB4;
    } else if (r->b12F != 0) {
        q->fC0 = 0xB00;
        D_0024B958[a] = 0xB00 | 0xB4;
    } else if (r->b130 != 0) {
        q->fC0 = 0x300;
        D_0024B958[a] = 0x300 | 0xB4;
    } else if (r->b131 != 0) {
        q->fC0 = 0xD00;
        D_0024B958[a] = 0xD00 | 0xB4;
    } else if (r->b132 != 0) {
        D_0024B958[a] = 0xB4;
        q->fC0 = 0;
    } else {
        D_0024B958[a] = q->fC0 | 0xB4;
    }
}

