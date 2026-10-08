#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
int func_00135DC8(int x);
void func_00139F90(void);
void func_0013A030(void *s);
extern s32 func_00133C58();
extern void func_00139F90();
extern void func_0013A030();
extern void func_00133BB8();
extern void func_00139F90(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00133BB8 */
/* libmpeg/libipu: IPU command word from the sync value; 2.9-ee-991111 */
extern s32 func_00124920(void);
extern void func_00124970_00133BB8(void);
void func_00133BB8(s32 a, s32 b) {
    u32 x;
    s32 ei;

    x = a;
    ei = func_00124920();
    if ((x >> 28) == 7) {
        x &= 0xFFFFFFF;
        x |= 0x80000000;
    } else {
        x &= 0xFFFFFFF;
    }
    *(volatile u32 *)0x1000B010 = x;
    *(volatile s32 *)0x1000B020 = b >> 4;
    *(volatile u32 *)0x1000B000 = 0x100;
    if (ei) {
        func_00124970_00133BB8();
    }
}
/* localdecomp:end func_00133BB8 */

/* localdecomp:start func_00133C58 */
typedef struct {
    u8 pad0[0x12C];
    int f12C;
    u8 pad130[0x13C - 0x130];
    int f13C;
    u8 pad140[0x1C0 - 0x140];
    int f1C0;
    int f1C4;
    u8 pad1C8[0x878 - 0x1C8];
    int f878;
} S_133C58;
void func_00134D68(void *s);
void func_00134D60(void *s);
int func_00132970(void *s, int n);
int func_00132888_00133C58(void *s, int n);
void func_00134C00_00133C58(void *s, int n);
int func_00132428(void *s);
void func_0013A150(void *s, char *fmt, int x);
extern s32 func_0013A0F8();
extern char D_00151DF8[];
extern char D_00151E20[];

int func_00133C58(S_133C58 *s, int a1, int *mbaddr, int *first, int *pred)
{
    int code;
    int v;

    s->f12C = 0;
    func_00134D68(s);
    while (func_00132970(s, 0x18) != 1 && s->f878 == 0) {
        func_00134C00_00133C58(s, 8);
    }
    code = func_00132970(s, 0x20);
    if ((u32)(code - 0x101) >= 0xAF) {
        func_0013A150(s, D_00151DF8, code);
        return 2;
    }
    func_00134D60(s);
    s->f1C4 = func_00132888_00133C58(s, 5);
    if (func_00132888_00133C58(s, 1)) {
        func_00132888_00133C58(s, 1);
        func_00134C00_00133C58(s, 7);
        while (func_00132888_00133C58(s, 1)) {
            func_00134C00_00133C58(s, 8);
        }
    }
    v = func_00132428(s);
    *first = v;
    if (s->f12C) {
        func_0013A0F8(s, D_00151E20);
        return 1;
    }
    *mbaddr = ((code & 0xFF) - 1) * s->f13C + v - 1;
    *first = 1;
    s->f1C0 = 1;
    pred[5] = 0;
    pred[4] = 0;
    pred[1] = 0;
    pred[0] = 0;
    pred[7] = 0;
    pred[6] = 0;
    pred[3] = 0;
    pred[2] = 0;
    return 0;
}
/* localdecomp:end func_00133C58 */

/* localdecomp:start func_00133DF8 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0x68 - 0x14];
} Fb_133DF8;

typedef struct {
    u8 pad0[0x10C];
    u32 f10C;
    u32 f110;
    u32 f114;
    s32 f118[3];
    s32 f124;
    u8 pad128[0x134 - 0x128];
    s32 f134;
    s32 f138;
    s32 f13C;
    s32 f140;
    u8 pad144[0x14C - 0x144];
    s32 f14C;
    s32 f150;
    s32 f154;
    u8 pad158[0x184 - 0x158];
    s32 f184;
    s32 f188;
    s32 f18C;
    u8 pad190[0x198 - 0x190];
    s32 f198;
    u8 pad19C[0x1F8 - 0x19C];
    Fb_133DF8 fb[9];
    u8 pad5A0[0x858 - 0x5A0];
    s32 f858;
    u8 pad85C[0x87C - 0x85C];
    s32 f87C;
} S_133DF8;

typedef struct {
    s32 w;
    s32 h;
    u8 pad8[0x40 - 8];
    S_133DF8 *q;
} H_133DF8;

extern void func_00136000();
extern u32 func_00136010();

static __inline__ void setfb_133DF8(Fb_133DF8 *f, s32 w, s32 h)
{
    f->f4 = w;
    f->f8 = h;
    f->fC = w >> 4;
    f->f10 = h >> 4;
}

void func_00133DF8(H_133DF8 *hd)
{
    S_133DF8 *q;
    s32 mode;
    s32 w;
    s32 h;
    u32 sz;
    u32 a;
    u32 b;
    u32 c;
    s32 k;
    s32 v;

    q = hd->q;
    mode = q->f858;
    if (mode == 0) {
        q->f184 = 3;
        q->f14C = 1;
        q->f150 = 1;
        q->f198 = 1;
        q->f18C = 1;
        q->f154 = 5;
    }
    q->f13C = (q->f134 + 15) >> 4;
    if (mode != 0 && q->f14C == 0) {
        v = ((q->f138 + 31) >> 5) << 1;
    } else {
        v = (q->f138 + 15) >> 4;
    }
    q->f140 = v;
    h = v << 4;
    w = q->f13C << 4;
    if (w == hd->w && h == hd->h) {
        return;
    }
    k = 0x180;
    hd->w = w;
    hd->h = h;
    sz = (u32)(w * (h * k)) >> 8;
    func_00136000(q->f118);
    q->f10C = func_00136010(q, q->f118, sz, 0x40);
    q->f110 = func_00136010(q, q->f118, sz, 0x40);
    q->f114 = func_00136010(q, q->f118, sz, 0x40);
    if (q->f87C == 0) {
        s32 n;
        a = (q->f10C & 0x0FFFFFFF) | 0x20000000;
        b = (q->f110 & 0x0FFFFFFF) | 0x20000000;
        c = (q->f114 & 0x0FFFFFFF) | 0x20000000;
        n = hd->w * hd->h / 512 * k;
        q->fb[0].f0 = a;
        q->fb[1].f0 = b;
        q->fb[2].f0 = c;
        q->fb[3].f0 = a;
        q->fb[4].f0 = b;
        q->fb[5].f0 = c;
        q->fb[6].f0 = a + n;
        q->fb[7].f0 = b + n;
        q->fb[8].f0 = c + n;
    } else if (q->f87C == 1) {
        s32 n;
        n = hd->w * hd->h / 512 * k;
        q->fb[0].f0 = q->f10C;
        q->fb[1].f0 = q->f110;
        q->fb[2].f0 = q->f114;
        q->fb[3].f0 = q->f10C;
        q->fb[4].f0 = q->f110;
        q->fb[5].f0 = q->f114;
        q->fb[6].f0 = q->f10C + n;
        q->fb[7].f0 = q->f110 + n;
        q->fb[8].f0 = q->f114 + n;
    }
    setfb_133DF8(&q->fb[0], w, h);
    setfb_133DF8(&q->fb[1], w, h);
    setfb_133DF8(&q->fb[2], w, h);
    setfb_133DF8(&q->fb[3], w, h / 2);
    setfb_133DF8(&q->fb[4], w, h / 2);
    setfb_133DF8(&q->fb[5], w, h / 2);
    setfb_133DF8(&q->fb[6], w, h / 2);
    setfb_133DF8(&q->fb[7], w, h / 2);
    setfb_133DF8(&q->fb[8], w, h / 2);
}
/* localdecomp:end func_00133DF8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134110);

/* localdecomp:start func_001343C0 */
void func_001343C0(u8 *p) {
    *(s32 *)(p + 0xFC) = 0;
    *(s32 *)(p + 0x864) = 1;
    *(s32 *)(p + 0x85C) = *(s32 *)(p + 0x860) + 1;
    func_00132888(p, 1);
    func_00132888(p, 5);
    func_00132888(p, 6);
    func_00132888(p, 1);
    func_00132888(p, 6);
    func_00132888(p, 6);
    *(s32 *)(p + 0x1B4) = func_00132888(p, 1);
    *(s32 *)(p + 0x1B8) = func_00132888(p, 1);
    func_001349F8(p);
}
/* localdecomp:end func_001343C0 */

/* localdecomp:start func_00134460 */
typedef struct {
    u8 pad0[0x160];
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
    s32 f170;
    u8 pad174[0x1BC - 0x174];
    s32 f1BC;
    u8 pad1C0[0x85C - 0x1C0];
    s32 f85C;
    s32 f860;
    s32 f864;
} S_134460;

extern u32 func_00132888();
extern void func_00134C00();
extern void func_001349F8();

void func_00134460(S_134460 *p)
{
    s32 tr;
    s32 flag;
    s32 prev;

    tr = func_00132888(p, 10);
    p->f160 = func_00132888(p, 3);
    func_00132888(p, 16);
    if (p->f160 == 2 || p->f160 == 3) {
        p->f164 = func_00132888(p, 1);
        p->f168 = func_00132888(p, 3);
    }
    if (p->f160 == 3) {
        p->f16C = func_00132888(p, 1);
        p->f170 = func_00132888(p, 3);
    }
    while (func_00132888(p, 1) != 0) {
        func_00134C00(p, 8);
    }
    func_001349F8(p);
    flag = 0;
    prev = 0;
    if (p->f160 != 3 && tr != 0) {
        if (tr < 0) {
            flag = p->f864 == 0;
        }
        p->f864 = 0;
        prev = tr;
    }
    p->f1BC = p->f85C + tr;
    if (flag && prev >= tr) {
        p->f1BC += 0x400;
    }
    p->f860 = (p->f860 < p->f1BC) ? p->f1BC : p->f860;
}
/* localdecomp:end func_00134460 */

/* localdecomp:start func_001345A8 */
typedef struct {
    u8 pad0[0x134];
    u32 f134;
    u32 f138;
    u8 pad13C[0x144 - 0x13C];
    int f144;
    int f148;
    int f14C;
    int f150;
    u8 pad154[0x858 - 0x154];
    int f858;
} S_1345A8;
extern char D_00151E60[];
extern char D_00151E88[];
int func_00132888_001345A8(void *s, int n);
extern s32 func_0013A0F8();

void func_001345A8(S_1345A8 *s)
{
    u32 v;
    u32 plid;
    u32 hext;
    u32 vext;
    u32 brext;
    u32 vbvext;

    s->f858 = 1;
    *(u32 *)0x10002010 &= ~0x800000;
    v = (u32)func_00132888_001345A8(s, 0x1C);
    brext = (v >> 1) & 0xFFF;
    s->f150 = (v >> 17) & 3;
    vext = (v >> 13) & 3;
    hext = (v >> 15) & 3;
    if (s->f150 != 1) {
        func_0013A0F8(s, D_00151E60);
    }
    s->f14C = (v >> 19) & 1;
    plid = v >> 20;
    vbvext = (u32)func_00132888_001345A8(s, 0x10) >> 8;
    if (plid != 0x48 && plid != 0x58 && plid != 0x44) {
        func_0013A0F8(s, D_00151E88);
    }
    s->f134 = (hext << 12) | (s->f134 & 0xFFF);
    s->f138 = (vext << 12) | (s->f138 & 0xFFF);
    s->f144 += brext << 18;
    s->f148 += vbvext << 10;
}
/* localdecomp:end func_001345A8 */

/* localdecomp:start func_001346E8 */
/* libmpeg: sequence extension flags (two IPU setup commands, two checks); 2.9-ee-991111 */
typedef struct {
    u8 pad0[0x828];
    s32 x828;           /* 0x828 */
    u32 x82C;           /* 0x82C */
    u8 pad830[0x850 - 0x830];
    u32 x850;           /* 0x850 */
    u32 x854;           /* 0x854 */
} S_1346E8;

extern u32 func_00132888();
extern void func_00134BC8(S_1346E8 *);
extern s32 func_0013A0F8();
extern char D_00151EA8[];
extern char D_00151ED0[];

static __inline__ void cmd_1346E8(S_1346E8 *p, u32 cmd) {
    *(volatile u32 *)0x10002000 = cmd;
    p->x82C = cmd & 0xF0000000;
    if (p->x82C == 0x20000000 || p->x82C == 0x30000000 || p->x82C == 0x40000000) {
        p->x828 = 0;
    } else {
        p->x828 = 1;
    }
}

void func_001346E8(S_1346E8 *p) {
    if ((p->x850 = func_00132888(p, 1)) != 0) {
        func_00134BC8(p);
        cmd_1346E8(p, 0x50000000);
        func_00134BC8(p);
    }
    if ((p->x854 = func_00132888(p, 1)) != 0) {
        func_00134BC8(p);
        cmd_1346E8(p, 0x58000000);
        func_00134BC8(p);
    }
    if (func_00132888(p, 1) != 0) {
        func_0013A0F8(p, D_00151EA8);
    }
    if (func_00132888(p, 1) != 0) {
        func_0013A0F8(p, D_00151ED0);
    }
}
/* localdecomp:end func_001346E8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001347D0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001347E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001347F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001349D8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001349E8);

/* localdecomp:start func_001349F8 */
/* libmpeg: walk the extension and user data start codes (0x1B5 / 0x1B2); 2.9-ee-991111 */
typedef struct { u8 pad[0x878]; s32 x878; } S_1349F8;
typedef struct { void (*f[11])(S_1349F8 *); } T_1349F8;

extern void func_00134D68_001349F8(S_1349F8 *);
extern void func_00134D60_001349F8(S_1349F8 *);
extern void func_00134C00_001349F8(S_1349F8 *, s32);
extern s32 func_00132970_001349F8(S_1349F8 *, s32);
extern u32 func_00132888_001349F8(S_1349F8 *, s32);
extern u8 D_00151FB8[];

static __inline__ void next_1349F8(S_1349F8 *p) {
    func_00134D68_001349F8(p);
    while (func_00132970_001349F8(p, 0x18) != 1) {
        if (p->x878 != 0) {
            break;
        }
        func_00134C00_001349F8(p, 8);
    }
}

void func_001349F8(S_1349F8 *p) {
    T_1349F8 tbl = *(T_1349F8 *)D_00151FB8;
    s32 c;

    next_1349F8(p);
    while ((c = func_00132970_001349F8(p, 0x20)) == 0x1B5 || c == 0x1B2) {
        if (c == 0x1B5) {
            u32 n;
            func_00134D60_001349F8(p);
            n = func_00132888_001349F8(p, 4);
            n = n > 10 ? 0 : n;
            tbl.f[n](p);
            next_1349F8(p);
        } else {
            func_00134D60_001349F8(p);
            next_1349F8(p);
        }
    }
}
/* localdecomp:end func_001349F8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134BC8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134C00);

/* localdecomp:start func_00134C08 */
typedef struct {
    u8 pad0[0x160];
    s32 f160;
    u8 pad164[0x838 - 0x164];
    long f838;
    long f840;
    u8 pad848[0x868 - 0x848];
    s32 f868;
    u8 pad86C[0x878 - 0x86C];
    s32 f878;
} S_134C08;

typedef struct {
    s32 type;
    s32 pad4;
    long f8;
    long f10;
} Cb_134C08;

extern void func_00134D68_00134C08();
extern void func_00134C00();
extern s32 func_00132970_00134C08();
extern u32 func_00132888();
extern void func_00134110();
extern void func_001343C0();
extern void func_00134460();
extern s32 func_00135D50(s32, s32 *);

s32 func_00134C08(S_134C08 *p)
{
    Cb_134C08 cb;

    for (;;) {
        if (p->f878 != 0) {
            return -1;
        }
        func_00134D68_00134C08(p);
        while (func_00132970_00134C08(p, 0x18) != 1 && p->f878 == 0) {
            func_00134C00(p, 8);
        }
        switch (func_00132888(p, 0x20)) {
        case 0x1B3:
            func_00134110(p);
            break;
        case 0x1B7:
            return 0;
        case 0x1B8:
            func_001343C0(p);
            break;
        case 0x100:
            func_00134460(p);
            cb.type = 5;
            cb.f8 = -1;
            cb.f10 = -1;
            func_00135D50(p->f868, (s32 *)&cb);
            p->f838 = cb.f8;
            p->f840 = cb.f10;
            return p->f160;
        }
    }
}
/* localdecomp:end func_00134C08 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134D60);

/* localdecomp:start func_00134D68 */
void func_00134D68(void *a) {
    s32 v;
    func_00134BC8(a);
    v = (-(*(volatile s32 *)0x10002020 & 7)) & 7;
    if (v != 0) {
        func_00134C00(a, v);
        return;
    }
}
/* localdecomp:end func_00134D68 */

/* localdecomp:start func_00134DB8 */
extern u32 func_00132888();

typedef struct {
    u8 pad[0x154];
    s32 f154;
    s32 f158;
    s32 f15C;
} S_134DB8;

void func_00134DB8(S_134DB8 *p) {
    func_00132888(p, 3);
    if (func_00132888(p, 1)) {
        func_00132888(p, 8);
        func_00132888(p, 8);
        p->f154 = func_00132888(p, 8);
    }
    p->f158 = func_00132888(p, 14);
    func_00132888(p, 1);
    p->f15C = func_00132888(p, 14);
}
/* localdecomp:end func_00134DB8 */

/* localdecomp:start func_00134E48 */
u32 func_00134E48(void *s) {
    func_00132888(s, 1);
    func_00132888(s, 8);
    func_00132888(s, 1);
    func_00132888(s, 7);
    func_00132888(s, 1);
    func_00132888(s, 0x14);
    func_00132888(s, 1);
    func_00132888(s, 0x16);
    func_00132888(s, 1);
    return func_00132888(s, 0x16);
}
/* localdecomp:end func_00134E48 */

/* localdecomp:start func_00134EE0 */
typedef struct {
    u8 pad0[0x14C];
    s32 f14C;
    u8 pad150[0x184 - 0x150];
    s32 f184;
    s32 f188;
    u8 pad18C[0x194 - 0x18C];
    s32 f194;
    u8 pad198[0x19C - 0x198];
    s32 hoff[3];
    s32 voff[3];
} S_134EE0;

extern u32 func_00132888();

void func_00134EE0(S_134EE0 *p)
{
    s32 n;
    s32 i;

    if (p->f14C != 0) {
        if (p->f194 != 0) {
            n = p->f188 ? 3 : 2;
        } else {
            n = 1;
        }
    } else {
        if (p->f184 != 3) {
            n = 1;
        } else {
            n = p->f194 ? 3 : 2;
        }
    }
    for (i = 0; i < n; i++) {
        p->hoff[i] = func_00132888(p, 16);
        func_00132888(p, 1);
        p->voff[i] = func_00132888(p, 16);
        func_00132888(p, 1);
    }
}
/* localdecomp:end func_00134EE0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134FD4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00134FD8);

/* localdecomp:start func_001350A8 */
typedef struct {
    u8 pad0[0x68];
} Fb_1350A8;

typedef struct {
    Fb_1350A8 *a;
    Fb_1350A8 *b;
    s32 pad;
    Fb_1350A8 *c;
} G_1350A8;

typedef struct {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[0x18 - 0x10];
    s32 f18;
    u8 pad1C[0x24 - 0x1C];
    s32 (*f24)();
    u8 pad28[0x30 - 0x28];
    s32 (*f30)();
    u8 pad34[0x3C - 0x34];
    s32 f3C;
    u8 pad40[0x48 - 0x40];
    s32 f48;
    u8 pad4C[0x54 - 0x4C];
    s32 f54;
    u8 pad58[0x60 - 0x58];
    s32 f60;
    s32 f64;
    u8 pad68[0x8C - 0x68];
    s32 f8C;
    long f90;
    s32 f98;
    s32 f9C;
    long fA0;
    s32 fA8;
    s32 fAC;
    s32 fB0;
    u8 padB4[0xC0 - 0xB4];
    s32 fC0;
    s32 fC4;
    s32 fC8[14];
    long f100;
    s32 f108;
    s32 f10C;
    s32 f110;
    s32 f114;
    s32 f118[4];
    u8 pad128[0x1C8 - 0x128];
    G_1350A8 g[3];
    Fb_1350A8 fb[9];
    u8 pad5A0[0x85C - 0x5A0];
    s32 f85C;
    s32 f860;
    s32 f864;
    void *f868;
} D_1350A8;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 padC[0x10 - 0xC];
    long f10;
    long f18;
    long f20;
    long f28;
    long f30;
    long f38;
    D_1350A8 *f40;
} M_1350A8;

