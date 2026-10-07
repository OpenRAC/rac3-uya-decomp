#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003934E8(s32, s32);
extern void func_00393580(void);
extern void func_00394060(void);
extern void func_003A3DA0(s32);
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003934E8 */
__asm__(".extern D_001D9FC8, 4");
extern s32 D_001D5F00[];
extern s32 D_001D5EE8[];
extern s32 D_001D9FCC;
extern s32 D_001D9FC8;
extern void func_13B0C8();
extern void func_00393460();
typedef struct { u8 pad[0x10]; s32 a; u16 b; u8 pad2[0x1A]; } S_3934E8;
void func_003934E8(s32 x, s32 y) {
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
    func_00393460(p, 2, &D_001D9FC8);
}
/* localdecomp:end func_003934E8 */

LINKER_REMNANT("asm/remnants", func_00393550);

/* localdecomp:start func_00393580 */
extern u8 D_00227600_00393580[];
extern u8 D_3EDDF7[];
extern u8 D_01FF8000[];
extern u8 D_01FFC000[];
extern u32 D_001DA0D8;
extern s32 func_0011A264(s32, s32, s32);
void func_00393580(void) {
    u32 *s = (u32 *)D_00227600_00393580;
    u32 c;
    func_0011A264((s32)s, 0, 0xA0);
    c = (u32)D_01FFC000;
    s[0] = 0;
    s[1] = 0x100000;
    s[2] = (u32)D_3EDDF7 & 0xFFFFF000;
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
/* localdecomp:end func_00393580 */

LINKER_REMNANT("asm/remnants", func_003936A0);

/* localdecomp:start func_003936A8 */
/* MATCH */
extern u8 D_002F9170[];
extern s32 D_002F8F18[];
typedef struct { s32 a, b; } P_3936A8;
extern P_3936A8 D_002F88C0[];
extern s32 D_001DA654;
extern void func_00388550();
void func_003936A8(s32 *hdr, s32 base, s32 *src, s32 n) {
    s32 *list = hdr + 4;
    s32 cnt = hdr[0];
    s32 off = hdr[2];
    s32 size = hdr[3];
    s32 i;
    for (i = 0; i < cnt; i++, list++) {
        s32 v = *list;
        if (v == 0) D_002F8F18[i] = (s32)D_002F9170;
        else D_002F8F18[i] = v - (off - (s32)D_002F9170);
    }
    func_00388550(D_002F9170, (u8 *)hdr + off, size);
    for (D_001DA654 = 0; D_001DA654 < n; D_001DA654++) {
        s32 a = *src++;
        s32 b = *src++;
        s32 c = *src++;
        s32 d = *src++;
        s32 e;
        __asm__("plzcw %0, %1" : "=r"(e) : "r"(d));
        e = 30 - e;
        D_002F88C0[D_001DA654].a = ((base + a) << 4) + b;
        D_002F88C0[D_001DA654].b = ((base + c) << 4) + e;
    }
}
/* localdecomp:end func_003936A8 */

ASM_FUNC("asm/handwritten", func_003937C8);

/* localdecomp:start func_00393878 */
typedef struct { unsigned long z; s16 h8; s16 hA; s16 hC; s16 hE; } E_393878;
typedef struct { s16 h0; s16 h2; s16 h4; u8 p6[0x1A]; s32 f20; } F_393878;
typedef struct { u8 p0[4]; s16 h4; s16 h6; u8 p8[4]; s16 hC; u8 pE[2]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20[1]; } H_393878;
extern H_393878 *D_001DA670;
void func_00393878(H_393878 *p) {
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
/* localdecomp:end func_00393878 */

/* localdecomp:start func_00393A18 */
typedef struct { s32 a, b, c, d; } E_00393A18;
typedef struct { u8 p0[0x1EB4]; s32 x1EB4; E_00393A18 e[1]; } S_160C40_00393A18;
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0x10]; s32 x24; } S_1A1ED0_00393A18;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393A18;
extern S_160C40_00393A18 D_160C40_00393A18;
extern S_1A1ED0_00393A18 D_1A1ED0_00393A18;
extern unsigned long D_1D4B70[1];
extern s32 func_0039D6C8(s32);
extern s32 func_0039D668(s32, s32, s32);
extern s32 func_0037DC58(void);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_00393A18(s32 n0) {
    s32 n;
    u8 buf[0x60];
    u8 *p;
    s32 *list;
    S_160C40_00393A18 *b;
    S_1A1ED0_00393A18 *r;
    s32 i, a, c;
    func_003A3DA0(1);
    n = n0;
    p = *(u8 **)0x1D4B64;
    func_0039D6C8(1);
    if (func_0037DC58() > 0) n = func_0037DC58();
    b = &D_160C40_00393A18;
    func_0039D668((s32)p, b->e[n].c + b->x1EB4, b->e[n].d);
    list = (s32 *)(p + 4);
    r = &D_1A1ED0_00393A18;
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
    func_0039D668((s32)p, D_160C40_00393A18.e[n].a + D_160C40_00393A18.x1EB4, D_160C40_00393A18.e[n].b);
}
/* localdecomp:end func_00393A18 */

