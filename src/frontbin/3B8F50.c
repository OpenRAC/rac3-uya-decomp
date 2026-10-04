#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003BD360(s32 p);
typedef int u128_t __attribute__((mode(TI)));
extern void func_00388440();
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 D_001D4B60[];
extern void func_00388440(void *, s32, s32);
extern s32 func_0037DF98();
extern s32 func_0037DF98(s32);
extern void func_003BD8A0(void);
extern s32 D_0016C5E4[];
extern void func_003BD490();
extern void func_003B6528(s32, s32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/nonmatchings/text", func_003B8F50);

/* localdecomp:start func_003B9030 */
extern s32 func_003B9090();
extern void func_003B9880();
void func_003B9030(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x19E9:
        ok = 1;
        *(void **)(p + 0x64) = func_003B9090;
        break;
    case 0x1D98:
        ok = 1;
        *(void **)(p + 0x64) = func_003B9880;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_003B9030 */

/* localdecomp:start func_003B9090 */
s32 func_003B9090(void) {
}
/* localdecomp:end func_003B9090 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B9098);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9160);

INCLUDE_ASM("asm/nonmatchings/text", func_003B92B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9730);

/* localdecomp:start func_003B9880 */
extern void func_003B98B8();
extern void func_00385840();
extern void func_003B9730(void *);
void func_003B9880(void *p) {
    func_00385840(func_003B98B8, p);
    func_003B9730(p);
}
/* localdecomp:end func_003B9880 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B98B8);

/* localdecomp:start func_003B99A0 */
extern u8 D_001DA354[];
extern u8 D_001DA380[];
extern s32 D_001D93A4[];
u8 func_003B8700(void);
s32 func_003B99A0(s32 a) {
    s32 r = 0;
    if ((D_001DA354[0] = func_003B8700()) != 0 && a) {
        r = D_001DA380[0] != 0;
    }
    D_001D93A4[0] = 1;
    return r;
}
/* localdecomp:end func_003B99A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B9A08);

/* localdecomp:start func_003B9B38 */
extern void func_003B8A48();
extern void func_003B7288();
 
void func_003B9B38(void) {
    func_003B8A48();
    func_003B7288();
}
/* localdecomp:end func_003B9B38 */

/* localdecomp:start func_003B9B60 */
extern u8 D_001DA390;
extern u8 D_001DA391;
extern s32 D_001D8E20;
extern s32 D_001D8E24;
extern void *D_002F8CC0;
extern void func_003B6528(s32, s32);
extern void func_003B6F28();
extern void func_003B87B8(s32, s32 *, s32);
extern s32 func_003B8840(void);
extern void func_003B8928(s32);
extern void func_003B9DA8(void);
extern void func_003B9BE8();
extern void func_003B8E10(void *);
extern void func_003B8D00(s32);
__asm__(".extern D_001DA390, 16");
__asm__(".extern D_001DA391, 16");
__asm__(".extern D_001D8E24, 16");
__asm__(".extern D_002F8CC0, 16");
s32 func_003B9B60(void) {
    register s32 first __asm__("$4") = 0;
    D_001DA390 = 0;
    D_001DA391 = 0;
    __asm__ volatile("" : : : "memory");
    {
        register s32 second __asm__("$5") = 0;
        func_003B6528(first, second);
    }
    func_003B6F28(4, &D_001D8E20);
    func_003B87B8(3, &D_001D8E24, D_001D8E20);
    func_003B8928(func_003B8840());
    {
        register u8 *callback __asm__("$2") = (u8 *)0x3C0000;
        register u8 *slot_base __asm__("$3") = (u8 *)0x300000;
        register u8 *handler __asm__("$4");
        __asm__ volatile("" : "+r"(callback), "+r"(slot_base));
        callback -= 0x6258;
        handler = (u8 *)0x3C0000;
        __asm__ volatile("" : "+r"(handler));
        *(void **)(slot_base - 0x7340) = callback;
        handler -= 0x6418;
        func_003B8E10(handler);
    }
    func_003B8D00(1);
    return 1;
}
/* localdecomp:end func_003B9B60 */

/* localdecomp:start func_003B9BE8 */
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x74]; s16 hAA; } S_3B9BE8;
extern s32 D_001D4B60[];
extern u8 func_0037DC58(void);
void func_003B9BE8(S_3B9BE8 *p) {
    if (p->hAA == 0x50A) {
        if (D_001D4B60[0] == 4 || ((s32 (*)(void))func_0037DC58)() > 0) {
            p->h34 |= 1;
        }
    }
    p->h34 |= 2;
}
/* localdecomp:end func_003B9BE8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B9C50);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9DA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B9E98);

/* localdecomp:start func_003BA0B8 */
extern s32 func_003B89F8(void);
extern void func_003B9E98(void *a);
void func_003BA0B8(void *a) {
    if (func_003B89F8() == 2) return;
    if (func_003B89F8() == 3) return;
    func_003B9E98(a);
}
/* localdecomp:end func_003BA0B8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BA108);

/* localdecomp:start func_003BA280 */
extern void func_003B8A48();
extern void func_003B7288();
 
