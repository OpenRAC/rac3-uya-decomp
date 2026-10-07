#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void * func_003AF2D0();
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 D_001D8118[];
extern s32 D_001D8118[2];
extern s32 D_001D8100[];
extern s32 D_001D8100[2];
extern u8 *func_003AB430(u8 *);
extern void func_003AB118(void *, s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003ACE50 */
typedef struct { f32 x, y; } V2_003A7690;
typedef struct { s32 a, b, c, d, e, f; } T6_003A7690;
typedef struct {
    f32 *pos;        /* 0x000 */
    u8 pad4[4];
    u32 *color;      /* 0x008 */
    u32 *font;       /* 0x00C */
    u8 sub10[0x3C];  /* 0x010 */
    u8 sub4C[0x13C]; /* 0x04C */
    s32 w;           /* 0x188 */
    s32 h;           /* 0x18C */
    s32 count;       /* 0x190 */
    u8 pad194[8];
    s32 xoff;        /* 0x19C */
    u8 pad1A0[4];
    s32 mode;        /* 0x1A4 */
    u8 pad1A8[8];
    f32 f1B0;        /* 0x1B0 */
    u8 pad1B4[4];
    s32 text[1];     /* 0x1B8 */
} O_003A7690;
extern V2_003A7690 D_001D8440[];
extern V2_003A7690 D_001D8448[];
extern f32 D_001D8450;
extern T6_003A7690 D_001D8458[];
extern T6_003A7690 D_001D8470[];
extern s32 D_001D55E8;
extern void func_0038C638_003ACE50(s32, s32, s32, s32, s32, u32 *);
extern void func_003AB0E8(void *, f32, f32, f32, f32);
extern void func_003AB210(void *, f32, f32, f32, f32);
extern void func_003AB5B0(void *);
extern void func_0038E478(s32);
extern void func_0038EB10_003ACE50(unsigned long, s32, s32, f32, f32, f32, f32, s32, s32, unsigned long, f32, f32);

void func_003ACE50(void *arg0) {
    O_003A7690 *o = arg0;
    u32 cols[4];
    V2_003A7690 a, b;
    T6_003A7690 t1, t2;
    f32 s;
    u32 c, alpha;
    s32 ix, iy, i, lh;

    alpha = *o->color >> 24;
    if ((s32)alpha > 0x60) alpha = 0x60;
    c = *o->color & 0xFFFFFF;
    c |= alpha << 24;
    cols[0] = c;
    cols[1] = c;
    cols[2] = c;
    cols[3] = c;
    func_0038C638_003ACE50(o->pos[0] - o->w, o->pos[1] - o->h, o->pos[0] + o->w + 2.0f, o->pos[1] + o->h, 0xFFFFF0, cols);
    a = D_001D8440[0];
    b = D_001D8448[0];
    s = 1.0f;
    if (o->mode == 0) s = D_001D8450;
    lh = 16;
    i = 0;
    func_003AB0E8(o->sub10, o->pos[0] - o->w - a.x, o->pos[1] - o->h - a.y, 0.0f, 0.0f);
    func_003AB210(o->sub10, -s, s, 0.0f, 0.0f);
    func_003AB5B0(o->sub10);
    func_003AB0E8(o->sub10, o->pos[0] + o->w + a.x + 1.0f, o->pos[1] - o->h - a.y, 0.0f, 0.0f);
    func_003AB210(o->sub10, s, s, 0.0f, 0.0f);
    func_003AB5B0(o->sub10);
    func_003AB0E8(o->sub4C, o->pos[0] + o->w + b.x, o->pos[1] - o->h - b.y, 0.0f, 0.0f);
    func_003AB210(o->sub4C, s, s, 0.0f, 0.0f);
    func_003AB5B0(o->sub4C);
    func_003AB0E8(o->sub4C, o->pos[0] - o->w - b.x + 1.0f, o->pos[1] - o->h - b.y, 0.0f, 0.0f);
    func_003AB210(o->sub4C, -s, s, 0.0f, 0.0f);
    func_003AB5B0(o->sub4C);
    func_003AB0E8(o->sub4C, o->pos[0] + o->w + b.x, o->pos[1] - o->h - b.y + o->f1B0, 0.0f, 0.0f);
    func_003AB210(o->sub4C, s, -s, 0.0f, 0.0f);
    func_003AB5B0(o->sub4C);
    func_003AB0E8(o->sub4C, o->pos[0] - o->w - b.x + 1.0f, o->pos[1] - o->h - b.y + o->f1B0, 0.0f, 0.0f);
    func_003AB210(o->sub4C, -s, -s, 0.0f, 0.0f);
    func_003AB5B0(o->sub4C);
    ix = o->pos[0] - o->w + o->xoff;
    iy = o->pos[1] - o->h;
    t1 = D_001D8458[0];
    t2 = D_001D8470[0];
    switch (o->mode) {
    case 0:
        if (o->text[0] != 0) {
            for (; i < o->count; i++) {
                s32 old = D_001D55E8;
                func_0038E478(1);
                func_0038EB10_003ACE50(*o->font, o->text[i], -1, ix + t2.c, iy + t2.d + i * lh, 1.0f, 1.0f, 0, 1, 0x80000000, 2.0f, 2.0f);
                func_0038E478(old);
            }
        }
        break;
    case 1:
        if (o->text[0] != 0) {
            for (; i < o->count; i++) {
                func_0038E478(1);
                func_0038EB10_003ACE50(*o->font, o->text[i], -1, ix + t1.c, iy + t1.d + i * lh + 2, 1.0f, 1.0f, 0, 1, 0x80000000, 2.0f, 2.0f);
            }
        }
        break;
    case 2:
        break;
    }
}
/* localdecomp:end func_003ACE50 */

/* localdecomp:start func_003AD488 */
s32 func_003AD488(void) {
}
/* localdecomp:end func_003AD488 */

/* localdecomp:start func_003AD490 */
void func_00387778();
void func_003ACE50(void *);
void func_003AD488(void *);
typedef struct { u8 pad0[0xB0]; f32 fB0; } S_00225980_003A7CD0_003A7CD0;
extern S_00225980_003A7CD0_003A7CD0 D_00225980[];

void func_003AD490(void *arg0) {
    f32 temp_f20;
    s32 temp_v1;

    if (*(*(f32 **)((u8 *)(arg0) + 4)) != 0.0f) {
        temp_f20 = D_00225980->fB0;
        D_00225980->fB0 = 0.62f;
        func_00387778();
        temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1A8));
        switch (temp_v1) {                          /* irregular */
        case 0:
            func_003ACE50(arg0);
            break;
        case 2:
            func_003AD488(arg0);
            break;
        }
        D_00225980->fB0 = temp_f20;
        func_00387778();
    }
}
/* localdecomp:end func_003AD490 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AD540);

/* localdecomp:start func_003AD608 */
void *func_003AD608(u8 *p) {
    s32 i;
    s32 *q = (s32 *)(p + 0x30);
    for (i = 3; i != -1; i--) {
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q += 4;
    }
    return p;
}
/* localdecomp:end func_003AD608 */

