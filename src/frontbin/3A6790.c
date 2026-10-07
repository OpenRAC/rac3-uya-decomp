#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003A69A0();
extern void *func_003A6910();
extern s32 func_003A6830(u8 *, s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003A6790 */
extern void func_00121760();
extern void func_003A4768();
extern char D_001D8230[];
extern char D_001D8270[];
extern char D_001D82A0[];
extern s32 D_001D5C84;
void func_003A6790(s32 *arg0)
{
  s32 *p;
  s32 n;
  s32 *new_var;
  new_var = arg0 + 7;
  func_00121760(D_001D8230);
  p = new_var;
  n = arg0[6];
  func_00121760(D_001D8270, p, n);
  if (n > 0)
  {
    do
    {
      p[1] += (s32) arg0;
      func_003A4768(p[1]);
      p += 2;
      D_001D5C84 = D_001D5C84 + 1;
      n--;
    }
    while (n != 0);
  }
  func_00121760(D_001D82A0);
}
/* localdecomp:end func_003A6790 */

/* localdecomp:start func_003A6830 */
typedef struct { s32 k, v; } E_3A6830;
s32 func_003A6830(u8 *p, s32 k) {
    s32 n = *(s32 *)(p + 0x18);
    E_3A6830 *e = (E_3A6830 *)(p + 0x1C);
    s32 i;
    s32 r = 0;
    for (i = 0; i < n; i++) {
        if (e[i].k == k) {
            r = e[i].v;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_003A6830 */

/* localdecomp:start func_003A6880 */
void *func_003A6880(void *p) {
    return p;
}
/* localdecomp:end func_003A6880 */

/* localdecomp:start func_003A6888 */
void func_00116F98(void *, s32, void *);
extern u8 D_001D82D8[];
extern u8 D_001D82F8[];
typedef struct { s32 f0; s32 f4; u32 f8; s32 fC; s32 f10; s32 f14; } S_003A6888;

void func_003A6888(S_003A6888 *arg0, u32 arg1, s32 arg2, s32 arg3) {
    if (arg1 < 4U) {
        func_00116F98(D_001D82D8, 0x26, D_001D82F8);
    }
    arg0->f0 = arg2;
    arg0->f4 = arg3;
    arg0->f8 = arg1;
    arg0->f14 = 0;
    arg0->fC = 0;
    arg0->f10 = 0;
}
/* localdecomp:end func_003A6888 */

LINKER_REMNANT("asm/remnants", func_003A6908);

/* localdecomp:start func_003A6910 */
void func_00116F98(void *, s32, void *);
extern u8 D_001D82D8[];
extern u8 D_001D8320[];
typedef struct { u8 *base; u32 size; s32 elem; u32 used; s32 count; void **free; } S_003A6910;

void *func_003A6910(S_003A6910 *pool) {
    void **p;
    u32 used;
    u32 next;

    p = pool->free;
    if (p != 0) {
        pool->free = *p;
        pool->count++;
        return p;
    }
    used = pool->used;
    next = used + pool->elem;
    if (pool->size < next) {
        func_00116F98(D_001D82D8, 0x54, D_001D8320);
        return 0;
    }
    { u8 *r = pool->base + used; pool->used = next; pool->count++; return r; }
}
/* localdecomp:end func_003A6910 */

/* localdecomp:start func_003A69A0 */
void func_003A69A0(void *a0, void *a1) {
    *(s32 *)a1 = *(s32 *)((u8 *)a0 + 0x14);
    *(s32 *)((u8 *)a0 + 0x14) = (s32)a1;
    *(s32 *)((u8 *)a0 + 0x10) = *(s32 *)((u8 *)a0 + 0x10) - 1;
}
/* localdecomp:end func_003A69A0 */

LINKER_REMNANT("asm/remnants", func_003A69C0);

/* localdecomp:start func_003A69C8 */
extern u8 *func_003A5C70(u8 *);
u8 *func_003A69C8(u8 *p) {
    func_003A5C70(p + 0x10);
    func_003A5C70(p + 0x4C);
    return p;
}
/* localdecomp:end func_003A69C8 */

/* localdecomp:start func_003A6A00 */
typedef struct {
    s32 *p0; s32 *p4; s32 *p8; s32 *pC;
    u8 sub10[0x3C]; u8 sub4C[0x3C]; u8 b88; u8 pad89[0x188 - 0x89];
    s32 f188, f18C, f190; u8 pad194[4]; s32 f198; u8 pad19C[8];
    s32 f1A4, f1A8, f1AC; u8 pad1B0[4]; s32 f1B4; u8 f1B8[0x78];
} O_3A6A00;
extern s32 D_001D5C78;
extern u8 D_001D8370[], D_001D8380[];
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003ECDC0(s32, s32);
extern void func_003A5CA8();
extern void func_003A5E80(u8 *, u8 *, s32);
extern void func_003A5EB0(void *, f32);
extern void func_003A5958(void *, s32);
extern s32 func_003A5910(void *);
void func_003A6A00(O_3A6A00 *o, s32 a) {
    s32 *t;
    o->b88 = 0;
    o->f18C = 0;
    o->f188 = 0;
    o->f1A8 = 0;
    o->f1A4 = 1;
    o->f1AC = 0;
    o->f1B4 = 0x28;
    o->f190 = 1;
    func_0011A264((s32)o->f1B8, 0, 0x78);
    if (a != 0) {
        {
            s32 *t0 = (s32 *)func_003ECDC0(0x10, (s32)func_003A6910(a));
            ((f32 *)t0)[0] = 255.0f;
            ((f32 *)t0)[1] = 108.0f;
            t0[2] = 0;
            t0[3] = 0;
            o->p0 = t0;
        }
        {
            s32 *t1 = (s32 *)func_003ECDC0(0x10, (s32)func_003A6910(a));
            ((f32 *)t1)[0] = 0.0f;
            ((f32 *)t1)[1] = 0.0f;
            t1[0] = 0x600E5092;
            t1[2] = 0;
            t1[3] = 0;
            o->p8 = t1;
        }
        {
            s32 *t2 = (s32 *)func_003ECDC0(0x10, (s32)func_003A6910(a));
            o->p4 = t2;
            t2[1] = 0;
            t2[2] = 0;
            t2[3] = 0;
            t2[0] = 0;
        }
        {
            s32 *t3 = (s32 *)func_003ECDC0(0x10, (s32)func_003A6910(a));
            o->pC = t3;
            t3[1] = 0;
            t3[2] = 0;
            t3[3] = 0;
            t3[0] = 0;
        }
    }
    func_003A5CA8(o->sub10, D_001D8370, a);
    func_003A5E80(o->sub10, (u8 *)D_001D5C78 + 0x7090, 0xC);
    func_003A5EB0(o->sub10, 0.02f);
    func_003A5958(o->sub10, 1);
    *(s32 *)func_003A5910(o->sub10) = 0x332299DE;
    func_003A5CA8(o->sub4C, D_001D8380, a);
    func_003A5E80(o->sub4C, (u8 *)D_001D5C78 + 0x7090, 0xD);
    func_003A5958(o->sub4C, 1);
    *(s32 *)func_003A5910(o->sub4C) = 0x332299DE;
    *o->pC = 0x8066CCFF;
    o->f198 = 0;
    *o->p4 = 0;
}
/* localdecomp:end func_003A6A00 */

LINKER_REMNANT("asm/remnants", func_003A6C08);

/* localdecomp:start func_003A6C30 */
/* MATCH */
typedef struct {
    s16 h0, h2, h4, h6, h8, hA, hC, hE, h10;
    u16 h12;
    s16 h14, h16, h18, h1A;
} W_3A6C30;
extern char D_001D8388[], D_001D8398[], D_001D83A8[], D_001D83E0[], D_001D8418[], D_001D8420[], D_001D8430[];
extern s32 func_11B2E8();
extern void func_0038C8F8();
extern void func_0038C980();
extern void func_0038B1E8();
extern void func_00387C78(s32, s32, s32, s32, s32, s32);
extern void func_003A7090(s32, s32, s32, f32, f32, f32, f32);
void func_003A6C30(s32 a0, W_3A6C30 *p, s32 a2, s32 a3, s32 mode, s32 center, s32 a6, s32 a7, s32 x, s32 y, u8 b) {
    char buf[0x200];
    s32 saved = (s16)p->h12;
    s32 dx, dy, l, r, t, bo, cx, cy;
    p->h12 |= 3;
    if (x != 0) {
        if (y != 0) {
            if (b != 0) {
                if (a7 != 0) func_11B2E8(buf, D_001D8388, a3, 1, x, 1, y);
                else func_11B2E8(buf, D_001D8398, a3, 1, 1, x, 1, y);
            } else {
                if (a7 != 0) func_11B2E8(buf, D_001D83A8, a3, 1, x, y);
                else func_11B2E8(buf, D_001D83E0, a3, 1, 1, x, y);
            }
        } else {
            if (a7 != 0) func_11B2E8(buf, D_001D8418, a3, 1, x);
            else func_11B2E8(buf, D_001D8420, a3, 1, 1, x);
        }
    } else {
        func_11B2E8(buf, D_001D8430, a3);
    }
    p->h12 |= 4;
    switch (mode) {
    case 0: func_0038C8F8(p, a2, buf, a6); break;
    case 1: ((void (*)(void *, s32, void *, s32, unsigned long, f32, f32))func_0038B1E8)(p, a2, buf, a6, 0x80000000UL, 1.0f, 1.0f); break;
    case 2: func_0038C980(p, a2, buf, a6); break;
    }
    if (center != 0) {
        s32 c = (*(s32 *)0x1D4BC4 - p->hE) >> 1;
        p->h0 = c;
        p->h2 = p->h0 + p->hE;
        p->hA = c + (p->hE >> 1);
    }
    switch (mode) {
    case 0: func_0038C8F8(p, a2, buf, a6); break;
    case 1: ((void (*)(void *, s32, void *, s32, unsigned long, f32, f32))func_0038B1E8)(p, a2, buf, a6, 0x80000000UL, 1.0f, 1.0f); break;
    case 2: func_0038C980(p, a2, buf, a6); break;
    }
    dx = (p->hC >> 1) + 10;
    dy = (p->hE >> 1) + 5;
    p->h12 &= ~4;
    cx = p->h8;
    cy = p->hA;
    t = cy - dy;
    l = cx - dx;
    r = cx + dx;
    bo = cy + dy;
    func_00387C78(t, bo, l, r, 0x60, 0x600E5092);
    func_003A7090(a0, 0x60, 0x332299DE, t, bo, l, r);
    p->h18 = 2;
    p->h12 |= 0x20;
    p->h1A = 2;
    switch (mode) {
    case 0: func_0038C8F8(p, a2, buf, a6); break;
    case 1: ((void (*)(void *, s32, void *, s32, unsigned long, f32, f32))func_0038B1E8)(p, a2, buf, a6, 0x80000000UL, 1.0f, 1.0f); break;
    case 2: func_0038C980(p, a2, buf, a6); break;
    }
    p->h12 = saved;
}
/* localdecomp:end func_003A6C30 */

/* localdecomp:start func_003A7090 */
typedef struct { u8 p0[0xB0]; f32 fB0; } S_225980_3A7090;
extern S_225980_3A7090 D_00225980_003A7090;
extern s32 D_001D5C78;
extern s32 D_001D52F0;
extern s32 func_003A4760();
extern void func_003A4758(s32);
extern s32 func_003A5900();
extern void func_003830E8();
extern void func_003A4DC8_003A7090(s32, f32, f32, s32, f32, f32, f32);
void func_003A7090(s32 base, s32 hi, s32 lo, f32 f0, f32 f1, f32 f2, f32 f3) {
    s32 saved;
    f32 old;
    f32 d;
    f32 one;
    f32 e;
    f32 y0;
    f32 y1;
    s32 p1, p2;
    saved = func_003A4760();
    func_003A4758(0);
    if (D_001D5C78 != 0) {
        one = 1.0f;
        old = D_00225980_003A7090.fB0;
        d = one;
        D_00225980_003A7090.fB0 = 0.62f;
        func_003830E8();
        e = ((f1 - f0) - 26.0f) / 112.0f;
        e = e * 0.31100002f + 0.0375f;
        if (func_003A5900() == 1) {
            d = 0.9f;
        }
        p1 = base + 0x5100;
        hi <<= 24;
        hi |= lo;
        func_003A4DC8_003A7090(*(s32 *)(p1 + (D_001D52F0 << 2)), f2, f0, hi, -1.0f, d, e);
        y0 = f2 + 16.0f;
        func_003A4DC8_003A7090(*(s32 *)(p1 + (D_001D52F0 << 2)), f3, f0, hi, one, d, e);
        p2 = base + 0x5110;
        y1 = f3 - 16.0f;
        e = ((f3 - f2) - 150.0f) / 306.0f;
        e = e * 0.43300003f + 0.102f;
        func_003A4DC8_003A7090(*(s32 *)(p2 + (D_001D52F0 << 2)), y0, f0, hi, -1.0f, one, e);
        func_003A4DC8_003A7090(*(s32 *)(p2 + (D_001D52F0 << 2)), y1, f0, hi, one, one, e);
        func_003A4DC8_003A7090(*(s32 *)(p2 + (D_001D52F0 << 2)), y0, f1, hi, -1.0f, -1.0f, e);
        func_003A4DC8_003A7090(*(s32 *)(p2 + (D_001D52F0 << 2)), y1, f1, hi, one, -1.0f, e);
        D_00225980_003A7090.fB0 = old;
        func_003830E8();
        func_003A4758(saved);
    }
}
/* localdecomp:end func_003A7090 */

LINKER_REMNANT("asm/remnants", func_003A7380);

/* localdecomp:start func_003A7398 */
s32 func_003A7398() {
}
/* localdecomp:end func_003A7398 */

/* localdecomp:start func_003A73A0 */
typedef struct { s32 *p0; s32 *p4; u8 *p8; s32 *pC; u8 sub10[0x178]; s32 f188, f18C, f190; u8 p194[4]; s32 f198, f19C, f1A0, f1A4; f32 f1A8; u8 p1AC[4]; f32 f1B0; s32 f1B4; } O_A73A0;
extern f32 D_001D8434_003A73A0;
extern f32 D_001D8438_003A73A0;
__asm__(".extern D_001D8434_003A73A0, 4");
__asm__(".extern D_001D8438_003A73A0, 4");
extern void func_003A5EB0(void *, f32);
s32 func_003A73A0(void *arg0) {
    O_A73A0 *o = arg0;
    s32 cnt = o->f198;
    s32 v = o->p8[3];
    u8 *p;
    u8 *q;
    s32 hi;
    s32 *t;
    s32 m;
    s32 x;
    f32 f;
    if (cnt > 0) {
        v = v + 8;
        v = (v >= 0x81) ? 0x80 : v;
        o->f198 = cnt - 1;
    } else {
        v = v - 8;
        v = (v <= -1) ? 0 : v;
    }
    if (v == 0) {
        *o->p4 = 0;
    } else {
        f32 k14 = 14.0f;
        f32 k23 = 23.5f;
        f32 g = 0.0f;
        f32 zero;
        hi = v << 24;
        p = (u8 *)o + 0x10;
        q = (u8 *)o + 0x4C;
        { s32 *r = (s32 *)o->p8; *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = o->pC; *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = (s32 *)func_003A5910(p); *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = (s32 *)func_003A5910(q); *r = (*r & 0xFFFFFF) | hi; }
        m = o->f1A4;
        switch (m) {
        case 0: {
            s32 x;
            f32 f;
            zero = g;
            x = (o->f1B4 >> 1) + 8;
            o->f19C = 8;
            o->f1A0 = 6;
            o->f18C = ((o->f190 * 0x10) >> 1) + 6;
            o->f188 = x;
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_003A5EB0(q, k + 0.005f); }
            f = D_001D8434_003A73A0;
            if (zero < f) {
                func_003A5EB0(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_003A5EB0(p, g * 0.85f + 0.03f);
            f = D_001D8438_003A73A0;
            if (zero <= f) {
                func_003A5EB0(p, f);
            }
            o->f1B0 = g * 306.0f + k23;
            break;
        }
        case 1: {
            s32 x;
            f32 f;
            zero = g;
            x = (o->f1B4 >> 1) + 8;
            o->f19C = 8;
            o->f1A0 = 6;
            o->f18C = ((o->f190 * 0x10) >> 1) + 6;
            o->f188 = x;
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_003A5EB0(q, k + 0.005f); }
            f = D_001D8434_003A73A0;
            if (zero < f) {
                func_003A5EB0(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_003A5EB0(p, g * 0.85f + 0.03f);
            f = D_001D8438_003A73A0;
            if (zero <= f) {
                func_003A5EB0(p, f);
            }
            o->f1B0 = g * 306.0f + k23;
            break;
        }
        case 2:
            break;
        }
    }
}
/* localdecomp:end func_003A73A0 */

/* localdecomp:start func_003A7610 */
s32 func_003A7610() {
}
/* localdecomp:end func_003A7610 */

/* localdecomp:start func_003A7618 */
extern s32 func_003A73A0(void *);

void func_003A7618(void *arg0) {
    s32 temp_v1;

    if (*(*(f32 **)((u8 *)(arg0) + 4)) != 0.0f) {
        temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x1A8));
        switch (temp_v1) {                          /* irregular */
        case 0:
            func_003A73A0(arg0);
            break;
        case 2:
            func_003A7610(arg0);
            break;
        }
        func_003A7398(arg0);
    }
}
/* localdecomp:end func_003A7618 */