void func_003BA280(void) {
    func_003B8A48();
    func_003B7288();
}
/* localdecomp:end func_003BA280 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BA2A8);

/* localdecomp:start func_003BA350 */
extern s32 D_0016C5E4[];
s32 func_003BA350(void) {
    return D_0016C5E4[0] == 1;
}
/* localdecomp:end func_003BA350 */

/* localdecomp:start func_003BA368 */
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x2E]; void *x64; u8 pad3[0x42]; s16 hAA; } S_3BA368;
extern void func_003BB210();
extern void func_003BA850(S_3BA368 *p);
void func_003BA368(S_3BA368 *p) {
    s32 r = 0;
    if (p->hAA == 0x1E01) {
        p->x64 = func_003BB210;
        func_003BA850(p);
        r = 1;
    }
    if (r) p->h34 &= ~2;
    else p->h34 |= 2;
}
/* localdecomp:end func_003BA368 */

/* localdecomp:start func_003BA3C8 */
extern void func_003A2DF8(void *);
extern u8 D_00319170[];
 
void func_003BA3C8(void) {
    func_003A2DF8(D_00319170);
}
/* localdecomp:end func_003BA3C8 */

/* localdecomp:start func_003BA3E8 */
extern u8 *D_001D6EEC_003BA3E8[];
void func_003BA3E8(s32 a0, u8 *src) {
    u8 *p;
    s32 i;
    if (D_001D6EEC_003BA3E8[0] == 0) return;
    p = D_001D6EEC_003BA3E8[0];
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
    } while (i < 0x15E);
}
/* localdecomp:end func_003BA3E8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BA490);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA5B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA748);

INCLUDE_ASM("asm/nonmatchings/text", func_003BA850);

/* localdecomp:start func_003BA948 */
extern s32 D_001DA39C[];
extern void func_003C7CE0(s32);
void func_003BA948(void) {
    s32 *p = D_001DA39C;
    s32 i;
    for (i = 5; i >= 0; i--, p++) {
        if (*p) { func_003C7CE0(*p); *p = 0; }
    }
}
/* localdecomp:end func_003BA948 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BA9A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BAE98);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB210);

INCLUDE_ASM("asm/nonmatchings/text", func_003BB398);

/* localdecomp:start func_003BB4D8 */
extern void func_003A3028();
extern s32 func_003BA350(void);
extern void func_003BA9A0(void *);
extern void func_003BAE98(void *);
void func_003BB4D8(void *p) {
    func_003A3028(p);
    if (func_003BA350()) func_003BA9A0(p);
    func_003BAE98(p);
}
/* localdecomp:end func_003BB4D8 */

/* localdecomp:start func_003BB520 */
extern void func_003B8A48();
extern void func_003B7288();
extern void func_003BA948();
 
void func_003BB520(void) {
    func_003B8A48();
    func_003B7288();
    func_003BA948();
    func_003BA3C8();
}
/* localdecomp:end func_003BB520 */

/* localdecomp:start func_003BB558 */
typedef struct { u8 pad[0x40]; s32 w40; s32 w44; } S_3BB558;
extern S_3BB558 D_002CE040[];
extern void func_003B6528(s32, s32);
extern s32 func_0037DF98(s32); extern s32 func_11BB58(void *, s32, s32);
extern void func_003B8B10(f32);
s32 func_003BB558(void) {
    func_003B6528(0, 0);
    func_11BB58(D_002CE040, func_0037DF98(0x14D7), 0x40);
    D_002CE040[0].w40 = 0xB4;
    D_002CE040[0].w44 = 0;
    func_003B8B10(1.0f);
    return 1;
}
/* localdecomp:end func_003BB558 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BB5C0);

/* localdecomp:start func_003BB730 */
extern s32 D_001D4BC0;
extern u8 D_002CE040_003BB730[];
extern void func_00384B68();
extern void func_0038C718(s32, s32, unsigned long, u8 *, s32, f32);
extern void func_00384C98();
void func_003BB730(void) {
    func_00384B68(1);
    func_0038C718(D_001D4BC0 >> 1, 0xA0, 0x80FFFFFF, D_002CE040_003BB730, -1, 1.2f);
    func_00384C98();
}
/* localdecomp:end func_003BB730 */

/* localdecomp:start func_003BB790 */
extern void func_003A2DF8(void *);
extern u8 D_00319170[];
 
