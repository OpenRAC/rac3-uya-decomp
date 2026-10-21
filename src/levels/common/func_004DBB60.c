#include "common.h"

/* localdecomp:start func_004DBB60 */
typedef int Q_4DBB60 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4DBB60;
typedef struct {
    u8 pad0[32];
    V4_4DBB60 v20;
    u8 pad30[80];
    V4_4DBB60 v80;
    u8 pad90[8];
    f32 f98;
    u8 pad9C[468];
    f32 f270;
    f32 f274;
    f32 f278;
    f32 f27C;
    u8 pad280[4];
    f32 f284;
    u8 pad288[2428];
    f32 fC04;
    u8 padC08[2168];
    u8 a1480[48];
    u8 a14B0[144];
    u8 a1540[192];
    f32 f1600;
    u8 pad1604[4];
    f32 f1608;
    u8 pad160C[28];
    void *p1628;
    void *p162C;
    u8 pad1630[52];
    f32 f1664;
    u8 pad1668[100];
    f32 f16CC;
    u8 pad16D0[3824];
    s32 i25C0;
    s32 i25C4;
    u8 pad25C8[524];
    s32 i27D4;
    s32 i27D8;
    s32 i27DC;
    u8 pad27E0[228];
    s32 i28C4;
} G_4DBB60;
typedef struct { s32 a; u8 pad[12]; } E16_4DBB60;
typedef struct { s32 a; u8 pad[28]; } E32_4DBB60;
typedef struct { u8 pad0[20]; E16_4DBB60 m[3][3]; u8 b164; } L_4DBB60;
typedef struct { u8 b0; u8 pad[239]; } C_4DBB60;
typedef struct { u8 pad0[70]; u8 b70; } P_4DBB60;
typedef struct { u8 pad0[36]; P_4DBB60 *p24; u8 pad28[130]; s16 h170; u8 padAC[84]; } M_4DBB60;
extern G_4DBB60 D_001A4BE0;
extern s32 D_001D4C40;
extern volatile s32 D_001D4C48;
extern u8 D_001425C0[];
extern C_4DBB60 D_002C5640[];
extern L_4DBB60 D_00143950;
extern E32_4DBB60 D_00143A10[];
extern E32_4DBB60 D_00143A70[];
extern E32_4DBB60 D_00143AD0[];
extern M_4DBB60 *D_001F0368[];
extern M_4DBB60 *D_001F03E8[];
extern M_4DBB60 *D_001F0468[];
extern M_4DBB60 *D_001F04E8[];
extern M_4DBB60 *D_001E009C;
extern M_4DBB60 *D_001E00A4;
extern s32 func_00416920(s32);
extern void func_00503930(s32);
extern void func_0050BF28(void);
extern void func_004FC518(s32, s32);
extern void func_004DE160(s32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_00410840(void *, void *, f32, s32, f32);
extern void func_00510530(s32);
extern void **func_00438488(s32, s32, s32);
void func_004DBB60(void) {
    V4_4DBB60 t;
    Q_4DBB60 a, b;
    L_4DBB60 *l;
    M_4DBB60 *m;
    void **h;
    s32 i;
    s32 j0, j1, j2, j3;
    s32 k;

    D_001A4BE0.f270 = 0.8f;
    D_001A4BE0.f274 = 0.7f;
    D_001A4BE0.f284 = 0.45f;
    D_001A4BE0.f278 = 0.8f;
    D_001A4BE0.f27C = 0.7f;
    D_001D4C48 = 0;
    if (D_001D4C40 != 9 && (D_002C5640[D_001425C0[D_001D4C40]].b0 != 0 || func_00416920(D_001D4C40) != 0)) {
        func_00503930(D_001D4C40);
    }
    D_001A4BE0.i25C4 = 0;
    D_001A4BE0.fC04 = 1.0f;
    func_0050BF28();
    func_004FC518(0, 1);
    func_004DE160(0);
    D_001A4BE0.i27D4 = -1;
    D_001A4BE0.i27D8 = -1;
    D_001A4BE0.i27DC = -1;
    D_001A4BE0.f16CC = 1.75f;
    func_0040C0F0(&t, &D_001A4BE0.v20, 1.75f);
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(t));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(D_001A4BE0.v80));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(a));
    func_00410840(D_001A4BE0.a1540, &t, D_001A4BE0.f98, D_001A4BE0.i25C0, 0.0f);
    l = &D_00143950;
    D_001A4BE0.p1628 = D_001A4BE0.a1480;
    D_001A4BE0.p162C = D_001A4BE0.a14B0;
    func_00510530(l->b164);
    if (l->b164 == 1) {
        D_001A4BE0.f1600 = -6.0f;
        D_001A4BE0.f1608 = 0.0f;
        D_001A4BE0.f1664 = 6.0f;
    }
    for (k = 0; k < 3; k++) {
        D_00143A10[k].a = D_00143950.m[0][k].a;
        D_00143A70[k].a = D_00143950.m[1][k].a;
        D_00143AD0[k].a = D_00143950.m[2][k].a;
    }
    D_001A4BE0.i28C4 = 0;
    for (i = 0; i < 32; i++) {
        D_001F0368[i] = 0;
    }
    for (i = 0; i < 32; i++) {
        D_001F03E8[i] = 0;
    }
    for (i = 0; i < 32; i++) {
        D_001F0468[i] = 0;
    }
    for (i = 0; i < 32; i++) {
        D_001F04E8[i] = 0;
    }
    for (m = D_001E009C; m < D_001E00A4; m++) {
        if (m->h170 == 803) {
            for (j0 = 0; j0 < 32; j0++) {
                if (D_001F0368[j0] == 0) {
                    D_001F0368[j0] = m;
                    break;
                }
            }
        } else if (m->h170 == 758) {
            for (j1 = 0; j1 < 32; j1++) {
                if (D_001F03E8[j1] == 0) {
                    D_001F03E8[j1] = m;
                    break;
                }
            }
        } else if (m->h170 == 2461) {
            for (j2 = 0; j2 < 32; j2++) {
                if (D_001F0468[j2] == 0) {
                    D_001F0468[j2] = m;
                    break;
                }
            }
        } else if (m != 0 && m->p24 != 0 && m->p24->b70 == 23) {
            for (j3 = 0; j3 < 32; j3++) {
                if (D_001F04E8[j3] == 0) {
                    D_001F04E8[j3] = m;
                    break;
                }
            }
        }
    }
    h = func_00438488(7791, 0, 12);
    if (h != 0) {
        ((void (*)(void))*h)();
    }
}
/* localdecomp:end func_004DBB60 */