extern char D_00152058[];
extern char D_00152008[];
extern char D_00152030[];
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_0013A0F8();
extern s32 func_0013A150_001350A8(void *, char *, ...);
extern void func_00135FD8();
extern u32 func_00136010();
extern void func_00134FD8();
extern s32 func_00135C60();
extern s32 func_00135E88();
extern s32 func_00135FF0();
extern s32 func_00136080();
extern s32 func_001360A8();

s32 func_001350A8(M_1350A8 *mp, u8 *work, s32 size)
{
    D_1350A8 *d;
    s32 off;
    s32 rest;
    u32 t;

    func_0011A264((s32)work, 0, size);
    d = (D_1350A8 *)((((u32)work + 3) >> 2) << 2);
    off = (u8 *)d - work;
    rest = size - off;
    if (rest < 0x19A0) {
        func_0013A0F8(d, D_00152058);
        return 0;
    }
    mp->f40 = d;
    func_00135FD8(d->f118, (u8 *)d + 0x19A0, rest - 0x19A0);
    mp->f0 = 0;
    mp->f4 = 0;
    mp->f8 = 0;
    mp->f10 = -1;
    mp->f18 = -1;
    mp->f20 = 0;
    mp->f28 = -1;
    mp->f30 = -1;
    mp->f38 = 0;
    d->fC8[0] = 0;
    d->fC8[1] = 0;
    d->fC8[2] = 0;
    d->fC8[3] = 0;
    d->fC8[4] = 0;
    d->fC8[5] = 0;
    d->fC8[6] = 0;
    d->fC8[7] = 0;
    d->fC8[8] = 0;
    d->fC8[9] = 0;
    d->fC8[10] = 0;
    d->fC8[11] = 0;
    d->fC8[12] = 0;
    d->fC8[13] = 0;
    d->f108 = 0;
    d->fC = 0;
    d->f18 = 0;
    d->f3C = 0;
    d->f48 = 0;
    d->f54 = 0;
    d->f100 = -1;
    d->f24 = func_00136080;
    d->f30 = func_001360A8;
    d->f60 = func_00136010(d, d->f118, 0x800, 8);
    d->f64 = 0;
    d->f10C = 0;
    d->f110 = 0;
    d->f114 = 0;
    d->f8C = 0;
    d->f90 = 0;
    d->f98 = -1;
    d->fA0 = 0;
    d->f9C = 0;
    d->fC0 = 0;
    d->fA8 = -1;
    d->fAC = -1;
    d->fB0 = -1;
    d->f868 = mp;
    d->fC4 = 1;
    func_00134FD8(d);
    func_00135C60(mp);
    func_00135E88(mp);
    d->g[0].a = &d->fb[0];
    d->g[0].b = &d->fb[1];
    d->g[0].c = &d->fb[2];
    d->g[1].a = &d->fb[3];
    d->g[1].b = &d->fb[4];
    d->g[1].c = &d->fb[5];
    d->g[2].a = &d->fb[6];
    d->g[2].b = &d->fb[7];
    d->g[2].c = &d->fb[8];
    func_00135FF0(d->f118);
    d->f860 = -1;
    d->f85C = 0;
    d->f864 = 0;
    /* _bstag and _idct alignment checks; both areas sit at 64-byte multiples in d */
    t = ((u32)d + 0x40) & 0x3F;
    if (t) {
        func_0013A150_001350A8(d, D_00152008, t);
        return 0;
    }
    t = ((u32)d + 0x80) & 0x3F;
    if (t) {
        func_0013A150_001350A8(d, D_00152030, t);
        return 0;
    }
    return 1;
}
/* localdecomp:end func_001350A8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001352E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001353A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135560);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135818);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135988);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135B50);

/* localdecomp:start func_00135C00 */
s32 func_00135C00(void) {
    return 1;
}
/* localdecomp:end func_00135C00 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00135C08);

/* localdecomp:start func_00135C10 */
typedef struct { u8 pad[0xC4]; s32 xC4; u8 pad2[0x24]; s32 xEC; s32 xF0; s32 xF4; s32 xF8; } T_135C10;
typedef struct { u8 pad[0x40]; T_135C10 *x40; } S_135C10;
extern void func_001353A8(S_135C10 *);
void func_00135C10(S_135C10 *p, u32 a, s32 b) {
    T_135C10 *q = p->x40;
    q->xC4 = 1;
    q->xEC = (a & 0x0FFFFFFF) | 0x20000000;
    q->xF8 = b;
    q->xF4 = 0;
    q->xF0 = 0;
    func_001353A8(p);
}
/* localdecomp:end func_00135C10 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00135C58);

/* localdecomp:start func_00135C60 */
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    u8 pC[0x98 - 0xC];
    s32 x98;
    u8 p9C[0xC0 - 0x9C];
    s32 xC0;
    u8 pC4[0x128 - 0xC4];
    s32 x128;
    u8 p12C[0x858 - 0x12C];
    s32 x858;
    u8 p85C[0x878 - 0x85C];
    s32 x878;
} S_135C60;

