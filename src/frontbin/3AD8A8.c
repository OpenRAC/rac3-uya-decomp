#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003ADC80(void *);
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern s32 func_0039D6C8(s32);
extern void func_0039B760(u8 *, u32);
extern s32 func_003AD8A8(void);
extern void func_003ADAA8(void);
extern void func_003ADAE0();
extern void func_003ADB40(void);
extern void func_003ADBB0(s32);
extern void func_003ADB78(void);
extern void func_003AE368(void);
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
void func_0039B760(u8 *, u32);
extern s32 func_0039D6C8();
extern void func_003ADC70();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AD8A8 */
typedef struct { s32 f0; s32 f4; } S_003AD8A8;
extern u8 D_001DA9B8_003AD8A8[];
extern u8 D_0022A8A0[];
extern u8 D_0022A4A0[];
extern void func_003A4758();
extern void func_003E3F08_003AD8A8();
extern void func_003E1D68();
extern void *func_003E16B8();
extern void *func_003AD820();
extern void func_003E0550_003AD8A8();
extern void func_003E1788_003AD8A8();
extern s32 *func_003AED08();
extern void *func_003AED40();
extern s32 *func_003AEDC8();
extern s32 *func_003AEDF8();
extern s32 func_003E1460();
extern s32 func_003E17C0();
extern void func_003E18C0_003AD8A8();
s32 func_003AD8A8(void) {
    s32 ok = 1;
    s32 t, u, v;
    s32 i;
    u8 *s;
    void *q;
    func_003A4758(1);
    func_003E3F08_003AD8A8();
    func_003E1D68(0);
    func_003E16B8();
    s = D_001DA9B8_003AD8A8;
    if (*(s32 *)(s + 4) != 0) q = s; else q = func_003E16B8();
    t = ok != 0;
    for (i = 0; i < 1; i++) {
        func_003E0550_003AD8A8(func_003AD820(i), i);
        func_003E1788_003AD8A8(q, i, func_003AD820(i));
    }
    func_003E1460(q, 0, func_003AED08());
    func_003E1460(q, 1, func_003AED40(0));
    func_003E1460(q, 2, func_003AED40(1));
    func_003E1460(q, 3, func_003AED40(2));
    func_003E1460(q, 4, func_003AED40(3));
    func_003E1460(q, 5, func_003AEDC8());
    func_003E1460(q, 6, func_003AEDF8(0));
    func_003E1460(q, 7, func_003AEDF8(1));
    func_003E1460(q, 8, func_003AEDF8(2));
    func_003E1460(q, 9, func_003AEDF8(3));
    u = func_003E17C0(q, 0, 0x400, D_0022A8A0, 0x10) != 0;
    ok = t & u;
    u = func_003E17C0(q, 1, 0x12000, D_0022A4A0, 0xC0) != 0;
    ok = ok & u;
    func_003E18C0_003AD8A8(q, 0);
    return ok;
}
/* localdecomp:end func_003AD8A8 */

/* localdecomp:start func_003ADAA8 */
extern void *func_003E16B8();
extern void func_003E14A8(void *);
extern u8 D_001DA9B8[];
 
void func_003ADAA8(void) {
    void *x = D_001DA9B8;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E16B8();
    }
    func_003E14A8(x);
}
/* localdecomp:end func_003ADAA8 */

/* localdecomp:start func_003ADAE0 */
extern u8 D_001D8880;
extern void func_003E2D90();
extern void *func_003E16B8();
extern void func_003E1510();
extern s32 func_003E0FC8();
extern s32 func_003E19C8();
void func_003ADAE0(void) {
    register void *object __asm__("$2");
    register void *base __asm__("$4");
    register u8 *page __asm__("$3");
    if (D_001D8880 == 0) {
        func_003E2D90();
        page = (u8 *)0x1E0000;
        __asm__ volatile("" : "+r"(page));
        base = page - 0x5648;
        if (*(s32 *)((u8 *)base + 4) != 0) {
            object = base;
        } else {
            object = func_003E16B8(base);
        }
        func_003E1510(object);
        object = (void *)func_003E0FC8(0);
        func_003E19C8(object, 0x14);
    }
}
/* localdecomp:end func_003ADAE0 */

/* localdecomp:start func_003ADB40 */
extern u8 D_001DA9B8[];
extern void *func_003E16B8();
extern void func_003E1548();
 
void func_003ADB40(void) {
    void *x = D_001DA9B8;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E16B8();
    }
    func_003E1548(x);
}
/* localdecomp:end func_003ADB40 */

/* localdecomp:start func_003ADB78 */
extern u8 D_001DA9B8[];
extern void *func_003E16B8();
extern void func_003E15D8(void *);

void func_003ADB78(void) {
    void *x = D_001DA9B8;
    if (*(s32 *)((u8 *)x + 0x4) == 0) {
        x = func_003E16B8();
    }
    func_003E15D8(x);
}
/* localdecomp:end func_003ADB78 */

/* localdecomp:start func_003ADBB0 */
__asm__(".extern D_001D8881, 1");
extern void func_003A4758();
extern void func_003E18C0_003ADBB0();
extern void func_003E1668();
extern void *func_003E16B8();
extern s32 D_001D9F40;
extern s32 D_001D9C5C;
extern u8 D_001D8881;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003ADBB0;
extern S_003ADBB0 D_001DA9B8_003ADBB0;
void func_003ADBB0(s32 a) {
    S_003ADBB0 *q;
    void *base;
    if (D_001D9F40 || D_001D9C5C) {
        *(volatile s32 *)&D_001D9F40 = 0;
        return;
    }
    func_003A4758(1);
    if (D_001D8881) return;
    q = &D_001DA9B8_003ADBB0;
    if (q->f4 != 0) base = q; else base = func_003E16B8(q);
    func_003E18C0_003ADBB0(base, a);
    q = &D_001DA9B8_003ADBB0;
    if (q->f4 != 0) base = q; else base = func_003E16B8(q);
    func_003E1668(base);
}
/* localdecomp:end func_003ADBB0 */

LINKER_REMNANT("asm/remnants", func_003ADC68);

extern s32 D_001D8888;
extern s32 D_001D888C;
/* localdecomp:start func_003ADC70 */
extern s32 D_001D8888;
extern s32 D_001D888C;
void func_003ADC70(s32 a) { D_001D8888 = a; D_001D888C = 0; }
/* localdecomp:end func_003ADC70 */

/* localdecomp:start func_003ADC80 */
extern void *D_001D8890;
void func_003ADC80(void *a) {
    D_001D8890 = a;
}
/* localdecomp:end func_003ADC80 */

/* localdecomp:start func_003ADC88 */
extern void *D_001D8890;
extern void func_003ADCB0(void *, s32);
void func_003ADC88(void) {
    if (D_001D8890 != 0) func_003ADCB0(D_001D8890, 0);
}
/* localdecomp:end func_003ADC88 */

/* localdecomp:start func_003ADCB0 */
typedef struct { u8 pad0[0x18]; u16 h18; u8 pad1a[0x12E]; s32 f148; u8 pad14c[0x18]; s32 f164; s32 f168; u8 pad16c[8]; s32 f174; } S_003ADCB0;
extern S_003ADCB0 D_00142430;
extern u8 D_001D4BE0;
extern u8 D_001D4BE0_b_003ADCB0;
extern void func_0012BE28();
extern void func_0013AD58();
extern void func_00399660();
void func_003ADCB0(void *a, s32 b) {
    S_003ADCB0 *e = &D_00142430;
    func_0012BE28(&D_001D4BE0);
    func_0013AD58(&D_001D4BE0_b_003ADCB0);
    func_00399660(a);
    e->f174 = (s32)a;
    e->h18 = b;
    e->f148 = 0;
    if (e->f164 < 0) {
        e->f168 = 0;
        e->f164 = 0x13;
    }
}
/* localdecomp:end func_003ADCB0 */

