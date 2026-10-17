#include "common.h"
typedef struct { u8 p0[6]; u8 b6; u8 p7[5]; u8 bC; u8 pD[0x3B]; s32 w48[1]; } W_5A3010;
typedef struct { u8 p0[0x24]; W_5A3010 *w24; u8 p28[0xA]; u16 h32; u16 h34; u8 p36[2]; long d38; u8 p40[2]; u8 b42; u8 b43; u8 p44[0x1E]; u8 b62; u8 b63; u8 p64[4]; s32 w68; u8 p6C[0x2C]; s32 w98; u8 p9C[0xE]; s16 hAA; u8 pAC[8]; s16 hB4; } O_5A3010;
typedef struct { u8 p0[0x38]; s32 w38; u8 p3C[4]; s16 h40; u8 p42[2]; s16 h44; u8 p46[2]; s16 h48; u8 p4A[0xA]; s32 w54; u8 p58[0xC]; s32 w64; u8 *w68; s32 w6C; u8 p70[0xC]; s16 h7C; s16 h7E; u8 p80[0x120]; O_5A3010 *arr[1]; } G_5A3010;
extern G_5A3010 D_0025CFC0;
extern O_5A3010 *D_0025023C;
extern void func_001264E0(s32);
extern void func_005A7BE0(u8 *, u32);
extern void func_005A83A8(O_5A3010 *, s32);
extern O_5A3010 *func_005A8280(s32, s32);
void func_005A3010(void) {
    u8 *h;
    s32 *tp;
    s32 *e;
    s32 i, k, kind, b, x;
    s32 off;
    O_5A3010 *o;
    func_001264E0(0);
    func_005A7BE0((u8 *)D_0025CFC0.w6C, (u32)D_0025CFC0.w68);
    func_001264E0(0);
    h = D_0025CFC0.w68;
    D_0025CFC0.w38 = 0;
    tp = (s32 *)(h + 0x14);
    D_0025CFC0.h40 = *(u16 *)(h + 0);
    x = *(s32 *)(h + 4);
    D_0025CFC0.h48 = *(u16 *)(h + 8);
    D_0025CFC0.h44 = *(u16 *)(h + 0xC);
    D_0025CFC0.w64 = (s32)h + *(s32 *)(h + 0x10);
    if (x != 0) {
        D_0025CFC0.h7C = x;
        D_0025CFC0.h7E = (x >> 16) + 1;
    }
    for (i = 0; i < D_0025CFC0.h44; i++) {
        e = (s32 *)(h + *tp++);
        kind = *e;
        e += 3;
        off = (s32)h + *e++;
        if (kind == 0x215 || kind == 0x10D1) kind = 0xD54;
        o = D_0025CFC0.arr[i];
        if (o == 0) {
            if (kind == 0) {
                o = D_0025023C;
                func_005A83A8(o, 0);
            } else {
                o = func_005A8280(kind, 0);
            }
            o->h32 = 0x1FF;
            o->b62 = 0xFF;
            o->h34 |= 6;
            o->w98 = 0;
            o->hB4 = 0;
            o->d38 = 0x0038383800000000L;
            if (o->w24->b6 != 0) o->b63 = 0x18;
            b = o->w24->bC;
            o->w24->bC = b + 1;
            o->b42 = b;
            o->b43 = b;
            D_0025CFC0.arr[i] = o;
            if (o->hAA == 0xD54) D_0025CFC0.w54 = (s32)o;
        }
        o->w68 = off;
        o->w24->w48[o->b42] = (s32)e;
        for (k = 0; k < ((u8 *)e)[0x10]; k++) {
            s32 *q = (s32 *)((u8 *)e + 0x1C);
            q[k] = (s32)e + q[k];
        }
    }
}
