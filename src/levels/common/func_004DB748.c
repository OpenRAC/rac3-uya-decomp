#include "common.h"

/* localdecomp:start func_004DB748 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_4DB748;
typedef struct {
    u8 pad0[0x10];
    V4_4DB748 pos;
    u8 pad20[0x14];
    u16 h52;
    u8 pad36[0x2C];
    u8 b98;
    u8 pad63[0x47];
    s16 h170;
    u8 padAC[0x14];
    u8 m192[0x20];
    V4_4DB748 v224;
    V4_4DB748 v240;
} M_4DB748;
typedef struct {
    s32 x;
    u8 pad4[76];
} E_4DB748;
typedef struct {
    u8 pad0[128];
    V4_4DB748 q128;
    V4_4DB748 q144;
    u8 pad160[3064 - 160];
    M_4DB748 *p3064;
    u8 pad3068[3728 - 3068];
    f32 f3728;
    f32 f3732;
    f32 f3736;
    u8 pad3740[4480 - 3740];
    s32 w4480;
    f32 f4484;
    f32 f4488;
    u8 pad4492[4648 - 4492];
    E_4DB748 arr[7];
    u8 pad5208[9664 - 5208];
    M_4DB748 *moby;
    u8 pad9668[10124 - 9668];
    s32 a10124[9];
    u8 pad10160[10252 - 10160];
    s32 w10252;
    u8 pad10256[10276 - 10256];
    f32 f10276;
    f32 f10280;
    u8 pad10284[10320 - 10284];
    s32 w10320;
    s32 w10324;
    s16 h10328;
    u8 pad10330[10372 - 10330];
    s16 h10372;
} G_4DB748;
typedef struct {
    V4_4DB748 q0;
    u8 pad10[9540 - 16];
    u8 b9540;
} H_4DB748;
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 padC[64 - 12];
    s16 h64;
    u8 pad42[120 - 66];
    s32 w120;
} S_4DB748;
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[62];
    u128_t q64;
    u128_t q80;
    u128_t q96;
    u128_t q112;
    u128_t q128;
    u128_t q144;
    u8 pad160[16];
} P_4DB748;
typedef struct {
    V4_4DB748 q0;
    V4_4DB748 q16;
} C_4DB748;
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3[13];
} B_4DB748;

extern S_4DB748 D_00142660;
extern G_4DB748 D_001A4BE0;
extern H_4DB748 D_001A4C90;
extern s32 D_001D673C;
extern s32 D_001DFCD0[2];
extern M_4DB748 *D_001E009C;
extern M_4DB748 *D_001E00A0;
extern V4_4DB748 D_001EAAA0;
extern C_4DB748 D_0016C5F0;
extern s32 D_001D4C40;
extern P_4DB748 D_002F4580[];
extern B_4DB748 D_00142D40;
extern B_4DB748 D_00142CA0;

extern void func_00422BD0(s32);
extern void func_0040BBA8(void *, s32, s32);
extern void func_0040C638(void *, V4_4DB748 *);
extern void func_0040C0F0(V4_4DB748 *, V4_4DB748 *, f32);
extern s32 func_003F8448(V4_4DB748 *, V4_4DB748 *, s32, M_4DB748 *, s32);
extern void func_004EBA68(void);
extern void func_004E0800(void);
extern void func_0050BE30(s32, s32);
extern void func_0050F920(void);
extern s32 func_00440878(s32, s32);
extern void func_004344A0(void);
extern s32 func_0050FF18(void);
extern void func_004DE160(s32);
extern void func_003F3918(s32, s32);

void func_004DB748(void) {
    s32 saved[7];
    V4_4DB748 b;
    V4_4DB748 a;
    M_4DB748 *m;
    M_4DB748 *n;
    M_4DB748 *base;
    s32 i;
    s32 j;
    s32 k;

    if (D_00142660.h64 == 4 && D_00142660.w120 != D_00142660.h64) {
        D_00142660.h64 = *(u16 *)&D_00142660.w120;
        func_00422BD0(D_00142660.w120);
    }
    for (j = 0; j < 7; j++) {
        saved[j] = D_001A4BE0.arr[j].x;
    }
    func_0040BBA8(&D_001A4BE0, 0, 10464);
    for (k = 0; k < 7; k++) {
        saved[k] = D_001A4BE0.arr[k].x;
    }
    if (D_001D673C != 0) {
        D_001A4C90.q0 = *(V4_4DB748 *)D_001DFCD0;
        D_001A4C90.b9540 = 2;
    }
    base = D_001E009C;
    for (i = 0; &base[i] < D_001E00A0; i++) {
        m = &base[i];
        if (m->h170 == 0) {
            D_001A4BE0.moby = m;
            func_0040C638(m->m192, &m->v240);
            D_001A4BE0.q144 = D_001A4BE0.moby->v240;
            func_0040C0F0(&a, &D_001A4BE0.moby->v224, -3.0f);
            func_0040C0F0(&b, &D_001A4BE0.moby->v224, 1.0f);
            n = D_001A4BE0.moby;
            {
                u128_t x, y;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(n->pos));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(b) : "j"(x));
            }
            {
                u128_t x, y;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(n->pos));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
            }
            if (func_003F8448(&b, &a, 2, n, 0) != 0) {
                D_001A4BE0.moby->pos = D_001EAAA0;
            }
            D_001A4BE0.moby->h52 |= 2;
            D_001A4BE0.p3064 = D_001A4BE0.moby;
            D_001A4BE0.q128 = D_001A4BE0.moby->pos;
            func_004EBA68();
            func_004E0800();
            func_0050BE30(0, 0);
            D_0016C5F0.q0 = D_001A4BE0.q128;
            D_0016C5F0.q16 = D_001A4BE0.q144;
            break;
        }
    }
    D_001A4BE0.moby->b98 = 255;
    if (D_001D4C40 == 0) {
        D_001D4C40 = 9;
    }
    for (j = 0; j < 43; j++) {
        D_002F4580[j].b1 = 0;
        __asm__ __volatile__(
            "sq $0, %0\n"
            "sq $0, %1\n"
            "sq $0, %2\n"
            "sq $0, %3\n"
            "sq $0, %4\n"
            "sq $0, %5\n"
            : "=m"(D_002F4580[j].q96), "=m"(D_002F4580[j].q64), "=m"(D_002F4580[j].q80),
              "=m"(D_002F4580[j].q144), "=m"(D_002F4580[j].q112), "=m"(D_002F4580[j].q128));
    }
    for (k = 0; k < 9; k++) {
        D_001A4BE0.a10124[k] = -1;
    }
    D_001A4BE0.f10276 = 2.125f;
    D_001A4BE0.f10280 = 1.25f;
    if (D_00142660.w8 < 10) {
        D_00142660.w8 = 10;
    }
    if (D_00142660.w8 == 0) {
        func_0050F920();
    }
    D_001A4BE0.w10320 = D_00142660.w8;
    D_001A4BE0.w10324 = 4;
    D_001A4BE0.h10328 = D_001A4BE0.w10320;
    D_001A4BE0.w4480 = func_00440878(180, 300);
    D_001A4BE0.f4484 = 0.007f;
    D_001A4BE0.f4488 = 0.3f;
    D_001A4BE0.f3728 = 1.15f;
    D_001A4BE0.f3732 = D_001A4BE0.q128.z;
    D_001A4BE0.f3736 = 0.12f;
    D_00142CA0.b2 = 1;
    D_00142D40.b2 = 1;
    func_004344A0();
    D_001A4BE0.h10372 = 0;
    if (func_0050FF18() != 0 && D_001A4BE0.w10252 != 4 && D_001A4BE0.w10252 != 81) {
        D_001A4BE0.w10252 = 32;
    } else if (D_001A4BE0.w10252 == 32) {
        D_001A4BE0.w10252 = 0;
    }
    func_004DE160(0);
    func_003F3918(0, 1);
}
/* localdecomp:end func_004DB748 */