/* localdecomp:start func_003ADD30 */
__asm__(".extern D_001D888C, 4");
extern s32 D_001D888C;
extern void (*D_001DA180)();
extern void func_0039BF98(s32, s32);
extern void func_003AE430(void);
void func_003ADD30(void) {
    s32 t = D_001D888C;
    switch (t) {
    case 0:
        if (D_001DA180 != 0) {
            D_001DA180();
            D_001DA180 = 0;
        }
        func_0039BF98(0, 0);
        t = D_001D888C;
        t += 1;
        D_001D888C = t;
        break;
    case 1:
        D_001D888C = 2;
        break;
    case 2:
        func_003AE430();
        break;
    }
}
/* localdecomp:end func_003ADD30 */

/* localdecomp:start func_003ADDD0 */
extern s32 D_001D888C;
extern s8 D_001DA020[];
void func_003ADDD0(void) {
    s32 temp_3;

    temp_3 = D_001D888C;
    switch (temp_3) {                               /* irregular */
    case 0:
        func_00397080();
        D_001DA020[0] = 1;
        /* fallthrough */
    case 1:
        func_0039BEC0(4, 1, 1, 0, 0);
        D_001D888C = (s32) (D_001D888C + 1);
        return;
    case 2:
        func_003AE430();
        break;
    }
}
/* localdecomp:end func_003ADDD0 */

/* localdecomp:start func_003ADE68 */
extern s32 D_001D888C;
extern void func_00396F18();
extern void func_003ADC88();
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern void func_003AE430(void);
void func_003ADE68(void) {
    switch (D_001D888C) {
    case 0:
        func_00396F18(func_003ADC88, 0, 0);
    case 1:
        func_0039BEC0(4, 1, 1, 0, 0);
        D_001D888C++;
        break;
    case 2:
        func_003AE430();
        break;
    }
}
/* localdecomp:end func_003ADE68 */

/* localdecomp:start func_003ADEF8 */
extern s32 D_001D888C;
extern void func_00396FA0();
extern void func_003ADC88();
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern void func_003AE430(void);
void func_003ADEF8(void) {
    switch (D_001D888C) {
    case 0:
        func_00396FA0(func_003ADC88, 0, 0);
    case 1:
        func_0039BEC0(4, 1, 1, 0, 0);
        D_001D888C++;
        break;
    case 2:
        func_003AE430();
        break;
    }
}
/* localdecomp:end func_003ADEF8 */

/* localdecomp:start func_003ADF88 */
__asm__(".extern D_001D888C, 4");
__asm__(".extern D_001D8894, 4");
extern void func_00396F18();
extern void func_003AE430(void);
extern void func_003AE438();
extern void func_003AE8A8(void);
extern void func_0013D3C0(s32);
extern s32 D_001D888C;
extern s32 D_001D8894;
extern s32 D_001D4CE8;
void func_003ADF88(void) {
    s32 t;
    s32 v;
    switch (D_001D888C) {
    case 0:
        func_00396F18((void *)func_003ADC88, 0, 0);
        func_003AE438();
        D_001D8894 = 0x1E;
        D_001D888C = D_001D888C + 1;
        break;
    case 1:
        func_003AE438();
        v = D_001D8894;
        if (v > 0) { v = v - 1; D_001D8894 = v; }
        D_001D8894 = v;
        if (v == 0) func_003AE8A8();
        break;
    case 2:
        t = D_001D4CE8;
        if (t == 1 || t == 0x12) func_0013D3C0(1);
        func_003AE430();
        break;
    }
}
/* localdecomp:end func_003ADF88 */

/* localdecomp:start func_003AE068 */
void func_003AE068(void) {
    u8 *b = (u8 *)&D_00142430;
    s32 t = *(s32 *)(b + 0x164);
    *(s16 *)(b + 0x18) = 0;
    *(s32 *)(b + 0x148) = 0;
    if (t < 0) {
        *(s32 *)(b + 0x168) = 0;
        *(s32 *)(b + 0x164) = 0xD;
    }
}
/* localdecomp:end func_003AE068 */

/* localdecomp:start func_003AE098 */
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003AE098;
extern s32 D_001D545C;
extern u8 D_001D5571;
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern void func_0039ED50(void);
extern void func_0013BFE0(s32);
extern void func_003A3A00(void);
void func_003AE098(void) {
    D_001425AC[0] = 1;
    func_0039ED50();
    ((s32 (*)(s32))func_0039D6C8)(1);
    func_0013BFE0(D_00143958[0] == 0);
    {
    s32 v = D_001D545C_gp_003AE098;
    if (D_001D545C < 2 && D_001D5571 == 0) {
        func_003A3A00();
        return;
    }
    func_0039BEC0(6, 2, 5, v, 0);
    }
}
/* localdecomp:end func_003AE098 */

/* localdecomp:start func_003AE120 */
__asm__(".extern D_001D545C_gp_003AE120, 4");
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003AE120;
extern s32 D_001D545C;
extern u8 D_001D5571;
extern s32 D_001D5B74;
extern s32 D_001D9D84;
extern void func_0039ED50(void);
extern s32 func_0039D6C8(s32);
extern void func_0013BFE0(s32);
extern void func_003A3A00(void);
void func_003AE120(void) {
    s32 v;
    D_001425AC[0] = 1;
    func_0039ED50();
    func_0039D6C8(1);
    func_0013BFE0(D_00143958[0] == 0);
    v = D_001D545C_gp_003AE120;
    if (D_001D545C < 2 && D_001D5571 == 0) {
        func_003A3A00();
        return;
    }
    *(volatile s32 *)&D_001D5B74 = 1;
    *(volatile s32 *)&D_001D9D84 = v;
}
/* localdecomp:end func_003AE120 */

/* localdecomp:start func_003AE1A8 */
extern void func_00396FD0();
extern void func_003AE068();
extern void func_003AE098();
extern s32 D_001D888C;
void func_003AE1A8(void)
{
  s32 (*new_var)();
  s32 *new_var2;
  s32 temp_3;
  temp_3 = D_001D888C;
  new_var2 = &D_001D888C;
  switch (*new_var2)
  {
    case 0:
      new_var = &func_003AE068;
      func_00396FD0(new_var, 0, &func_003AE098);

    case 1:
      func_0039BEC0(4, 1, 1, 0, 0);
 do { } while (0);
      temp_3 = *new_var2;
      temp_3 = (s32) (temp_3 + 1);
      D_001D888C = temp_3;
      return;

    case 2:
      func_003AE430();
      break;

  }

}
/* localdecomp:end func_003AE1A8 */

/* localdecomp:start func_003AE240 */
extern s32 D_001D888C;
extern s32 D_001D8898;
extern void func_00396FD0();
extern void func_003AE068();
extern void func_003AE120();
extern void func_003AE438(void);
extern void func_003AE8A8(void);
extern void func_003AE430(void);
void func_003AE240(void) {
    switch (D_001D888C) {
    case 0:
        func_00396FD0(func_003AE068, 0, func_003AE120);
        func_003AE438();
        D_001D8898 = 30;
        D_001D888C++;
        break;
    case 1:
        func_003AE438();
        { s32 t = D_001D8898; if (t > 0) { t--; D_001D8898 = t; } D_001D8898 = t; if (t == 0) func_003AE8A8(); }
        break;
    case 2:
        func_003AE430();
        break;
    }
}
/* localdecomp:end func_003AE240 */

