#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_0011A264(s32, s32, s32);
extern void func_00393460();
extern void func_0038DC08(s32, s32, s32, s32);
extern void func_0038E030(s32, s32);
extern void func_0038DA80(void);
extern void func_0038DB18(s32);
extern void func_0038DEB0(void);
extern void func_00391FD8(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/nonmatchings/text", func_003896E8);

/* localdecomp:start func_003898C0 */
s32 func_003898C0(u8 *p, s32 off, s32 *out) {
    u8 *q = p + off;
    s32 r = 0;
    s32 b = q[0];
    *out = b;
    if (b & 0x80) {
        r = 1;
        *out = (((b & 0x7F) << 8) | q[1]) + 0x7F;
    }
    return r;
}
/* localdecomp:end func_003898C0 */

LINKER_REMNANT("asm/remnants", func_00389900);

extern s32 D_001D9C48[];
/* localdecomp:start func_00389908 */
extern s32 D_001D9C48[];
extern s32 D_001D5B34;
void func_00389908(void) { D_001D5B34 = D_001D9C48[0] - 1; }
/* localdecomp:end func_00389908 */

/* localdecomp:start func_00389920 */
extern s32 D_001D55D0[];
extern s32 D_001D55D8[];
extern s32 D_001D55E0[];
extern s32 D_001D55C0;
extern s32 D_001D55C4_00389920;
extern s32 D_001D55C8;
extern u8 D_00318F90[];
extern u8 D_00319010[];
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D55E8;
__asm__(".extern D_001D55D0, 16");
__asm__(".extern D_001D55D8, 16");
__asm__(".extern D_001D55E0, 16");
__asm__(".extern D_001D55C0, 16");
__asm__(".extern D_001D55C4_00389920, 16");
__asm__(".extern D_001D55C8, 16");
__asm__(".extern D_00318F90, 16");
__asm__(".extern D_00319010, 16");
void func_00389920(s32 index) {
    register s32 offset __asm__("$2") = index << 2;
    register s32 *table0 __asm__("$7");
    register s32 *table2 __asm__("$8");
    register s32 *table1 __asm__("$3");
    register s32 *ptr1 __asm__("$2");
    register s32 offset64 __asm__("$5");
    register u8 *out1 __asm__("$3");
    register u8 *out0 __asm__("$6");
    register s32 value1 __asm__("$10");
    register s32 value0 __asm__("$9");
    register s32 value2 __asm__("$2");
    __asm__ volatile("" : "+r"(offset));
    table0 = D_001D55D0;
    __asm__ volatile("" : "+r"(table0));
    table2 = D_001D55E0;
    __asm__ volatile("" : "+r"(table2));
    table1 = D_001D55D8;
    __asm__ volatile("" : "+r"(table1));
    table0 = (s32 *)(offset + (s32)table0);
    __asm__ volatile("" : "+r"(table0));
    table2 = (s32 *)(offset + (s32)table2);
    __asm__ volatile("" : "+r"(table2));
    ptr1 = (s32 *)(offset + (s32)table1);
    __asm__ volatile("" : "+r"(ptr1));
    offset64 = index << 6;
    __asm__ volatile("" : "+r"(offset64));
    out1 = (u8 *)0x320000;
    __asm__ volatile("" : "+r"(out1));
    value1 = *ptr1;
    __asm__ volatile("" : "+r"(value1));
    out0 = (u8 *)0x320000;
    __asm__ volatile("" : "+r"(out0));
    out1 -= 0x6FF0;
    value0 = *table0;
    out1 = (u8 *)(offset64 + (s32)out1);
    __asm__ volatile("" : "+r"(out1));
    value2 = *table2;
    __asm__ volatile("" : "+r"(value2));
    out0 -= 0x7070;
    offset64 += (s32)out0;
    __asm__ volatile("" : "+r"(offset64));
    D_001D55C0 = value0;
    D_001D55C4_00389920 = value1;
    D_001D55C8 = value2;
    D_001D5B38 = (u8 *)offset64;
    D_001D5B3C = out1;
    D_001D55E8 = index;
}
/* localdecomp:end func_00389920 */

/* localdecomp:start func_00389998 */
extern s32 *D_001D55C4[];
s32 func_00389998(void) {
    s32 *p = D_001D55C4[0];
    s32 r = -1;
    if (p) r = p[-1];
    return r;
}
/* localdecomp:end func_00389998 */

INCLUDE_ASM("asm/nonmatchings/text", func_003899B8);

/* localdecomp:start func_00389B90 */
extern u8 D_001D5B42;
void func_00389B90(s32 a) { D_001D5B42 = a; }
/* localdecomp:end func_00389B90 */

INCLUDE_ASM("asm/nonmatchings/text", func_00389B98);

INCLUDE_ASM("asm/nonmatchings/text", func_00389D18);

INCLUDE_ASM("asm/nonmatchings/text", func_00389FB8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_003180C0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038A848);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_003180F0);

