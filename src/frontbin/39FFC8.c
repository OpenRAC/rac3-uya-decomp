#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
typedef struct {
    u8 pad[0x84];
    s32 f84;
} Struct227600;
extern void func_003A30E0(void);
extern void func_003A3B00(void);
extern void func_003A44F0(void);
extern s32 func_0039EE68(void);
extern void func_003A3EF0(s32, unsigned long);
extern void func_003A35C0(void);
extern void func_003A2460(void);
extern void (*D_001D9AC0[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void func_003886E8(f32 *, void *, f32);
extern void func_003A4188(void);
extern void func_003A4128(void);
extern void func_003A40C8();
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003A3DE8(s32, u32);
extern void func_003A41F0(void);
extern void func_003A3FB0(s32, s32, s32, s32);
extern void func_003A0010(void);
extern s32 func_003A3128();
extern void func_003A3508(void);
extern void func_003A3368();
/* --- end of declarations from other files --- */

/* localdecomp:start func_0039FFC8 */
extern u8 D_001A30B0[];
s32 func_0039FFC8(u32 a0, s32 a1) {
    if (a0 < 0x34) {
        u8 *p = (u8 *)&D_001A30B0[0] + a0 * 0x80;
        *(u16 *)(p + 0xcc) = a1;
    }
    return 1;
}
/* localdecomp:end func_0039FFC8 */

LINKER_REMNANT("asm/remnants", func_0039FFF0);

/* localdecomp:start func_003A0010 */
/* sq $zero has no C form (the compiler always emits por+sq from a zero); this is the inline-asm macro the original used */
#define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
extern s32 D_001D6E1C;
extern u8 D_1A3100[];
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_13C170(void);
extern s32 func_12C908(s32);
extern void func_003A0200(void);
void func_003A0010(void) {
    s32 c;
    s32 i;
    u8 *p;
    func_13CA28();
    func_13B620();
    func_13C170();
    D_001D6E1C = 0xB4;
    while (func_13B620() != 0) {
        func_12C908(0);
        c = D_001D6E1C;
        if (c == 0) break;
        D_001D6E1C = c - 1;
    }
    for (i = 3; i >= 0; i--) {
        QZERO(D_1A3100 + i * 0x10);
    }
    p = D_001A30B0;
    *(s32 *)(p + 0x48) = 0;
    for (i = 0x33; i >= 0; i--) {
        *(s32 *)(p + 0xC0) = 0;
        *(u8 *)(p + 0xD0) = 0;
        p += 0x80;
    }
    func_003A0200();
}
/* localdecomp:end func_003A0010 */

/* localdecomp:start func_003A00D0 */
void func_003A00D0(s32 a0, long a1) {
    s32 *p = (s32 *)(u32)a1;
    if (p != 0) {
        *p = a0;
    }
}
/* localdecomp:end func_003A00D0 */

/* localdecomp:start func_003A00E8 */
void func_003A00E8(s32 a0, long a1) {
    u8 *p = (u8 *)(s32)a1;
    if (p != 0) {
        *(s32 *)p = a0;
        if (a0 != 0) {
            if (p[0x10] == 1) {
                p[0x10] = 2;
            }
        } else {
    *(s32 *)(p + 0x1C) = 0;
    *(s32 *)(p + 0x40) = 0;
    p[0x10] = 0;
        }
    }
}
/* localdecomp:end func_003A00E8 */

/* localdecomp:start func_003A0130 */
void func_003A0130(s32 a, long l) {
    u8 *p = (u8 *)(u32)l;
    if (p == 0) return;
    if (p[0x13] != *(s32 *)(p + 0x4C)) return;
    *(s32 *)p = a;
    if (a == 0) {
        *(s32 *)(p + 0x1C) = 0;
        *(s32 *)(p + 0x40) = 0;
        p[0x10] = 0;
    }
    p[0x13] = 0;
}
/* localdecomp:end func_003A0130 */

LINKER_REMNANT("asm/remnants", func_003A0170);

/* localdecomp:start func_003A0178 */
void func_003A0178(u8 *p, s32 i, s32 *v) {
    switch (i) {
    case 3:
        *(s32 *)(p + 0xC) = *v;
        break;
    case 0:
        *(u128_t *)(p + 0x40) = *(u128_t *)v;
        break;
    case 1:
        *(u128_t *)(p + 0x50) = *(u128_t *)v;
        break;
    case 2:
        *(f32 *)(p + 8) = *(f32 *)v;
        break;
    case 4:
        *(s32 *)(p + 0x10) = *v;
        break;
    case 5:
        *(s32 **)(p + 0x14) = v;
        break;
    case 6:
        *(s32 *)(p + 0x18) = *v;
        break;
    }
}
/* localdecomp:end func_003A0178 */

LINKER_REMNANT("asm/remnants", func_003A01F8);

/* localdecomp:start func_003A0200 */
typedef struct { u8 x0; s8 x1; s8 x2; s8 x3; u16 x4; u16 x6; s32 x8; s32 xC; u32 x10; s32 x14; s32 x18; u8 pad[0x60-0x1C]; } S_3A0200;
extern S_3A0200 D_002294B0[];
void func_003A0200(void) {
    s32 i;
    for (i = 0; i < 12; i++) {
        S_3A0200 *p = &D_002294B0[i];
        p->x0 = 0;
        p->x1 = -1;
        p->x2 = -1;
        p->x3 = -1;
        p->xC = 0;
        p->x8 = 0;
        p->x4 = 0xFFFF;
        p->x10 = 0xFFFFFFFF;
        p->x14 = 0;
        p->x18 = -1;
    }
}
/* localdecomp:end func_003A0200 */

LINKER_REMNANT("asm/remnants", func_003A0268);

/* localdecomp:start func_003A0280 */
extern s32 D_00229930[];
extern void func_003BD360(s32 p);
void func_003A0280(void) {
    s32 *p = D_00229930;
    s32 i;
    for (i = 19; i >= 0; i--) {
        if (*p) func_003BD360(*p);
        *p = 0;
        p++;
    }
}
/* localdecomp:end func_003A0280 */

/* localdecomp:start func_003A02D8 */
typedef struct O2_3A02D8 { u8 pad[8]; void *f8; } O2_3A02D8;
typedef struct { u8 pad[0x30]; u8 f30; u8 pad31; s16 f32; u16 f34; u8 pad36[0x63 - 0x36]; u8 f63; u8 pad64[4]; O2_3A02D8 *f68; } O_3A02D8;
typedef struct { O_3A02D8 *f0; u8 pad[0x40]; } S_16C580_3A02D8;
extern S_16C580_3A02D8 D_0016C580_003A02D8;
extern u32 D_001D54D0;
extern s16 D_001D5BB0[4];
extern s16 D_001D5BB6;
extern s16 D_001D5BB8;
extern s16 D_001D5BBA;
extern s16 D_001D5BBC;
extern O_3A02D8 *func_003BCFB0_003A02D8(s32, s32);
extern void func_003A0280(void);
void func_003A02D8(O_3A02D8 *o) {
    s16 *k;
    O_3A02D8 **t;
    O_3A02D8 *p;
    s32 i;
    if (o == 0) o = D_0016C580_003A02D8.f0;
    func_003A0280();
    o->f30 = 0xFF;
    t = (O_3A02D8 **)D_00229930;
    k = &D_001D5BB0[(D_001D54D0 >> 2) & 3];
    t[0] = func_003BCFB0_003A02D8(*k, 0x80);
    t[1] = p = func_003BCFB0_003A02D8(*k, 0x80);
    p->f34 |= 0x8000;
    t[2] = func_003BCFB0_003A02D8(D_001D5BB6, 0x80);
    t[3] = func_003BCFB0_003A02D8(D_001D5BB8, 0x80);
    t[4] = p = func_003BCFB0_003A02D8(D_001D5BB8, 0x80);
    p->f34 |= 0x8000;
    t[5] = func_003BCFB0_003A02D8(D_001D5BBA, 0x80);
    t[6] = p = func_003BCFB0_003A02D8(D_001D5BBA, 0x80);
    p->f34 |= 0x8000;
    t[7] = func_003BCFB0_003A02D8(D_001D5BBC, 0x80);
    t[8] = p = func_003BCFB0_003A02D8(D_001D5BBC, 0x80);
    p->f34 |= 0x8000;
    for (i = 0; t[i] != 0; i++) {
        if (t[i]->f63 != 0) t[i]->f63 = 8;
        t[i]->f34 |= 0x124;
        t[i]->f32 = 0x1FF;
        t[i]->f68->f8 = (u8 *)t[i]->f68 + 0x30;
    }
    o->f34 |= 0x20;
    o->f68->f8 = (u8 *)o->f68 + 0x30;
}
/* localdecomp:end func_003A02D8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A04A0);

LINKER_REMNANT("asm/remnants", func_003A0D20);

/* localdecomp:start func_003A0D58 */
typedef struct { u8 p0[0x20]; s16 f20; } S_16C580_3A0D58;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0D58;
extern S_16C580_3A0D58 D_16C580_003A0D58;
extern f32 func_0037E2A8(void);
extern void func_003BF6A8(f32 *v, f32 r);
extern void func_003D3FA0_003A0D58(void *, s32, s32, s32, f32, f32, f32);
void func_003A0D58(f32 a, f32 b, u128_t *src, V4_3A0D58 *step, f32 g, s32 n, s32 c) {
    u128_t pos[1];
    u128_t tmp;
    f32 inv;
    f32 t, r;
    s32 i;
    inv = 1.0f / n;
    pos[0] = *src;
    i = 0;
    while (i < n) {
        t = a + (b - a) * (i++ * inv);
        r = func_0037E2A8();
        tmp = pos[0];
        func_003BF6A8((f32 *)&tmp, g);
        func_003D3FA0_003A0D58(&tmp, (D_16C580_003A0D58.f20 == 2) ? 5 : 0x2E, c, 1, t, 0.0f, r);
        {
            u128_t x, y;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos[0]));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*step));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(pos[0]) : "j"(x));
        }
    }
}
/* localdecomp:end func_003A0D58 */