typedef struct {
    u8 p0[8];
    s32 x8;
    u8 pC[0x40 - 0xC];
    S_135C60 *x40;
} A_135C60;

extern void func_001352E0(S_135C60 *);

s32 func_00135C60(A_135C60 *a) {
    S_135C60 *p = a->x40;
    u32 v;

    p->x878 = 0;
    p->x0 = 0;
    p->x4 = 0;
    p->x8 = 0;
    a->x8 = 0;
    p->xC0 = 0;
    p->x98 = -1;
    func_001352E0(p);
    p->x128 = 0;
    p->x858 = 0;
    v = *(u32 *)0x10002010;
    *(u32 *)0x10002010 = (v & 0xFF7FFFFF) | 0x800000;
    return 1;
}
/* localdecomp:end func_00135C60 */

/* localdecomp:start func_00135CE0 */
s32 func_00135CE0(u8 *p) {
    return *(s32 *)(*(u8 **)(p + 0x40));
}
/* localdecomp:end func_00135CE0 */

/* localdecomp:start func_00135CF0 */
s32 func_00135CF0(void *a) {
    u8 *p = *(u8 **)((u8 *)a + 0x40);
    return *(s32 *)(p + 4) == 0;
}
/* localdecomp:end func_00135CF0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00135D00);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135D08);

LINKER_REMNANT("asm/boot_elf/remnants", func_00135D40);

LINKER_REMNANT("asm/boot_elf/remnants", func_00135D48);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135D50);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135DC8);

/* localdecomp:start func_00135E40 */
typedef struct { u8 pad[0x184]; s32 x184; } T_135E40;
typedef struct { u8 pad[0x40]; T_135E40 *x40; } S_135E40;
extern void func_00135818(S_135E40 *, s32, s32);
extern void func_00135988(S_135E40 *, s32, s32);
void func_00135E40(S_135E40 *p, s32 b, s32 c) {
    if (p->x40->x184 != 3) {
        func_00135988(p, b, c);
    } else {
        func_00135818(p, b, c);
    }
}
/* localdecomp:end func_00135E40 */

/* localdecomp:start func_00135E88 */
typedef struct { u8 pad[0x28]; s32 x28; } C_135E88;
typedef struct { u8 pad[0x1C8]; C_135E88 *a0; C_135E88 *b0; u8 p1[8]; C_135E88 *a1; C_135E88 *b1; u8 p2[8]; C_135E88 *a2; C_135E88 *b2; } T_135E88;
typedef struct { u8 pad[0x40]; T_135E88 *x40; } S_135E88;
s32 func_00135E88(S_135E88 *p) {
    T_135E88 *q = p->x40;
    if (q->a0 != 0) q->a0->x28 = 0;
    if (q->a1 != 0) q->a1->x28 = 0;
    if (q->a2 != 0) q->a2->x28 = 0;
    if (q->b0 != 0) q->b0->x28 = 0;
    if (q->b1 != 0) q->b1->x28 = 0;
    if (q->b2 != 0) q->b2->x28 = 0;
    return 1;
}
/* localdecomp:end func_00135E88 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00135EE0);

LINKER_REMNANT("asm/boot_elf/remnants", func_00135F00);

/* localdecomp:start func_00135F08 */
typedef struct {
    u8 pad[0x28];
    s32 x28;
} Pic_135F08;

typedef struct {
    u8 pad[0x130];
    s32 x130;
    u8 pad134[0x50];
    s32 x184;
    u8 pad188[0x48];
    Pic_135F08 *x1D0;
    u8 pad1D4[0xC];
    Pic_135F08 *x1E0;
    u8 pad1E4[0xC];
    Pic_135F08 *x1F0;
} Dec_135F08;

extern char D_00152138[];
extern char D_00152158[];
extern s32 func_0013A0F8();
extern s32 func_00131398(Dec_135F08 *);

s32 func_00135F08(Dec_135F08 *d) {
    Pic_135F08 *p;
    s32 r;

    if (d->x184 == 3 && d->x130 != 0) {
        func_0013A0F8(d, D_00152138);
        d->x130 = 0;
    }
    switch (d->x184) {
    case 3:
        p = d->x1D0;
        break;
    case 1:
        p = d->x1E0;
        break;
    case 2:
        p = d->x1F0;
        break;
    default:
        p = d->x1D0;
        func_0013A0F8(d, D_00152158);
        break;
    }
    r = func_00131398(d);
    if (r != 0) {
        p->x28 = 1;
    }
    return r;
}
/* localdecomp:end func_00135F08 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00135FD4);

/* localdecomp:start func_00135FD8 */
void func_00135FD8(s32 *p, s32 a, s32 b) {
    p[1] = b;
    p[0] = a;
    p[2] = a;
    p[3] = a;
}
/* localdecomp:end func_00135FD8 */

/* localdecomp:start func_00135FF0 */
s32 func_00135FF0(s32 *p) {
    p[3] = p[2];
}
/* localdecomp:end func_00135FF0 */

/* localdecomp:start func_00136000 */
void func_00136000(s32 *p) {
    p[2] = p[3];
}
/* localdecomp:end func_00136000 */

/* localdecomp:start func_00136010 */
typedef struct { u32 x0; u32 x4; u32 x8; } S_136010;
extern s32 func_0013A0F8();
extern char D_00152178[];
u32 func_00136010(s32 a, S_136010 *s, u32 c, u32 al) {
    u32 off = (s->x8 + al - 1) / al * al;
    if (s->x0 + s->x4 < off + c) {
        func_0013A0F8(a, D_00152178);
        return 0;
    }
    s->x8 = off + c;
    return off;
}
/* localdecomp:end func_00136010 */

/* localdecomp:start func_00136080 */
typedef struct { u8 pad[0x40]; u8 *x40; } S_136080;
extern void func_0013A280(u8 *);
s32 func_00136080(S_136080 *p) {
    func_0013A280(p->x40 + 0x68);
    return 1;
}
/* localdecomp:end func_00136080 */

/* localdecomp:start func_001360A8 */
typedef struct { u8 pad[0x40]; u8 *x40; } S_1360A8;
extern void func_0013A368(u8 *);
s32 func_001360A8(S_1360A8 *p) {
    func_0013A368(p->x40 + 0x68);
    return 1;
}
/* localdecomp:end func_001360A8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001360CC);

/* localdecomp:start func_001360D0 */
typedef struct {
    u8 pad0[0xEC];
    u32 fEC;
    u8 padF0[4];
    int fF4;
    int fF8;
    u8 padFC[0x184 - 0xFC];
    int f184;
} S_1360D0;
typedef struct {
    u32 f0;
    u8 pad4[0xC - 4];
    int fC;
    int f10;
} In_1360D0;
int func_00124920(void);
int func_00124970(void);

void func_001360D0(S_1360D0 *s, In_1360D0 *in)
{
    u32 src;
    u32 dst;
    int n;
    int q;
    int stride;
    int cnt;
    u32 base;
    int i;
    int j;
    int di;
    u32 a;
    u32 b;

    src = in->f0 & 0x0FFFFFFF;
    base = s->fEC & 0x0FFFFFFF;
    if (s->f184 == 3 || s->fF4 == 0) {
        n = in->f10 * 0x180;
        q = n >> 4;
        if (s->fF4) {
            stride = (s->fF4 >> 4) * 0x180;
        } else {
            stride = n;
        }
        cnt = 1;
    } else {
        stride = (s->fF4 >> 4) * 0xC0;
        n = (in->f10 >> 1) * 0x180;
        q = n >> 4;
        cnt = 2;
    }
    for (i = 0; i < cnt; i++) {
        dst = base;
        for (j = 0; j < in->fC; j++) {
            di = func_00124920();
            *(volatile u32 *)0x1000D480 = 0;
            *(volatile u32 *)0x1000D410 = src;
            *(volatile u32 *)0x1000D420 = q;
            *(volatile u32 *)0x1000D400 = 0x101;
            if (di) {
                func_00124970();
            }
            a = src + n;
            b = dst + stride;
            while (*(volatile u32 *)0x1000D400 & 0x100) {
            }
            di = func_00124920();
            *(volatile u32 *)0x1000D080 = 0;
            *(volatile u32 *)0x1000D010 = dst;
            *(volatile u32 *)0x1000D020 = q;
            *(volatile u32 *)0x1000D000 = 0x100;
            if (di) {
                func_00124970();
            }
            while (*(volatile u32 *)0x1000D000 & 0x100) {
            }
            while (*(volatile u32 *)0x1000D020) {
            }
            dst = b;
            src = a;
        }
        base += s->fF8 * 0xC0;
    }
}
/* localdecomp:end func_001360D0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00136360);

/* localdecomp:start func_00136620 */
typedef struct {
    u8 pad0[4];
    int f4;
    int f8;
    int fC;
    int f10;
    u8 pad14[4];
    long f18;
    long f20;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    int f50;
    int f54;
    int f58;
    int f5C;
    int f60;
} In_136620;
typedef struct {
    long a;
    long b;
    long c;
} TS_136620;
typedef struct {
    u8 pad0[0x10];
    TS_136620 ts[2];
} Out_136620;
typedef struct {
    u8 pad0[8];
    int f8;
    u8 padC[0x8C - 0xC];
    int f8C;
    long f90;
    int f98;
    int f9C;
    long fA0;
    u8 padA8[0xC0 - 0xA8];
    int fC0;
    int fC4;
    int fC8;
    int fCC;
    int fD0;
    int fD4;
    int fD8;
    u8 padDC[0xE0 - 0xDC];
    int fE0;
    int fE4;
    u8 padE8[0xF0 - 0xE8];
    int fF0;
    int fF4;
    int fF8;
    u8 padFC[0x100 - 0xFC];
    long f100;
    int f108;
    u8 pad10C[0x128 - 0x10C];
    int f128;
    u8 pad12C[0x184 - 0x12C];
    int f184;
    u8 pad188[0x834 - 0x188];
    int f834;
    u8 pad838[0x868 - 0x838];
    Out_136620 *f868;
} S_136620;
extern char D_00152198[];
int func_00121718(char *buf, int n, const char *fmt, ...);
void func_00136D50();
void func_001360D0();

static inline void ts_136620(S_136620 *s, long *pa, long *pb, long *pc, In_136620 *in)
{
    long t;
    int n;
    int odd;
    int b;

    if (s->f8C && in->f18 < 0 && s->f98 >= 0) {
            n = s->fA0;
            b = n & 1;
            { long q = s->f90 & 1; long r = s->f9C & 1; odd = b & r & q; }
            *pa = s->f98 + ((int)((s->f90 * n) >> 1) + odd);
            if (b & s->f90) {
                s->f9C++;
            }
    } else {
        *pa = in->f18;
    }
    if (s->f108 == 2 && s->f100 >= 0) {
        *pa = s->f100;
        s->f108 = 0;
        s->f100 = -1;
    }
    *pb = in->f20;
    *pc = (long)in->f34 << 8 | (long)in->f38 << 7 | (long)in->f3C << 6 | (long)in->f40 << 5 | (long)in->f30 << 3 | in->f2C;
}

