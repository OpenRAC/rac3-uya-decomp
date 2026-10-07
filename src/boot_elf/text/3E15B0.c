#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003E5790(void);
extern void func_003E5828(void);
extern s32 func_003E1660();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E15B0);

/* localdecomp:start func_003E15E0 */
extern void func_003A9560(s32);
extern void func_00391648(void);
extern s32 D_001D5520[];
extern void func_00391998(s32, s32, s32, s32, s32, s32);
extern void func_003D9588(void);
void func_003E15E0(void) {   /* same as func_003B6718 plus the call below */
    func_003A9560(1);
    func_00391648();
    if (D_001D5520[0] != 0) {
        func_00391998(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        func_00391998(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
    func_003D9588();
}
/* localdecomp:end func_003E15E0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E1658);

/* localdecomp:start func_003E1660 */
extern s32 D_00306DC0[];
 
s32 func_003E1660(void) {
    return D_00306DC0[0];
}
/* localdecomp:end func_003E1660 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E1670);

/* localdecomp:start func_003E1688 */
typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA, fC, fE;
    s16 f10;
    u16 f12;
    s16 f14, f16, f18, f1A;
} T_3DBEC8;
typedef struct {
    u8 pad0[0x40];
    s32 f40;
    s32 f44;
    u8 pad48[0x58 - 0x48];
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 pad64[0x7C - 0x64];
    s16 f7C, f7E;
    s32 f80;
    u8 pad84[0x98 - 0x84];
} S_3DBEC8;

__asm__(".extern D_001D94DC, 4");
__asm__(".extern D_001D94E0, 4");
__asm__(".extern D_001D94E4, 4");
__asm__(".extern D_001D94E8, 1");
__asm__(".extern D_001D94FC, 4");
__asm__(".extern D_001D9500, 4");

extern S_3DBEC8 D_00306D80_003E1688;
extern T_3DBEC8 D_001D9510;
extern T_3DBEC8 D_001D9550;
extern char D_001D9530[];
extern char D_001D9538[];
extern char D_001D9540[];
extern char D_001D9570[];
extern s32 D_001D9C48;
extern u16 D_001D4BC4;
extern s32 D_001D5B90;
extern s32 D_001D4CE8;
extern u8 D_001DA020;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD;
extern f32 D_001DA0F4;
extern s32 D_001DA0F0;
extern char *D_001D94DC;
extern char *D_001D94E0;
extern char *D_001D94E4;
extern u8 D_001D94E8;
extern s32 D_001D94FC;
extern s32 D_001D9500;
extern u8 D_00335860[];

extern void func_0038B148(s32, s32, s32, s32);
extern void func_003895C8(s32);
extern void func_003A96B0(s32, unsigned long);
extern char *func_00382488(s32);
extern s32 func_11BB58(void *, void *, s32);
extern s32 func_11B868(void *);
extern void func_0038FD40(T_3DBEC8 *, unsigned long, void *, s32, unsigned long, f32, f32);
extern void func_003AF620(T_3DBEC8 *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern s32 func_00396C60(s32, s32);
extern void func_00396F58(s32, s32, s32, s32, s32, s32);
extern s32 func_00396D30(s32);
extern void func_00397930(f32, f32, f32, f32, f32, s32, s32, s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_0038E478(s32);
extern void func_003824B0(void);
extern void func_11B2E8();
extern void func_0038C6D8(s32, s32, s32, s32, s32, s32);
extern s32 func_0038DF00(s32, s32, f32);
extern s32 func_003910D8(s32, s32, s32, void *, s32);
extern long func_00389920(s32);
extern void func_00391400(T_3DBEC8 *, s32, void *, s32, long, void *);
extern void func_003913E0(T_3DBEC8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003896F8(void);

void func_003E1688(void) {
    char buf[0x200];
    T_3DBEC8 s210;
    T_3DBEC8 s230;
    T_3DBEC8 s250;
    char buf2[0x100];
    s32 tmp;
    T_3DBEC8 *ps;

    if (D_00306D80_003E1688.f7E == 0) {
        func_0038B148(0, 0, 0, 0x30);
    }
    if (D_00306D80_003E1688.f7C != 0) {
        return;
    }
    func_003895C8(0);
    func_003A96B0(0x42, 0x8000000044UL);
    func_003A96B0(0x47, 0x5360B);
    switch (D_00306D80_003E1688.f40) {
    case 2: {
        u8 *s = (u8 *)0x70000000;
        u8 *p;
        s32 n, k, x, y;
        f32 w;
        char *str;
        f32 a, fx;
        s32 r;
        s210 = D_001D9510;
        func_11BB58(s, func_00382488(0xB75), 0x400);
        p = s;
        while (*p >= 2) p++;
        while (*p == 1) { *p = 0; p++; }
        s210.f12 |= 4;
        func_0038FD40(&s210, 0x80000000UL, s, -1, 0x80000000UL, 1.0f, 1.0f);
        s210.f12 ^= 4;
        tmp = s210.fE;
        n = func_11B868(s);
        for (k = 4; k >= 0; k--) s[n + k] = 1;
        s[n + 5] = 0;
        if (D_00306D80_003E1688.f5C >= 0x79) {
            str = func_00382488(0x8DE);
        } else {
            str = D_001D9530;
        }
        w = 272.0f;
        func_003AF620(&s210, 0x8066CCFF, s, 1, 1, -1, 1, str, 0, 0);
        x = s210.f0 + tmp;
        func_003A96B0(0x47, 0x3004B);
        y = x + 8;
        func_00396F58(func_00396C60(0x755D, 0), 0xE0, y, 0x40, 0x40, 0x80);
        a = (f32)(D_001D9C48 % 0x37) * -6.2831855f / 55.0f;
        fx = (x + 0x28) << 4;
        r = func_00396D30(func_00396C60(0x755D, 1));
        func_00397930(4096.0f, fx, w, w, a, 0x40, 0x40, r);
        break;
    }
    case 4: {
        u8 *s = (u8 *)0x70000000;
        u8 *p;
        s32 id;
        char *str;
        if (D_00306D80_003E1688.f5C <= 0) break;
        func_11BB58(s, func_00382488(0x194), 0x400);
        p = s;
        while (*p >= 2) p++;
        while (*p == 1) { *p = 0; p++; }
        id = D_00306D80_003E1688.f44 ? 0 : 0x8DE;
        func_0011A264(&s230, 0, 0x1C);
        s230.f2 = D_001D4BC4;
        s230.f4 = 0x4C;
        s230.f6 = 0x1B4;
        s230.f8 = 0x100;
        s230.fA = 0x68;
        s230.f10 = 0x10;
        s230.f12 = 1;
        s210 = s230;
        str = id ? func_00382488(id) : 0;
        func_0038E478(1);
        func_003AF620(&s210, 0x8066CCFF, p, 1, 1, -1, 0, str, 0, 0);
        break;
    }
    case 5: {
        char *t;
        s32 id;
        char *str;
        if (D_00306D80_003E1688.f5C <= 0) break;
        t = func_00382488(D_00306D80_003E1688.f80 ? 0x1B3 : 0x1B2);
        id = D_00306D80_003E1688.f44 ? 0 : 0x8DE;
        func_0011A264(&s250, 0, 0x1C);
        s250.f2 = D_001D4BC4;
        s250.f4 = 0x4C;
        s250.f6 = 0x1B4;
        s250.f8 = 0x100;
        s250.fA = 0x68;
        s250.f10 = 0x10;
        s250.f12 = 1;
        s210 = s250;
        str = id ? func_00382488(id) : 0;
        func_0038E478(1);
        func_003AF620(&s210, 0x8066CCFF, t, 1, 1, -1, 0, str, 0, 0);
        break;
    }
    case 1: {
        s32 ok, id2, id3, a;
        char *text;
        char *t2;
        char *t3;
        if (D_001D5B90 != -2) break;
        ok = 1;
        if (D_00306D80_003E1688.f5C <= 0) break;
        id2 = 0;
        id3 = 0;
        text = D_001D9538;
        func_003824B0();
        switch (D_001D4CE8) {
        case 8:
            a = 0x1A3;
            id2 = 0x8E3;
            id3 = 0x8DF;
            text = func_00382488(a);
            break;
        case 14:
            if (D_001DA020) {
                a = 0x195;
                id2 = 0x197;
                text = func_00382488(a);
                break;
            }
        case 15:
            a = 0x19F;
            id2 = 0x8E3;
            id3 = 0x8DF;
            text = func_00382488(a);
            break;
        case 33:
            a = 0x1A8;
            id2 = 0x8E3;
            id3 = 0x8DF;
            text = func_00382488(a);
            break;
        case 12: case 13: case 31: case 32:
            text = func_00382488(0x1AF);
            break;
        case 9: case 10:
            text = func_00382488(0x1AD);
            break;
        case 16: case 17:
            text = func_00382488(0x1AE);
            break;
        case 25: case 29:
            text = func_00382488(0x1AB);
            break;
        case 23: case 30:
            text = func_00382488(0x1AC);
            break;
        case 19:
            id2 = 0x8DE;
            text = func_00382488(0x1B0);
            break;
        case 20:
            id2 = 0x8DE;
            text = func_00382488(0x1B2);
            break;
        case 3:
            text = func_00382488(0x194);
            id2 = D_00306D80_003E1688.f44 ? 0 : 0x8DE;
            break;
        case 21:
            if (D_001DA020) {
                id2 = 0x197;
                text = func_00382488(0x195);
                break;
            }
            if (D_001D5BDC) {
                char *fmt = D_001D9540;
                text = func_00382488(0x198);
                id2 = 0x8E2;
                id3 = 0x8DF;
                func_11B2E8(buf, fmt, text, 1, 1, func_00382488(0x19A));
                text = buf;
                break;
            } else {
                char *fmt = D_001D9540;
                text = func_00382488(0x198);
                id2 = 0x8E2;
                func_11B2E8(buf, fmt, text, 1, 1, func_00382488(0x19A));
                text = buf;
                break;
            }
        case 24:
            id2 = 0x8DE;
            text = func_00382488(0x1B3);
            break;
        case 22:
            id2 = 0x8DE;
            text = func_00382488(0x1B1);
            break;
        case 27: {
            char *fmt = D_001D9540;
            text = func_00382488(0x1A1);
            id2 = 0x8E2;
            id3 = 0x8DF;
            func_11B2E8(buf, fmt, text, 1, 1, func_00382488(0x11E8));
            text = buf;
            break;
        }
        case 26:
            id2 = 0x8E2;
            id3 = 0x8DF;
            text = func_00382488(0x1A5);
            break;
        case 4: case 5: case 6:
            if (D_001D5BDC && !D_001DA020) {
                id2 = 0x8E2;
                id3 = 0x8DF;
                text = func_00382488(0x19B);
                break;
            }
            if (D_001D5BDD) {
                id2 = 0x8E2;
                text = func_00382488(0x19B);
                break;
            }
            if (D_001DA020) {
                id2 = 0x197;
                text = func_00382488(0x195);
                break;
            }
            id2 = 0x197;
            text = func_00382488(0x19D);
            break;
        case 7:
            id2 = 0x197;
            text = func_00382488(0x195);
            break;
        default:
            ok = 0;
            break;
        }
        if (!ok) break;
        func_0011A264(&s230, 0, 0x1C);
        s230.f2 = D_001D4BC4;
        s230.f4 = 0x4C;
        s230.f6 = 0x1B4;
        s230.f8 = 0x100;
        s230.fA = 0x68;
        s230.f10 = 0x10;
        s230.f12 = 1;
        s210 = s230;
        t2 = id2 ? func_00382488(id2) : 0;
        t3 = id3 ? func_00382488(id3) : 0;
        func_0038E478(1);
        func_003AF620(&s210, 0x8066CCFF, text, 1, 1, -1, 0, t2, t3, 1);
        break;
    }
    case 3: {
        f32 t;
        s32 c1, id, col;
        t = 1.0f - (f32)D_00306D80_003E1688.f44 / 30.0f;
        s210 = D_001D9550;
        func_0038C6D8(0x64, 0x12C, 0x60, 0x1A0, (s32)(t * 80.0f), 0x40404);
        c1 = func_0038DF00(D_001D94FC, D_001D9500, t);
        id = func_0038DF00(0x20FFFF, 0x8020FFFF, t);
        switch (D_00306D80_003E1688.f58) {
        case 0:
        case 1:
            col = id;
            func_003910D8(0xCA, 0x118, col, func_00382488(0x8E2), -1);
            func_003910D8(0x135, 0x118, col, func_00382488(0x8DF), -1);
            id = 0x24C;
            break;
        case 2:
            col = id;
            func_003910D8(0xCA, 0x118, col, func_00382488(0x8E2), -1);
            func_003910D8(0x135, 0x118, col, func_00382488(0x8DF), -1);
            id = 0x24D;
            break;
        case 3:
            col = id;
            func_003910D8(0x100, 0x118, col, func_00382488(0x8DE), -1);
            id = 0x24E;
            break;
        default:
            id = 0;
            break;
        }
        ps = &s210;
        if (id == 0) break;
        col = c1;
        c1 = (s32)func_00382488(id);
        func_00391400(ps, col, (void *)c1, -1, func_00389920(1), D_00335860);
        break;
    }
    case 9: {
        s32 v;
        char *a, *b, *c;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_001DA0F4 * 100.0f + 0.5f + (D_001DA0F0 == 1 ? z0 : z1)); }
        tmp = (s32)&s210;
        func_003913E0((T_3DBEC8 *)tmp, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, v, 0x10, 3);
        if ((a = D_001D94DC) == 0) a = func_00382488(0x8E2);
        if ((b = D_001D94E0) == 0) b = func_00382488(0x8DF);
        if ((c = D_001D94E4) == 0) c = func_00382488(0x17C);
        func_0038E478(1);
        func_003AF620((T_3DBEC8 *)tmp, 0x80F0F0F0, c, 1, 1, -1, 0, a, b, D_001D94E8);
        break;
    }
    case 10: {
        s32 v;
        char *a, *c;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_001DA0F4 * 100.0f + 0.5f + (D_001DA0F0 == 1 ? z0 : z1)); }
        ps = &s210;
        func_003913E0(ps, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, v, 0x10, 3);
        if ((a = D_001D94DC) == 0) a = func_00382488(0x8E2);
        if ((c = D_001D94E4) == 0) c = func_00382488(0x17C);
        func_0038E478(1);
        func_003AF620(ps, 0x80F0F0F0, c, 1, 1, -1, 0, a, 0, D_001D94E8);
        break;
    }
    case 11: {
        s32 v;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_001DA0F4 * 100.0f + 0.5f + (D_001DA0F0 == 1 ? z0 : z1)); }
        func_003913E0(&s210, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, v, 0x10, 3);
        switch (D_00306D80_003E1688.f58) {
        case 0:
            break;
        case 1: {
            char *t1, *t2;
            t1 = func_00382488(0x8DE);
            t2 = func_00382488(0x8C1);
            func_11B2E8(buf2, func_00382488(0x50A), 0xF);
            func_0038E478(1);
            func_003AF620(&s210, 0x8066CCFF, buf2, 1, 1, -1, 0, t1, t2, 0);
            break;
        }
        case 2:
            break;
        case 3: {
            char *t1, *t2, *t3;
            char *fmt = D_001D9570;
            tmp = (s32)buf2;
            D_00306D80_003E1688.f60 = D_00306D80_003E1688.f5C / 60 + 1;
            t1 = func_00382488(0x511);
            t2 = func_00382488(0x512);
            t3 = func_00382488(0x513);
            func_11B2E8((char *)tmp, fmt, t1, t2, D_00306D80_003E1688.f60, t3);
            t1 = func_00382488(0x8E3);
            t2 = func_00382488(0x8DF);
            func_0038E478(1);
            func_003AF620(&s210, 0x8066CCFF, (char *)tmp, 1, 1, -1, 0, t1, t2, 0);
            break;
        }
        }
        break;
    }
    case 6: case 7: case 8:
        break;
    }
    func_003896F8();
}
/* localdecomp:end func_003E1688 */