/* localdecomp:start func_003A0EB0 */
/* Float constants are written as the exact decimal of retail's values, some of which are truncated (0.0749999955f is 0x3D999999). */
typedef struct { f32 x, y, z, w; } V_3A0EB0;
typedef struct { f32 x, y, z, w; } E_3A0EB0;
typedef struct {
    V_3A0EB0 v;
    u128_t q10;
    f32 f20; f32 f24; f32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; s32 f44; s32 f48; s32 f4C;
} T_3A0EB0;
extern s32 D_001D6FA0[2];
__asm__(".extern D_001D6FA0, 8");
extern s32 D_001DA090[2];
extern s32 D_002257B4[];
extern void func_003BD9A0();
extern void func_003888F0();
extern s32 func_003894A0(s32, s32, f32);
extern void func_003A0D58(void *, void *, s32, f32, f32, f32, s32);
extern void func_003A2EE0_003A0EB0(void *, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_0037E208(s32, s32);
extern void func_003A2E40(s32, u8 *);
void func_003A0EB0(void *op, s32 idx, s32 flag) {
    u8 *o = (u8 *)op;
    f32 m0[4];
    f32 v[4];
    f32 m1[16];
    T_3A0EB0 t;
    E_3A0EB0 *e;
    f32 s;
    f32 f24, f28, f27, f25, f22, f23, f26, f21;
    s32 i20, i21, c1, c2, x;
    func_003BD9A0(o, 0, m1);
    e = &((E_3A0EB0 *)D_001D6FA0)[idx];
    func_003888F0(m0, e, m1);
    s = (f32)o[0x95] * 0.0078125f * e->w;
    f24 = s * 0.0599999987f + 0.0599999987f;
    i20 = s * 5.0f + 25.0f;
    f25 = s * 0.0399999991f + 0.0399999991f;
    f22 = s * 0.375f + 0.375f;
    f27 = s * 0.0249999911f + 0.174999997f;
    i21 = s * 5.0f + 15.0f;
    f28 = s * 0.0f + 0.0749999955f;
    f23 = s * 0.099999994f + 0.099999994f;
    f26 = s * 0.0249999985f + 0.0249999985f;
    f21 = s * 0.0749999955f + 0.0749999955f;
    c1 = func_003894A0(0x40204080, 0x40205080, s);
    c2 = func_003894A0(-1, -1, s);
    if (flag == 0 && (s8)o[0x95] >= 0) {
        c1 = (c1 & 0xFFFFFF) | ((((c1 >> 24) * o[0x95]) >> 7) << 24);
        c2 = (c2 & 0xFFFFFF) | ((((c2 >> 24) * o[0x95]) >> 7) << 24);
    }
    func_003886E8(v, m1, -f24);
    func_003A0D58(m0, v, i20, f22, f23, f21, c1);
    if (idx == 0) {
        func_003886E8(v, m1, -f25);
        func_003A0D58(m0, v, i21, f27, f26, f28, c2);
    }
    func_003A2EE0_003A0EB0(o, 0x3F3F3F);
    x = func_003894A0(0x2F7F, 0x7F7F, func_0037E250(0.0f, 1.0f));
    *(u128_t *)&t.v = *(u128_t *)m0;
    t.f2C = x;
    t.f30 = x;
    t.v.x += func_0037E250(-0.025f, 0.025f);
    t.v.y += func_0037E250(-0.025f, 0.025f);
    t.v.z += func_0037E250(-0.025f, 0.025f);
    t.q10 = *(u128_t *)D_001DA090;
    *(f32 *)&t.f24 = func_0037E2A8();
    t.f20 = func_0037E250(90.0f, 180.0f) * 0.017453292f * 0.016666668f;
    t.f4C = 5;
    t.f3C = 1;
    if (flag != 0) {
        t.f38 = t.f34 = func_0037E208(0x28, 0x38);
        t.f40 = t.f44 = func_0037E208(0x32, 0x3C);
        t.f28 = func_0037E250(0.8f, 1.5f);
        if (o[0x95] >= 0x41) func_003A2E40((s32)o, (u8 *)&t);
    } else {
        t.f38 = t.f34 = func_0037E208(0x1F, 0x3F);
        t.f40 = t.f44 = func_0037E208(0x46, 0x5A);
        t.f28 = func_0037E250(1.0f, 2.0f);
        t.f3C |= ((D_002257B4[0] & 1) + 1) << 1;
        func_003A2E40((s32)o, (u8 *)&t);
    }
}
/* localdecomp:end func_003A0EB0 */

/* localdecomp:start func_003A1340 */
extern void func_003A0EB0(void *, s32, s32);
void func_003A1340(void *p) {
    func_003A0EB0(p, 1, 0);
    func_003A0EB0(p, 2, 0);
}
/* localdecomp:end func_003A1340 */

LINKER_REMNANT("asm/remnants", func_003A1380);

/* localdecomp:start func_003A13B0 */
typedef struct { u8 pad[0x30]; s32 f30; u8 pad2[0x38]; s32 f6C; } S_225780;
typedef struct { s32 v[0x53]; } E_160C40;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad2[0xB0]; E_160C40 e[1]; } S_160C40;
extern S_225780 D_00225780_003A13B0;
extern S_160C40 D_160C40;
extern s32 func_0039D510(s32, s32, s32);
extern s32 func_0039D6C8(s32);
s32 func_003A13B0(s32 a) {
    s32 idx = D_00225780_003A13B0.f30;
    s32 h = D_00225780_003A13B0.f6C;
    s32 lo = D_160C40.e[idx].v[a];
    s32 d = D_160C40.e[idx].v[a + 1] - lo;
    if (d > 0) {
        func_0039D510(h, lo + D_160C40.f1284, d);
        func_0039D6C8(0);
    }
    return 1;
}
/* localdecomp:end func_003A13B0 */

/* localdecomp:start func_003A1438 */
/* VU0 j-form: each VU0 instruction is a separate non-volatile __asm__
   using the "j" (VU0 register) constraint, which needs -mvu0-use-vf0-vf2 (on every line of
   tools/text_parts.txt). With -mvu0-use-vf0-vf31 loop.c hoists and strength-reduces differently
   (234 diffs). Uses one plain-C volatile read of D.f34. See Matching-Patterns,
   "VU0 j-form". */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A1438;
