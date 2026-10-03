#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_003E3040();
extern void func_003A3DA0(s32);
extern void func_0038CAF0(void);
extern s32 D_001D5520[];
extern void func_0038CE40(s32, s32, s32, s32, s32, s32);
extern s32 func_003E2C88(s32, f32, f32);
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003DBDF0);

/* localdecomp:start func_003DBE20 */
extern void func_003A3DA0(s32);
extern void func_0038CAF0(void);
extern s32 D_001D5520[];
extern void func_0038CE40(s32, s32, s32, s32, s32, s32);
extern void func_003D3DC8(void);
void func_003DBE20(void) {   /* same as func_003B0F58 plus the call below */
    func_003A3DA0(1);
    func_0038CAF0();
    if (D_001D5520[0] != 0) {
        func_0038CE40(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        func_0038CE40(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
    func_003D3DC8();
}
/* localdecomp:end func_003DBE20 */

LINKER_REMNANT("asm/remnants", func_003DBE98);

/* localdecomp:start func_003DBEA0 */
extern s32 D_00302DC0[];
 
s32 func_003DBEA0(void) {
    return D_00302DC0[0];
}
/* localdecomp:end func_003DBEA0 */

LINKER_REMNANT("asm/remnants", func_003DBEB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003DBEC8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318AE0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318B10);

INCLUDE_ASM("asm/nonmatchings/text", func_003DCD08);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318B90);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318BC0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318C50);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318C70);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE260);

/* localdecomp:start func_003DE3A8 */
__asm__(".extern D_001D950C_003DE3A8, 4");
extern f32 D_001D950C_003DE3A8;
extern f32 D_002224A0_003DE3A8[];
extern void func_003BF778();
extern void func_003890D8();
extern void func_00388EB8();
void func_003DE3A8(f32 *arg0) {
    f32 a[4];
    f32 b[12];
    ((void (*)(f32 *, f32 *, f32))func_003BF778)(a, D_002224A0_003DE3A8, *arg0 * (D_001D950C_003DE3A8 * 0.017453292f * 0.016666668f));
    func_003890D8(a, b);
    func_00388EB8(D_002224A0_003DE3A8, b, D_002224A0_003DE3A8);
}
/* localdecomp:end func_003DE3A8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003DE430);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE4A0);

LINKER_REMNANT("asm/remnants", func_003DE558);

INCLUDE_ASM("asm/nonmatchings/text", func_003DE560);

/* localdecomp:start func_003DE870 */
typedef struct { u8 pad[0x40]; s32 f40; u8 pad2[0x14]; s32 f58; } S_302D80;
extern S_302D80 D_00302D80;
 
void func_003DE870(void) {
    S_302D80 *s = &D_00302D80;
    if (s->f40 == 7 && s->f58 == 1) {
        s->f58 = 2;
    }
}
/* localdecomp:end func_003DE870 */

/* localdecomp:start func_003DE8A0 */
extern s32 D_00302DC0[];
s32 func_003DE8A0(void) {
    return D_00302DC0[0] == 7;
}
/* localdecomp:end func_003DE8A0 */

/* localdecomp:start func_003DE8B8 */
extern s32 D_001D94F0;
void func_003DE8B8(void) {
    D_001D94F0 = 3;
}
/* localdecomp:end func_003DE8B8 */

LINKER_REMNANT("asm/remnants", func_003DE8C8);

/* localdecomp:start func_003DE8D0 */
extern s16 D_00302E04[];
 
void func_003DE8D0(void) {
    D_00302E04[0] = 0;
}
/* localdecomp:end func_003DE8D0 */

/* localdecomp:start func_003DE8E0 */
void *func_003DE8E0(void *p) {
    return (u8 *)p + 0xED1C;
}
/* localdecomp:end func_003DE8E0 */

/* localdecomp:start func_003DE8F0 */
__asm__(".extern D_001D9590_003DE8F0, 4");
__asm__(".extern D_001D9598_003DE8F0, 4");

typedef struct { u8 pad[0xAA]; s16 xAA; } M_3DE8F0;
typedef struct { f32 f0; s16 h4; } R_3DE8F0;
typedef struct {
    u8 pad0[0x19E0];
    M_3DE8F0 *x19E0;
    u8 pad19E4[0x25C4 - 0x19E4];
    s32 x25C4;
    u8 pad25C8[0x25E4 - 0x25C8];
    u8 x25E4;
    u8 pad25E5[0x2850 - 0x25E5];
    s32 x2850;
} W_3DE8F0;
typedef struct { u8 pad[0x20]; u8 x20; } F_3DE8F0;