/* localdecomp:start func_0038B1B0 */
void func_0038B1B0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    p[4] = e;
    p[5] = f;
    p[8] = g;
    p[9] = h;
    p[6] = 0;
    p[7] = 0;
    p[10] = 0;
    p[11] = 0;
}
/* localdecomp:end func_0038B1B0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038B1E8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038BB50);

/* localdecomp:start func_0038C3C0 */
extern void func_00389D18();
f32 func_0038C3C0(s32 a, s32 unused, s32 c, f32 f) {
    f32 r = 1.0f;
    s32 t;
    if (a) t = ((s32 (*)(f32))func_00389D18)(1.0f); else t = 0;
    if (c < t) {
        r = (f32)c / (f32)t;
        if (r < f) r = f;
    }
    return r;
}
/* localdecomp:end func_0038C3C0 */

/* localdecomp:start func_0038C450 */
extern void func_003899B8(void);

void func_0038C450(void) {
    func_003899B8();
}
/* localdecomp:end func_0038C450 */

/* localdecomp:start func_0038C470 */
extern void func_00389B90();

void func_0038C470(void) {
    func_00389B90(1);
}
/* localdecomp:end func_0038C470 */

/* localdecomp:start func_0038C490 */
extern void func_00389B90();
 
void func_0038C490(void) {
    func_00389B90(0);
}
/* localdecomp:end func_0038C490 */

LINKER_REMNANT("asm/remnants", func_0038C4B0);

/* localdecomp:start func_0038C4E8 */
extern void func_00389D18();

void func_0038C4E8(void) {
    func_00389D18();
}
/* localdecomp:end func_0038C4E8 */

LINKER_REMNANT("asm/remnants", func_0038C508);

/* localdecomp:start func_0038C510 */
extern void func_00389D18();
 
void func_0038C510(void) {
    func_00389D18();
}
/* localdecomp:end func_0038C510 */

LINKER_REMNANT("asm/remnants", func_0038C530);

/* localdecomp:start func_0038C538 */
extern void func_00389D18();
 
void func_0038C538(s32 a, s32 b, s32 c, f32 d) {
    func_00389D18();
}
/* localdecomp:end func_0038C538 */

LINKER_REMNANT("asm/remnants", func_0038C558);

/* localdecomp:start func_0038C580 */
extern void func_00389FB8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
extern void func_00389D18();
s32 func_0038C580(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    ((void (*)(float, float, float, float, float, float, s32, s32, s32, s32, s32, unsigned long))func_00389FB8)((float)a0, (float)a1, 1.0f, 1.0f, 0.0f, 0.0f, a2, a3, a4, 1, 0, 0x80000000UL);
    return a0 - (((s32 (*)(s32, s32, float))func_00389D18)(a3, a4, 1.0f) >> 1);
}
/* localdecomp:end func_0038C580 */