/* localdecomp:start func_003AD640 */
typedef struct { u8 p0[0x18]; f32 f18; s32 f1C; s32 f20; f32 f24; s8 b28; u8 p29[3]; s32 f2C; u8 p30[0x50]; s32 f80; s32 f84; } S_3A7E80;
extern u8 func_003AD750_003AD640[];
extern u8 func_003AD788_003AD640[];
void func_003AD640(S_3A7E80 *s) {
    f32 f;
    s->f18 = 0;
    s->b28 = 0;
    f = s->f18;
    s->f2C = 0;
    s->f80 = 0;
    s->f24 = 0.005f;
    ((void (*)(void *, s32, f32, f32, f32, f32, f32))func_003AD750_003AD640)(s, 0, f, f, f, f, f);
    ((void (*)(void *, s32, f32, f32, f32, f32, f32))func_003AD750_003AD640)(s, 1, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    s->f84 = 2;
    ((void (*)(void *, s32, f32, f32))func_003AD788_003AD640)(s, 0, f, f);
    s->f20 = 0;
    s->f1C = 1;
}
/* localdecomp:end func_003AD640 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AD6F8);

/* localdecomp:start func_003AD700 */
void func_003AD700(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003AD700 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AD708);

/* localdecomp:start func_003AD718 */
typedef struct {
    char pad_0[0x18];   /* Offset 0x00 down to 0x18 */
    f32 float_field;    /* Offset 0x18 - Targeted by lwc1/swc1 */
    char pad_1C[0xC];   /* Padding from 0x1C to 0x28 */
    char byte_flag;     /* Offset 0x28 - Targeted by sb $v0, 0x28($a0) */
} InitContext;

void func_003AD718(InitContext* ctx) {
    // 0: lui $at, 0x3f80
    // 4: mtc1 $at, $f1
    register f32 constant_one __asm__("$f1") = 1.0f;

    // FENCE 1: Blocks 'li $v0, 1' from climbing to offset 0:
    __asm__ __volatile__ ("");

    // 8: li $v0, 1
    ctx->byte_flag = 1;

    // c: lwc1 $f0, 0x18($a0)
    (void)((volatile InitContext*)ctx)->float_field;

    // MEMORY CLOBBER FENCE:
    // This tells ee-gcc that all previous memory actions (the lwc1 load) must be 
    // completely processed and finalized before any subsequent memory instructions 
    // are evaluated. This forces 'sb' perfectly down to offset 10:!
    __asm__ __volatile__ ("" : : : "memory");

    // 18: swc1 $f1, 0x18($a0)
    ctx->float_field = constant_one;
}
/* localdecomp:end func_003AD718 */

/* localdecomp:start func_003AD738 */
void func_003AD738(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x80) = value;
}
/* localdecomp:end func_003AD738 */