/* localdecomp:start func_00393C98 */
extern unsigned long D_00228B50[3];
extern s32 D_002D9CB0[];
extern s32 D_002D67C0[];
extern s32 D_001D4B64;
extern s32 D_001D4B68;
extern unsigned long D_001D4B70[1];
__asm__(".extern D_001D5F40, 4");
extern s32 D_001D5F40;
extern s32 D_002DA430[];
typedef struct { u8 p0[8]; u8 f8; u8 f9; u8 pa[5]; u8 fF; u8 p10[4]; s32 f14; } S_393C98;
typedef struct { s32 a; s32 b; } E_393C98;
extern E_393C98 D_003334C0[];
extern void func_00394B38();
extern void func_00388440();
extern s32 func_0037DC58();
extern void func_003885F0();
void func_00393C98(s32 a) {
    s32 i, n;
    S_393C98 *p;
    n = D_001D4B68;
    for (i = 0; i < n; i++) {
        D_00228B50[i * 3] = D_001D4B70[i];
        D_00228B50[i * 3 + 1] = 0xFFA0000000E0;
        D_00228B50[i * 3 + 2] = 0x40000400004000;
    }
    func_00394B38(D_001D4B64, 0, &D_001D5F40);
    D_002D9CB0[0] = 0xFFFC0000;
    func_00388440(D_002DA430, -1, 0x10);
    {
        S_393C98 *p1 = ((S_393C98 **)D_002D67C0)[0];
        p1->f9 = p1->f8;
    }
    if (func_0037DC58() > 0) a = func_0037DC58();
    p = ((S_393C98 **)D_002D67C0)[0];
    func_003885F0(p->f14 - (p->fF << 4), D_003334C0[a].a, D_003334C0[a].b);
}
/* localdecomp:end func_00393C98 */

LINKER_REMNANT("asm/remnants", func_00393DB0);

/* localdecomp:start func_00393DC8 */
typedef struct { u8 p0[0x18]; s32 f18; u8 p1c[0x1C]; unsigned long f38; } S_16C580_00393DC8;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAD8]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393DC8;
extern S_16C580_00393DC8 D_16C580;
extern S_160C40_00393DC8 D_160C40;
extern s32 D_00227670[];
extern unsigned long D_00228B50[3];
__asm__(".extern D_001D5F30, 4");
extern s32 D_001D5F30;
extern void func_003A3DA0(s32);
extern s32 func_0039D668(s32, s32, s32);
extern void func_00394C58(s32, s32, void *, s32);
void func_00393DC8(s32 n) {
    S_160C40_00393DC8 *b;
    s32 h;
    D_16C580.f18 = n;
    func_003A3DA0(1);
    b = &D_160C40;
    h = D_00227670[0];
    func_0039D668(h, b->e[n].a + b->f1284, b->e[n].b);
    D_00228B50[0] = D_16C580.f38;
    D_00228B50[1] = 0xFFA0000000E0;
    D_00228B50[2] = 0x40000400004000;
    func_00394C58(h, 0, &D_001D5F30, -1);
}
/* localdecomp:end func_00393DC8 */

