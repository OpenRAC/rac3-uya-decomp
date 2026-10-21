#include "common.h"

/* localdecomp:start func_00424048 */
extern unsigned long D_001F3E40[3];
extern s32 D_00200E70[];
extern void func_00424048(s32, s32, void *, s32);
extern void func_00423E10();

typedef int u128_394C58 __attribute__((mode(TI)));
typedef struct 
{
  u8 p0[0xA];
  s16 hA;
  u8 pC[4];
} T_394C58;
typedef struct 
{
  u8 p0[0x20];
  s32 x20;
} R_394C58;
typedef struct 
{
  u8 p0[0x10];
  u8 b10;
  u8 p11[3];
  s32 x14;
  u8 p18[4];
  s32 x1C[1];
} O_394C58;
typedef struct 
{
  u8 b0;
  u8 p1[0xB];
  s32 xC;
} E_394C58;
typedef struct 
{
  s32 x0;
  u8 b4;
  u8 b5;
  u8 b6;
  u8 b7;
  u8 b8;
  u8 b9;
  u8 bA;
  u8 bB;
  u8 bC;
  u8 pD[3];
  s32 x10;
  s32 x14;
  s32 x18;
  s32 x1C;
  s32 x20;
  s32 x24;
  s32 x28;
  u8 b2C;
  u8 p2D[0x1A];
  u8 b47;
  s32 x48[1];
} H_394C58;
extern R_394C58 D_001A1ED0_00394C58;
extern u8 D_001FDC50[];
extern s32 D_00200E70[];
void func_00424048(s32 a, s32 b, void *cv, s32 d)
{
  H_394C58 *p = (H_394C58 *) a;
  T_394C58 *tbl = (T_394C58 *) b;
  u8 *c = cv;
  u32 n;
  s32 i;
  n = (p->b4 + p->b5) + p->b6;
  if (p->b2C != 0)
  {
    n += (((u8 *) p) + (p->b2C << 4))[1];
  }
  if (p->x0 != 0)
  {
    s32 *q = (s32 *) (p->x0 = ((s32) p) + p->x0);
    if (n != 0)
    {
      u32 k0 = n;
      do
      {
        q[0] = q[0] + ((s32) p);
        q[2] = q[2] + ((s32) p);
        q += 4;
      }
      while (--k0);
    }
  }
  if (p->x10 != 0)
  {
    p->x10 = ((s32) p) + p->x10;
  }
  if (p->x14 != 0)
  {
    p->x14 = ((s32) p) + p->x14;
  }
  if (p->x18 != 0)
  {
    p->x18 = ((s32) p) + p->x18;
  }
  if (p->x1C != 0)
  {
    s32 m;
    p->x1C = ((s32) p) + p->x1C;
    m = *((s32 *) p->x1C);
    for (i = 0; i < m; i++)
    {
      s32 *e = (s32 *) ((i << 2) + p->x1C);
      e[1] = e[1] + ((s32) p);
    }

  }
  if (p->x20 != 0)
  {
    E_394C58 *e = (E_394C58 *) (p->x20 = ((s32) p) + p->x20);
    for (;;)
    {
      u8 *s = &e->b0;
      e->xC = e->xC + ((s32) p);
      if (*s != 0xFF)
      {
        do
        {
          *s = c[*s];
          s++;
        }
        while ((*s) != 0xFF);
      }
      if (e->xC < 0) break;
      e++;
    }
  }
  if (p->bB != 0)
  {
    s32 hi = p->bB >> 4;
    u16 *dst = (u16 *) ((p->x20 - (((p->bB & 0xF) * hi) * 1024)) - 0x10);
    s32 j;
    for (j = 0; j < hi; j++)
    {
      if (tbl != 0)
      {
        s32 t = tbl[c[j]].hA + (D_001A1ED0_00394C58.x20 >> 8);
        dst[j] = t;
      }
      else
      {
        dst[j] = (D_001F3E40[c[j] * 3] >> 37) & 0x3FFF;
      }
    }
  }
  if (p->x28 != 0)
  {
    p->x28 = ((s32) p) + p->x28;
  }
  for (i = 0; i < p->bC; i++)
  {
    if (p->x48[i] != 0)
    {
      O_394C58 *o = (O_394C58 *) (((s32) p) + p->x48[i]);
      s32 j;
      p->x48[i] = (s32) o;
      if (p->b8 == 0)
      {
        if (o->b10 >= 2)
        {
          o->b10 = 1;
        }
      }
      if (o->x14 != 0)
      {
        o->x14 = ((s32) o) + o->x14;
      }
      for (j = 0; j < o->b10; j++)
      {
        o->x1C[j] = ((s32) p) + o->x1C[j];
      }

    }
  }

  if (d >= 0)
  {
    *(((u128_394C58 *) D_00200E70) + (*(D_001FDC50 + d))) = *((u128_394C58 *) c);
  }
  if (p->x0 != 0)
  {
    func_00423E10((s32 *)p->x0, (u8 *)b, c, n);
  }
  if (p->b47 == 0xFF)
  {
    p->b47 = 0;
  }
}
/* localdecomp:end func_00424048 */