/* localdecomp:start func_003AD740 */
u8 func_003AD740(void *p, u8 value) {
    u8 old = *((u8 *)p + 0x28);
    *((u8 *)p + 0x28) = value;
    return old;
}
/* localdecomp:end func_003AD740 */

/* localdecomp:start func_003AD750 */
typedef struct { u8 pad[0x30]; f32 m[4][4]; f32 v[4]; } S_3A7F90;
void func_003AD750(S_3A7F90 *p, s32 i, f32 a, f32 b, f32 c, f32 d, f32 e) {
    p->m[i][0] = b;
    p->m[i][1] = c;
    p->m[i][2] = d;
    p->m[i][3] = e;
    p->v[i] = a;
}
/* localdecomp:end func_003AD750 */

/* localdecomp:start func_003AD788 */
typedef struct { f32 a[3]; f32 b[3]; } V_7FC8;
void func_003AD788(V_7FC8 *s, s32 i, f32 x, f32 y) {
    s->a[i] = x; s->b[i] = y;
}
/* localdecomp:end func_003AD788 */

/* localdecomp:start func_003AD7A0 */
void func_003AD7A0(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x84) = value;
}
/* localdecomp:end func_003AD7A0 */

/* localdecomp:start func_003AD7A8 */
void func_003AD7A8(u8 *p, s32 a) {
    *(s32 *)(p + 0x1C) = a;
    if (p[0x28] == 0) {
        if (a == 1) *(f32 *)(p + 0x18) = 0.0f;
        else *(f32 *)(p + 0x18) = 1.0f;
        p[0x28] = 1;
    }
}
/* localdecomp:end func_003AD7A8 */

/* localdecomp:start func_003AD7E8 */
void func_003AD7E8(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x20) = value;
}
/* localdecomp:end func_003AD7E8 */

/* localdecomp:start func_003AD7F0 */
void func_003AD7F0(void *p, f32 value) {
    *(f32 *)((u8 *)p + 0x24) = value;
}
/* localdecomp:end func_003AD7F0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AD7F8);

/* localdecomp:start func_003AD820 */
u8 *func_003AD820(u8 *p) {
    u8 *q;
    u8 *a, *b, *c;
    s32 i;
    func_003AB430(p);
    func_003AB430(p + 0x3C);
    func_003AB430(p + 0x78);
    func_003ABBD0(p + 0xD0);
    func_003AB950(p + 0x110);
    func_003AB430(p + 0x140);
    func_003AB430(p + 0x17C);
    func_003ABBD0(p + 0x1D0);
    func_003AB950(p + 0x210);
    func_003AB430(p + 0x244);
    func_003AB430(p + 0x280);
    q = p + 0x2BC;
    for (i = 7; i != -1; i--) { func_003AB430(q); q += 0x3C; }
    func_003AB430(p + 0x49C);
    func_003AB430(p + 0x4D8);
    func_003AB430(p + 0x514);
    func_003AB430(p + 0x550);
    func_003AB430(p + 0x58C);
    func_003AB950(p + 0x5C8);
    func_003AB950(p + 0x5F8);
    func_003AB430(p + 0x628);
    q = p + 0x664;
    for (i = 7; i != -1; i--) { func_003AB950(q); q += 0x30; }
    func_003AD608(p + 0x7E8);
    func_003AD608(p + 0x870);
    func_003AD608(p + 0x8F8);
    func_003AD608(p + 0x980);
    func_003AD608(p + 0xA08);
    func_003AD608(p + 0xA90);
    func_003AADC8(p + 0xB18);
    *(u8 **)(p + 0xB18) = (u8 *)D_001D8118;
    func_003AADC8(p + 0xB1C);
    *(u8 **)(p + 0xB1C) = (u8 *)D_001D8100;
    return p;
}
/* localdecomp:end func_003AD820 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AD9E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AD9F0);

/* localdecomp:start func_003AED60 */