static inline int chk_136620(S_136620 *s, In_136620 *a1)
{
    char buf[0x100];
    int ok;

    if (s->fF4) {
        ok = s->fF0 >= a1->f4 && s->fF4 >= a1->f8;
    } else {
        ok = s->fF8 >= a1->fC * a1->f10;
    }
    if (!ok) {
        func_00121718(buf, 0x100, D_00152198, a1->f4, a1->f8);
        func_0013A0F8(s, buf);
    }
    return ok;
}

void func_00136620(S_136620 *s, In_136620 *a1, In_136620 *a2, int n)
{
    int flag;
    In_136620 *top;
    In_136620 *bot;

    flag = 0;
    if (s->f184 == 2) {
        top = a1;
        bot = a2;
        flag = 0x40;
    } else {
        top = a2;
        bot = a1;
    }
    ts_136620(s, &s->f868->ts[0].a, &s->f868->ts[0].b, &s->f868->ts[0].c, top);
    s->f98 = s->f868->ts[0].a;
    s->fA0 = 1;
    ts_136620(s, &s->f868->ts[1].a, &s->f868->ts[1].b, &s->f868->ts[1].c, bot);
    s->f98 = s->f868->ts[1].a;
    s->fA0 = 1;
    s->f868->ts[0].c |= flag;
    s->f868->ts[1].c |= flag;
    s->fE0 = top->f5C;
    s->fE4 = top->f60;
    s->fC8 = top->f44;
    s->fCC = bot->f48;
    s->fD4 = top->f50;
    s->fD8 = bot->f54;
    if (chk_136620(s, a1) && a1->f28 == 1 && a2->f28 == 1) {
        a1->f10 <<= 1;
        if (s->fC4) {
            func_00136D50(s, a1);
        } else {
            func_001360D0(s, a1);
        }
        a1->f10 >>= 1;
        if (s->f8 != 2) {
            s->f8 = 2;
            s->fC0 = s->f128;
        }
        s->f834 = 1;
    }
}
/* localdecomp:end func_00136620 */

/* localdecomp:start func_00136A40 */
typedef struct {
    u8 pad0[4];
    int f4;
    int f8;
    u8 padC[0xC0 - 0xC];
    int fC0;
    u8 padC4[0x128 - 0xC4];
    int f128;
    u8 pad12C[0x130 - 0x12C];
    int f130;
    u8 pad134[0x184 - 0x134];
    int f184;
    u8 pad188[0x1CC - 0x188];
    int f1CC;
    u8 pad1D0[0x1DC - 0x1D0];
    In_136620 *f1DC;
    u8 pad1E0[0x1EC - 0x1E0];
    In_136620 *f1EC;
} S_136A40;
typedef struct {
    u8 pad0[8];
    int f8;
    u8 padC[0x40 - 0xC];
    S_136A40 *f40;
} O_136A40;
extern char D_001521C8[];
extern void func_00136360(S_136A40 *s, int a, int b);
void func_00136620(S_136620 *s, In_136620 *a1, In_136620 *a2, int n);

int func_00136A40(O_136A40 *o)
{
    S_136A40 *s;
    int ret;
    int n;

    s = o->f40;
    ret = 0;
    if (s->f4 != 0 && s->f8 != 0) {
        n = s->f128;
        if (s->f130) {
            func_0013A0F8(s, D_001521C8, n);
        } else if (s->f184 == 3) {
            func_00136360(s, s->f1CC, n - 1);
        } else {
            func_00136620((S_136620 *)s, s->f1DC, s->f1EC, n - 1);
        }
        ret = 1;
        s->f130 = 0;
        o->f8 = s->f128 - s->fC0;
        s->f4 = 0;
    }
    return ret;
}
/* localdecomp:end func_00136A40 */

/* localdecomp:start func_00136B00 */
typedef struct {
    u8 pad0[0x108];
    s32 f108;
    u8 pad10C[0x160 - 0x10C];
    s32 f160;
    u8 pad164[0x184 - 0x164];
    s32 f184;
    u8 pad188[0x1C8 - 0x188];
    s32 f1C8;
    u8 pad1CC[0x1D4 - 0x1CC];
    s32 f1D4;
    u8 pad1D8[0x1D8 - 0x1D8];
    s32 f1D8;
    u8 pad1DC[0x1E4 - 0x1DC];
    s32 f1E4;
    u8 pad1E8[0x1E8 - 0x1E8];
    s32 f1E8;
    u8 pad1EC[0x1F4 - 0x1EC];
    s32 f1F4;
} S_136B00;

void func_00136B00(S_136B00 *p, s32 a, s32 n) {
    s32 s1;
    s32 s2;

    if (n != 0) {
        if (p->f184 == 3) {
            if (p->f160 == 3) {
                s1 = p->f1D4;
            } else {
                s1 = p->f1C8;
            }
            func_00136360((S_136A40 *)p, s1, a - 1);
        } else {
            if (p->f160 == 3) {
                s1 = p->f1E4;
                s2 = p->f1F4;
            } else {
                s1 = p->f1D8;
                s2 = p->f1E8;
            }
            func_00136620((S_136620 *)p, (In_136620 *)s1, (In_136620 *)s2, a - 1);
        }
    }
    if (p->f108 == 1) {
        p->f108 = 2;
    }
}
/* localdecomp:end func_00136B00 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00136B90);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00136D50);

ASM_FUNC("asm/boot_elf/handwritten", func_00137228);

ASM_FUNC("asm/boot_elf/handwritten", func_00137370);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00137444);

/* localdecomp:start func_00137450 */
/* libmpeg: skip a PS system header (then its stream entries); 2.9-ee-991111 */
typedef struct {
    u64 buf;
    u64 pos;
    u32 x10;
    u8 *ptr;
    s32 bits;
    u8 *start;
    u8 *end;
} BS_137450;

static __inline__ void skip_137450(BS_137450 *bs, s32 n) {
    bs->buf <<= n;
    bs->bits -= n;
    while (bs->bits <= 56) {
        bs->buf |= (u64)*bs->ptr++ << (56 - bs->bits);
        if (bs->ptr >= bs->end) bs->ptr = bs->start;
        bs->bits += 8;
    }
    bs->pos += n;
}

static __inline__ u32 show_137450(BS_137450 *bs, s32 n) {
    return bs->buf >> (64 - n);
}

s32 func_00137450(BS_137450 *bs) {
    skip_137450(bs, 56);
    skip_137450(bs, 40);
    while (show_137450(bs, 1) == 1) {
        skip_137450(bs, 24);
    }
    return 1;
}
/* localdecomp:end func_00137450 */

/* localdecomp:start func_00137620 */
typedef struct {
    u64 buf;
    u64 pos;
    u32 x10;
    u8 *ptr;
    s32 bits;
    u8 *start;
    u8 *end;
} BS_137620;

typedef struct {
    u32 ext;
    u32 scr;
    u32 scr_hi;
    u32 sys;
} PH_137620;

extern void func_00137450_00137620(BS_137620 *, PH_137620 *);

static __inline__ void skip_137620(BS_137620 *bs, s32 n) {
    bs->buf <<= n;
    bs->bits -= n;
    while (bs->bits <= 56) {
        bs->buf |= (u64)*bs->ptr++ << (56 - bs->bits);
        if (bs->ptr >= bs->end) bs->ptr = bs->start;
        bs->bits += 8;
    }
    bs->pos += n;
}

static __inline__ u32 getbits_137620(BS_137620 *bs, s32 n) {
    u32 v = bs->buf >> (64 - n);
    skip_137620(bs, n);
    return v;
}

s32 func_00137620(BS_137620 *bs, PH_137620 *ph) {
    u32 a, b, c, n, i;

    skip_137620(bs, 34);
    a = getbits_137620(bs, 3);
    skip_137620(bs, 1);
    b = getbits_137620(bs, 15);
    skip_137620(bs, 1);
    c = getbits_137620(bs, 15);
    skip_137620(bs, 1);
    ph->ext = getbits_137620(bs, 9);
    skip_137620(bs, 30);
    n = getbits_137620(bs, 3);
    ph->scr = (a << 30) | (b << 15) | c;
    ph->scr_hi = a >> 2;
    for (i = 0; i < n; i++) {
        skip_137620(bs, 8);
    }
    if ((s32)(bs->buf >> 32) == 0x1BB) {
        ph->sys = 1;
        func_00137450_00137620(bs, ph);
    } else {
        ph->sys = 0;
    }
    return 1;
}
/* localdecomp:end func_00137620 */

/* localdecomp:start func_00137CC8 */
/* MPEG-2 program stream: parse one PES packet header from the bit reader bs into out
   (Sony libmpeg, built with ee-gcc 2.9-ee-991111). */
typedef struct {
    unsigned long buf;   /* 0x00 */
    unsigned long pos;   /* 0x08: bit position */
    u8 *base;            /* 0x10 */
    u8 *ptr;             /* 0x14 */
    s32 cnt;             /* 0x18 */
    u8 *top;             /* 0x1C */
    u8 *end;             /* 0x20 */
    s32 size;            /* 0x24 */
} BS_137CC8;

typedef struct {
    unsigned long id;    /* 0x00 */
    u32 len;             /* 0x08 */
    u32 scr;             /* 0x0C */
    unsigned long pts;   /* 0x10 */
    unsigned long dts;   /* 0x18 */
    u32 datapos;         /* 0x20 */
    s32 datalen;         /* 0x24 */
    u32 pktpos;          /* 0x28 */
} PES_137CC8;

typedef struct { u8 b[16]; } T16_137CC8;
extern const T16_137CC8 D_00152200;
extern char D_00152210[];

/* Refill the 64-bit bit buffer a byte at a time from the ring buffer. */
static __inline__ void fill_137CC8(BS_137CC8 *bs) {
    while (bs->cnt < 57) {
        bs->buf |= (unsigned long)*bs->ptr++ << (56 - bs->cnt);
        if (bs->ptr >= bs->end) bs->ptr = bs->top;
        bs->cnt += 8;
    }
}

static __inline__ u32 getbits_137CC8(BS_137CC8 *bs, s32 n) {
    u32 v;
    v = bs->buf >> (64 - n);
    bs->buf <<= n;
    bs->cnt -= n;
    fill_137CC8(bs);
    bs->pos += n;
    return v;
}

static __inline__ void skipbits_137CC8(BS_137CC8 *bs, s32 n) {
    bs->buf <<= n;
    bs->cnt -= n;
    fill_137CC8(bs);
    bs->pos += n;
}

static __inline__ void seek_137CC8(BS_137CC8 *bs, s32 n) {
    bs->buf = 0;
    bs->cnt = 0;
    bs->pos += n * 8;
    bs->ptr = bs->base + (s32)(bs->pos >> 3);
    if (bs->ptr >= bs->end) bs->ptr -= bs->size;
    skipbits_137CC8(bs, 0);
}

