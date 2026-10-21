#include "common.h"

/* localdecomp:start func_00429740 */
extern void func_0011F0A0(s32);
extern void func_0011F0A0();
void func_00433EA0(u8 *, u32);

typedef struct { u8 p0[6]; u8 b6; u8 p7[5]; u8 bC; u8 pD[0x3B]; s32 w48[1]; } W_395648;
typedef struct { u8 p0[0x24]; W_395648 *w24; u8 p28[0xA]; u16 h32; u16 h34; u8 p36[2]; long d38; u8 p40[2]; u8 b42; u8 b43; u8 p44[0x1E]; u8 b62; u8 b63; u8 p64[4]; s32 w68; u8 p6C[0x2C]; s32 w98; u8 p9C[0xE]; s16 hAA; u8 pAC[8]; s16 hB4; } O_395648;
typedef struct { u8 p0[0x38]; s32 w38; u8 p3C[4]; s16 h40; u8 p42[2]; s16 h44; u8 p46[2]; s16 h48; u8 p4A[0xA]; s32 w54; u8 p58[0xC]; s32 w64; u8 *w68; s32 w6C; u8 p70[0xC]; s16 h7C; s16 h7E; u8 p80[0x120]; O_395648 *arr[1]; } G_395648;
typedef struct { u8 p0[0x25C0]; u8 *q25C0; } Q_395648;
extern G_395648 D_001E6E00_00395648;
extern Q_395648 D_001A4BE0;
extern O_395648 *D_001DF9CC;
extern void func_0011F0A0(s32);
extern void func_00435F98(O_395648 *, s32);
extern O_395648 *func_00435E70_00395648(s32, s32);
void func_00429740(void) {
    u8 *h;
    s32 *tp;
    s32 *e;
    s32 i, k, kind, b, x;
    s32 off;
    O_395648 *o;
    func_0011F0A0(0);
    func_00433EA0((u8 *)D_001E6E00_00395648.w6C, (u32)D_001E6E00_00395648.w68);
    func_0011F0A0(0);
    h = D_001E6E00_00395648.w68;
    D_001E6E00_00395648.w38 = 0;
    tp = (s32 *)(h + 0x14);
    D_001E6E00_00395648.h40 = *(u16 *)(h + 0);
    x = *(s32 *)(h + 4);
    D_001E6E00_00395648.h48 = *(u16 *)(h + 8);
    D_001E6E00_00395648.h44 = *(u16 *)(h + 0xC);
    D_001E6E00_00395648.w64 = (s32)h + *(s32 *)(h + 0x10);
    if (x != 0) {
        D_001E6E00_00395648.h7C = x;
        D_001E6E00_00395648.h7E = (x >> 16) + 1;
    }
    for (i = 0; i < D_001E6E00_00395648.h44; i++) {
        e = (s32 *)(h + *tp++);
        kind = *e;
        e += 3;
        off = (s32)h + *e++;
        if (kind == 0x215 || kind == 0x10D1) kind = 0xD54;
        o = D_001E6E00_00395648.arr[i];
        if (o == 0) {
            if (kind == 0) {
                o = D_001DF9CC;
                func_00435F98(o, 0);
            } else {
                o = func_00435E70_00395648(kind, 0);
            }
            o->h32 = 0x1FF;
            o->b62 = 0xFF;
            o->h34 |= 6;
            o->w98 = 0;
            o->hB4 = 0;
            if (D_001A4BE0.q25C0 == 0) {
                o->d38 = 0x0038383800000000L;
            } else {
                o->d38 = *(long *)(D_001A4BE0.q25C0 + 0x38);
            }
            if (o->w24->b6 != 0) o->b63 = 0x18;
            b = o->w24->bC;
            o->w24->bC = b + 1;
            o->b42 = b;
            o->b43 = b;
            D_001E6E00_00395648.arr[i] = o;
            if (o->hAA == 0xD54) D_001E6E00_00395648.w54 = (s32)o;
        }
        o->w68 = off;
        o->w24->w48[o->b42] = (s32)e;
        for (k = 0; k < ((u8 *)e)[0x10]; k++) {
            s32 *q = (s32 *)((u8 *)e + 0x1C);
            q[k] = (s32)e + q[k];
        }
    }
}
/* localdecomp:end func_00429740 */
