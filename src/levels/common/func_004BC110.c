#include "common.h"

/* localdecomp:start func_004BC110 */
typedef int Q_4BC110 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4BC110;
typedef struct {
    u8 pad0[5];
    u8 f5;
    u8 pad6[2];
    f32 f8;
    u8 padC[0x17];
    u8 f23;
    u8 pad24[4];
    s32 f28;
    u8 pad2C[0xC];
    u8 *f38;
    u8 *f3C;
} E_4BC110;
typedef struct {
    u8 pad0[0xC0];
    Q_4BC110 fC0;
    Q_4BC110 fD0;
    Q_4BC110 fE0;
} M_4BC110;
typedef struct {
    u8 pad0[0x90];
    Q_4BC110 f90;
    u8 padA0[0x6C0 - 0xA0];
    Q_4BC110 m[3];
    V4_4BC110 f6F0;
    V4_4BC110 f700;
    u8 pad710[0xE78 - 0x710];
    E_4BC110 *fE78[3];
    s32 fE84;
    u8 padE88[0x1434 - 0xE88];
    s16 f1434;
    u8 pad1436[0x16B0 - 0x1436];
    s32 f16B0;
    u8 pad16B4[0x25C0 - 0x16B4];
    M_4BC110 *f25C0;
    u8 pad25C4[8];
    s32 f25CC;
    u8 pad25D0[0x19];
    u8 f25E9;
    u8 pad25EA;
    u8 f25EB;
    u8 pad25EC[8];
    u8 f25F4;
    u8 pad25F5[0x2830 - 0x25F5];
    s32 f2830;
    s32 f2834;
} G_4BC110;
typedef struct {
    u8 pad0[0x28];
    s32 f28;
    s32 f2C;
    u8 pad30[0xC0];
} T_4BC110;
typedef struct {
    u8 pad0[0xF8];
    f32 fF8;
    u8 padFC[0xAC];
    f32 f1A8;
} C_4BC110;
extern G_4BC110 D_001A4BE0;
extern Q_4BC110 D_001A52A0[];
extern u8 D_00252940[];
extern u8 D_001425C0[];
extern T_4BC110 D_002C3200[];
extern C_4BC110 D_002F2000;
extern s32 func_004DDC38(s32);
extern void func_004BC080(void);
extern s32 func_004BA970(s32);
extern void func_0040EEC0(M_4BC110 *, E_4BC110 *, s32, s32, s32, s32);
extern void func_0040EAE8(M_4BC110 *, E_4BC110 *);
extern void func_0041C818(f32 *, f32, f32);
extern void func_0040EA48(M_4BC110 *, E_4BC110 **);
extern s32 func_00433B10(s32, s32, s32, s32);
extern f32 func_003E5630(f32, f32);
extern void func_003E4DA0(V4_4BC110 *, V4_4BC110 *);
extern void func_003E50C8(void *, void *, V4_4BC110 *);
extern void func_003E4A38(void *, void *, void *);
void func_004BC110(void) {
    V4_4BC110 m[3];
    V4_4BC110 v;
    s32 i;
    s32 r;
    s32 a;
    T_4BC110 *t;
    f32 f;
    G_4BC110 *g;
    Q_4BC110 q;
    if (D_001A4BE0.f25E9 != 0 && D_001A4BE0.f25EB != 0 && func_004DDC38(-1) == 0) {
        func_004BC080();
    }
    for (i = 0; i < 2; i++) {
        if (D_001A4BE0.fE78[i] == 0) {
            continue;
        }
        D_001A4BE0.fE78[i]->f38 = D_00252940 + i * 0xC00;
        D_001A4BE0.fE78[i]->f3C = D_00252940 + 0x600 + i * 0xC00;
        r = func_004BA970(0);
        if (r == D_001A4BE0.f2834) {
            t = &D_002C3200[D_001425C0[r]];
            a = t->f28;
            if (D_001A4BE0.f25CC == 12) {
                a = t->f2C;
            }
            if (a != -1 && D_001A4BE0.fE78[i]->f23 != a) {
                D_001A4BE0.f2830 = a;
                func_0040EEC0(D_001A4BE0.f25C0, D_001A4BE0.fE78[i], a, 0, 8, 1);
            }
        }
        func_0040EAE8(D_001A4BE0.f25C0, D_001A4BE0.fE78[i]);
        if (D_001A4BE0.fE84 != 0) {
            if (D_001A4BE0.fE84 == 2) {
                func_0041C818(&D_001A4BE0.fE78[i]->f8, 0.0f, 0.25f);
            } else {
                func_0041C818(&D_001A4BE0.fE78[i]->f8, 0.0f, 0.07f);
            }
            if (D_001A4BE0.fE78[i]->f8 == 0.0f) {
                func_0040EA48(D_001A4BE0.f25C0, &D_001A4BE0.fE78[i]);
                return;
            }
        } else {
            func_0041C818(&D_001A4BE0.fE78[i]->f8, 1.0f, 0.2f);
            if ((D_001A4BE0.fE78[i]->f5 & 2) && D_001A4BE0.f25EB == 0) {
                D_001A4BE0.fE84 = 1;
                D_001A4BE0.fE78[i]->f28 = 0;
                D_001A4BE0.f25E9 = 0;
                return;
            }
        }
    }
    f = 0.0f;
    if (D_001A4BE0.f1434 == 0 && (D_001A4BE0.f16B0 != 1 || func_00433B10(0x28, 2, 0, 0) == 0)) {
        f = func_003E5630(D_002F2000.f1A8, D_002F2000.fF8);
    }
    __asm__("sq $0, %0" : "=m"(v));
    v.z = f;
    func_003E4DA0(m, &v);
    func_003E50C8(D_001A52A0, D_001A52A0, m);
    g = (G_4BC110 *)((u8 *)D_001A52A0 - 0x6C0);
    D_001A52A0[0] = g->f25C0->fC0;
    D_001A52A0[1] = g->f25C0->fD0;
    q = g->f25C0->fE0;
    __asm__("sq $0, %0" : "=m"(g->f6F0));
    D_001A52A0[2] = q;
    g->f6F0.x = 1.0f;
    func_003E4A38(&D_001A52A0[3], &D_001A52A0[3], D_001A52A0);
    *(Q_4BC110 *)&g->f700 = g->f90;
    if (g->f25F4 == 0) {
        g->f700.z = func_003E5630(g->f700.z, f);
    }
}
/* localdecomp:end func_004BC110 */
