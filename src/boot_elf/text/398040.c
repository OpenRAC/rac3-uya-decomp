#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00398040(s32, s32);
extern void func_003982E0(void);
extern void func_00399118(void);
extern void func_003A9560(s32);
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00398040 */
__asm__(".extern D_001D9FC8, 4");
extern s32 D_001D5F00[];
extern s32 D_001D5EE8[];
extern s32 D_001D9FCC;
extern s32 D_001D9FC8;
extern void func_13B0C8();
extern void func_00397FB8();
typedef struct { u8 pad[0x10]; s32 a; u16 b; u8 pad2[0x1A]; } S_3934E8;
void func_00398040(s32 x, s32 y) {
    S_3934E8 s;
    s32 *p;
    s32 *q;
    p = D_001D5EE8;
    q = &s.a;
    D_001D9FCC = (s32)q;
    s.a = D_001D5F00[0];
    s.b = ((u16 *)D_001D5F00)[2];
    D_001D9FC8 = (s32)&s;
    func_13B0C8((u8 *)q + 5);
    func_00397FB8(p, 2, &D_001D9FC8);
}
/* localdecomp:end func_00398040 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003980A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003980C0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003980C4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003980C8);

/* localdecomp:start func_003980F0 */
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern s32 func_001240E0();
extern void func_003980C8(void);
s32 func_003980F0(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 s[4];
    s32 h;
    s32 r;
    r = -1;
    s[0] = a;
    s[1] = c;
    s[2] = b;
    s[3] = 0;
    h = func_11F1E0(s, 1);
    if (h != 0) {
        do {} while (func_11F1C0(h) >= 0);
        r = func_001240E0(c, d, e);
    }
    func_003980C8();
    return r;
}
/* localdecomp:end func_003980F0 */