/* localdecomp:start func_003AE300 */
extern s32 D_001D888C;
extern void func_003AE430(void);
void func_003AE300(void) {
    switch (D_001D888C) {
    case 0: D_001D888C = 1; break;
    case 1: D_001D888C = 2; break;
    case 2: func_003AE430(); break;
    }
}
/* localdecomp:end func_003AE300 */

/* localdecomp:start func_003AE368 */
__asm__(".extern D_001D8888, 4");
extern s32 D_001D8888;
extern void func_003ADEF8(void);
extern void func_003ADE68(void);
extern void func_003AE1A8(void);
extern void func_003ADF88(void);
extern void func_003AE240(void);
extern void func_003AE300(void);
extern void func_003ADDD0(void);
extern void func_003ADD30(void);
extern void func_0039BF98(s32, s32);
void func_003AE368(void) {
    switch (D_001D8888) {
    case 1:
        func_003ADEF8();
        break;
    case 2:
        func_003ADE68();
        break;
    case 3:
        func_003AE1A8();
        break;
    case 7:
        func_003ADF88();
        break;
    case 8:
        func_003AE240();
        break;
    case 5:
        func_003AE300();
        break;
    case 4:
        func_003ADDD0();
        break;
    case 6:
        func_003ADD30();
        break;
    case 0:
    default:
        func_0039BF98(0, 0);
        break;
    }
}
/* localdecomp:end func_003AE368 */
/* localdecomp:start func_003AE430 */
extern s32 D_001D8888;
void func_003AE430(void) {
    D_001D8888 = 0;
}
/* localdecomp:end func_003AE430 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AE438);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_003186C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003AE8A8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318740);

/* localdecomp:start func_003AECA0 */
void func_003AECA0(void *p, s32 a) {
    void *q = *(void **)((u8 *)p + 0x4);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)q + 0x1C))(p, a, 0);
}
/* localdecomp:end func_003AECA0 */

/* localdecomp:start func_003AECC8 */
extern s32 func_00392108(s32, s32);
s32 func_003AECC8(u8 *p, s32 a, s32 b) {
    s32 r = func_00392108(a, b);
    *(s32 *)(p + 8) = r;
    return r != 0;
}
/* localdecomp:end func_003AECC8 */

/* localdecomp:start func_003AED00 */
s32 func_003AED00(void *p) {
    return *(s32 *)((u8 *)p + 0x8);
}
/* localdecomp:end func_003AED00 */

/* localdecomp:start func_003AED08 */
extern s32 D_001DA194;
extern s32 D_001DA188;
extern u8 *D_001DA18C[];
extern s32 D_001DA190[];
extern u8 D_001D8948[];
s32 *func_003AED08(void) {
    if (D_001DA194 == 0) { D_001DA18C[0] = D_001D8948; D_001DA188 = 1; D_001DA194 = 1; D_001DA190[0] = 0; }
    return &D_001DA188;
}
/* localdecomp:end func_003AED08 */

/* localdecomp:start func_003AED40 */
extern void **func_003AEE80();
extern s32 D_001DA198;
extern u8 D_0023CAA0[];
void *func_003AED40(s32 arg0) {
    s32 i; u8 *p;
    if (D_001DA198 == 0) {
        p = D_0023CAA0;
        i = 3;
        do { func_003AEE80(p); i--; __asm__ volatile("nop"); p += 0x20; } while (i != -1);
        D_001DA198 = 1;
    }
    return (arg0 << 5) + D_0023CAA0;
}
/* localdecomp:end func_003AED40 */

/* localdecomp:start func_003AEDC8 */
extern s32 D_001DA1AC;
extern s32 D_001DA1A0;
extern u8 *D_001DA1A4[];
extern u8 D_001D88E8[];
s32 *func_003AEDC8(void) {
    if (D_001DA1AC == 0) { D_001DA1A4[0] = D_001D88E8; D_001DA1A0 = 1; D_001DA1AC = 1; }
    return &D_001DA1A0;
}
/* localdecomp:end func_003AEDC8 */

/* localdecomp:start func_003AEDF8 */
typedef struct { u8 b[0x14]; } E_3AEDF8;
extern E_3AEDF8 D_0023CB20[];
extern s32 D_001DA1B0;
extern void **func_003AF0A0(void **);
s32 *func_003AEDF8(s32 idx) {
    s32 i;
    E_3AEDF8 *p;
    if (D_001DA1B0 == 0) {
        p = D_0023CB20;
        i = 3;
        do {
            func_003AF0A0((void **)p);
            i--;
            __asm__ volatile("nop");
            p++;
        } while (i != -1);
        D_001DA1B0 = 1;
    }
    return (s32 *)&D_0023CB20[idx];
}
/* localdecomp:end func_003AEDF8 */

/* localdecomp:start func_003AEE80 */
extern u8 D_001D8928[];
void **func_003AEE80(void **p) { p[0] = (void *)1; p[1] = D_001D8928; p[2] = 0; p[3] = 0; p[4] = 0; p[5] = 0; p[6] = 0; p[7] = 0; return p; }
/* localdecomp:end func_003AEE80 */

/* localdecomp:start func_003AEEB8 */
s32 func_003AEEB8(s32 *p) {
    *p = 8;
    return 1;
}
/* localdecomp:end func_003AEEB8 */

/* localdecomp:start func_003AEEC8 */
extern s32 func_0039D510(s32, s32, s32);
extern s16 D_001CCFD4[];
s32 func_003AEEC8(void *arg0, s32 arg1)
{
  s32 temp_3;
  s32 temp_4;
  s32 temp_6;
  u8 *new_var2;
  char var_7;
  int new_var;
  void *temp_6_2;
  temp_6 = *((s32 *) (((u8 *) arg0) + 0x14));
  var_7 = 0;
  if (temp_6 != 0)
  {
    temp_4 = *((s32 *) (((u8 *) arg0) + 0xC));
    if (temp_4 != 0)
    {
      temp_3 = *((s32 *) (((u8 *) arg0) + 0));
      if (((temp_3 ^ 4) != 0) && ((temp_3 ^ 8) != 0))
      {
        if (D_001CCFD4[0] == 0)
        {
          new_var = 8;
 do { temp_6_2 = (arg1 * new_var) + temp_6; if ((*((s32 *) (((u8 *) temp_6_2) + 4))) > 0) { new_var2 = (u8 *) arg0; *((s32 *) (new_var2 + 0x1C)) = arg1; ((s32 (*)(s32, s32, s32, s32))func_0039D510)(temp_4, (*((s32 *) (((u8 *) temp_6_2) + 0))) + (*((s32 *) (((u8 *) arg0) + 0x18))), *((s32 *) (((u8 *) temp_6_2) + 4)), 0); var_7 = 1; *((s32 *) (((u8 *) arg0) + 0)) = 4; } } while (0);
        }
        else
        {
          *((s32 *) (((u8 *) arg0) + 0x1C)) = arg1;
          *((s32 *) (((u8 *) arg0) + 0)) = 0x10;
          var_7 = 1;
        }
      }
    }
  }
  return var_7;
}
/* localdecomp:end func_003AEEC8 */

/* localdecomp:start func_003AEF70 */
typedef struct { s32 type; s8 pad4[8]; s32 fC; s32 f10; s32 f14; s32 f18; } S_3AEF70;