/* localdecomp:start func_0038C628 */
extern s32 D_001D55E8;
extern void func_00389920(s32);
extern void func_00389FB8_0038C628(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
extern s32 func_00389D18_0038C628(s32, s32, f32);
s32 func_0038C628(s32 x, s32 y, s32 a, s32 b, s32 c) {
    s32 saved;
    saved = D_001D55E8;
    func_00389920(1);
    func_00389FB8_0038C628(a, b, c, 1, 0, 0x80000000UL, (f32)x, (f32)y, 1.0f, 1.0f, 0.0f, 0.0f);
    x -= func_00389D18_0038C628(b, c, 1.0f) >> 1;
    func_00389920(saved);
    return x;
}
/* localdecomp:end func_0038C628 */

LINKER_REMNANT("asm/remnants", func_0038C708);

/* localdecomp:start func_0038C718 */
extern void func_00389FB8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
void func_0038C718(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, f32 p) {
    func_00389FB8((f32)a0, (f32)a1, p, p, a2, a3, a4, 1, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_0038C718 */

/* localdecomp:start func_0038C778 */
__asm__(".extern D_001D55E8, 4");
extern s32 D_001D55E8;
extern void func_00389920(s32);
void func_0038C778(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 save;
    save = D_001D55E8;
    func_00389920(1);
    ((void (*)(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32))func_00389FB8)(c, d, e, 0, 0, 0x80000000, (f32)a, (f32)b, 1.0f, 1.0f, 0.0f, 0.0f);
    func_00389920(save);
}
/* localdecomp:end func_0038C778 */

LINKER_REMNANT("asm/remnants", func_0038C830);

/* localdecomp:start func_0038C840 */
extern void func_00389FB8(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);
void func_0038C840(s32 a0, s32 a1, s32 a2, f32 x, f32 y, f32 z) {
    func_00389FB8(x, y, z, z, a0, a1, a2, 0, 0, 0x80000000, 0.0f, 0.0f);
}
/* localdecomp:end func_0038C840 */

LINKER_REMNANT("asm/remnants", func_0038C878);

/* localdecomp:start func_0038C888 */
void func_0038C888(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    func_0038B1B0(p, a, b, c, d, e, f, g, h);
}
/* localdecomp:end func_0038C888 */

/* localdecomp:start func_0038C8A8 */
extern void func_0038B1E8(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_0038C8A8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038B1E8(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_0038C8A8 */

LINKER_REMNANT("asm/remnants", func_0038C8D8);

/* localdecomp:start func_0038C8F8 */
extern s32 D_001D55E8;
extern void func_00389920(s32);
extern void func_0038B1E8(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_0038C8F8(s32 a, s32 b, s32 c, s32 d) {
    s32 old = D_001D55E8;
    func_00389920(1);
    ((void (*)(s32, s32, s32, s32, f32, f32, unsigned long))func_0038B1E8)(a, b, c, d, 1.0f, 1.0f, 0x80000000UL);
    func_00389920(old);
}
/* localdecomp:end func_0038C8F8 */

/* localdecomp:start func_0038C980 */
extern void func_0038B1E8(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_0038C980(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g) {
    func_0038B1E8(a, b, c, d, 0x80000000, g, 1.0f, 1.0f);
}
/* localdecomp:end func_0038C980 */

LINKER_REMNANT("asm/remnants", func_0038C9B0);

/* localdecomp:start func_0038C9B8 */
extern void func_0038B1E8(s32, s32, s32, s32, unsigned long, s32, f32, f32);
void func_0038C9B8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 g, s32 h, f32 x) {
    func_0038B1E8(a, b, c, d, h, g, x, x);
}
/* localdecomp:end func_0038C9B8 */

/* localdecomp:start func_0038C9D8 */
extern void func_0038BB50();
void func_0038C9D8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s16 g, long h, s32 x, s32 y) {
    func_0038BB50(a, b, c, d, g, h, x, y);
}
/* localdecomp:end func_0038C9D8 */

/* localdecomp:start func_0038CA08 */
extern f32 func_0038C3C0(s32, s32, s32, f32);
extern void func_00389FB8_0038CA08(s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, unsigned long, f32);
void func_0038CA08(s32 x, s32 y, s32 a, s32 b, s32 c, s32 d, f32 p) {
    f32 r = func_0038C3C0(b, c, d, p);
    func_00389FB8_0038CA08(a, b, c, (f32)x, (f32)y, r, r, 0.0f, 1, 0, 0x80000000UL, 0.0f);
}
/* localdecomp:end func_0038CA08 */

/* localdecomp:start func_0038CAB0 */
extern void func_003896E8();
 
void func_0038CAB0(void) {
    func_003896E8();
}
/* localdecomp:end func_0038CAB0 */

/* localdecomp:start func_0038CAD0 */
extern f32 func_0038C3C0();
 
void func_0038CAD0(void) {
    func_0038C3C0();
}
/* localdecomp:end func_0038CAD0 */

/* localdecomp:start func_0038CAF0 */
extern s32 D_00143950[];
extern s32 D_001D5520;
extern void func_12A950(void);
extern void func_12BEE8(s32, s32, s32, s32);
void func_0038CAF0(void) {
    func_12A950();
    if (D_00143950[0]) D_001D5520 = 0;
    if (D_001D5520) func_12BEE8(0, 0, 0x50, 1);
    else func_12BEE8(0, 1, D_00143950[0] ? 3 : 2, 0);
}
/* localdecomp:end func_0038CAF0 */

/* localdecomp:start func_0038CB60 */
extern s32 D_001D4D08[];
extern s32 D_001D4D0C[];
extern s32 D_001D4D10[];
extern s32 D_001D4D14[];
extern s32 D_001D4D18[];
extern s32 D_001D4D1C[];
extern s32 D_001D4CF8[];
void func_0038CB60(void) {
    *(unsigned long *)((u8 *)D_001D4CF8[0] + 0x18) = (long)D_001D4D08[0] | ((long)D_001D4D0C[0] << 12) | ((long)D_001D4D10[0] << 23) | ((long)D_001D4D14[0] << 27) | ((long)D_001D4D18[0] << 32) | ((long)D_001D4D1C[0] << 44);
}
/* localdecomp:end func_0038CB60 */

LINKER_REMNANT("asm/remnants", func_0038CBC8);

/* localdecomp:start func_0038CBD0 */
extern s32 D_001D4D08_0038CBD0;
extern s32 D_001D4D0C_0038CBD0;
extern void func_0038CB60(void);
void func_0038CBD0(s32 dx, s32 dy, s32 clamp) {
    D_001D4D08_0038CBD0 += dx; D_001D4D0C_0038CBD0 += dy; if (clamp) { s32 x = D_001D4D08_0038CBD0 >= 0 ? D_001D4D08_0038CBD0 : 0; s32 y = D_001D4D0C_0038CBD0 >= 0 ? D_001D4D0C_0038CBD0 : 0; D_001D4D08_0038CBD0 = x <= 3000 ? x : 3000; D_001D4D0C_0038CBD0 = y <= 450 ? y : 450; }
    func_0038CB60();
}
/* localdecomp:end func_0038CBD0 */

LINKER_REMNANT("asm/remnants", func_0038CC58);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CC68);

INCLUDE_ASM("asm/nonmatchings/text", func_0038CE40);

/* localdecomp:start func_0038DA28 */
extern unsigned long D_001D07E8[];
void func_0038DA28(s32 arg0, long arg1, long arg2) {
    D_001D07E8[0] = arg0 | (arg1 << 8) | (arg2 << 0x10) | (unsigned long)0x80000000;
}
/* localdecomp:end func_0038DA28 */

LINKER_REMNANT("asm/remnants", func_0038DA50);

/* localdecomp:start func_0038DA58 */
extern void func_12C4B0(s32);
extern s32 D_001D4CF8[];

void func_0038DA58(void) {
    func_12C4B0(D_001D4CF8[0]);
}
/* localdecomp:end func_0038DA58 */

/* localdecomp:start func_0038DA80 */
extern u32 *D_001DA0D0;
extern s32 D_001D4CF8_0038DA80; 
extern void func_12C820(s32);

void func_0038DA80(void) {
    if (D_001DA0D0 != 0) {
        D_001DA0D0[0] = 0x30000009;
        D_001DA0D0[1] = (D_001D4CF8_0038DA80 + 0x30) & 0xFFFFFFF;
        D_001DA0D0[2] = 0;
        D_001DA0D0[3] = 0x50000009;
        D_001DA0D0 += 4;
    } else {
        func_12C820(D_001D4CF8_0038DA80 + 0x30);
    }
}
/* localdecomp:end func_0038DA80 */

/* localdecomp:start func_0038DB18 */
extern u32 *D_001DA0D0;
extern u8 D_1D07B0[], D_1D0900[];
void func_0038DB18(s32 a) {
    if (D_001DA0D0 != 0) {
        D_001DA0D0[0] = 0x30000015;
        if (a == 0) D_001DA0D0[1] = (u32)D_1D07B0;
        else D_001DA0D0[1] = (u32)D_1D0900;
        D_001DA0D0[2] = 0;
        D_001DA0D0[3] = 0x50000015;
        D_001DA0D0 += 4;
    }
}
/* localdecomp:end func_0038DB18 */

/* localdecomp:start func_0038DB98 */
extern u32 *D_001DA0D0;
extern s32 D_001D4CF8_0038DB98;
void func_0038DB98(void) {
    D_001DA0D0[0] = 0x30000009;
    D_001DA0D0[1] = (D_001D4CF8_0038DB98 + 0xC0) & 0xFFFFFFF;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000009;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_0038DB98 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038DC08);

/* localdecomp:start func_0038DEB0 */
extern u32 *D_001DA0D0;
extern u8 D_001D0070[];
void func_0038DEB0(void) {
    D_001DA0D0[0] = 0x30000026;
    D_001DA0D0[1] = (u32)D_001D0070;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000026;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_0038DEB0 */

/* localdecomp:start func_0038DF10 */
extern u32 *D_001DA0D0;
extern u8 D_001D7370[];
extern u8 D_001D7390[];
extern u8 D_001D02D0[];
extern u8 D_001D7300[];
void func_0038DF10(s32 a0) {
    D_001DA0D0[0] = 0x30000002;
    if (a0 != 0) {
        D_001DA0D0[1] = (u32)D_001D7370;
    } else {
        D_001DA0D0[1] = (u32)D_001D7390;
    }
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000002;
    D_001DA0D0 += 4;
    D_001DA0D0[0] = 0x30000029;
    D_001DA0D0[1] = (u32)D_001D02D0;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000029;
    D_001DA0D0 += 4;
    D_001DA0D0[0] = 0x30000003;
    D_001DA0D0[1] = (u32)D_001D7300;
    D_001DA0D0[2] = 0;
    D_001DA0D0[3] = 0x50000003;
    D_001DA0D0 += 4;
}
/* localdecomp:end func_0038DF10 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038E030);

/* localdecomp:start func_0038E1E0 */
extern s32 D_001D5C78;
s32 func_0038E1E0(void) { s32 v = D_001D5C78; if (v != 0) return v + 0x7090; return 0; }
/* localdecomp:end func_0038E1E0 */

/* localdecomp:start func_0038E200 */
void *func_0038E200(p) u8 *p; {  /* K&R: a later caller uses an unprototyped call */
    void *r;
    *(s32 *)(p + 0x58) = 0; *(s32 *)(p + 0x5C) = 0; *(s32 *)(p + 0x60) = 0;
    r = ((void *(*)(void *, s32, s32))func_0011A264)(p + 8, 0xCD, 0x50);
    p[0x6C] = 0; *(s32 *)(p + 0x68) = 1;
    return r;
}
/* localdecomp:end func_0038E200 */

/* localdecomp:start func_0038E248 */
typedef struct { s32 a, b; } E_38E;
typedef struct { u8 pad[8]; E_38E e[10]; s32 f58, f5C, f60, f64, f68; u8 f6C; } S_38E;
s32 func_0038E248(S_38E *p, s32 *a, s32 *b) {
    s32 i;
    if (p->f60 == 0) return 0;
    if (--p->f60 == 0) p->f6C = 0;
    *a = p->e[p->f5C].a;
    *b = p->e[p->f5C].b;
    p->e[p->f5C].a = -1;
    p->e[p->f5C].b = -1;
    i = p->f5C + 1;
    if (i == 10) i = 0;
    p->f5C = i;
    return 1;
}
/* localdecomp:end func_0038E248 */

/* localdecomp:start func_0038E2E8 */
s32 func_0038E2E8(S_38E *p, s32 v) {
    s32 i, n;
    if (p->f60 == 10 || p->f6C != 0) return 0;
    p->e[p->f58].a = v;
    p->e[p->f58].b = v >= 100;
    i = p->f58 + 1;
    n = p->f60 + 1;
    if (i == 10) i = 0;
    p->f60 = n;
    p->f58 = i;
    return 1;
}
/* localdecomp:end func_0038E2E8 */

/* localdecomp:start func_0038E360 */
extern void *func_0038E200();
 
void func_0038E360(s32 *p) {
    func_0038E200();
}
/* localdecomp:end func_0038E360 */

/* localdecomp:start func_0038E380 */
extern s32 func_00399F90();
typedef struct { u8 p0[8]; struct { s32 id; s32 x; } e[10]; s32 head; s32 tail; } S_E380;
extern u8 D_00142BA0[];
void func_0038E380(S_E380 *s) {
    s32 i = s->tail;
    if (i != s->head) {
        do {
            s32 v = s->e[i].id;
            if (v >= 0) {
                u32 *p = (u32 *)(D_00142BA0 + (((u32)v >> 2) << 2));
                *p |= 1 << (v & 0x1F);
            }
            i = (i + 1 != 10) ? i + 1 : 0;
        } while (i != s->head);
    }
    func_00399F90();
}
/* localdecomp:end func_0038E380 */

/* localdecomp:start func_0038E410 */
extern void func_0038E380(s32 *);
extern void func_0038E360(s32 *);
void func_0038E410(s32 *p) {
    func_0038E380(p);
    *p = 0;
    func_0038E360(p);
}
/* localdecomp:end func_0038E410 */

/* localdecomp:start func_0038E440 */
typedef struct {
    u8 pad0[0x60];
    s32 active;
    u8 flag64;
    u8 pad65[3];
    s32 mode68;
    u8 flag6C;
} Object_0038E440;

extern s32 D_001D5B94;
extern void func_0038E248(Object_0038E440 *, s32 *, s32 *);
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern void func_0038E360(s32 *);

s32 func_0038E440(Object_0038E440 *object) {
    register s32 result __asm__("$17");
    s32 values[2];
    s32 mode;

    if (object->active == 0) {
        goto inactive;
    }
    object->flag64 = 0;
    object->flag6C = 1;
    values[0] = 0;
    result = 0;
    values[1] = 0;
    func_0038E248(object, &values[0], &values[1]);

    mode = 1;
    if ((u32)(D_001D5B94 - 1) < 2) {
        mode = 2;
    }
    object->mode68 = mode;

    if (values[1] == 0) {
        result = func_0039BEC0(1, mode, 0, values[0], 0);
    } else if (values[1] == 1) {
        result = func_0039BEC0(2, mode, values[0], 0, 0);
    }
    if (result < 0) {
        func_0038E360((s32 *)object);
    }
    return result == 0;
inactive:
    return 0;
}
/* localdecomp:end func_0038E440 */

/* localdecomp:start func_0038E508 */
extern s32 func_00399F90();

void func_0038E508(s32 *input_ptr) {
    s32 *value_ptr = input_ptr;
    register u8 *page_temp __asm__("$2") = (u8 *)0x140000;
    register u8 *page __asm__("$17");
    register u8 *late_base __asm__("$3");
    register s32 output __asm__("$2");
    u8 *base;
    u8 flags;
    s32 value;

    __asm__ volatile("" : "+r"(page_temp));
    base = page_temp + 0x26E0;
    page = page_temp;
    flags = base[0x82];

    if ((flags & 1) == 0) {
        value = *value_ptr;
    } else {
        if (base[0x14] != 0) {
            value = *value_ptr;
            if (value == 3) {
                goto evaluate;
            }
            base[0x82] = flags & 0xFE;
            func_00399F90();
        }
        value = *value_ptr;
    }

evaluate:
    if (value == 0xD && *(u8 *)0x1D5587 == 0) {
        output = 0x17;
    } else {
        if (value != 3) {
            return;
        }
        late_base = page + 0x26E0;
        __asm__ volatile("" : "+r"(late_base));
        if ((late_base[0x82] & 1) == 0) {
            return;
        }
        output = 6;
    }
    *value_ptr = output;
}
/* localdecomp:end func_0038E508 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038E5B8);

LINKER_REMNANT("asm/remnants", func_0038E688);

/* localdecomp:start func_0038E6B8 */
extern u8 D_001D551C;
void func_0038E6B8(void) {
    D_001D551C = 0;
}
/* localdecomp:end func_0038E6B8 */

LINKER_REMNANT("asm/remnants", func_0038E6C0);

/* localdecomp:start func_0038E6D0 */
extern u8 D_001D5BDC;
extern s32 D_001D5C90;
extern s32 D_0022760C;
extern s32 D_001DA0D8;
__asm__(".extern D_0022760C, 16");
__asm__(".extern D_001DA0D8, 16");
s32 func_0038E6D0(u32 value, s32 *result) {
    register u32 amount __asm__("$6") = value;
    register s32 page __asm__("$2");
    register s32 base __asm__("$4");
    register s32 total __asm__("$3");
    if (amount > 0x40000) {
        *result = 0;
        return -1;
    }
    page = D_001D5BDC;
    if (page != 0) {
        page = 0x220000;
        goto calculate;
    }
    page = D_001D5C90;
    if (page != 0) {
        goto cached;
    }
    page = 0x220000;
calculate:
    base = D_001DA0D8;
    __asm__ volatile("" : "+r"(base));
    total = *(s32 *)(page + 0x760C);
    total += base;
    total -= amount;
    *result = total;
    goto done;
cached:
    *result = page;
done:
    return 0;
}
/* localdecomp:end func_0038E6D0 */

/* localdecomp:start func_0038E728 */
extern s32 D_001D5C90;
void func_0038E728(s32 a) {
    D_001D5C90 = a;
}
/* localdecomp:end func_0038E728 */

/* localdecomp:start func_0038E730 */
typedef struct LookupEntry_38E730 {
    u16 key;
    u8 reserved[6];
} LookupEntry_38E730;
extern LookupEntry_38E730 *D_001D9F24_0038E730[];
s32 func_0038E730(s32 key) {
    LookupEntry_38E730 *entry = *D_001D9F24_0038E730;
    s32 index = 0;
    if (entry->key != 0xFFFF && entry->key != key) {
        LookupEntry_38E730 *cursor = entry;
        s32 current;
        for (;;) {
            cursor++;
            current = cursor->key;
            index++;
            if (current == 0xFFFF || current == key) break;
        }
    }
    return index <= 0x3FF ? index : -1;
}
/* localdecomp:end func_0038E730 */

LINKER_REMNANT("asm/remnants", func_0038E788);

INCLUDE_ASM("asm/nonmatchings/text", func_0038E798);

LINKER_REMNANT("asm/remnants", func_0038E8F8);

/* localdecomp:start func_0038E900 */
extern u32 D_001D5D50;
u32 func_0038E900(void) {
    u32 v = D_001D5D50;
    u32 r = 0;
    if (v <= 0x1CFFFF) r = (0x1D0000 - v) >> 2;
    return r;
}
/* localdecomp:end func_0038E900 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038E930);

/* localdecomp:start func_0038EA58 */
extern s32 D_00227680[];
extern s32 D_001D9F18;
extern s32 D_001D9F1C;
void func_0038EA58(void) {
    s32 a = D_00227680[0];
    D_001D9F18 = a;
    *(volatile s32 *)&D_001D9F1C = a + 0x64000;
}
/* localdecomp:end func_0038EA58 */

/* localdecomp:start func_0038EA88 */
__asm__(".extern D_001D9F18, 16");
__asm__(".extern D_001D9F1C, 16");
s32 func_0038EA88(s32 size) {
    register s32 amount __asm__("$16") = size;
    register s32 current __asm__("$4");
    register s32 result __asm__("$2");
    if (D_001D9F18 == 0) {
        func_0038EA58();
    }
    result = D_001D9F1C;
    current = D_001D9F18;
    if (amount > result - current) {
        goto failure;
    }
    {
        register u32 mask __asm__("$3") = 0xfffffff0U;
        register s32 rounded __asm__("$5") = amount + 0xF;
        result = current;
        amount = rounded & mask;
        current += amount;
        D_001D9F18 = current;
        __asm__ volatile("" : : : "memory");
    }
    goto done;
failure:
    result = 0;
    __asm__ volatile("");
done:
    return result;
}
/* localdecomp:end func_0038EA88 */
TEXT_PADDING(2);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EB10);

/* localdecomp:start func_0038EC18 */
typedef struct S_38EC18 {
    s32 pad0;
    s32 v4, v8, vC;
    void (*f10)(struct S_38EC18 *);
    s32 v14, v18, pad1C;
    s32 a20, a24, a28, a2C;
    void (*a30)(struct S_38EC18 *);
    s32 a34, a38;
    s32 pad3C[11];
    s32 x68;
} S_38EC18;
extern void func_0038ED00();
void func_0038EC18(S_38EC18 *p) {
    func_0038ED00(p, p->a20);
    p->v4 = p->a24;
    p->v14 = p->a34;
    p->v18 = p->a38;
    p->vC = p->a2C;
    p->v8 = p->a28;
    p->f10 = p->a30;
    if (p->f10) p->f10(p);
    p->x68 = 0;
}
/* localdecomp:end func_0038EC18 */

/* localdecomp:start func_0038EC80 */
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_0032DB20[];
extern void func_0038EB10();
s32 func_0038EC80(s32 id) {
    s32 i;
    for (i = 0; i < 13; i++) {
        if (D_0032DB20[i].id == id) break;
    }
    if (i < 13) {
        func_0038EB10(i, 0xFFFF, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_0038EC80 */

/* localdecomp:start func_0038ED00 */
typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
typedef struct { s32 x0; u8 pad[0x3C]; s16 x40; u8 x42; u8 x43; s32 x44; } S_38ED00;
extern E_38ED00 *D_001D9F24[];
s32 func_0038E730(s32);
void func_0038ED00(S_38ED00 *d, s32 a) {
    s32 i = func_0038E730(a);
    if (i < 0) i = 0;
    d->x0 = D_001D9F24[0][i].x0;
    d->x40 = i;
    d->x42 = D_001D9F24[0][i].x6;
    d->x44 = D_001D9F24[0][i].x4;

}
/* localdecomp:end func_0038ED00 */

/* localdecomp:start func_0038ED78 */
void func_0038ED78(s32 id, s32 v) {
    s32 i;
    for (i = 0; i < 13; i++) {
        if (D_0032DB20[i].id == id) break;
    }
    if (i < 13) {
        D_0032DB20[i].f24 = v;
        if (!D_0032DB20[i].f68) D_0032DB20[i].f4 = v;
    }
}
/* localdecomp:end func_0038ED78 */

/* localdecomp:start func_0038EDE8 */
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
s32 func_0038EDE8(S_38EDE8 *p, s32 *x, s32 *y) {
    s32 w = p->w;
    s32 h = p->h;
    if ((p->u.c ^ 1) & 1) {
        if (!(p->u.flags & 2)) *y -= h >> 1;
    }
    if (!(p->u.flags & 4)) {
        if (p->u.flags & 8) *x -= w;
        else *x -= w >> 1;
    }
    return 0;
}
/* localdecomp:end func_0038EDE8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038EE58);

INCLUDE_ASM("asm/nonmatchings/text", func_0038EFD0);

/* localdecomp:start func_0038F0C0 */
extern void func_0038EFD0(void *);
 
void func_0038F0C0(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0xD2;
    *(s16 *)((u8 *)p + 0x48) = 0;
    *(s16 *)((u8 *)p + 0x4A) = 0;
    func_0038EFD0(p);
}
/* localdecomp:end func_0038F0C0 */

LINKER_REMNANT("asm/remnants", func_0038F0F0);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F0F8);

LINKER_REMNANT("asm/remnants", func_0038F2A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F310);

/* localdecomp:start func_0038F3A0 */
typedef struct { u8 pad[0x48]; s16 h48; s16 h4A; u8 p2[0x58-0x4C]; s32 w58; s32 w5C; u8 p3[0x70-0x60]; s32 w70; s32 w74; s32 w78; } S_38F3A0;
extern void func_0038F310(s32);
void func_0038F3A0(S_38F3A0 *p) {
    func_0038F310(0);
    p->w58 = 0xD2; p->w5C = 0xC8; p->w74 = -2; p->w78 = 30; p->h48 = 0; p->h4A = 0; p->w70 = 0;
}
/* localdecomp:end func_0038F3A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038F3F8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038FDC0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318120);

/* localdecomp:start func_003906E8 */
extern s32 D_001D9F68[];
extern s32 D_001D9F70[];
extern s32 D_001D5D38;
extern s32 D_001D5CAC;
void func_003906E8(u8 *p) {
    D_001D9F68[0] = 4;
    D_001D9F70[0] = (s32)&D_001D5D38;
    *(s32 *)(p + 0x58) = 0xD2;
    *(s32 *)(p + 0x5C) = 0xC8;
    *(s32 *)(p + 0x74) = -2;
    *(s16 *)(p + 0x48) = 0;
    *(s16 *)(p + 0x4A) = 0;
    *(s32 *)(p + 0x78) = 0x1E;
    D_001D5CAC = 0;
}
/* localdecomp:end func_003906E8 */

INCLUDE_ASM("asm/nonmatchings/text", func_00390730);

INCLUDE_ASM("asm/nonmatchings/text", func_00390C18);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318140);

LINKER_REMNANT("asm/remnants", func_003919E0);

/* localdecomp:start func_00391A18 */
typedef struct { u8 p0[8]; s32 w8; u8 pC[0x44]; s32 w50; s32 w54; s32 w58; s32 w5C; u8 p60[0xC]; s32 w6C; u8 p70[4]; s32 w74; } O_91A18;
extern s32 func_00392108();
extern void func_00392400();
extern void func_00392878();
extern void func_0038EE58();
extern s16 D_001A666A[];
s32 func_00391A18(O_91A18 *o) {
    s32 x, y, h;
    x = o->w50;
    y = o->w54;
    o->w58 = 0x100;
    o->w5C = 0x40;
    func_0038EDE8(o, &x, &y);
    func_0038EE58(o, &x, &y, o->w6C, 0);
    h = o->w74 * 0xDD / o->w8 + 0x1B;
    func_00392878(func_00392108(0x7558, 1), x, y, h, 0x40, 0x80);
    func_00392400(func_00392108(0x7558, 0), x, y, 0x100, 0x40, 0x80);
    func_00392400(func_00392108(0x7558, 2), x, y, 0x20, 0x20, D_001A666A[0] == 0 ? 0 : 0x80);
    return o->w58;
}
/* localdecomp:end func_00391A18 */

/* localdecomp:start func_00391B30 */
extern void func_0038EFD0(void *);
 
void func_00391B30(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0x96;
    *(s32 *)((u8 *)p + 0x58) = 0x20;
    *(s32 *)((u8 *)p + 0x5C) = 0x20;
    func_0038EFD0(p);
}
/* localdecomp:end func_00391B30 */

/* localdecomp:start func_00391B60 */
s32 func_00391B60(void) {
    return 0;
}
/* localdecomp:end func_00391B60 */

LINKER_REMNANT("asm/remnants", func_00391B68);

INCLUDE_ASM("asm/nonmatchings/text", func_00391B70);

INCLUDE_ASM("asm/nonmatchings/text", func_00391D08);

/* localdecomp:start func_00391E30 */
typedef struct {
    u8 pad[0x84];
    u16 f84;
    u8 pad2[0xF0 - 0x86];
} S_391E30;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern S_391E30 D_001DAAC0[];
s32 func_00391E30(void) {
    u8 *b = D_001A4BE0;
    s32 r = *(s32 *)(b + 0x1228);
    u8 f = b[0x25E4];
    u8 *q = (u8 *)D_001425C0 + r;
    S_391E30 *t = D_001DAAC0;
    if (t[*q].f84 == 0) {
        r = 0;
    }
    if (f != 0) {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_00391E30 */

INCLUDE_ASM("asm/nonmatchings/text", func_00391E78);

INCLUDE_ASM("asm/nonmatchings/text", func_00391FD8);

INCLUDE_ASM("asm/nonmatchings/text", func_00392108);

INCLUDE_ASM("asm/nonmatchings/text", func_003921D8);

INCLUDE_ASM("asm/nonmatchings/text", func_00392400);

INCLUDE_ASM("asm/nonmatchings/text", func_003925F0);

INCLUDE_ASM("asm/nonmatchings/text", func_00392878);

LINKER_REMNANT("asm/remnants", func_00392A20);

INCLUDE_ASM("asm/nonmatchings/text", func_00392A40);

INCLUDE_ASM("asm/nonmatchings/text", func_00392DD8);

INCLUDE_ASM("asm/nonmatchings/text", func_00393120);

LINKER_REMNANT("asm/remnants", func_00393290);

/* localdecomp:start func_003932B0 */
typedef struct {
    u8 pad0[8]; s32 f8; s32 *fC; u8 pad10[0x5C]; s32 f6C; u8 b[2]; u8 pad72[2]; s32 f74; u8 pad78[4]; s32 f7C;
} S_3932B0;
void func_003932B0(S_3932B0 *p) {
    u8 *b = p->b;
    s32 t = *p->fC;
    s32 a = p->f8;
    p->f74 = t;
    if (a < t) {
        p->f74 = a;
    } else if (t < 0) {
        p->f74 = 0;
    }
    if (p->f7C >= 5) {
        p->f7C = 5;
        if (b[0] < 8) {
            b[0]++;
        } else if (b[1] < 8) {
            b[1]++;
        }
    } else {
        p->f6C = 1;
        if (b[1] != 0) {
            b[1]--;
        } else if (b[0] != 0) {
            b[0]--;
        } else {
            p->f6C = -6;
        }
    }
}
/* localdecomp:end func_003932B0 */

LINKER_REMNANT("asm/remnants", func_00393360);

/* localdecomp:start func_00393370 */
extern u8 D_001D5EDC;
void func_00393370(void) { D_001D5EDC = 1; }
/* localdecomp:end func_00393370 */

/* localdecomp:start func_00393380 */
__asm__(".extern D_001D5EDC, 1");
__asm__(".extern D_001D5ED8, 4");
extern u8 D_001D5EDC;
extern s32 D_001D5ED8;
extern void func_003866E8();
void func_00393380(void) {
    s32 v;
    f32 t;
    if (D_001D5EDC) {
        D_001D5EDC = 0;
        D_001D5ED8 = D_001D5ED8 + 1;
        if (D_001D5ED8 > 10) D_001D5ED8 = 10;
    } else {
        D_001D5ED8 = D_001D5ED8 - 1;
        if (D_001D5ED8 < 0) D_001D5ED8 = 0;
    }
    t = (f32)D_001D5ED8;
    t = t / 10.0f;
    t = t * 48.0f;
    v = (s32)t;
    if (v) func_003866E8(0, 0, 0, v);
}
/* localdecomp:end func_00393380 */

LINKER_REMNANT("asm/remnants", func_00393418);

/* localdecomp:start func_00393420 */
extern u8 D_001D5EDD;
void func_00393420(void) {
    D_001D5EDD = 0;
}
/* localdecomp:end func_00393420 */

/* localdecomp:start func_00393428 */
extern s32 D_001D5EE0;
void func_00393428(void) {
    D_001D5EE0 = 0;
}
/* localdecomp:end func_00393428 */

/* localdecomp:start func_00393430 */
extern s32 D_001D5EE0;
void func_00393430(void) {
    if (D_001D5EE0 == 0) D_001D5EE0 = 1;
}
/* localdecomp:end func_00393430 */

/* localdecomp:start func_00393448 */
extern s32 D_001D5EE0;
s32 func_00393448(void) {
    return D_001D5EE0 == 3;
}
/* localdecomp:end func_00393448 */

LINKER_REMNANT("asm/remnants", func_00393458);

/* localdecomp:start func_00393460 */
extern void func_00385B60(s32);
extern void func_13CA28(void);
extern void func_13B620(void);
extern void func_003A0010(void);
extern void func_0039D4D0(void);
extern void func_0039CBA0(void);
extern void func_12EF10(void);
extern void func_121B38(void);
extern void func_124ED8(s32, s32, s32);
void func_00393460(s32 a, s32 b, s32 c) {
    func_00385B60(5);
    func_13CA28();
    func_13B620();
    func_003A0010();
    func_0039D4D0();
    func_0039CBA0();
    func_12EF10();
    func_121B38();
    func_124ED8(a, b, c);
}
/* localdecomp:end func_00393460 */
