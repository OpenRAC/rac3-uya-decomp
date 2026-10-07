#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A2E80);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A2F98);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A3088);

LINKER_REMNANT("asm/boot_elf/remnants", func_003A39F8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A3A00);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C560);

/* localdecomp:start func_003A3E30 */
typedef struct { u8 pad[0x5C0]; } S_39E8E0;
extern S_39E8E0 D_001CD0C0[];
void func_003A3A00(S_39E8E0 *);
void func_003A3E30(void) {
    s32 i;
    for (i = 0; i < 8; i++) func_003A3A00(&D_001CD0C0[i]);
}
/* localdecomp:end func_003A3E30 */

/* localdecomp:start func_003A3E78 */
typedef struct { u8 pad[0xA4]; u8 arr[1]; } S_143950;
extern S_143950 D_143950;
extern u8 D_001A71C4[];
s32 func_003A3E78(s32 a, s32 i) {
    if (D_143950.arr[i] != 0 && D_001A71C4[0] == 0) {
        switch (a) {
        case 0x40: return 0x44;
        case 4: return 1;
        case 8: return 2;
        }
    }
    return a;
}
/* localdecomp:end func_003A3E78 */

/* localdecomp:start func_003A3EF0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39E9A0;
extern V4_39E9A0 D_00222480_003A3EF0[];
extern V4_39E9A0 D_002276E0[];
extern s32 D_001A30F4[];
extern void func_00382980(s32, f32, f32);
extern s32 func_003D3F00();
extern void func_0038D148_003A3EF0(void *, void *, f32);
void func_003A3EF0(V4_39E9A0 *a, V4_39E9A0 *p) {
    u128_t va, vb;
    if (p == 0) p = D_00222480_003A3EF0;
    func_00382980((s32)a, 0.5f, 6.0f);
    __asm__("lqc2 %0, %1" : "=j"(va) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(*p));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
    __asm__("sqc2 %1, %0" : "=m"(*a) : "j"(va));
    if (func_003D3F00(p, a, 0x82, D_001A30F4[0], 0)) {
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(*p));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(D_002276E0[0]));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(*a) : "j"(va));
        func_0038D148_003A3EF0(a, a, 0.75f);
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(*p));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(*a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(*a) : "j"(va));
    }
}
/* localdecomp:end func_003A3EF0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A3FA8);

/* localdecomp:start func_003A3FB0 */
typedef struct { u8 pad[8]; s32 f8; s32 fC; u8 pad2[9]; u8 f19; } S_39EA60;
s32 func_003A3FB0(f32 *op, void *c, f32 x, f32 lo, f32 hi) {
    S_39EA60 *o = (S_39EA60 *)op;
    s32 a = o->f8;
    f32 t;
    if ((o->f19 & 1) || c != 0) {
        if (x <= lo) return o->fC;
        if (hi <= x) return a;
        t = hi - x;
        return a + (s32)((t * t * (f32)(o->fC - a)) / ((hi - lo) * (hi - lo)));
    }
    if (x <= lo) return o->fC;
    if (!(hi <= x)) return a + (s32)(((hi - x) * (f32)(o->fC - a)) / (hi - lo));
    return a;
}
/* localdecomp:end func_003A3FB0 */

/* localdecomp:start func_003A4088 */
extern s32 D_00222480[];
extern f32 func_0038D228(void *, void *);
extern s32 func_003A3FB0(f32 *, void *, f32, f32, f32);
typedef struct { s32 pad; f32 *q; } S_39EB38;
void func_003A4088(S_39EB38 *p, void *a, void *b, void *c) {
    f32 f;
    if (b == 0) b = D_00222480;
    f = func_0038D228(a, b);
    func_003A3FB0(p->q, c, f, p->q[0], p->q[1]);
}
/* localdecomp:end func_003A4088 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A40E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A42A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A4390);

/* localdecomp:start func_003A4520 */
extern s32 D_001685EC[];
extern void func_0013CFC0(s32, s32);
void func_003A4520(void) {
    func_0013CFC0(2, D_001685EC[0]);
}
/* localdecomp:end func_003A4520 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A4548);

LINKER_REMNANT("asm/boot_elf/remnants", func_003A51D8);

/* localdecomp:start func_003A51E8 */
extern u8 D_1A30B0[];
void func_003A51E8(u32 i) {
    if (i < 52) {
        u8 *e = D_1A30B0 + i * 128;
        u8 s = e[0xD0];
        if (s == 7) {
            *(s32 *)(e + 0xDC) = 0;
            *(s32 *)(e + 0x100) = 0;
            e[0xD0] = 0;
            return;
        }
        if (s != 0 && s != 6) e[0xD0] = 4;
    }
}
/* localdecomp:end func_003A51E8 */