s32 func_003AEF70(S_3AEF70 *a, s32 b, s32 c, s32 d, s32 e) {
    s32 result = 0;
    s32 t = a->type;
    if ((t ^ 2) == 0 || (t ^ 1) == 0 || (t ^ 8) == 0) {
        a->fC = b;
        a->f10 = c;
        a->f18 = d;
        a->f14 = e;
        result = 1;
    }
    return result;
}
/* localdecomp:end func_003AEF70 */

/* localdecomp:start func_003AEFB0 */
s32 func_003AEFB0(s32 *arg0) {
    s32 val = arg0[4]; // offset 0x10 (4 * 4 bytes)
    
    if (val != 0) {
        return val;
    }
    
    return arg0[3]; // offset 0x0C (3 * 4 bytes)
}
/* localdecomp:end func_003AEFB0 */

/* localdecomp:start func_003AEFD0 */
s32 func_003AEFD0(s32 *p) {
    s32 s = p[0];
    if ((s ^ 0x10) == 0) {
        if (D_001CCFD4[0] == 0) {
            s32 *e = (s32 *)(p[7] * 8 + p[5]);
            func_0039D510(p[3], e[0] + p[6], e[1]);
            p[0] = 4;
        }
    } else if ((s ^ 8) == 0) {
        if (D_001CCFD4[0] == 0) {
            p[0] = 1;
        }
    } else if ((s ^ 4) == 0) {
        if (D_001CCFD4[0] == 0) {
            s32 v = 2;
            if (p[4] != 0) {
                func_0039B760((u8 *)p[3], p[4]);
            }
            p[0] = v;
        }
    }
    return 1;
}
/* localdecomp:end func_003AEFD0 */

/* localdecomp:start func_003AF0A0 */
extern u8 D_001D8908[];
void **func_003AF0A0(void **p) { p[0] = (void *)1; p[1] = D_001D8908; p[2] = 0; p[3] = 0; p[4] = 0; return p; }
/* localdecomp:end func_003AF0A0 */

/* localdecomp:start func_003AF0C8 */
s32 func_003AF0C8(void) {
    return 1;
}
/* localdecomp:end func_003AF0C8 */

/* localdecomp:start func_003AF0D0 */
s32 func_003AF0D0(s32 *p) {
    s32 v = 1;
    if (p[3] != 0) {
        if (p[4] != 0) {
            func_0039B760((u8 *)p[3], p[4]);
        }
        v = 2;
    }
    p[0] = v;
    return 1;
}
/* localdecomp:end func_003AF0D0 */

/* localdecomp:start func_003AF120 */
s32 func_003AF120(s32 *arg0) {
    if (arg0[4] != 0) {
        return arg0[4];
    }
    return arg0[3];
}
/* localdecomp:end func_003AF120 */

/* localdecomp:start func_003AF140 */
s32 func_003AF140(void) {
    return 1;
}
/* localdecomp:end func_003AF140 */

/* localdecomp:start func_003AF148 */
s32 func_003AF148(void) {
    return 2;
}
/* localdecomp:end func_003AF148 */

/* localdecomp:start func_003AF150 */
s32 func_003AF150(void) {
    return 0;
}
/* localdecomp:end func_003AF150 */

/* localdecomp:start func_003AF158 */
s32 func_003AF158(void) {
    return 1;
}
/* localdecomp:end func_003AF158 */

LINKER_REMNANT("asm/remnants", func_003AF160);

/* localdecomp:start func_003AF168 */
s32 func_003AF168(void) {
    return 0;
}
/* localdecomp:end func_003AF168 */

/* localdecomp:start func_003AF170 */
s32 func_003AF170(void) {
    return 1;
}
/* localdecomp:end func_003AF170 */

/* localdecomp:start func_003AF178 */
s32 func_003AF178(void) {
    return 0;
}
/* localdecomp:end func_003AF178 */

/* localdecomp:start func_003AF180 */
s32 func_003AF180(void) {
    return 0;
}
/* localdecomp:end func_003AF180 */

/* localdecomp:start func_003AF188 */
s32 func_003AF188(void) {
    return 0;
}
/* localdecomp:end func_003AF188 */

/* localdecomp:start func_003AF190 */
s32 func_003AF190(void) {
    return 1;
}
/* localdecomp:end func_003AF190 */

/* localdecomp:start func_003AF198 */
extern void func_003934E8(s32, s32);
 
void func_003AF198(void) {
    func_003934E8(0, 0);
}
/* localdecomp:end func_003AF198 */

/* localdecomp:start func_003AF1B8 */
extern void func_003B62D0(s32);
extern void func_003ADC80(void *);
extern void func_003B1028(s32);
extern s32 func_003B2AA0(void);
extern s32 func_003E2E60();
extern void *func_003AFA18();
extern void func_003E1AA8(void *p);
extern u8 D_0023CB70[];
void func_003AF1B8(void) {
    func_003B62D0(1);
    func_003ADC80(D_0023CB70);
    func_003B1028(2);
    func_003E2E60(func_003B2AA0());
    func_003E1AA8(func_003AFA18());
}
/* localdecomp:end func_003AF1B8 */

/* localdecomp:start func_003AF208 */
extern void func_003B62D0(s32);
extern void func_003B1028(s32);
extern s32 func_003B2AA0(void);
extern s32 func_003E2E60();
extern void *func_003AFA18();
extern void func_003E1AA8(void *p);
void func_003AF208(void) {
    func_003B1028(1);
    func_003B62D0(1);
    func_003E2E60(func_003B2AA0());
    func_003E1AA8(func_003AFA18());
}
/* localdecomp:end func_003AF208 */

/* localdecomp:start func_003AF250 */
extern s32 func_003AFC10(void);
extern s32 func_003E2E60();
extern void *func_003AFA18();   /* no prototype: func_003AFA70 passes an arg */
extern void func_003E1AA8(void *p);
 
void func_003AF250(void) {
    func_003E2E60(func_003AFC10());
    func_003E1AA8(func_003AFA18());
}
/* localdecomp:end func_003AF250 */

/* localdecomp:start func_003AF288 */
extern u8 D_00227480[];
extern s32 func_0038E2E8();
extern s32 func_0038E440(void *);
void func_003AF288(void) {
    func_0038E2E8(D_00227480, 0x2B);
    func_0038E440(D_00227480);
}
/* localdecomp:end func_003AF288 */