typedef struct {
    u8 pad[0x10]; V4_3A1438 f10; u8 pad20[0x40 - 0x20]; u8 f40; u8 f41; u8 pad42[2]; f32 f44;
    u8 pad48[0x61 - 0x48]; u8 f61; u8 pad62; u8 f63; u8 pad64[4]; u8 *f68; u8 pad6C[0xAA - 0x6C]; s16 fAA;
} O_3A1438;
typedef struct { u8 pad[0x20]; u8 f20; u8 pad21[0x34 - 0x21]; u16 f34; u8 pad36[0xAA - 0x36]; s16 fAA; u8 padAC[0x100 - 0xAC]; } E_3A1438;
typedef struct {
    u8 pad[0x34]; s32 f34; s32 f38; s32 f3C; s16 f40; u8 pad42[2]; s16 f44; u8 pad46[2]; s16 f48;
    u8 pad4A[0x60 - 0x4A]; s8 f60; u8 pad61[0x1A0 - 0x61]; O_3A1438 *f1A0[1];
} S_225780_3A1438;
typedef struct { u8 pad[0x1A0]; unsigned long f1A0; } Pad_3A1438;
typedef struct { u8 pad[0x25C0]; O_3A1438 *f25C0; } S_1A4BE0_3A1438;
extern S_225780_3A1438 D_00225780_003A1438;
extern S_1A4BE0_3A1438 D_001A4BE0_003A1438;
extern f32 D_001D9C50_003A1438;
extern s32 D_001D5B90_003A1438;
extern Pad_3A1438 *D_001D52FC_003A1438;
extern s32 D_00142690_003A1438[];
extern s32 D_001D4D40_003A1438;
extern s32 D_001D545C_003A1438;
extern s32 D_00143950_003A1438[];
extern s16 D_001CCFD4_003A1438[];
extern O_3A1438 *D_001DA088;
extern s32 D_001D4B60_003A1438;
extern E_3A1438 *D_001DA51C_003A1438;
extern E_3A1438 *D_001DA524_003A1438;
extern void func_003DFFD0(void);
extern void func_003A2C18(void);
extern s32 func_0039C710(void);
extern s32 func_003E0190(void);
extern void func_003BD490_003A1438(O_3A1438 *);
extern void func_003886E8_003A1438(void *, void *, f32);
extern void func_003A04A0(O_3A1438 *, s32);
extern void func_003A26D0();
extern void func_00385840_003A1438(void (*)(), O_3A1438 *);
extern void func_003C26C8_003A1438(O_3A1438 *);
extern void func_0037DD10(O_3A1438 *, s32);
extern void func_0037DC38(O_3A1438 *);
extern s32 func_0037DC58_003A1438(void);
extern void func_003CB5B0(void);
extern void func_003A1870(void);
extern s32 func_003A13B0(s32);
extern s32 func_0039D6C8(s32);
extern void func_003E0068(void);
s32 func_003A1438(void) {
    s32 r;
    s32 over;
    f32 f;
    if (D_00225780_003A1438.f60 != 0) return 0;
    if (!(D_00225780_003A1438.f34 + 1 < D_00225780_003A1438.f40)) {
        D_001D5B90_003A1438 = 0;
        D_00225780_003A1438.f60 = 1;
        return 0;
    }
    func_003DFFD0();
    func_003A2C18();
    f = D_001D9C50_003A1438 - 0.34f;
    D_00225780_003A1438.f38++;
    D_00225780_003A1438.f34++;
    D_001D9C50_003A1438 = f;
    if (f < 0.0f) D_001D9C50_003A1438 = 0.0f;
    if (!(*(volatile s32 *)&D_00225780_003A1438.f34 < D_00225780_003A1438.f48)) func_0039C710();
    r = 0;
    over = !(D_00225780_003A1438.f34 < D_00225780_003A1438.f40);
    if (D_00225780_003A1438.f34 >= 0x12 && D_001D9C50_003A1438 == 0.0f) {
        if (((D_00142690_003A1438[0] & 0xFFFF0000) != 0 || D_001D4D40_003A1438 != 0 || D_001D545C_003A1438 <= 0)
            && (((s32 *)D_001D52FC_003A1438)[0x1A4 / 4] & 0x800)) {
            r = 1;
        } else {
            r = 1;
            if ((D_001D52FC_003A1438->f1A0 & 0x8000000000FUL) ^ 0x8000000000FUL) r = 0;
        }
    }
    if (r != 0 || over) {
        D_00225780_003A1438.f60 = 1;
        D_001D5B90_003A1438 = 0;
    } else {
        s32 i;
        s32 v;
        s32 lim = D_00143950_003A1438[0] ? 0x50 : 0x60;
        if (D_00225780_003A1438.f38 >= lim) {
            D_00225780_003A1438.f3C++;
            if (D_001CCFD4_003A1438[0] != 0) func_0039D6C8(1);
            func_003A1870();
            func_003A13B0(D_00225780_003A1438.f3C + 1);
        }
        v = func_003E0190();
        for (i = 0; i < D_00225780_003A1438.f44; i++) {
            O_3A1438 *o = D_00225780_003A1438.f1A0[i];
            s32 h = D_00225780_003A1438.f38 >> 1;
            u8 *p;
            V4_3A1438 a, b;
            o->f41 = h + 1;
            o->f40 = h;
            func_003BD490_003A1438(o);
            o->f44 = (f32)(D_00225780_003A1438.f38 & 1) * 0.5f;
            if (v != 0 && (D_00225780_003A1438.f38 & 1)) o->f44 = 1.0f;
            p = o->f68;
            func_003886E8_003A1438(&a, p + o->f40 * 16, 1.0f - o->f44);
            func_003886E8_003A1438(&b, p + o->f41 * 16, o->f44);
            {
                u128_t x, y;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(o->f10) : "j"(x));
            }
            {
                s32 aa = o->fAA;
                if (aa == 0xD54) {
                    o->f63 = 8;
                    func_003A04A0(o, 0);
                    if (D_001DA088 == 0 || D_001DA088->fAA == aa) func_00385840_003A1438(func_003A26D0, o);
                }
            }
            o->f61 = 0xFF;
            func_003C26C8_003A1438(o);
            if (o->fAA == 0) {
                D_001A4BE0_003A1438.f25C0 = o;
                func_0037DD10(o, 1);
            }
            if (o->fAA == 10) func_0037DC38(o);
        }
        if (D_001D4B60_003A1438 == 4 || func_0037DC58_003A1438() > 0) {
            E_3A1438 *e;
            for (e = D_001DA51C_003A1438; e < D_001DA524_003A1438; e++) {
                if (e->f20 < 0xFE && e->fAA == 0x50A) e->f34 |= 1;
            }
        }
    }
    func_0039EE68();
    func_003CB5B0();
    func_003E0068();
    return r;
}
/* localdecomp:end func_003A1438 */

/* localdecomp:start func_003A1870 */
typedef struct { u8 pad[6]; u8 f6; u8 pad7[5]; u8 fC; u8 padD[0x48 - 0xD]; void *f48[1]; } T_3A1870;
typedef struct { u8 pad[0x10]; u8 n; u8 pad11[0xB]; s32 a[1]; } E_3A1870;
typedef struct {
    u8 pad[0x24]; T_3A1870 *f24; u8 pad28[0x32 - 0x28]; s16 f32; u16 f34; u8 pad36[2];
    long f38; u8 pad40[2]; u8 f42; u8 f43; u8 pad44[0x62 - 0x44]; u8 f62; u8 f63; u8 pad64[4];
    u8 *f68; u8 pad6C[0x98 - 0x6C]; s32 f98; u8 pad9C[0xAA - 0x9C]; s16 fAA;
} O_3A1870;
typedef struct {
    u8 pad[0x38]; s32 f38; u8 pad3C[4]; s16 f40; u8 pad42[2]; s16 f44; u8 pad46[2]; s16 f48;
    u8 pad4A[0x54 - 0x4A]; O_3A1870 *f54; u8 pad58[0x64 - 0x58]; u8 *f64; u8 *f68; s32 f6C;
    u8 pad70[0x1A0 - 0x70]; O_3A1870 *f1A0[1];
} S_225780_3A1870;
extern S_225780_3A1870 D_00225780_003A1870;
extern O_3A1870 *D_001D9C4C;
extern void func_11F0A0(s32);
extern void func_0039B760(u8 *, u32);
extern void func_003BD0D8(O_3A1870 *, s32);
extern O_3A1870 *func_003BCFB0_003A1870(s32, s32);
void func_003A1870(void) {
    s32 i;
    u8 *data;
    s32 *offs;
    u8 *e;
    u8 *q;
    s32 kind;
    O_3A1870 *o;
    s32 n;
    s32 j;
    func_11F0A0(0);
    func_0039B760((u8 *)D_00225780_003A1870.f6C, (u32)D_00225780_003A1870.f68);
    func_11F0A0(0);
    data = D_00225780_003A1870.f68;
    D_00225780_003A1870.f38 = 0;
    offs = (s32 *)(data + 0x14);
    D_00225780_003A1870.f40 = *(u16 *)(data + 0);
    D_00225780_003A1870.f48 = *(u16 *)(data + 8);
    D_00225780_003A1870.f44 = *(u16 *)(data + 0xC);
    D_00225780_003A1870.f64 = data + *(s32 *)(data + 0x10);
    for (i = 0; i < D_00225780_003A1870.f44; i++) {
        e = data + *offs++;
        kind = *(s32 *)e;
        e += 0xC;
        o = D_00225780_003A1870.f1A0[i];
        q = data + *(s32 *)e;
        e += 4;
        if (kind == 0x215) kind = 0xD54;
        if (o == 0) {
            if (kind == 0) {
                o = D_001D9C4C;
                func_003BD0D8(o, 0);
            } else {
                o = func_003BCFB0_003A1870(kind, 0x80);
            }
            o->f32 = 0x1FF;
            o->f34 |= 6;
            o->f62 = 0xFF;
            o->f38 = 0x20202000000000UL;
            o->f98 = 0;
            if (o->f24->f6 != 0) {
                if (o->fAA == 0xD54) o->f63 = 0;
                else o->f63 = 8;
            }
            n = o->f24->fC;
            o->f24->fC = n + 1;
            o->f42 = n;
            o->f43 = n;
            D_00225780_003A1870.f1A0[i] = o;
            if (o->fAA == 0xD54) D_00225780_003A1870.f54 = o;
        }
        o->f68 = q;
        o->f24->f48[o->f42] = e;
        for (j = 0; j < ((E_3A1870 *)e)->n; j++) {
            ((E_3A1870 *)e)->a[j] = (s32)(e + ((E_3A1870 *)e)->a[j]);
        }
    }
}
/* localdecomp:end func_003A1870 */

/* localdecomp:start func_003A1AA0 */
extern s32 D_001D6EF8[2];
s32 func_003A1AA0(s32 k) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (D_001D6EF8[i] == k) return i;
    }
    return -1;
}
/* localdecomp:end func_003A1AA0 */

