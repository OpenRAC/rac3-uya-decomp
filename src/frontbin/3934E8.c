#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003934E8(s32, s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/nonmatchings/text", func_003934E8);

LINKER_REMNANT("asm/remnants", func_00393550);

INCLUDE_ASM("asm/nonmatchings/text", func_00393580);

LINKER_REMNANT("asm/remnants", func_003936A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003936A8);

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

INCLUDE_ASM("asm/nonmatchings/text", func_00393E90);

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