s32 func_00137CC8(void *ctx, BS_137CC8 *bs, PES_137CC8 *out) {
    T16_137CC8 tbl = D_00152200;
    u32 v;
    u32 ptsdts, escr, flags, ext, hlen;
    s32 start;
    s32 len;

    out->pktpos = bs->pos;
    skipbits_137CC8(bs, 24);
    out->id = (unsigned long)getbits_137CC8(bs, 8) << 32;
    v = getbits_137CC8(bs, 16);
    out->len = v;
    out->dts = -1;
    out->pts = -1;
    if (out->id != 0xBC00000000 && out->id != 0xBE00000000 && out->id != 0xBF00000000
        && out->id != 0xF000000000 && out->id != 0xF100000000 && out->id != 0xFF00000000
        && out->id != 0xF200000000 && out->id != 0xF800000000) {
        skipbits_137CC8(bs, 2);
        v = getbits_137CC8(bs, 2);
        out->scr = v;
        skipbits_137CC8(bs, 4);
        ptsdts = getbits_137CC8(bs, 2);
        escr = getbits_137CC8(bs, 1);
        flags = getbits_137CC8(bs, 4);
        ext = getbits_137CC8(bs, 1);
        hlen = getbits_137CC8(bs, 8);
        start = bs->pos;
        if (ptsdts & 2) {
            u32 a, b, c, lo;
            skipbits_137CC8(bs, 4);
            a = getbits_137CC8(bs, 3);
            skipbits_137CC8(bs, 1);
            b = getbits_137CC8(bs, 15);
            skipbits_137CC8(bs, 1);
            c = getbits_137CC8(bs, 15);
            skipbits_137CC8(bs, 1);
            lo = (a << 30) | (b << 15) | c;
            out->pts = (((unsigned long)(a >> 2)) << 32) | lo;
        }
        if (ptsdts == 3) {
            u32 a, b, c, lo;
            skipbits_137CC8(bs, 4);
            a = getbits_137CC8(bs, 3);
            skipbits_137CC8(bs, 1);
            b = getbits_137CC8(bs, 15);
            skipbits_137CC8(bs, 1);
            c = getbits_137CC8(bs, 15);
            skipbits_137CC8(bs, 1);
            lo = (a << 30) | (b << 15) | c;
            out->dts = (((unsigned long)(a >> 2)) << 32) | lo;
        }
        if (escr == 1) {
            skipbits_137CC8(bs, 48);
        }
        if (flags) {
            s32 n = tbl.b[flags];
            skipbits_137CC8(bs, n);
        }
        if (ext == 1) {
            u32 priv, pack, seq, pstd, ext2;
            priv = getbits_137CC8(bs, 1);
            pack = getbits_137CC8(bs, 1);
            seq = getbits_137CC8(bs, 1);
            pstd = getbits_137CC8(bs, 1);
            skipbits_137CC8(bs, 3);
            ext2 = getbits_137CC8(bs, 1);
            if (priv == 1) {
                skipbits_137CC8(bs, 48);
                skipbits_137CC8(bs, 48);
                skipbits_137CC8(bs, 32);
            }
            if (pack == 1) {
                func_0013A0F8(ctx, D_00152210);
                return 0;
            }
            if (seq == 1) {
                skipbits_137CC8(bs, 16);
            }
            if (pstd == 1) {
                skipbits_137CC8(bs, 16);
            }
            if (ext2 == 1) {
                u32 n, i;
                skipbits_137CC8(bs, 1);
                n = getbits_137CC8(bs, 7);
                for (i = 0; i < n; i++) {
                    skipbits_137CC8(bs, 8);
                }
            }
        }
        {
            s32 k = hlen - (s32)((bs->pos - start) >> 3);
            if (k) {
                seek_137CC8(bs, k);
            }
        }
        len = out->len - hlen - 3;
        out->datalen = len;
        out->datapos = bs->pos;
        if (out->id == 0xBD00000000) {
            out->id |= getbits_137CC8(bs, 32);
            len -= 4;
        }
        if (len) {
            seek_137CC8(bs, len);
        }
    } else if (out->id == 0xBC00000000 || out->id == 0xBF00000000 || out->id == 0xF000000000
               || out->id == 0xF100000000 || out->id == 0xFF00000000 || out->id == 0xF200000000
               || out->id == 0xF800000000) {
        s32 n = out->len;
        if (out->id == 0xBF00000000) {
            out->id |= getbits_137CC8(bs, 32);
            n -= 4;
        }
        if (n) {
            seek_137CC8(bs, n);
        }
    } else if (out->id == 0xBE00000000) {
        s32 n = out->len;
        if (n) {
            seek_137CC8(bs, n);
        }
    }
    return 1;
}
/* localdecomp:end func_00137CC8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00139A70);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00139E50);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00139F80);

/* localdecomp:start func_00139F90 */
extern s32 func_00124920(void);
extern s32 func_00124970(void);

void func_00139F90(void) {
    s32 r;
    volatile s32 *p7;
    volatile s32 *p8;

    r = func_00124920();
    p7 = (volatile s32 *)0x1000F520;
    p8 = (volatile s32 *)0x1000F590;
    *p8 = *p7 | 0x10000;
    *(volatile s32 *)0x1000B000 = 0;
    *(volatile s32 *)0x1000B400 = 0;
    *p8 = *p7 & 0xFFFEFFFF;
    if (r != 0) {
        func_00124970();
    }
    *(volatile s32 *)0x1000B020 = 0;
    *(volatile s32 *)0x1000B420 = 0;
    *(volatile s32 *)0x10002010 = 0x40000000;
}
/* localdecomp:end func_00139F90 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A030);

/* localdecomp:start func_0013A0F8 */
typedef struct { u8 pad[0xC]; s32 xC; u8 pad2[0x858]; s32 x868; } S_13A0F8;
extern s32 func_00135D50(s32, s32 *);
extern s32 func_00139F80(s32);
s32 func_0013A0F8(S_13A0F8 *p, s32 b) {
    s32 q = p->x868;
    if (q != 0 && p != 0 && p->xC != 0) {
        s32 buf[2];
        buf[1] = b;
        buf[0] = 0;
        return func_00135D50(q, buf);
    }
    return func_00139F80(b);
}
/* localdecomp:end func_0013A0F8 */

/* localdecomp:start func_0013A150 */
void func_0013A150(void *s, char *fmt, int x) {
    char buf[0x100];
    func_00121718(buf, 0x100, fmt, x);
    func_0013A0F8(s, buf);
}
/* localdecomp:end func_0013A150 */

/* localdecomp:start func_0013A190 */
void func_0013A190(s32 a) {
    s32 r;
    r = func_00124920();
    *(volatile s32 *)0x1000F590 = *(volatile s32 *)0x1000F520 | 0x10000;
    *(volatile s32 *)0x1000B000 = a;
    *(volatile s32 *)0x1000F590 = *(volatile s32 *)0x1000F520 & 0xFFFEFFFF;
    if (r != 0) {
        func_00124970();
    }
}
/* localdecomp:end func_0013A190 */

/* localdecomp:start func_0013A208 */
extern s32 func_00124920(void);
extern s32 func_00124970(void);
void func_0013A208(s32 x) {
    s32 r;
    r = func_00124920();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile s32 *)0x1000B400 = x;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & 0xFFFEFFFF;
    if (r != 0) {
        func_00124970();
    }
}
/* localdecomp:end func_0013A208 */

/* localdecomp:start func_0013A280 */
extern void func_0013A208(s32);
extern void func_0013A190(s32);

void func_0013A280(u8 *p)
{
    u32 *s = (u32 *)p;

    func_0013A208(1);
    s[0] = *(volatile u32 *)0x1000B410;
    s[1] = *(volatile u32 *)0x1000B430;
    s[2] = *(volatile u32 *)0x1000B420;
    s[3] = *(volatile u32 *)0x1000B400;
    while (*(volatile u32 *)0x10002010 & 0xF0) {
    }
    func_0013A190(0);
    s[4] = *(volatile u32 *)0x1000B010;
    s[5] = *(volatile u32 *)0x1000B020;
    s[6] = *(volatile u32 *)0x1000B000;
    s[7] = *(volatile u32 *)0x10002020;
    s[8] = *(volatile u32 *)0x10002010;
}
/* localdecomp:end func_0013A280 */

/* localdecomp:start func_0013A368 */
/* libipu: restore the IPU and its DMA channels from a saved state; 2.9-ee-991111 */
typedef struct {
    u32 d4madr;     /* 0x00 */
    u32 d4tadr;     /* 0x04 */
    u32 d4qwc;      /* 0x08 */
    u32 d4chcr;     /* 0x0C */
    u32 d3madr;     /* 0x10 */
    u32 d3qwc;      /* 0x14 */
    u32 d3chcr;     /* 0x18 */
    u32 ipubp;      /* 0x1C */
} E_13A368;

extern void func_0013A190_0013A368(u32);
extern void func_0013A208_0013A368(u32);

void func_0013A368(u8 *arg) {
    E_13A368 *e = (E_13A368 *)arg;
    u32 bp = e->ipubp;
    u32 cmd = bp & 0x7F;
    u32 n = ((bp >> 16) & 3) + ((bp >> 8) & 0xF);
    u32 madr = e->d4madr - n * 16;
    u32 qwc = e->d4qwc + n;

    if (e->d3madr != 0 && e->d3qwc != 0) {
        *(volatile u32 *)0x1000B010 = e->d3madr;
        *(volatile u32 *)0x1000B020 = e->d3qwc;
        func_0013A190_0013A368(e->d3chcr | 0x100);
    }
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile u32 *)0x10002000 = cmd;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    if (madr != 0 && qwc != 0) {
        *(volatile u32 *)0x1000B410 = madr;
        *(volatile u32 *)0x1000B430 = e->d4tadr;
        *(volatile u32 *)0x1000B420 = qwc;
        func_0013A208_0013A368(e->d4chcr | 0x100);
    }
}
/* localdecomp:end func_0013A368 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013A4B8);

/* localdecomp:start func_0013A520 */
void func_0013A520(s32 a) {
    s32 r = func_00124920();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile s32 *)0x1000B400 = a;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & 0xFFFEFFFF;
    if (r != 0) {
        func_00124970();
    }
}
/* localdecomp:end func_0013A520 */

/* localdecomp:start func_0013A598 */
typedef int u128_13A598 __attribute__((mode(TI)));
extern volatile u128_13A598 D_001417B0[];
extern u128_13A598 D_00141800[];
void func_0013A520(int x);

#define IPU_CMD_13A598 (*(volatile u32 *)0x10002000)
#define IPU_CTRL_13A598 (*(volatile s32 *)0x10002010)
#define IPU_IN_13A598 (*(volatile u128_13A598 *)0x10007010)

void func_0013A598(void)
{
    func_0013A520(1);
    IPU_CTRL_13A598 = 0x40000000;
    while (IPU_CTRL_13A598 < 0) {
    }
    IPU_CMD_13A598 = 0;
    while (IPU_CTRL_13A598 < 0) {
    }
    IPU_IN_13A598 = D_001417B0[0];
    IPU_IN_13A598 = D_001417B0[1];
    IPU_IN_13A598 = D_001417B0[2];
    IPU_IN_13A598 = D_001417B0[3];
    IPU_IN_13A598 = D_001417B0[4];
    IPU_IN_13A598 = D_001417B0[4];
    IPU_IN_13A598 = D_001417B0[4];
    IPU_IN_13A598 = D_001417B0[4];
    IPU_CMD_13A598 = 0x50000000;
    while (IPU_CTRL_13A598 < 0) {
    }
    IPU_CMD_13A598 = 0x58000000;
    while (IPU_CTRL_13A598 < 0) {
    }
    IPU_IN_13A598 = D_00141800[0];
    IPU_IN_13A598 = D_00141800[1];
    IPU_CMD_13A598 = 0x60000000;
    while (IPU_CTRL_13A598 < 0) {
    }
    IPU_CMD_13A598 = 0x90000000;
    while (IPU_CTRL_13A598 < 0) {
    }
    IPU_CTRL_13A598 = 0x40000000;
    while (IPU_CTRL_13A598 < 0) {
    }
    IPU_CMD_13A598 = 0;
    while (IPU_CTRL_13A598 < 0) {
    }
}
/* localdecomp:end func_0013A598 */

/* localdecomp:start func_0013A7D0 */
extern s8 D_00141838_0013A7D0[];
extern char D_00152270_0013A7D0[];
extern s32 func_00123430();
extern void func_00123840();
extern void func_001236C0();

s8 *func_0013A7D0(void) {
    s32 r;
    if (D_00141838_0013A7D0[0] == 0) {
        r = func_00123430(D_00152270_0013A7D0, 1);
        if (r >= 0) {
            func_00123840(r, D_00141838_0013A7D0, 0xE);
            func_001236C0(r);
        }
    }
    return D_00141838_0013A7D0;
}
/* localdecomp:end func_0013A7D0 */

/* localdecomp:start func_0013A840 */
extern u8 D_00141838[];
extern void func_0013A7D0_0013A840(void);
s32 func_0013A840(void) {
    s8 *p = (s8 *)D_00141838;
    if (*p == 0) {
        func_0013A7D0_0013A840();
    }
    return *(s8 *)(p + 4) == 0x54;
}
/* localdecomp:end func_0013A840 */

