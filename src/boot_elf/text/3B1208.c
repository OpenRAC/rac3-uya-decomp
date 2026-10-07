#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003B1520();
extern s32 func_003B2690(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003B29E0();
extern s32 func_003B1538();
extern s32 func_003B2800();
extern s32 func_003B1630();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B1208 */
typedef struct { u8 p0[8]; s32 f8; s32 fC; unsigned long f10; unsigned long f18; } O_ABA48;
extern s32 D_001DA134_003B1208;
extern u8 D_001D87C8[];
extern s32 func_003B27B8_003B1208();
extern s32 func_003B2860_003B1208();
extern s32 func_003B0258();
extern s32 func_003B27D8_003B1208();
extern s32 func_003B13F0();
s32 func_003B1208(s32 unused, O_ABA48 *obj, u8 *buf) {
    s32 v[4];
    s32 t, p, q, w, q2, n;
    t = *(s32 *)(buf + 0x50008);
    p = obj->f8;
    q = obj->fC;
    w = (s32)buf + t - p;
    w = (q < w) ? q : w;
    q2 = q - w;
    func_003B27B8_003B1208(D_001DA134_003B1208, &v[0], &v[1], &v[2], &v[3]);
    n = func_003B13F0((v[0] & 0xFFFFFFF) | 0x20000000, v[1], (v[2] & 0xFFFFFFF) | 0x20000000, v[3], p, w, buf, q2);
    if (n > 0) {
        if (func_003B2860_003B1208(D_001DA134_003B1208, obj->f10, obj->f18, v[0], n) == 0) {
            func_003B0258(D_001D87C8);
        }
    }
    func_003B27D8_003B1208(D_001DA134_003B1208, n);
    return n > 0;
}
/* localdecomp:end func_003B1208 */

/* localdecomp:start func_003B1320 */
typedef struct { u8 p0[8]; u32 f8; s32 fC; } O_ABB60;
extern s32 D_001DA138;
extern s32 func_003B13F0();
s32 func_003B1320(s32 unused, O_ABB60 *obj, u8 *buf) {
    s32 v[4];
    s32 a0, a1, a2, a3;
    s32 t, q, q2, w, res;
    u32 p, end;
    t = *(s32 *)(buf + 0x50008);
    p = obj->f8 + 4;
    end = (u32)buf + t;
    p = (p >= end) ? p - t : p;
    q = obj->fC - 4;
    w = end - p;
    w = (q < w) ? q : w;
    q2 = q - w;
    func_003B0430(D_001DA138, v, &v[1], &v[2], &v[3]);
    a1 = v[1];
    a0 = v[0];
    a2 = v[2];
    a3 = v[3];
    res = func_003B13F0(a0, a1, a2, a3, p, w, buf, q2);
    func_003B0500(D_001DA138, res);
    return res > 0;
}
/* localdecomp:end func_003B1320 */

/* localdecomp:start func_003B13F0 */
extern void func_11A0B0();
s32 func_003B13F0(u8 *a, s32 sz, u8 *b, s32 off, u8 *src1, s32 len1, u8 *src2, s32 len2) {
    s32 d;
    if (sz + off < len1 + len2) return 0;
    if (len1 >= sz) {
        d = sz - len1;
        func_11A0B0(a, src1, sz);
        func_11A0B0(b, src1 + sz, len1 - sz);
        func_11A0B0(b + len1 - sz, src2, len2);
    } else {
        d = sz - len1;
        if (len2 >= d) {
            func_11A0B0(a, src1, len1);
            func_11A0B0(a + len1, src2, d);
            func_11A0B0(b, src2 + sz - len1, len2 - d);
        } else {
            func_11A0B0(a, src1, len1);
            func_11A0B0(a + len1, src2, len2);
        }
    }
    return len1 + len2;
}
/* localdecomp:end func_003B13F0 */

/* localdecomp:start func_003B1520 */
void func_003B1520(void *a0) {
    u8 *p = (u8 *)a0 + 0x50000;
    *(s32 *)(p + 8) = 0x50000;
    *(s32 *)(p + 0) = 0;
    *(s32 *)(p + 4) = 0;
}
/* localdecomp:end func_003B1520 */

/* localdecomp:start func_003B1538 */
s32 func_003B1538(void) {
}
/* localdecomp:end func_003B1538 */

/* localdecomp:start func_003B1540 */
s32 func_003B1540(u8 *p, void **out) {
    u8 *q = p + 0x50000;
    s32 n = *(s32 *)(q + 8) - *(s32 *)(q + 4);
    if (n != 0) {
        *out = p + *(s32 *)q;
    }
    return n;
}
/* localdecomp:end func_003B1540 */

/* localdecomp:start func_003B1570 */
typedef struct { s32 a, b, c; } R_3ABDB0;
void func_003B1570(u8 *p, s32 n) {
    R_3ABDB0 *r = (R_3ABDB0 *)(p + 0x50000);
    s32 m = r->c - r->b;
    if (n < m) m = n;
    r->b += m;
    r->a = (r->a + m) % r->c;
}
/* localdecomp:end func_003B1570 */

/* localdecomp:start func_003B15B0 */
typedef struct { s32 a, b, c; } R_3ABDF0;
s32 func_003B15B0(u8 *p, u8 **out) {
    R_3ABDF0 *r = (R_3ABDF0 *)(p + 0x50000);
    if (r->b != 0) *out = p + (r->a - r->b + r->c) % r->c;
    return r->b;
}
/* localdecomp:end func_003B15B0 */

/* localdecomp:start func_003B15F0 */
typedef struct { u8 pad[0x50004]; s32 x; } S_3ABE30;
s32 func_003B15F0(S_3ABE30 *a, s32 n) {
    s32 m = a->x;
    if (n < m) m = n;
    a->x -= m;
    return m;
}
/* localdecomp:end func_003B15F0 */

/* localdecomp:start func_003B1618 */
extern s32 D_001D87E0;
s32 func_003B1618(s32 *p, s32 b, s32 c) { D_001D87E0 = 0; p[2] = b; p[0] = c; return 1; }
/* localdecomp:end func_003B1618 */

/* localdecomp:start func_003B1630 */
extern s32 func_13CEB0();
extern void func_13CDF0(s32);
 
s32 func_003B1630(void) {
    func_13CEB0();
    func_13CDF0(0);
    return 1;
}
/* localdecomp:end func_003B1630 */

/* localdecomp:start func_003B1658 */
__asm__(".extern D_001D87E0, 4");
extern s32 D_001D87E0;
typedef struct { u8 p0[8]; s32 f8; } P_3ABE98;
extern char D_001D87E8[];
extern char D_001D8800[];
extern void func_11F0A0();
extern s32 func_12BC00();
extern void func_11AF48();
extern s32 func_13CD28();
s32 func_003B1658(P_3ABE98 *p, s32 b, s32 c) {
    s32 r;
    u8 buf[3];
    r = 0;
    if (D_001D87E0 != 0) {
        func_11F0A0(2);
        if (((s32 (*)(s32))func_13CDF0)(1) == 0) {
            D_001D87E0 = 0;
            if (func_12BC00() == 0) {
                r = (c >> 11) << 11;
                p->f8 = p->f8 + (c >> 11);
            } else {
                func_11AF48(D_001D87E8);
            }
        }
    } else {
        buf[0] = 100;
        buf[1] = 0;
        buf[2] = 0;
        func_13CDF0(0);
        if (func_13CD28(p->f8, c >> 11, b, buf) != 0) {
            D_001D87E0 = 1;
        } else {
            func_11AF48(D_001D8800);
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_003B1658 */

/* localdecomp:start func_003B1748 */
typedef struct { s32 f0; s32 f4; s32 f8; } S_ABF88;
s32 func_003B1748(S_ABF88 *p, s32 a1) {
    s32 t = p->f8 * 0x10 + 0x10;
    s32 addr = (p->f4 + t) & 0xFFFFFFF;
    if (a1 == addr) {
        return 0;
    }
    return (u32)(a1 - p->f0) >> 11;
}
/* localdecomp:end func_003B1748 */

/* localdecomp:start func_003B1790 */
extern void func_124920(void);
extern void func_124970(void);
void func_003B1790(s32 a) {
    func_124920();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = a;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    func_124970();
}
/* localdecomp:end func_003B1790 */

/* localdecomp:start func_003B1800 */
extern void func_124920(void);
extern void func_124970(void);
void func_003B1800(s32 a) {
    func_124920();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B400 = a;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    func_124970();
}
/* localdecomp:end func_003B1800 */

/* localdecomp:start func_003B1870 */
void func_003B1870(unsigned long *p, unsigned long a, unsigned long b, unsigned long c) {
    *p = (a << 32) | ((b << 32) >> 4) | ((c << 32) >> 32);
}
/* localdecomp:end func_003B1870 */

/* localdecomp:start func_003B1898 */
typedef struct { s32 f0; s32 f4; s32 f8; u8 pC[0xC]; s32 f18; u8 p1C[0x24]; s32 f40; u8 p44[4]; long f48; s32 f50; s32 f54; } O_3AC0D8;
typedef struct { s32 w0; s32 w4; s32 w8; s32 pad[5]; } St_3AC0D8;
extern s32 func_11EE20();
extern s32 func_003B1910();
s32 func_003B1898(O_3AC0D8 *o, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{  St_3AC0D8 *new_var;
  St_3AC0D8 st;
  o->f0 = a1;
  o->f8 = a3;
  o->f50 = a4;
  o->f54 = a5;
  st.w8 = 1;
  o->f4 = (a2 & 0xFFFFFFF) | 0x20000000;
  st.w4 = 1;
  new_var = &st;
  o->f18 = a3 << 11;
  o->f40 = func_11EE20(new_var);
  ((s32 (*)(void *))func_003B1910)(o);
  o->f48 = 0;
  return 1;
}
/* localdecomp:end func_003B1898 */

/* localdecomp:start func_003B1910 */
extern void func_003B1870_003B1910();
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; u8 p18[0x2C]; s32 f44; u8 p48[8]; s32 f50; s32 f54; s32 f58; s32 f5C; } O_3AC150;
s32 func_003B1910(O_3AC150 *o) {
    s32 i = 0;
    o->f44 = 1;
    o->fC = 0;
    o->f10 = 0;
    o->f14 = 0;
    o->f58 = 0;
    o->f5C = 0;
    if (o->f54 > 0) {
        long m = -1;
        s32 off = 0;
        do {
            i++;
            *(long *)(off + o->f50) = m;
            *(long *)(off + o->f50 + 8) = m;
            *(s32 *)(off + o->f50 + 0x10) = 0;
            *(s32 *)(off + o->f50 + 0x14) = 0;
            off += 0x18;
        } while (i < o->f54);
    }
    i = 0;
    while (i < o->f8) {
        func_003B1870_003B1910((unsigned long *)(o->f4 + i * 16), (o->f0 + i * 0x800) & 0xFFFFFFF, 3, 0x80);
        i++;
    }
    func_003B1870_003B1910((unsigned long *)(o->f4 + i * 16), o->f4 & 0xFFFFFFF, 2, 0);
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000B410 = o->f0 & 0xFFFFFFF;
    *(volatile u32 *)0x1000B430 = o->f4 & 0xFFFFFFF;
    func_003B1800(5);
    return 1;
}
/* localdecomp:end func_003B1910 */

/* localdecomp:start func_003B1A70 */
extern void func_0011EE40(s32);
extern void func_0011EE60(s32);
void func_003B1A70(arg0, arg1, arg2, arg3, arg4)
    void *arg0;
    s32 *arg1;
    s32 *arg2;
    s32 *arg3;
    s32 *arg4;
{
  s32 temp_2;
  s32 temp_3;
  s32 temp_4;
  s32 temp_5;
  s32 temp_5_2;
  s32 temp_6;
  s32 temp_hi;
  func_0011EE60(*((s32 *) (((u8 *) arg0) + 0x40)));
  temp_4 = *((s32 *) (((u8 *) arg0) + 0x10));
  temp_5 = *((s32 *) (((u8 *) arg0) + 0x14));
  temp_6 = temp_4 + 2;
  temp_3 = *((s32 *) (((u8 *) arg0) + 0x18));
  temp_hi = ((s32) ((((*((s32 *) (((u8 *) arg0) + 0xC))) + temp_4) << 0xB) + temp_5)) % temp_3;
  temp_5_2 = (((*((s32 *) (((u8 *) arg0) + 8))) - temp_6) << 0xB) - temp_5;
  ;
  if ((temp_3 - temp_hi) >= temp_5_2)
  {
    *arg1 = (*((s32 *) (((u8 *) arg0) + 0))) + temp_hi;
    *arg2 = temp_5_2;
    *arg3 = 0;
    *arg4 = 0;
  }
  else
  {
    *arg1 = (*((s32 *) (((u8 *) arg0) + 0))) + temp_hi;
    *arg2 = (*((s32 *) (((u8 *) arg0) + 0x18))) - temp_hi;
    *arg3 = *((s32 *) (arg0 + 0));
    *arg4 = temp_5_2 - ((*((s32 *) (((u8 *) arg0) + 0x18))) - temp_hi);
  }
  temp_4 = temp_6;
  ((void (*)(s32, s32, s32, s32)) func_0011EE40)(*((s32 *) (((u8 *) arg0) + 0x40)), temp_5_2, temp_4, temp_hi);
}
/* localdecomp:end func_003B1A70 */

/* localdecomp:start func_003B1B60 */
typedef struct { u8 pad[0x14]; s32 w14; u8 pad2[0x28]; s32 w40; u8 pad3[4]; unsigned long d48; } S_AC3A0;
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
void func_003B1B60(p, n) S_AC3A0 *p; s32 n; {  /* K&R: older callers use unprototyped calls */
    func_11EE60(p->w40);
    p->w14 += n;
    p->d48 = n + p->d48;
    func_11EE40(p->w40);
}
/* localdecomp:end func_003B1B60 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B1BB8);

/* localdecomp:start func_003B1DA0 */
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
extern void func_003B1800(s32);
extern void func_003B1790(s32);
s32 func_003B1DA0(s32 *p) {
    func_11EE60(p[0x10]);
    p[0x11] = 0;
    func_003B1800(5);
    p[7] = *(volatile s32 *)0x1000B410;
    p[8] = *(volatile s32 *)0x1000B430;
    p[9] = *(volatile s32 *)0x1000B420;
    p[10] = *(volatile s32 *)0x1000B400;
    if (*(volatile s32 *)0x10002010 & 0xF0) { do {} while (*(volatile s32 *)0x10002010 & 0xF0); }
    func_003B1790(0);
    p[11] = *(volatile s32 *)0x1000B010;
    p[12] = *(volatile s32 *)0x1000B020;
    p[13] = *(volatile s32 *)0x1000B000;
    p[14] = *(volatile s32 *)0x10002020;
    p[15] = *(volatile s32 *)0x10002010;
    func_11EE40(p[0x10]);
    return 1;
}
/* localdecomp:end func_003B1DA0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B1EB0);

/* localdecomp:start func_003B21C0 */
extern void func_003B1800(s32);
extern void func_11EE30(s32);
s32 func_003B21C0(u8 *p) {
    func_003B1800(5);
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000B410 = 0;
    *(volatile u32 *)0x1000B430 = 0;
    func_11EE30(*(s32 *)(p + 0x40));
    return 1;
}
/* localdecomp:end func_003B21C0 */

/* localdecomp:start func_003B2218 */
extern void func_0011EE60(s32);
extern void func_0011EE40(s32);
s32 func_003B2218(u8 *p) {
    s32 r;
    func_0011EE60(*(s32 *)(p + 0x40));
    r = (*(s32 *)(p + 0x10) << 11) + *(s32 *)(p + 0x14);
    func_0011EE40(*(s32 *)(p + 0x40));
    return r;
}
/* localdecomp:end func_003B2218 */

/* localdecomp:start func_003B2268 */
typedef struct { u8 pad[0x14]; s32 w14; u8 pad2[0x28]; s32 w40; } S_ACAA8;
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
void func_003B2268(S_ACAA8 *p) {
    func_11EE60(p->w40);
    p->w14 = (p->w14 + 0x7FF) / 0x800 * 0x800;
    func_11EE40(p->w40);
}
/* localdecomp:end func_003B2268 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B22C0);

/* localdecomp:start func_003B23F0 */
typedef struct { long f0; long f8; s32 f10; s32 f14; } S_CCb;
typedef struct { u8 p0[0x40]; s32 f40; u8 p44[0xC]; S_CCb *f50; s32 f54; s32 f58; s32 f5C; } S_CCa;
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
extern void func_003B22C0();
s32 func_003B23F0(S_CCa *a, S_CCb *b) {
    s32 r = 0;
    func_11EE60(a->f40);
    if (a->f58 < a->f54) {
        func_003B22C0(a, b);
        if (b->f0 >= 0 || b->f8 >= 0) {
        a->f50[a->f5C].f0 = b->f0;
        a->f50[a->f5C].f8 = b->f8;
        a->f50[a->f5C].f10 = b->f10;
        a->f50[a->f5C].f14 = b->f14;
        a->f58 = a->f58 + 1;
        a->f5C = (a->f5C + 1) % a->f54;
        }
        r = 1;
    }
    func_11EE40(a->f40);
    return r;
}
/* localdecomp:end func_003B23F0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B24F8);

/* localdecomp:start func_003B2690 */
extern void func_003B27F8(void *);
extern s32 func_003B2BF0();
extern s32 func_003B2C18();
extern s32 func_003B2C48();
extern s32 func_003B2C70();
extern s32 func_003B2C98();
extern void func_003B1898_003B2690(s32, s32, s32, s32, s32, s32);
extern void func_001350A8(void);
extern void func_00135D08(s32, s32, void *, s32);
s32 func_003B2690(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    func_001350A8();
    func_00135D08(arg0, 0, &func_003B2BF0, 0);
    func_00135D08(arg0, 1, &func_003B2C18, 0);
    func_00135D08(arg0, 2, &func_003B2C48, 0);
    func_00135D08(arg0, 3, &func_003B2C70, 0);
    func_00135D08(arg0, 5, &func_003B2C98, 0);
    func_003B27F8((void *)arg0);
    func_003B1898_003B2690(arg0 + 0x48, arg3, arg4, arg5, arg6, arg7);
    return 1;
}
/* localdecomp:end func_003B2690 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B2790);

/* localdecomp:start func_003B2798 */
extern void func_139E50();
 
s32 func_003B2798(void) {
    func_139E50();
    return 1;
}
/* localdecomp:end func_003B2798 */

/* localdecomp:start func_003B27B8 */
s32 func_003B27B8(s32 arg0) {
    func_003B1A70(arg0 + 0x48);
}
/* localdecomp:end func_003B27B8 */

/* localdecomp:start func_003B27D8 */
s32 func_003B27D8(s32 arg0) {
    func_003B1B60(arg0 + 0x48);
}
/* localdecomp:end func_003B27D8 */

/* localdecomp:start func_003B27F8 */
void func_003B27F8(void *p) {
    *(s32 *)((u8 *)p + 0xA8) = 0;
}
/* localdecomp:end func_003B27F8 */

/* localdecomp:start func_003B2800 */
extern void func_00135C00(u8 *);
s32 func_003B2800(u8 *p) {
    func_003B21C0(p + 0x48);
    func_00135C00(p);
    return 1;
}
/* localdecomp:end func_003B2800 */

/* localdecomp:start func_003B2838 */
void func_003B2838(void *a0) {
    *(s32 *)((u8 *)a0 + 168) = 1;
}
/* localdecomp:end func_003B2838 */

/* localdecomp:start func_003B2848 */
s32 func_003B2848(void *p) {
    return *(s32 *)((u8 *)p + 0xA8);
}
/* localdecomp:end func_003B2848 */

/* localdecomp:start func_003B2850 */
s32 func_003B2850(void *a0, s32 a1) {
    s32 old = *(s32 *)((u8 *)a0 + 168);
    *(s32 *)((u8 *)a0 + 168) = a1;
    return old;
}
/* localdecomp:end func_003B2850 */

/* localdecomp:start func_003B2860 */
typedef struct { unsigned long a, b; s32 c, d; } S_3AD0A0;
extern u8 *D_001DA134[];
extern void func_003B23F0(u8 *, S_3AD0A0 *);
void func_003B2860(u8 *p, unsigned long a, unsigned long b, s32 c, s32 d) {
    S_3AD0A0 s;
    s.a = a;
    s.b = b;
    s.c = c - *(s32 *)(p + 0x48);
    s.d = d;
    func_003B23F0(D_001DA134[0] + 0x48, &s);
}
/* localdecomp:end func_003B2860 */

/* localdecomp:start func_003B28A0 */
s32 func_003B28A0(s32 arg0) {
    func_003B2218(arg0 + 0x48);
}
/* localdecomp:end func_003B28A0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B28C0);

/* localdecomp:start func_003B28C8 */
typedef struct { char c[4]; } S4_3AD108;
typedef struct { u8 p0[0x48]; u8 p48[0x60]; s32 fA8; } S_3AD108;
extern S4_3AD108 D_001D8830[];
extern s32 D_001DA134_003B28C8;
extern void func_003B27B8();
extern s32 func_003B2CE0();
extern void func_003B27D8();
extern void func_003B2268();
s32 func_003B28C8(S_3AD108 *a) {
    S4_3AD108 buf;
    s32 r0;
    s32 r1;
    s32 r2;
    s32 r3;
    s32 v;
    buf = D_001D8830[0];
    func_003B27B8(a, &r0, &r1, &r2, &r3);
    if (r1 + r3 < 4) return 0;
    v = func_003B2CE0((r0 & 0xFFFFFFF) | 0x20000000, r1, (r2 & 0xFFFFFFF) | 0x20000000, r3, &buf, 4, 0, 0);
    func_003B27D8(D_001DA134_003B28C8, v);
    func_003B2268((u8 *)a + 0x48);
    if (a->fA8 == 0) {
        a->fA8 = 2;
    }
    return 1;
}
/* localdecomp:end func_003B28C8 */

/* localdecomp:start func_003B2998 */
extern s32 func_00135CF0(void *);
s32 func_003B2998(void *p) {
    s32 r = 0;
    if (func_003B28A0(p) == 0) r = func_00135CF0(p) != 0;
    return r;
}
/* localdecomp:end func_003B2998 */

/* localdecomp:start func_003B29E0 */
extern s32 func_003B2850();
extern void func_003B2E70();
extern s32 func_003B1910();
extern s32 func_003B2A48();
extern s32 D_001DA108;
extern s32 *D_001DA108_003B29E0[];
void func_003B29E0(s32 arg0) {
    volatile s32 *p;
    s32 x;
    func_003B1910(arg0 + 0x48);
    func_003B2E70(D_001DA108);
    func_003B2A48(arg0);
    p = (volatile s32 *)D_001DA108_003B29E0[0];
    do { x = p[3]; __asm__ volatile("nop
	nop
	nop
	nop"); } while (x != 0);
    func_003B2850(arg0, 3);
}
/* localdecomp:end func_003B29E0 */

/* localdecomp:start func_003B2A48 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; } S_3AD288;
__asm__(".extern D_001DA108_003B2A48, 16");
extern S_3AD288 *D_001DA108_003B2A48;
extern u8 D_001D8850[];
extern u8 D_001D8838[];
extern s32 func_003B2F08();
extern void func_003AFFA0();
extern s32 func_135C10();
extern s32 func_135CE0();
extern void func_135C60();
extern void func_003B2E98();
extern void func_003B0DD0();
extern s32 func_003B2848();
extern void func_11AF48();
extern s32 func_003B0258();
s32 func_003B2A48(s32 *a) {
    s32 ret = 1;
    s32 v, h, w, hh;
    while (func_135CE0(a) == 0) {
        if (func_003B2848(a) == 1) {
            ret = -1;
            func_11AF48(D_001D8838);
            break;
        }
        while ((v = func_003B2F08(D_001DA108)) == 0) {
            func_003AFFA0();
        }
        if (func_135C10(a, v, 0x340) < 0) {
            func_003B0258(D_001D8850);
        }
        if (a[2] == 0) {
            S_3AD288 *p;
            hh = a[0];
            w = a[1];
            h = 0;
            p = (S_3AD288 *)D_001DA108;
            if (h < p->x10) {
                do {
                    func_003B0DD0(p->x4 + h * 0x27E40 + 0x40, p->x0 + h * 0xD0000, 0, hh, w);
                    func_003B0DD0(D_001DA108_003B2A48->x4 + h * 0x27E40 + 0x13F40, D_001DA108_003B2A48->x0 + h * 0xD0000, 1, hh, w);
                    h++;
                    p = D_001DA108_003B2A48;
                } while (h < p->x10);
            }
        }
        func_003B2E98(D_001DA108);
        func_003AFFA0();
    }
    func_135C60(a);
    return ret;
}
/* localdecomp:end func_003B2A48 */