/* localdecomp:start func_003E24C8 */
/* VU0 j-form: each VU0 instruction is a separate non-volatile __asm__ using the "j" (VU0
   register) constraint, which needs -mvu0-use-vf0-vfN. The original build used N = 2 on every
   file (tools/text_parts.txt carries -mvu0-use-vf0-vf2 on every line); see Matching-Patterns,
   "VU0 j-form: one asm statement per instruction". */
typedef int Q_3DCD08 __attribute__((mode(TI)));
typedef struct { Q_3DCD08 a, b; } V2_3DCD08;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DCD08;
typedef struct {
    V4_3DCD08 v0;
    V4_3DCD08 v10;
    V4_3DCD08 v20;
    V4_3DCD08 v30;
    s32 f40;
    s32 f44;
    s32 f48, f4C, f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    f32 f6C;
    s32 f70;
    s32 f74, f78;
    s16 f7C, f7E;
    s32 f80;
    s16 f84, f86;
    s32 f88, f8C, f90, f94;
} S_3DCD08;
typedef struct {
    u8 pad0[0x100];
    s32 f100;
    u8 pad104[0x148 - 0x104];
    f32 f148;
    f32 f14C;
    u8 pad150[0x1A4 - 0x150];
    s32 f1A4;
    u8 pad1A8[0x1C0 - 0x1A8];
    s32 f1C0;
    s32 f1C4;
} P_3DCD08;
typedef struct { u8 pad[0x120]; u16 f120; } T_3DCD08;
typedef struct { u8 pad[8]; s32 f8; s32 fC; s32 f10; } M_3DCD08;
typedef struct { u8 pad[0x64]; void (*f64)(void *); u8 pad68[0xAA - 0x68]; s16 fAA; u8 padAC[0x100 - 0xAC]; } E_3DCD08;

__asm__(".extern D_001D9504, 4");
__asm__(".extern D_001D9508, 4");
__asm__(".extern D_001D94D0, 4");
__asm__(".extern D_001D94D4, 4");
__asm__(".extern D_001D94D8, 4");
__asm__(".extern D_001D94F0, 4");

extern S_3DCD08 D_00306D80_003E24C8;
extern P_3DCD08 *D_001D52FC;
extern s32 D_001D4CEC;
extern s32 D_001D4CE8;
extern s32 D_001D545C;
extern s32 D_001D5B90;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD;
extern s32 D_001D9DD0;
extern s32 D_001D9DD4;
extern f32 D_001D9E90;
extern u8 D_001DA020;
extern u8 D_001DA268;
extern E_3DCD08 *D_001DA51C;
extern E_3DCD08 *D_001DA520;
extern s32 D_001D5520_003E24C8;
extern s32 D_001D94D0;
extern s32 D_001D94D4;
extern s32 D_001D94D8;
extern s32 D_001D94F0;
extern s32 D_001D9504;
extern f32 D_001D9508;
extern u8 D_001A71C4[];
extern T_3DCD08 D_1A7E18;
extern M_3DCD08 D_142430;
extern s32 D_001425AC[];
extern V4_3DCD08 D_00222480[];

