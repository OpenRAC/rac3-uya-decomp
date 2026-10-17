#include "common.h"

extern s32 func_00512828(s32, f32);
extern s32 func_00511E28(void *);
extern s32 func_00511368();
extern void *func_00511BF8();
extern s32 D_001DC0F8;

extern s32 func_00511E28(void *);
extern s32 func_00511368();
extern void *func_00511BF8();
extern s32 D_001DC0F8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2118;
extern S_003E2118 D_001E1660_003E2118;
extern u8 D_001E1690[];
s32 func_00512828(s32 arg0, f32 fa)
{
  s32 *base;
  unsigned char new_var;
  s32 (*cb)(void *, f32);
  s32 r;
  s32 t;
  void *p;
  S_003E2118 *q;
  r = 0;
  q = &D_001E1660_003E2118;
  if (q->f4 != 0)
  {
    base = (s32 *) q;
  }
  else
  {
    base = (s32 *) func_00511BF8(q);
  }
  p = (void *) func_00511368(func_00511E28(base), arg0);
  new_var = p == 0;
  if (new_var || ((*((s32 (**)(void *, s32)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0x10)))(p, D_001DC0F8) == 0))
  {
    p = 0;
  }
  if (p != 0)
  {
    t = (*((s32 (**)(void *)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0xC)))(p);
 do { } while (0);
    cb = (void *) func_00515798(D_001E1690, t);
    if (cb != 0)
    {
      r = cb(p, fa);
    }
  }
  return r;
}