/* localdecomp:start func_0013A880 */
extern s32 func_0013A840(void);
extern void func_0011EED0(u32 *);
extern u8 D_00141834[];
s32 func_0013A880(void) {
    u32 buf[4];
    s32 r;
    func_0011EED0(buf);
    if (func_0013A840() != 0) {
        r = D_00141834[0];
    } else {
        func_0011EED0(buf);
        if (((buf[0] >> 13) & 7) == 0) {
            r = (buf[0] >> 4) & 1;
        } else {
            r = (buf[0] >> 16) & 0x1F;
        }
    }
    return r;
}
/* localdecomp:end func_0013A880 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013A8E0);

/* localdecomp:start func_0013A8E8 */
extern s32 func_0013A840(void);
extern void func_0011EED0(u32 *);
extern u8 D_00141832[];
s32 func_0013A8E8(void) {
    u32 buf[4];
    if (func_0013A840() == 0) {
        func_0011EED0(buf);
        return (buf[0] >> 1) & 3;
    }
    return D_00141832[0];
}
/* localdecomp:end func_0013A8E8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013A928);

/* localdecomp:start func_0013A930 */
extern s16 D_00141830[];
extern s32 func_0013A840(void);
extern void func_0011EED0(u32 *);
s32 func_0013A930(void) {
 u32 buf[4];
s32 r; if (func_0013A840() != 0) { r = D_00141830[0]; } else { func_0011EED0(buf); r = (s32)buf[0] >> 21; if (((buf[0] >> 13) & 7) == 0) { r = 0x21C; } } return r;
}
/* localdecomp:end func_0013A930 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013A980);

/* localdecomp:start func_0013A988 */
extern s32 func_0013A840(void);
extern void func_0011EED0(u32 *);
extern s32 func_0011F130(u8 *, s32, s32);
extern u8 D_00141836[];
s32 func_0013A988(void) {
    u32 buf[4];
    s32 r;
    if (func_0013A840() != 0) {
        r = D_00141836[0];
    } else {
        func_0011EED0(buf);
        if (((buf[0] >> 13) & 7) == 0) {
            r = 0;
        } else {
            func_0011F130((u8 *)buf + 4, 1, 1);
            r = (((u8 *)buf)[4] >> 4) & 1;
        }
    }
    return r;
}
/* localdecomp:end func_0013A988 */

/* localdecomp:start func_0013A9F0 */
u8 func_0013A9F0(u8 a) {
    return (a / 10) * 6 + a;
}
/* localdecomp:end func_0013A9F0 */

/* localdecomp:start func_0013AA20 */
u8 func_0013AA20(u8 x) {
    u32 q = x >> 4;
    u8 r = (u8)(q * 6);
    return x - r;
}
/* localdecomp:end func_0013AA20 */

/* localdecomp:start func_0013AA40 */
typedef struct {
    u8 x0;
    u8 x1;
    u8 x2;
    u8 x3;
    u8 x4;
    u8 x5;
    u8 x6;
    u8 x7;
} S_13AA40;
void func_0013AA40(S_13AA40 *p) {
    p->x7 = func_0013AA20(p->x7);
    p->x6 = func_0013AA20(p->x6);
    p->x5 = func_0013AA20(p->x5);
    p->x3 = func_0013AA20(p->x3);
    p->x2 = func_0013AA20(p->x2);
    p->x1 = func_0013AA20(p->x1);
}
/* localdecomp:end func_0013AA40 */

/* localdecomp:start func_0013AAA8 */
void func_0013AAA8(u8 *p) {
    p[7] = func_0013A9F0(p[7]);
    p[6] = func_0013A9F0(p[6]);
    p[5] = func_0013A9F0(p[5]);
    p[3] = func_0013A9F0(p[3]);
    p[2] = func_0013A9F0(p[2]);
    p[1] = func_0013A9F0(p[1]);
}
/* localdecomp:end func_0013AAA8 */

/* localdecomp:start func_0013AB10 */
typedef struct {
    s8 d[12];
} Days_13AB10;

extern Days_13AB10 D_00152280;

void func_0013AB10(u8 *t)
{
    Days_13AB10 days;
    s32 y;

    y = t[7];
    days = D_00152280;
    t[5]++;
    if ((y & 3) == 0) {
        days.d[1] = 29;
    }
    if (days.d[t[6] - 1] < t[5]) {
        t[5] = 1;
        t[6]++;
        if (t[6] == 13) {
            if (t[7] == 99) {
                t[7] = 0;
            } else {
                t[7]++;
            }
            t[6] = 1;
        }
    }
}
/* localdecomp:end func_0013AB10 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013ABC8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AC70);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013ACA0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013ACC8);

/* localdecomp:start func_0013AD58 */
extern void func_0013ACC8(void *, s32);
void func_0013AD58(void *a) {
    s32 x = func_0013A930();
    s32 k = func_0013A988();
    func_0013ACC8(a, x - 0x21C + k * 0x3C);
}
/* localdecomp:end func_0013AD58 */
TEXT_PADDING(2);

ASM_FUNC("asm/boot_elf/handwritten", func_0013ADA8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AFE8);

ASM_FUNC("asm/boot_elf/handwritten", func_0013AFF0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013AFF8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B0C8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B208);

/* localdecomp:start func_0013B330 */
extern u8 D_001D551D;
extern char D_001D4D90[];
extern char D_001D4D98[];
extern void func_001260D0(void);
extern s32 func_0011B9A0(char *, char *, s32);
extern s32 func_0011B610(char *, char *);
extern void func_0013B208(char *);
extern void *func_0013AFF8(void);
extern void func_0011F0A0(s32);
extern void func_00381280(void);

void func_0013B330(s32 argc, char **argv) {
    void (*fn)(void);

    func_001260D0();
    D_001D551D = 0;
    if (argc > 0) {
        do {
            if (func_0011B9A0(*argv, D_001D4D90, 5) == 0) {
                func_0013B208(*argv + 5);
                D_001D551D++;
            } else if (func_0011B610(*argv, D_001D4D98) == 0) {
                D_001D551D++;
            }
            argv++;
        } while (--argc != 0);
    }
    fn = func_00381280;
    for (;;) {
        fn();
        fn = (void (*)(void))func_0013AFF8();
        func_0011F0A0(0);
        func_0011F0A0(2);
    }
}
/* localdecomp:end func_0013B330 */

/* localdecomp:start func_0013B3F8 */
__asm__(".extern D_001D4E18, 4");
__asm__(".extern D_001D4DE8, 4");
__asm__(".extern D_001D4DF0, 4");
__asm__(".extern D_001D4DC0, 4");
__asm__(".extern D_001D4DC8, 4");
__asm__(".extern D_001D4DD0, 4");
__asm__(".extern D_001D4DD8, 4");
typedef struct { s32 a; s32 pad; long b; } E_13C578;
extern s32 D_001D4E18;
extern s32 *D_001D4DC0[2];
extern s32 D_001D4DC8[2];
extern E_13C578 *D_001D4DD0[2];
extern u8 *D_001D4DD8[2];
extern s32 D_001D4DE8;
extern s32 D_001D4DF0;
extern long D_001D4DF8;
typedef struct { s32 a, b; } S_1D4900;
extern S_1D4900 D_1D4900;
extern S_1D4900 D_1D49C0;
extern s32 D_1D4980;
extern s32 D_1D4990_0013B3F8;
extern s32 D_1D4A00;
extern u8 D_15C3C0[];
extern u8 D_15D3C0[];
extern u8 D_15E3C0[];
extern u8 D_15F3C0[];
extern u8 D_1603C0[];
extern u8 D_160800[];
extern char D_001D4E20[];
extern char D_001D4E48[];
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern void func_0011AF48();
extern s32 func_0013C348(s32, s32, void *);
void func_0013B3F8(s32 flags) {
    s32 i;
    s32 sv;
    s32 buf[2];

    D_001D4DC0[0] = (s32 *)D_15C3C0;
    D_001D4DC0[1] = (s32 *)D_15D3C0;
    D_001D4DD8[0] = D_1603C0;
    D_001D4DD8[1] = D_160800;
    D_001D4DD0[0] = (E_13C578 *)D_15E3C0;
    D_001D4DD0[1] = (E_13C578 *)D_15F3C0;
    if (flags & 2) D_001D4E18 = 1;
    else D_001D4E18 = 0;
    func_00121FE8(0);
    do {
        if (func_00122630(&D_1D4900, 0x123456, 0) < 0) {
            func_0011AF48(D_001D4E20, D_001D4E48, 0xB5);
            for (;;) ;
        }
        i = 9999;
        sv = *(s32 *)0x1D4924;
        do { for (; i != -1; i--) ; } while (0);
    } while (sv == 0);
    D_001D4DE8 = 0;
    D_001D4DF0 = 0;
    D_001D4DF8 = 0;
    D_1D4A00 = 0;
    do {
        if (func_00122630(&D_1D49C0, 0x123457, 0) < 0) {
            func_0011AF48(D_001D4E20, D_001D4E48, 0xCA);
            for (;;) ;
        }
        i = 9999;
        sv = *(s32 *)0x1D49E4;
        do { for (; i != -1; i--) ; } while (0);
    } while (sv == 0);
    D_001D4DC8[0] = 0xFFC;
    *(s32 *)0x1D4980 = 0;
    *(s32 *)D_15C3C0 = 0;
    *(s32 *)D_15D3C0 = 0;
    D_001D4DC8[1] = 0xFFC;
    buf[1] = flags;
    buf[0] = (s32)&D_1D4980;
    *(volatile s32 *)&D_1D4990_0013B3F8 = 0;
    func_0013C348(0, 8, buf);
}
/* localdecomp:end func_0013B3F8 */

/* localdecomp:start func_0013B620 */
typedef struct { void (*fn)(s32, long); s32 pad; long arg; } E_13B620;
__asm__(".extern D_001D4DA0, 4");
__asm__(".extern D_001D4DB0, 4");
__asm__(".extern D_001D4DB4, 4");
__asm__(".extern D_001D4DB8, 4");
__asm__(".extern D_001D4DBC, 4");
__asm__(".extern D_001D4DC0, 8");
__asm__(".extern D_001D4DD0_0013B620, 8");
__asm__(".extern D_001D4DD8, 8");
__asm__(".extern D_001D4DE0, 4");
__asm__(".extern D_001D4DE4, 4");
__asm__(".extern D_001D4DE8, 4");
__asm__(".extern D_001D4DF0, 4");
__asm__(".extern D_001D4E04, 4");
__asm__(".extern D_001D4E08, 8");
extern s32 *D_001D4DA0;
extern s32 D_001D4DB0;
extern s32 D_001D4DB4;
extern s32 D_001D4DB8;
extern s32 D_001D4DBC;
extern s32 *D_001D4DC0[2];
extern E_13B620 *D_001D4DD0_0013B620[2];
extern u8 *D_001D4DD8[2];
extern s32 D_001D4DE0;
extern s32 D_001D4DE4;
extern s32 D_001D4DE8;
extern s32 D_001D4DF0;
extern long D_001D4DF8;
extern s32 D_1D4A00;
extern void (*D_001D4E04)(s32, long);
extern long D_001D4E08;
extern s32 func_0013B818(void);
extern void func_11F0A0(s32);
extern void func_0013C908(void);
extern s32 func_0013CDF0(s32);
s32 func_0013B620(void) {
    if (D_001D4DA0 != 0 && func_0013B818() != 0) {
        if (D_001D4DBC != 0) {
            if (D_001D4E04 != 0) {
                D_001D4E04(*(s32 *)0x1D4944, D_001D4E08);
            }
            D_001D4E04 = 0;
            D_001D4DBC = 0;
        } else {
            s32 i = D_001D4DE0 != 1;
            s32 j;
            for (j = 0; j < *D_001D4DC0[i]; j++) {
                E_13B620 *e = (E_13B620 *)((j << 4) + (s32)D_001D4DD0_0013B620[i]);
                if (e->fn != 0) e->fn(((s32 *)D_001D4DD8[i])[j + 1], e->arg);
            }
        }
    }
    if (D_001D4DE8 != 0) {
        func_11F0A0(0);
        if ((u32)D_1D4A00 != 0xFFFFFFFF) {
            void (*fn)(s32, long) = (void (*)(s32, long))D_001D4DF0;
            if (fn != 0) {
                long a = *(long *)0x1D4DF8;
                D_001D4DF0 = 0;
                *(volatile long *)&D_001D4DF8 = 0;
                fn(D_1D4A00, a);
            }
            D_1D4A00 = 0;
            D_001D4DE8 = 0;
        }
    }
    if (D_001D4DA0 == 0) {
        if (*D_001D4DC0[D_001D4DE0] != 0 && D_001D4DE4 == 0) func_0013C908();
    }
    if (D_001D4DB4 != 0) {
        func_0013CDF0(1);
        if (D_001D4DB8 != 0) {
            D_001D4DB4 = 0;
            D_001D4DB8 = 0;
            if (D_001D4DB0 != 0) ((void (*)(s32))D_001D4DB0)(1);
        }
    }
    return D_001D4DA0 != 0 || D_001D4DE8 != 0;
}
/* localdecomp:end func_0013B620 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013B808);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013B810);

/* localdecomp:start func_0013B818 */
__asm__(".extern D_001D4DA0, 4");
__asm__(".extern D_001D4DA4, 4");
__asm__(".extern D_001D4E18, 4");
extern s32 D_001D4DA4;
extern s32 *D_001D4DA0;
extern s32 D_001D4E18;
extern s32 D_1D4900_0013B818[2];
extern char D_00152290[];
extern void func_0011F0A0(s32);
extern s32 func_00122A10(void *);
extern s32 func_0011AF48_0013B818(const char *, ...);
s32 func_0013B818(void) {
    s32 *p;
    func_0011F0A0(0);
    if (D_001D4DA0 == 0) return 1;
    if (func_00122A10(D_1D4900_0013B818) != 0) return 0;
    p = D_001D4DA0;
    if ((u32)p[0] == 0xFFFFFFFF && p[D_001D4DA4 + 1] == p[0]) {
        D_001D4DA0 = 0;
        return 1;
    }
    if (D_001D4E18 == 0) func_0011AF48_0013B818(D_00152290);
    return 0;
}
/* localdecomp:end func_0013B818 */