/* localdecomp:start func_003981A0 */
extern u8 D_00227600_003981A0[];
extern u8 D_3F35B7[];
extern u8 D_01FF8000[];
extern u8 D_01FFC000[];
extern u32 D_001DA0D8;
extern s32 func_0011A264(s32, s32, s32);
void func_003981A0(void) {
    u32 *s = (u32 *)D_00227600_003981A0;
    u32 c;
    func_0011A264((s32)s, 0, 0xA0);
    c = (u32)D_01FFC000;
    s[0] = 0;
    s[1] = 0x100000;
    s[2] = (u32)D_3F35B7 & 0xFFFFF000;
    s[3] = s[2];
    s[4] = s[3] + D_001DA0D8;
    s[5] = s[4] + D_001DA0D8;
    s[6] = s[5] + 0x100000;
    s[0x22] = (u32)D_01FF8000;
    s[0x21] = s[0x22] - 0x40000;
    s[0x20] = s[0x21] - 0x64000;
    s[0x1F] = s[0x20];
    s[0x1E] = s[0x1F] - 0x2C000;
    s[0x1D] = s[0x1E] - 0x8000;
    s[0x1C] = s[0x1D] - 0x14000;
    s[0x1A] = s[6];
    s[0x23] = c;
    s[0x1B] = s[0x1C];
    s[0x24] = 0x7000000;
    s[0x25] = 0x7100000;
    s[0x26] = 0x7180000;
    s[0x27] = 0x7200000;
}
/* localdecomp:end func_003981A0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003982C0);

/* localdecomp:start func_003982E0 */
typedef struct { s32 f0; u8 p4[0xA9]; u8 fAD; u8 pAE[9]; u8 fB7; } S_143950_3982E0;
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[8]; s32 f658; s32 f65C; } S_160C40_3982E0;
typedef struct { u8 p0[0x78]; s32 f78; } S_227600_3982E0;
typedef struct { u8 p0[0x24]; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; } S_1A1ED0_3982E0;
typedef struct { u8 p0[0x18]; s32 f18; u8 p1C[0x14]; s32 f30; } S_16C580_3982E0;
extern S_143950_3982E0 D_00143950_003982E0;
extern S_160C40_3982E0 D_160C40_003982E0;
extern S_227600_3982E0 D_227600_003982E0;
extern S_1A1ED0_3982E0 D_1A1ED0_003982E0;
extern S_16C580_3982E0 D_16C580_003982E0;
extern u8 D_001D551D;
extern s32 D_001D5520;
extern u8 D_001D5F08[];
extern u8 D_1FF8000[];
extern u8 D_0010F1A0[];
extern u8 D_1FEBEF8[];
extern u8 D_227740[];
extern u8 D_227480[];
extern s32 D_1D4B64;
extern s32 D_1D4B60;
extern s32 D_1D4B90;
extern s32 D_1D4BA0;
extern void func_0012A950(void);
extern s32 func_0012D678(s32);
extern void func_00391648(void);
extern void func_003A0518(void);
extern void func_00387ED0(s32);
extern void func_0013D208();
extern void func_0012D4D8(void *);
extern void func_003A92C0(void);
extern void func_003981A0(void);
extern void func_003A9378(void);
extern void func_003A9CB0(void);
extern void func_00388320(void);
extern void func_0012B300(s32);
extern void func_0012B800(s32);
extern s32 func_00124308(void *);
extern s32 func_001242B8(void);
extern void func_00121FE8(s32);
extern void func_00124920(void);
extern void func_00123B10(void);
extern void func_00124970(void);
extern s32 func_00123EA0(void);
extern void func_003982C0(void);
extern s32 func_001233F8(void);
extern s32 func_0013D290(s32, s32, void *);
extern void func_11F0A0(s32);
extern void func_0039C340_003982E0(void *);
extern void func_003A9200(u32);
extern void func_0013D2E0_003982E0(void *);
extern void func_003A0A20(u8 *, u32);
extern s32 func_00123B98(s32, s32, s32);
extern s32 func_003980F0(s32, s32, s32, s32, void *);
extern void func_003A87B8(void);
extern void func_003A2E80(void);
extern void func_0039E950(void);
extern void func_00387620(void);
extern void func_00387778();
extern void func_003980C8(void);
extern void func_003A4390(void);
extern void func_003A1590(void);
extern void func_0039A9A8(void);
extern s32 func_0013A880(void);
extern s32 func_0013A8E8(void);
extern void func_0038CEA0(void *, s32, s32);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
extern void func_003826C8(void);
extern s32 func_00398738(s32);
extern void func_00392D58(void *);
void func_003982E0(void) {
    u8 buf[0x800];
    s32 x;
    u8 *p;
    s32 r;
    s32 *m;
    func_0012A950();
    func_0012D678(1);
    if (D_001D551D == 0) {
        D_001D5520 = 0;
        D_00143950_003982E0.fAD = 0;
    }
    func_00391648();
    func_003A0518();
    func_00387ED0(1);
    func_0012D4D8(func_0013D208);
    func_003A92C0();
    func_003981A0();
    func_003A92C0();
    func_003A9378();
    func_003A9CB0();
    func_00388320();
    func_0012B300(0);
    func_0012B800(0);
    while (func_00124308(D_001D5F08) == 0);
    while (func_001242B8() == 0);
    func_00121FE8(0);
    func_00124920();
    func_00123B10();
    func_00124970();
    func_00123EA0();
    func_0012B300(0);
    func_0012B800(0);
    func_003982C0();
    func_001233F8();
    func_0013D290(0x3E8, 1, buf);
    func_11F0A0(0);
    D_00143950_003982E0.f0 = 0;
    func_0039C340_003982E0(buf);
    func_003A9200((u32)D_0010F1A0);
    func_0013D2E0_003982E0(D_1FEBEF8);
    {
        S_160C40_3982E0 *g = &D_160C40_003982E0;
        p = D_1FF8000 - (g->f65C << 11);
        func_0013D290(g->f658 + g->f64C, g->f65C, p);
    }
    func_11F0A0(0);
    func_003A0A20(p, 0x1000000);
    m = (s32 *)0x1000000;
    r = func_00123B98(0, 0x78000, 0);
    {
        s32 a0 = m[0x10] + (s32)m;
        s32 a1 = m[0x11];
        x = 0x8012FC00;
        func_003980F0(a0, a1, r, 0x51, (u8 *)&x - 1);
    }
    func_003A87B8();
    func_0012B800(0);
    func_003A2E80();
    {
        S_227600_3982E0 *t = &D_227600_003982E0;
        S_1A1ED0_3982E0 *a = &D_1A1ED0_003982E0;
        S_16C580_3982E0 *q = &D_16C580_003982E0;
        a->f28 = 0x60000;
        a->f2C = 0x70000;
        a->f30 = 0xB0000;
        a->f24 = 0;
        a->f34 = 0xF0000;
        D_1D4B60 = -1;
        a->f38 = 0x160000;
        a->f3C = 0x1D0000;
        a->f40 = 0x1E0000;
        D_1D4B64 = t->f78;
        D_1D4B90 = -1;
        D_1D4BA0 = -1;
        q->f30 = -1;
        q->f18 = -1;
    }
    func_0012B800(0);
    func_0039E950();
    func_00387620();
    func_00387778();
    func_003A9378();
    func_003980C8();
    func_0012B800(0);
    func_003A4390();
    func_003980C8();
    func_003A1590();
    func_003980C8();
    func_0039A9A8();
    if (D_001D551D == 0) {
        switch (func_0013A880()) {
        case 2: D_00143950_003982E0.fB7 = 2; break;
        case 3: D_00143950_003982E0.fB7 = 4; break;
        case 0:
        default: D_00143950_003982E0.fB7 = 0; break;
        }
    }
    if (D_001D551D == 0) {
        switch (func_0013A8E8()) {
        case 1: D_00143950_003982E0.fAD = 1; break;
        case 0: case 2: D_00143950_003982E0.fAD = 0; break;
        }
    }
    func_0038CEA0(D_227740, 0x80808080, 0x100);
    func_12C9A0(buf, 0x3FFB, 1, 0, 0, 0, 8, 8);
    func_11F0A0(0);
    func_12CCC8(buf, D_227740);
    func_12A9F0(0, 0);
    func_003826C8();
    func_00398738(0);
    *(volatile u32 *)0x10000810 = 0x82;
    *(volatile u32 *)0x10000800 = 0;
    func_00392D58(D_227480);
    func_003980C8();
}
/* localdecomp:end func_003982E0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00398738);

/* localdecomp:start func_00398760 */
/* MATCH */
extern u8 D_002FD170[];
extern s32 D_002FCF18[];
typedef struct { s32 a, b; } P_3936A8;
extern P_3936A8 D_002FC8C0[];
extern s32 D_001DA654;
extern void func_0038CFB0();
void func_00398760(s32 *hdr, s32 base, s32 *src, s32 n) {
    s32 *list = hdr + 4;
    s32 cnt = hdr[0];
    s32 off = hdr[2];
    s32 size = hdr[3];
    s32 i;
    for (i = 0; i < cnt; i++, list++) {
        s32 v = *list;
        if (v == 0) D_002FCF18[i] = (s32)D_002FD170;
        else D_002FCF18[i] = v - (off - (s32)D_002FD170);
    }
    func_0038CFB0(D_002FD170, (u8 *)hdr + off, size);
    for (D_001DA654 = 0; D_001DA654 < n; D_001DA654++) {
        s32 a = *src++;
        s32 b = *src++;
        s32 c = *src++;
        s32 d = *src++;
        s32 e;
        __asm__("plzcw %0, %1" : "=r"(e) : "r"(d));
        e = 30 - e;
        D_002FC8C0[D_001DA654].a = ((base + a) << 4) + b;
        D_002FC8C0[D_001DA654].b = ((base + c) << 4) + e;
    }
}
/* localdecomp:end func_00398760 */