extern s32 func_003A4548(void);
extern void func_003A5608(s32, s32, s32);
extern void func_003B8D18(s32);
extern void func_003A91C0(void);
extern void func_0038A5C0(s32);
extern void func_003A1160(s32);
extern s32 func_003A1180(s32, s32, s32, s32, s32);
extern void func_003A1258(s32, s32);
extern s32 func_003BB958(void);
extern void func_0039C158(void);
extern void func_0039C2A0(void);
extern void func_0039C2B8(void);
extern void func_0039C5C8(void);
extern f32 func_0038D1D0(void *);
extern void func_003C4420(f32 *, void *, f32, f32, f32, f32);
extern void func_0038D290(void *, void *, f32);
extern void func_003E3A20(void *, s32);
extern void func_0038D328(void *, void *, void *);
extern void func_003C4E00(void *, f32);
extern void func_0038D148(void *, void *, f32);
extern void func_003E3BF0(void *);
extern void func_003E3B68(f32 *);
extern void func_0038D8D8(void *, void *);
extern void func_003C4B20(void *, void *);
extern void func_0038D120(void *, void *, void *, f32);
extern void func_003C4240(void *, void *);
extern void func_0038D9F0(void *, void *, void *, f32);
extern void func_0038DB38(void *, void *);
extern s32 func_00381C90(void);
extern void func_00397EC8(void);
extern void func_003E4078(void);
extern s32 func_00393668(s32, s32, void *, void *, void *, s32, s32);
extern void func_003AFA50(void);
extern void func_003E3D20(void);
extern void func_003E4F80(s32);
extern void func_003E5750(s32);
extern void func_00397F80(void);
extern void func_00397F78(void);
extern void func_003E4090(void);
extern void func_003E15E0(void);
extern void func_00385140(void);
extern void func_00393EF8(void);
extern void func_00393F50(void);
extern void func_00394918(void);
extern void func_00395240(void);
extern void func_00395288(void);
extern void func_00395770(void);

