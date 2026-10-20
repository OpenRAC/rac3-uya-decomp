#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void * func_003A9B10();
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003A95A0(void *, s32);
extern s32 D_001D8118[];
extern s32 D_001D8118[2];
extern s32 D_001D8100[];
extern s32 D_001D8100[2];
extern u8 *func_003A5C70(u8 *);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003A7690 */
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
extern void func_00387BD8_003A7690(s32, s32, s32, s32, s32, u32 *);
extern void func_003A5928(void *, f32, f32, f32, f32);
extern void func_003A5A50(void *, f32, f32, f32, f32);
extern void func_003A5DF0(void *);
extern void func_00389920(s32);
extern void func_00389FB8_003A7690(unsigned long, s32, s32, f32, f32, f32, f32, s32, s32, unsigned long, f32, f32);

void func_003A7690(void *arg0) {
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
    func_00387BD8_003A7690(o->pos[0] - o->w, o->pos[1] - o->h, o->pos[0] + o->w + 2.0f, o->pos[1] + o->h, 0xFFFFF0, cols);
    a = D_001D8440[0];
    b = D_001D8448[0];
    s = 1.0f;
    if (o->mode == 0) s = D_001D8450;
    lh = 16;
    i = 0;
    func_003A5928(o->sub10, o->pos[0] - o->w - a.x, o->pos[1] - o->h - a.y, 0.0f, 0.0f);
    func_003A5A50(o->sub10, -s, s, 0.0f, 0.0f);
    func_003A5DF0(o->sub10);
    func_003A5928(o->sub10, o->pos[0] + o->w + a.x + 1.0f, o->pos[1] - o->h - a.y, 0.0f, 0.0f);
    func_003A5A50(o->sub10, s, s, 0.0f, 0.0f);
    func_003A5DF0(o->sub10);
    func_003A5928(o->sub4C, o->pos[0] + o->w + b.x, o->pos[1] - o->h - b.y, 0.0f, 0.0f);
    func_003A5A50(o->sub4C, s, s, 0.0f, 0.0f);
    func_003A5DF0(o->sub4C);
    func_003A5928(o->sub4C, o->pos[0] - o->w - b.x + 1.0f, o->pos[1] - o->h - b.y, 0.0f, 0.0f);
    func_003A5A50(o->sub4C, -s, s, 0.0f, 0.0f);
    func_003A5DF0(o->sub4C);
    func_003A5928(o->sub4C, o->pos[0] + o->w + b.x, o->pos[1] - o->h - b.y + o->f1B0, 0.0f, 0.0f);
    func_003A5A50(o->sub4C, s, -s, 0.0f, 0.0f);
    func_003A5DF0(o->sub4C);
    func_003A5928(o->sub4C, o->pos[0] - o->w - b.x + 1.0f, o->pos[1] - o->h - b.y + o->f1B0, 0.0f, 0.0f);
    func_003A5A50(o->sub4C, -s, -s, 0.0f, 0.0f);
    func_003A5DF0(o->sub4C);
    ix = o->pos[0] - o->w + o->xoff;
    iy = o->pos[1] - o->h;
    t1 = D_001D8458[0];
    t2 = D_001D8470[0];
    switch (o->mode) {
    case 0:
        if (o->text[0] != 0) {
            for (; i < o->count; i++) {
                s32 old = D_001D55E8;
                func_00389920(1);
                func_00389FB8_003A7690(*o->font, o->text[i], -1, ix + t2.c, iy + t2.d + i * lh, 1.0f, 1.0f, 0, 1, 0x80000000, 2.0f, 2.0f);
                func_00389920(old);
            }
        }
        break;
    case 1:
        if (o->text[0] != 0) {
            for (; i < o->count; i++) {
                func_00389920(1);
                func_00389FB8_003A7690(*o->font, o->text[i], -1, ix + t1.c, iy + t1.d + i * lh + 2, 1.0f, 1.0f, 0, 1, 0x80000000, 2.0f, 2.0f);
            }
        }
        break;
    case 2:
        break;
    }
}
/* localdecomp:end func_003A7690 */

/* localdecomp:start func_003A7CC8 */
s32 func_003A7CC8(void) {
}
/* localdecomp:end func_003A7CC8 */

/* localdecomp:start func_003A7CD0 */
void func_003830E8();
void func_003A7690(void *);
void func_003A7CC8(void *);
typedef struct { u8 pad0[0xB0]; f32 fB0; } S_00225980_003A7CD0_003A7CD0;
extern S_00225980_003A7CD0_003A7CD0 D_00225980[];

void func_003A7CD0(void *arg0) {
    f32 temp_f20;
    s32 temp_v1;

    if (*(*(f32 **)((u8 *)(arg0) + 4)) != 0.0f) {
        temp_f20 = D_00225980->fB0;
        D_00225980->fB0 = 0.62f;
        func_003830E8();
        temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1A8));
        switch (temp_v1) {                          /* irregular */
        case 0:
            func_003A7690(arg0);
            break;
        case 2:
            func_003A7CC8(arg0);
            break;
        }
        D_00225980->fB0 = temp_f20;
        func_003830E8();
    }
}
/* localdecomp:end func_003A7CD0 */

LINKER_REMNANT("asm/remnants", func_003A7D80);

