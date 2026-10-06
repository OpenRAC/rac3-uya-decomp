#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003934E8(s32, s32);
extern void func_00393580(void);
extern void func_00394060(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/nonmatchings/text", func_003934E8);

LINKER_REMNANT("asm/remnants", func_00393550);

INCLUDE_ASM("asm/nonmatchings/text", func_00393580);

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

INCLUDE_ASM("asm/nonmatchings/text", func_00393878);

INCLUDE_ASM("asm/nonmatchings/text", func_00393A18);

INCLUDE_ASM("asm/nonmatchings/text", func_00393C98);

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

INCLUDE_ASM("asm/nonmatchings/text", func_00394060);

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

INCLUDE_ASM("asm/nonmatchings/text", func_00394660);

INCLUDE_ASM("asm/nonmatchings/text", func_003947B0);

INCLUDE_ASM("asm/nonmatchings/text", func_00394A20);

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

INCLUDE_ASM("asm/nonmatchings/text", func_00394C58);

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

INCLUDE_ASM("asm/nonmatchings/text", func_00395648);

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