ASM_FUNC("asm/boot_elf/handwritten", func_00398880);

/* localdecomp:start func_00398930 */
typedef struct { unsigned long z; s16 h8; s16 hA; s16 hC; s16 hE; } E_393878;
typedef struct { s16 h0; s16 h2; s16 h4; u8 p6[0x1A]; s32 f20; } F_393878;
typedef struct { u8 p0[4]; s16 h4; s16 h6; u8 p8[4]; s16 hC; u8 pE[2]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20[1]; } H_393878;
extern H_393878 *D_001DA670;
void func_00398930(H_393878 *p) {
    H_393878 *q;
    s32 i, k;
    D_001DA670 = p;
    p->h4 = 1;
    p->f10 += (s32)p;
    p->f14 += (s32)p;
    p->f18 += (s32)p;
    if (p->f1C) p->f1C += (s32)p;
    q = D_001DA670;
    {
        s32 *src = (s32 *)q->f10;
        for (i = 0; i < q->hC; i++) {
            s32 a = *src++ >> 4;
            s32 b = *src++ >> 4;
            s32 c, d;
            { s32 r; __asm__("plzcw %0, %1" : "=r"(r) : "r"(*src++)); c = 30 - r; }
            { s32 r; __asm__("plzcw %0, %1" : "=r"(r) : "r"(*src++)); d = 30 - r; }
            ((E_393878 *)q->f10)[i].hA = a;
            ((E_393878 *)q->f10)[i].h8 = b;
            ((E_393878 *)q->f10)[i].hC = c;
            ((E_393878 *)q->f10)[i].hE = d;
            ((E_393878 *)q->f10)[i].z = 0;
        }
    }
    for (k = 0; k < D_001DA670->h6; k++) {
        F_393878 *e = (F_393878 *)(D_001DA670->f20[k] + (s32)p);
        s32 j;
        if (!(e->h2 & 1)) {
            if (e->h4) {
                e->h2 = e->h4;
                e->h4 = 0;
            }
        }
        D_001DA670->f20[k] = (s32)e;
        for (j = 0; j < e->h0; j++) {
            ((F_393878 *)((u8 *)e + j * 0x20))->f20 += (s32)p;
        }
    }
}
/* localdecomp:end func_00398930 */

/* localdecomp:start func_00398AD0 */
typedef struct { s32 a, b, c, d; } E_00393A18;
typedef struct { u8 p0[0x1EB4]; s32 x1EB4; E_00393A18 e[1]; } S_160C40_00393A18;
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0x10]; s32 x24; } S_1A1ED0_00393A18;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393A18;
extern S_160C40_00393A18 D_160C40_00398AD0;
extern S_1A1ED0_00393A18 D_1A1ED0_00398AD0;
extern unsigned long D_1D4B70[1];
extern s32 func_003A2A10(s32);
extern s32 func_003A29B0(s32, s32, s32);
extern s32 func_00381BE8(void);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_00398AD0(s32 n0) {
    s32 n;
    u8 buf[0x60];
    u8 *p;
    s32 *list;
    S_160C40_00393A18 *b;
    S_1A1ED0_00393A18 *r;
    s32 i, a, c;
    func_003A9560(1);
    n = n0;
    p = *(u8 **)0x1D4B64;
    func_003A2A10(1);
    if (func_00381BE8() > 0) n = func_00381BE8();
    b = &D_160C40_00398AD0;
    func_003A29B0((s32)p, b->e[n].c + b->x1EB4, b->e[n].d);
    list = (s32 *)(p + 4);
    r = &D_1A1ED0_00398AD0;
    c = r->x24;
    a = r->x10;
    *(s32 *)0x1D4B68 = *(s32 *)p;
    for (i = 0; i < *(s32 *)0x1D4B68; i++) {
        {
            s32 tbp = a >> 8;
            u8 *q = p + *list;
            u8 *q20 = q + 0x20;
            s32 cbp, w, h, k, lz;
            func_12C9A0(buf, tbp, 1, 0, 0, 0, 0x10, 0x10);
            cbp = c >> 8;
            a += 0x400;
            func_11F0A0(0);
            list++;
            func_12CCC8(buf, q20);
            func_12A9F0(0, 0);
            w = *(s32 *)(q + 8);
            __asm__("plzcw %0, %1" : "=r"(lz) : "r"(w));
            k = 30 - lz;
            h = w >> 6;
            if (h <= 0) h = 1;
            func_12C9A0(buf, cbp, h, 0x1B, 0, 0, ((T_00393A18 *)q)->h8, ((T_00393A18 *)q)->hC);
            func_11F0A0(0);
            func_12CCC8(buf, q + 0x420);
            func_12A9F0(0, 0);
            D_1D4B70[i] = (unsigned long)cbp | ((unsigned long)h << 14) | ((unsigned long)0x1B << 20)
                | ((unsigned long)k << 26) | ((unsigned long)k << 30) | ((unsigned long)1 << 34)
                | ((unsigned long)tbp << 37) | ((unsigned long)4 << 61);
            c += *(s32 *)(q + 8) * *(s32 *)(q + 0xC) * 4;
        }
    }
    func_003A29B0((s32)p, D_160C40_00398AD0.e[n].a + D_160C40_00398AD0.x1EB4, D_160C40_00398AD0.e[n].b);
}
/* localdecomp:end func_00398AD0 */