/* localdecomp:start func_003A1AD0 */
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[4]; s32 f3C; u8 pad40[8]; s16 f48; u8 pad4A[2]; s32 f4C;
    u8 pad50[8]; s32 f58; u8 pad5C[0x68 - 0x5C]; s32 f68; s32 f6C; u8 pad70[0x1E0 - 0x70];
} S_225780_3A1AD0;
typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad10[0x14C - 0x10]; } R_3A1AD0;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad1288[0x1300 - 0x1288]; R_3A1AD0 r[1]; } S_160C40_3A1AD0;
typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_1CCFD0_3A1AD0;
typedef struct { u8 pad[6]; u8 f6; u8 pad7[9]; } S_143950_3A1AD0;
extern S_225780_3A1AD0 D_00225780_003A1AD0;
extern S_160C40_3A1AD0 D_160C40_003A1AD0;
extern S_1CCFD0_3A1AD0 D_1CCFD0_003A1AD0;
extern S_143950_3A1AD0 D_00143950_003A1AD0;
extern u32 D_142BA0[];
extern s32 D_0022766C[];
extern u8 D_1A5DC0[];
extern u8 D_001D99E0[8];
extern u8 D_001D9920[8];
extern u8 D_001E22C0[];
extern u8 D_001D9960[8];
extern u8 D_001D99A0[8];
extern f32 D_001D5BC8;
extern s32 D_001D5BCC;
extern s32 D_001D5B94;
extern s32 D_001D9C5C_003A1AD0;
extern s32 D_001D9C60_003A1AD0;
extern f32 D_001D9C50_003A1AD0[1];
extern s32 D_001D9C58_003A1AD0[1];
extern void func_00388440(void *, s32, s32);
extern s32 func_003A1AA0(s32);
extern void func_00385B60(s32);
extern s32 func_003A13B0(s32);
extern void func_003A1870(void);
extern void func_003A2BC0(void);
extern void func_0039DAE0(s32, s32);
extern s32 func_0039EE68(void);
extern s32 func_12C908(s32);
extern s32 func_0039C710(void);
__asm__(".extern D_001D9C60_003A1AD0, 4");
s32 func_003A1AD0(s32 lvl) {
    s32 slot;
    s32 b;
    s32 i;
    s32 dst;
    s32 n;
    s32 off;
    S_143950_3A1AD0 *p;
    if (lvl >= 0) { u32 *w = &D_142BA0[(u32)lvl >> 2]; *w |= 1 << (lvl & 0x1F); }
    slot = func_003A1AA0(lvl);
    if (slot < 0) return 0;
    func_00388440(D_1A5DC0, 0, 0x230);
    func_00388440(&D_00225780_003A1AD0, 0, 0x1E0);
    func_00388440(D_001D99E0, 0, 0x40);
    func_00388440(D_001D9920, 0, 0x40);
    func_00388440(D_001E22C0, 0, 0x40);
    func_00388440(D_001E22C0 + 0x40, 0, 0x40);
    func_00388440(D_001D9960, 0, 0x40);
    func_00388440(D_001D99A0, 0, 0x40);
    b = D_0022766C[0];
    D_00225780_003A1AD0.f30 = slot;
    D_00225780_003A1AD0.f68 = b - 0x82000;
    D_00225780_003A1AD0.f6C = b - 0x102000;
    D_001D5BC8 = 1.0f;
    D_001D5BCC = 0;
    D_00225780_003A1AD0.f34 = 0;
    D_00225780_003A1AD0.f3C = 0;
    D_00225780_003A1AD0.f58 = b - 0x90000;
    { s32 j; for (j = 0; j < 1; j++) { D_001D9C50_003A1AD0[j] = 1.0f; D_001D9C58_003A1AD0[j] = 0; } }
    D_001D5B94 = 2;
    D_001D9C5C_003A1AD0 = 1;
    D_001D9C60_003A1AD0 = 0x34;
    p = &D_00143950_003A1AD0;
    if (p->f6 != 0) {
        D_00225780_003A1AD0.f4C = 0;
        dst = D_00225780_003A1AD0.f58 + 0x8E000;
        n = D_160C40_003A1AD0.r[D_00225780_003A1AD0.f30].fC;
        off = D_160C40_003A1AD0.r[D_00225780_003A1AD0.f30].f8;
        if (n > 0) {
            func_0039D510(dst, off + D_160C40_003A1AD0.f1284, n);
            func_0039D6C8(1);
            D_00225780_003A1AD0.f4C = dst;
        }
    }
    if (D_1CCFD0_003A1AD0.f4 != 0) {
        func_00385B60(6);
        func_0039D6C8(1);
        func_003A13B0(0);
    } else {
        func_003A13B0(0);
        func_00385B60(6);
    }
    if (D_1CCFD0_003A1AD0.f4 != 0) func_0039D6C8(1);
    func_003A1870();
    func_003A2BC0();
    func_0039DAE0(D_00225780_003A1AD0.f30 + 4000, 0);
    while (D_1CCFD0_003A1AD0.f76 != 0 || D_1CCFD0_003A1AD0.f9E != 3 || D_1CCFD0_003A1AD0.f98 >= 7000) {
        func_0039EE68();
        func_12C908(0);
    }
    D_00225780_003A1AD0.f48 = -3;
    func_0039C710();
    func_003A13B0(1);
    for (i = 0; D_00225780_003A1AD0.f48 < i; i--) func_12C908(0);
    return 1;
}
/* localdecomp:end func_003A1AD0 */

/* localdecomp:start func_003A1E48 */
typedef struct { u8 p0[0x24]; s32 f24; u8 p28[0x44]; s32 f6C; u8 p70[6]; u16 f76; u8 p78[0x1C]; s32 f94; u8 p98[6]; u16 f9E; } S_3A1E48a;
typedef struct { u8 p0[0xC]; u8 bC; u8 pD[0x3B]; s32 f48[1]; } S_3A1E48c;
typedef struct { u8 p0[0x24]; S_3A1E48c *f24; } S_3A1E48d;
typedef struct { u8 p0[0x44]; s16 n44; u8 p46[0x15A]; S_3A1E48d *e[1]; } S_3A1E48b;
typedef struct { u8 p0[0x34]; u16 h34; } S_3A1E48e;
extern S_3A1E48a D_001CCFD0_003A1E48;
extern u8 D_00225980_003A1E48[];
extern S_3A1E48b D_00225780_003A1E48;
extern u8 D_001A4BE0_003A1E48[];
extern S_3A1E48e *D_001D9E58;
extern s32 D_001D9C5C;
extern s32 D_001D9C60;
extern s32 D_001D9C50[1];
extern void func_00385B60(s32);
extern s32 func_0039EE68(void);
extern s32 func_12C908(s32);
extern void func_13B620_003A1E48(void);
extern void func_003830E8();
extern void func_003BD360(s32 p);
void func_003A1E48(void) {
    s32 i;
    if ((u16)(D_001CCFD0_003A1E48.f76 - 6) >= 2) D_001CCFD0_003A1E48.f76 = 5;
    if ((u16)(D_001CCFD0_003A1E48.f9E - 6) >= 2) D_001CCFD0_003A1E48.f9E = 5;
    func_00385B60(0xC);
    while (D_001CCFD0_003A1E48.f6C != 0 || D_001CCFD0_003A1E48.f24 != -1 || D_001CCFD0_003A1E48.f94 != 0) {
        func_0039EE68();
        func_12C908(0);
    }
    while (((s32 (*)(void))func_13B620_003A1E48)() != 0) {
    }
    {
    s32 j;
    j = 0;
    D_001D9C5C = 0;
    D_001D9C60 = 0;
    for (; j >= 0; j--) D_001D9C50[j] = 0;
    }
    { u8 *q = D_00225980_003A1E48; *(f32 *)(q + 0xB0) = 0.63f; }
    func_003830E8();
    for (i = 0; i < D_00225780_003A1E48.n44; i++) {
        S_3A1E48d *p = D_00225780_003A1E48.e[i];
        if (p) {
            p->f24->bC--;
            p->f24->f48[p->f24->bC] = 0;
            func_003BD360((s32)p);
            D_00225780_003A1E48.e[i] = 0;
        }
    }
    {
        u8 *q = D_001A4BE0_003A1E48;
        if (*(s32 *)(q + 0x12A0)) {
            func_003BD360(*(s32 *)(q + 0x12A0));
            *(s32 *)(q + 0x12A0) = 0;
        }
    }
    {
        S_3A1E48e *e = *(S_3A1E48e * volatile *)&D_001D9E58;
        if (e) e->h34 &= ~1;
    }
}
/* localdecomp:end func_003A1E48 */