/* localdecomp:start func_003A5240 */
typedef struct { u8 pad[0x1200]; s32 x1200; u8 pad2[0x25C0 - 0x1204]; s32 x25C0; } S_39FB60;
typedef struct { u8 pad[0x50]; u8 b50; u8 pad2[0x2F]; } S2_39FB60;
extern S_39FB60 D_001A4BE0[];
extern S2_39FB60 D_001A30B0[];
s32 func_003A5240(s32 id) {
    s32 n = 0x34;
    s32 i;
    if (id == 0 || (D_001A4BE0[0].x25C0 != id && D_001A4BE0[0].x1200 != id)) n = 0x2A;
    for (i = 0; i < n; i++) {
        if (D_001A30B0[i + 1].b50 == 0) break;
    }
    if (i == n) return -1;
    return i;
}
/* localdecomp:end func_003A5240 */

/* localdecomp:start func_003A52B8 */
__asm__(".extern D_001D6E14, 1");
typedef int u128_39FBD8 __attribute__((mode(TI)));
extern void func_003A4088(void *, void *, void *, void *);
typedef struct 
{
  u8 p0[0xC4];
  u8 *c4;
  u8 pC8[0x18];
  u128_39FBD8 qE0;
  u128_39FBD8 qF0;
} E_39FBD8;
typedef struct { u8 b[0x80]; } R_39FBD8;
extern s32 D_001D5B98_003A52B8;
extern u8 D_001D6E14;
extern u8 D_00222500[];
extern s32 func_00382868(s32);
s32 func_003A52B8(u8 *s, u32 flags, u8 *src, u8 *pos, s32 vol)
{
  s32 r;
  s32 off;
  s32 v = 0;
  s32 empty = s[0x18] == 0;
  u128_39FBD8 *new_var;
  s32 a;
  s32 b;
  s32 c;
  if (!(flags & 4))
  {
    if ((empty ^ 1) != 0)
      goto fail;
  }
  else
    if (empty)
      goto fail;
  r = func_003A5240(src);
  if (r >= 0)
  {
    {
      u8 *e;
      off = r * 128;
      e = (u8 *) (off + ((s32) D_1A30B0));
      *((s32 *) (e + 0x114)) = 0;
      *((u8 **) (e + 0xC4)) = s;
      new_var = (u128_39FBD8 *) pos;
      *((s16 *) (e + 0xC8)) = *((s16 *) (s + 0x1A));
      *((s16 *) (e + 0xCA)) = -1;
      *((f32 *) (e + 0x110)) = -1.0f;
      *((s16 *) (e + 0xCC)) = vol;
      *((s32 *) (e + 0xDC)) = 0;
      *((s32 *) (e + 0x100)) = 0;
      __asm__("sq $0,%0" : "=m"(*((u128_39FBD8 *) (off + (D_1A30B0 + 0xF0)))));
      if ((pos != 0) || (src != 0))
      {
        if (src != 0)
        {
          ((u128_39FBD8 (*)[8]) D_1A30B0)[r][14] = *((u128_39FBD8 *) (src + 0x10));
          *((f32 *) (e + 0xE8)) += 1.0f;
        }
        else
        {
          ((u128_39FBD8 (*)[8]) D_1A30B0)[r][14] = *new_var;
        }
      }
      else
      {
        flags |= 0x11;
        __asm__("sq $0,%0" : "=m"(*((u128_39FBD8 *) ((r * 128) + (D_1A30B0 + 0xE0)))));
      }
    }
    if (!(flags & 0x10))
    {
    if (D_001D5B98_003A52B8 != 0)
    {
      s32 i;
      for (i = 0; i < (D_001D5B98_003A52B8 + 1); i++)
      {
        f32 *o;
        f32 f = func_0038D228((r * 128) + (D_1A30B0 + 0xE0), D_00222500 + i * 0x460);
        o = (f32 *)((E_39FBD8 *)(D_1A30B0 + (r * 128)))->c4;
        v += func_003A3FB0(o, (void *) 1, f, o[0], o[1]);
      }

      {
        s32 lim = 0x400 - (*((s32 *) 0x1D52E4));
        if (v >= lim)
        {
          v = lim;
        }
      }
    }
    else
    {
      v = ((s32 (*)(void *, void *, void *, void *)) func_003A4088)((r * 128) + (D_1A30B0 + 0xC0), (r * 128) + (D_1A30B0 + 0xE0), 0, 0);
    }
    }
    else
    {
      v = vol;
    }
    if (v < 0x20)
    {
      return -1;
    }
    else
    {
      {
        u8 *e = (u8 *) ((r * 128) + ((s32) D_1A30B0));
        *((u32 *) (e + 0x118)) = flags;
        e[0xD0] = 7;
        *((s16 *) (e + 0xCE)) = 0;
      }
      a = *((s32 *) (s + 0x14));
      b = *((s32 *) (s + 0x10));
      if (a != b)
      {
        c = func_00382868(a - b) + (*((s32 *) (s + 0x10)));
      }
      else
      {
        c = a;
      }
      {
        u8 *e = (u8 *) ((r * 128) + ((s32) D_1A30B0));
        u8 t = D_001D6E14;
        u8 t1 = t + 1;
        *((s32 *) (0xD4 + e)) = c;
        *((u32 *) (e + 0xC0)) = 0xFFFFFFFF;
        D_001D6E14 = t1;
        *((s32 *) (e + 0xD8)) = 0;
        e[0xD3] = t;
      }
    }
  }
  else
  {
    r = -1;
  }
  return r;
  fail:
  return -1;
}
/* localdecomp:end func_003A52B8 */