void func_003BB790(void) {
    func_003A2DF8(D_00319170);
}
/* localdecomp:end func_003BB790 */

/* localdecomp:start func_003BB7B0 */
extern u8 D_001D8D50;
void func_003BB7B0(void) {
    D_001D8D50 = 0;
}
/* localdecomp:end func_003BB7B0 */

/* localdecomp:start func_003BB7B8 */
extern s32 D_002CE098[];
extern s32 func_11BB58(void *, s32, s32);
extern u8 D_001D8D50;
void func_003BB7B8(s32 a0) {
    D_001D8D50 = 1;
    func_11BB58(D_002CE098, a0, 0x40);
}
/* localdecomp:end func_003BB7B8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BB7E8);

/* localdecomp:start func_003BB9F0 */
extern void func_003BBD70();
void func_003BB9F0(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x1E03:
        *(u16 *)(p + 0x34) |= 1;
        *(void **)(p + 0x64) = func_003BBD70;
        ok = 1;
        break;
    case 0xD54:
        *(void **)(p + 0x64) = 0;
        ok = 1;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_003BB9F0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BBA50);

INCLUDE_ASM("asm/nonmatchings/text", func_003BBC48);

/* localdecomp:start func_003BBD70 */
extern void func_00385688(void (*)(), s32);
extern void func_003BBD98();
 
void func_003BBD70(s32 a0) {
    func_00385688(func_003BBD98, a0);
}
/* localdecomp:end func_003BBD70 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BBD98);

/* localdecomp:start func_003BBF80 */
extern void func_003A1340(void *);
extern void func_003A26D0(void *);
extern void func_003A3028();
void func_003BBF80(u8 *p) {
    if (p[0x95] < 11) return;
    func_003A1340(p);
    func_003A26D0(p);
    func_003A3028();
}
/* localdecomp:end func_003BBF80 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BBFC8);

/* localdecomp:start func_003BC0B8 */
extern s16 D_0016C5AC[];
 
void func_003BC0B8(void) {
    func_003B8A48();
    func_003B7288();
    func_003BB790();
    D_0016C5AC[0] = 1;
}
/* localdecomp:end func_003BC0B8 */

/* localdecomp:start func_003BC0F0 */
extern s32 func_0037DF98(s32);
extern void func_003B6528(s32, s32);
extern void func_003B6F28(s32, s32);
extern s32 func_0011B754(void *, s32);
__asm__(".extern D_001D90B8_003BC0F0, 1");
extern u8 D_001D90B8_003BC0F0;
extern volatile s32 D_001D4B4C_003BC0F0;
typedef struct { u8 n0[0x10]; u8 n1[0x10]; u8 n2[0x10]; s32 f30, f34, f38, f3C, f40, f44, f48, f4C, f50; u8 p54[0xC]; s8 f60; } S_BC0F0;
extern S_BC0F0 D_002CE0E0_003BC0F0[];
typedef struct { u8 pad[0x1AF8]; s32 f1AF8; u8 p2[0x1B14-0x1AFC]; s32 f1B14, f1B18, f1B1C; } S_BC0F0b;
extern S_BC0F0b D_001A4BE0_003BC0F0[];
s32 func_003BC0F0(s32 arg0, s32 arg1) {
    S_BC0F0 *p = D_002CE0E0_003BC0F0;
    S_BC0F0b *q;
    func_0011B754(p->n0, func_0037DF98(0x1645));
    func_0011B754(p->n1, func_0037DF98(0x1646));
    func_0011B754(p->n2, func_0037DF98(0xF07));
    p->f30 = 0;
    q = D_001A4BE0_003BC0F0;
    p->f34 = q->f1B14;
    p->f38 = q->f1B1C;
    p->f3C = q->f1B18;
    p->f40 = arg1;
    if (arg1 != 0 && q->f1AF8 != 0) {
        p->f40 = 0;
    }
    D_002CE0E0_003BC0F0->f44 = arg0;
    D_002CE0E0_003BC0F0->f60 = 0;
    func_003B6528(0, 0);
    if (D_002CE0E0_003BC0F0->f40 == 0) {
        D_002CE0E0_003BC0F0->f48 = 0;
        D_002CE0E0_003BC0F0->f4C = 0x3C;
        D_002CE0E0_003BC0F0->f50 = 0;
        D_001D4B4C_003BC0F0 = 0;
    } else {
        D_002CE0E0_003BC0F0->f48 = 0;
        D_002CE0E0_003BC0F0->f4C = 0x3C;
        func_003B6F28(3, (s32)&D_001D90B8_003BC0F0);
    }
    return 1;
}
/* localdecomp:end func_003BC0F0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BC218);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318A00);

INCLUDE_ASM("asm/nonmatchings/text", func_003BC568);
TEXT_PADDING(2);

INCLUDE_ASM("asm/nonmatchings/text", func_003BCFB0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD0D8);

/* localdecomp:start func_003BD360 */
__asm__(".extern D_001DA520_003BD360, 16");
__asm__(".extern D_001DA530_003BD360, 16");
__asm__(".extern D_001DA534_003BD360, 16");
__asm__(".extern D_001D9D80_003BD360, 16");
typedef struct { u8 pad[0x20]; u8 b20; u8 pad21[0x33]; s32 f54; u8 pad58[0x10]; s32 f68; u8 pad6C[0x34]; s32 fA0; } O_3BD360;
extern u32 D_001DA520_003BD360; 
extern s32 D_001DA530_003BD360; 
extern s32 D_001DA534_003BD360; 
extern s32 D_001D9D80_003BD360; 
extern void func_003C1F10();
extern void func_003BD778();
extern void func_003C23E8();
void func_003BD360(s32 arg) {
    O_3BD360 *o = (O_3BD360 *)arg;
    s32 p;
    if ((u32)o < D_001DA520_003BD360) {
        o->b20 = 0xFD;
    } else {
        o->b20 = 0xFE;
        p = o->f68;
        if (p) {
            if (p >= D_001DA530_003BD360 && p < D_001DA530_003BD360 + D_001DA534_003BD360 * 64) {
                func_003C1F10(p);
                o->f68 = 0;
            }
        }
        while (o->f54) {
            func_003BD778(o, o->f54);
        }
    }
    o->fA0 = D_001D9D80_003BD360 + 2;
    func_003C23E8(o, 0x80807F7F);
}
/* localdecomp:end func_003BD360 */

