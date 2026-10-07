#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003ABD60();
extern s32 func_003ACED0(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003AD220();
extern s32 func_003ABD78();
extern s32 func_003AD040();
extern s32 func_003ABE70();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003ABA48 */
typedef struct { u8 p0[8]; s32 f8; s32 fC; unsigned long f10; unsigned long f18; } O_ABA48;
extern s32 D_001DA134_003ABA48;
extern u8 D_001D87C8[];
extern s32 func_003ACFF8_003ABA48();
extern s32 func_003AD0A0_003ABA48();
extern s32 func_003AAA98();
extern s32 func_003AD018_003ABA48();
extern s32 func_003ABC30();
s32 func_003ABA48(s32 unused, O_ABA48 *obj, u8 *buf) {
    s32 v[4];
    s32 t, p, q, w, q2, n;
    t = *(s32 *)(buf + 0x50008);
    p = obj->f8;
    q = obj->fC;
    w = (s32)buf + t - p;
    w = (q < w) ? q : w;
    q2 = q - w;
    func_003ACFF8_003ABA48(D_001DA134_003ABA48, &v[0], &v[1], &v[2], &v[3]);
    n = func_003ABC30((v[0] & 0xFFFFFFF) | 0x20000000, v[1], (v[2] & 0xFFFFFFF) | 0x20000000, v[3], p, w, buf, q2);
    if (n > 0) {
        if (func_003AD0A0_003ABA48(D_001DA134_003ABA48, obj->f10, obj->f18, v[0], n) == 0) {
            func_003AAA98(D_001D87C8);
        }
    }
    func_003AD018_003ABA48(D_001DA134_003ABA48, n);
    return n > 0;
}
/* localdecomp:end func_003ABA48 */

/* localdecomp:start func_003ABB60 */
typedef struct { u8 p0[8]; u32 f8; s32 fC; } O_ABB60;
extern s32 D_001DA138;
extern s32 func_003ABC30();
s32 func_003ABB60(s32 unused, O_ABB60 *obj, u8 *buf) {
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
    func_003AAC70(D_001DA138, v, &v[1], &v[2], &v[3]);
    a1 = v[1];
    a0 = v[0];
    a2 = v[2];
    a3 = v[3];
    res = func_003ABC30(a0, a1, a2, a3, p, w, buf, q2);
    func_003AAD40(D_001DA138, res);
    return res > 0;
}
/* localdecomp:end func_003ABB60 */

/* localdecomp:start func_003ABC30 */
extern void func_11A0B0();
s32 func_003ABC30(u8 *a, s32 sz, u8 *b, s32 off, u8 *src1, s32 len1, u8 *src2, s32 len2) {
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
/* localdecomp:end func_003ABC30 */

/* localdecomp:start func_003ABD60 */
void func_003ABD60(void *a0) {
    u8 *p = (u8 *)a0 + 0x50000;
    *(s32 *)(p + 8) = 0x50000;
    *(s32 *)(p + 0) = 0;
    *(s32 *)(p + 4) = 0;
}
/* localdecomp:end func_003ABD60 */

/* localdecomp:start func_003ABD78 */
s32 func_003ABD78(void) {
}
/* localdecomp:end func_003ABD78 */

/* localdecomp:start func_003ABD80 */
s32 func_003ABD80(u8 *p, void **out) {
    u8 *q = p + 0x50000;
    s32 n = *(s32 *)(q + 8) - *(s32 *)(q + 4);
    if (n != 0) {
        *out = p + *(s32 *)q;
    }
    return n;
}
/* localdecomp:end func_003ABD80 */

/* localdecomp:start func_003ABDB0 */
typedef struct { s32 a, b, c; } R_3ABDB0;
void func_003ABDB0(u8 *p, s32 n) {
    R_3ABDB0 *r = (R_3ABDB0 *)(p + 0x50000);
    s32 m = r->c - r->b;
    if (n < m) m = n;
    r->b += m;
    r->a = (r->a + m) % r->c;
}
/* localdecomp:end func_003ABDB0 */

/* localdecomp:start func_003ABDF0 */
typedef struct { s32 a, b, c; } R_3ABDF0;
s32 func_003ABDF0(u8 *p, u8 **out) {
    R_3ABDF0 *r = (R_3ABDF0 *)(p + 0x50000);
    if (r->b != 0) *out = p + (r->a - r->b + r->c) % r->c;
    return r->b;
}
/* localdecomp:end func_003ABDF0 */

/* localdecomp:start func_003ABE30 */
typedef struct { u8 pad[0x50004]; s32 x; } S_3ABE30;
s32 func_003ABE30(S_3ABE30 *a, s32 n) {
    s32 m = a->x;
    if (n < m) m = n;
    a->x -= m;
    return m;
}
/* localdecomp:end func_003ABE30 */

/* localdecomp:start func_003ABE58 */
extern s32 D_001D87E0;
s32 func_003ABE58(s32 *p, s32 b, s32 c) { D_001D87E0 = 0; p[2] = b; p[0] = c; return 1; }
/* localdecomp:end func_003ABE58 */

/* localdecomp:start func_003ABE70 */
extern s32 func_13CEB0();
extern void func_13CDF0(s32);
 
s32 func_003ABE70(void) {
    func_13CEB0();
    func_13CDF0(0);
    return 1;
}
/* localdecomp:end func_003ABE70 */

/* localdecomp:start func_003ABE98 */
__asm__(".extern D_001D87E0, 4");
extern s32 D_001D87E0;
typedef struct { u8 p0[8]; s32 f8; } P_3ABE98;
extern char D_001D87E8[];
extern char D_001D8800[];
extern void func_11F0A0();
extern s32 func_12BC00();
extern void func_11AF48();
extern s32 func_13CD28();
s32 func_003ABE98(P_3ABE98 *p, s32 b, s32 c) {
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
/* localdecomp:end func_003ABE98 */

/* localdecomp:start func_003ABF88 */
typedef struct { s32 f0; s32 f4; s32 f8; } S_ABF88;
s32 func_003ABF88(S_ABF88 *p, s32 a1) {
    s32 t = p->f8 * 0x10 + 0x10;
    s32 addr = (p->f4 + t) & 0xFFFFFFF;
    if (a1 == addr) {
        return 0;
    }
    return (u32)(a1 - p->f0) >> 11;
}
/* localdecomp:end func_003ABF88 */

/* localdecomp:start func_003ABFD0 */
extern void func_124920(void);
extern void func_124970(void);
void func_003ABFD0(s32 a) {
    func_124920();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = a;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    func_124970();
}
/* localdecomp:end func_003ABFD0 */

/* localdecomp:start func_003AC040 */
extern void func_124920(void);
extern void func_124970(void);
void func_003AC040(s32 a) {
    func_124920();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B400 = a;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    func_124970();
}
/* localdecomp:end func_003AC040 */

/* localdecomp:start func_003AC0B0 */
void func_003AC0B0(unsigned long *p, unsigned long a, unsigned long b, unsigned long c) {
    *p = (a << 32) | ((b << 32) >> 4) | ((c << 32) >> 32);
}
/* localdecomp:end func_003AC0B0 */

/* localdecomp:start func_003AC0D8 */
typedef struct { s32 f0; s32 f4; s32 f8; u8 pC[0xC]; s32 f18; u8 p1C[0x24]; s32 f40; u8 p44[4]; long f48; s32 f50; s32 f54; } O_3AC0D8;
typedef struct { s32 w0; s32 w4; s32 w8; s32 pad[5]; } St_3AC0D8;
extern s32 func_11EE20();
extern s32 func_003AC150();
s32 func_003AC0D8(O_3AC0D8 *o, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
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
  ((s32 (*)(void *))func_003AC150)(o);
  o->f48 = 0;
  return 1;
}
/* localdecomp:end func_003AC0D8 */

/* localdecomp:start func_003AC150 */
extern void func_003AC0B0_003AC150();
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; u8 p18[0x2C]; s32 f44; u8 p48[8]; s32 f50; s32 f54; s32 f58; s32 f5C; } O_3AC150;
s32 func_003AC150(O_3AC150 *o) {
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
        func_003AC0B0_003AC150((unsigned long *)(o->f4 + i * 16), (o->f0 + i * 0x800) & 0xFFFFFFF, 3, 0x80);
        i++;
    }
    func_003AC0B0_003AC150((unsigned long *)(o->f4 + i * 16), o->f4 & 0xFFFFFFF, 2, 0);
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000B410 = o->f0 & 0xFFFFFFF;
    *(volatile u32 *)0x1000B430 = o->f4 & 0xFFFFFFF;
    func_003AC040(5);
    return 1;
}
/* localdecomp:end func_003AC150 */

/* localdecomp:start func_003AC2B0 */
extern void func_0011EE40(s32);
extern void func_0011EE60(s32);
void func_003AC2B0(arg0, arg1, arg2, arg3, arg4)
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
/* localdecomp:end func_003AC2B0 */

/* localdecomp:start func_003AC3A0 */
typedef struct { u8 pad[0x14]; s32 w14; u8 pad2[0x28]; s32 w40; u8 pad3[4]; unsigned long d48; } S_AC3A0;
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
void func_003AC3A0(p, n) S_AC3A0 *p; s32 n; {  /* K&R: older callers use unprototyped calls */
    func_11EE60(p->w40);
    p->w14 += n;
    p->d48 = n + p->d48;
    func_11EE40(p->w40);
}
/* localdecomp:end func_003AC3A0 */

/* localdecomp:start func_003AC3F8 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; u8 p18[0x28]; s32 f40; s32 f44; } O_3AC3F8;
extern void func_003AC0B0_003AC3F8();
extern s32 func_003AAA98();
extern u8 D_001D8818[];
s32 func_003AC3F8(O_3AC3F8 *o) {
    s32 flag = 0;
    u32 reg;
    s32 pos;
    s32 t;
    s32 n;
    s32 cur;
    s32 idx;
    s32 i;
    func_11EE60(o->f40);
    if (o->f44 == 0) {
        func_003AAA98(D_001D8818);
        return 0;
    }
    func_003AC040(5);
    reg = *(volatile u32 *)0x1000B400;
    pos = func_003ABF88(o, *(volatile u32 *)0x1000B410);
    t = (pos + o->f8 - o->fC) % o->f8;
    n = o->f14 / 0x800;
    o->f14 = o->f14 - n * 0x800;
    o->fC = (o->fC + t) % o->f8;
    o->f10 = o->f10 - t;
    idx = (o->fC + o->f10) % o->f8;
    if (n > 0) {
        s32 m1 = o->f8 - 1;
        s32 k = (o->fC + o->f10 + m1) % o->f8;
        func_003AC0B0_003AC3F8(o->f4 + k * 16, o->f0 + k * 0x800, 3, 0x80);
        flag = 1;
    }
    {
        s32 c2 = idx;
        for (i = 0; i < n; i++) {
            s32 m = i != n - 1 ? 3 : 0;
        func_003AC0B0_003AC3F8(o->f4 + c2 * 16, o->f0 + c2 * 0x800, m, 0x80);
            c2 = (c2 + 1) % o->f8;
        }
    }
    o->f10 = o->f10 + n;
    if (o->f10 != 0) {
        if (flag) {
            reg = (reg & 0xFFFFFFF) | 0x30000000;
        }
        func_003AC040(reg | 0x100);
    }
    func_11EE40(o->f40);
    return 1;
}
/* localdecomp:end func_003AC3F8 */

/* localdecomp:start func_003AC5E0 */
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
extern void func_003AC040(s32);
extern void func_003ABFD0(s32);
s32 func_003AC5E0(s32 *p) {
    func_11EE60(p[0x10]);
    p[0x11] = 0;
    func_003AC040(5);
    p[7] = *(volatile s32 *)0x1000B410;
    p[8] = *(volatile s32 *)0x1000B430;
    p[9] = *(volatile s32 *)0x1000B420;
    p[10] = *(volatile s32 *)0x1000B400;
    if (*(volatile s32 *)0x10002010 & 0xF0) { do {} while (*(volatile s32 *)0x10002010 & 0xF0); }
    func_003ABFD0(0);
    p[11] = *(volatile s32 *)0x1000B010;
    p[12] = *(volatile s32 *)0x1000B020;
    p[13] = *(volatile s32 *)0x1000B000;
    p[14] = *(volatile s32 *)0x10002020;
    p[15] = *(volatile s32 *)0x10002010;
    func_11EE40(p[0x10]);
    return 1;
}
/* localdecomp:end func_003AC5E0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AC6F0);

/* localdecomp:start func_003ACA00 */
extern void func_003AC040(s32);
extern void func_11EE30(s32);
s32 func_003ACA00(u8 *p) {
    func_003AC040(5);
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000B410 = 0;
    *(volatile u32 *)0x1000B430 = 0;
    func_11EE30(*(s32 *)(p + 0x40));
    return 1;
}
/* localdecomp:end func_003ACA00 */

/* localdecomp:start func_003ACA58 */
extern void func_0011EE60(s32);
extern void func_0011EE40(s32);
s32 func_003ACA58(u8 *p) {
    s32 r;
    func_0011EE60(*(s32 *)(p + 0x40));
    r = (*(s32 *)(p + 0x10) << 11) + *(s32 *)(p + 0x14);
    func_0011EE40(*(s32 *)(p + 0x40));
    return r;
}
/* localdecomp:end func_003ACA58 */

/* localdecomp:start func_003ACAA8 */
typedef struct { u8 pad[0x14]; s32 w14; u8 pad2[0x28]; s32 w40; } S_ACAA8;
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
void func_003ACAA8(S_ACAA8 *p) {
    func_11EE60(p->w40);
    p->w14 = (p->w14 + 0x7FF) / 0x800 * 0x800;
    func_11EE40(p->w40);
}
/* localdecomp:end func_003ACAA8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ACB00);

/* localdecomp:start func_003ACC30 */
typedef struct { long f0; long f8; s32 f10; s32 f14; } S_CCb;
typedef struct { u8 p0[0x40]; s32 f40; u8 p44[0xC]; S_CCb *f50; s32 f54; s32 f58; s32 f5C; } S_CCa;
extern s32 func_11EE60(s32);
extern void func_11EE40(s32);
extern s32 func_003ACB00();
s32 func_003ACC30(S_CCa *a, S_CCb *b) {
    s32 r = 0;
    func_11EE60(a->f40);
    if (a->f58 < a->f54) {
        func_003ACB00(a, b);
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
/* localdecomp:end func_003ACC30 */

INCLUDE_ASM("asm/nonmatchings/text", func_003ACD38);

/* localdecomp:start func_003ACED0 */
extern void func_003AD038(void *);
extern s32 func_003AD430();
extern s32 func_003AD458();
extern s32 func_003AD488();
extern s32 func_003AD4B0();
extern s32 func_003AD4D8();
extern void func_003AC0D8_003ACED0(s32, s32, s32, s32, s32, s32);
extern void func_001350A8(void);
extern void func_00135D08(s32, s32, void *, s32);
s32 func_003ACED0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    func_001350A8();
    func_00135D08(arg0, 0, &func_003AD430, 0);
    func_00135D08(arg0, 1, &func_003AD458, 0);
    func_00135D08(arg0, 2, &func_003AD488, 0);
    func_00135D08(arg0, 3, &func_003AD4B0, 0);
    func_00135D08(arg0, 5, &func_003AD4D8, 0);
    func_003AD038((void *)arg0);
    func_003AC0D8_003ACED0(arg0 + 0x48, arg3, arg4, arg5, arg6, arg7);
    return 1;
}
/* localdecomp:end func_003ACED0 */

LINKER_REMNANT("asm/remnants", func_003ACFD0);

/* localdecomp:start func_003ACFD8 */
extern void func_139E50();
 
s32 func_003ACFD8(void) {
    func_139E50();
    return 1;
}
/* localdecomp:end func_003ACFD8 */

/* localdecomp:start func_003ACFF8 */
s32 func_003ACFF8(s32 arg0) {
    func_003AC2B0(arg0 + 0x48);
}
/* localdecomp:end func_003ACFF8 */

/* localdecomp:start func_003AD018 */
s32 func_003AD018(s32 arg0) {
    func_003AC3A0(arg0 + 0x48);
}
/* localdecomp:end func_003AD018 */

/* localdecomp:start func_003AD038 */
void func_003AD038(void *p) {
    *(s32 *)((u8 *)p + 0xA8) = 0;
}
/* localdecomp:end func_003AD038 */

/* localdecomp:start func_003AD040 */
extern void func_00135C00(u8 *);
s32 func_003AD040(u8 *p) {
    func_003ACA00(p + 0x48);
    func_00135C00(p);
    return 1;
}
/* localdecomp:end func_003AD040 */

/* localdecomp:start func_003AD078 */
void func_003AD078(void *a0) {
    *(s32 *)((u8 *)a0 + 168) = 1;
}
/* localdecomp:end func_003AD078 */

/* localdecomp:start func_003AD088 */
s32 func_003AD088(void *p) {
    return *(s32 *)((u8 *)p + 0xA8);
}
/* localdecomp:end func_003AD088 */

/* localdecomp:start func_003AD090 */
s32 func_003AD090(void *a0, s32 a1) {
    s32 old = *(s32 *)((u8 *)a0 + 168);
    *(s32 *)((u8 *)a0 + 168) = a1;
    return old;
}
/* localdecomp:end func_003AD090 */

/* localdecomp:start func_003AD0A0 */
typedef struct { unsigned long a, b; s32 c, d; } S_3AD0A0;
extern u8 *D_001DA134[];
extern void func_003ACC30(u8 *, S_3AD0A0 *);
void func_003AD0A0(u8 *p, unsigned long a, unsigned long b, s32 c, s32 d) {
    S_3AD0A0 s;
    s.a = a;
    s.b = b;
    s.c = c - *(s32 *)(p + 0x48);
    s.d = d;
    func_003ACC30(D_001DA134[0] + 0x48, &s);
}
/* localdecomp:end func_003AD0A0 */

/* localdecomp:start func_003AD0E0 */
s32 func_003AD0E0(s32 arg0) {
    func_003ACA58(arg0 + 0x48);
}
/* localdecomp:end func_003AD0E0 */

LINKER_REMNANT("asm/remnants", func_003AD100);

/* localdecomp:start func_003AD108 */
typedef struct { char c[4]; } S4_3AD108;
typedef struct { u8 p0[0x48]; u8 p48[0x60]; s32 fA8; } S_3AD108;
extern S4_3AD108 D_001D8830[];
extern s32 D_001DA134_003AD108;
extern void func_003ACFF8();
extern s32 func_003AD520();
extern void func_003AD018();
extern void func_003ACAA8();
s32 func_003AD108(S_3AD108 *a) {
    S4_3AD108 buf;
    s32 r0;
    s32 r1;
    s32 r2;
    s32 r3;
    s32 v;
    buf = D_001D8830[0];
    func_003ACFF8(a, &r0, &r1, &r2, &r3);
    if (r1 + r3 < 4) return 0;
    v = func_003AD520((r0 & 0xFFFFFFF) | 0x20000000, r1, (r2 & 0xFFFFFFF) | 0x20000000, r3, &buf, 4, 0, 0);
    func_003AD018(D_001DA134_003AD108, v);
    func_003ACAA8((u8 *)a + 0x48);
    if (a->fA8 == 0) {
        a->fA8 = 2;
    }
    return 1;
}
/* localdecomp:end func_003AD108 */

/* localdecomp:start func_003AD1D8 */
extern s32 func_00135CF0(void *);
s32 func_003AD1D8(void *p) {
    s32 r = 0;
    if (func_003AD0E0(p) == 0) r = func_00135CF0(p) != 0;
    return r;
}
/* localdecomp:end func_003AD1D8 */

/* localdecomp:start func_003AD220 */
extern s32 func_003AD090();
extern void func_003AD6B0();
extern s32 func_003AC150();
extern s32 func_003AD288();
extern s32 D_001DA108;
extern s32 *D_001DA108_003AD220[];
void func_003AD220(s32 arg0) {
    volatile s32 *p;
    s32 x;
    func_003AC150(arg0 + 0x48);
    func_003AD6B0(D_001DA108);
    func_003AD288(arg0);
    p = (volatile s32 *)D_001DA108_003AD220[0];
    do { x = p[3]; __asm__ volatile("nop
	nop
	nop
	nop"); } while (x != 0);
    func_003AD090(arg0, 3);
}
/* localdecomp:end func_003AD220 */

/* localdecomp:start func_003AD288 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; } S_3AD288;
__asm__(".extern D_001DA108_003AD288, 16");
extern S_3AD288 *D_001DA108_003AD288;
extern u8 D_001D8850[];
extern u8 D_001D8838[];
extern s32 func_003AD748();
extern void func_003AA7E0();
extern s32 func_135C10();
extern s32 func_135CE0();
extern void func_135C60();
extern void func_003AD6D8();
extern void func_003AB610();
extern s32 func_003AD088();
extern void func_11AF48();
extern s32 func_003AAA98();
s32 func_003AD288(s32 *a) {
    s32 ret = 1;
    s32 v, h, w, hh;
    while (func_135CE0(a) == 0) {
        if (func_003AD088(a) == 1) {
            ret = -1;
            func_11AF48(D_001D8838);
            break;
        }
        while ((v = func_003AD748(D_001DA108)) == 0) {
            func_003AA7E0();
        }
        if (func_135C10(a, v, 0x340) < 0) {
            func_003AAA98(D_001D8850);
        }
        if (a[2] == 0) {
            S_3AD288 *p;
            hh = a[0];
            w = a[1];
            h = 0;
            p = (S_3AD288 *)D_001DA108;
            if (h < p->x10) {
                do {
                    func_003AB610(p->x4 + h * 0x27E40 + 0x40, p->x0 + h * 0xD0000, 0, hh, w);
                    func_003AB610(D_001DA108_003AD288->x4 + h * 0x27E40 + 0x13F40, D_001DA108_003AD288->x0 + h * 0xD0000, 1, hh, w);
                    h++;
                    p = D_001DA108_003AD288;
                } while (h < p->x10);
            }
        }
        func_003AD6D8(D_001DA108);
        func_003AA7E0();
    }
    func_135C60(a);
    return ret;
}
/* localdecomp:end func_003AD288 */