/* localdecomp:start func_003A5560 */
typedef struct { u8 pad[0xD]; u8 bD; u8 pad2[0x1A]; s32 f28; } O_39FE80;
typedef struct { u8 pad[0x24]; O_39FE80 *o; } P_39FE80;
extern u8 D_1A30B0[];
extern s32 func_003A52B8();
s32 func_003A5560(s32 a, s32 b, P_39FE80 *p) {
    O_39FE80 *o;
    s32 r;
    u8 *e;
    if (p == 0) return -1;
    o = p->o;
    if (o == 0) return -1;
    if (o->f28 == 0) return -1;
    if (a >= o->bD) return -1;
    r = func_003A52B8(o->f28 + a * 32, b, p, 0, 0x400);
    if (r >= 0) {
        e = D_1A30B0 + r * 128;
        *(s32 *)(e + 0xDC) = (s32)p;
        *(s16 *)(e + 0xCA) = a;
        *(s32 *)(e + 0x108) = -1;
    }
    return r;
}
/* localdecomp:end func_003A5560 */

/* localdecomp:start func_003A5608 */
extern s32 D_001D9DAC;
extern s32 D_001D5B9C;
extern u8 D_1A30B0[];
extern s32 func_003A52B8();
s32 func_003A5608(s32 a, s32 b, s32 c) {
    s32 r;
    u8 *e;
    if (D_001D9DAC == 0) return -1;
    if (a >= D_001D5B9C) return -1;
    r = func_003A52B8(D_001D9DAC + a * 32, b, c, 0, 0x400);
    if (r >= 0) {
        e = D_1A30B0 + r * 128;
        *(s32 *)(e + 0xDC) = c;
        *(s16 *)(e + 0xCA) = a;
    }
    return r;
}
/* localdecomp:end func_003A5608 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A5698);