/* localdecomp:start func_003BD428 */
extern int D_001DA54C_003BD428;
extern int D_001DA53C_003BD428;
extern int D_001DA548_003BD428;
extern int D_001DA540_003BD428;
extern int D_001DA544_003BD428;
__asm__(".extern D_001DA544_003BD428, 4");
extern void func_00388440(void *, int, int);

unsigned int func_003BD428(int count, int base) {
    int size;
    register int start __asm__("$3") = base;
    register int end __asm__("$2");
    size = count * 4;
    end = start + size;

    D_001DA54C_003BD428 = end;
    D_001DA53C_003BD428 = start;
    D_001DA548_003BD428 = start;
    D_001DA540_003BD428 = 0;
    D_001DA544_003BD428 = 0;
    func_00388440((void *)start, 0, size);
    return (D_001DA54C_003BD428 + 0x3F) & 0xFFFFFFC0;
}
/* localdecomp:end func_003BD428 */

/* localdecomp:start func_003BD490 */
typedef struct { u8 p0[0x48]; u8 *tbl[1]; } C_3BD490;
typedef struct { u8 p0[0x24]; C_3BD490 *f24; u8 p28[0x18]; u8 b40; u8 b41; u8 b42; u8 b43; u8 p44[0x14]; s32 f58; s32 f5C; u8 p60[0xC]; u8 b6C; u8 p6D; u8 b6E; } S_3BD490;
extern u8 D_002CE180_003BD490[];
void func_003BD490(S_3BD490 *s)
{
  u8 *new_var2;
  int new_var;
  if (s->b42 != 0xFF)
  {
    new_var2 = s->f24->tbl[s->b42] + (s->b40 * 4);
    s->f58 = *((s32 *) (new_var2 + 0x1C));
    s->b6E = s->f24->tbl[s->b42][0x12];
    s->b6C = s->f24->tbl[s->b42][0x11];
  }
  else
  {
    s->b6C = s->b42;
    s->b6E = 0;
    s->f58 = (s32) (D_002CE180_003BD490 + (s->b40 << 11));
  }
  s->f5C = *((s32 *) ((s->f24->tbl[s->b43] + (new_var = s->b41 * 4)) + 0x1C));
}
/* localdecomp:end func_003BD490 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BD550);

LINKER_REMNANT("asm/remnants", func_003BD630);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD668);

LINKER_REMNANT("asm/remnants", func_003BD768);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD778);

/* localdecomp:start func_003BD810 */
extern s32 D_001DA480[];
extern s32 D_001DA4C0[];
s32 func_003BD810(s32 x) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_001DA480[i] == 0 || D_001DA480[i] == x) {
            D_001DA480[i] = x;
            D_001DA4C0[i] = 0;
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_003BD810 */

/* localdecomp:start func_003BD868 */
extern s32 D_001DA480[];
extern s32 D_001DA4C0[];
void func_003BD868(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        D_001DA480[i] = 0;
        D_001DA4C0[i] = 0;
    }
}
/* localdecomp:end func_003BD868 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BD8A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD9A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BDA38);