void func_003AED60(void *arg0, s32 arg1) {
    void *temp_s0;
    void *temp_s1;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;
    void *temp_s5;

    (*(s32 *)((u8 *)(arg0) + 0xB38)) = arg1;
    if ((*(s32 *)((u8 *)(arg0) + 0xB3C)) != 0) {
        (*(s32 *)((u8 *)(arg0) + 0xB3C)) = 0;
        temp_s4 = arg0 + 0x7E8;
        func_003AB118(arg0 + 0x628, 0);
        temp_s5 = arg0 + 0x870;
        func_003AD7A8(temp_s4, 1);
        temp_s3 = arg0 + 0x8F8;
        func_003AD7A8(temp_s5, 1);
        temp_s2 = arg0 + 0x980;
        func_003AD7A8(temp_s3, 1);
        temp_s1 = arg0 + 0xA08;
        func_003AD7A8(temp_s2, 1);
        temp_s0 = arg0 + 0xA90;
        func_003AD7A8(temp_s1, 1);
        func_003AD7A8(temp_s0, 1);
        func_003AD718(temp_s4);
        func_003AD718(temp_s5);
        func_003AD718(temp_s3);
        func_003AD718(temp_s2);
        func_003AD718(temp_s1);
        func_003AD718(temp_s0);
    }
}
/* localdecomp:end func_003AED60 */

/* localdecomp:start func_003AEE58 */
typedef struct { u8 p0[0x1C4]; u32 f1C4; } S_3A9698;
extern S_3A9698 *D_001D52FC[];
extern s32 func_003829F8(s32, s32, s32, s32, s32, s32);
extern s32 *func_003AB0D0();
extern f32 *func_003AB5A8();
extern void func_003AB118();
void func_003AEE58(u8 *base, s32 b, f32 f) {
    s32 *r;
    f32 *q;
    u8 *p;
    if ((D_001D52FC[0]->f1C4 & 0xF000) != 0) {
        func_003829F8(0, 0, 1, 0, 1, 0);
    }
    p = base + 0x628;
    r = func_003AB0D0(p);
    *r = func_003829F8(0x331465B7, 0x706EC8FF, 0x14, 0, 0, 0);
    q = func_003AB5A8(p);
    *q = f;
    func_003AB118(p, b);
}
/* localdecomp:end func_003AEE58 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AEF18);

/* localdecomp:start func_003AEF28 */
u8 *func_003AEF28(u8 *p) {
    u8 *q; u8 *base; s32 i, j, k;
    base = p;
    for (j = 3; j != -1; j--) {
        q = base;
        for (k = 25; k != -1; k--) { func_003AB680(q); q += 0x3C; }
        base += 0x618;
    }
    func_003AB680(p + 0x1860);
    q = p + 0x18A0;
    for (i = 3; i != -1; i--) { func_003AD820(q); q += 0xB50; }
    func_003AB950(p + 0x45E0);
    q = p + 0x4610;
    for (i = 3; i != -1; i--) { func_003AC188(q); q += 0x230; }
    func_003AC188(p + 0x4ED0);
    return p;
}
/* localdecomp:end func_003AEF28 */