/* localdecomp:start func_003A7E48 */
void *func_003A7E48(u8 *p) {
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
/* localdecomp:end func_003A7E48 */

/* localdecomp:start func_003A7E80 */
typedef struct { u8 p0[0x18]; f32 f18; s32 f1C; s32 f20; f32 f24; s8 b28; u8 p29[3]; s32 f2C; u8 p30[0x50]; s32 f80; s32 f84; } S_3A7E80;
extern u8 func_003A7F90_003A7E80[];
extern u8 func_003A7FC8_003A7E80[];
void func_003A7E80(S_3A7E80 *s) {
    f32 f;
    s->f18 = 0;
    s->b28 = 0;
    f = s->f18;
    s->f2C = 0;
    s->f80 = 0;
    s->f24 = 0.005f;
    ((void (*)(void *, s32, f32, f32, f32, f32, f32))func_003A7F90_003A7E80)(s, 0, f, f, f, f, f);
    ((void (*)(void *, s32, f32, f32, f32, f32, f32))func_003A7F90_003A7E80)(s, 1, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    s->f84 = 2;
    ((void (*)(void *, s32, f32, f32))func_003A7FC8_003A7E80)(s, 0, f, f);
    s->f20 = 0;
    s->f1C = 1;
}
/* localdecomp:end func_003A7E80 */

LINKER_REMNANT("asm/remnants", func_003A7F38);

/* localdecomp:start func_003A7F40 */
void func_003A7F40(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003A7F40 */

LINKER_REMNANT("asm/remnants", func_003A7F48);

/* localdecomp:start func_003A7F58 */
typedef struct {
    char pad_0[0x18];   /* Offset 0x00 down to 0x18 */
    f32 float_field;    /* Offset 0x18 - Targeted by lwc1/swc1 */
    char pad_1C[0xC];   /* Padding from 0x1C to 0x28 */
    char byte_flag;     /* Offset 0x28 - Targeted by sb $v0, 0x28($a0) */
} InitContext;

void func_003A7F58(InitContext* ctx) {
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
/* localdecomp:end func_003A7F58 */

/* localdecomp:start func_003A7F78 */
void func_003A7F78(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x80) = value;
}
/* localdecomp:end func_003A7F78 */

/* localdecomp:start func_003A7F80 */
u8 func_003A7F80(void *p, u8 value) {
    u8 old = *((u8 *)p + 0x28);
    *((u8 *)p + 0x28) = value;
    return old;
}
/* localdecomp:end func_003A7F80 */

/* localdecomp:start func_003A7F90 */
typedef struct { u8 pad[0x30]; f32 m[4][4]; f32 v[4]; } S_3A7F90;
void func_003A7F90(S_3A7F90 *p, s32 i, f32 a, f32 b, f32 c, f32 d, f32 e) {
    p->m[i][0] = b;
    p->m[i][1] = c;
    p->m[i][2] = d;
    p->m[i][3] = e;
    p->v[i] = a;
}
/* localdecomp:end func_003A7F90 */

/* localdecomp:start func_003A7FC8 */
typedef struct { f32 a[3]; f32 b[3]; } V_7FC8;
void func_003A7FC8(V_7FC8 *s, s32 i, f32 x, f32 y) {
    s->a[i] = x; s->b[i] = y;
}
/* localdecomp:end func_003A7FC8 */

/* localdecomp:start func_003A7FE0 */
void func_003A7FE0(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x84) = value;
}
/* localdecomp:end func_003A7FE0 */

/* localdecomp:start func_003A7FE8 */
void func_003A7FE8(u8 *p, s32 a) {
    *(s32 *)(p + 0x1C) = a;
    if (p[0x28] == 0) {
        if (a == 1) *(f32 *)(p + 0x18) = 0.0f;
        else *(f32 *)(p + 0x18) = 1.0f;
        p[0x28] = 1;
    }
}
/* localdecomp:end func_003A7FE8 */

/* localdecomp:start func_003A8028 */
void func_003A8028(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x20) = value;
}
/* localdecomp:end func_003A8028 */

/* localdecomp:start func_003A8030 */
void func_003A8030(void *p, f32 value) {
    *(f32 *)((u8 *)p + 0x24) = value;
}
/* localdecomp:end func_003A8030 */

LINKER_REMNANT("asm/remnants", func_003A8038);

/* localdecomp:start func_003A8060 */
u8 *func_003A8060(u8 *p) {
    u8 *q;
    u8 *a, *b, *c;
    s32 i;
    func_003A5C70(p);
    func_003A5C70(p + 0x3C);
    func_003A5C70(p + 0x78);
    func_003A6410(p + 0xD0);
    func_003A6190(p + 0x110);
    func_003A5C70(p + 0x140);
    func_003A5C70(p + 0x17C);
    func_003A6410(p + 0x1D0);
    func_003A6190(p + 0x210);
    func_003A5C70(p + 0x244);
    func_003A5C70(p + 0x280);
    q = p + 0x2BC;
    for (i = 7; i != -1; i--) { func_003A5C70(q); q += 0x3C; }
    func_003A5C70(p + 0x49C);
    func_003A5C70(p + 0x4D8);
    func_003A5C70(p + 0x514);
    func_003A5C70(p + 0x550);
    func_003A5C70(p + 0x58C);
    func_003A6190(p + 0x5C8);
    func_003A6190(p + 0x5F8);
    func_003A5C70(p + 0x628);
    q = p + 0x664;
    for (i = 7; i != -1; i--) { func_003A6190(q); q += 0x30; }
    func_003A7E48(p + 0x7E8);
    func_003A7E48(p + 0x870);
    func_003A7E48(p + 0x8F8);
    func_003A7E48(p + 0x980);
    func_003A7E48(p + 0xA08);
    func_003A7E48(p + 0xA90);
    func_003A5608(p + 0xB18);
    *(u8 **)(p + 0xB18) = (u8 *)D_001D8118;
    func_003A5608(p + 0xB1C);
    *(u8 **)(p + 0xB1C) = (u8 *)D_001D8100;
    return p;
}
/* localdecomp:end func_003A8060 */

LINKER_REMNANT("asm/remnants", func_003A8228);

/* localdecomp:start func_003A8230 */
typedef struct { u8 pad[0x3A]; u8 f3A; u8 pad3B; } W3C_3A8230;
typedef struct { u8 pad[0x30]; } W30_3A8230;
typedef struct { u8 pad[0x40]; } W40_3A8230;
typedef struct { u8 pad[0x88]; } W88_3A8230;
typedef struct {
    W3C_3A8230 w0;        /* 0x000 */
    W3C_3A8230 w3C;       /* 0x03C */
    W3C_3A8230 w78;       /* 0x078 */
    u8 bufB4[0x1C];       /* 0x0B4 */
    W40_3A8230 wD0;       /* 0x0D0 */
    W30_3A8230 w110;      /* 0x110 */
    W3C_3A8230 w140;      /* 0x140 */
    W3C_3A8230 w17C;      /* 0x17C */
    u8 buf1B8[0x18];      /* 0x1B8 */
    W40_3A8230 w1D0;      /* 0x1D0 */
    W30_3A8230 w210;      /* 0x210 */
    u8 pad240[4];
    W3C_3A8230 w244;      /* 0x244 */
    W3C_3A8230 w280;      /* 0x280 */
    W3C_3A8230 items[8];  /* 0x2BC */
    W3C_3A8230 w49C;      /* 0x49C */
    W3C_3A8230 w4D8;      /* 0x4D8 */
    W3C_3A8230 w514;      /* 0x514 */
    W3C_3A8230 w550;      /* 0x550 */
    W3C_3A8230 w58C;      /* 0x58C */
    W30_3A8230 w5C8;      /* 0x5C8 */
    W30_3A8230 w5F8;      /* 0x5F8 */
    W3C_3A8230 w628;      /* 0x628 */
    W30_3A8230 dots[8];   /* 0x664 */
    f32 *p7E4;            /* 0x7E4 */
    W88_3A8230 a7E8;      /* 0x7E8 */
    W88_3A8230 a870;      /* 0x870 */
    W88_3A8230 a8F8;      /* 0x8F8 */
    W88_3A8230 a980;      /* 0x980 */
    W88_3A8230 aA08;      /* 0xA08 */
    W88_3A8230 aA90;      /* 0xA90 */
    s32 fB18;             /* 0xB18 */
    s32 fB1C;             /* 0xB1C */
    u8 padB20[8];
    s32 fB28, fB2C, fB30, fB34, fB38, fB3C; /* 0xB28 */
    u8 bB40;              /* 0xB40 */
    u8 padB41[3];
    s32 fB44;             /* 0xB44 */
    u8 padB48[8];
} S_3A8230;
__asm__(".extern D_001D867C, 4");
__asm__(".extern D_001D8680, 4");
__asm__(".extern D_001D8684, 4");
__asm__(".extern D_001D8688, 4");
__asm__(".extern D_001D868C, 4");
__asm__(".extern D_001D8690, 4");
__asm__(".extern D_001D8694, 4");
__asm__(".extern D_001D8698, 4");
__asm__(".extern D_001D869C, 4");
__asm__(".extern D_001D86A0, 4");
__asm__(".extern D_001D86A4, 4");
__asm__(".extern D_001D86A8, 4");
__asm__(".extern D_001D86AC, 4");
__asm__(".extern D_001D86B0, 4");
__asm__(".extern D_001D86B4, 4");
extern s32 D_001D867C, D_001D8680;
extern f32 D_001D8684, D_001D8688, D_001D868C;
extern s32 D_001D8690, D_001D8694;
extern s32 D_001D8698, D_001D869C;
extern f32 D_001D86A0, D_001D86A4, D_001D86A8;
extern s32 D_001D86AC, D_001D86B0;
extern s32 D_001D86B4;
extern s32 D_00143950[];
extern char D_001D8530[], D_001D8540[], D_001D8550[], D_001D8558[], D_001D8568[];
extern char D_001D8578[], D_001D8588[], D_001D8598[], D_001D85A8[], D_001D85B8[];
extern char D_001D85C8[], D_001D85D8[], D_001D85E8[], D_001D85F8[], D_001D8608[];
extern char D_001D8618[], D_001D8630[], D_001D8640[], D_001D8650[], D_001D8660[];
extern char D_001D8670[];
extern void func_003A5CA8(void *, char *, s32);
extern void func_003A5E80(void *, u8 *, s32);
extern void func_003A5928(void *, f32, f32, f32, f32);
extern void func_003A5A50(void *, f32, f32, f32, f32);
extern s32 *func_003A5910(void *);
extern f32 *func_003A5908(void *);
extern void func_003A59E8(void *, void *);
extern void func_003A5958(void *, s32);
extern void func_003A5978(void *, void *);
extern void func_003A6450(void *, char *, s32);
extern void func_003A64E0(void *, void *);
extern void func_003A64D8(void *, s32);
extern void func_003A61D0(void *, char *, s32);
extern void func_003A63E0(void *, s32, s32);
extern void *func_003A6910();
extern s32 func_003ECDC0(s32, s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_11B2E8(char *, char *, s32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003A7E80_003A8230(void *, s32);
extern void func_003A7FE0(void *, s32);
extern void func_003A7F90_003A8230(void *, s32, f32, f32, f32, f32, f32);
extern void func_003A7FC8_003A8230(void *, s32, f32, f32);
extern void func_003A7F40(void *, s32);
extern void func_003A8028(void *, s32);
extern void func_003A7F78(void *, s32);
extern void func_003A7FE8(u8 *, s32);
extern void func_003A8030(void *, f32);
extern u8 func_003A7F80(void *, u8);
void func_003A8230(S_3A8230 *s, u8 *a1, s32 a2) {
    f32 *t;
    s32 j;
    char buf[16];
    s32 k;
    f32 v;
    s32 col;

    s->bB40 = 0;
    s->fB44 = 0;
    func_003A5CA8(&s->w0, D_001D8530, a2);
    func_003A5E80(&s->w0, a1 + 0x7090, 0);
    func_003A5928(&s->w0, 10.0f, 10.0f, 0.0f, 0.0f);
    s->w0.f3A = 1;
    func_003A5CA8(&s->w3C, D_001D8540, a2);
    func_003A5928(&s->w3C, 10.0f, 10.0f, 0.0f, 0.0f);
    func_003A5E80(&s->w3C, a1 + 0x7090, 0);
    s->w3C.f3A = 1;
    func_003A5CA8(&s->w78, D_001D8550, a2);
    func_003A5928(&s->w78, 10.0f, 18.5f, 0.0f, 0.0f);
    func_003A5E80(&s->w78, a1 + 0x7090, 0);
    s->w78.f3A = 1;
    func_0011A264(s->bufB4, 0, 0x18);
    func_003A6450(&s->wD0, D_001D8558, a2);
    func_003A5A50(&s->wD0, 0.9f, 0.0f, 0.0f, 0.0f);
    func_003A64E0(&s->wD0, s->bufB4);
    func_003A5928(&s->wD0, 64.0f, 15.0f, 0.0f, 0.0f);
    func_003A64D8(&s->wD0, 0);
    func_003A61D0(&s->w110, D_001D8568, a2);
    func_003A5A50(&s->w110, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003A5928(&s->w110, 20.0f, 15.0f, 0.0f, 0.0f);
    *func_003A5910(&s->w110) = 0x60F0F0B0;
    func_003A5CA8(&s->w140, D_001D8578, a2);
    func_003A5928(&s->w140, 498.0f, 10.0f, 0.0f, 0.0f);
    func_003A5E80(&s->w140, a1 + 0x7090, 0);
    func_003A5CA8(&s->w17C, D_001D8588, a2);
    func_003A5928(&s->w17C, 498.0f, 10.0f, 0.0f, 0.0f);
    func_003A5E80(&s->w17C, a1 + 0x7090, 0);
    func_0011A264(s->buf1B8, 0, 0x18);
    func_003A6450(&s->w1D0, D_001D8598, a2);
    func_003A5A50(&s->w1D0, 0.9f, 0.0f, 0.0f, 0.0f);
    func_003A64E0(&s->w1D0, s->buf1B8);
    func_003A5928(&s->w1D0, 440.0f, 15.0f, 0.0f, 0.0f);
    func_003A64D8(&s->w1D0, 2);
    func_003A61D0(&s->w210, D_001D85A8, a2);
    func_003A5A50(&s->w210, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003A5928(&s->w210, 457.0f, 15.0f, 0.0f, 0.0f);
    func_003A63E0(&s->w210, 0x7567, 0);
    if (a2 != 0) {
        t = (f32 *)func_003ECDC0(0x10, (s32)func_003A6910(a2));
        s->p7E4 = t;
        t[1] = 0.0f;
        t[2] = 0.0f;
        t[3] = 0.0f;
        t[0] = 0.0f;
    }

    func_003A5CA8(&s->w244, D_001D85B8, a2);
    func_003A5E80(&s->w244, a1 + 0x7090, 0x29);
    func_003A5A50(&s->w244, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A5928(&s->w244, 125.0f, 208.0f, 0.0f, 0.0f);
    col = 0x1465B7;
    *func_003A5910(&s->w244) = col;
    func_003A59E8(&s->w244, s->p7E4);
    s->w244.f3A = 1;
    func_003A5CA8(&s->w280, D_001D85C8, a2);
    func_003A5E80(&s->w280, a1 + 0x7090, 0x25);
    func_003A5A50(&s->w280, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A5928(&s->w280, 125.0f, 208.0f, 0.0f, 0.0f);
    col = 0x2299DE;
    *func_003A5910(&s->w280) = col;
    func_003A59E8(&s->w280, s->p7E4);
    s->w280.f3A = 1;
    func_003A5CA8(&s->w628, D_001D85D8, a2);
    func_003A5E80(&s->w628, a1 + 0x7090, 0x2A);
    func_003A5928(&s->w628, 125.0f, 208.0f, 0.0f, 0.0f);
    col = 0xFFFEED;
    *func_003A5910(&s->w628) = col;
    func_003A5958(&s->w628, 0);
    s->w628.f3A = 1;
    func_003A5CA8(&s->w49C, D_001D85E8, a2);
    func_003A5E80(&s->w49C, a1 + 0x7090, 0x27);
    func_003A5928(&s->w49C, 125.0f, 208.0f, 0.0f, 0.0f);
    col = 0x8000FFFF;
    *func_003A5910(&s->w49C) = col;
    func_003A59E8(&s->w49C, s->p7E4);
    s->w49C.f3A = 1;
    func_003A5CA8(&s->w4D8, D_001D85F8, a2);
    func_003A5E80(&s->w4D8, a1 + 0x7090, 0x28);
    func_003A5928(&s->w4D8, 125.0f, 208.0f, 0.0f, 0.0f);
    col = 0x80FFFF00;
    *func_003A5910(&s->w4D8) = col;
    func_003A59E8(&s->w4D8, s->p7E4);
    s->w4D8.f3A = 1;
    func_003A5CA8(&s->w514, D_001D8608, a2);
    func_003A5E80(&s->w514, a1 + 0x7090, 0x26);
    func_003A5928(&s->w514, 125.0f, 208.0f, 0.0f, 0.0f);
    col = 0x800000FF;
    *func_003A5910(&s->w514) = col;
    func_003A59E8(&s->w514, s->p7E4);
    s->w514.f3A = 1;
    func_003A5CA8(&s->w550, D_001D8618, a2);
    func_003A5E80(&s->w550, a1 + 0x7090, 0x8B);
    func_003A5928(&s->w550, 52.0f, 281.0f, 0.0f, 0.0f);
    col = 0x800000FF;
    *func_003A5910(&s->w550) = col;
    func_003A59E8(&s->w550, s->p7E4);
    s->w550.f3A = 1;
    t = func_003A5908(&s->w550);
    *t = -*t;
    func_003A5CA8(&s->w58C, D_001D8630, a2);
    func_003A5E80(&s->w58C, a1 + 0x7090, 0x8A);
    func_003A5928(&s->w58C, 52.0f, 281.0f, 0.0f, 0.0f);
    col = 0x800000FF;
    *func_003A5910(&s->w58C) = col;
    func_003A59E8(&s->w58C, s->p7E4);
    s->w58C.f3A = 1;
    t = func_003A5908(&s->w58C);
    *t = -*t;
    func_003A61D0(&s->w5C8, D_001D8640, a2);
    func_003A5A50(&s->w5C8, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003A5928(&s->w5C8, 24.0f, 278.0f, 0.0f, 0.0f);
    func_003A63E0(&s->w5C8, 0xED51, 0);
    func_003A5958(&s->w5C8, 0);
    *func_003A5910(&s->w5C8) = 0xF0F0B0;
    func_003A61D0(&s->w5F8, D_001D8650, a2);
    func_003A5A50(&s->w5F8, 32.0f, 32.0f, 0.0f, 0.0f);
    func_003A5928(&s->w5F8, 23.0f, 277.0f, 0.0f, 0.0f);
    func_003A63E0(&s->w5F8, 0xED56, 0);
    func_003A5958(&s->w5F8, 0);
    *func_003A5910(&s->w5F8) = 0xF0F0B0;

    {
    s32 i;
    for (i = 0; i < 8; i++) {
        f32 ang;
        f32 x;
        func_11B2E8(buf, D_001D8660, i);
        func_003A5CA8(&s->items[i], buf, a2);
        func_003A5E80(&s->items[i], a1 + 0x7090, i + 3);
        func_003A5A50(&s->items[i], 1.0f, 1.0f, 0.0f, 0.0f);
        func_003A5928(&s->items[i], 125.0f, 208.0f, 0.0f, 0.0f);
        func_003A59E8(&s->items[i], s->p7E4);
        { s32 off = i * 0x3C; ((u8 *)s + off)[0x2F6] = 1; }
        col = 0x1465B7;
        *func_003A5910(&s->items[i]) = col;
        func_11B2E8(buf, D_001D8670, i);
        func_003A61D0(&s->dots[i], buf, a2);
        func_003A5958(&s->dots[i], 0);
        ang = func_00389380(((f32)i + (f32)i) * 3.1415927f * 0.125f - 3.1415927f, 1.5707964f);
        x = (f32)(D_001D8690 + D_001D867C + (s32)(D_001D8684 * func_00388960(ang) * D_001D8688));
        func_003A5928(&s->dots[i], x,
                      (f32)(D_001D8694 + D_001D8680 + (s32)(D_001D8684 * func_00388978(ang) * D_001D868C)),
                      0.0f, 0.0f);
        func_003A5A50(&s->dots[i], 32.0f, 32.0f, 0.0f, 0.0f);
        col = 0xF0F0B0;
        *func_003A5910(&s->dots[i]) = col;
    }
    }
    {
        s32 *c = func_003A5910(&s->w5C8);
        *c = (*c & 0xFF000000) | 0x1465B7;
    }
    {
        s32 *c = func_003A5910(&s->w5F8);
        *c = (*c & 0xFF000000) | 0x1465B7;
    }
    for (j = 0; j < 8; j++) {
        f32 ang;
        f32 x;
        f32 y;
        s32 *c;
        ang = func_00389380(((f32)j + (f32)j) * 3.1415927f * 0.125f - 3.1415927f, 1.5707964f);
        x = (f32)(D_001D86AC + D_001D8698 + (s32)(D_001D86A0 * func_00388960(ang) * D_001D86A4));
        y = (f32)(D_001D86B0 + D_001D869C + (s32)(D_001D86A0 * func_00388978(ang) * D_001D86A8));
        func_003A5928(&s->dots[j], x, y, 0.0f, 0.0f);
        func_003A5A50(&s->dots[j], 32.0f, 32.0f, 0.0f, 0.0f);
        c = func_003A5910(&s->dots[j]);
        *c = (*c & 0xFF000000) | (D_001D86B4 & 0xFFFFFF);
    }
    for (j = 1; j < 8; j++) {
        func_003A5978(&s->items[j], func_003A5908(&s->items[0]));
        func_003A5978(&s->dots[j], func_003A5908(&s->dots[0]));
    }
    func_003A5978(&s->w244, func_003A5908(&s->items[0]));

    func_003A7E80_003A8230(&s->a7E8, a2);
    func_003A7FE0(&s->a7E8, 3);
    /* Key values given as bit patterns: retail builds them in a GPR and moves them with mtc1. */
    k = 0x442D00;
    func_003A7F90_003A8230(&s->a7E8, 0, 0.0f, *(f32 *)&k, 0.0f, 0.0f, 0.0f);
    k = 0x33140000;
    /* The asm hides the constant from cse/combine, which would otherwise fold the
       mtc1 into an li.s through $at; retail keeps lui/ori into $v0 + mtc1. */
    __asm__("ori %0, %0, 0x65B7" : "+r"(k));
    v = *(f32 *)&k;
    func_003A7F90_003A8230(&s->a7E8, 1, 0.3f, v, 0.0f, 0.0f, 0.0f);
    func_003A7F90_003A8230(&s->a7E8, 2, 1.0f, v, 0.0f, 0.0f, 0.0f);
    k = 0x40000000;
    func_003A7FC8_003A8230(&s->a7E8, 1, 0.0f, *(f32 *)&k);
    func_003A7F40(&s->a7E8, (s32)func_003A5910(&s->items[0]));
    func_003A8028(&s->a7E8, 0);
    func_003A7F78(&s->a7E8, (s32)&s->fB1C);
    func_003A7FE8((u8 *)&s->a7E8, -1);
    func_003A8030(&s->a7E8, D_00143950[0] ? 1.0f : 0.833333313f);
    func_003A7F80(&s->a7E8, 0);

    func_003A7E80_003A8230(&s->a870, a2);
    func_003A7FE0(&s->a870, 3);
    func_003A7F90_003A8230(&s->a870, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_003A7F90_003A8230(&s->a870, 1, 0.3f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A7F90_003A8230(&s->a870, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A7F40(&s->a870, (s32)func_003A5908(&s->items[0]));
    func_003A8028(&s->a870, 0);
    func_003A7F78(&s->a870, (s32)&s->fB18);
    func_003A7FE8((u8 *)&s->a870, -1);
    func_003A8030(&s->a870, D_00143950[0] ? 1.0f : 0.833333313f);
    func_003A7F80(&s->a870, 0);

    func_003A7E80_003A8230(&s->aA08, a2);
    func_003A7FE0(&s->aA08, 3);
    k = 0xF00000;
    __asm__("ori %0, %0, 0xF0B0" : "+r"(k));
    v = *(f32 *)&k;
    func_003A7F90_003A8230(&s->aA08, 0, 0.0f, v, 0.0f, 0.0f, 0.0f);
    func_003A7F90_003A8230(&s->aA08, 1, 0.5f, v, 0.0f, 0.0f, 0.0f);
    func_003A7FC8_003A8230(&s->aA08, 0, 0.0f, 0.0f);
    k = 0x80FFFFFF;
    func_003A7F90_003A8230(&s->aA08, 2, 1.0f, *(f32 *)&k, 0.0f, 0.0f, 0.0f);
    func_003A7FC8_003A8230(&s->aA08, 1, 0.0f, 0.0f);
    func_003A7F40(&s->aA08, (s32)func_003A5910(&s->dots[0]));
    func_003A8028(&s->aA08, 0);
    func_003A7F78(&s->aA08, (s32)&s->fB1C);
    func_003A7FE8((u8 *)&s->aA08, -1);
    func_003A8030(&s->aA08, D_00143950[0] ? 1.0f : 0.833333313f);
    func_003A7F80(&s->aA08, 0);

    func_003A7E80_003A8230(&s->a8F8, a2);
    func_003A7FE0(&s->a8F8, 3);
    k = 0xF0C070;
    func_003A7F90_003A8230(&s->a8F8, 0, 0.0f, *(f32 *)&k, 0.0f, 0.0f, 0.0f);
    k = 0x33220000;
    __asm__("ori %0, %0, 0x99DE" : "+r"(k));
    v = *(f32 *)&k;
    func_003A7F90_003A8230(&s->a8F8, 1, 0.3f, v, 0.0f, 0.0f, 0.0f);
    func_003A7F90_003A8230(&s->a8F8, 2, 1.0f, v, 0.0f, 0.0f, 0.0f);
    k = 0x40400000;
    func_003A7FC8_003A8230(&s->a8F8, 1, 0.0f, *(f32 *)&k);
    func_003A7F40(&s->a8F8, (s32)func_003A5910(&s->w280));
    func_003A8028(&s->a8F8, 0);
    func_003A7F78(&s->a8F8, (s32)&s->fB1C);
    func_003A7FE8((u8 *)&s->a8F8, -1);
    func_003A8030(&s->a8F8, D_00143950[0] ? 1.0f : 0.833333313f);
    func_003A7F80(&s->a8F8, 0);

    func_003A7E80_003A8230(&s->a980, a2);
    func_003A7FE0(&s->a980, 3);
    func_003A7F90_003A8230(&s->a980, 0, 0.0f, 1.2f, 1.2f, 0.0f, 0.0f);
    func_003A7F90_003A8230(&s->a980, 1, 0.3f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A7F90_003A8230(&s->a980, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A7F40(&s->a980, (s32)func_003A5908(&s->w280));
    func_003A8028(&s->a980, 0);
    func_003A7F78(&s->a980, (s32)&s->fB18);
    func_003A7FE8((u8 *)&s->a980, -1);
    func_003A8030(&s->a980, D_00143950[0] ? 1.0f : 0.833333313f);
    func_003A7F80(&s->a980, 0);

    func_003A7E80_003A8230(&s->aA90, a2);
    func_003A7FE0(&s->aA90, 3);
    func_003A7F90_003A8230(&s->aA90, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    func_003A7F90_003A8230(&s->aA90, 1, 0.01f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A7F90_003A8230(&s->aA90, 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f);
    func_003A7F40(&s->aA90, (s32)s->p7E4);
    func_003A8028(&s->aA90, 0);
    func_003A7F78(&s->aA90, (s32)&s->fB18);
    func_003A7FE8((u8 *)&s->aA90, -1);
    func_003A8030(&s->aA90, D_00143950[0] ? 1.0f : 0.833333313f);
    func_003A7F80(&s->aA90, 0);

    s->fB28 = 0;
    s->fB2C = -1;
    s->fB30 = 0;
    s->fB34 = -1;
    s->fB38 = 0;
    s->fB3C = -1;
}
/* localdecomp:end func_003A8230 */

/* localdecomp:start func_003A95A0 */

void func_003A95A0(void *arg0, s32 arg1) {
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
        func_003A5958(arg0 + 0x628, 0);
        temp_s5 = arg0 + 0x870;
        func_003A7FE8(temp_s4, 1);
        temp_s3 = arg0 + 0x8F8;
        func_003A7FE8(temp_s5, 1);
        temp_s2 = arg0 + 0x980;
        func_003A7FE8(temp_s3, 1);
        temp_s1 = arg0 + 0xA08;
        func_003A7FE8(temp_s2, 1);
        temp_s0 = arg0 + 0xA90;
        func_003A7FE8(temp_s1, 1);
        func_003A7FE8(temp_s0, 1);
        func_003A7F58(temp_s4);
        func_003A7F58(temp_s5);
        func_003A7F58(temp_s3);
        func_003A7F58(temp_s2);
        func_003A7F58(temp_s1);
        func_003A7F58(temp_s0);
    }
}
/* localdecomp:end func_003A95A0 */

/* localdecomp:start func_003A9698 */
typedef struct { u8 p0[0x1C4]; u32 f1C4; } S_3A9698;
extern S_3A9698 *D_001D52FC[];
extern s32 func_0037E368(s32, s32, s32, s32, s32, s32);
extern s32 *func_003A5910();
extern f32 *func_003A5DE8();
extern void func_003A5958();
void func_003A9698(u8 *base, s32 b, f32 f) {
    s32 *r;
    f32 *q;
    u8 *p;
    if ((D_001D52FC[0]->f1C4 & 0xF000) != 0) {
        func_0037E368(0, 0, 1, 0, 1, 0);
    }
    p = base + 0x628;
    r = func_003A5910(p);
    *r = func_0037E368(0x331465B7, 0x706EC8FF, 0x14, 0, 0, 0);
    q = func_003A5DE8(p);
    *q = f;
    func_003A5958(p, b);
}
/* localdecomp:end func_003A9698 */

LINKER_REMNANT("asm/remnants", func_003A9758);

/* localdecomp:start func_003A9768 */
u8 *func_003A9768(u8 *p) {
    u8 *q; u8 *base; s32 i, j, k;
    base = p;
    for (j = 3; j != -1; j--) {
        q = base;
        for (k = 25; k != -1; k--) { func_003A5EC0(q); q += 0x3C; }
        base += 0x618;
    }
    func_003A5EC0(p + 0x1860);
    q = p + 0x18A0;
    for (i = 3; i != -1; i--) { func_003A8060(q); q += 0xB50; }
    func_003A6190(p + 0x45E0);
    q = p + 0x4610;
    for (i = 3; i != -1; i--) { func_003A69C8(q); q += 0x230; }
    func_003A69C8(p + 0x4ED0);
    return p;
}
/* localdecomp:end func_003A9768 */

/* localdecomp:start func_003A9890 */
extern u8 *D_001D5C78_003A9890;
extern s32 D_001D545C;
extern u8 D_001D8730[];
extern u8 D_001D8740[];
__asm__(".extern D_001D5C78_003A9890, 16");
__asm__(".extern D_001D545C, 16");
extern s32 func_003A6830();
extern void func_003A5EF8();
extern void func_003A6770();
extern void func_003A6638();
extern void func_003A6640();
extern void func_003A5F88();
extern void func_003A5FA0();
extern void func_003A6788();
extern void func_003A6768();
extern void func_003A8230();
extern void func_003A6A00();
extern void func_003A61D0();
extern f32 *func_003A6278();
typedef struct { u8 pad[0x5100]; s32 a[4]; s32 b[4]; } S_3A9890;
void func_003A9890(S_3A9890 *sx, s32 a1, s32 a2) {
    u8 *s = (u8 *)sx;
    u8 *b;
    u8 *q;
    s32 i;
    s32 k;
    u32 j;
    f32 *r;
    for (k = 0; k < 4; k++) {
        sx->a[k] = func_003A6830(D_001D5C78_003A9890 + 0x7090, 0xC);
        sx->b[k] = func_003A6830(D_001D5C78_003A9890 + 0x7090, 0xD);
    }
    if (D_001D545C != -2) {
        for (i = 0; i < 4; i++) {
            b = s + i * 0x618;
            j = 0;
            do {
                func_003A5EF8(b, 0x16, 1, D_001D8730, a2);
                func_003A6770(b, 5);
                func_003A6638(b, 0x64);
                func_003A6640(b, 0);
                func_003A5F88(b, 0x706EC8FF, 0x706EC8FF);
                func_003A5FA0(b, 0x80808080, 0x80808080);
                func_003A6788(b, 0x80000000);
                func_003A6768(b, 1);
                j++;
                b += 0x3C;
            } while (j < 0x1A);
            func_003A8230(s + (i * 0xB50 + 0x18A0), a1, a2);
            func_003A6A00(s + (i * 0x230 + 0x4610), a2);
        }
    }
    q = s + 0x45E0;
    func_003A61D0(q, D_001D8740, a2);
    *(f32 *)func_003A5910(q) = 2155905024.0f;
    *func_003A6278(q) = 60008.0f;
    ((s32 *)func_003A6278(q))[1] = 0;
    *(s32 *)(s + 0x189C) = a2;
    func_003A6A00(s + 0x4ED0, a2);
}
/* localdecomp:end func_003A9890 */

LINKER_REMNANT("asm/remnants", func_003A9AB0);

/* localdecomp:start func_003A9AC0 */
extern void func_003A7618(void *);
 
void func_003A9AC0(void *p, s32 i) {
    func_003A7618((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003A9AC0 */

/* localdecomp:start func_003A9AE8 */
extern void func_003A7CD0(void *);
 
void func_003A9AE8(void *p, s32 i) {
    func_003A7CD0((u8 *)p + (i * 0x230 + 0x4610));
}
/* localdecomp:end func_003A9AE8 */

extern void *func_003A6880(void *);
extern u8 *func_003A9768(u8 *);
extern void func_00121760(void *, void *);
extern s32 func_0039D668();
extern void func_003A6888(void *, s32, void *, s32);
extern void func_0011F0A0(s32);
extern s32 func_0039D6C8(s32);
extern void func_003A6790(void *);
extern void func_003A9890(void *, void *, void *);
extern s32 D_001D5C78;
extern u8 D_00160C40[];
/* localdecomp:start func_003A9B10 */
typedef struct { u8 b[8]; } V8_3A9B10;
extern u8 D_001D8790[];
extern u8 D_001D8770[];
extern void func_11A264();
extern void func_121760();
extern void func_11F0A0();
void *func_003A9B10(u8 *a0, s32 a1) {
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
    func_003A6880(a0 + 0x1FC90);
    func_003A9768(a0 + 0x1FCA8);
    func_121760(D_001D8770, a1);
    sz = 0x24F10;
    D_001D5C78 = (s32)a0;
    *(s32 *)a0 = ((s32)a0 + sz + 3) & ~3;
    *(s32 *)(a0 + 0x24DC8) = sz;
    t = D_00160C40;
    func_0039D668(a0 + 0x7090, *(s32 *)(t + 0x61C8) + *(s32 *)(t + 0x4954), *(s32 *)(t + 0x61CC));
    ((void (*)(void *, u32, s32, s32))func_003A6888)(a0 + 0x1FC90, 0x10, (s32)(a0 + 4), 0x7080);
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
    func_0039D6C8(1);
    func_003A6790(a0 + 0x7090);
    func_003A9890(a0 + 0x1FCA8, a0, a0 + 0x1FC90);
    return a0;
}
/* localdecomp:end func_003A9B10 */

LINKER_REMNANT("asm/remnants", func_003A9CE8);