/* localdecomp:start func_00393E90 */
/* MATCH */
typedef struct { u8 p0[0x30]; s32 x30; u8 p34[4]; unsigned long x38; } S_16C580_00393E90;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAF0]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393E90;
typedef struct { u8 p0[0x18]; s32 x18; u8 p1c[0x10]; s32 x2C; } S_1A1ED0_00393E90;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393E90;
extern S_16C580_00393E90 D_16C580_00393E90;
extern S_160C40_00393E90 D_160C40_00393E90;
extern S_1A1ED0_00393E90 D_1A1ED0_00393E90;
__asm__(".extern D_001DA0DC, 16");
extern s32 D_001DA0DC;
extern s32 D_001DA0C8[];
extern s32 func_0039D6C8(s32);
extern s32 func_0039D668(s32, s32, s32);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_00393E90(s32 n) {
    u8 buf[0x60];
    S_16C580_00393E90 *g = &D_16C580_00393E90;
    S_160C40_00393E90 *b;
    S_1A1ED0_00393E90 *r;
    u8 *t;
    u8 *q;
    s32 w, h, k, lz;
    g->x30 = n;
    func_003A3DA0(1);
    t = (u8 *)D_001DA0C8[1 - D_001DA0DC];
    func_0039D6C8(1);
    b = &D_160C40_00393E90;
    q = t + 0x20;
    func_0039D668((s32)t, b->e[n].a + b->f1284, b->e[n].b);
    r = &D_1A1ED0_00393E90;
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
/* localdecomp:end func_00393E90 */

/* localdecomp:start func_00394060 */
typedef struct { s32 off; s32 size; } E_94060;
typedef struct { u8 p0[0x18]; s32 f18; s32 f1C; E_94060 e[5]; } B_94060;
typedef struct { u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[0x40]; s32 f54; s32 f58; s32 f5C; s32 f60; s32 f64; u8 p68[0x2C]; s32 f94; u8 p98[4]; s32 f9C; s32 fA0; s32 fA4; } G_94060;
typedef struct { u8 p0[0x10]; s32 f10; } Q_94060;
extern B_94060 *D_001D4B50_00394060;
extern int D_001D9F20_00394060;
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
extern s32 func_0038EA88();
extern void func_003885F0();
extern void func_00394300();
extern s32 func_003A3128();
extern void func_0038E930();
extern void func_11F0A0();
extern void func_0038E798();
extern void func_0038E900();
void func_00394060(void) {
    B_94060 *b;
    s32 *h;
    s32 *q;
    s32 i;
    s32 r, x, t;
    b = D_001D4B50_00394060;
    for (i = 0; i < 5; i++) {
        D_001D9F48[i] = (b->e[i].size + 0x3F) & 0xFFFFFFC0;
    }
    r = (b->f1C + 0x3F) & 0xFFFFFFC0;
    q = (s32 *)D_00227600;
    h = (s32 *)func_0038EA88(r, 0, D_001D5F50, 0x39E);
    func_003885F0(h, (void *)(b->f18 + (s32)b), r);
    x = q[4] + 0x30000;
    D_001D9F20_00394060 = (int)h;
    D_001D9F24 = (s32)h + h[1];
    D_001D9F28 = (s32)h + h[2];
    D_001D9F30 = (s32)h + h[3];
    D_001D9F2C = (s32)h + h[4];
    if (h[0x15]) {
        u32 s = (u32)((b->e[0].size + 0x3F) & 0xFFFFFFC0) >> 4;
        func_00394300(0, x);
        *(s32 *)(D_001D9F20_00394060 + 0x94) = func_003A3128((void *)(b->e[0].off + (s32)b), s, s, D_001D5F60);
        func_0038E930(0, x, 1);
    }
    if (*(s32 *)(D_001D9F20_00394060 + 0x58)) {
        t = func_0038EA88(*(s32 *)(D_001D9F20_00394060 + 0x58), 0, D_001D5F50, 0x3CE);
        func_00394300(1, t);
        func_11F0A0(0);
        func_0038E798(1, t);
    }
    if (*(s32 *)(D_001D9F20_00394060 + 0x5C)) {
        s32 s = ((b->e[2].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        *(s32 *)(D_001D9F20_00394060 + 0x9C) = func_003A3128((void *)(b->e[2].off + (s32)b), s, s, D_001D5F70);
    }
    if (*(s32 *)(D_001D9F20_00394060 + 0x60)) {
        s32 s = ((b->e[3].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        *(s32 *)(D_001D9F20_00394060 + 0xA0) = func_003A3128((void *)(b->e[3].off + (s32)b), s, s, D_001D5F80);
    }
    if (*(s32 *)(D_001D9F20_00394060 + 0x64)) {
        s32 s = ((b->e[4].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        *(s32 *)(D_001D9F20_00394060 + 0xA4) = func_003A3128((void *)(b->e[4].off + (s32)b), s, s, D_001D5F90);
    }
    func_0038E900();
}
/* localdecomp:end func_00394060 */

/* localdecomp:start func_00394300 */
typedef struct { s32 off; s32 x4; } E_394300;
typedef struct { u8 pad[0x18]; E_394300 e[1]; } H_394300;
typedef struct { u8 pad[0x74]; s32 arr[1]; } G_394300;
extern H_394300 *D_001D4B50;
extern G_394300 *D_001D9F20;
void func_0039B760(u8 *, u32);
void func_00394300(s32 a, u32 b) {
    H_394300 *h;
    b = (b + 15) & 0xFFFFFFF0;
    if (b) {
        h = D_001D4B50;
        func_0039B760((u8 *)(h->e[a + 1].off + (s32)h), b);
    }
    D_001D9F20->arr[a] = 0;
}
/* localdecomp:end func_00394300 */

INCLUDE_ASM("asm/nonmatchings/text", func_00394368);

/* localdecomp:start func_00394660 */
extern unsigned long D_001D9FE0[];
extern unsigned long D_001D9FF8[];
void func_00394660(unsigned long *p, s32 a, s32 b, s32 c, s32 d, s32 idx) {
    unsigned long t0 = D_00228B50[idx * 3];
    unsigned long t1 = D_00228B50[idx * 3 + 1];
    unsigned long t2 = D_00228B50[idx * 3 + 2];
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
/* localdecomp:end func_00394660 */

/* localdecomp:start func_003947B0 */
typedef struct { u8 p0[0x20]; s32 x20; u8 p24[0x10]; s32 x34; } S_1A1ED0_003947B0;
extern S_1A1ED0_003947B0 D_1A1ED0_003947B0;
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
typedef s32 (*F12C9A0_3947B0)(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_003947B0(u8 *base, s32 n, s32 m, s32 *e) {
    u8 buf[0x60];
    s32 x, r, i, j;
    { S_1A1ED0_003947B0 *g = &D_1A1ED0_003947B0; x = g->x20; }
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
    r = D_1A1ED0_003947B0.x34;
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
/* localdecomp:end func_003947B0 */

/* localdecomp:start func_00394A20 */
extern void func_00394368();
extern void func_00394660();
void func_00394A20(s32 *a0, u8 *b, u8 *c, s32 n) {
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
                func_00394368(e, b + (idx << 4), e[0], e[1], e[4], e[5], idx);
            } else {
                func_00394660((unsigned long *)e, e[0], e[1], e[4], e[5], idx);
            }
            e += 16;
        }
        p = nx;
    }
}
/* localdecomp:end func_00394A20 */

/* localdecomp:start func_00394B38 */
typedef struct { s32 pad[2]; s32 f8; s32 pad2[8]; } S_227600_00394B38;
extern S_227600_00394B38 D_00227600_00394B38;
extern void func_00394A20();
void func_00394B38(u8 *a, s32 b, u8 *tab) {
    s32 n, i;
    s32 *p, *q, *r, *r0;
    u8 *s;
    n = a[0] + a[1] + a[2];
    p = (s32 *)(a + *(s32 *)(a + 4));
    r0 = (s32 *)(a + *(s32 *)(a + 8));
    q = p;
    for (i = 0; i < n; i++) {
        if (q[0] < D_00227600_00394B38.f8) {
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
    func_00394A20(p, b, tab, n);
}
/* localdecomp:end func_00394B38 */

/* localdecomp:start func_00394C18 */
void func_00394C18(u8 *d, u8 *s) {
    d[4] = s[0];
    d[5] = s[1];
    d[6] = s[2];
    d[7] = s[3];
    *(u8 **)d = s + *(s32 *)(s + 4);
    *(u8 **)(d + 0x20) = s + *(s32 *)(s + 8);
}
/* localdecomp:end func_00394C18 */

/* localdecomp:start func_00394C58 */
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
extern R_394C58 D_1A1ED0_00394C58;
extern u8 D_002D7210[];
extern s32 D_002DA430[];
void func_00394C58(s32 a, s32 b, void *cv, s32 d)
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
        s32 t = tbl[c[j]].hA + (D_1A1ED0_00394C58.x20 >> 8);
        dst[j] = t;
      }
      else
      {
        dst[j] = (D_00228B50[c[j] * 3] >> 37) & 0x3FFF;
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
    *(((u128_394C58 *) D_002DA430) + (*(D_002D7210 + d))) = *((u128_394C58 *) c);
  }
  if (p->x0 != 0)
  {
    func_00394A20((s32 *)p->x0, (u8 *)b, c, n);
  }
  if (p->b47 == 0xFF)
  {
    p->b47 = 0;
  }
}
/* localdecomp:end func_00394C58 */

/* localdecomp:start func_00394F78 */
typedef struct { u8 p[0x2D]; u8 b2D; } S_4F78;
extern u8 D_002D7210[];
extern s16 D_002D7030[];
extern s32 D_002D67C0[];
extern s32 D_002D9CB0[];
extern s32 D_001DA500;
extern s32 D_001DA504;
extern void func_00394C58(s32, s32, void *, s32);
extern void func_003C79F0();
void func_00394F78(S_4F78 *a, s32 b, void *c, s32 d) {
    if (a == 0) {
        func_003C79F0(d, 1);
        D_002D7210[d] = D_001DA504;
        D_001DA504 = D_001DA504 + 1;
    } else {
        D_002D7030[D_001DA500] = d;
        D_002D7210[d] = D_001DA500;
        D_002D67C0[D_001DA500] = (s32)a;
        D_002D9CB0[D_001DA500] = a->b2D << 10;
        if (a->b2D == 0xFF) D_002D9CB0[D_001DA500] = 0x100000;
        func_00394C58((s32)a, b, c, d);
        func_003C79F0(d, 0);
        D_001DA500 = D_001DA500 + 1;
    }
}
/* localdecomp:end func_00394F78 */

LINKER_REMNANT("asm/remnants", func_00395088);

INCLUDE_ASM("asm/nonmatchings/text", func_00395090);

LINKER_REMNANT("asm/remnants", func_00395358);

/* localdecomp:start func_00395360 */
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x668 - 0x650]; s32 f668; s32 f66C; } S_395360;
extern S_395360 D_00160C40;
extern s32 *D_001D4B50_00395360;
extern u8 D_01FF7FF0[];
extern s32 func_0039D5F8();
s32 func_00395360(void) {
    S_395360 *s = &D_00160C40;
    u32 x;
    s32 *p;
    x = ((s->f66C << 11) + 0x1057) & 0xFFFFF000;
    p = (s32 *)((s32)((u32)D_01FF7FF0 - x) & -16);
    D_001D4B50_00395360 = p;
    *p = 0x60;
    func_0039D5F8((s32)D_001D4B50_00395360 + D_001D4B50_00395360[0], s->f668 + s->f64C, s->f66C);
    return 1;
}
/* localdecomp:end func_00395360 */
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_003953E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003953F0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318170);

LINKER_REMNANT("asm/remnants", func_00395628);

/* localdecomp:start func_00395648 */
typedef struct { u8 p0[6]; u8 b6; u8 p7[5]; u8 bC; u8 pD[0x3B]; s32 w48[1]; } W_395648;
typedef struct { u8 p0[0x24]; W_395648 *w24; u8 p28[0xA]; u16 h32; u16 h34; u8 p36[2]; long d38; u8 p40[2]; u8 b42; u8 b43; u8 p44[0x1E]; u8 b62; u8 b63; u8 p64[4]; s32 w68; u8 p6C[0x2C]; s32 w98; u8 p9C[0xE]; s16 hAA; u8 pAC[8]; s16 hB4; } O_395648;
typedef struct { u8 p0[0x38]; s32 w38; u8 p3C[4]; s16 h40; u8 p42[2]; s16 h44; u8 p46[2]; s16 h48; u8 p4A[0xA]; s32 w54; u8 p58[0xC]; s32 w64; u8 *w68; s32 w6C; u8 p70[0xC]; s16 h7C; s16 h7E; u8 p80[0x120]; O_395648 *arr[1]; } G_395648;
typedef struct { u8 p0[0x25C0]; u8 *q25C0; } Q_395648;
extern G_395648 D_00225780_00395648;
extern Q_395648 D_1A4BE0;
extern O_395648 *D_001D9C4C;
extern void func_11F0A0(s32);
extern void func_003BD0D8(O_395648 *, s32);
extern O_395648 *func_003BCFB0_00395648(s32, s32);
void func_00395648(void) {
    u8 *h;
    s32 *tp;
    s32 *e;
    s32 i, k, kind, b, x;
    s32 off;
    O_395648 *o;
    func_11F0A0(0);
    func_0039B760((u8 *)D_00225780_00395648.w6C, (u32)D_00225780_00395648.w68);
    func_11F0A0(0);
    h = D_00225780_00395648.w68;
    D_00225780_00395648.w38 = 0;
    tp = (s32 *)(h + 0x14);
    D_00225780_00395648.h40 = *(u16 *)(h + 0);
    x = *(s32 *)(h + 4);
    D_00225780_00395648.h48 = *(u16 *)(h + 8);
    D_00225780_00395648.h44 = *(u16 *)(h + 0xC);
    D_00225780_00395648.w64 = (s32)h + *(s32 *)(h + 0x10);
    if (x != 0) {
        D_00225780_00395648.h7C = x;
        D_00225780_00395648.h7E = (x >> 16) + 1;
    }
    for (i = 0; i < D_00225780_00395648.h44; i++) {
        e = (s32 *)(h + *tp++);
        kind = *e;
        e += 3;
        off = (s32)h + *e++;
        if (kind == 0x215 || kind == 0x10D1) kind = 0xD54;
        o = D_00225780_00395648.arr[i];
        if (o == 0) {
            if (kind == 0) {
                o = D_001D9C4C;
                func_003BD0D8(o, 0);
            } else {
                o = func_003BCFB0_00395648(kind, 0);
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
            D_00225780_00395648.arr[i] = o;
            if (o->hAA == 0xD54) D_00225780_00395648.w54 = (s32)o;
        }
        o->w68 = off;
        o->w24->w48[o->b42] = (s32)e;
        for (k = 0; k < ((u8 *)e)[0x10]; k++) {
            s32 *q = (s32 *)((u8 *)e + 0x1C);
            q[k] = (s32)e + q[k];
        }
    }
}
/* localdecomp:end func_00395648 */

/* localdecomp:start func_003958A0 */
typedef struct {
    u8 pad0[0x6C];
    u32 f6C;
    u8 pad1[0x20];
    u32 slots[1];
} T_958A0;

extern T_958A0 D_00225780[];
extern u32 D_00227610[];
extern u32 D_001DA0D8;
extern void func_00395648(void);

void func_003958A0(s32 a0) {
    u32 value = D_00225780[0].slots[a0];

    D_00225780[0].f6C = value;
    func_00395648();
    D_00225780[0].f6C = D_00227610[0] + D_001DA0D8;
}
/* localdecomp:end func_003958A0 */