/* localdecomp:start func_003A2028 */
typedef struct { u8 pad[0x44]; s16 h44; u8 pad2[0x15A]; s32 tbl[1]; } S_225780_3A2028;
typedef struct { u8 pad[0x28]; s32 f28; } E_3A2028;
extern S_225780_3A2028 D_00225780_3A2028;
extern E_3A2028 *D_001DA51C_3A2028;
extern s32 D_001D5B94;
extern s32 D_001D5B90;
extern s32 D_001D9C44;
extern s32 D_001D9C48;
extern s32 D_001D9D9C;
extern void func_003A3C80();
extern void func_003A3C00();
extern void func_0038DB98();
extern void func_0038DF10();
extern void func_0038DA80();
extern void func_00397490();
extern void func_00381F18();
extern void func_003BD8A0();
extern void func_003838C0();
extern void func_0039E8E0();
extern s32 func_003A1438();
extern void func_0038DB18();
extern void func_00384420();
extern void func_003A3DA0();
extern void func_003A1E48();
s32 func_003A2028(void) {
    E_3A2028 *t;
    E_3A2028 *e;
    s32 i;
    s32 r;
    s32 s;
    if (((s32 (*)())func_003A1AD0)() == 0) return 1;
    t = D_001DA51C_3A2028;
    for (i = 0; i < D_00225780_3A2028.h44; i++) {
        do { e = (E_3A2028 *)D_00225780_3A2028.tbl[i]; } while (0);
        if (e != 0 && t != e) {
            do { e->f28 = (s32)t; t = e; } while (0);
        }
    }
    D_001D5B94 = 2;
    do {
        func_003A3C80();
        func_003A3C00();
        func_0038DB98();
        func_0038DF10(1);
        func_0038DA80();
        func_00397490();
        func_00381F18();
        func_003BD8A0();
        func_003838C0();
        D_001D9D9C = -1;
        func_0039E8E0();
        r = func_003A1438();
        func_0038DB18(0);
        D_001D9C44 = 0x131;
        func_00384420(0);
        s = D_001D5B90;
        if (s != -2) {
            D_001D5B94 = s;
            D_001D5B90 = -2;
        }
        func_003A3DA0(1);
        func_12C908(0);
        D_001D9C48 = D_001D9C48 + 1;
    } while (D_001D5B94 == 2);
    D_001D5B94 = 0;
    func_003A1E48();
    return r;
}
/* localdecomp:end func_003A2028 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A21C0);

/* localdecomp:start func_003A2460 */
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_3A2460;
typedef struct { u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C; u8 p240[0x10]; s32 f250; s32 f254; s32 f258; } S_225980_3A2460;
extern S_142430_3A2460 D_00142430_003A2460;
extern u8 D_001CCFD0_003A2460[];
extern u8 D_001A30B0[];
extern S_225980_3A2460 D_00225980_003A2460;
extern s32 D_001D9D84;
extern u32 D_001D545C;
extern s32 D_001D4B48;
extern s32 D_001D9DAC;
extern u8 D_001D9CC4, D_001D9CC5, D_001D9CC6;
extern f32 D_001D9CC8, D_001D9CCC, D_001D9CD0, D_001D9CD4;
extern u8 D_002CE180[];
extern s32 func_003B7FD8();
extern void func_00385B60(s32);
extern void func_11F0A0(s32);
extern void func_13CF80();
extern void func_13CA28(void);
extern void func_13B620_003A2460(void);
extern void func_003A0010(void);
extern void func_0039CBA0(void);
extern void func_13BF00();
extern void func_13BED0();
extern void func_0038DA28(s32, long, long);
extern void func_13D310();
extern s32 func_12C908(s32);
extern void func_00397490(void);
extern void func_00395FF0(void);
extern s32 func_003953F0();
extern void func_13CF40();
extern void func_13CDF0(s32);
extern void func_003A4580();
void func_003A2460(void) {
    s32 i;
    s32 *p;
    u8 *b;
    S_225980_3A2460 *q;
    if (func_003B7FD8() != 0) return;
    func_00385B60(6);
    D_001D4B48 = 0;
    D_001D545C = D_001D9D84;
    func_11F0A0(0);
    func_13CF80(2, 0, 0, 0, 0);
    func_13CA28();
    func_13B620_003A2460();
    func_003A0010();
    func_0039CBA0();
    b = D_001CCFD0_003A2460;
    b[7] = 1;
    { u8 *t = D_001A30B0; p = (s32 *)(t + 0x90); }
    for (i = 0; i < 6; i++) {
        if (*p) {
            func_13BF00(*p);
            func_13BED0();
            D_001D9DAC = 0;
            *p = 0;
        }
        p++;
    }
    q = &D_00225980_003A2460;
    q->f258 = 0x10;
    q->f250 = 0;
    q->f254 = 0;
    q->f228 = 0;
    q->f22C = 524288.0f;
    q->f238 = 255.0f;
    q->f23C = 128.0f;
    D_001D9CC4 = q->f250;
    D_001D9CC5 = q->f254;
    D_001D9CC6 = q->f258;
    D_001D9CC8 = q->f228;
    D_001D9CCC = q->f22C;
    D_001D9CD0 = q->f238;
    D_001D9CD4 = q->f23C;
    func_0038DA28(0, 0, 0);
    func_13D310(D_001D545C, D_002CE180);
    b = D_001CCFD0_003A2460;
    b[7] = 1;
    do {
        func_11F0A0(0);
        func_12C908(0);
        func_00397490();
        func_00395FF0();
    } while (func_003953F0() == 0);
    while (D_00142430_003A2460.f15C != 2 || D_00142430_003A2460.f164 >= 0) {
        func_11F0A0(0);
        func_12C908(0);
        func_00397490();
        func_00395FF0();
    }
    while (((s32 (*)(void))func_13B620_003A2460)() != 0) {
    }
    func_13BED0();
    func_13CF40(0);
    func_13CDF0(0);
    func_13CDF0(0);
    b = D_001CCFD0_003A2460;
    b[7] = 0;
    func_003A4580();
}
/* localdecomp:end func_003A2460 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A26D0);

/* localdecomp:start func_003A2BC0 */
typedef struct { u8 pad[0x20]; void *p20; u8 pad2[0x1C]; s32 p40; } S2_3A2BC0;
typedef struct { u8 pad[0x30]; s32 f30; u8 pad2[0x1C]; S2_3A2BC0 *f50; u8 pad3[0x14C]; s32 f1A0[4]; } B_3A2BC0;
extern B_3A2BC0 D_00225780;
extern S2_3A2BC0 D_00330BD0[];
extern s32 D_001D7000;
extern void *D_001D7080;
extern s32 D_001D7090;
void func_003A2BC0(void) {
    B_3A2BC0 *base = &D_00225780;
    s32 idx = -1;
    S2_3A2BC0 *p;
    if (base->f30 == 0) idx = 3;
    if (idx != -1) {
        p = D_00330BD0;
        base->f50 = p;
        D_001D7080 = &D_001D7000;
        p->p20 = &D_001D7090;
        p->p40 = base->f1A0[idx];
    }
}
/* localdecomp:end func_003A2BC0 */

/* localdecomp:start func_003A2C18 */
__asm__(".extern D_001D7080, 4");
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A2C18;
typedef struct { u8 pad0[0x10]; V4_3A2C18 f10; u8 pad20[0x8A]; s16 hAA; } E_3A2C18;
typedef struct { u8 pad[0x20]; V4_3A2C18 *f20; u8 pad2[0x1C]; s32 f40; } S3_3A2C18;
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[0xC]; s16 h44; u8 pad46[0xA];
    S3_3A2C18 *f50; u8 pad54[0x14C]; E_3A2C18 *tbl[4];
} B_3A2C18;
extern B_3A2C18 D_00225780_003A2C18;
extern V4_3A2C18 D_00222480_003A2C18[];
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
void func_003A2C18(void) {
    s32 lo = -1, hi = 0x270F, idx = 0;
    E_3A2C18 *r;
    s32 i, j;
    V4_3A2C18 t;
    u128_t va, vb;
    if (D_00225780_003A2C18.f30 == 0) { lo = 0xB4; hi = 0x870; idx = 3; }
    if (hi < D_00225780_003A2C18.f34) D_00225780_003A2C18.f50 = 0;
    if (D_00225780_003A2C18.f34 < lo) return;
    if (hi < D_00225780_003A2C18.f34) return;
    r = 0;
    for (i = 0; i < D_00225780_003A2C18.h44; i++) {
        E_3A2C18 *e = D_00225780_003A2C18.tbl[i];
        if (e->hAA == 0xD54) { r = e; break; }
    }
    if (r != 0) {
        for (j = 0; j < 4; j++) {
            func_003888C8(D_00225780_003A2C18.f50->f20 + j, (V4_3A2C18 *)D_001D7080 + j, (u8 *)r + 0xC0);
            __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(r->f10));
            __asm__("lqc2 %0, %1" : "=j"(va) : "m"(D_00225780_003A2C18.f50->f20[j]));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
            __asm__("sqc2 %1, %0" : "=m"(D_00225780_003A2C18.f50->f20[j]) : "j"(va));
            __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(D_00222480_003A2C18[0]));
            __asm__("lqc2 %0, %1" : "=j"(va) : "m"(D_00225780_003A2C18.f50->f20[j]));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(vb) : "j"(vb), "j"(va));
            __asm__("sqc2 %1, %0" : "=m"(t) : "j"(vb));
            func_00388830(&t, &t, 0.02f);
            __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(t));
            __asm__("lqc2 %0, %1" : "=j"(va) : "m"(D_00225780_003A2C18.f50->f20[j]));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
            __asm__("sqc2 %1, %0" : "=m"(D_00225780_003A2C18.f50->f20[j]) : "j"(va));
        }
    }
    D_00225780_003A2C18.f50->f40 = (s32)D_00225780_003A2C18.tbl[idx];
}
/* localdecomp:end func_003A2C18 */

/* localdecomp:start func_003A2DF8 */
typedef struct { u8 pad[0x48]; s32 f48; s32 f4C; } E_3A2DF8;
__asm__(".extern D_001D6EEC, 4");
__asm__(".extern D_001D6EF0, 4");
extern u8 *D_001D6EEC;
extern f32 D_001D6EF0;
extern s32 D_001DA090[2];
void func_003A2DF8(E_3A2DF8 *a0) {
    s32 i;
    f32 one;
    D_001D6EEC = (u8 *)a0;
    for (i = 0x1FF; i >= 0; i--) {
        a0[i].f48 = 0;
    }
    one = 1.0f;
    QZERO(D_001DA090);
    D_001D6EF0 = one;
}
/* localdecomp:end func_003A2DF8 */

/* localdecomp:start func_003A2E40 */
extern u8 *D_001D6EEC;
void func_003A2E40(s32 a0, u8 *src) {
    u8 *p;
    s32 i;
    if (D_001D6EEC == 0) return;
    p = D_001D6EEC;
    i = 0;
    do {
        i++;
        if (*(s32 *)(p + 0x48) == 0) {
            *(s32 *)(p + 0x38) = *(s32 *)(src + 0x38);
            *(s32 *)(p + 0x3C) = *(s32 *)(src + 0x3C);
            *(s32 *)(p + 0x30) = *(s32 *)(src + 0x30);
            *(s32 *)(p + 0x44) = *(s32 *)(src + 0x44);
            *(f32 *)(p + 0x24) = *(f32 *)(src + 0x24);
            *(f32 *)(p + 0x20) = *(f32 *)(src + 0x20);
            *(f32 *)(p + 0x28) = *(f32 *)(src + 0x28);
            *(s32 *)(p + 0x34) = *(s32 *)(src + 0x34);
            *(s32 *)(p + 0x2C) = *(s32 *)(src + 0x2C);
            *(s32 *)(p + 0x40) = *(s32 *)(src + 0x40);
            *(s32 *)(p + 0x4C) = *(s32 *)(src + 0x4C);
            *(u128_t *)(p + 0) = *(u128_t *)(src + 0);
            *(u128_t *)(p + 0x10) = *(u128_t *)(src + 0x10);
            *(s32 *)(p + 0x48) = a0;
            return;
        }
        p += 0x50;
    } while (i < 0x200);
}
/* localdecomp:end func_003A2E40 */