void func_003E24C8(void) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    f32 len;

    func_003A4548();
    D_001D9DD0 = D_00306D80_003E24C8.f94;
    if (D_00306D80_003E24C8.f44 != 0) {
        D_00306D80_003E24C8.f44--;
    }
    if (D_00306D80_003E24C8.f7C != 0) {
        D_00306D80_003E24C8.f7C--;
    }
    switch (D_00306D80_003E24C8.f40) {
    case 2:
        D_00306D80_003E24C8.f5C++;
        if (D_00306D80_003E24C8.f5C >= 0x5B && D_00306D80_003E24C8.f60 != 0) {
            D_00306D80_003E24C8.f60--;
        }
        if (D_001D4CE8 == 3) {
            func_003A1180(4, 2, 1, 0, 0);
            break;
        }
        if (D_00306D80_003E24C8.f5C >= 0x79 && (D_001D52FC->f1A4 & 0x40)) {
            if (D_1A7E18.f120 == 0) {
                D_1A7E18.f120 = 1;
            }
            func_003A5608(4, 0, 0);
            func_003A1258(0, 0);
        }
        break;
    case 5:
        D_00306D80_003E24C8.f5C++;
        if (D_00306D80_003E24C8.f5C >= 0x1F && D_00306D80_003E24C8.f60 != 0) {
            D_00306D80_003E24C8.f60--;
        }
        if (D_00306D80_003E24C8.f60 == 0 && (D_001D52FC->f1A4 & 0x40)) {
            D_001D4CEC &= ~0x40;
            D_001425AC[0] = 0;
            func_003B8D18(-1);
            func_003A91C0();
        }
        break;
    case 4:
        D_00306D80_003E24C8.f5C++;
        if (D_00306D80_003E24C8.f5C >= 0x1F && D_00306D80_003E24C8.f60 != 0) {
            D_00306D80_003E24C8.f60--;
        }
        if (D_00306D80_003E24C8.f60 == 0 && (D_001D52FC->f1A4 & 0x40)) {
            D_001425AC[0] = 0;
            func_003B8D18(-1);
            func_003A91C0();
        }
        break;
    case 3:
        switch (D_00306D80_003E24C8.f58) {
        case 0:
            if (D_00306D80_003E24C8.f44 == 0) {
                D_00306D80_003E24C8.f58 = 1;
            }
            break;
        case 1: {
            s32 t = D_001D52FC->f1A4;
            if (t & 0x10) {
                func_003A1258(0, 0);
                break;
            }
            if (t & 0x40) {
                func_0038A5C0(4);
                D_00306D80_003E24C8.f58 = 2;
                D_00306D80_003E24C8.f5C = 0x258;
                D_001DA268 = 0;
            }
            break;
        }
        case 2:
            if (D_00306D80_003E24C8.f5C != 0) {
                D_00306D80_003E24C8.f5C--;
            }
            if (D_00306D80_003E24C8.f5C == 0) {
                D_001DA268 = 1;
                D_00306D80_003E24C8.f58 = 3;
                break;
            } else {
                s32 t = D_001D52FC->f1A4;
                if (t & 0x10) {
                    func_0038A5C0(4);
                    D_001DA268 = 1;
                    func_003A1258(0, 0);
                    break;
                }
                if (t & 0x40) {
                    D_001DA268 = 0;
                    func_003A1258(0, 0);
                }
            }
            break;
        case 3:
            if (D_001D52FC->f1A4 & 0x40) {
                func_003A1258(0, 0);
            }
            break;
        default:
            func_003A1258(0, 0);
            break;
        }
        break;
    case 1:
        if (D_001D5B90 != -2) {
            break;
        }
        D_00306D80_003E24C8.f5C++;
        if (D_00306D80_003E24C8.f5C >= 0x1F && D_00306D80_003E24C8.f60 != 0) {
            D_00306D80_003E24C8.f60--;
        }
        switch (D_001D4CE8) {
        case 3:
            if (D_00306D80_003E24C8.f60 != 0) break;
            if (!(D_001D52FC->f1A4 & 0x40)) break;
            D_001D4CEC &= ~1;
            D_00306D80_003E24C8.f84 = 2;
            if (D_001D5BDD != 0) {
                func_003A1160(5);
                func_003A1180(3, 2, 7, 0, 0);
                break;
            }
            func_003A1258(0, 0);
            break;
        case 8:
            if (D_00306D80_003E24C8.f60 == 0 && (D_001D52FC->f1A4 & 0x20)) {
                D_00306D80_003E24C8.f84 = 2;
                D_001D4CEC |= 8;
                break;
            }
            if (D_00306D80_003E24C8.f44 != 0) break;
            if (!(D_001D52FC->f1A4 & 0x10)) break;
            if (D_001D5BDD != 0) {
                D_00306D80_003E24C8.f84 = 2;
                func_003A91C0();
                break;
            }
            D_001D4CEC |= 0x20;
            if (func_003BB958() == 0) {
                D_001D4CEC &= ~2;
            }
            D_001D4CEC &= ~4;
            D_00306D80_003E24C8.f84 = 1;
            if (D_001D5BDC == 0) {
                func_003A1258(0, 0);
            }
            break;
        case 15:
            if (D_00306D80_003E24C8.f60 == 0 && (D_001D52FC->f1A4 & 0x20)) {
                func_0039C158();
                D_00306D80_003E24C8.f84 = 2;
                break;
            }
            if (D_00306D80_003E24C8.f44 != 0) break;
            if (!(D_001D52FC->f1A4 & 0x10)) break;
            if (D_001D5BDD != 0) {
                D_00306D80_003E24C8.f84 = 2;
                func_003A91C0();
                break;
            }
            D_001D4CEC |= 0x20;
            D_001D4CEC &= ~2;
            D_001D4CEC &= ~4;
            D_00306D80_003E24C8.f84 = 1;
            if (D_001D5BDC == 0) {
                func_003A1258(0, 0);
            }
            break;
        case 33: {
            s32 t = D_001D52FC->f1A4;
            if (t & 0x20) {
                func_0039C158();
                break;
            }
            if (t & 0x10) {
                func_0039C2A0();
                func_0039C2B8();
            }
            break;
        }
        case 22:
            if (D_00306D80_003E24C8.f60 != 0) break;
            if (!(D_001D52FC->f1A4 & 0x40)) break;
            D_001D4CEC &= ~0x40;
            D_001D4CEC &= ~0x400;
            D_001D4CEC &= ~2;
            D_001D4CEC &= ~4;
            D_00306D80_003E24C8.f84 = 2;
            if (D_001D5BDC != 0) {
                func_003A1258(0, 0);
            } else {
                func_003A1258(0, 0);
            }
            break;
        case 19:
        case 20:
        case 24:
            if (D_00306D80_003E24C8.f68 > 0) {
                D_00306D80_003E24C8.f68--;
                if (D_00306D80_003E24C8.f68 > 0) break;
                if (D_142430.f8 == 2) {
                    s32 t = D_142430.f10;
                    if (t == 0) {
                        D_001D4CE8 = 0xB;
                    } else if (t == -1) {
                        D_001D4CE8 = 0xB;
                        D_142430.f10 = 0;
                    } else if (t == -2) {
                        D_001D4CE8 = 7;
                    } else {
                        D_001D4CE8 = 0xE;
                    }
                    func_003A1258(0, 0);
                    break;
                }
                D_00306D80_003E24C8.f84 = 2;
                func_003A91C0();
                break;
            }
            if (D_00306D80_003E24C8.f60 != 0) break;
            if (!(D_001D52FC->f1A4 & 0x40)) break;
            if (D_001D5BDD != 0) {
                D_00306D80_003E24C8.f68 = 0xF;
                break;
            }
            D_001D4CEC &= ~0x40;
            D_001D4CEC &= ~0x400;
            D_001D4CEC &= ~2;
            D_001D4CEC &= ~4;
            D_00306D80_003E24C8.f84 = 2;
            func_003A1258(0, 0);
            break;
        case 1:
        case 18:
            if (D_001D4CEC & 6) break;
            func_003A1258(0, 0);
            break;
        case 14:
            if (D_001DA020 == 0) break;
        case 4:
        case 5:
        case 7:
            if (D_00306D80_003E24C8.f60 != 0) break;
            if (!(D_001D52FC->f1A4 & 0x10)) break;
            D_001D4CEC &= ~2;
            D_001D4CEC &= ~4;
            D_00306D80_003E24C8.f84 = 1;
            func_003A1258(0, 0);
            break;
        case 21:
            if (D_001D5BDC != 0 && D_001DA020 == 0) {
                s32 t;
                if (D_00306D80_003E24C8.f60 != 0) break;
                t = D_001D52FC->f1A4;
                if (t & 0x40) {
                    func_0039C5C8();
                    D_001D4CEC &= ~2;
                    D_001D4CEC &= ~4;
                    D_001D4CEC |= 0x20;
                    D_00306D80_003E24C8.f84 = 2;
                    func_003A91C0();
                    break;
                }
                if (t & 0x10) {
                    D_001D4CEC &= ~2;
                    D_001D4CEC &= ~4;
                    D_00306D80_003E24C8.f84 = 1;
                    func_003A1258(0, 0);
                }
                break;
            }
            if (D_001D5BDD != 0) {
                if (D_00306D80_003E24C8.f60 != 0) break;
                if (D_001D52FC->f1A4 & 0x40) {
                    D_00306D80_003E24C8.f84 = 2;
                    func_003A91C0();
                }
                break;
            }
            if (D_00306D80_003E24C8.f60 != 0) break;
            if (!(D_001D52FC->f1A4 & 0x10)) break;
            D_001D4CEC &= ~2;
            D_001D4CEC &= ~4;
            D_00306D80_003E24C8.f84 = 1;
            func_003A1258(0, 0);
            break;
        case 26:
        case 27: {
            s32 t;
            if (D_00306D80_003E24C8.f60 != 0) break;
            t = D_001D52FC->f1A4;
            if (t & 0x40) {
                func_0039C5C8();
                D_001D4CEC &= ~2;
                D_001D4CEC &= ~4;
                D_001D4CEC |= 0x20;
                D_00306D80_003E24C8.f84 = 2;
                func_003A91C0();
                break;
            }
            if (t & 0x10) {
                D_00306D80_003E24C8.f84 = 1;
                D_001D4CEC |= 0x20;
                func_003A1258(0, 0);
            }
            break;
        }
        case 6:
            if (D_001D5BDC != 0 && D_001DA020 == 0) {
                if (D_00306D80_003E24C8.f60 == 0 && (D_001D52FC->f1A4 & 0x40)) {
                    func_0039C5C8();
                    D_001D4CEC &= ~2;
                    D_001D4CEC &= ~4;
                    D_00306D80_003E24C8.f84 = 2;
                    func_003A91C0();
                }
                if (D_00306D80_003E24C8.f60 == 0 && (D_001D52FC->f1A4 & 0x10)) {
                    D_001D4CEC |= 0x20;
                    D_001D4CEC &= ~2;
                    D_001D4CEC &= ~4;
                    D_00306D80_003E24C8.f84 = 1;
                    func_003A1258(0, 0);
                }
                break;
            }
            if (D_001D5BDC == 0 && D_001D5BDD != 0) {
                if (D_00306D80_003E24C8.f60 != 0) break;
                if (D_001D52FC->f1A4 & 0x20) {
                    D_00306D80_003E24C8.f84 = 2;
                    func_003A91C0();
                }
                break;
            }
            if (D_00306D80_003E24C8.f60 != 0) break;
            if (!(D_001D52FC->f1A4 & 0x10)) break;
            D_001D4CEC |= 0x20;
            D_001D4CEC &= ~2;
            D_001D4CEC &= ~4;
            D_00306D80_003E24C8.f84 = 1;
            func_003A1258(0, 0);
            break;
        case 11:
            if (D_001D4CEC & 6) break;
            func_003A1258(0, 0);
            break;
        case 2: case 9: case 10: case 12: case 13: case 16: case 17: case 23: case 25:
        case 28: case 29: case 30: case 31: case 32:
        default:
            break;
        }
        break;
    case 6:
        switch (D_00306D80_003E24C8.f58) {
        case 0:
            *(V2_3DCD08 *)&D_00306D80_003E24C8.v0 = *(V2_3DCD08 *)D_00222480;
            D_00306D80_003E24C8.f58 = 1;
            if (D_001D545C == 0xB) {
                if (D_001D9E90 == 200.0f) {
                    D_001D9504 = 0xAF;
                } else {
                    D_001D9504 = 0x7D;
                }
            }
            break;
        case 1: {
            Q_3DCD08 v1, v2;
            if (D_001D545C != 0xB) {
                D_001D9DD0 = 3;
            }
            __asm__("lqc2 %0, %1" : "=j"(v2) : "m"(D_001D9E90));
            __asm__("lqc2 %0, %1" : "=j"(v1) : "m"(D_00222480[0]));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(v1) : "j"(v1), "j"(v2));
            __asm__("sqc2 %1, %0" : "=m"(*(V4_3DCD08 *)a) : "j"(v1));
            len = func_0038D1D0(a);
            func_003C4420(&len, &D_00306D80_003E24C8.f6C, (f32)D_001D9504, 0.041666668f, 0.041666668f, 5.0000005f);
            func_0038D290(a, a, len);
            __asm__("lqc2 %0, %1" : "=j"(v1) : "m"(*(V4_3DCD08 *)a));
            __asm__("lqc2 %0, %1" : "=j"(v2) : "m"(D_001D9E90));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(v1) : "j"(v1), "j"(v2));
            __asm__("sqc2 %1, %0" : "=m"(D_00222480[0]) : "j"(v1));
            func_003E3A20(&D_00306D80_003E24C8.f70, 0);
            if ((f32)D_001D9504 <= len) {
                D_00306D80_003E24C8.f58 = 2;
            }
            break;
        }
        case 2: {
            P_3DCD08 *p;
            if (D_001D545C != 0xB) {
                D_001D9DD0 = 3;
            }
            p = D_001D52FC;
            if (p->f148 != 0.0f || p->f14C != 0.0f) {
                *(Q_3DCD08 *)b = 0;
                b[1] = p->f148;
                b[2] = p->f14C;
                *(Q_3DCD08 *)a = *(Q_3DCD08 *)b;
                func_0038D328(a, a, &D_00222480[2]);
                func_003C4E00(a, 1.0f);
                func_0038D148(a, a, (f32)-D_001D9504 * (D_001D9508 * 0.017453292f * 0.016666668f));
                func_003E3BF0(a);
            }
            func_003E3A20(&D_00306D80_003E24C8.f70, 1);
            func_003E3B68((f32 *)&D_001D52FC->f100);
            break;
        }
        case 3: {
            f32 s, ang;
            Q_3DCD08 v1, v2;
            if (D_001D545C != 0xB) {
                D_001D9DD0 = 3;
            }
            s = (f32)D_001D9504;
            ang = s * (D_001D9508 * 0.017453292f * 0.016666668f);
            { Q_3DCD08 x, y, r;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_00306D80_003E24C8.v0));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001D9E90));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(*(V4_3DCD08 *)b) : "j"(r)); }
            func_0038D290(b, b, s);
            { Q_3DCD08 x, y, r;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001D9E90));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3DCD08 *)b));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(*(V4_3DCD08 *)b) : "j"(r)); }
            { Q_3DCD08 x, y, r;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3DCD08 *)b));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_00222480[0]));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(*(V4_3DCD08 *)a) : "j"(r)); }
            func_0038D8D8(m, &D_00222480[2]);
            func_0038D328(a, a, m);
            a[0] = 0.0f;
            if (a[1] == a[0] && a[2] == a[0]) {
                a[1] = 1.0f;
            }
            func_003C4E00(a, ang);
            func_0038D328(a, a, &D_00222480[2]);
            func_003E3BF0(a);
            func_003E3A20(&D_00306D80_003E24C8.f70, 1);
            if (func_0038D1D0(a) < ang - 0.01f) {
                D_001D9DD4 = 2;
                *(Q_3DCD08 *)&D_00306D80_003E24C8.v20 = *(Q_3DCD08 *)&D_00222480[0];
                func_003C4B20(&D_00222480[2], &D_00306D80_003E24C8.v30);
                D_00306D80_003E24C8.f58 = 4;
            }
            break;
        }
        case 4: {
            if (D_001D545C != 0xB) {
                D_001D9DD0 = 3;
            }
            func_003C4420(&D_00306D80_003E24C8.f6C, &D_00306D80_003E24C8.f70, 1.0f, 0.00055555557f, 0.00055555557f, 0.025000002f);
            func_0038D120(D_00222480, &D_00306D80_003E24C8.v20, &D_00306D80_003E24C8.v0, D_00306D80_003E24C8.f6C);
            func_003C4240(a, &D_00306D80_003E24C8.v30);
            func_003C4240(b, &D_00306D80_003E24C8.v10);
            func_0038D9F0(m, a, b, D_00306D80_003E24C8.f6C);
            func_0038DB38(m, &D_00222480[2]);
            if (1.0f <= D_00306D80_003E24C8.f6C) {
                func_003A1258(0, 0);
            }
            break;
        }
        }
        D_00306D80_003E24C8.f7E = 1;
        if ((D_001D52FC->f1A4 & 0x500) && D_00306D80_003E24C8.f58 == 2) {
            D_00306D80_003E24C8.f58 = 3;
            *(s32 *)&D_00306D80_003E24C8.f6C = 0;
            D_00306D80_003E24C8.f70 = 0;
        }
        if (D_001D545C == 0x16 || D_001D545C == 0x17) {
            E_3DCD08 *e;
            for (e = D_001DA51C; e < D_001DA520; e++) {
                if (e->fAA == 0xD3D && e->f64 != 0) {
                    e->f64(e);
                }
            }
        }
        break;
    case 7:
        switch (D_00306D80_003E24C8.f58) {
        case 0:
            D_00306D80_003E24C8.f7E = 1;
            D_00306D80_003E24C8.f58 = 1;
            if (D_001A71C4[0] != 1) {
                func_00381C90();
            }
            D_001D94D0 = D_001D94D4;
            D_001D94D8 = 0;
            func_00397EC8();
            func_003E4078();
            break;
        case 1:
            if (D_001A71C4[0] != 1) {
                func_00381C90();
                func_00393668(0x23, 0, func_00393EF8, func_00393F50, func_00394918, 0, 0);
            } else {
                func_00393668(0x23, 0, func_00395240, func_00395288, func_00395770, 0, 0);
            }
            func_003AFA50();
            func_003E3D20();
            func_003E4F80(0x168);
            func_003E5750(0xB4);
            func_00397EC8();
            D_001D94D0 = D_001D94D0 > 0 ? --D_001D94D0 : D_001D94D0;
            if (--D_001D94F0 < 0) {
                D_001D94F0 = 0;
            }
            if (D_001D94F0 == 0) {
                D_00306D80_003E24C8.f58++;
            }
            break;
        case 2:
            if (D_001A71C4[0] != 1) {
                func_00381C90();
                func_00393668(0x23, 0, func_00393EF8, func_00393F50, func_00394918, 0, 0);
            } else {
                func_00393668(0x23, 0, func_00395240, func_00395288, func_00395770, 0, 0);
            }
            func_003AFA50();
            func_003E4F80(0x168);
            func_003E5750(0xB4);
            func_00397EC8();
            D_001D94D0 = D_001D94D0 > 0 ? --D_001D94D0 : D_001D94D0;
            if (D_001D94D0 <= 0) {
                D_001D94D0 = 0;
                D_00306D80_003E24C8.f58++;
            }
            break;
        case 3:
            if (D_001A71C4[0] != 1) {
                func_00381C90();
            }
            func_00397F80();
            func_00397F78();
            func_003A1258(0, 0);
            break;
        }
        break;
    case 8:
        switch (D_00306D80_003E24C8.f58) {
        case 0:
        case 1:
            D_00306D80_003E24C8.f58++;
            break;
        case 2:
            func_003A1180(3, 2, D_00306D80_003E24C8.f54, 0, 0);
            func_003A1160(3);
            D_00306D80_003E24C8.f58++;
            break;
        case 3:
            break;
        }
        break;
    case 9:
        switch (D_00306D80_003E24C8.f58) {
        case 0:
            func_003E4090();
            D_00306D80_003E24C8.f58++;
            break;
        case 1: {
            s32 m = D_001D52FC->f1C4;
            if (m & D_00306D80_003E24C8.f8C) {
                D_00306D80_003E24C8.f84 = 2;
                func_003A1258(0, 0);
                break;
            }
            if (m & D_00306D80_003E24C8.f90) {
                D_00306D80_003E24C8.f84 = 1;
                func_003A1258(0, 0);
            }
            break;
        }
        }
        break;
    case 10:
        switch (D_00306D80_003E24C8.f58) {
        case 0:
            func_003E4090();
            D_00306D80_003E24C8.f58++;
            break;
        case 1:
            if (D_001D52FC->f1C4 & D_00306D80_003E24C8.f8C) {
                D_00306D80_003E24C8.f84 = 2;
                func_003A5608(0x12, 0, 0);
                func_003A1258(0, 0);
            }
            break;
        }
        break;
    case 11:
        switch (D_00306D80_003E24C8.f58) {
        case 0:
            func_003E4090();
            D_00306D80_003E24C8.f58++;
            if (D_001D5520_003E24C8 != 0) {
                D_001D5520_003E24C8 = D_001D5520_003E24C8 == 0;
                func_003E15E0();
                func_003A1258(D_00306D80_003E24C8.f54, 0);
            }
            break;
        case 1:
            if (D_001D52FC->f1C4 & 0x40) {
                D_00306D80_003E24C8.f84 = 2;
                D_00306D80_003E24C8.f58++;
                break;
            }
            if (D_001D52FC->f1C0 & 0x10) {
                D_00306D80_003E24C8.f84 = 1;
                func_003A1258(D_00306D80_003E24C8.f54, 0);
            }
            break;
        case 2:
            D_00306D80_003E24C8.f5C = 900;
            D_00306D80_003E24C8.f58++;
            D_00306D80_003E24C8.f60 = 0;
            D_00306D80_003E24C8.f84 = 0;
            D_001D5520_003E24C8 = D_001D5520_003E24C8 == 0;
            func_003E15E0();
            break;
        case 3: {
            s32 t = D_001D52FC->f1C4;
            if (t & 0x20) {
                D_00306D80_003E24C8.f84 = 2;
            } else if (t & 0x10) {
                D_00306D80_003E24C8.f84 = 1;
            }
            if (--D_00306D80_003E24C8.f5C <= 0 || D_00306D80_003E24C8.f84 != 0) {
                D_00306D80_003E24C8.f58++;
            }
            break;
        }
        case 4:
            switch (D_00306D80_003E24C8.f84) {
            case 0:
            case 1:
                D_001D5520_003E24C8 = D_001D5520_003E24C8 == 0;
                func_003E15E0();
                break;
            case 2:
                break;
            }
            D_00306D80_003E24C8.f58++;
            break;
        case 5:
            func_003A1258(D_00306D80_003E24C8.f54, 0);
            break;
        }
        break;
    case 12:
        func_00385140();
        break;
    }
}
/* localdecomp:end func_003E24C8 */