/* localdecomp:start func_003AF2C0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } E_3AF2C0;
__asm__(".extern D_001D897C, 4");
__asm__(".extern D_001D8970, 4");
__asm__(".extern D_001D8974, 4");
__asm__(".extern D_001D8980, 4");
__asm__(".extern D_001D8988, 4");
__asm__(".extern D_001D8984, 4");
extern f32 D_001D897C;
extern f32 D_001D8970;
extern f32 D_001D8974;
extern f32 D_001D8980;
extern f32 D_001D8988;
extern f32 D_001D8984;
extern f32 D_001D898C;
extern E_3AF2C0 D_00333680_003AF2C0[];
extern s32 func_003E3988(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E3BD0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E3580(s32, s32, s32, s32, s32, s32);
extern s32 func_003E3DF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E38D0(s32, s32, s32);
extern s32 func_003E3330(s32, f32, f32);
extern s32 func_003E33F0(s32, s32);
extern s32 func_003E34A0(s32, s32, s32);
extern s32 func_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E22D0(s32, s32, s32);
extern s32 func_003E30C8(s32, s32);
extern s32 func_003E2DE0(s32, s32);
extern s32 func_003E1E50(s32, f32, f32);
extern s32 func_003AFAA8(s32);
extern s32 func_0037DF98();
void func_003AF2C0(void) {
    f32 half = 0.5f;
    f32 one = 1.0f;
    f32 one2;
    f32 zero;
    s32 i, j;
    E_3AF2C0 *e;
    f32 y, step;
    func_003E3988(0xD0000, 0x3D, 0x332299DE, half, half, one, one, D_001D897C);
    func_003E3988(0xD0001, 0x3E, 0x332299DE, half, half, one, one, D_001D897C);
    func_003E3988(0xD0002, 0x3F, 0x331465B7, half, half, one, one, D_001D897C);
    func_003E3988(0xD0003, 0x40, 0x802299DE, half, half, one, one, D_001D897C);
    func_003E3BD0(0xD0028, 0x402299DE, 0, half, half, 0.333333f, 0.025f);
    func_003AFAA8(0xD000B);
    func_003E3580(0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0028);
    func_003E2DE0(0x10, 0xD000B);
    func_003AFAA8(0xD0025);
    for (i = 0; i < 5; i++) {
        if (D_00333680_003AF2C0[i].x4 == 0x169C) {
            func_003E3DF0(D_00333680_003AF2C0[i].x0, func_0037DF98(0x169C), 0x8066CCFF, 0.5f, 0.0f, 0.465f, 0.078f, 1.0f);
            func_003E22D0(D_00333680_003AF2C0[i].x0, 0x40, 1);
            func_003E38D0(D_00333680_003AF2C0[i].x0, 1, 1);
        } else {
            zero = 0.0f;
            one2 = 1.0f;
            func_003E3A80(D_00333680_003AF2C0[i].x0, func_0037DF98(D_00333680_003AF2C0[i].x4), 0x8066CCFF, zero, zero, one2, one2);
            func_003E22D0(D_00333680_003AF2C0[i].x0, 0x40, 1);
            func_003E3330(D_00333680_003AF2C0[i].x0, 0.425f, 0.85f);
            func_003E33F0(D_00333680_003AF2C0[i].x0, 1);
        }
        func_003E30C8(0xD0025, D_00333680_003AF2C0[i].x0);
    }
    func_003E2DE0(0x11, 0xD0025);
    {
    s32 id = 0x169C;
    step = D_001D8970;
    y = D_001D8974;
    for (i = 4, j = 0; i >= 0; i--, j++) {
        if (D_00333680_003AF2C0[j].x4 == id) y = 0.558f;
        func_003E1E50(D_00333680_003AF2C0[j].x0, 0.5f, y);
        if (D_00333680_003AF2C0[j].x4 == id) y = 0.647f;
        else y += step;
    }
    }
    func_003E3BD0(0x5B0000, 0x332299DE, 0xED5A, D_001D8980, D_001D8988, -0.07f, 0.08615385f);
    func_003E3BD0(0x5B0001, 0x332299DE, 0xED5A, D_001D8984, D_001D898C, 0.07f, -0.08615385f);
    func_003E34A0(0xD000B, 0x5B0000, 0x5B0001);
    for (i = 0; i < 4; i++) {
        func_003E3BD0(i + 0x5B0002, 0x331465B7, 0, 0.5f, 0.2f, 0.33f, 0.006667f);
        func_003E30C8(0xD000B, i + 0x5B0002);
    }
}
/* localdecomp:end func_003AF2C0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AF718);

/* localdecomp:start func_003AF9E0 */
extern s32 func_003E3040();
 
void func_003AF9E0(void) {
    func_003E3040(0x10);
    func_003E3040(0x11);
}
/* localdecomp:end func_003AF9E0 */

/* localdecomp:start func_003AFA08 */
s32 func_003AFA08(void) {
}
/* localdecomp:end func_003AFA08 */

/* localdecomp:start func_003AFA10 */
s32 func_003AFA10(void) {
}
/* localdecomp:end func_003AFA10 */

/* localdecomp:start func_003AFA18 */
extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA1E0;
extern s32 D_001DA1C8[2];
extern void func_003AF2C0();
extern void func_003AF9E0(void);
extern void func_003AF718();
extern s32 func_003AFA08(void);
extern s32 func_003AFA10(void);
void *func_003AFA18() {
    if (D_001DA1E0 == 0) {
        func_003E1A50(D_001DA1C8, (s32)func_003AF2C0, (s32)func_003AF9E0, (s32)func_003AF718, (s32)func_003AFA08, (s32)func_003AFA10);
        D_001DA1E0 = 1;
    }
    return D_001DA1C8;
}
/* localdecomp:end func_003AFA18 */

/* localdecomp:start func_003AFA70 */
void func_003AFA70(s32 arg0) {
    func_003AFA18(arg0);
}
/* localdecomp:end func_003AFA70 */

/* localdecomp:start func_003AFA90 */
extern u8 D_003336D0[];
 
void *func_003AFA90(s32 i) {
    return D_003336D0 + i * 0x9000;
}
/* localdecomp:end func_003AFA90 */