/* localdecomp:start func_003A2EE0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A2EE0;
typedef struct {
    V4_3A2EE0 v0; V4_3A2EE0 v10;
    f32 f20; f32 f24; f32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C;
    s32 f40; s32 f44; s32 f48; s32 f4C;
} E_3A2EE0;
__asm__(".extern D_001D6EEC, 4");
extern u8 *D_001D6EEC;
extern s32 func_003894A0(s32, s32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(f32 *, void *, f32);
extern s32 func_00388398(void *);
void func_003A2EE0(s32 id, s32 arg) {
    s32 i, off;
    if (D_001D6EEC == 0) return;
    off = 0;
    for (i = 0x1FF; i >= 0; i--) {
        E_3A2EE0 *e = (E_3A2EE0 *)(off + (s32)D_001D6EEC);
        if (e->f48 == id) {
            f32 b;
            u128_t va, vb;
            b = (f32)e->f40 / (f32)e->f44;
            e->f30 = e->f2C;
            e->f38 = (s32)((f32)e->f34 * b);
            e->f30 = func_003894A0(arg, e->f30, b * b * b);
            e->f24 = func_00389380(e->f24, e->f20);
            if (e->f3C) e->f28 += func_0037E250(0.001f, 0.003f);
            __asm__("lqc2 %0, %1" : "=j"(va) : "m"(e->v0));
            __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(e->v10));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
            __asm__("sqc2 %1, %0" : "=m"(e->v0) : "j"(va));
            func_003886E8(&e->v10.x, &e->v10, 0.99f);
            if (func_00388398(&e->f40)) e->f48 = 0;
        }
        off += 0x50;
    }
}
/* localdecomp:end func_003A2EE0 */

/* localdecomp:start func_003A3028 */
__asm__(".extern D_001D6EEC_003A3028, 4");
__asm__(".extern D_001D6EF0, 4");
typedef struct { u8 pad0[0x24]; f32 f24; f32 f28; u8 pad2C[4]; s32 f30; u8 pad34[4]; s32 f38; s32 f3C; u8 pad40[8]; s32 f48; s32 f4C; } E_3A3028;
extern E_3A3028 *D_001D6EEC_003A3028;
extern f32 D_001D6EF0;
extern void func_003D3FA0(E_3A3028 *, s32, s32, s32, f32, f32, f32);
void func_003A3028(void) {
    s32 i;
    s32 off;
    if (D_001D6EEC_003A3028) {
        off = 0;
        for (i = 0x1FF; i >= 0; i--) {
            E_3A3028 *e = (E_3A3028 *)((u8 *)D_001D6EEC_003A3028 + off);
            if (e->f48) {
                s32 s = e->f3C >> 1;
                s32 flag = 1;
                if (s) { s = s ^ 1; flag = s != 0; }
                func_003D3FA0(e, e->f4C, e->f30 | ((s32)((f32)e->f38 * D_001D6EF0) << 24), flag, e->f28, 0.001f, e->f24);
            }
            off += 0x50;
        }
    }
}
/* localdecomp:end func_003A3028 */

LINKER_REMNANT("asm/remnants", func_003A30D8);

/* localdecomp:start func_003A30E0 */
extern s32 D_001D4B00;
extern s32 D_001D4B34;
extern s32 D_001D4B30;
extern s32 D_00229FA0[];
void func_003A30E0(void) {
    s32 i;
    s32 *p = D_00229FA0;
    D_001D4B34 = 0;
    D_001D4B30 = D_001D4B00;
    for (i = 0x3F; i >= 0; i--) {
        p[0] = 0;
        p[1] = 0;
        p += 4;
    }
}
/* localdecomp:end func_003A30E0 */

/* localdecomp:start func_003A3128 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; } E_3A3128;
extern s32 D_001D4B00;
extern s32 D_001D4B04;
extern s32 D_001D4B30;
extern s32 D_001D4B34;
extern E_3A3128 D_00229FA0_3A3128[];
extern s32 func_11F1E0();
s32 func_003A3128(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 cur = D_001D4B30;
    s32 v[4];
    s32 r;
    if (D_001D4B04 - (cur - D_001D4B00) < a2 * 16) return -1;
    if (D_001D4B34 == 0x40) return -2;
    v[0] = a0;
    v[1] = cur;
    v[2] = a1 << 4;
    v[3] = 0;
    func_11F1E0(v, 1);
    r = D_001D4B34++;
    ((E_3A3128 *)((u8 *)D_00229FA0_3A3128 + r * 16))->f0 = D_001D4B30;
    D_00229FA0_3A3128[r].f4 = a2;
    D_00229FA0_3A3128[r].f8 = a3;
    *(volatile s32 *)&D_001D4B30 = D_001D4B30 + a2 * 16;
    return r;
}
/* localdecomp:end func_003A3128 */

/* localdecomp:start func_003A3220 */
extern u8 D_001D7FC0;
__asm__(".extern D_001D7FC0, 8");
s32 func_003A3220(s32 arg0) {
    s32 i;
    s32 v;
    if (arg0 >= 100) {
        for (i = 0x3B; i >= 0; i--) {
            v = *(&D_001D7FC0 + i);
            if (arg0 >= v && v != 0) {
                arg0 -= v;
                break;
            }
        }
    }
    return arg0;
}
/* localdecomp:end func_003A3220 */

/* localdecomp:start func_003A3288 */
extern s32 D_001D8000;
extern s32 D_001D8004;
extern s32 D_001D8008;
extern s32 D_001D800C;
extern s32 D_001D8010;
extern void func_00388490(s32, s32);
void func_003A3288(s32 a, s32 b, s32 c, s32 d) {
    a = (a + 63) & ~63;
    c = (c + 63) & ~63;
    D_001D8008 = c;
    D_001D800C = d;
    D_001D8000 = a;
    D_001D8004 = b;
    D_001D8010 = 0;
    func_00388490(a, b);
    func_00388490(D_001D8008, D_001D800C);
}
/* localdecomp:end func_003A3288 */

/* localdecomp:start func_003A32E0 */
extern u32 D_001D8010_003A32E0;
extern u32 D_001D8004_003A32E0;
extern s32 D_001D8000;
extern s32 D_001D8008;
u32 func_003A32E0(s32 arg0, u32 arg1) {
    s32 temp_4;
    u32 temp_2;
    u32 temp_2_2;
    u32 temp_6;
    u32 var_2;
    u32 var_3;
    temp_2 = D_001D8010_003A32E0;
    temp_6 = D_001D8004_003A32E0;
    temp_4 = (arg0 + 0x3F) & 0xFFFFFFC0;
    if (temp_2 < temp_6) {
        if (temp_6 < (u32) (temp_2 + temp_4)) {
            D_001D8010_003A32E0 = temp_6;
        }
        temp_2_2 = D_001D8010_003A32E0;
        if (temp_2_2 < temp_6) {
            goto A;
        }
    }
    var_2 = (D_001D8010_003A32E0 - D_001D8004_003A32E0) + D_001D8008;
    goto done;
A:
    var_2 = temp_2_2 + D_001D8000;
done:
    var_3 = var_2 % arg1;
    if (var_3 != 0) {
        var_3 = arg1 - var_3;
        var_2 += var_3;
    }
    D_001D8010_003A32E0 = (u32) (D_001D8010_003A32E0 + (temp_4 + var_3));
    return var_2;
}
/* localdecomp:end func_003A32E0 */

/* localdecomp:start func_003A3368 */
extern s32 func_003A3220(s32);
extern s32 D_001DA0B4;
extern u8 D_00142BA0[];
extern s32 D_00227480[];
extern u8 D_00143A07[];
extern u8 D_00160C40_003A3368[];
extern void func_0038E380(s32 *);
extern void func_003A3430(s32, s32, s32, s32, s32);
void func_003A3368(s32 arg) {
    u32 *p;
    s32 idx;
    s32 v;
    s32 d;
    s32 x;
    s32 arr;
    u8 *q;
    s32 f;
    if (arg < 0) {
        D_001DA0B4 = 0;
        return;
    }
    idx = func_003A3220(arg);
    p = (u32 *)(D_00142BA0 + (((u32)arg >> 2) << 2));
    *p |= 1 << (arg & 0x1F);
    func_0038E380(D_00227480);
    q = D_00160C40_003A3368;
    arr = (s32)q + 8;
    x = (idx * 4 + 2) << 2;
    v = *(s32 *)(x + arr);
    d = D_00143A07[0];
    if (D_00227480[0]) d = 0;
    f = idx == 0x1F;
    func_003A3430(v + *(s32 *)(q + 4), *(s32 *)(D_00160C40_003A3368 + x + 0xC), (idx << 4) + arr, d, f);
}
/* localdecomp:end func_003A3368 */