extern s32 D_001D9590_003DE8F0;
extern f32 D_001D9598_003DE8F0;
extern W_3DE8F0 D_1A4BE0_003DE8F0[];
extern F_3DE8F0 D_142CA0_003DE8F0[];
extern s32 D_00142668_003DE8F0[];
extern s32 D_001DA868_003DE8F0[2];
extern char D_001D95A0_003DE8F0[];

extern R_3DE8F0 *func_0037E0B8_003DE8F0(M_3DE8F0 *);
extern s32 func_003894A0_003DE8F0(s32, s32, f32);
extern f32 func_00388960_003DE8F0(f32);
extern s32 func_003DE8E0_003DE8F0(s32);
extern void func_003DFB20_003DE8F0(f32 *, f32);
extern s32 func_003E1E50_003DE8F0(s32, f32, f32);
extern s32 func_003E2C88_003DE8F0(s32, f32, f32);
extern s32 func_003E24B0_003DE8F0(s32, s32);
extern s32 func_003E28E0_003DE8F0(s32, s32);
extern s32 func_003E22D0_003DE8F0(s32, s32, s32);
extern s32 func_003E2808_003DE8F0(s32, s32);
extern s32 func_003E2618_003DE8F0(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_11B2E8_003DE8F0(void *, char *, s32);

void func_003DE8F0(void) {
    s32 ammo, max, max2, d0, d1, d2, hund, color;
    f32 fammo, fmax, w2, x, t, b, v;
    f32 x0, y, x1;
    f32 sum;
    R_3DE8F0 *r;
    s16 h;

    ammo = D_1A4BE0_003DE8F0->x2850;
    if ((D_1A4BE0_003DE8F0->x25E4 ^ 1) == 0) {
        max = 4;
    } else {
        max = D_00142668_003DE8F0[0];
    }
    max2 = max;
    if (D_1A4BE0_003DE8F0->x25C4 == 0x31 && D_1A4BE0_003DE8F0->x19E0 != 0) {
        h = D_1A4BE0_003DE8F0->x19E0->xAA;
        if ((h == 0x1A17 || h == 0x107E) && (r = func_0037E0B8_003DE8F0(D_1A4BE0_003DE8F0->x19E0)) != 0) {
            max2 = 100;
            ammo = r->f0 * 100.0f / r->h4;
        }
    }
    fammo = ammo;
    fmax = max2;
    if (!D_142CA0_003DE8F0->x20) {
        f32 w;
        w = fammo / fmax * 0.230333f;
        func_003DFB20_003DE8F0(&w, 0.230333f);
        func_003E2C88_003DE8F0(0x9000A, 0.230333f - w, 0.049333f);
        func_003E1E50_003DE8F0(0x9000A, 0.61558104f, 0.0739995f);
        func_003E2C88_003DE8F0(0x9000B, w, 0.049333f);
        func_003E1E50_003DE8F0(0x9000B, 0.385248f, 0.0739995f);
        func_003E24B0_003DE8F0(0x90008, 0);
    } else {
        f32 w;
        w = fammo / fmax * 0.226833f;
        func_003DFB20_003DE8F0(&w, 0.226833f);
        func_003E2C88_003DE8F0(0x9000A, 0.226833f - w, 0.049333f);
        func_003E1E50_003DE8F0(0x9000A, 0.587748f, 0.0739995f);
        func_003E2C88_003DE8F0(0x9000B, w, 0.049333f);
        func_003E1E50_003DE8F0(0x9000B, 0.360915f, 0.0739995f);
        func_003E24B0_003DE8F0(0x90008, 1);
        func_003E1E50_003DE8F0(0x90008, 0.598917f, 0.074f);
    }
    w2 = 0.09f;
    d0 = func_003DE8E0_003DE8F0(ammo % 10);
    d1 = func_003DE8E0_003DE8F0(ammo / 10 % 10);
    hund = ammo / 100 % 10 != 0;
    d2 = func_003DE8E0_003DE8F0(ammo / 100 % 10);
    func_003E28E0_003DE8F0(0x90003, d0);
    func_003E28E0_003DE8F0(0x90004, d1);
    func_003E28E0_003DE8F0(0x90005, d2);
    func_003E22D0_003DE8F0(0x90005, 1, hund);
    if (hund) {
        w2 = 0.135f;
    }
    func_11B2E8_003DE8F0(D_001DA868_003DE8F0, D_001D95A0_003DE8F0, max2);
    x0 = 0.0f;
    x1 = 0.0f;
    func_003E2618_003DE8F0(0x90006, &x0, &y, &x1, &y);
    sum = w2 + (x1 - x0);
    t = 0.5f;
    if (D_142CA0_003DE8F0->x20) {
        t = 0.475f;
    }
    x = t - sum * 0.5f;
    if (hund) {
        func_003E1E50_003DE8F0(0x90005, x, 0.074f);
        x += 0.045f;
    }
    func_003E1E50_003DE8F0(0x90004, x, 0.074f);
    x += 0.045f;
    func_003E1E50_003DE8F0(0x90003, x, 0.074f);
    func_003E1E50_003DE8F0(0x90006, x + 0.045f, 0.069f);
    if (fammo < fmax * 0.15f) {
        b = D_001D9598_003DE8F0 + 0.05f;
        D_001D9598_003DE8F0 = b;
        if (b >= 2.0f) {
            D_001D9598_003DE8F0 = b - 2.0f;
        }
        D_001D9590_003DE8F0++;
    } else {
        if (D_001D9598_003DE8F0 > 1.0f) {
            D_001D9598_003DE8F0 = 2.0f - D_001D9598_003DE8F0;
        }
        D_001D9598_003DE8F0 = D_001D9598_003DE8F0 * 0.95f;
    }
    v = D_001D9598_003DE8F0 > 1.0f ? 2.0f - D_001D9598_003DE8F0 : D_001D9598_003DE8F0;
    color = func_003894A0_003DE8F0(0x8066CCFF, 0x60202080, (1.0f - func_00388960_003DE8F0(v * 3.1415927f)) * 0.5f);
    func_003E2808_003DE8F0(0x90003, color);
    func_003E2808_003DE8F0(0x90004, color);
    func_003E2808_003DE8F0(0x90005, color);
    func_003E2808_003DE8F0(0x90006, color);
}
/* localdecomp:end func_003DE8F0 */

/* localdecomp:start func_003DEEF0 */
typedef struct { u8 pad[0x28B4]; s32 a; s32 b; } S_003DEEF0;
extern S_003DEEF0 D_001A4BE0_003DEEF0;
extern s32 D_00142694_003DEEF0[];
extern void func_0037DCD8_003DEEF0();
extern s32 func_003E2C88_003DEEF0(s32, f32, f32);
s32 func_003DEEF0(void) {
    s32 l[3];
    s32 pos;
    f32 den;
    f32 num;
    f32 t;
    pos = D_00142694_003DEEF0[0] >> 5;
    l[0] = D_001A4BE0_003DEEF0.b;
    l[1] = D_001A4BE0_003DEEF0.a;
    if (l[0] == 0) {
        l[2] = 0;
        func_0037DCD8_003DEEF0(l, l + 1, l + 2);
    }
    num = (f32)(pos - l[0]);
    den = (f32)(l[1] - l[0]);
    t = (den <= 0.0f) ? 0.0f : num / den;
    return func_003E2C88_003DEEF0(0x90007, t * 0.1285f, 0.008f);
}
/* localdecomp:end func_003DEEF0 */

/* localdecomp:start func_003DEFB8 */
extern u8 D_00142CC0[];
extern u8 D_001426E0_003DEFB8[];
extern s32 func_003E2C88(s32, f32, f32);
void func_003DEFB8(void) {
    if (D_00142CC0[0]) {
        u8 *s = D_001426E0_003DEFB8;
        f32 r = 0.0f;
        if (s[0xD4]) r = (f32)s[0xD3] / (f32)s[0xD4];
        func_003E2C88(0x90008, r * 0.0430830009f, 0.0504160002f);
    }
}
/* localdecomp:end func_003DEFB8 */

/* localdecomp:start func_003DF038 */
__asm__(".extern D_001D9594_003DF038, 1");
__asm__(".extern D_001D959D_003DF038, 1");
__asm__(".extern D_001D959C_003DF038, 1");
__asm__(".extern D_001D97A0_003DF038, 4");
typedef struct { s32 x0, x4, x8, xC; } S_3DF038;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3DF038;
typedef struct { u8 pad[8]; VT_3DF038 *vt; u8 padC[0x3E]; s16 x4A; } W_3DF038;

extern u8 D_001D9594_003DF038;
extern u8 D_001D959D_003DF038;
extern u8 D_001D959C_003DF038;
extern s32 D_001D97A0_003DF038;
extern s32 D_001DA868_003DF038[2];
extern S_3DF038 D_001DA9B8_003DF038[];

extern void func_003E1E48_003DF038(s32);
extern void func_00388440_003DF038(void *, s32, s32);
extern void func_003AFAA8_003DF038(s32);
extern void func_003DFB40_003DF038(s32);
extern void func_003DFCA8_003DF038(s32);
extern void func_003DFE10_003DF038(s32);
extern s32 func_0037DF98_003DF038(s32);
extern s32 func_0038E1E0_003DF038(void);
extern s32 func_003E3A80_003DF038(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E3BD0_003DF038(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E2560_003DF038(s32, s32);
extern s32 func_003E23C0_003DF038(s32, s32, s32);
extern s32 func_003E22D0_003DF038(s32, s32, s32);
extern s32 func_003E2A90_003DF038(s32, s32, s32, s32, s32);
extern s32 func_003E2B98_003DF038(s32, s32, s32);
extern s32 func_003E1E50_003DF038(s32, f32, f32);
extern s32 func_003E2028_003DF038(s32, f32, f32);
extern s32 func_003E2C88_003DF038(s32, f32, f32);
extern s32 func_003E29B8_003DF038(s32, s32);
extern s32 func_003E2808_003DF038(s32, s32);
extern s32 func_003E2728_003DF038(s32, void *);
extern s32 func_003E28E0_003DF038(s32, s32);
extern s32 func_003E30C8_003DF038(s32, s32);
extern s32 func_003E2DE0_003DF038(s32, s32);
extern void func_003E1AA0_003DF038(s32, s32);
extern void func_003DE8F0_003DF038(void);
extern S_3DF038 *func_003E16B8_003DF038(S_3DF038 *);
extern s32 func_003E1898_003DF038(S_3DF038 *);
extern W_3DF038 *func_003E0E28_003DF038(s32, s32);

void func_003DF038(s32 arg0) {
    S_3DF038 *p;
    S_3DF038 *q;
    W_3DF038 *t;
    W_3DF038 *v;

    D_001D9594_003DF038 = 1;
    func_003E1E48_003DF038(1);
    func_00388440_003DF038(D_001DA868_003DF038, 0, 8);
    func_003AFAA8_003DF038(0x90000);
    func_003DFB40_003DF038(0x90001);
    func_003DFB40_003DF038(0x90002);
    func_003DFCA8_003DF038(0x90003);
    func_003DFCA8_003DF038(0x90004);
    func_003DFCA8_003DF038(0x90005);
    func_003DFE10_003DF038(0x90006);
    func_003DFCA8_003DF038(0x90007);
    func_003E3A80_003DF038(0x9000C, func_0037DF98_003DF038(0x182D), 0x8066CCFF, 0.4285f, 0.1315f, 0.6f, 0.6f);
    func_003E2560_003DF038(0x9000C, 1);
    func_003E3BD0_003DF038(0x90008, 0x706EC8FF, 0, 0.598917f, 0.074f, 0.043083f, 0.050416f);
    func_003E23C0_003DF038(0x90008, 1, 3);
    func_003E2A90_003DF038(0x90008, 0x601465B7, 0x6066CCFF, 0x601465B7, 0x6066CCFF);
    func_003E2B98_003DF038(0x90002, func_0038E1E0_003DF038(), 0x8C);
    func_003E2B98_003DF038(0x90001, func_0038E1E0_003DF038(), 0x8D);
    func_003E1E50_003DF038(0x90003, 0.487997f, 0.074f);
    func_003E1E50_003DF038(0x90004, 0.440497f, 0.074f);
    func_003E1E50_003DF038(0x90005, 0.39347f, 0.074f);
    func_003E1E50_003DF038(0x90006, 0.627999f, 0.069f);
    func_003E2028_003DF038(0x90006, 0.003f, 0.003f);
    func_003E29B8_003DF038(0x90006, 1);
    func_003E1E50_003DF038(0x90007, 0.464136f, 0.1335f);
    func_003E2C88_003DF038(0x90003, 0.035f, 0.035f);
    func_003E2C88_003DF038(0x90004, 0.035f, 0.035f);
    func_003E2C88_003DF038(0x90005, 0.035f, 0.035f);
    func_003E2C88_003DF038(0x90006, 1.0f, 1.0f);
    func_003E2C88_003DF038(0x90007, 0.0f, 0.008f);
    func_003E2808_003DF038(0x90001, 0x331465B7);
    func_003E2808_003DF038(0x90002, 0x332299DE);
    func_003E2808_003DF038(0x90003, 0x8066CCFF);
    func_003E2808_003DF038(0x90004, 0x8066CCFF);
    func_003E2808_003DF038(0x90005, 0x8066CCFF);
    func_003E2808_003DF038(0x90006, 0x8066CCFF);
    func_003E2808_003DF038(0x90007, 0x706EC8FF);
    func_003E2728_003DF038(0x90006, D_001DA868_003DF038);
    func_003E23C0_003DF038(0x90006, 1, 1);
    func_003E23C0_003DF038(0x90007, 1, 3);
    func_003E22D0_003DF038(0x90006, 0x40, 1);
    func_003E22D0_003DF038(0x90003, 0x40, 1);
    func_003E22D0_003DF038(0x90004, 0x40, 1);
    func_003E22D0_003DF038(0x90005, 0x40, 1);
    func_003E23C0_003DF038(0x90003, 1, 3);
    func_003E23C0_003DF038(0x90004, 1, 3);
    func_003E23C0_003DF038(0x90005, 1, 3);

    func_003E28E0_003DF038(0x90003, 0xED1C);
    p = D_001DA9B8_003DF038;
    if (p->x4) q = p; else q = func_003E16B8_003DF038(p);
    t = func_003E0E28_003DF038(func_003E1898_003DF038(q), 0x90003);
    v = (t != 0 && t->vt->isA(t, D_001D97A0_003DF038) != 0) ? t : 0;
    v->x4A = 0;

    func_003E28E0_003DF038(0x90004, 0xED1D);
    p = D_001DA9B8_003DF038;
    if (p->x4) q = p; else q = func_003E16B8_003DF038(p);
    t = func_003E0E28_003DF038(func_003E1898_003DF038(q), 0x90004);
    v = (t != 0 && t->vt->isA(t, D_001D97A0_003DF038) != 0) ? t : 0;
    v->x4A = 0;

    func_003E28E0_003DF038(0x90005, 0xED1E);
    p = D_001DA9B8_003DF038;
    if (p->x4) q = p; else q = func_003E16B8_003DF038(p);
    t = func_003E0E28_003DF038(func_003E1898_003DF038(q), 0x90005);
    v = (t != 0 && t->vt->isA(t, D_001D97A0_003DF038) != 0) ? t : 0;
    v->x4A = 0;

    func_003E3BD0_003DF038(0x9000A, 0x59000000, 0, 0.61558104f, 0.0739995f, 0.230333f, 0.049333f);
    func_003E23C0_003DF038(0x9000A, 2, 3);
    func_003E3BD0_003DF038(0x9000B, 0x59000000, 0, 0.385248f, 0.0739995f, 0.230333f, 0.049333f);
    func_003E23C0_003DF038(0x9000B, 1, 3);
    func_003E2A90_003DF038(0x9000B, 0x601465B7, 0x6066CCFF, 0x601465B7, 0x6066CCFF);
    func_003E30C8_003DF038(0x90000, 0x90001);
    func_003E30C8_003DF038(0x90000, 0x90002);
    func_003E30C8_003DF038(0x90000, 0x9000A);
    func_003E30C8_003DF038(0x90000, 0x9000B);
    func_003E30C8_003DF038(0x90000, 0x90006);
    func_003E30C8_003DF038(0x90000, 0x90007);
    func_003E30C8_003DF038(0x90000, 0x90008);
    func_003E30C8_003DF038(0x90000, 0x90003);
    func_003E30C8_003DF038(0x90000, 0x90004);
    func_003E30C8_003DF038(0x90000, 0x90005);
    func_003E30C8_003DF038(0x90000, 0x9000C);
    func_003E2DE0_003DF038(7, 0x90000);
    func_003E1AA0_003DF038(arg0, 1);
    func_003DE8F0_003DF038();
    func_003E1E48_003DF038(0);
    D_001D959D_003DF038 = 0;
    D_001D959C_003DF038 = 1;
}
/* localdecomp:end func_003DF038 */

/* localdecomp:start func_003DF7C0 */
extern u8 D_001D9594;
extern u8 D_001D95A6;
extern s32 D_001D9590;
extern s32 func_003E22D0(s32, s32, s32);
extern s32 func_003DF9E0(s32);
extern void func_003DF958();
void func_003DF7C0(s32 a) {
    if (D_001D9594 != 0 && D_001D95A6 == 0) {
        D_001D9590 = a;
        func_003E22D0(0x90000, 1, a != 0);
        func_003DF958(func_003DF9E0(0));
    }
}
/* localdecomp:end func_003DF7C0 */

LINKER_REMNANT("asm/remnants", func_003DF810);

INCLUDE_ASM("asm/nonmatchings/text", func_003DF820);

/* localdecomp:start func_003DF958 */
extern s32 D_001D9590;
extern u8 D_001D95A6;
extern void func_003DF820(s32);
extern void func_003DE8F0(void);
extern void func_003DEEF0(void);
extern void func_003DEFB8(void);
extern s32 func_003E22D0(s32, s32, s32);
void func_003DF958(void) {
    if (D_001D9590 != 0 && D_001D95A6 == 0) {
        D_001D9590--;
        func_003DF820(0x90000);
        func_003DE8F0();
        func_003DEEF0();
        func_003DEFB8();
    } else {
        func_003E22D0(0x90000, 1, 0);
    }
}
/* localdecomp:end func_003DF958 */

/* localdecomp:start func_003DF9C0 */
extern u8 D_001D9594;
extern s32 func_003E3040();
void func_003DF9C0(void) {
    D_001D9594 = 0;
    func_003E3040(7);
}
/* localdecomp:end func_003DF9C0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003DF9E0);

/* localdecomp:start func_003DFB20 */
void func_003DFB20(f32 *p, f32 a) {
    *p = (a < *p) ? a : *p;
}
/* localdecomp:end func_003DFB20 */

INCLUDE_ASM("asm/nonmatchings/text", func_003DFB40);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFCA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003DFE10);

LINKER_REMNANT("asm/remnants", func_003DFF78);

/* localdecomp:start func_003DFF90 */
extern u8 D_001D95C0;
extern s32 D_001D95B8;
extern s32 func_003E22D0(s32, s32, s32);
void func_003DFF90(s32 a) {
    if (D_001D95C0 != 0) {
        D_001D95B8 = a;
        func_003E22D0(0x10000, 1, a != 0);
    }
}
/* localdecomp:end func_003DFF90 */

LINKER_REMNANT("asm/remnants", func_003DFFC0);

/* localdecomp:start func_003DFFD0 */
extern u8 D_001A71C4_003DFFD0[];
extern s32 D_001D5B90_003DFFD0;
extern s32 D_001D5B94_003DFFD0;
extern s32 D_001D9C88_003DFFD0;
extern s32 D_001D9C8C_003DFFD0;
extern s32 D_001D9C90_003DFFD0;
extern s32 D_001D9C94_003DFFD0;
extern s32 D_001D9CB8_003DFFD0;
extern s32 D_001D9CC0_003DFFD0;
extern s16 D_001D9F34;
extern s16 D_001D9F36;
extern s16 D_001D9F38;
extern s16 D_001D9F3A;
extern s16 D_001D9F3C;

void func_003DFFD0(void) {
    D_001D9C88_003DFFD0 = 0;
    D_001D9C90_003DFFD0 = 0;
    D_001D9C94_003DFFD0 = 0;
    D_001D9C8C_003DFFD0 = 0;
    D_001D9CB8_003DFFD0 = 0;
    D_001D9CC0_003DFFD0 = 0;
    if ((D_001A71C4_003DFFD0[0] == 1) && !((*(s32 *)((u8 *)(*(void **)0x1D52FC) + 0x1A0)) & 0x10) && (D_001D5B94_003DFFD0 != 4) && (D_001D5B90_003DFFD0 != 4)) {
        D_001D9F34 = 0;
        D_001D9F36 = 0;
        D_001D9F38 = 0;
        D_001D9F3A = 0;
        D_001D9F3C = 0;
    }
}
/* localdecomp:end func_003DFFD0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E0068);
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_003E0178);