/* localdecomp:start func_003AFAA8 */
typedef struct { void *f0; void *f4; void *(*f8)(void *, void *); void (*fC)(void *, void *); } VT_3AFAA8;
typedef struct { VT_3AFAA8 *vt; } O_3AFAA8;
typedef struct { void *f0; void *f4; void (*f8)(void *, s32); } VT2_3AFAA8;
typedef struct { s32 f0; s32 f4; VT2_3AFAA8 *vt; } P_3AFAA8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_3AFAA8;
extern u8 D_001DA9B8[];
extern void *func_003E16B8();
extern s32 func_003E1898();
extern void func_003E1E38(s32);
extern s32 func_003E1E40();
extern s32 func_003E03A8();
extern s32 func_003E1770();
extern s32 func_003ECDC0(s32, s32);
extern s32 func_003E89F0();
extern void func_003E0DF8();
s32 func_003AFAA8(s32 a0) {
    S_3AFAA8 *q;
    void *x;
    void *s;
    void *w;
    void *e;
    P_3AFAA8 *p;
    O_3AFAA8 *o;
    s32 r = 0;
    x = D_001DA9B8;
    if (((S_3AFAA8 *)x)->f4 == 0) x = func_003E16B8();
    s = (void *)func_003E1898(x);
    func_003E1E38(0x30);
    w = (void *)func_003E1E40();
    if (s != 0) {
        if (func_003E03A8(s, a0) == 0) {
            q = (S_3AFAA8 *)D_001DA9B8;
            if (q->f4 != 0) x = q; else x = func_003E16B8(q);
            o = (O_3AFAA8 *)func_003E1770(x, 1);
            e = o->vt->f8(o, w);
            if (e != 0) {
                p = (P_3AFAA8 *)func_003E89F0(func_003ECDC0(0x30, (s32)e));
                r = ((s32 (*)())func_003E0DF8)(s, p, a0) != 0;
                if (r == 0) {
                    p->vt->f8(p, 2);
                    q = (S_3AFAA8 *)D_001DA9B8;
                    if (q->f4 != 0) x = q; else x = func_003E16B8(q);
                    o = (O_3AFAA8 *)func_003E1770(x, 1);
                    o->vt->fC(o, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003AFAA8 */

/* localdecomp:start func_003AFC10 */
extern s32 func_003E1A50(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001DA200;
extern s32 D_001DA1E8[2];
extern void func_003AFC68();
extern void func_003B0210(void);
extern void func_003AFF20();
extern void func_003B0258(void);
extern void func_003B0278(void);
s32 func_003AFC10(void) {
    if (D_001DA200 == 0) {
        func_003E1A50(D_001DA1E8, (s32)func_003AFC68, (s32)func_003B0210, (s32)func_003AFF20, (s32)func_003B0258, (s32)func_003B0278);
        D_001DA200 = 1;
    }
    return (s32)D_001DA1E8;
}
/* localdecomp:end func_003AFC10 */

/* localdecomp:start func_003AFC68 */
__asm__(".extern D_001D89EC, 4");
__asm__(".extern D_001D8A14, 4");
extern s32 D_001D89EC;
extern s32 D_001D8A14;
extern u8 D_0037B8D0[];
extern f32 D_001D96D8_003AFC68;
extern void func_003B0580();
extern void func_00389920(s32);
extern s32 func_0037DF98();
extern s32 func_00389D18(f32, s32, s32);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E2C88(s32, f32, f32);
extern void func_003B02A0();
extern s32 func_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E23C0(s32, s32, s32);
extern s32 func_003E22D0(s32, s32, s32);
extern s32 func_003E30C8(s32, s32);
extern s32 func_003E2DE0(s32, s32);
extern s32 func_003E24B0(s32, s32);
extern s32 func_003E31A8(s32, s32);
extern s32 func_003E28E0(s32, s32);
extern s32 func_003E3250(s32, s32, s32);
extern void func_003B07B8();
extern void func_003B0A60();
extern void *func_003AED40();
void func_003AFC68(void) {
    s32 flag = 0;
    f32 lim = 0.49f;
    f32 scale = 0.0f;
    f32 base = 0.0f;
    f32 lo = 6.0f;
    f32 hi = 11.0f;
    f32 x, y;
    D_001D89EC = -1;
    D_001D8A14 = 0;
    func_003B0580();
    func_00389920(0);
    x = (f32)func_00389D18(1.2f, func_0037DF98(0x107), -1) / D_001D96D8_003AFC68;
    if (lim < x) {
        flag = 1;
        scale = 0.588000059f / x;
        x = lim;
    }
    y = func_003BEB48(lo, hi, (x - base) / lim);
    if (hi < y) y = hi;
    else if (y < lo) y = lo;
    func_003B3DB8(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, y, 0xD0008, func_0037DF98(0x107), 0xD0006, 0xFF, 0xD0007, 0xCD5);
    if (flag) func_003E2C88(0xD0005, scale, scale);
    func_003B02A0(D_0037B8D0);
    func_003E3A80(0x1C0004, func_0037DF98(0x1EBD), 0x8066CCFF, 0.5f, 0.932f, 0.9f, 0.9f);
    func_003E23C0(0x1C0004, 3, 3);
    func_003E22D0(0x1C0004, 0x2040, 1);
    func_003E30C8(0x1C0000, 0x1C0004);
    func_003E2DE0(0x11, 0x1C0000);
    func_003E24B0(0x1C0003, 0);
    func_003E31A8(0x1C0003, func_003AED40(0));
    func_003E28E0(0x1C0003, 5);
    func_003E3250(0x1C0003, 1, 0xA);
    func_003B07B8();
    func_003B0A60();
}
/* localdecomp:end func_003AFC68 */

/* localdecomp:start func_003AFF20 */
typedef struct { u8 p[0x1C0]; u32 f1C0; u32 f1C4; } P_3AFF20;
__asm__(".extern D_001D8A14, 4");
__asm__(".extern D_001D8A18, 4");
__asm__(".extern D_001D8A1C, 4");
__asm__(".extern D_001D89E0, 4");
__asm__(".extern D_001D89E4, 4");
__asm__(".extern D_001D8A2C, 4");
extern s32 D_001D8A14;
extern s32 D_001D8A18;
extern s32 D_001D8A1C;
extern s32 D_001D89E0;
extern s32 D_001D89E4;
extern s32 D_001D8A2C;
__asm__(".extern D_001D5520_003AFF20, 16");
extern s32 D_001D5520_003AFF20;
extern s32 D_001D5520_g_003AFF20;
__asm__(".extern D_001D52FC_003AFF20, 16");
extern P_3AFF20 *D_001D52FC_003AFF20;
extern P_3AFF20 *D_001D52FC_g_003AFF20;
extern u8 D_0037B6D0[];
extern char D_001D8A20[];
extern s32 func_003B42D0(void);
extern s32 func_003B41F0(void);
extern s32 func_003B4220();
extern void func_003B41F8();
extern void func_003B0F58(void);
extern void func_003B43B0(void);
extern void func_0038CBD0(s32, s32, s32);
extern void func_003B5018(void *, s32);
extern void func_003B0720(void);
extern void func_003B0608(s32, s32);
extern void func_11B2E8();
void func_003AFF20(s32 a0) {
    switch (D_001D8A14) {
    case 1:
        if (func_003B42D0() != 0) break;
        switch (func_003B41F0()) {
        case 1: {
            u8 *buf; char *fmt;
            s32 x, y, z;
            D_001D8A1C = D_001D89E0;
            D_001D8A18 = D_001D89E4;
            buf = D_0037B6D0;
            fmt = D_001D8A20;
            x = func_0037DF98(0x511);
            y = func_0037DF98(0x512);
            z = func_0037DF98(0x513);
            func_11B2E8(buf, fmt, x, y, D_001D8A1C, z);
            {
                s32 w = func_0037DF98(0x8E3);
                func_003B4220(0, w, func_0037DF98(0x8DF), buf, 0);
            }
            func_003B41F8(0x20, 0x10);
            D_001D8A14 = 2;
            break;
        }
        case 2:
            D_001D8A14 = 0;
            break;
        }
        break;
    case 2:
        D_001D5520_g_003AFF20 = D_001D5520_003AFF20 == 0;
        func_003B0F58();
        D_001D8A14 = 3;
        break;
    case 3: {
        u8 *buf; char *fmt;
        s32 x, y, z;
        buf = D_0037B6D0;
        fmt = D_001D8A20;
        x = func_0037DF98(0x511);
        y = func_0037DF98(0x512);
        z = func_0037DF98(0x513);
        func_11B2E8(buf, fmt, x, y, D_001D8A1C, z);
        if (func_003B42D0() == 0) {
            switch (func_003B41F0()) {
            case 1:
                D_001D8A14 = 0;
                break;
            case 2:
                D_001D8A14 = 4;
                break;
            }
        } else {
            if (--D_001D8A18 > 0) break;
            if (--D_001D8A1C <= 0) {
                ((s32 (*)(void))func_003B43B0)();
                D_001D8A14 = 4;
            }
            D_001D8A18 = D_001D89E4;
        }
        break;
    }
    case 4:
        D_001D5520_g_003AFF20 = D_001D5520_003AFF20 == 0;
        func_003B0F58();
        D_001D8A14 = 0;
        break;
    case 5: {
        u32 bits;
        if (func_003B42D0() == 0) {
            D_001D8A14 = 0;
            break;
        }
        bits = D_001D52FC_g_003AFF20->f1C0;
        if (bits & 0xF000) {
            s32 dx, dy;
            u32 q;
            if (++D_001D8A2C < 3) break;
            D_001D8A2C = 0;
            if (bits & 0x8000) dx = -2;
            else dx = (bits & 0x2000) ? 2 : 0;
            q = D_001D52FC_003AFF20->f1C0;
            if (q & 0x1000) dy = -1;
            else if (q & 0x4000) dy = 1;
            else dy = 0;
            func_0038CBD0(dx, dy, 1);
        }
        break;
    }
    case 0: {
        s32 b = D_001D52FC_003AFF20->f1C4;
        func_003B5018(func_003B46F0(0), b);
        func_003B0720();
        func_003B0608(a0, b);
        func_003B0A60();
        break;
    }
    }
}
/* localdecomp:end func_003AFF20 */

/* localdecomp:start func_003B0210 */
extern s32 func_003E3040();
extern void func_003B05D8(void);
extern s32 func_0039D6C8(s32);
extern void func_003B43B0(void);
void func_003B0210(void) {
    func_003E3040(0x10);
    func_003E3040(0x11);
    func_003E3040(0x14);
    func_003B05D8();
    func_0039D6C8(1);
    func_003B43B0();
}
/* localdecomp:end func_003B0210 */

/* localdecomp:start func_003B0258 */
void func_003B0258(void) {
    func_0037DCE0();
}
/* localdecomp:end func_003B0258 */

/* localdecomp:start func_003B0278 */
extern s32 func_0037DCE8(void);
extern void func_003B43C0();
 
void func_003B0278(void) {
    func_0037DCE8();
    func_003B43C0();
}
/* localdecomp:end func_003B0278 */

/* localdecomp:start func_003B02A0 */
typedef struct {
    s32 f0; s32 f4; s32 f8; s32 fC; f32 f10; f32 f14; f32 f18; f32 f1C;
    u32 f20; s32 f24; f32 f28; u32 f2C;
} E_3B02A0;
extern void func_003E3EE8();
extern s32 func_003E37F0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003E1E50(s32, f32, f32);
extern s32 func_003E2C88(s32, f32, f32);
extern s32 func_003E3988(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E3BD0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E3D08(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E3B50(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E3DF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E2118(s32, f32);
extern s32 func_003E2028(s32, f32, f32);
extern s32 func_003E22D0(s32, s32, s32);
extern s32 func_003E38D0(s32, s32, s32);
extern s32 func_003E23C0(s32, s32, s32);
extern s32 func_003E30C8(s32, s32);
void func_003B02A0(E_3B02A0 *tbl) {
    s32 i;
    s32 h = 3;
    s32 v = 3;
    for (i = 0; tbl[i].f0 != 0; i++) {
        E_3B02A0 *e = &tbl[i];
        u32 f;
        switch (e->f8) {
        case 0:
            ((s32 (*)())func_003E3EE8)(e->f0);
            if (e->f2C & 1) {
                func_003E37F0(e->f0, 1, 1);
                func_003E1E50(e->f0, e->f10, e->f14);
                func_003E2C88(e->f0, e->f18, e->f1C);
            }
            break;
        case 1:
            func_003E3988(e->f0, e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 0.0f);
            break;
        case 2:
            ((s32 (*)(s32, s32, f32, f32, f32, f32, s32))func_003E3BD0)(e->f0, e->fC, e->f10, e->f14, e->f18, e->f1C, e->f24);
            break;
        case 3:
            func_003E3D08(e->f0, e->fC, e->f10, e->f14, e->f18, e->f1C, e->f28, e->f28);
            break;
        case 4: {
            s32 id;
            if (e->f2C & 4) id = func_0037DF98(e->f24);
            else id = e->f24;
            func_003E3B50(e->f0, id, e->fC, e->f10, e->f14, e->f18, e->f1C, 0.005f, 0.005f);
            break;
        }
        case 5: {
            s32 id;
            if (e->f2C & 4) id = func_0037DF98(e->f24);
            else id = e->f24;
            func_003E3DF0(e->f0, id, e->fC, e->f10, e->f14, e->f18, e->f1C, 1.0f);
            func_003E2118(e->f0, e->f28);
            func_003E2028(e->f0, e->f28 * 0.005f, e->f28 * 0.005f);
            func_003E22D0(e->f0, 0x40, 1);
            if (e->f2C & 8) func_003E38D0(e->f0, 1, 1);
            break;
        }
        }
        f = e->f20;
        if (f != 0) {
            if (f & 1) h = 1;
            else if (f & 2) h = 2;
            if (f & 8) v = 1;
            else if (f & 0x10) v = 2;
            func_003E23C0(e->f0, h, v);
        }
        if (e->f2C & 2) func_003E22D0(e->f0, 1, 0);
        if (e->f4) func_003E30C8(e->f4, e->f0);
    }
}
/* localdecomp:end func_003B02A0 */

/* localdecomp:start func_003B0580 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_3B0580;
extern S_3B0580 D_00160C40[];
extern void *D_001D8A00;
extern void *D_001D8A04;
extern void *func_003AFA90(s32);
extern void *func_003AED40(s32);
extern s32 func_003AEF70(void *, s32, s32, s32, s32);
void func_003B0580(void) {
    D_001D8A00 = func_003AFA90(0);
    D_001D8A04 = func_003AFA90(2);
    func_003AEF70(func_003AED40(0), (s32)D_001D8A00, (s32)D_001D8A04, D_00160C40->f4954, (s32)D_00160C40->f6F30);
}
/* localdecomp:end func_003B0580 */

/* localdecomp:start func_003B05D8 */
extern void *func_003AED40(s32);
 
void func_003B05D8(void) {
    void *o = func_003AED40(0);
    ((void (*)(void *))(*(void ***)((u8 *)o + 0x4))[3])(o);
}
/* localdecomp:end func_003B05D8 */

/* localdecomp:start func_003B0608 */
extern u8 D_0037B870_003B0608[];
extern u8 D_0037B6D0_003B0608[];
extern s32 D_001D89E8_003B0608;
extern s32 D_001D8A14_003B0608;
extern void func_0039FF28();
extern s32 func_0037DF98();
extern void func_0011B2E8();
extern s32 func_003B4220();
extern void func_003B41F8();
extern s32 func_003E2E60();
extern void *func_003AFA18();
extern s32 func_003AFC10(void);
extern void func_003E1AA8(void *p);
__asm__(".extern D_001D89E8_003B0608, 4");
__asm__(".extern D_001D8A14_003B0608, 4");
void func_003B0608(s32 a0, s32 a1) {
    s32 t;
    s32 u;
    u8 *g;
    if (a1 & 0x40) {
        func_0039FF28(4, 0, 0);
        g = D_0037B870_003B0608;
        t = D_001D89E8_003B0608 * 16;
        if (((s32 *)(D_0037B870_003B0608 + t))[2] != 0) {
            ((void (*)(s32, u8 *))((s32 *)(g + t))[2])(t, g);
        }
    } else if (a1 & 8) {
        func_0011B2E8(D_0037B6D0_003B0608, func_0037DF98(0xB3B));
 u = func_0037DF98(0x8DE);
 func_003B4220(1, u, func_0037DF98(0x8DF), D_0037B6D0_003B0608, 0);
        func_003B41F8(0x40, 0x10);
        D_001D8A14_003B0608 = 5;
    }
    if (a1 & 0x10) {
        func_0039FF28(4, 0, 0);
        func_003E2E60(func_003AFA18());
        func_003E1AA8((void *)func_003AFC10());
    }
}
/* localdecomp:end func_003B0608 */

/* localdecomp:start func_003B0720 */
typedef struct { s32 a, b, c, d; } E_37B870;
extern E_37B870 D_0037B870[];
extern s32 D_001D89E8;
extern s32 D_001D89EC;
extern s32 D_001D8A30;
extern s32 *func_003B46F0(s32);
extern s32 func_003B4778(s32 *);
extern s32 func_003E28E0(s32, s32);
extern s32 func_003E24B0(s32 arg0, s32 arg1);
void func_003B0720(void) {
    s32 v = func_003B4778(func_003B46F0(0));
    D_001D89E8 = v;
    if (v < 0) return;
    if (D_001D89EC != v) {
        if (D_001D89EC >= 0) D_001D8A30 = 30;
        else D_001D8A30 = 1;
    }
    if (D_001D8A30 != 0) {
        if (--D_001D8A30 == 0) {
            func_003E28E0(0x1C0003, D_0037B870[D_001D89E8].d);
            func_003E24B0(0x1C0003, 1);
        }
    }
    D_001D89EC = D_001D89E8;
}
/* localdecomp:end func_003B0720 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B07B8);

INCLUDE_ASM("asm/nonmatchings/text", func_003B0A60);

/* localdecomp:start func_003B0C40 */
extern s32 D_00143950_b[];
extern void func_003830E8();
 
void func_003B0C40(void) {
    u8 *b = (u8 *)D_00143950_b;
    b[0xAD] = b[0xAD] == 0;
    func_003830E8();
}
/* localdecomp:end func_003B0C40 */

/* localdecomp:start func_003B0C70 */
__asm__(".extern D_001D89E0, 4");
__asm__(".extern D_001D8A14, 4");
extern s32 D_001D5520_003B0C70;
extern s32 D_001D89E0;
extern s32 D_001D8A14;
extern u8 D_0037B6D0[];
extern s32 func_0037DF98();
extern void func_11B2E8();
extern void func_003B0F58(void);
extern s32 func_003B4220();
extern void func_003B41F8();
void func_003B0C70(void) {
    s32 x;
    s32 v = D_001D5520_003B0C70;
    s32 y;
    u8 *s;
    if (v != 0) {
        D_001D5520_003B0C70 = v == 0;
        func_003B0F58();
    } else {
        s = D_0037B6D0;
        func_11B2E8(s, func_0037DF98(0x50A), D_001D89E0);
        x = func_0037DF98(0x8E2);
        y = func_0037DF98(0x8DF);
        func_003B4220(0, x, y, s, 0);
        func_003B41F8(0x40, 0x10);
        D_001D8A14 = 1;
    }
}
/* localdecomp:end func_003B0C70 */

/* localdecomp:start func_003B0D18 */
extern s32 D_00143950_b[];
extern void func_003B0DA0(void);
void func_003B0D18(void) {
    u8 *b = (u8 *)D_00143950_b;
    u8 s = b[0xB7];
    if (s == 0) b[0xB7] = 2;
    else if (s == 2) b[0xB7] = 4;
    else if (s == 4) b[0xB7] = 0;
    func_003B0DA0();
}
/* localdecomp:end func_003B0D18 */

/* localdecomp:start func_003B0D70 */
extern u8 D_00143950[];
s32 func_003B0D70(void) {
    u8 *p = &D_00143950[0];
    s32 v = p[6] == 0;
    p[6] = v;
    return v;
}
/* localdecomp:end func_003B0D70 */

/* localdecomp:start func_003B0D88 */
extern s32 D_00143950_b[];

s32 func_003B0D88(void) {
    s32 inverted_val = !D_00143950_b[2];
    D_00143950_b[2] = inverted_val;
    return inverted_val;
}
/* localdecomp:end func_003B0D88 */

/* localdecomp:start func_003B0DA0 */
typedef struct { u8 p0[0x18]; u8 *f18; } O_3B0DA0;
typedef struct { u8 p0[0x2C]; s32 f2C; } Z_3B0DA0;
extern O_3B0DA0 D_00227600;
extern u8 D_00143A07[];
extern Z_3B0DA0 D_00318CC0;
extern s32 *D_001D9A20;
extern void func_0039B760();
extern s32 func_0037DF98();
extern void func_003E2728_003B0DA0();
extern void func_003B5A70();
extern void func_003E2C88_003B0DA0(s32, f32, f32);
extern void func_003E21F8_003B0DA0(s32, f32);
void func_003B0DA0(void)
{
  u8 *base;
  s32 off;
  s32 *q;
  s32 *p;
  s32 i;
  f32 v[2];
  int new_var2;
  f32 z;
  f32 new_var;
  f32 new_var3;
  f32 w;
  off = 0;
  base = D_00227600.f18 + 0x400000;
  switch (D_00143A07[0])
  {
    case 0:

    case 1:
      off = ((s32) base) + (*((s32 *) (base + 0)));
      break;

    case 2:
      off = ((s32) base) + (*((s32 *) (base + 8)));
      break;

    case 3:
      off = ((s32) base) + (*((s32 *) (base + 0x10)));
      break;

    case 4:
      off = ((s32) base) + (*((s32 *) (base + 0x18)));
      break;

    case 5:
      off = ((s32) base) + (*((s32 *) (base + 0x20)));
      break;

  }

  func_0039B760(off, D_00227600.f18);
  q = (s32 *) D_00227600.f18;
  D_00318CC0.f2C = ((u32) q[0]) >> 4;
  D_001D9A20 = q;
  p = q;
  new_var2 = 0;
  for (i = 0; i < D_00318CC0.f2C; i++)
  {
    p[new_var2] = p[new_var2] + ((s32) q);
    p += 4;
  }

  w = 1.2f;
  z = 0.0f;
  v[0] = w;
  v[1] = z;
  func_003E2728_003B0DA0(0xD0005, func_0037DF98(0x107));
  func_003E2728_003B0DA0(0xD0006, func_0037DF98(0xFF));
  func_003E2728_003B0DA0(0xD0007, func_0037DF98(0xCD5));
  func_003B5A70(0x107, v, &v[1]);
  func_003E2C88_003B0DA0(0xD0005, v[0], v[0]);
  func_003E21F8_003B0DA0(0xD0002, v[1]);
  new_var3 = v[1];
  func_003E21F8_003B0DA0(0xD0003, new_var3);
  func_003E21F8_003B0DA0(0xD0000, v[1]);
  func_003E21F8_003B0DA0(0xD0001, new_var = v[1]);
}
/* localdecomp:end func_003B0DA0 */

/* localdecomp:start func_003B0F58 */
extern void func_003A3DA0(s32);
extern void func_0038CAF0(void);
extern s32 D_001D5520[];
extern void func_0038CE40(s32, s32, s32, s32, s32, s32);
void func_003B0F58(void) {
    func_003A3DA0(1);
    func_0038CAF0();
    if (D_001D5520[0] != 0) {
        func_0038CE40(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        func_0038CE40(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
}
/* localdecomp:end func_003B0F58 */

/* localdecomp:start func_003B0FC8 */
/* First C switch: its jump table comes from gcc now (tools/migrate_jtbls.py). */
extern u8 D_00143A07[];
s32 func_003B0FC8(void) {
    switch (D_00143A07[0]) {
    case 2: return 0x151;
    case 3: return 0x153;
    case 4: return 0x152;
    case 5: return 0x154;
    case 6: case 7: return 0x150;
    case 0: case 1: default: return 0x150;
    }
}
/* localdecomp:end func_003B0FC8 */

/* localdecomp:start func_003B1028 */
extern s32 D_001D8A48;
void func_003B1028(s32 a) { D_001D8A48 = a; }
/* localdecomp:end func_003B1028 */

/* localdecomp:start func_003B1030 */
extern s32 func_00397258(void);
extern void func_0013D3C0(s32);
extern s32 D_001D8A70_g;
void func_003B1030(void) {
    if (func_00397258()) D_001D8A70_g = 5;
    else func_0013D3C0(1);
}
/* localdecomp:end func_003B1030 */