/* localdecomp:start func_003A3430 */
extern u8 D_001A30B0[];
extern s32 D_001DA0B0;
extern s32 D_001DA0B4;
extern s32 D_001DA0B8;
extern s32 D_001DA0BC;
extern s32 D_001DA0C0;
extern s32 D_001DA0C4;
extern s16 D_001CD018[];
extern void func_13CF80();
extern void func_11F0A0();
extern void func_003A0010();
extern void func_0039CBA0();
extern void func_00385B60();
extern void func_0039BD40();
void func_003A3430(s32 a, s32 b, s32 c, s32 d, s32 e) {
    D_001A30B0[0x43] |= 8;
    func_13CF80(2, 0, 0, 0, 0);
    func_11F0A0(0);
    func_003A0010();
    func_0039CBA0();
    D_001DA0B0 = a;
    D_001DA0C4 = D_001CD018[0];
    D_001DA0B4 = b;
    D_001DA0B8 = c;
    D_001DA0BC = d;
    D_001DA0C0 = e;
    func_00385B60(4);
    func_0039BD40();
}
/* localdecomp:end func_003A3430 */

/* localdecomp:start func_003A3508 */
extern s32 D_001D4D40;
extern void *D_001DA0C4_003A3508;
extern u8 D_001A30B0[];
extern void (*D_001D5BD4)(s32);
extern s32 D_002274E0[];
extern s32 D_001D5B90;
extern s32 D_001D5BD8;
extern void func_00385B60(s32);
extern void func_0039C8A8(void *, s32, s32);
extern void func_0039CC78(void);
extern void func_003A3BB8(void);
void func_003A3508(void) {
    if (D_001D4D40 == 0) { D_001D4D40 = 1; }
    func_00385B60(4);
    func_0039C8A8(D_001DA0C4_003A3508, 1, 0x400);
    func_0039CC78();
    D_001A30B0[0x43] |= 0x10;
    func_003A3BB8();
    if (D_001D5BD4 != 0 && D_002274E0[0] == 0 && D_001D5B90 != 2 && D_001D5B90 != 1) {
        D_001D5BD4(D_001D5BD8);
        D_001D5BD4 = 0;
        D_001D5BD8 = 0;
    }
}
/* localdecomp:end func_003A3508 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A35C0);

/* localdecomp:start func_003A3A00 */
extern s32 D_001425AC[];
extern s16 D_0016C5A8[];
extern s32 D_001D4D40;
extern void func_0038E5B8(s32, s32);
void func_003A3A00(void) {
    D_001D4D40 = 1;
    D_0016C5A8[0] = 1;
    D_001425AC[0] = 1;
    func_0038E5B8(1, 1);
}
/* localdecomp:end func_003A3A00 */
TEXT_PADDING(2);

/* localdecomp:start func_003A3A40 */
extern void func_00388418();
void func_003A3A40(u32 a) {
    while (*(volatile u32 *)0x10008000 & 0x100) {
        func_00388418(0x10);
    }
    *(volatile u32 *)0x10008020 = 0;
    *(volatile u32 *)0x10008030 = a & 0xFFFFFFF;
    *(volatile u32 *)0x10008000 = 0x145;
    while (*(volatile u32 *)0x10008000 & 0x100) {
        func_00388418(0x10);
    }
}
/* localdecomp:end func_003A3A40 */

/* localdecomp:start func_003A3B00 */
extern u32 D_001D545C;
extern u32 D_00330CF0[];
extern s32 D_001DA0D8;
extern s32 D_001D5BA4;
extern void func_003A3B50(void);

void func_003A3B00(void) {
    u32 index = D_001D545C;

    if (index >= 0x25) {
        index = 0;
    }
    D_001D5BA4 = 0x1E000;
    D_001DA0D8 = D_00330CF0[index];
    func_003A3B50();
}
/* localdecomp:end func_003A3B00 */

/* localdecomp:start func_003A3B50 */
extern s32 D_001DA0DC;
extern s32 D_001DA0C8[];
extern s32 D_001DA0D8;
extern s32 D_001D5BA4;
extern s32 D_001D5BA8;
extern s32 D_001D9DB0;
extern s32 D_001D9DB4;
extern s32 D_001D9DB8;
void func_003A3B50(void) {
    u32 t = (D_001DA0C8[D_001DA0DC] + D_001DA0D8) & 0xFFFFE000;
    s32 a = t - D_001D5BA4;
    D_001D9DB4 = t - D_001D5BA8;
    D_001D9DB8 = a - 0x2000;
    D_001D9DB0 = a;
}
/* localdecomp:end func_003A3B50 */

/* localdecomp:start func_003A3BB8 */
extern Struct227600 D_00227600;
extern s32 D_001DA0C8[];
extern u32 *D_001DA0D0_g;
extern s32 D_001DA0DC_g;
extern void func_003A3B50(void);
void func_003A3BB8(void) {
    u8 *p = (u8 *)&D_00227600;
    D_001DA0C8[0] = *(s32 *)(p + 0xC);
    D_001DA0C8[1] = *(s32 *)(p + 0x10);
    D_001DA0D0_g = *(u32 **)(p + 0xC);
    D_001DA0DC_g = 0;
    func_003A3B50();
}
/* localdecomp:end func_003A3BB8 */

/* localdecomp:start func_003A3C00 */
extern s32 D_001D5BA4;
extern s32 D_001D5BA8;
extern s32 D_001D9DB0;
extern s32 D_001D9DB4;
extern s32 D_001D9DB8;
extern u8 D_001DA0C8_003A3C00[];
extern s32 D_001DA0D0;
extern s32 D_001DA0D8;
extern s32 D_001DA0DC;

void func_003A3C00(void) {
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_t0;
    s32 temp_v1;

    temp_a2 = 1 - D_001DA0DC;
    temp_t0 = *(s32 *)(D_001DA0C8_003A3C00 + (temp_a2 * 4));
    temp_v1 = (temp_t0 + D_001DA0D8) & 0xFFFFE000;
    D_001DA0DC = temp_a2;
    temp_a0 = temp_v1 - D_001D5BA4;
    D_001DA0D0 = temp_t0;
    D_001D9DB4 = temp_v1 - D_001D5BA8;
    D_001D9DB8 = temp_a0 - 0x2000;
    D_001D9DB0 = temp_a0;
}
/* localdecomp:end func_003A3C00 */

/* localdecomp:start func_003A3C80 */
__asm__(".extern D_001D8014_003A3C80, 4");
__asm__(".extern D_001DA0E0_g_003A3C80, 4");
extern s32 D_001D8014_003A3C80;
extern s32 D_001DA0E0_g_003A3C80;
extern s32 D_001DA0E0_003A3C80;
extern s32 D_001DA0D8_003A3C80;
extern s32 D_001DA0DC_003A3C80;
extern s32 D_001DA0C8_003A3C80[];
extern u32 *D_001DA0D0_003A3C80;
extern s32 *func_12D650();
extern void func_12D938();
extern void func_11F0A0();
extern void func_003D4858();
extern void func_003A3C00();
extern void func_003A3DA0(s32);
void func_003A3C80(void) {
    s32 t;
    s32 flags;
    s32 lim;
    s32 c;
    s32 *r;
    t = (s32)D_001DA0D0_003A3C80 - D_001DA0C8_003A3C80[D_001DA0DC_003A3C80];
    flags = D_001D8014_003A3C80 | 0x1F;
    lim = D_001DA0E0_003A3C80;
    if (t >= lim) lim = t;
    D_001D8014_003A3C80 = flags;
    c = D_001DA0D8_003A3C80 < t;
    D_001DA0E0_g_003A3C80 = lim;
    if (c == 0 || D_001DA0DC_003A3C80 == 0) {
        D_001DA0D0_003A3C80[0] = 0x70000000;
        D_001DA0D0_003A3C80[1] = 0;
        D_001DA0D0_003A3C80[2] = 0;
        D_001DA0D0_003A3C80[3] = 0;
        r = func_12D650(1);
        *r |= 0xC0;
        func_11F0A0(0);
        func_12D938(r, D_001DA0C8_003A3C80[D_001DA0DC_003A3C80]);
        if (c != 0) {
            func_003A3DA0(1);
            func_003A3C00();
        }
    } else {
        *(volatile s32 *)&D_001D8014_003A3C80 = 0;
        func_003D4858();
    }
}
/* localdecomp:end func_003A3C80 */

/* localdecomp:start func_003A3DA0 */
extern s32 D_001D8014;
extern void func_00388418(s32);
void func_003A3DA0(s32 a) {
    while (D_001D8014 & a) {
        func_00388418(0x400);
    }
}
/* localdecomp:end func_003A3DA0 */

/* localdecomp:start func_003A3DE8 */
extern u32 *D_001DA0D0_003A3DE8;
void func_003A3DE8(s32 a0, u32 a1) {
    D_001DA0D0_003A3DE8[0] = a1 | 0x30000000;
    D_001DA0D0_003A3DE8[1] = a0;
    D_001DA0D0_003A3DE8[2] = 0;
    D_001DA0D0_003A3DE8[3] = 0;
    D_001DA0D0_003A3DE8 += 4;
}
/* localdecomp:end func_003A3DE8 */

LINKER_REMNANT("asm/remnants", func_003A3E38);

/* localdecomp:start func_003A3E40 */
extern u32 *D_001DA0D0_003A3E40;
extern void func_003885F0(u32 *, s32, s32);
void func_003A3E40(u32 a0, s32 a1, u32 a2) {
    D_001DA0D0_003A3E40[0] = a2 | 0x10000000;
    D_001DA0D0_003A3E40[1] = 0;
    D_001DA0D0_003A3E40[2] = 0x1000404;
    D_001DA0D0_003A3E40[3] = a0 | (a2 << 16) | 0x6C000000;
    D_001DA0D0_003A3E40 += 4;
    func_003885F0(D_001DA0D0_003A3E40, a1, a2 << 4);
    D_001DA0D0_003A3E40 = (u32 *)((u8 *)D_001DA0D0_003A3E40 + (a2 << 4));
}
/* localdecomp:end func_003A3E40 */

