#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; u32 f10; } S_EAA80_4D3998;
typedef struct { u8 p0[0x90]; s32 f90[6]; } S_A30B0_4D3998;
typedef struct { u8 p0[0x20]; s16 f20; s16 f22; u8 p24[8]; s16 f2C; s16 f2E; u8 p30[0x34]; s32 f64; } S_6C580_4D3998;
typedef struct { s16 a; s16 b; s32 c; s32 d; s32 e; } S_F3E58_4D3998;
typedef struct { s32 f0; void *f4; void *f8; void *fC; void *f10; void *f14; } S_F3D80_4D3998;
typedef struct { u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C; u8 p240[0x10]; s32 f250; s32 f254; s32 f258; } S_E7600_4D3998;
typedef union { u128_t q; f32 f[4]; } U_E2C90_4D3998;

extern u8 D_001EA8C0[];
extern S_EAA80_4D3998 D_001EAA80;
extern s32 D_001D6694[] __attribute__((section(".sdata")));
extern u8 D_001CCFD7[];
extern S_A30B0_4D3998 D_001A30B0;
extern s32 D_001DFBEC[] __attribute__((section(".sdata")));
extern s32 D_001D545C[] __attribute__((section(".sdata")));
extern s32 D_001DFBC4[] __attribute__((section(".sdata")));
extern S_6C580_4D3998 D_0016C580;
extern s32 D_001D9870[] __attribute__((section(".sdata")));
extern s32 D_001DB918;
extern s32 D_001DB91C;
extern S_F3E58_4D3998 D_002F3E58[];
extern S_F3D80_4D3998 D_002F3D80[];
extern s32 D_001DB8F8;
extern s32 D_001DB8FC;
extern void *D_001DB8E4;
extern void *D_001DB8E8;
extern void *D_001DB8EC;
extern void *D_001DB8F0;
extern void *D_001DB8F4;
extern S_E7600_4D3998 D_001E7600;
extern u8 D_001DFA64[] __attribute__((section(".sdata")));
extern u8 D_001DFA65[] __attribute__((section(".sdata")));
extern u8 D_001DFA66[] __attribute__((section(".sdata")));
extern f32 D_001DFA68[] __attribute__((section(".sdata")));
extern f32 D_001DFA6C[] __attribute__((section(".sdata")));
extern f32 D_001DFA70[] __attribute__((section(".sdata")));
extern f32 D_001DFA74[] __attribute__((section(".sdata")));
extern U_E2C90_4D3998 D_001E2C90;
extern s32 D_001D4B4C[] __attribute__((section(".sdata")));
extern s32 D_001D4B48;
extern u8 D_001F4BC0[];
extern void func_0040BBA8();
extern void func_004374C8(void);
extern void func_0011F0A0(s32);
extern void func_0013CF80(s32, s32, s32, s32, s32);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern void func_004A7810(void);
extern void func_0045BEC8(void);
extern void func_0013BF00(s32);
extern void func_0013BED0(void);
extern void func_004D3460();
extern void func_00412C70(s32, long, long);
extern void func_0013D310();
extern void func_004D4A10(void);
extern void func_004D38E8(void);

/* localdecomp:start func_004D3998 */
s32 func_004D3998(void) {
    s32 i;
    s32 idx;
    s32 lvl, pl;
    s32 v;
    U_E2C90_4D3998 *z;
    S_F3E58_4D3998 *e;
    S_F3D80_4D3998 *t;
    S_E7600_4D3998 *q;
    func_0040BBA8(D_001EA8C0, -1, 0x80);
    D_001EAA80.f10 |= 0x80000000;
    D_001D6694[0] = 6;
    func_004374C8();
    func_0011F0A0(0);
    func_0013CF80(2, 0, 0, 0, 0);
    func_0013CA28();
    func_0013B620();
    func_004A7810();
    func_0045BEC8();
    D_001CCFD7[0] = 1;
    for (i = 0; i < 6; i++) {
        if (D_001A30B0.f90[i] != 0) {
            func_0013BF00(D_001A30B0.f90[i]);
            func_0013BED0();
            D_001DFBEC[0] = 0;
            D_001A30B0.f90[i] = 0;
        }
    }
    lvl = D_001D545C[0];
    pl = D_001DFBC4[0];
    D_0016C580.f20 = 2;
    D_0016C580.f2E = -1;
    D_0016C580.f22 = -1;
    D_0016C580.f2C = 0;
    D_0016C580.f64 = -1;
    D_001D9870[0] = 0;
    D_001DB918 = lvl;
    D_001DB91C = pl;
    e = D_002F3E58;
    i = 0;
    do {
        if ((e->a == -1 && e->b == pl) || (e->a == lvl && (e->b == -1 || e->b == pl))) break;
        i++;
        e++;
    } while (i < 51);
    idx = 8;
    D_001DB8FC = 0;
    D_001DB8F8 = 0;
    if (i < 51) {
        D_001DB8FC = e->e;
        D_001DB8F8 = e->d;
        idx = e->c;
    }
    t = &D_002F3D80[idx];
    D_001DB8E4 = 0;
    D_001DB8E8 = 0;
    D_001DB8EC = 0;
    D_001DB8F0 = func_004D3460;
    D_001DB8F4 = 0;
    if (t->f4) D_001DB8E4 = t->f4;
    if (t->f8) D_001DB8E8 = t->f8;
    if (t->fC) D_001DB8EC = t->fC;
    if (t->f10) D_001DB8F0 = t->f10;
    if (t->f14) D_001DB8F4 = t->f14;
    v = t->f0;
    q = &D_001E7600;
    q->f258 = 0x10;
    q->f250 = 0;
    q->f254 = 0;
    q->f228 = 0;
    q->f22C = 524288.0f;
    q->f238 = 255.0f;
    q->f23C = 128.0f;
    D_0016C580.f2E = v;
    D_001DFA64[0] = q->f250;
    D_001DFA65[0] = q->f254;
    D_001DFA66[0] = q->f258;
    D_001DFA68[0] = q->f228;
    D_001DFA6C[0] = q->f22C;
    D_001DFA70[0] = q->f238;
    D_001DFA74[0] = q->f23C;
    func_00412C70(0, 0, 0);
    D_001EAA80.f10 |= 0x80000000;
    z = &D_001E2C90;
    __asm__("sq $0,%0" : "=m"(z->q));
    z->f[2] = -1.0f;
    D_001D4B4C[0] = 1;
    D_001D545C[0] = D_001DFBC4[0];
    D_001D4B48 = 0;
    func_0013D310(D_001D545C[0], D_001F4BC0);
    func_004D4A10();
    func_004D38E8();
    if (D_001DB8E4) ((void (*)(s32, s32))D_001DB8E4)(D_001DB8F8, D_001DB8FC);
    return 1;
}
/* localdecomp:end func_004D3998 */