/* localdecomp:start func_003AF050 */
extern u8 *D_001D5C78_003AF050;
extern s32 D_001D545C;
extern u8 D_001D8730[];
extern u8 D_001D8740[];
__asm__(".extern D_001D5C78_003AF050, 16");
__asm__(".extern D_001D545C, 16");
extern s32 func_003ABFF0();
extern void func_003AB6B8();
extern void func_003ABF30();
extern void func_003ABDF8();
extern void func_003ABE00();
extern void func_003AB748();
extern void func_003AB760();
extern void func_003ABF48();
extern void func_003ABF28();
extern void func_003AD9F0();
extern void func_003AC1C0();
extern void func_003AB990();
extern f32 *func_003ABA38();
typedef struct { u8 pad[0x5100]; s32 a[4]; s32 b[4]; } S_3A9890;
void func_003AF050(S_3A9890 *sx, s32 a1, s32 a2) {
    u8 *s = (u8 *)sx;
    u8 *b;
    u8 *q;
    s32 i;
    s32 k;
    u32 j;
    f32 *r;
    for (k = 0; k < 4; k++) {
        sx->a[k] = func_003ABFF0(D_001D5C78_003AF050 + 0x7090, 0xC);
        sx->b[k] = func_003ABFF0(D_001D5C78_003AF050 + 0x7090, 0xD);
    }
    if (D_001D545C != -2) {
        for (i = 0; i < 4; i++) {
            b = s + i * 0x618;
            j = 0;
            do {
                func_003AB6B8(b, 0x16, 1, D_001D8730, a2);
                func_003ABF30(b, 5);
                func_003ABDF8(b, 0x64);
                func_003ABE00(b, 0);
                func_003AB748(b, 0x706EC8FF, 0x706EC8FF);
                func_003AB760(b, 0x80808080, 0x80808080);
                func_003ABF48(b, 0x80000000);
                func_003ABF28(b, 1);
                j++;
                b += 0x3C;
            } while (j < 0x1A);
            func_003AD9F0(s + (i * 0xB50 + 0x18A0), a1, a2);
            func_003AC1C0(s + (i * 0x230 + 0x4610), a2);
        }
    }
    q = s + 0x45E0;
    func_003AB990(q, D_001D8740, a2);
    *(f32 *)func_003AB0D0(q) = 2155905024.0f;
    *func_003ABA38(q) = 60008.0f;
    ((s32 *)func_003ABA38(q))[1] = 0;
    *(s32 *)(s + 0x189C) = a2;
    func_003AC1C0(s + 0x4ED0, a2);
}
/* localdecomp:end func_003AF050 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AF270);

/* localdecomp:start func_003AF280 */
extern void func_003ACDD8(void *);
 
void func_003AF280(void *p, s32 i) {
    func_003ACDD8((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003AF280 */

/* localdecomp:start func_003AF2A8 */
extern void func_003AD490(void *);
 
void func_003AF2A8(void *p, s32 i) {
    func_003AD490((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003AF2A8 */

extern void *func_003AC040(void *);
extern u8 *func_003AEF28(u8 *);
extern void func_00121760(void *, void *);
extern s32 func_003A29B0();
extern void func_003AC048(void *, s32, void *, s32);
extern void func_0011F0A0(s32);
extern s32 func_003A2A10(s32);
extern void func_003ABF50(void *);
extern void func_003AF050(void *, void *, void *);
extern s32 D_001D5C78;
extern u8 D_00160C40[];

/* localdecomp:start func_003AF2D0 */
typedef struct { u8 b[8]; } V8_3A9B10;
extern u8 D_001D8790[];
extern u8 D_001D8770[];
extern void func_11A264();
extern void func_121760();
extern void func_11F0A0();
void *func_003AF2D0(u8 *a0, s32 a1) {
    s32 i;
    s32 *p;
    s32 z;
    V8_3A9B10 v;
    u32 j;
    s32 sz;
    u8 *t;

    p = (s32 *)(a0 + 4);
    for (i = 0x707; i != -1; i--) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    }
    func_003AC040(a0 + 0x1FC90);
    func_003AEF28(a0 + 0x1FCA8);
    func_121760(D_001D8770, a1);
    sz = 0x24F10;
    D_001D5C78 = (s32)a0;
    *(s32 *)a0 = ((s32)a0 + sz + 3) & ~3;
    *(s32 *)(a0 + 0x24DC8) = sz;
    t = D_00160C40;
    func_003A29B0(a0 + 0x7090, *(s32 *)(t + 0x61C8) + *(s32 *)(t + 0x4954), *(s32 *)(t + 0x61CC));
    ((void (*)(void *, u32, s32, s32))func_003AC048)(a0 + 0x1FC90, 0x10, (s32)(a0 + 4), 0x7080);
    *(s32 *)(a0 + 0x24DCC) = 0;
    *(s32 *)(a0 + 0x24DD0) = 0;
    *(s32 *)(a0 + 0x24DD4) = 0;
    *(s32 *)(a0 + 0x24DD8) = 0;
    *(s32 *)(a0 + 0x24DE4) = 0;
    *(s32 *)(a0 + 0x24DE8) = 0;
    *(s32 *)(a0 + 0x24DEC) = 0;
    func_11A264(a0 + 0x24DF0, 0, 0x20);
    func_11A264(a0 + 0x24E10, 0, 0x100);
    func_11F0A0(0);
    z = 0;
    do {
        v = *(V8_3A9B10 *)D_001D8790;
    } while (z);
    j = 0;
    do { j++; } while (j < 8);
    func_003A2A10(1);
    func_003ABF50(a0 + 0x7090);
    func_003AF050(a0 + 0x1FCA8, a0, a0 + 0x1FC90);
    return a0;
}
/* localdecomp:end func_003AF2D0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AF4A8);