/* localdecomp:start func_00398D50 */
extern unsigned long D_0022CB50[3];
extern s32 D_002DDCB0[];
extern s32 D_002DA7C0[];
extern s32 D_001D4B64;
extern s32 D_001D4B68;
extern unsigned long D_001D4B70[1];
__asm__(".extern D_001D5F40, 4");
extern s32 D_001D5F40;
extern s32 D_002DE430[];
typedef struct { u8 p0[8]; u8 f8; u8 f9; u8 pa[5]; u8 fF; u8 p10[4]; s32 f14; } S_393C98;
typedef struct { s32 a; s32 b; } E_393C98;
extern E_393C98 D_00337500[];
extern void func_00399BF0();
extern void func_0038CEA0();
extern s32 func_00381BE8();
extern void func_0038D050();
void func_00398D50(s32 a) {
    s32 i, n;
    S_393C98 *p;
    n = D_001D4B68;
    for (i = 0; i < n; i++) {
        D_0022CB50[i * 3] = D_001D4B70[i];
        D_0022CB50[i * 3 + 1] = 0xFFA0000000E0;
        D_0022CB50[i * 3 + 2] = 0x40000400004000;
    }
    func_00399BF0(D_001D4B64, 0, &D_001D5F40);
    D_002DDCB0[0] = 0xFFFC0000;
    func_0038CEA0(D_002DE430, -1, 0x10);
    {
        S_393C98 *p1 = ((S_393C98 **)D_002DA7C0)[0];
        p1->f9 = p1->f8;
    }
    if (func_00381BE8() > 0) a = func_00381BE8();
    p = ((S_393C98 **)D_002DA7C0)[0];
    func_0038D050(p->f14 - (p->fF << 4), D_00337500[a].a, D_00337500[a].b);
}
/* localdecomp:end func_00398D50 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00398E68);

/* localdecomp:start func_00398E80 */
typedef struct { u8 p0[0x18]; s32 f18; u8 p1c[0x1C]; unsigned long f38; } S_16C580_00393DC8;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAD8]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393DC8;
extern S_16C580_00393DC8 D_16C580;
extern S_160C40_00393DC8 D_160C40;
extern s32 D_00227670[];
extern unsigned long D_0022CB50[3];
__asm__(".extern D_001D5F30, 4");
extern s32 D_001D5F30;
extern void func_003A9560(s32);
extern s32 func_003A29B0(s32, s32, s32);
extern void func_00399D10(s32, s32, void *, s32);
void func_00398E80(s32 n) {
    S_160C40_00393DC8 *b;
    s32 h;
    D_16C580.f18 = n;
    func_003A9560(1);
    b = &D_160C40;
    h = D_00227670[0];
    func_003A29B0(h, b->e[n].a + b->f1284, b->e[n].b);
    D_0022CB50[0] = D_16C580.f38;
    D_0022CB50[1] = 0xFFA0000000E0;
    D_0022CB50[2] = 0x40000400004000;
    func_00399D10(h, 0, &D_001D5F30, -1);
}
/* localdecomp:end func_00398E80 */

/* localdecomp:start func_00398F48 */
/* MATCH */
typedef struct { u8 p0[0x30]; s32 x30; u8 p34[4]; unsigned long x38; } S_16C580_00393E90;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAF0]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393E90;
typedef struct { u8 p0[0x18]; s32 x18; u8 p1c[0x10]; s32 x2C; } S_1A1ED0_00393E90;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393E90;
extern S_16C580_00393E90 D_16C580_00398F48;
extern S_160C40_00393E90 D_160C40_00398F48;
extern S_1A1ED0_00393E90 D_1A1ED0_00398F48;
__asm__(".extern D_001DA0DC, 16");
extern s32 D_001DA0DC;
extern s32 D_001DA0C8[];
extern s32 func_003A2A10(s32);
extern s32 func_003A29B0(s32, s32, s32);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_00398F48(s32 n) {
    u8 buf[0x60];
    S_16C580_00393E90 *g = &D_16C580_00398F48;
    S_160C40_00393E90 *b;
    S_1A1ED0_00393E90 *r;
    u8 *t;
    u8 *q;
    s32 w, h, k, lz;
    g->x30 = n;
    func_003A9560(1);
    t = (u8 *)D_001DA0C8[1 - D_001DA0DC];
    func_003A2A10(1);
    b = &D_160C40_00398F48;
    q = t + 0x20;
    func_003A29B0((s32)t, b->e[n].a + b->f1284, b->e[n].b);
    r = &D_1A1ED0_00398F48;
    func_12C9A0(buf, r->x18 >> 8, 1, 0, 0, 0, 0x10, 0x10);
    func_11F0A0(0);
    func_12CCC8(buf, q);
    func_12A9F0(0, 0);
    w = *(s32 *)(t + 8);
    __asm__("plzcw %0, %1" : "=r"(lz) : "r"(w));
    k = 30 - lz;
    h = w >> 6;
    if (h <= 0) h = 1;
    func_12C9A0(buf, r->x2C >> 8, h, 0x1B, 0, 0, ((T_00393E90 *)t)->h8, ((T_00393E90 *)t)->hC);
    func_11F0A0(0);
    func_12CCC8(buf, t + 0x420);
    func_12A9F0(0, 0);
    g->x38 = (unsigned long)(r->x2C >> 8) | ((unsigned long)h << 14) | ((unsigned long)0x1B << 20)
           | ((unsigned long)k << 26) | ((unsigned long)k << 30) | ((unsigned long)1 << 34)
           | ((unsigned long)(r->x18 >> 8) << 37) | ((unsigned long)4 << 61);
}
/* localdecomp:end func_00398F48 */