LINKER_REMNANT("asm/remnants", func_003A3EE8);

/* localdecomp:start func_003A3EF0 */
extern u32 *D_001DA0D0_003A3EF0;
void func_003A3EF0(s32 a0, unsigned long a1) {
    D_001DA0D0_003A3EF0[0] = 0x10000002;
    D_001DA0D0_003A3EF0[1] = 0;
    D_001DA0D0_003A3EF0[2] = 0;
    D_001DA0D0_003A3EF0[3] = 0x50000002;
    D_001DA0D0_003A3EF0[4] = 0x8001;
    D_001DA0D0_003A3EF0[5] = 0x10000000;
    D_001DA0D0_003A3EF0[6] = 0xE;
    D_001DA0D0_003A3EF0[7] = 0;
    *(unsigned long *)(D_001DA0D0_003A3EF0 + 8) = a1;
    D_001DA0D0_003A3EF0[10] = a0;
    D_001DA0D0_003A3EF0[11] = 0;
    D_001DA0D0_003A3EF0 += 12;
}
/* localdecomp:end func_003A3EF0 */

LINKER_REMNANT("asm/remnants", func_003A3FA8);

/* localdecomp:start func_003A3FB0 */
typedef struct { u8 pad[0x150]; s16 w; s16 h; } S_1CFEC0_3A3FB0;
extern S_1CFEC0_3A3FB0 D_001CFEC0_003A3FB0;
extern u32 *D_001DA0D0_003A3FB0;
void func_003A3FB0(s32 x0, s32 x1, s32 y0, s32 y1) {
    s32 w = D_001CFEC0_003A3FB0.w - 1;
    s32 h = D_001CFEC0_003A3FB0.h - 1;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (w < x1) x1 = w;
    if (h < y1) y1 = h;
    D_001DA0D0_003A3FB0[0] = 0x10000002;
    D_001DA0D0_003A3FB0[1] = 0;
    D_001DA0D0_003A3FB0[2] = 0;
    D_001DA0D0_003A3FB0[3] = 0x50000002;
    D_001DA0D0_003A3FB0[4] = 0x8001;
    D_001DA0D0_003A3FB0[5] = 0x10000000;
    D_001DA0D0_003A3FB0[6] = 0xE;
    D_001DA0D0_003A3FB0[7] = 0;
    *(unsigned long *)(D_001DA0D0_003A3FB0 + 8) = (unsigned long)x0 | ((unsigned long)x1 << 16) | ((unsigned long)y0 << 32) | ((unsigned long)y1 << 48);
    D_001DA0D0_003A3FB0[10] = 0x40;
    D_001DA0D0_003A3FB0[11] = 0;
    D_001DA0D0_003A3FB0 += 12;
}
/* localdecomp:end func_003A3FB0 */

/* localdecomp:start func_003A40C8 */
extern u32 *D_001DA0D0_g;
extern u8 D_001D7830[];
void func_003A40C8(void) {
    D_001DA0D0_g[0] = 0x30000003;
    D_001DA0D0_g[1] = (u32)D_001D7830;
    D_001DA0D0_g[2] = 0;
    D_001DA0D0_g[3] = 0x50000003;
    D_001DA0D0_g += 4;
}
/* localdecomp:end func_003A40C8 */

/* localdecomp:start func_003A4128 */
extern u32 *D_001DA0D0_g;
extern u8 D_001D7300[];
void func_003A4128(void) {
    D_001DA0D0_g[0] = 0x30000003;
    D_001DA0D0_g[1] = (u32)D_001D7300;
    D_001DA0D0_g[2] = 0;
    D_001DA0D0_g[3] = 0x50000003;
    D_001DA0D0_g += 4;
}
/* localdecomp:end func_003A4128 */

/* localdecomp:start func_003A4188 */
extern u32 *D_001DA0D0_g;
extern u8 D_001D7330[];
void func_003A4188(void) {
    D_001DA0D0_g[0] = 0x30000004;
    D_001DA0D0_g[1] = (u32)D_001D7330;
    D_001DA0D0_g[2] = 0;
    D_001DA0D0_g[3] = 0x50000004;
    D_001DA0D0_g += 4;
}
/* localdecomp:end func_003A4188 */

LINKER_REMNANT("asm/remnants", func_003A41E8);

/* localdecomp:start func_003A41F0 */
extern u32 *D_001DA0D0_003A41F0;
extern u8 D_00142120[];
extern u8 D_001D5330[];
extern void func_00388550();
void func_003A41F0(void) {
    D_001DA0D0_003A41F0[0] = 0x30000009;
    D_001DA0D0_003A41F0[1] = (u32)D_00142120;
    D_001DA0D0_003A41F0[2] = 0;
    D_001DA0D0_003A41F0[3] = 0x50000009;
    D_001DA0D0_003A41F0 += 4;
    D_001DA0D0_003A41F0[0] = 0x10000003;
    D_001DA0D0_003A41F0[1] = 0;
    D_001DA0D0_003A41F0[2] = 0;
    D_001DA0D0_003A41F0[3] = 0x50000003;
    D_001DA0D0_003A41F0 += 4;
    func_00388550(D_001DA0D0_003A41F0, D_001D5330, 0x30);
    D_001DA0D0_003A41F0 = (u32 *)((u8 *)D_001DA0D0_003A41F0 + 0x30);
}
/* localdecomp:end func_003A41F0 */

LINKER_REMNANT("asm/remnants", func_003A42D0);

/* localdecomp:start func_003A42E0 */
extern void func_12C9A0(s32, s16, s16, s16, s16, s16, s16, s16);
long func_003A42E0(s32 src, s32 dst, s32 w, s32 h) {
    s32 tw, th, t, t2, t3;
    s32 size, chunk, i;
    s32 p;
    __asm__("plzcw %0, %1" : "=r"(t) : "r"(w));
    tw = 0x1E - t;
    if (w & (w - 1)) tw++;
    chunk = w << 7;
    __asm__("plzcw %0, %1" : "=r"(t2) : "r"(h));
    th = 0x1E - t2;
    if (h & (h - 1)) th++;
    size = w * (h << 2);
    t3 = size - 1;
    size = (t3 + chunk) & -chunk;
    i = 0;
    while (size > 0) {
        *(s32 *)(D_001DA0D0 + 0) = 0x10000006;
        *(s32 *)(D_001DA0D0 + 4) = 0;
        *(s32 *)(D_001DA0D0 + 8) = 0;
        *(s32 *)(D_001DA0D0 + 0xC) = 0x50000006;
        size -= chunk;
        D_001DA0D0 = D_001DA0D0 + 0x10;
        func_12C9A0(D_001DA0D0, (dst + i) >> 8, w >> 6, 0, 0, 0, w, 0x20);
        p = D_001DA0D0;
        D_001DA0D0 = p + 0x60;
        *(s32 *)(p + 0x60) = (chunk >> 4) | 0x30000000;
        *(s32 *)(D_001DA0D0 + 4) = src + i;
        *(s32 *)(D_001DA0D0 + 8) = 0;
        *(s32 *)(D_001DA0D0 + 0xC) = (chunk >> 4) | 0x50000000;
        i += chunk;
        D_001DA0D0 = D_001DA0D0 + 0x10;
    }
    return (dst >> 8) | ((long)(w >> 6) << 14) | ((long)tw << 26) | ((long)th << 30) | (0x8000UL << 19);
}
/* localdecomp:end func_003A42E0 */

/* localdecomp:start func_003A44F0 */
extern s32 D_001DA0E8;
extern s32 D_001DA0EC;
extern void func_003A45F0();
extern void func_003A46F0();
extern s32 func_11EB30();
extern void func_11F9A8();
void func_003A44F0(void) {
    if (D_001DA0E8 == 0 && D_001DA0EC == 0) {
        volatile u32 *r = (volatile u32 *)0x1000E010;
        if ((*r & 0x20000) == 0) {
            *(u32 *)0x1000E010 = 0x20000;
        }
        D_001DA0E8 = func_11EB30(1, func_003A45F0, 0);
        D_001DA0EC = func_11EB30(0xF, func_003A46F0, 0);
        func_11F9A8(1);
    }
}
/* localdecomp:end func_003A44F0 */

/* localdecomp:start func_003A4580 */
extern s32 D_001DA0E8;
extern s32 D_001DA0EC;
extern void func_11EB50(s32, s32);
extern void func_11F940(s32);
void func_003A4580(void) {
    if (*(volatile u32 *)0x1000E010 & 0x20000) {
        *(volatile u32 *)0x1000E010 = 0x20000;
    }
    func_11EB50(1, D_001DA0E8);
    func_11EB50(15, D_001DA0EC);
    func_11F940(1);
    D_001DA0E8 = 0;
    D_001DA0EC = 0;
}
/* localdecomp:end func_003A4580 */

ASM_FUNC("asm/handwritten", func_003A45F0);

ASM_FUNC("asm/handwritten", func_003A46F0);

/* localdecomp:start func_003A4720 */
typedef struct { u32 a, b, c, d; } S_3A4720;
extern S_3A4720 *D_001DA0D0_003A4720;
void func_003A4720(u32 x) {
    S_3A4720 *p = D_001DA0D0_003A4720++;
    p->a = x + 0x90000000;
    p->b = 0; p->c = 0; p->d = 0;
}
/* localdecomp:end func_003A4720 */