/* localdecomp:start func_0013B8B0 */
extern s32 D_001D4DA4;
extern s32 *D_001D4DA0;
extern void func_0011F698(void *, void *);
void func_0013B8B0(s32 *p, s32 n) {
    D_001D4DA4 = n;
    D_001D4DA0 = p;
    p[n + 1] = 0;
    p[0] = 0;
    func_0011F698(p, (u8 *)p + 3);
    p = &p[n + 1];
    func_0011F698(p, (u8 *)p + 3);
}
/* localdecomp:end func_0013B8B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013B910);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013B918);

/* localdecomp:start func_0013BAB8 */
__asm__(".extern D_001D4DA8, 4");
__asm__(".extern D_001D4DE8, 4");
__asm__(".extern D_001D4E18, 4");
__asm__(".extern D_001D4DF0, 4");
extern s32 D_001D4DA8;
extern s32 D_001D4DE8;
extern s32 D_001D4E18;
extern s32 D_001D4DF0;
extern s32 D_1D4A00;
extern s32 D_1D4A04;
extern s32 D_1D4A40;
extern s32 D_1D4A44;
extern u8 D_1D49C0_0013BAB8[8];
extern char D_001D4F20[];
extern char D_001D4F50[];
extern char D_001D4F70[];
extern char D_001D4E98[];
extern void func_0011AF48_0013BAB8(char *);
extern s32 func_0013CDF0(s32);
extern void func_0011F698(void *, void *);
extern s32 func_00122A10(void *);
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_11F0A0(s32);
void func_0013BAB8(s32 a, s32 b, void (*cb)(s32, long), long arg) {
    D_001D4DA8 = 0;
    if (D_001D4DE8 != 0) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4F20);
        return;
    }
    if (func_0013CDF0(1) == 1) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4F50);
        return;
    }
    *(u32 *)&D_1D4A00 = 0xFFFFFFFF;
    func_0011F698(&D_1D4A00, &D_1D4A04);
    D_1D4A40 = a;
    D_1D4A44 = b;
    D_001D4DF0 = (s32)cb;
    *(long *)0x1D4DF8 = arg;
    while (func_00122A10(D_1D49C0_0013BAB8) != 0) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4E98);
        func_0013B620();
        func_11F0A0(0);
    }
    D_001D4DE8 = 1;
    func_00122810(D_1D49C0_0013BAB8, 3, 1, &D_1D4A40, 8, &D_1D4A00, 4, 0, 0);
}
/* localdecomp:end func_0013BAB8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013BC28);

/* localdecomp:start func_0013BC30 */
__asm__(".extern D_001D4DE8, 4");
__asm__(".extern D_001D4E18, 4");
__asm__(".extern D_001D4DF0, 4");
__asm__(".extern D_001D4DA8, 4");
extern s32 D_001D4DA8;
extern s32 D_1D4A04;
extern s32 D_1D4A40;
extern char D_001D5018[];
extern void func_0011F698(void *, void *);
extern char D_001D4E98[];
extern s32 func_00122A10();
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_0011F0A0(s32);
void func_0013BC30(s32 a, void *b, unsigned long c) {
    D_001D4DA8 = 0;
    if (D_001D4DE8 != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D5018);
        return;
    }
    *(u32 *)&D_1D4A00 = 0xFFFFFFFFU;
    func_0011F698(&D_1D4A00, &D_1D4A04);
    D_1D4A40 = a;
    D_001D4DF0 = (s32)b;
    *(volatile long *)&D_001D4DF8 = c;
    while (func_00122A10(&D_1D49C0) != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D4E98);
        func_0013B620();
        func_0011F0A0(0);
    }
    D_001D4DE8 = 1;
    func_00122810(&D_1D49C0, 0x57, 1, &D_1D4A40, 4, &D_1D4A00, 4, 0, 0);
}
/* localdecomp:end func_0013BC30 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013BD58);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013BEB0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013BEC8);

/* localdecomp:start func_0013BED0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BED0(void) {
    return func_0013C578(0x8, 0, 0, 0, 0);
}
/* localdecomp:end func_0013BED0 */

/* localdecomp:start func_0013BF00 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BF00(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x6, 4, buf, 0, 0);
}
/* localdecomp:end func_0013BF00 */

/* localdecomp:start func_0013BF30 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BF30(s32 a, s32 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0013C578(0x9, 8, buf, 0, 0);
}
/* localdecomp:end func_0013BF30 */

/* localdecomp:start func_0013BF68 */
typedef struct { u8 b[0x18]; } V_13BF68;
typedef struct { s32 a; V_13BF68 v; } B_13BF68;
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BF68(s32 a, V_13BF68 *p) {
    B_13BF68 buf;
    buf.a = a;
    if (p != 0) {
        buf.v = *p;
    } else {
        *(s32 *)&buf.v = -1;
    }
    return func_0013C578(0x60, 0x1C, &buf, 0, 0);
}
/* localdecomp:end func_0013BF68 */

/* localdecomp:start func_0013BFE0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BFE0(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0xB, 4, buf, 0, 0);
}
/* localdecomp:end func_0013BFE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C010);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C020);

/* localdecomp:start func_0013C028 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C028(s32 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0013C578(0x4E, 0xC, buf, 0, 0);
}
/* localdecomp:end func_0013C028 */

/* localdecomp:start func_0013C068 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C068(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x64, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C068 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C098);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C0B0);

/* localdecomp:start func_0013C0B8 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C0B8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_0013C578(0x11, 0x18, buf, g, h);
}
/* localdecomp:end func_0013C0B8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C100);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C110);

/* localdecomp:start func_0013C118 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C118(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x15, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C118 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C148);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C168);

/* localdecomp:start func_0013C170 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C170(void) {
    return func_0013C578(0x18, 0, 0, 0, 0);
}
/* localdecomp:end func_0013C170 */

/* localdecomp:start func_0013C1A0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C1A0(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x16, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C1A0 */

/* localdecomp:start func_0013C1D0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C1D0(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x17, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C1D0 */

/* localdecomp:start func_0013C200 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C200(s32 a, s32 b, long c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x19, 4, buf, b, c);
}
/* localdecomp:end func_0013C200 */

/* localdecomp:start func_0013C230 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C230(s32 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0013C578(0x1B, 0xC, buf, 0, 0);
}
/* localdecomp:end func_0013C230 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C270);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C298);

/* localdecomp:start func_0013C2A0 */
extern s32 func_0013C2C0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_0013C2A0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    return func_0013C2C0(a, b, c, d, e, f, 0, 0);
}
/* localdecomp:end func_0013C2A0 */

/* localdecomp:start func_0013C2C0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C2C0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_0013C578(0x21, 0x18, buf, g, h);
}
/* localdecomp:end func_0013C2C0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C308);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C340);

/* localdecomp:start func_0013C348 */
__asm__(".extern D_001D4DE4, 4");
__asm__(".extern D_001D4E18, 4");
__asm__(".extern D_001D4DE0, 4");
__asm__(".extern D_001D4DC0, 8");
__asm__(".extern D_001D4DC8, 8");
__asm__(".extern D_001D4DD0, 8");
__asm__(".extern D_001D4DA0, 4");
extern s32 D_001D4DE4;
extern s32 D_001D4DE0;
extern s32 D_1D4940[2];
extern u8 D_15C1C0[];
extern u8 D_15C1CC[];
extern char D_001522E8[];
extern char D_001D4E98[];
extern s32 func_00122A10();
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_0011F0A0(s32);
extern void func_0011A0B0(void *, void *, s32);
extern s32 func_0013B818(void);
extern void func_0013C908(void);
s32 func_0013C348(s32 cmd, s32 len, void *data) {
    s32 i;
    s32 r;

    if (cmd != 0x68) {
        for (i = 0; i < len; i++) D_15C1C0[i] = ((u8 *)data)[i];
    } else {
        if ((u32)(((s32 *)data)[2] + 0xC) > 0x200) {
            func_0011AF48(D_001522E8);
            for (;;) ;
        }
        for (i = 0; i < 0xC; i++) D_15C1C0[i] = ((u8 *)data)[i];
        func_0011A0B0(D_15C1CC, ((void **)data)[3], ((s32 *)data)[2]);
    }
    while (D_001D4DA0 != 0) {
        func_0013B620();
        func_0011F0A0(0);
    }
    func_0013B8B0(D_1D4940, 1);
    while (func_00122A10(&D_1D4900) != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D4E98);
        func_0013B620();
        func_0011F0A0(0);
    }
    if (len != 0) {
        func_00122810(&D_1D4900, cmd, 1, D_15C1C0, len, D_1D4940, 0xC, 0, 0);
    } else {
        func_00122810(&D_1D4900, cmd, 1, 0, 0, D_1D4940, 0xC, 0, 0);
    }
    do {} while (func_0013B818() == 0);
    r = D_1D4940[1];
    if (*D_001D4DC0[D_001D4DE0] != 0 && D_001D4DE4 == 0) func_0013C908();
    return r;
}
/* localdecomp:end func_0013C348 */

/* localdecomp:start func_0013C578 */
extern char D_001D5270[];
extern char D_001D5298[];
extern char D_00152330[];
extern s32 func_0013C8D0(void);
s32 func_0013C578(s32 cmd, s32 len, void *data, s32 a3, long a4) {
    s32 n, i, cnt, flag, idx;
    u8 *p;

    flag = 0;
    if (D_001D4DE4 == 0 && D_001D4DA0 == 0 && len == 0 && a3 == 0) {
        func_0013B8B0(D_1D4940, 1);
        while (func_00122A10(&D_1D4900) != 0) {
            if (D_001D4E18 == 0) func_0011AF48(D_001D4E98);
            func_0013B620();
            func_0011F0A0(0);
        }
        return func_00122810(&D_1D4900, cmd, 1, 0, 0, D_1D4940, 0xC, 0, 0);
    }
    n = len + 4;
    cnt = 0;
    if (n % 4) n += 4 - n % 4;
    if (n > 0x200) {
        func_0011AF48(D_001D5270);
        for (;;) ;
    }
    while (*D_001D4DC0[D_001D4DE0] == 0x100 || D_001D4DC8[D_001D4DE0] < n) {
        if (D_001D4DE4 != 0) {
            D_001D4DE4 = 0;
            flag = 1;
        }
        func_0013B620();
        if (cnt == 1 && D_001D4E18 == 0) {
            func_0011AF48(D_00152330, D_001D4DE0, *D_001D4DC0[D_001D4DE0]);
        }
        cnt++;
    }
    if (cnt != 0 && D_001D4E18 == 0) func_0011AF48(D_001D5298, cnt);
    if (flag) D_001D4DE4 = 1;
    idx = D_001D4DE0;
    p = (u8 *)D_001D4DC0[idx] - (D_001D4DC8[idx] - 0x1000);
    *(s16 *)p = cmd;
    p += 2;
    *(s16 *)p = len;
    p += 2;
    if (cmd != 0x68) {
        for (i = 0; i < len; i++) p[i] = ((u8 *)data)[i];
    } else {
        for (i = 0; i < 0xC; i++) p[i] = ((u8 *)data)[i];
        func_0011A0B0(p + 0xC, ((void **)data)[3], ((s32 *)data)[2]);
    }
    D_001D4DC8[D_001D4DE0] -= n;
    D_001D4DD0[D_001D4DE0][*D_001D4DC0[D_001D4DE0]].a = a3;
    D_001D4DD0[D_001D4DE0][*D_001D4DC0[D_001D4DE0]].b = a4;
    return func_0013C8D0();
}
/* localdecomp:end func_0013C578 */