/* localdecomp:start func_003E3A20 */
__asm__(".extern D_001D9580, 4");
extern s32 D_001D9580;
extern void func_0038D630(void *, void *);
extern void func_0038D918(void *, void *, void *);
extern void func_0038D1B8(void *, void *, void *);
extern void func_003C4F38(void *, void *, f32);
extern void func_003C45E0(void *, f32, f32, f32, f32);
extern f32 D_002224A0[];
void func_003E3A20(void *o, s32 flag) {
    f32 *obj = (f32 *)o;
    f32 z[12];
    f32 c[12];
    f32 b[12];
    V4_3DCD08 d;
    V4_3DCD08 a;
    u128_t va, vb;
    f32 h;
    __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(D_001D9E90));
    __asm__("lqc2 %0, %1" : "=j"(va) : "m"(D_00222480[0]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(va));
    func_0038D290(&a, &a, 1.0f);
    func_0038D630(b, &D_001D9580);
    func_0038D918(c, &D_00222480[2], b);
    func_0038D1B8(&d, c, &a);
    h = func_0038D1D0(&d) * 0.5f;
    if (flag) {
        func_003C4F38(&d, &d, -h);
    } else {
        func_003C45E0(obj, h, 0.000581776432f, 0.000581776432f, 0.0523598827f);
        func_003C4F38(&d, &d, -*obj);
    }
    func_0038DB38(&d, z);
    func_0038D918(D_002224A0, z, D_002224A0);
}
/* localdecomp:end func_003E3A20 */

/* localdecomp:start func_003E3B68 */
__asm__(".extern D_001D950C, 4");
extern f32 D_001D950C;
extern f32 D_002224A0[];
extern void func_003C4F38();
extern void func_0038DB38();
extern void func_0038D918();
void func_003E3B68(f32 *arg0) {
    f32 a[4];
    f32 b[12];
    ((void (*)(f32 *, f32 *, f32))func_003C4F38)(a, D_002224A0, *arg0 * (D_001D950C * 0.017453292f * 0.016666668f));
    func_0038DB38(a, b);
    func_0038D918(D_002224A0, b, D_002224A0);
}
/* localdecomp:end func_003E3B68 */

/* localdecomp:start func_003E3BF0 */
__asm__(".extern D_001D9504, 4");
void func_003E3BF0(void *a) {
    u128_t va, vb;
    __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(D_001D9E90));
    __asm__("lqc2 %0, %1" : "=j"(va) : "m"(D_00222480[0]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
    __asm__("sqc2 %1, %0" : "=m"(D_00222480[0]) : "j"(va));
    __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(*(V4_3DCD08 *)a));
    __asm__("lqc2 %0, %1" : "=j"(va) : "m"(D_00222480[0]));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
    __asm__("sqc2 %1, %0" : "=m"(D_00222480[0]) : "j"(va));
    func_0038D290(D_00222480, D_00222480, (f32)D_001D9504);
    __asm__("lqc2 %0, %1" : "=j"(va) : "m"(D_00222480[0]));
    __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(D_001D9E90));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
    __asm__("sqc2 %1, %0" : "=m"(D_00222480[0]) : "j"(va));
}
/* localdecomp:end func_003E3BF0 */