/* localdecomp:start func_00399118 */
typedef struct { s32 off; s32 size; } E_94060;
typedef struct { u8 p0[0x18]; s32 f18; s32 f1C; E_94060 e[5]; } B_94060;
typedef struct { u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[0x40]; s32 f54; s32 f58; s32 f5C; s32 f60; s32 f64; u8 p68[0x2C]; s32 f94; u8 p98[4]; s32 f9C; s32 fA0; s32 fA4; } G_94060;
typedef struct { u8 p0[0x10]; s32 f10; } Q_94060;
extern B_94060 *D_001D4B50_00399118;
extern int D_001D9F20_00399118;
extern s32 D_001D9F48[5];
extern u8 D_001D5F50[];
extern u8 D_001D5F60[];
extern u8 D_001D5F70[];
extern u8 D_001D5F80[];
extern u8 D_001D5F90[];
extern s32 D_001D9F24;
extern s32 D_001D9F28;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern Q_94060 D_00227600[];
extern s32 func_003935E0();
extern void func_0038D050();
extern void func_003993B8();
extern s32 func_003A88E8();
extern void func_00393488();
extern void func_11F0A0();
extern void func_003932F0();
extern void func_00393458();
void func_00399118(void) {
    B_94060 *b;
    s32 *h;
    s32 *q;
    s32 i;
    s32 r, x, t;
    b = D_001D4B50_00399118;
    for (i = 0; i < 5; i++) {
        D_001D9F48[i] = (b->e[i].size + 0x3F) & 0xFFFFFFC0;
    }
    r = (b->f1C + 0x3F) & 0xFFFFFFC0;
    q = (s32 *)D_00227600;
    h = (s32 *)func_003935E0(r, 0, D_001D5F50, 0x39E);
    func_0038D050(h, (void *)(b->f18 + (s32)b), r);
    x = q[4] + 0x30000;
    D_001D9F20_00399118 = (int)h;
    D_001D9F24 = (s32)h + h[1];
    D_001D9F28 = (s32)h + h[2];
    D_001D9F30 = (s32)h + h[3];
    D_001D9F2C = (s32)h + h[4];
    if (h[0x15]) {
        u32 s = (u32)((b->e[0].size + 0x3F) & 0xFFFFFFC0) >> 4;
        func_003993B8(0, x);
        *(s32 *)(D_001D9F20_00399118 + 0x94) = func_003A88E8((void *)(b->e[0].off + (s32)b), s, s, D_001D5F60);
        func_00393488(0, x, 1);
    }
    if (*(s32 *)(D_001D9F20_00399118 + 0x58)) {
        t = func_003935E0(*(s32 *)(D_001D9F20_00399118 + 0x58), 0, D_001D5F50, 0x3CE);
        func_003993B8(1, t);
        func_11F0A0(0);
        func_003932F0(1, t);
    }
    if (*(s32 *)(D_001D9F20_00399118 + 0x5C)) {
        s32 s = ((b->e[2].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        *(s32 *)(D_001D9F20_00399118 + 0x9C) = func_003A88E8((void *)(b->e[2].off + (s32)b), s, s, D_001D5F70);
    }
    if (*(s32 *)(D_001D9F20_00399118 + 0x60)) {
        s32 s = ((b->e[3].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        *(s32 *)(D_001D9F20_00399118 + 0xA0) = func_003A88E8((void *)(b->e[3].off + (s32)b), s, s, D_001D5F80);
    }
    if (*(s32 *)(D_001D9F20_00399118 + 0x64)) {
        s32 s = ((b->e[4].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        *(s32 *)(D_001D9F20_00399118 + 0xA4) = func_003A88E8((void *)(b->e[4].off + (s32)b), s, s, D_001D5F90);
    }
    func_00393458();
}
/* localdecomp:end func_00399118 */

/* localdecomp:start func_003993B8 */
typedef struct { s32 off; s32 x4; } E_394300;
typedef struct { u8 pad[0x18]; E_394300 e[1]; } H_394300;
typedef struct { u8 pad[0x74]; s32 arr[1]; } G_394300;
extern H_394300 *D_001D4B50;
extern G_394300 *D_001D9F20;
void func_003A0A20(u8 *, u32);
void func_003993B8(s32 a, u32 b) {
    H_394300 *h;
    b = (b + 15) & 0xFFFFFFF0;
    if (b) {
        h = D_001D4B50;
        func_003A0A20((u8 *)(h->e[a + 1].off + (s32)h), b);
    }
    D_001D9F20->arr[a] = 0;
}
/* localdecomp:end func_003993B8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00399420);

/* localdecomp:start func_00399718 */
extern unsigned long D_001D9FE0[];
extern unsigned long D_001D9FF8[];
void func_00399718(unsigned long *p, s32 a, s32 b, s32 c, s32 d, s32 idx) {
    unsigned long t0 = D_0022CB50[idx * 3];
    unsigned long t1 = D_0022CB50[idx * 3 + 1];
    unsigned long t2 = D_0022CB50[idx * 3 + 2];
    if (idx >= 0) {
        p[0] = (((t1 & 0x1C) | 0x20) | ((unsigned long)b << 6)) | ((unsigned long)a << 32);
        p += 2;
        p[0] = c | ((unsigned long)d << 2) | ((unsigned long)idx << 24);
        p += 2;
        p[0] = t0;
        p[2] = t2;
        return;
    }
    if (idx < -1) {
        unsigned long *q = D_001D9FE0;
        if (idx == -3) q = D_001D9FF8;
        p[0] = (((unsigned long)b << 6) | 0x20) | ((unsigned long)a << 32);
        p += 2;
        p[0] = 5;
        p += 2;
        p[0] = q[0];
        p[2] = q[2];
    } else {
        p[0] = (((unsigned long)b << 6) | 0x20) | ((unsigned long)a << 32);
        p += 2;
        p[0] = 5;
        p += 2;
        p[0] = 0x80000004CC007FFBUL;
        p[2] = 0;
    }
}
/* localdecomp:end func_00399718 */

/* localdecomp:start func_00399868 */
typedef struct { u8 p0[0x20]; s32 x20; u8 p24[0x10]; s32 x34; } S_1A1ED0_003947B0;
extern S_1A1ED0_003947B0 D_1A1ED0_00399868;
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
typedef s32 (*F12C9A0_3947B0)(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_00399868(u8 *base, s32 n, s32 m, s32 *e) {
    u8 buf[0x60];
    s32 x, r, i, j;
    { S_1A1ED0_003947B0 *g = &D_1A1ED0_00399868; x = g->x20; }
    D_001D4BB0 = x;
    D_001D4BB4 = x;
    if (n > 0) {
        s32 one = 1;
        i = n;
        do {
            u8 *off = base + e[3];
            s32 lo = e[1] & 0xFFFF;
            s32 hi = e[1] >> 16;
            s32 cur = D_001D4BB0;
            if (e[0] == 0x13) {
                s32 t = lo >> 6;
                s32 k;
                if (t == 0) t = one;
                ((F12C9A0_3947B0)func_12C9A0)(buf, cur >> 8, t, 0x13, 0, 0, lo, hi);
                k = lo * hi;
                if (k <= 0xFF) k = 0x100;
                D_001D4BB0 += k;
            } else if (e[0] == 2) {
                ((F12C9A0_3947B0)func_12C9A0)(buf, cur >> 8, 1, 2, 0, 0, 0x10, 0x10);
                D_001D4BB0 += 0x200;
            } else if (e[0] == 0) {
                ((F12C9A0_3947B0)func_12C9A0)(buf, cur >> 8, 1, 0, 0, 0, 0x10, 0x10);
                D_001D4BB0 += 0x400;
            }
            func_11F0A0(0);
            i--;
            e += 4;
            func_12CCC8(buf, off);
            func_12A9F0(0, 0);
        } while (i != 0);
    }
    r = D_1A1ED0_00399868.x34;
    D_001D4BB4 = D_001D4BB0;
    if (m > 0) {
        j = m;
        do {
            s32 lo = e[1] & 0xFFFF;
            s32 hi = e[1] >> 16;
            u8 *off = base + e[2];
            s32 t = lo >> 6;
            if (t == 0) t = 1;
            ((F12C9A0_3947B0)func_12C9A0)(buf, r >> 8, t, 0x1B, 0, 0, lo, hi);
            j--;
            e += 4;
            r += lo * hi * 4;
            func_11F0A0(0);
            func_12CCC8(buf, off);
            func_12A9F0(0, 0);
        } while (j != 0);
    }
}
/* localdecomp:end func_00399868 */

/* localdecomp:start func_00399AD8 */
extern void func_00399420();
extern void func_00399718();
void func_00399AD8(s32 *a0, u8 *b, u8 *c, s32 n) {
    s32 i, j, cnt, lo, idx;
    s32 *e, *nx;
    s32 *p = a0;
    for (i = 0; i < n; i++) {
        nx = p + 4;
        cnt = p[1] >> 16;
        lo = p[1] & 0xFFFF;
        p[1] = lo;
        e = (s32 *)((u8 *)p[0] + ((lo - cnt) << 4));
        for (j = 0; j < cnt; j += 4) {
            idx = e[8];
            if (idx >= 0) idx = c[idx];
            if (b) {
                func_00399420(e, b + (idx << 4), e[0], e[1], e[4], e[5], idx);
            } else {
                func_00399718((unsigned long *)e, e[0], e[1], e[4], e[5], idx);
            }
            e += 16;
        }
        p = nx;
    }
}
/* localdecomp:end func_00399AD8 */

/* localdecomp:start func_00399BF0 */
typedef struct { s32 pad[2]; s32 f8; s32 pad2[8]; } S_227600_00394B38;
extern S_227600_00394B38 D_00227600_00399BF0;
extern void func_00399AD8();
void func_00399BF0(u8 *a, s32 b, u8 *tab) {
    s32 n, i;
    s32 *p, *q, *r, *r0;
    u8 *s;
    n = a[0] + a[1] + a[2];
    p = (s32 *)(a + *(s32 *)(a + 4));
    r0 = (s32 *)(a + *(s32 *)(a + 8));
    q = p;
    for (i = 0; i < n; i++) {
        if (q[0] < D_00227600_00399BF0.f8) {
            q[0] = q[0] + (s32)a;
            q[2] = q[2] + (s32)a;
        }
        q += 4;
    }
    r = r0;
    for (;;) {
        r[3] = r[3] + (s32)a;
        s = (u8 *)r;
        if (*s != 0xFF) {
            do {
                *s = tab[*s];
                s++;
            } while (*s != 0xFF);
        }
        if (r[3] < 0) break;
        r += 4;
    }
    func_00399AD8(p, b, tab, n);
}
/* localdecomp:end func_00399BF0 */

/* localdecomp:start func_00399CD0 */
void func_00399CD0(u8 *d, u8 *s) {
    d[4] = s[0];
    d[5] = s[1];
    d[6] = s[2];
    d[7] = s[3];
    *(u8 **)d = s + *(s32 *)(s + 4);
    *(u8 **)(d + 0x20) = s + *(s32 *)(s + 8);
}
/* localdecomp:end func_00399CD0 */

/* localdecomp:start func_00399D10 */
typedef int u128_394C58 __attribute__((mode(TI)));
typedef struct 
{
  u8 p0[0xA];
  s16 hA;
  u8 pC[4];
} T_394C58;
typedef struct 
{
  u8 p0[0x20];
  s32 x20;
} R_394C58;
typedef struct 
{
  u8 p0[0x10];
  u8 b10;
  u8 p11[3];
  s32 x14;
  u8 p18[4];
  s32 x1C[1];
} O_394C58;
typedef struct 
{
  u8 b0;
  u8 p1[0xB];
  s32 xC;
} E_394C58;
typedef struct 
{
  s32 x0;
  u8 b4;
  u8 b5;
  u8 b6;
  u8 b7;
  u8 b8;
  u8 b9;
  u8 bA;
  u8 bB;
  u8 bC;
  u8 pD[3];
  s32 x10;
  s32 x14;
  s32 x18;
  s32 x1C;
  s32 x20;
  s32 x24;
  s32 x28;
  u8 b2C;
  u8 p2D[0x1A];
  u8 b47;
  s32 x48[1];
} H_394C58;
extern R_394C58 D_1A1ED0_00399D10;
extern u8 D_002DB210[];
extern s32 D_002DE430[];
void func_00399D10(s32 a, s32 b, void *cv, s32 d)
{
  H_394C58 *p = (H_394C58 *) a;
  T_394C58 *tbl = (T_394C58 *) b;
  u8 *c = cv;
  u32 n;
  s32 i;
  n = (p->b4 + p->b5) + p->b6;
  if (p->b2C != 0)
  {
    n += (((u8 *) p) + (p->b2C << 4))[1];
  }
  if (p->x0 != 0)
  {
    s32 *q = (s32 *) (p->x0 = ((s32) p) + p->x0);
    if (n != 0)
    {
      u32 k0 = n;
      do
      {
        q[0] = q[0] + ((s32) p);
        q[2] = q[2] + ((s32) p);
        q += 4;
      }
      while (--k0);
    }
  }
  if (p->x10 != 0)
  {
    p->x10 = ((s32) p) + p->x10;
  }
  if (p->x14 != 0)
  {
    p->x14 = ((s32) p) + p->x14;
  }
  if (p->x18 != 0)
  {
    p->x18 = ((s32) p) + p->x18;
  }
  if (p->x1C != 0)
  {
    s32 m;
    p->x1C = ((s32) p) + p->x1C;
    m = *((s32 *) p->x1C);
    for (i = 0; i < m; i++)
    {
      s32 *e = (s32 *) ((i << 2) + p->x1C);
      e[1] = e[1] + ((s32) p);
    }

  }
  if (p->x20 != 0)
  {
    E_394C58 *e = (E_394C58 *) (p->x20 = ((s32) p) + p->x20);
    for (;;)
    {
      u8 *s = &e->b0;
      e->xC = e->xC + ((s32) p);
      if (*s != 0xFF)
      {
        do
        {
          *s = c[*s];
          s++;
        }
        while ((*s) != 0xFF);
      }
      if (e->xC < 0) break;
      e++;
    }
  }
  if (p->bB != 0)
  {
    s32 hi = p->bB >> 4;
    u16 *dst = (u16 *) ((p->x20 - (((p->bB & 0xF) * hi) * 1024)) - 0x10);
    s32 j;
    for (j = 0; j < hi; j++)
    {
      if (tbl != 0)
      {
        s32 t = tbl[c[j]].hA + (D_1A1ED0_00399D10.x20 >> 8);
        dst[j] = t;
      }
      else
      {
        dst[j] = (D_0022CB50[c[j] * 3] >> 37) & 0x3FFF;
      }
    }
  }
  if (p->x28 != 0)
  {
    p->x28 = ((s32) p) + p->x28;
  }
  for (i = 0; i < p->bC; i++)
  {
    if (p->x48[i] != 0)
    {
      O_394C58 *o = (O_394C58 *) (((s32) p) + p->x48[i]);
      s32 j;
      p->x48[i] = (s32) o;
      if (p->b8 == 0)
      {
        if (o->b10 >= 2)
        {
          o->b10 = 1;
        }
      }
      if (o->x14 != 0)
      {
        o->x14 = ((s32) o) + o->x14;
      }
      for (j = 0; j < o->b10; j++)
      {
        o->x1C[j] = ((s32) p) + o->x1C[j];
      }

    }
  }

  if (d >= 0)
  {
    *(((u128_394C58 *) D_002DE430) + (*(D_002DB210 + d))) = *((u128_394C58 *) c);
  }
  if (p->x0 != 0)
  {
    func_00399AD8((s32 *)p->x0, (u8 *)b, c, n);
  }
  if (p->b47 == 0xFF)
  {
    p->b47 = 0;
  }
}
/* localdecomp:end func_00399D10 */

/* localdecomp:start func_0039A030 */
typedef struct { u8 p[0x2D]; u8 b2D; } S_4F78;
extern u8 D_002DB210[];
extern s16 D_002DB030[];
extern s32 D_002DA7C0[];
extern s32 D_002DDCB0[];
extern s32 D_001DA500;
extern s32 D_001DA504;
extern void func_00399D10(s32, s32, void *, s32);
extern void func_003CD1B0();
void func_0039A030(S_4F78 *a, s32 b, void *c, s32 d) {
    if (a == 0) {
        func_003CD1B0(d, 1);
        D_002DB210[d] = D_001DA504;
        D_001DA504 = D_001DA504 + 1;
    } else {
        D_002DB030[D_001DA500] = d;
        D_002DB210[d] = D_001DA500;
        D_002DA7C0[D_001DA500] = (s32)a;
        D_002DDCB0[D_001DA500] = a->b2D << 10;
        if (a->b2D == 0xFF) D_002DDCB0[D_001DA500] = 0x100000;
        func_00399D10((s32)a, b, c, d);
        func_003CD1B0(d, 0);
        D_001DA500 = D_001DA500 + 1;
    }
}
/* localdecomp:end func_0039A030 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0039A140);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0039A148);

LINKER_REMNANT("asm/boot_elf/remnants", func_0039A410);

/* localdecomp:start func_0039A418 */
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x668 - 0x650]; s32 f668; s32 f66C; } S_395360;
extern S_395360 D_00160C40;
extern s32 *D_001D4B50_0039A418;
extern u8 D_01FF7FF0[];
extern s32 func_003A2940();
s32 func_0039A418(void) {
    S_395360 *s = &D_00160C40;
    u32 x;
    s32 *p;
    x = ((s->f66C << 11) + 0x1057) & 0xFFFFF000;
    p = (s32 *)((s32)((u32)D_01FF7FF0 - x) & -16);
    D_001D4B50_0039A418 = p;
    *p = 0x60;
    func_003A2940((s32)D_001D4B50_0039A418 + D_001D4B50_0039A418[0], s->f668 + s->f64C, s->f66C);
    return 1;
}
/* localdecomp:end func_0039A418 */
TEXT_PADDING(2);

LINKER_REMNANT("asm/boot_elf/remnants", func_0039A4A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0039A4A8);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C1A0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0039A6E0);

/* localdecomp:start func_0039A700 */
typedef struct { u8 p0[6]; u8 b6; u8 p7[5]; u8 bC; u8 pD[0x3B]; s32 w48[1]; } W_395648;
typedef struct { u8 p0[0x24]; W_395648 *w24; u8 p28[0xA]; u16 h32; u16 h34; u8 p36[2]; long d38; u8 p40[2]; u8 b42; u8 b43; u8 p44[0x1E]; u8 b62; u8 b63; u8 p64[4]; s32 w68; u8 p6C[0x2C]; s32 w98; u8 p9C[0xE]; s16 hAA; u8 pAC[8]; s16 hB4; } O_395648;
typedef struct { u8 p0[0x38]; s32 w38; u8 p3C[4]; s16 h40; u8 p42[2]; s16 h44; u8 p46[2]; s16 h48; u8 p4A[0xA]; s32 w54; u8 p58[0xC]; s32 w64; u8 *w68; s32 w6C; u8 p70[0xC]; s16 h7C; s16 h7E; u8 p80[0x120]; O_395648 *arr[1]; } G_395648;
typedef struct { u8 p0[0x25C0]; u8 *q25C0; } Q_395648;
extern G_395648 D_00225780_0039A700;
extern Q_395648 D_1A4BE0;
extern O_395648 *D_001D9C4C;
extern void func_11F0A0(s32);
extern void func_003C2898(O_395648 *, s32);
extern O_395648 *func_003C2770_0039A700(s32, s32);
void func_0039A700(void) {
    u8 *h;
    s32 *tp;
    s32 *e;
    s32 i, k, kind, b, x;
    s32 off;
    O_395648 *o;
    func_11F0A0(0);
    func_003A0A20((u8 *)D_00225780_0039A700.w6C, (u32)D_00225780_0039A700.w68);
    func_11F0A0(0);
    h = D_00225780_0039A700.w68;
    D_00225780_0039A700.w38 = 0;
    tp = (s32 *)(h + 0x14);
    D_00225780_0039A700.h40 = *(u16 *)(h + 0);
    x = *(s32 *)(h + 4);
    D_00225780_0039A700.h48 = *(u16 *)(h + 8);
    D_00225780_0039A700.h44 = *(u16 *)(h + 0xC);
    D_00225780_0039A700.w64 = (s32)h + *(s32 *)(h + 0x10);
    if (x != 0) {
        D_00225780_0039A700.h7C = x;
        D_00225780_0039A700.h7E = (x >> 16) + 1;
    }
    for (i = 0; i < D_00225780_0039A700.h44; i++) {
        e = (s32 *)(h + *tp++);
        kind = *e;
        e += 3;
        off = (s32)h + *e++;
        if (kind == 0x215 || kind == 0x10D1) kind = 0xD54;
        o = D_00225780_0039A700.arr[i];
        if (o == 0) {
            if (kind == 0) {
                o = D_001D9C4C;
                func_003C2898(o, 0);
            } else {
                o = func_003C2770_0039A700(kind, 0);
            }
            o->h32 = 0x1FF;
            o->b62 = 0xFF;
            o->h34 |= 6;
            o->w98 = 0;
            o->hB4 = 0;
            if (D_1A4BE0.q25C0 == 0) {
                o->d38 = 0x0038383800000000L;
            } else {
                o->d38 = *(long *)(D_1A4BE0.q25C0 + 0x38);
            }
            if (o->w24->b6 != 0) o->b63 = 0x18;
            b = o->w24->bC;
            o->w24->bC = b + 1;
            o->b42 = b;
            o->b43 = b;
            D_00225780_0039A700.arr[i] = o;
            if (o->hAA == 0xD54) D_00225780_0039A700.w54 = (s32)o;
        }
        o->w68 = off;
        o->w24->w48[o->b42] = (s32)e;
        for (k = 0; k < ((u8 *)e)[0x10]; k++) {
            s32 *q = (s32 *)((u8 *)e + 0x1C);
            q[k] = (s32)e + q[k];
        }
    }
}
/* localdecomp:end func_0039A700 */

/* localdecomp:start func_0039A958 */
typedef struct {
    u8 pad0[0x6C];
    u32 f6C;
    u8 pad1[0x20];
    u32 slots[1];
} T_958A0;

extern T_958A0 D_00225780[];
extern u32 D_00227610[];
extern u32 D_001DA0D8;
extern void func_0039A700(void);

void func_0039A958(s32 a0) {
    u32 value = D_00225780[0].slots[a0];

    D_00225780[0].f6C = value;
    func_0039A700();
    D_00225780[0].f6C = D_00227610[0] + D_001DA0D8;
}
/* localdecomp:end func_0039A958 */