/* localdecomp:start func_0013C8D0 */
s32 func_0013C8D0(void) {
    s32 *p = D_001D4DC0[D_001D4DE0];
    *p = *p + 1;
    return func_0013B620();
}
/* localdecomp:end func_0013C8D0 */

/* localdecomp:start func_0013C908 */
__asm__(".extern D_001D4DE0, 4");
__asm__(".extern D_001D4E18, 4");
__asm__(".extern D_001D4DC0, 8");
__asm__(".extern D_001D4DC8, 8");
__asm__(".extern D_001D4DD8, 8");
void func_0013C908(void) {
    s32 idx;

    func_0013B8B0((s32 *)D_001D4DD8[D_001D4DE0], *D_001D4DC0[D_001D4DE0]);
    while (func_00122A10(&D_1D4900) != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D4E98);
        func_0011F0A0(0);
    }
    func_00122810(&D_1D4900, 0x4D, 1, D_001D4DC0[D_001D4DE0], 0x1000 - D_001D4DC8[D_001D4DE0],
                  D_001D4DD8[D_001D4DE0], *D_001D4DC0[D_001D4DE0] * 4 + 8, 0, 0);
    idx = D_001D4DE0 != 1;
    D_001D4DE0 = idx;
    *D_001D4DC0[idx] = 0;
    D_001D4DC8[idx] = 0xFFC;
}
/* localdecomp:end func_0013C908 */

/* localdecomp:start func_0013CA20 */
void func_0013CA20(void) {
}
/* localdecomp:end func_0013CA20 */

/* localdecomp:start func_0013CA28 */
void func_0013CA28(void) {
}
/* localdecomp:end func_0013CA28 */

/* localdecomp:start func_0013CA30 */
extern s32 D_001D4DAC;
extern s32 D_001D4DE8;
extern s32 func_0013B620(void);
extern s32 func_0013CDF0(s32);
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013CA30(s32 a, s32 b, s32 c, s32 d) {
    s32 buf[4];
    if (D_001D4DAC == 1) return 0;
    if (D_001D4DE8 != 0) {
        while (func_0013B620() != 0);
    }
    func_0013CDF0(0);
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    return D_001D4DAC = func_0013C348(0x2A, 0x10, buf);
}
/* localdecomp:end func_0013CA30 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CAD8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CAE0);

/* localdecomp:start func_0013CAE8 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CAE8(void) {
    return func_0013C578(0x34, 0, 0, 0, 0);
}
/* localdecomp:end func_0013CAE8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CB18);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013CB20);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CC00);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CC08);

/* localdecomp:start func_0013CC10 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CC10(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x2D, 4, buf, 0, 0);
}
/* localdecomp:end func_0013CC10 */

/* localdecomp:start func_0013CC40 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CC40(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x2E, 4, buf, 0, 0);
}
/* localdecomp:end func_0013CC40 */

/* localdecomp:start func_0013CC70 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CC70(s32 a, s32 b, long c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x30, 4, buf, b, c);
}
/* localdecomp:end func_0013CC70 */

/* localdecomp:start func_0013CCA0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CCA0(s32 a, s32 b, long c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x32, 4, buf, b, c);
}
/* localdecomp:end func_0013CCA0 */

/* localdecomp:start func_0013CCD0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CCD0(s32 a, s32 b, long c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x4F, 4, buf, b, c);
}
/* localdecomp:end func_0013CCD0 */

/* localdecomp:start func_0013CD00 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013CD00(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C348(0x36, 4, buf);
}
/* localdecomp:end func_0013CD00 */

/* localdecomp:start func_0013CD28 */
__asm__(".extern D_001D4DAC, 4");
__asm__(".extern D_001D4DB4, 4");
__asm__(".extern D_001D4DB8, 4");
extern s32 D_001D4DAC;
extern s32 D_001D4DB4;
extern s32 D_001D4DB8;
extern s32 D_1D4980;
extern s32 D_1D4990_0013CD28;
extern u8 D_1D49BF;
extern s32 func_0012BA20(void);
extern s32 func_0013CDF0(s32);
extern void func_0011F698(void *, void *);
extern s32 func_0013C578();
s32 func_0013CD28(s32 a, s32 b, s32 c) {
    s32 buf[3];
    if (D_001D4DAC == 0) return func_0012BA20();
    if (func_0013CDF0(1) == 1) return 0;
    *(volatile s32 *)&D_1D4980 = 1;
    *(volatile s32 *)&D_1D4990_0013CD28 = 0;
    func_0011F698(&D_1D4980, &D_1D49BF);
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    D_001D4DB4 = 1;
    D_001D4DB8 = 0;
    func_0013C578(0x38, 0xC, buf, 0, 0);
    return 1;
}
/* localdecomp:end func_0013CD28 */

/* localdecomp:start func_0013CDF0 */
__asm__(".extern D_001D4DAC, 4");
__asm__(".extern D_001D4DB8, 4");
extern s32 D_001D4DAC;
extern s32 D_001D4DB8;
extern s32 D_1D4980;
extern u8 D_1D49BF;
extern s32 func_0012B098();
extern void func_0011F7C8(void *, void *);
extern s32 func_0013B620(void);
s32 func_0013CDF0(s32 mode) {
    u8 *q;
    if (D_001D4DAC == 0) return func_0012B098(mode);
    q = &D_1D49BF;
    func_0011F7C8(&D_1D4980, q);
    D_001D4DB8 = D_1D4980 == 0;
    if (D_001D4DB8 != 1) {
        if (mode == 1) return 1;
        while (D_001D4DB8 == 0) {
            func_0013B620();
            func_0011F7C8(&D_1D4980, q);
            D_001D4DB8 = D_1D4980 == 0;
        }
    }
    return 0;
}
/* localdecomp:end func_0013CDF0 */

/* localdecomp:start func_0013CEB0 */
extern s32 D_001D4DAC;
extern s32 func_0013C578(s32, s32, void *, s32, long);
extern s32 func_0012BC98(void);
s32 func_0013CEB0(void) {
    if (D_001D4DAC == 0) {
        return func_0012BC98();
    }
    func_0013C578(0x37, 0, 0, 0, 0);
    return 1;
}
/* localdecomp:end func_0013CEB0 */

/* localdecomp:start func_0013CEF8 */
extern s32 D_001D4DAC;
extern s32 D_1D4990[];
extern s32 func_0012BC00(void);
s32 func_0013CEF8(void) {
    if (D_001D4DAC == 0) {
        return func_0012BC00();
    }
    return D_1D4990[0];
}
/* localdecomp:end func_0013CEF8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CF30);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CF38);

/* localdecomp:start func_0013CF40 */
extern s32 D_001D4DAC;
extern s32 D_001D4DB0;
extern s32 func_0012AA78(s32);
s32 func_0013CF40(s32 a) {
    s32 old;
    if (D_001D4DAC == 0) {
        return func_0012AA78(a);
    }
    old = D_001D4DB0;
    D_001D4DB0 = a;
    return old;
}
/* localdecomp:end func_0013CF40 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CF70);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CF78);

/* localdecomp:start func_0013CF80 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CF80(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 buf[5];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    return func_0013C578(0x50, 0x14, buf, 0, 0);
}
/* localdecomp:end func_0013CF80 */

/* localdecomp:start func_0013CFC0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CFC0(s32 a, s32 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0013C578(0x51, 8, buf, 0, 0);
}
/* localdecomp:end func_0013CFC0 */

/* localdecomp:start func_0013CFF8 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CFF8(s32 a, s32 b, s32 c, s32 d) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    return func_0013C578(0x10, 0x10, buf, 0, 0);
}
/* localdecomp:end func_0013CFF8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D038);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D078);

/* localdecomp:start func_0013D080 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D080(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_0013C348(0x3B, 0x18, buf);
}
/* localdecomp:end func_0013D080 */

/* localdecomp:start func_0013D0C0 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D0C0(void) {
    return func_0013C348(0x3D, 0, 0);
}
/* localdecomp:end func_0013D0C0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D0E8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D0F0);

/* localdecomp:start func_0013D0F8 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D0F8(void) {
    return func_0013C348(0x3C, 0, 0);
}
/* localdecomp:end func_0013D0F8 */

/* localdecomp:start func_0013D120 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D120(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 buf[5];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    return func_0013C348(0x3E, 0x14, buf);
}
/* localdecomp:end func_0013D120 */

/* localdecomp:start func_0013D158 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D158(void) {
    return func_0013C348(0x40, 0, 0);
}
/* localdecomp:end func_0013D158 */

/* localdecomp:start func_0013D180 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D180(s32 a, s32 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0013C348(0x5A, 8, buf);
}
/* localdecomp:end func_0013D180 */

/* localdecomp:start func_0013D1B0 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D1B0(void) {
    return func_0013C348(0x5B, 0, 0);
}
/* localdecomp:end func_0013D1B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D1D8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D1E0);

/* localdecomp:start func_0013D1E8 */
s32 func_0013D1E8(s32 a) {
    return a * 0x5F4 / 0x2E5;
}
/* localdecomp:end func_0013D1E8 */

ASM_FUNC("asm/boot_elf/handwritten", func_0013D208);

/* localdecomp:start func_0013D258 */
void func_0013D258(u8 *d, u8 *s, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        d[i] = s[i];
    }
}
/* localdecomp:end func_0013D258 */

/* localdecomp:start func_0013D290 */
extern u8 D_001D52E0[];
extern void func_0013CD28(s32, s32, s32, u8 *);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern s32 func_0013CDF0(s32);
s32 func_0013D290(s32 a, s32 b, s32 c) {
    u8 buf[4];
    buf[0] = 0x20;
    buf[1] = D_001D52E0[0];
    buf[2] = 0;
    buf[3] = 0;
    func_0013CD28(a, b, c, buf);
    func_0013CA28();
    func_0013B620();
    return func_0013CDF0(0);
}
/* localdecomp:end func_0013D290 */

/* localdecomp:start func_0013D2E0 */
extern s32 func_0013D290(s32, s32, void *);
extern u8 D_160C40[];
s32 func_0013D2E0(void) {
    return func_0013D290(0x3E9, 0x10, D_160C40);
}
/* localdecomp:end func_0013D2E0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D308);

/* localdecomp:start func_0013D310 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; } E_13D310;
typedef struct { u8 p0[0x7400]; E_13D310 e[(0x79A0 - 0x7400) / 0x18]; u8 a79A0[0x60]; u8 a7A00[0x1818]; } S_13D310;
extern S_13D310 D_160C40_0013D310;
extern void func_0013D258(void *, void *, s32);
extern u8 D_169E58[];
void func_0013D310(s32 idx, void *buf) {
    func_0013D290(D_160C40_0013D310.e[idx].f8, 1, buf);
    func_0013D258(D_160C40_0013D310.a79A0, buf, 0x60);
    func_0013D290(D_160C40_0013D310.e[idx].f0, 4, buf);
    func_0013D258(D_160C40_0013D310.a7A00, buf, 0x1818);
    func_0013D290(D_160C40_0013D310.e[idx].f10, 5, buf);
    func_0013D258(D_169E58, buf, 0x26F0);
}
/* localdecomp:end func_0013D310 */

/* localdecomp:start func_0013D3C0 */
extern s32 D_001D5458;
void func_0013D3C0(s32 a) {
    D_001D5458 = a;
}
/* localdecomp:end func_0013D3C0 */

/* localdecomp:start func_0013D3C8 */
extern s32 D_001D5458;
s32 func_0013D3C8(void) {
    return D_001D5458;
}
/* localdecomp:end func_0013D3C8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0013D3D0);

ASM_FUNC("asm/boot_elf/handwritten", func_0013D3E0);