/* localdecomp:start func_003E3C60 */
extern void func_0038D1B8(void *, void *, void *);
extern u8 D_00306E50[];
void func_003E3C60(void *a) {
    V4_3DCD08 v;
    u128_t va, vb;
    __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(D_00222480[0]));
    __asm__("lqc2 %0, %1" : "=j"(va) : "m"(*(V4_3DCD08 *)a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(va));
    func_0038D290(&D_00222480[2], &v, 1.0f);
    func_0038D1B8(&D_00222480[3], &D_00222480[2], D_00306E50);
    func_0038D290(&D_00222480[3], &D_00222480[3], 1.0f);
    func_0038D1B8(&D_00222480[4], &D_00222480[2], &D_00222480[3]);
    func_0038D290(&D_00222480[4], &D_00222480[4], -1.0f);
}
/* localdecomp:end func_003E3C60 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E3D18);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E3D20);

/* localdecomp:start func_003E4030 */
typedef struct { u8 pad[0x40]; s32 f40; u8 pad2[0x14]; s32 f58; } S_302D80;
extern S_302D80 D_00306D80;
 
void func_003E4030(void) {
    S_302D80 *s = &D_00306D80;
    if (s->f40 == 7 && s->f58 == 1) {
        s->f58 = 2;
    }
}
/* localdecomp:end func_003E4030 */

/* localdecomp:start func_003E4060 */
extern s32 D_00306DC0[];
s32 func_003E4060(void) {
    return D_00306DC0[0] == 7;
}
/* localdecomp:end func_003E4060 */

/* localdecomp:start func_003E4078 */
extern s32 D_001D94F0;
void func_003E4078(void) {
    D_001D94F0 = 3;
}
/* localdecomp:end func_003E4078 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E4088);

/* localdecomp:start func_003E4090 */
extern s16 D_00306E04[];
 
void func_003E4090(void) {
    D_00306E04[0] = 0;
}
/* localdecomp:end func_003E4090 */

/* localdecomp:start func_003E40A0 */
void *func_003E40A0(void *p) {
    return (u8 *)p + 0xED1C;
}
/* localdecomp:end func_003E40A0 */

/* localdecomp:start func_003E40B0 */
__asm__(".extern D_001D9590, 4");
__asm__(".extern D_001D9598, 4");

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

extern s32 D_001D9590;
extern f32 D_001D9598;
extern W_3DE8F0 D_1A4BE0[];
extern F_3DE8F0 D_142CA0[];
extern s32 D_00142668[];
extern s32 D_001DA868[2];
extern char D_001D95A0[];

extern R_3DE8F0 *func_00382748(M_3DE8F0 *);
extern s32 func_0038DF00(s32, s32, f32);
extern f32 func_0038D3C0(f32);
extern s32 func_003E40A0(s32);
extern void func_003E52E0(f32 *, f32);
extern s32 func_003E7610(s32, f32, f32);
extern s32 func_003E8448(s32, f32, f32);
extern s32 func_003E7C70(s32, s32);
extern s32 func_003E80A0(s32, s32);
extern s32 func_003E7A90(s32, s32, s32);
extern s32 func_003E7FC8(s32, s32);
extern s32 func_003E7DD8_003E40B0(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_11B2E8(void *, char *, s32);

void func_003E40B0(void) {
    s32 ammo, max, max2, d0, d1, d2, hund, color;
    f32 fammo, fmax, w2, x, t, b, v;
    f32 x0, y, x1;
    f32 sum;
    R_3DE8F0 *r;
    s16 h;

    ammo = D_1A4BE0->x2850;
    if ((D_1A4BE0->x25E4 ^ 1) == 0) {
        max = 4;
    } else {
        max = D_00142668[0];
    }
    max2 = max;
    if (D_1A4BE0->x25C4 == 0x31 && D_1A4BE0->x19E0 != 0) {
        h = D_1A4BE0->x19E0->xAA;
        if ((h == 0x1A17 || h == 0x107E) && (r = func_00382748(D_1A4BE0->x19E0)) != 0) {
            max2 = 100;
            ammo = r->f0 * 100.0f / r->h4;
        }
    }
    fammo = ammo;
    fmax = max2;
    if (!D_142CA0->x20) {
        f32 w;
        w = fammo / fmax * 0.230333f;
        func_003E52E0(&w, 0.230333f);
        func_003E8448(0x9000A, 0.230333f - w, 0.049333f);
        func_003E7610(0x9000A, 0.61558104f, 0.0739995f);
        func_003E8448(0x9000B, w, 0.049333f);
        func_003E7610(0x9000B, 0.385248f, 0.0739995f);
        func_003E7C70(0x90008, 0);
    } else {
        f32 w;
        w = fammo / fmax * 0.226833f;
        func_003E52E0(&w, 0.226833f);
        func_003E8448(0x9000A, 0.226833f - w, 0.049333f);
        func_003E7610(0x9000A, 0.587748f, 0.0739995f);
        func_003E8448(0x9000B, w, 0.049333f);
        func_003E7610(0x9000B, 0.360915f, 0.0739995f);
        func_003E7C70(0x90008, 1);
        func_003E7610(0x90008, 0.598917f, 0.074f);
    }
    w2 = 0.09f;
    d0 = func_003E40A0(ammo % 10);
    d1 = func_003E40A0(ammo / 10 % 10);
    hund = ammo / 100 % 10 != 0;
    d2 = func_003E40A0(ammo / 100 % 10);
    func_003E80A0(0x90003, d0);
    func_003E80A0(0x90004, d1);
    func_003E80A0(0x90005, d2);
    func_003E7A90(0x90005, 1, hund);
    if (hund) {
        w2 = 0.135f;
    }
    func_11B2E8(D_001DA868, D_001D95A0, max2);
    x0 = 0.0f;
    x1 = 0.0f;
    func_003E7DD8_003E40B0(0x90006, &x0, &y, &x1, &y);
    sum = w2 + (x1 - x0);
    t = 0.5f;
    if (D_142CA0->x20) {
        t = 0.475f;
    }
    x = t - sum * 0.5f;
    if (hund) {
        func_003E7610(0x90005, x, 0.074f);
        x += 0.045f;
    }
    func_003E7610(0x90004, x, 0.074f);
    x += 0.045f;
    func_003E7610(0x90003, x, 0.074f);
    func_003E7610(0x90006, x + 0.045f, 0.069f);
    if (fammo < fmax * 0.15f) {
        b = D_001D9598 + 0.05f;
        D_001D9598 = b;
        if (b >= 2.0f) {
            D_001D9598 = b - 2.0f;
        }
        D_001D9590++;
    } else {
        if (D_001D9598 > 1.0f) {
            D_001D9598 = 2.0f - D_001D9598;
        }
        D_001D9598 = D_001D9598 * 0.95f;
    }
    v = D_001D9598 > 1.0f ? 2.0f - D_001D9598 : D_001D9598;
    color = func_0038DF00(0x8066CCFF, 0x60202080, (1.0f - func_0038D3C0(v * 3.1415927f)) * 0.5f);
    func_003E7FC8(0x90003, color);
    func_003E7FC8(0x90004, color);
    func_003E7FC8(0x90005, color);
    func_003E7FC8(0x90006, color);
}
/* localdecomp:end func_003E40B0 */

/* localdecomp:start func_003E46B0 */
typedef struct { u8 pad[0x28B4]; s32 a; s32 b; } S_003DEEF0;
extern S_003DEEF0 D_001A4BE0;
extern s32 D_00142694[];
extern void func_00381C68();
extern s32 func_003E8448(s32, f32, f32);
s32 func_003E46B0(void) {
    s32 l[3];
    s32 pos;
    f32 den;
    f32 num;
    f32 t;
    pos = D_00142694[0] >> 5;
    l[0] = D_001A4BE0.b;
    l[1] = D_001A4BE0.a;
    if (l[0] == 0) {
        l[2] = 0;
        func_00381C68(l, l + 1, l + 2);
    }
    num = (f32)(pos - l[0]);
    den = (f32)(l[1] - l[0]);
    t = (den <= 0.0f) ? 0.0f : num / den;
    return func_003E8448(0x90007, t * 0.1285f, 0.008f);
}
/* localdecomp:end func_003E46B0 */

/* localdecomp:start func_003E4778 */
extern u8 D_00142CC0[];
extern u8 D_001426E0[];
extern s32 func_003E8448(s32, f32, f32);
void func_003E4778(void) {
    if (D_00142CC0[0]) {
        u8 *s = D_001426E0;
        f32 r = 0.0f;
        if (s[0xD4]) r = (f32)s[0xD3] / (f32)s[0xD4];
        func_003E8448(0x90008, r * 0.0430830009f, 0.0504160002f);
    }
}
/* localdecomp:end func_003E4778 */

/* localdecomp:start func_003E47F8 */
__asm__(".extern D_001D9594, 1");
__asm__(".extern D_001D959D, 1");
__asm__(".extern D_001D959C, 1");
__asm__(".extern D_001D97A0, 4");
typedef struct { s32 x0, x4, x8, xC; } S_3DF038;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3DF038;
typedef struct { u8 pad[8]; VT_3DF038 *vt; u8 padC[0x3E]; s16 x4A; } W_3DF038;

extern u8 D_001D9594;
extern u8 D_001D959D;
extern u8 D_001D959C;
extern s32 D_001D97A0;
extern s32 D_001DA868[2];
extern S_3DF038 D_001DA9B8[];

extern void func_003E7608_003E47F8(s32);
extern void func_0038CEA0(void *, s32, s32);
extern void func_003B5268(s32);
extern s32 func_003E5300(s32);
extern s32 func_003E5468(s32);
extern s32 func_003E55D0(s32);
extern s32 func_003823F0(s32);
extern s32 func_00392D38(void);
extern s32 func_003E9240(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9390(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7D20(s32, s32);
extern s32 func_003E7B80(s32, s32, s32);
extern s32 func_003E7A90(s32, s32, s32);
extern s32 func_003E8250(s32, s32, s32, s32, s32);
extern s32 func_003E8358(s32, s32, s32);
extern s32 func_003E7610(s32, f32, f32);
extern s32 func_003E77E8(s32, f32, f32);
extern s32 func_003E8448(s32, f32, f32);
extern s32 func_003E8178(s32, s32);
extern s32 func_003E7FC8(s32, s32);
extern s32 func_003E7EE8_003E47F8(s32, void *);
extern s32 func_003E80A0(s32, s32);
extern s32 func_003E8888(s32, s32);
extern s32 func_003E85A0(s32, s32);
extern void func_003E7260_003E47F8(s32, s32);
extern void func_003E40B0(void);
extern S_3DF038 *func_003E6E78_003E47F8(S_3DF038 *);
extern s32 func_003E7058_003E47F8(S_3DF038 *);
extern W_3DF038 *func_003E65E8(s32, s32);

void func_003E47F8(s32 arg0) {
    S_3DF038 *p;
    S_3DF038 *q;
    W_3DF038 *t;
    W_3DF038 *v;

    D_001D9594 = 1;
    func_003E7608_003E47F8(1);
    func_0038CEA0(D_001DA868, 0, 8);
    func_003B5268(0x90000);
    func_003E5300(0x90001);
    func_003E5300(0x90002);
    func_003E5468(0x90003);
    func_003E5468(0x90004);
    func_003E5468(0x90005);
    func_003E55D0(0x90006);
    func_003E5468(0x90007);
    func_003E9240(0x9000C, func_003823F0(0x182D), 0x8066CCFF, 0.4285f, 0.1315f, 0.6f, 0.6f);
    func_003E7D20(0x9000C, 1);
    func_003E9390(0x90008, 0x706EC8FF, 0, 0.598917f, 0.074f, 0.043083f, 0.050416f);
    func_003E7B80(0x90008, 1, 3);
    func_003E8250(0x90008, 0x601465B7, 0x6066CCFF, 0x601465B7, 0x6066CCFF);
    func_003E8358(0x90002, func_00392D38(), 0x8C);
    func_003E8358(0x90001, func_00392D38(), 0x8D);
    func_003E7610(0x90003, 0.487997f, 0.074f);
    func_003E7610(0x90004, 0.440497f, 0.074f);
    func_003E7610(0x90005, 0.39347f, 0.074f);
    func_003E7610(0x90006, 0.627999f, 0.069f);
    func_003E77E8(0x90006, 0.003f, 0.003f);
    func_003E8178(0x90006, 1);
    func_003E7610(0x90007, 0.464136f, 0.1335f);
    func_003E8448(0x90003, 0.035f, 0.035f);
    func_003E8448(0x90004, 0.035f, 0.035f);
    func_003E8448(0x90005, 0.035f, 0.035f);
    func_003E8448(0x90006, 1.0f, 1.0f);
    func_003E8448(0x90007, 0.0f, 0.008f);
    func_003E7FC8(0x90001, 0x331465B7);
    func_003E7FC8(0x90002, 0x332299DE);
    func_003E7FC8(0x90003, 0x8066CCFF);
    func_003E7FC8(0x90004, 0x8066CCFF);
    func_003E7FC8(0x90005, 0x8066CCFF);
    func_003E7FC8(0x90006, 0x8066CCFF);
    func_003E7FC8(0x90007, 0x706EC8FF);
    func_003E7EE8_003E47F8(0x90006, D_001DA868);
    func_003E7B80(0x90006, 1, 1);
    func_003E7B80(0x90007, 1, 3);
    func_003E7A90(0x90006, 0x40, 1);
    func_003E7A90(0x90003, 0x40, 1);
    func_003E7A90(0x90004, 0x40, 1);
    func_003E7A90(0x90005, 0x40, 1);
    func_003E7B80(0x90003, 1, 3);
    func_003E7B80(0x90004, 1, 3);
    func_003E7B80(0x90005, 1, 3);

    func_003E80A0(0x90003, 0xED1C);
    p = D_001DA9B8;
    if (p->x4) q = p; else q = func_003E6E78_003E47F8(p);
    t = func_003E65E8(func_003E7058_003E47F8(q), 0x90003);
    v = (t != 0 && t->vt->isA(t, D_001D97A0) != 0) ? t : 0;
    v->x4A = 0;

    func_003E80A0(0x90004, 0xED1D);
    p = D_001DA9B8;
    if (p->x4) q = p; else q = func_003E6E78_003E47F8(p);
    t = func_003E65E8(func_003E7058_003E47F8(q), 0x90004);
    v = (t != 0 && t->vt->isA(t, D_001D97A0) != 0) ? t : 0;
    v->x4A = 0;

    func_003E80A0(0x90005, 0xED1E);
    p = D_001DA9B8;
    if (p->x4) q = p; else q = func_003E6E78_003E47F8(p);
    t = func_003E65E8(func_003E7058_003E47F8(q), 0x90005);
    v = (t != 0 && t->vt->isA(t, D_001D97A0) != 0) ? t : 0;
    v->x4A = 0;

    func_003E9390(0x9000A, 0x59000000, 0, 0.61558104f, 0.0739995f, 0.230333f, 0.049333f);
    func_003E7B80(0x9000A, 2, 3);
    func_003E9390(0x9000B, 0x59000000, 0, 0.385248f, 0.0739995f, 0.230333f, 0.049333f);
    func_003E7B80(0x9000B, 1, 3);
    func_003E8250(0x9000B, 0x601465B7, 0x6066CCFF, 0x601465B7, 0x6066CCFF);
    func_003E8888(0x90000, 0x90001);
    func_003E8888(0x90000, 0x90002);
    func_003E8888(0x90000, 0x9000A);
    func_003E8888(0x90000, 0x9000B);
    func_003E8888(0x90000, 0x90006);
    func_003E8888(0x90000, 0x90007);
    func_003E8888(0x90000, 0x90008);
    func_003E8888(0x90000, 0x90003);
    func_003E8888(0x90000, 0x90004);
    func_003E8888(0x90000, 0x90005);
    func_003E8888(0x90000, 0x9000C);
    func_003E85A0(7, 0x90000);
    func_003E7260_003E47F8(arg0, 1);
    func_003E40B0();
    func_003E7608_003E47F8(0);
    D_001D959D = 0;
    D_001D959C = 1;
}
/* localdecomp:end func_003E47F8 */

/* localdecomp:start func_003E4F80 */
extern u8 D_001D9594;
extern u8 D_001D95A6;
extern s32 D_001D9590;
extern s32 func_003E7A90(s32, s32, s32);
extern s32 func_003E51A0(s32);
extern void func_003E5118();
void func_003E4F80(s32 a) {
    if (D_001D9594 != 0 && D_001D95A6 == 0) {
        D_001D9590 = a;
        func_003E7A90(0x90000, 1, a != 0);
        func_003E5118(func_003E51A0(0));
    }
}
/* localdecomp:end func_003E4F80 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E4FD0);

/* localdecomp:start func_003E4FE0 */
__asm__(".extern D_001D959D, 1");
__asm__(".extern D_001D959C, 1");
extern u8 D_001D959D;
extern u8 D_001D959C;
extern s32 func_00392D38(void);
extern s32 func_003E8358(s32, s32, s32);
extern s32 func_003E7610(s32, f32, f32);
extern s32 func_003E8448(s32, f32, f32);
void func_003E4FE0(s32 arg0) {
    F_3DE8F0 *g = D_142CA0;
    s32 a, b;
    D_001D959C = (g->x20 != D_001D959D);
    if (D_001D959C) {
        a = g->x20 ? 0x8E : 0x8C;
        b = g->x20 ? 0x8F : 0x8D;
        D_001D959D = g->x20 != 0;
        func_003E8358(0x90002, func_00392D38(), a);
        func_003E8358(0x90001, func_00392D38(), b);
        func_003E7610(0x9000C, g->x20 ? 0.4025f : 0.4285f, 0.1315f);
        func_003E8448(0x9000C, 0.6f, 0.6f);
        func_003E7610(0x90007, g->x20 ? 0.4394f : 0.464136f, 0.1335f);
    }
}
/* localdecomp:end func_003E4FE0 */

/* localdecomp:start func_003E5118 */
extern s32 D_001D9590;
extern u8 D_001D95A6;
extern void func_003E4FE0(s32);
extern void func_003E40B0(void);
extern void func_003E46B0(void);
extern void func_003E4778(void);
extern s32 func_003E7A90(s32, s32, s32);
void func_003E5118(void) {
    if (D_001D9590 != 0 && D_001D95A6 == 0) {
        D_001D9590--;
        func_003E4FE0(0x90000);
        func_003E40B0();
        func_003E46B0();
        func_003E4778();
    } else {
        func_003E7A90(0x90000, 1, 0);
    }
}
/* localdecomp:end func_003E5118 */

/* localdecomp:start func_003E5180 */
extern u8 D_001D9594;
extern s32 func_003E8800();
void func_003E5180(void) {
    D_001D9594 = 0;
    func_003E8800(7);
}
/* localdecomp:end func_003E5180 */

/* localdecomp:start func_003E51A0 */
typedef struct { u8 b[16]; } V16_3DF9E0;
extern void func_003E47F8(s32);
extern void func_003E5180(void);
extern void func_003E5118(void);
extern s32 func_003E7210(s32 *, s32, s32, s32, s32, s32);
extern s32 D_001DA800;
extern s32 D_001DA820;
extern s32 D_001DA840;
extern s32 D_001DA860;
extern s32 D_001DA7E8[2];
extern s32 D_001DA808[2];
extern s32 D_001DA828[2];
extern s32 D_001DA848[2];
extern V16_3DF9E0 D_001D95A8[];
s32 func_003E51A0(s32 idx) {
    V16_3DF9E0 v;
    if (D_001DA800 == 0) {
        func_003E7210(D_001DA7E8, (s32)func_003E47F8, (s32)func_003E5180, (s32)func_003E5118, 0, 0);
        D_001DA800 = 1;
    }
    if (D_001DA820 == 0) {
        func_003E7210(D_001DA808, (s32)func_003E47F8, (s32)func_003E5180, (s32)func_003E5118, 0, 0);
        D_001DA820 = 1;
    }
    if (D_001DA840 == 0) {
        func_003E7210(D_001DA828, (s32)func_003E47F8, (s32)func_003E5180, (s32)func_003E5118, 0, 0);
        D_001DA840 = 1;
    }
    if (D_001DA860 == 0) {
        func_003E7210(D_001DA848, (s32)func_003E47F8, (s32)func_003E5180, (s32)func_003E5118, 0, 0);
        D_001DA860 = 1;
    }
    v = D_001D95A8[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_003E51A0 */

/* localdecomp:start func_003E52E0 */
void func_003E52E0(f32 *p, f32 a) {
    *p = (a < *p) ? a : *p;
}
/* localdecomp:end func_003E52E0 */

/* localdecomp:start func_003E5300 */
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E6F30();
extern s32 func_003E5B68();
extern void func_003E65B8(void **, s32, s32);
extern void *func_003F1EA0();
extern s32 func_003F2580();
extern void func_003E75F8(s32);
extern s32 func_003E7600();
s32 func_003E5300(s32 a) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA9B8;
    if (!q->x4) q = func_003E6E78();
    obj = func_003E7058(q);
    func_003E75F8(0x48);
    vv = func_003E7600();
    if (obj != 0) {
        if (func_003E5B68(obj, a) == 0) {
            p = D_001DA9B8;
            if (p->x4) q = p;
            else q = func_003E6E78(p);
            t1 = func_003E6F30(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003F1EA0(func_003F2580(0x48, e));
                r = ((s32 (*)())func_003E65B8)(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA9B8;
                    if (p->x4) q = p;
                    else q = func_003E6E78(p);
                    w = func_003E6F30(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E5300 */

/* localdecomp:start func_003E5468 */
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E6F30();
extern s32 func_003E5B68();
extern void func_003E65B8(void **, s32, s32);
extern void *func_003EF368();
extern s32 func_003F2580();
extern void func_003E75F8(s32);
extern s32 func_003E7600();
s32 func_003E5468(s32 a) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA9B8;
    if (!q->x4) q = func_003E6E78();
    obj = func_003E7058(q);
    func_003E75F8(0x54);
    vv = func_003E7600();
    if (obj != 0) {
        if (func_003E5B68(obj, a) == 0) {
            p = D_001DA9B8;
            if (p->x4) q = p;
            else q = func_003E6E78(p);
            t1 = func_003E6F30(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003EF368(func_003F2580(0x54, e));
                r = ((s32 (*)())func_003E65B8)(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA9B8;
                    if (p->x4) q = p;
                    else q = func_003E6E78(p);
                    w = func_003E6F30(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E5468 */

/* localdecomp:start func_003E55D0 */
typedef struct { u8 pad[8]; s32 (*f8)(); s32 (*fC)(); } VT_3DFE10;
typedef struct { VT_3DFE10 *vt; } O_3DFE10;
typedef struct { u8 pad[8]; VT_3DFE10 *vt; } D_3E55D0;
extern void *func_003E6E78();
extern s32 func_003E7058();
extern void func_003E75F8(s32);
extern s32 func_003E7600(void);
extern s32 func_003E5B68();
extern s32 func_003E6F30();
extern s32 func_003F2580(s32, s32);
extern void *func_003F0170();
extern void func_003E65B8(void **, s32, s32);
s32 func_003E55D0(s32 arg0) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 a, b, c, r;
    D_3E55D0 *d;
    O_3DFE10 *o;
    r = 0;
    q = D_001DA9B8;
    if (!q->x4) q = func_003E6E78();
    a = func_003E7058(q);
    func_003E75F8(0x64);
    b = func_003E7600();
    if (a != 0) {
        if (func_003E5B68(a, arg0) == 0) {
            p = D_001DA9B8;
            if (p->x4) q = p; else q = func_003E6E78(p);
            o = (O_3DFE10 *)func_003E6F30(q, 1);
            c = o->vt->f8(o, b);
            if (c != 0) {
                d = func_003F0170(func_003F2580(0x64, c));
                r = ((s32 (*)())func_003E65B8)(a, d, arg0) != 0;
                if (r == 0) {
                    ((void (*)())d->vt->f8)(d, 2);
                    p = D_001DA9B8;
                    if (p->x4) q = p; else q = func_003E6E78(p);
                    o = (O_3DFE10 *)func_003E6F30(q, 1);
                    o->vt->fC(o, c);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E55D0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E5738);

/* localdecomp:start func_003E5750 */
extern u8 D_001D95C0;
extern s32 D_001D95B8;
extern s32 func_003E7A90(s32, s32, s32);
void func_003E5750(s32 a) {
    if (D_001D95C0 != 0) {
        D_001D95B8 = a;
        func_003E7A90(0x10000, 1, a != 0);
    }
}
/* localdecomp:end func_003E5750 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E5780);

/* localdecomp:start func_003E5790 */
extern u8 D_001A71C4[];
extern s32 D_001D5B90;
extern s32 D_001D5B94;
extern s32 D_001D9C88;
extern s32 D_001D9C8C;
extern s32 D_001D9C90;
extern s32 D_001D9C94;
extern s32 D_001D9CB8;
extern s32 D_001D9CC0;
extern s16 D_001D9F34;
extern s16 D_001D9F36;
extern s16 D_001D9F38;
extern s16 D_001D9F3A;
extern s16 D_001D9F3C;

void func_003E5790(void) {
    D_001D9C88 = 0;
    D_001D9C90 = 0;
    D_001D9C94 = 0;
    D_001D9C8C = 0;
    D_001D9CB8 = 0;
    D_001D9CC0 = 0;
    if ((D_001A71C4[0] == 1) && !((*(s32 *)((u8 *)(*(void **)0x1D52FC) + 0x1A0)) & 0x10) && (D_001D5B94 != 4) && (D_001D5B90 != 4)) {
        D_001D9F34 = 0;
        D_001D9F36 = 0;
        D_001D9F38 = 0;
        D_001D9F3A = 0;
        D_001D9F3C = 0;
    }
}
/* localdecomp:end func_003E5790 */

/* localdecomp:start func_003E5828 */
__asm__(".extern D_001D9608_003E5828, 4");
__asm__(".extern D_001D4C38_gp_003E0068, 4");
__asm__(".extern D_001D545C_003E5828, 4");
extern u8 *D_001D52FC_003E5828;
extern s32 D_001D9608_003E5828;
extern s32 D_001D4C38_gp_003E0068;
extern s32 D_001D4C38_003E5828;
extern s32 D_001D545C_003E5828;
extern s32 D_001D9D80_003E5828;
extern s32 D_001D5BC4_003E5828;
extern s32 D_001DA600_003E5828;
extern s32 D_001D9140_003E5828;
extern s32 D_001A91E8_003E5828[];
void func_003E5828(void) {
    u8 *o = D_001D52FC_003E5828;
    s32 *c;
    if (*(s32 *)(o + 0x1A0) != 0) {
        D_001D9608_003E5828 = 0;
    } else if (*(f32 *)(o + 0x108) != 0.0f) {
        D_001D9608_003E5828 = 0;
    } else if (*(f32 *)(o + 0x10C) != 0.0f) {
        D_001D9608_003E5828 = 0;
    } else if (*(f32 *)(o + 0x100) != 0.0f) {
        D_001D9608_003E5828 = 0;
    } else if (*(f32 *)(o + 0x104) != 0.0f) {
        D_001D9608_003E5828 = 0;
    } else {
        D_001D9608_003E5828 = D_001D9608_003E5828 + 1;
    }
    D_001D9D80_003E5828 += 1;
    D_001D4C38_gp_003E0068 = D_001D4C38_003E5828 + 1;
    if (D_001D5BC4_003E5828 != 0 && D_001D9608_003E5828 < 0x384) {
        c = &D_001A91E8_003E5828[D_001D545C_003E5828];
        *c += 1;
    }
    if (D_001DA600_003E5828 != D_001D4C38_003E5828 - 1) {
        D_001D9140_003E5828 = -1;
    }
}
/* localdecomp:end func_003E5828 */
TEXT_PADDING(2);

LINKER_REMNANT("asm/boot_elf/remnants", func_003E5938);
