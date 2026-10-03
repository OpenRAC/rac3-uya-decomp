#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void *func_003E16B8();
extern void func_003E2D90();
extern s32 func_003E2E60();
extern s32 func_003E3040();
extern s32 func_003E28E0(s32, s32);
extern s32 func_003E24B0(s32 arg0, s32 arg1);
extern s32 func_003E23C0(s32, s32, s32);
extern s32 func_003E2C88(s32, f32, f32);
extern s32 func_003E24B0(s32, s32);
extern s32 func_003E1E50(s32, f32, f32);
extern s32 func_003E21F8(s32, f32);
extern s32 func_003E2808();
extern s32 func_003E2808(s32, s32);
extern s32 func_003E22D0(s32, s32, s32);
extern s32 func_003E0E28();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E1E38 */
extern s32 D_001D96F8;
void func_003E1E38(s32 a) {
    D_001D96F8 = a;
}
/* localdecomp:end func_003E1E38 */

/* localdecomp:start func_003E1E40 */
extern s32 D_001D96F8;
s32 func_003E1E40(void) {
    return D_001D96F8;
}
/* localdecomp:end func_003E1E40 */

/* localdecomp:start func_003E1E48 */
s32 func_003E1E48(void) {
}
/* localdecomp:end func_003E1E48 */

/* localdecomp:start func_003E1E50 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4790_003E1E50[];
extern s32 D_001D96A8_003E1E50;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E1E50;
extern S_003E1E50 D_001DA9B8_003E1E50;
extern u8 D_00317848_003E1E50[];
s32 func_003E1E50(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E1E50 *q;

    r = 0;
    q = &D_001DA9B8_003E1E50;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E1E50) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E4790_003E1E50)(D_00317848_003E1E50, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E1E50 */

LINKER_REMNANT("asm/remnants", func_003E1F38);

INCLUDE_ASM("asm/nonmatchings/text", func_003E1F40);

/* localdecomp:start func_003E2028 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4790_003E2028[];
extern s32 D_001D96A8_003E2028;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2028;
extern S_003E2028 D_001DA9B8_003E2028;
extern u8 D_003179F8_003E2028[];
s32 func_003E2028(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E2028 *q;

    r = 0;
    q = &D_001DA9B8_003E2028;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E2028) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E4790_003E2028)(D_003179F8_003E2028, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E2028 */

LINKER_REMNANT("asm/remnants", func_003E2110);

/* localdecomp:start func_003E2118 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4918_003E2118[];
extern s32 D_001D96A8_003E2118;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2118;
extern S_003E2118 D_001DA9B8_003E2118;
extern u8 D_001DA9E8_003E2118[];
s32 func_003E2118(s32 arg0, f32 fa)
{
  s32 *base;
  unsigned char new_var;
  s32 (*cb)(void *, f32);
  s32 r;
  s32 t;
  void *p;
  S_003E2118 *q;
  r = 0;
  q = &D_001DA9B8_003E2118;
  if (q->f4 != 0)
  {
    base = (s32 *) q;
  }
  else
  {
    base = (s32 *) func_003E16B8(q);
  }
  p = (void *) func_003E0E28(func_003E1898(base), arg0);
  new_var = p == 0;
  if (new_var || ((*((s32 (**)(void *, s32)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0x10)))(p, D_001D96A8_003E2118) == 0))
  {
    p = 0;
  }
  if (p != 0)
  {
    t = (*((s32 (**)(void *)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0xC)))(p);
 do { } while (0);
    cb = (void *) func_003E4918(D_001DA9E8_003E2118, t);
    if (cb != 0)
    {
      r = cb(p, fa);
    }
  }
  return r;
}
/* localdecomp:end func_003E2118 */

LINKER_REMNANT("asm/remnants", func_003E21F0);

/* localdecomp:start func_003E21F8 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E49A0_003E21F8[];
extern s32 D_001D96A8_003E21F8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E21F8;
extern S_003E21F8 D_001DA9B8_003E21F8;
extern u8 D_00317C38_003E21F8[];
s32 func_003E21F8(s32 arg0, f32 fa) {
    s32 *base;
    s32 (*cb)(void *, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E21F8 *q;

    r = 0;
    q = &D_001DA9B8_003E21F8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E21F8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E49A0_003E21F8)(D_00317C38_003E21F8, t);
        if (cb != 0) {
            r = cb(p, fa);
        }
    }
    return r;
}
/* localdecomp:end func_003E21F8 */

/* localdecomp:start func_003E22D0 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4A20_003E22D0[];
extern s32 D_001D96A8_003E22D0;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E22D0;
extern S_003E22D0 D_001DA9B8_003E22D0;
extern u8 D_00317C80_003E22D0[];
s32 func_003E22D0(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E22D0 *q;

    r = 0;
    q = &D_001DA9B8_003E22D0;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E22D0) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E4A20_003E22D0)(D_00317C80_003E22D0, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_003E22D0 */

LINKER_REMNANT("asm/remnants", func_003E23B8);

/* localdecomp:start func_003E23C0 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4A20_003E23C0[];
extern s32 D_001D96A8_003E23C0;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E23C0;
extern S_003E23C0 D_001DA9B8_003E23C0;
extern u8 D_00317D10_003E23C0[];
s32 func_003E23C0(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E23C0 *q;

    r = 0;
    q = &D_001DA9B8_003E23C0;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E23C0) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E4A20_003E23C0)(D_00317D10_003E23C0, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_003E23C0 */

LINKER_REMNANT("asm/remnants", func_003E24A8);

/* localdecomp:start func_003E24B0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E24B0;
extern S_003E24B0 D_001DA9B8_003E24B0[];
extern void *func_003E16B8();
extern s32 func_003E1898();
extern s32 func_003E0E28();
extern s32 D_001D9710;
extern void func_003E8568(void *p, s32, s32);
s32 func_003E24B0(s32 arg0, s32 arg1) {
    S_003E24B0 *q;
    S_003E24B0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA9B8_003E24B0;
    if (p->x4) q = p;
    else q = func_003E16B8(p);
    t = (void *)func_003E0E28(func_003E1898(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9710) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003E8568(v, 1, arg1);
    }
    return r;
}
/* localdecomp:end func_003E24B0 */

/* localdecomp:start func_003E2560 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E2560;
extern S_003E2560 D_001DA9B8_003E2560[];
extern void *func_003E16B8();
extern s32 func_003E1898();
extern s32 func_003E0E28();
extern s32 D_001D9710;
extern void func_003E8568(void *p, s32, s32);
s32 func_003E2560(s32 arg0, s32 arg1) {
    S_003E2560 *q;
    S_003E2560 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA9B8_003E2560;
    if (p->x4) q = p;
    else q = func_003E16B8(p);
    t = (void *)func_003E0E28(func_003E1898(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9710) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003E8568(v, 0x40, arg1);
    }
    return r;
}
/* localdecomp:end func_003E2560 */

LINKER_REMNANT("asm/remnants", func_003E2610);

/* localdecomp:start func_003E2618 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4BA0_003E2618[];
extern s32 D_001D96A8_003E2618;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2618;
extern S_003E2618 D_001DA9B8_003E2618;
extern u8 D_00317DA0_003E2618[];
s32 func_003E2618(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 *base;
    s32 (*cb)(void *, s32, s32, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2618 *q;

    r = 0;
    q = &D_001DA9B8_003E2618;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E2618) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E4BA0_003E2618)(D_00317DA0_003E2618, t);
        if (cb != 0) {
            r = cb(p, a1, a2, a3, a4);
        }
    }
    return r;
}
/* localdecomp:end func_003E2618 */

LINKER_REMNANT("asm/remnants", func_003E2720);

/* localdecomp:start func_003E2728 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4C20_003E2728[];
extern s32 D_001D96A8_003E2728;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_3E2728;
extern S_3E2728 D_001DA9B8_003E2728;
extern u8 D_00317920_003E2728[];
s32 func_003E2728(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_3E2728 *q;

    r = 0;
    q = &D_001DA9B8_003E2728;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E2728) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E4C20_003E2728)(D_00317920_003E2728, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_003E2728 */

LINKER_REMNANT("asm/remnants", func_003E2800);

/* localdecomp:start func_003E2808 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4D20_003E2808[];
extern s32 D_001D96A8_003E2808;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2808;
extern S_003E2808 D_001DA9B8_003E2808;
extern u8 D_003179B0_003E2808[];
s32 func_003E2808(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2808 *q;

    r = 0;
    q = &D_001DA9B8_003E2808;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E2808) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E4D20_003E2808)(D_003179B0_003E2808, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_003E2808 */

/* localdecomp:start func_003E28E0 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4D20_003E28E0[];
extern s32 D_001D96A8_003E28E0;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E28E0;
extern S_003E28E0 D_001DA9B8_003E28E0;
extern u8 D_00317AD0_003E28E0[];
s32 func_003E28E0(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E28E0 *q;

    r = 0;
    q = &D_001DA9B8_003E28E0;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E28E0) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E4D20_003E28E0)(D_00317AD0_003E28E0, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_003E28E0 */

/* localdecomp:start func_003E29B8 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern void *func_003E4DA0();
extern s32 D_001D96A8_003E29B8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E29B8;
extern S_003E29B8 D_001DA9B8_003E29B8;
extern u8 D_001DAA68_003E29B8[];
s32 func_003E29B8(s32 arg0, s32 arg1)
{
  s32 *base;
  s32 (*cb)(void *, s32);
  s32 r;
  s32 t;
  void *p;
  S_003E29B8 *q;
  r = 0;
  q = &D_001DA9B8_003E29B8;
  if (q->f4 != 0)
  {
    base = (s32 *) q;
  }
  else
  {
    base = (s32 *) func_003E16B8(q);
  }
  p = (void *) func_003E0E28(func_003E1898(base), arg0);
  if ((p == 0) || ((*((s32 (**)(void *, s32)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0x10)))(p, D_001D96A8_003E29B8) == 0))
  {
    p = 0;
  }
  if (p != 0)
  {
 do { t = (*((s32 (**)(void *)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0xC)))(p); } while (0);
    cb = (void *) func_003E4DA0(D_001DAA68_003E29B8, t);
    if (cb != 0)
    {
      r = cb(p, arg1);
    }
  }
  return r;
}
/* localdecomp:end func_003E29B8 */

/* localdecomp:start func_003E2A90 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4E28_003E2A90[];
extern s32 D_001D96A8_003E2A90;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2A90;
extern S_003E2A90 D_001DA9B8_003E2A90;
extern u8 D_00317DE8_003E2A90[];
s32 func_003E2A90(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 *base;
    s32 (*cb)(void *, s32, s32, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2A90 *q;

    r = 0;
    q = &D_001DA9B8_003E2A90;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E2A90) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E4E28_003E2A90)(D_00317DE8_003E2A90, t);
        if (cb != 0) {
            r = cb(p, a1, a2, a3, a4);
        }
    }
    return r;
}
/* localdecomp:end func_003E2A90 */

/* localdecomp:start func_003E2B98 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4EA8_003E2B98[];
extern s32 D_001D96A8_003E2B98;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2B98;
extern S_003E2B98 D_001DA9B8_003E2B98;
extern u8 D_00317BF0_003E2B98[];
s32 func_003E2B98(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2B98 *q;

    r = 0;
    q = &D_001DA9B8_003E2B98;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E2B98) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E4EA8_003E2B98)(D_00317BF0_003E2B98, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_003E2B98 */

LINKER_REMNANT("asm/remnants", func_003E2C80);

/* localdecomp:start func_003E2C88 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4790_003E2C88[];
extern s32 D_001D96A8_003E2C88;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2C88;
extern S_003E2C88 D_001DA9B8_003E2C88;
extern u8 D_003178D8_003E2C88[];
s32 func_003E2C88(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E2C88 *q;

    r = 0;
    q = &D_001DA9B8_003E2C88;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E2C88) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E4790_003E2C88)(D_003178D8_003E2C88, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E2C88 */

LINKER_REMNANT("asm/remnants", func_003E2D70);

/* localdecomp:start func_003E2D90 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2D90;
extern S_3E2D90 D_001DA9B8_003E2D90;
extern void *func_003E16B8();
extern void func_003E18C0();
void func_003E2D90(s32 a) {
    S_3E2D90 *q;
    if (D_001DA9B8_003E2D90.x4) q = &D_001DA9B8_003E2D90;
    else q = func_003E16B8(&D_001DA9B8_003E2D90);
    func_003E18C0(q, a);
}
/* localdecomp:end func_003E2D90 */

LINKER_REMNANT("asm/remnants", func_003E2DD8);

/* localdecomp:start func_003E2DE0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2DE0;
extern S_3E2DE0 D_001DA9B8_003E2DE0;
extern void *func_003E16B8();
extern s32 func_003E1898();
extern s32 func_003E0798(s32, s32, s32);
s32 func_003E2DE0(s32 a, s32 b) {
    S_3E2DE0 *q;
    s32 r = 0;
    s32 t;
    if (D_001DA9B8_003E2DE0.x4) q = &D_001DA9B8_003E2DE0;
    else q = func_003E16B8(&D_001DA9B8_003E2DE0);
    t = func_003E1898(q);
    if (t) r = func_003E0798(t, a, b);
    return r;
}
/* localdecomp:end func_003E2DE0 */

/* localdecomp:start func_003E2E60 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2E60;
extern S_3E2E60 D_001DA9B8_003E2E60;
extern void *func_003E16B8();
extern s32 func_003E1898();
extern s32 func_003E0D78();
s32 func_003E2E60(s32 a) {
    S_3E2E60 *q;
    s32 r = 0;
    s32 t;
    if (D_001DA9B8_003E2E60.x4) q = &D_001DA9B8_003E2E60;
    else q = func_003E16B8(&D_001DA9B8_003E2E60);
    t = func_003E1898(q);
    if (t) r = func_003E0D78(t, a);
    return r;
}
/* localdecomp:end func_003E2E60 */

LINKER_REMNANT("asm/remnants", func_003E2ED0);

/* localdecomp:start func_003E2ED8 */
extern s32 func_003E0CC0(s32, s32);
s32 *func_003E16B8_003E2ED8(s32 *);                  /* extern */
s32 func_003E1898_003E2ED8(s32 *);                       /* extern */
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E2ED8;
extern S_001DA9B8_003E2ED8 D_001DA9B8_003E2ED8[];

s32 func_003E2ED8(s32 arg0) {
    s32 *var_v0;
    s32 temp_v0;
    s32 var_s1;

    var_s1 = -1;
    if (D_001DA9B8_003E2ED8->f4 != 0) {
        var_v0 = D_001DA9B8_003E2ED8;
    } else {
        var_v0 = func_003E16B8_003E2ED8(D_001DA9B8_003E2ED8);
    }
    temp_v0 = func_003E1898_003E2ED8(var_v0);
    if (temp_v0 != 0) {
        var_s1 = func_003E0CC0(temp_v0, arg0);
    }
    return var_s1;
}
/* localdecomp:end func_003E2ED8 */

/* localdecomp:start func_003E2F48 */
typedef struct { s32 a; s32 b; } S_3E2F48;
extern S_3E2F48 D_001DA9B8_003E2F48[];
extern void *func_003E16B8();
extern s32 func_003E1898();
extern s32 func_003E0E48(void *, s32);
static inline S_3E2F48 *get_3E2F48(void) {
    S_3E2F48 *p = D_001DA9B8_003E2F48;
    if (p->b != 0) return p;
    return func_003E16B8();
}
s32 func_003E2F48(s32 a) {
    s32 r = 0;
    void *q = func_003E1898(get_3E2F48());
    if (q != 0) r = func_003E0E48(q, a);
    return r;
}
/* localdecomp:end func_003E2F48 */

LINKER_REMNANT("asm/remnants", func_003E2FB8);

/* localdecomp:start func_003E2FC0 */
s32 func_003E0780_003E2FC0(s32, s32);                        /* extern */
s32 *func_003E16B8_003E2FC0(s32 *);                  /* extern */
s32 func_003E1898_003E2FC0(s32 *);                       /* extern */
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E2FC0;
extern S_001DA9B8_003E2FC0 D_001DA9B8_003E2FC0[];

s32 func_003E2FC0(s32 arg0, s32 *arg1) {
    s32 *var_v0;
    s32 temp_v0;
    s32 var_s2;

    var_s2 = 0;
    if (D_001DA9B8_003E2FC0->f4 != 0) {
        var_v0 = D_001DA9B8_003E2FC0;
    } else {
        var_v0 = func_003E16B8_003E2FC0(D_001DA9B8_003E2FC0);
    }
    temp_v0 = func_003E1898_003E2FC0(var_v0);
    if (temp_v0 != 0) {
        var_s2 = 1;
        *arg1 = func_003E0780_003E2FC0(temp_v0, arg0);
    }
    return var_s2;
}
/* localdecomp:end func_003E2FC0 */

/* localdecomp:start func_003E3040 */
typedef struct { s32 a; s32 b; } S_3E3040;
extern S_3E3040 D_001DA9B8_003E3040[];
extern void *func_003E16B8();
extern s32 func_003E1898();
extern void func_003E0870(void *, s32);
s32 func_003E3040(s32 a) {
    S_3E3040 *p = D_001DA9B8_003E3040;
    void *q;
    s32 r = 0;
    { S_3E3040 *t; if (p->b != 0) t = p; else t = func_003E16B8(); q = func_003E1898(t); }
    if (q) { func_003E0870(q, a); r = 1; }
    return r;
}
/* localdecomp:end func_003E3040 */

LINKER_REMNANT("asm/remnants", func_003E30B0);

/* localdecomp:start func_003E30C8 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern u8 func_003E4D20_003E30C8[];
extern s32 D_001D96A8_003E30C8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E30C8;
extern S_003E30C8 D_001DA9B8_003E30C8;
extern u8 D_00317B18_003E30C8[];
s32 func_003E30C8(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E30C8 *q;

    r = 0;
    q = &D_001DA9B8_003E30C8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8_003E30C8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E4D20_003E30C8)(D_00317B18_003E30C8, t);
        if (cb != 0) {
            r = cb(p, arg1);
        } else {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_003E30C8 */

/* localdecomp:start func_003E31A8 */
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern void *func_003E16B8();
extern s32 D_001D97A0_003E31A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E31A8;
extern S_003E31A8 D_001DA9B8_003E31A8;
s32 func_003E31A8(s32 arg0, s32 arg1) {
    s32 *base;
    s32 r;
    void *p;
    void *o;
    S_003E31A8 *q;

    r = 0;
    q = &D_001DA9B8_003E31A8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (void *)func_003E0E28(func_003E1898(base), arg0);
    o = (p != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D97A0_003E31A8) != 0) ? p : 0;
    if (o != 0) {
        *(s32 *)((u8 *)o + 0x50) = arg1;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003E31A8 */

/* localdecomp:start func_003E3250 */
void *func_003E0E28_003E3250(s32, s32);                      /* extern */
s32 *func_003E16B8_003E3250(s32 *);                  /* extern */
s32 func_003E1898_003E3250(s32 *);                       /* extern */
s32 func_003E22D0(s32, s32, s32);
void func_003EA930_003E3250(void *, s32);
extern s32 D_001D97A0_003E3250;
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E3250;
extern S_001DA9B8_003E3250 D_001DA9B8_003E3250[];

s32 func_003E3250(s32 arg0, s32 arg1, s32 arg2) {
    s32 *var_v0;
    s32 var_s4;
    void *var_s0;

    var_s4 = 0;
    if (D_001DA9B8_003E3250->f4 != 0) {
        var_v0 = D_001DA9B8_003E3250;
    } else {
        var_v0 = func_003E16B8_003E3250(D_001DA9B8_003E3250);
    }
    var_s0 = func_003E0E28_003E3250(func_003E1898_003E3250(var_v0), arg0);
    if ((var_s0 == 0) || ((*(s32 (**)(void *, s32))((u8 *)((*(void **)((u8 *)(var_s0) + 8))) + 0x10))(var_s0, D_001D97A0_003E3250) == 0)) {
        var_s0 = 0;
    }
    if (var_s0 != 0) {
        var_s4 = 1;
        func_003E22D0(arg0, 0x8000, arg1);
        func_003EA930_003E3250(var_s0, arg2);
    }
    return var_s4;
}
/* localdecomp:end func_003E3250 */

LINKER_REMNANT("asm/remnants", func_003E3320);

/* localdecomp:start func_003E3330 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E3330;
extern S_003E3330 D_001DA9B8_003E3330[];
extern void *func_003E16B8();
extern s32 func_003E1898();
extern s32 func_003E0E28();
extern s32 D_001D97D0_003E3330;
extern void func_003EAA80(void *p, f32, f32);
s32 func_003E3330(s32 arg0, f32 fparg0, f32 fparg1) {
    S_003E3330 *q;
    S_003E3330 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA9B8_003E3330;
    if (p->x4) q = p;
    else q = func_003E16B8(p);
    t = (void *)func_003E0E28(func_003E1898(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D97D0_003E3330) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EAA80(v, fparg0, fparg1);
    }
    return r;
}
/* localdecomp:end func_003E3330 */

LINKER_REMNANT("asm/remnants", func_003E33E8);

/* localdecomp:start func_003E33F0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E33F0;
extern S_003E33F0 D_001DA9B8_003E33F0[];
extern void *func_003E16B8();
extern s32 func_003E1898();
extern s32 func_003E0E28();
extern s32 D_001D97D0_003E33F0;
extern void func_003EAA38(u8 *p, u8, s32);
s32 func_003E33F0(s32 arg0, s32 arg1) {
    S_003E33F0 *q;
    S_003E33F0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA9B8_003E33F0;
    if (p->x4) q = p;
    else q = func_003E16B8(p);
    t = (void *)func_003E0E28(func_003E1898(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D97D0_003E33F0) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EAA38(v, 1, arg1);
    }
    return r;
}
/* localdecomp:end func_003E33F0 */

/* localdecomp:start func_003E34A0 */
s32 func_003E30C8(s32, s32);
s32 func_003E34A0(s32 a, s32 b, s32 c) {
    s32 x = func_003E30C8(a, b) != 0;
    s32 y = func_003E30C8(a, c) != 0;
    return x & y;
}
/* localdecomp:end func_003E34A0 */

/* localdecomp:start func_003E34F0 */
extern s32 func_003E30C8();
s32 func_003E34F0(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 r;
    s32 t;
    r = func_003E30C8(a, b) != 0;
    t = func_003E30C8(a, c) != 0;
    r = r & t;
    t = func_003E30C8(a, d) != 0;
    r = r & t;
    t = func_003E30C8(a, e) != 0;
    return r & t;
}
/* localdecomp:end func_003E34F0 */

/* localdecomp:start func_003E3580 */
extern s32 func_003E30C8();
s32 func_003E3580(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 r;
    s32 t;
    r = func_003E30C8(a, b) != 0;
    t = func_003E30C8(a, c) != 0;
    r = r & t;
    t = func_003E30C8(a, d) != 0;
    r = r & t;
    t = func_003E30C8(a, e) != 0;
    r = r & t;
    t = func_003E30C8(a, f) != 0;
    return r & t;
}
/* localdecomp:end func_003E3580 */

/* localdecomp:start func_003E3630 */
extern s32 func_003E30C8();
s32 func_003E3630(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    s32 r;
    s32 t;
    r = func_003E30C8(a, b) != 0;
    t = func_003E30C8(a, c) != 0;
    r = r & t;
    t = func_003E30C8(a, d) != 0;
    r = r & t;
    t = func_003E30C8(a, e) != 0;
    r = r & t;
    t = func_003E30C8(a, f) != 0;
    r = r & t;
    t = func_003E30C8(a, g) != 0;
    return r & t;
}
/* localdecomp:end func_003E3630 */

/* localdecomp:start func_003E3700 */
extern s32 func_003E30C8(s32, s32);
s32 func_003E3700(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s32 r;
    s32 t;
    r = func_003E30C8(a0, a1) != 0;
    t = func_003E30C8(a0, a2) != 0; r = r & t;
    t = func_003E30C8(a0, a3) != 0; r = r & t;
    t = func_003E30C8(a0, a4) != 0; r = r & t;
    t = func_003E30C8(a0, a5) != 0; r = r & t;
    t = func_003E30C8(a0, a6) != 0; r = r & t;
    t = func_003E30C8(a0, a7) != 0; r = r & t;
    return r;
}
/* localdecomp:end func_003E3700 */

/* localdecomp:start func_003E37F0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E37F0;
extern S_003E37F0 D_001DA9B8_003E37F0[];
extern void *func_003E16B8();
extern s32 func_003E1898();
extern s32 func_003E0E28();
extern s32 D_001D9740_003E37F0;
extern void func_003E8BF8(void *p, s32, s32);
s32 func_003E37F0(s32 arg0, s32 arg1, s32 arg2) {
    S_003E37F0 *q;
    S_003E37F0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA9B8_003E37F0;
    if (p->x4) q = p;
    else q = func_003E16B8(p);
    t = (void *)func_003E0E28(func_003E1898(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9740_003E37F0) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003E8BF8(v, arg1, arg2);
    }
    return r;
}
/* localdecomp:end func_003E37F0 */

LINKER_REMNANT("asm/remnants", func_003E38A8);

/* localdecomp:start func_003E38B0 */
extern s32 func_003E37F0(s32 arg0, s32 arg1, s32 arg2);
 
void func_003E38B0(void *p, s32 arg1) {
    func_003E37F0(p, 1, arg1);
}
/* localdecomp:end func_003E38B0 */

/* localdecomp:start func_003E38D0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E38D0;
extern S_003E38D0 D_001DA9B8_003E38D0[];
extern void *func_003E16B8();
extern s32 func_003E1898();
extern s32 func_003E0E28();
extern s32 D_001D9800_003E38D0;
extern s32 func_003EB620(u8 *arg0, s32, s32);
s32 func_003E38D0(s32 arg0, s32 arg1, s32 arg2) {
    S_003E38D0 *q;
    S_003E38D0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA9B8_003E38D0;
    if (p->x4) q = p;
    else q = func_003E16B8(p);
    t = (void *)func_003E0E28(func_003E1898(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9800_003E38D0) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EB620(v, arg1, arg2);
    }
    return r;
}
/* localdecomp:end func_003E38D0 */

/* localdecomp:start func_003E3988 */
extern s32 func_003DFB40_003E3988();
extern s32 func_0038E1E0_003E3988();
extern s32 func_003E2B98_003E3988(s32, s32, s32);
extern s32 func_003E2808_003E3988(s32, s32);
extern s32 func_003E2C88_003E3988(s32, f32, f32);
extern s32 func_003E1E50_003E3988(s32, f32, f32);
extern s32 func_003E21F8_003E3988(s32, f32);
s32 func_003E3988(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w, f32 u) {
    s32 f = func_003DFB40_003E3988(a);
    s32 ok = func_003E2B98_003E3988(a, func_0038E1E0_003E3988(), b) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E2808_003E3988(a, c) != 0;
    ok = ok & t;
    t = func_003E2C88_003E3988(a, z, w) != 0;
    ok = ok & t;
    t = func_003E1E50_003E3988(a, x, y) != 0;
    ok = ok & t;
    t = func_003E21F8_003E3988(a, u) != 0;
    return ok & t;
}
/* localdecomp:end func_003E3988 */

/* localdecomp:start func_003E3A80 */
extern s32 func_003DFE10_003E3A80();
extern s32 func_003E2728_003E3A80(s32, s32);
extern s32 func_003E2808_003E3A80(s32, s32);
extern s32 func_003E2C88_003E3A80(s32, f32, f32);
extern s32 func_003E1E50_003E3A80(s32, f32, f32);
s32 func_003E3A80(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    s32 f = func_003DFE10_003E3A80(a);
    s32 ok = func_003E2728_003E3A80(a, b) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E2808_003E3A80(a, c) != 0;
    ok = ok & t;
    t = func_003E2C88_003E3A80(a, z, w) != 0;
    ok = ok & t;
    t = func_003E1E50_003E3A80(a, x, y) != 0;
    return ok & t;
}
/* localdecomp:end func_003E3A80 */

/* localdecomp:start func_003E3B50 */
extern s32 func_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E2028(s32, f32, f32);
s32 func_003E3B50(s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i) {
    s32 r;
    s32 t;
    s32 u;
    u = func_003E3A80(a, b, c, d, e, f, g);
    r = func_003E2028(a, h, i) != 0;
    if (u == 0) r = 0;
    t = ((s32 (*)(s32, s32, s32))func_003E22D0)(a, 0x40, 1) != 0;
    return r & t;
}
/* localdecomp:end func_003E3B50 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E3BD0);

/* localdecomp:start func_003E3D08 */
extern s32 func_003E50A8_003E3D08();
extern s32 func_003E1E50_003E3D08(s32, f32, f32);
extern s32 func_003E2808_003E3D08(s32, s32);
extern s32 func_003E2C88_003E3D08(s32, f32, f32);
extern s32 func_003E1F40_003E3D08(s32, f32, f32);
s32 func_003E3D08(s32 a, s32 b, f32 x, f32 y, f32 z, f32 w, f32 u, f32 v) {
    s32 f = func_003E50A8_003E3D08(a);
    s32 ok = func_003E1E50_003E3D08(a, x, y) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E2808_003E3D08(a, b) != 0;
    ok = ok & t;
    t = func_003E2C88_003E3D08(a, z, w) != 0;
    ok = ok & t;
    t = func_003E1F40_003E3D08(a, u, v) != 0;
    return ok & t;
}
/* localdecomp:end func_003E3D08 */

/* localdecomp:start func_003E3DF0 */
extern s32 func_003E5210_003E3DF0();
extern s32 func_003E1E50_003E3DF0(s32, f32, f32);
extern s32 func_003E2808_003E3DF0(s32, s32);
extern s32 func_003E2C88_003E3DF0(s32, f32, f32);
extern s32 func_003E2728_003E3DF0(s32, s32);
extern s32 func_003E2118_003E3DF0(s32, f32);
s32 func_003E3DF0(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w, f32 u) {
    s32 f = func_003E5210_003E3DF0(a);
    s32 ok = func_003E1E50_003E3DF0(a, x, y) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E2808_003E3DF0(a, c) != 0;
    ok = ok & t;
    t = func_003E2C88_003E3DF0(a, z, w) != 0;
    ok = ok & t;
    t = func_003E2728_003E3DF0(a, b) != 0;
    ok = ok & t;
    t = func_003E2118_003E3DF0(a, u) != 0;
    return ok & t;
}
/* localdecomp:end func_003E3DF0 */

/* localdecomp:start func_003E3EE8 */
extern void func_003AFAA8();
 
void func_003E3EE8(void) {
    func_003AFAA8();
}
/* localdecomp:end func_003E3EE8 */

/* localdecomp:start func_003E3F08 */
__asm__(".extern D_001D96FC_003E3F08, 1");
extern u8 D_001D96FC_003E3F08;
extern s32 D_001D9740_003E3F08;
extern s32 D_001D9770_003E3F08;
extern s32 D_001D97A0_003E3F08;
extern s32 D_001D97D0_003E3F08;
extern s32 D_001D9800_003E3F08;
extern s32 D_001D9830_003E3F08;
extern s32 D_001DA9C8_003E3F08[2];
extern s32 D_001DA9E8_003E3F08[2];
extern s32 D_001DAA08_003E3F08[2];
extern s32 D_001DAA28_003E3F08[2];
extern s32 D_001DAA48_003E3F08[2];
extern s32 D_001DAA68_003E3F08[2];
extern u8 D_00317848_003E3F08[];
extern u8 D_00317890_003E3F08[];
extern u8 D_003178D8_003E3F08[];
extern u8 D_00317920_003E3F08[];
extern u8 D_00317968_003E3F08[];
extern u8 D_003179B0_003E3F08[];
extern u8 D_003179F8_003E3F08[];
extern u8 D_00317A40_003E3F08[];
extern u8 D_00317A88_003E3F08[];
extern u8 D_00317AD0_003E3F08[];
extern u8 D_00317B18_003E3F08[];
extern u8 D_00317B60_003E3F08[];
extern u8 D_00317BA8_003E3F08[];
extern u8 D_00317BF0_003E3F08[];
extern u8 D_00317C38_003E3F08[];
extern u8 D_00317C80_003E3F08[];
extern u8 D_00317CC8_003E3F08[];
extern u8 D_00317D10_003E3F08[];
extern u8 D_00317D58_003E3F08[];
extern u8 D_00317DA0_003E3F08[];
extern u8 D_00317DE8_003E3F08[];
extern u8 D_00317E30_003E3F08[];
extern s32 func_003E53E0_003E3F08(void *, s32, void *);
extern s32 func_003E5518_003E3F08(void *, s32, void *);
extern s32 func_003E5638_003E3F08(void *, s32, void *);
extern s32 func_003E57C0_003E3F08(void *, s32, void *);
extern s32 func_003E58F8_003E3F08(void *, s32, void *);
extern s32 func_003E5A30_003E3F08(void *, s32, void *);
extern s32 func_003E5BD0_003E3F08(void *, s32, void *);
extern s32 func_003E5DE0_003E3F08(void *, s32, void *);
extern s32 func_003E5F00_003E3F08(void *, s32, void *);
extern s32 func_003E6198_003E3F08(void *, s32, void *);
extern s32 func_003E6680_003E3F08(void *, s32, void *);
extern s32 func_003E67B8_003E3F08(void *, s32, void *);
extern s32 func_003E69B8_003E3F08(void *, s32, void *);
extern s32 func_003E70B0_003E3F08(void *, s32, void *);
extern s32 func_003E71D8_003E3F08(void *, s32, void *);
extern s32 func_003E7960_003E3F08(void *, s32, void *);
extern s32 func_003E7DF8_003E3F08(void *, s32, void *);
extern s32 func_003E7F70_003E3F08(void *, s32, void *);
extern u8 func_003E5378_003E3F08[];
extern u8 func_003E54B0_003E3F08[];
extern u8 func_003E55E8_003E3F08[];
extern u8 func_003E5708_003E3F08[];
extern u8 func_003E5770_003E3F08[];
extern u8 func_003E5890_003E3F08[];
extern u8 func_003E59C8_003E3F08[];
extern u8 func_003E5B00_003E3F08[];
extern u8 func_003E5B68_003E3F08[];
extern u8 func_003E5CA0_003E3F08[];
extern u8 func_003E5D08_003E3F08[];
extern u8 func_003E5EB0_003E3F08[];
extern u8 func_003E5FD8_003E3F08[];
extern u8 func_003E6048_003E3F08[];
extern u8 func_003E60B0_003E3F08[];
extern u8 func_003E6108_003E3F08[];
extern u8 func_003E6268_003E3F08[];
extern u8 func_003E62D8_003E3F08[];
extern u8 func_003E6330_003E3F08[];
extern u8 func_003E6398_003E3F08[];
extern u8 func_003E6400_003E3F08[];
extern u8 func_003E6468_003E3F08[];
extern u8 func_003E64D0_003E3F08[];
extern u8 func_003E6538_003E3F08[];
extern u8 func_003E6610_003E3F08[];
extern u8 func_003E6758_003E3F08[];
extern u8 func_003E6890_003E3F08[];
extern u8 func_003E68F0_003E3F08[];
extern u8 func_003E6960_003E3F08[];
extern u8 func_003E6A88_003E3F08[];
extern u8 func_003E6AF0_003E3F08[];
extern u8 func_003E6B48_003E3F08[];
extern u8 func_003E6BB0_003E3F08[];
extern u8 func_003E6C18_003E3F08[];
extern u8 func_003E6C80_003E3F08[];
extern u8 func_003E6CE8_003E3F08[];
extern u8 func_003E6D48_003E3F08[];
extern u8 func_003E6DB0_003E3F08[];
extern u8 func_003E6E18_003E3F08[];
extern u8 func_003E6E80_003E3F08[];
extern u8 func_003E6EE8_003E3F08[];
extern u8 func_003E6F50_003E3F08[];
extern u8 func_003E7028_003E3F08[];
extern u8 func_003E7180_003E3F08[];
extern u8 func_003E72A8_003E3F08[];
extern u8 func_003E7310_003E3F08[];
extern u8 func_003E7378_003E3F08[];
extern u8 func_003E73E0_003E3F08[];
extern u8 func_003E7430_003E3F08[];
extern u8 func_003E7498_003E3F08[];
extern u8 func_003E7500_003E3F08[];
extern u8 func_003E7568_003E3F08[];
extern u8 func_003E75D0_003E3F08[];
extern u8 func_003E7638_003E3F08[];
extern u8 func_003E7710_003E3F08[];
extern u8 func_003E7778_003E3F08[];
extern u8 func_003E77E0_003E3F08[];
extern u8 func_003E7848_003E3F08[];
extern u8 func_003E78B0_003E3F08[];
extern u8 func_003E7900_003E3F08[];
extern u8 func_003E7A30_003E3F08[];
extern u8 func_003E7A98_003E3F08[];
extern u8 func_003E7B00_003E3F08[];
extern u8 func_003E7B68_003E3F08[];
extern u8 func_003E7BD0_003E3F08[];
extern u8 func_003E7C38_003E3F08[];
extern u8 func_003E7C90_003E3F08[];
extern u8 func_003E7D68_003E3F08[];
extern u8 func_003E7EC8_003E3F08[];
extern u8 func_003E7F20_003E3F08[];
extern u8 func_003E8040_003E3F08[];
extern u8 func_003E80A8_003E3F08[];
extern u8 func_003E8110_003E3F08[];
extern u8 func_003E8178_003E3F08[];
extern u8 func_003E81E0_003E3F08[];
extern u8 func_003E8248_003E3F08[];
extern u8 func_003E82B8_003E3F08[];
extern u8 func_003E8320_003E3F08[];

s32 func_003E3F08(void) {
    if (D_001D96FC_003E3F08 == 0) {
        D_001D96FC_003E3F08 = 1;
        func_003E53E0_003E3F08(D_00317848_003E3F08, D_001D97D0_003E3F08, func_003E5378_003E3F08);
        func_003E5518_003E3F08(D_00317890_003E3F08, D_001D97D0_003E3F08, func_003E54B0_003E3F08);
        func_003E5638_003E3F08(D_00317920_003E3F08, D_001D97D0_003E3F08, func_003E55E8_003E3F08);
        func_003E53E0_003E3F08(D_003178D8_003E3F08, D_001D97D0_003E3F08, func_003E5708_003E3F08);
        func_003E57C0_003E3F08(D_003179B0_003E3F08, D_001D97D0_003E3F08, func_003E5770_003E3F08);
        func_003E58F8_003E3F08(D_00317C80_003E3F08, D_001D97D0_003E3F08, func_003E5890_003E3F08);
        func_003E5A30_003E3F08(D_00317CC8_003E3F08, D_001D97D0_003E3F08, func_003E59C8_003E3F08);
        func_003E58F8_003E3F08(D_00317D10_003E3F08, D_001D97D0_003E3F08, func_003E5B00_003E3F08);
        func_003E5BD0_003E3F08(D_00317D58_003E3F08, D_001D97D0_003E3F08, func_003E5B68_003E3F08);
        func_003E53E0_003E3F08(D_003179F8_003E3F08, D_001D97D0_003E3F08, func_003E5CA0_003E3F08);
        func_003E5DE0_003E3F08(D_00317DA0_003E3F08, D_001D97D0_003E3F08, func_003E5D08_003E3F08);
        func_003E5F00_003E3F08(D_001DAA68_003E3F08, D_001D97D0_003E3F08, func_003E5EB0_003E3F08);
        func_003E53E0_003E3F08(D_00317848_003E3F08, D_001D9800_003E3F08, func_003E5FD8_003E3F08);
        func_003E5518_003E3F08(D_00317890_003E3F08, D_001D9800_003E3F08, func_003E6048_003E3F08);
        func_003E5638_003E3F08(D_00317920_003E3F08, D_001D9800_003E3F08, func_003E60B0_003E3F08);
        func_003E6198_003E3F08(D_00317968_003E3F08, D_001D9800_003E3F08, func_003E6108_003E3F08);
        func_003E53E0_003E3F08(D_003178D8_003E3F08, D_001D9800_003E3F08, func_003E6268_003E3F08);
        func_003E57C0_003E3F08(D_003179B0_003E3F08, D_001D9800_003E3F08, func_003E62D8_003E3F08);
        func_003E58F8_003E3F08(D_00317C80_003E3F08, D_001D9800_003E3F08, func_003E6330_003E3F08);
        func_003E5A30_003E3F08(D_00317CC8_003E3F08, D_001D9800_003E3F08, func_003E6398_003E3F08);
        func_003E58F8_003E3F08(D_00317D10_003E3F08, D_001D9800_003E3F08, func_003E6400_003E3F08);
        func_003E5BD0_003E3F08(D_00317D58_003E3F08, D_001D9800_003E3F08, func_003E6468_003E3F08);
        func_003E53E0_003E3F08(D_003179F8_003E3F08, D_001D9800_003E3F08, func_003E64D0_003E3F08);
        func_003E5DE0_003E3F08(D_00317DA0_003E3F08, D_001D9800_003E3F08, func_003E6538_003E3F08);
        func_003E6680_003E3F08(D_001DA9C8_003E3F08, D_001D9800_003E3F08, func_003E6610_003E3F08);
        func_003E67B8_003E3F08(D_001DA9E8_003E3F08, D_001D9800_003E3F08, func_003E6758_003E3F08);
        func_003E67B8_003E3F08(D_001DAA08_003E3F08, D_001D9800_003E3F08, func_003E6890_003E3F08);
        func_003E6680_003E3F08(D_001DAA28_003E3F08, D_001D9800_003E3F08, func_003E68F0_003E3F08);
        func_003E69B8_003E3F08(D_00317A40_003E3F08, D_001D9800_003E3F08, func_003E6960_003E3F08);
        func_003E5518_003E3F08(D_00317A88_003E3F08, D_001D9800_003E3F08, func_003E6A88_003E3F08);
        func_003E5F00_003E3F08(D_001DAA68_003E3F08, D_001D9800_003E3F08, func_003E6AF0_003E3F08);
        func_003E53E0_003E3F08(D_00317848_003E3F08, D_001D97A0_003E3F08, func_003E6B48_003E3F08);
        func_003E5518_003E3F08(D_00317890_003E3F08, D_001D97A0_003E3F08, func_003E6BB0_003E3F08);
        func_003E53E0_003E3F08(D_003178D8_003E3F08, D_001D97A0_003E3F08, func_003E6C18_003E3F08);
        func_003E57C0_003E3F08(D_003179B0_003E3F08, D_001D97A0_003E3F08, func_003E6C80_003E3F08);
        func_003E57C0_003E3F08(D_00317AD0_003E3F08, D_001D97A0_003E3F08, func_003E6CE8_003E3F08);
        func_003E58F8_003E3F08(D_00317C80_003E3F08, D_001D97A0_003E3F08, func_003E6D48_003E3F08);
        func_003E5A30_003E3F08(D_00317CC8_003E3F08, D_001D97A0_003E3F08, func_003E6DB0_003E3F08);
        func_003E58F8_003E3F08(D_00317D10_003E3F08, D_001D97A0_003E3F08, func_003E6E18_003E3F08);
        func_003E5BD0_003E3F08(D_00317D58_003E3F08, D_001D97A0_003E3F08, func_003E6E80_003E3F08);
        func_003E53E0_003E3F08(D_003179F8_003E3F08, D_001D97A0_003E3F08, func_003E6EE8_003E3F08);
        func_003E5DE0_003E3F08(D_00317DA0_003E3F08, D_001D97A0_003E3F08, func_003E6F50_003E3F08);
        func_003E70B0_003E3F08(D_00317DE8_003E3F08, D_001D97A0_003E3F08, func_003E7028_003E3F08);
        func_003E71D8_003E3F08(D_00317E30_003E3F08, D_001D97A0_003E3F08, func_003E7180_003E3F08);
        func_003E53E0_003E3F08(D_00317848_003E3F08, D_001D9770_003E3F08, func_003E72A8_003E3F08);
        func_003E5518_003E3F08(D_00317890_003E3F08, D_001D9770_003E3F08, func_003E7310_003E3F08);
        func_003E53E0_003E3F08(D_003178D8_003E3F08, D_001D9770_003E3F08, func_003E7378_003E3F08);
        func_003E57C0_003E3F08(D_003179B0_003E3F08, D_001D9770_003E3F08, func_003E73E0_003E3F08);
        func_003E58F8_003E3F08(D_00317C80_003E3F08, D_001D9770_003E3F08, func_003E7430_003E3F08);
        func_003E5A30_003E3F08(D_00317CC8_003E3F08, D_001D9770_003E3F08, func_003E7498_003E3F08);
        func_003E58F8_003E3F08(D_00317D10_003E3F08, D_001D9770_003E3F08, func_003E7500_003E3F08);
        func_003E5BD0_003E3F08(D_00317D58_003E3F08, D_001D9770_003E3F08, func_003E7568_003E3F08);
        func_003E53E0_003E3F08(D_003179F8_003E3F08, D_001D9770_003E3F08, func_003E75D0_003E3F08);
        func_003E5DE0_003E3F08(D_00317DA0_003E3F08, D_001D9770_003E3F08, func_003E7638_003E3F08);
        func_003E6680_003E3F08(D_001DAA48_003E3F08, D_001D9770_003E3F08, func_003E7710_003E3F08);
        func_003E53E0_003E3F08(D_00317848_003E3F08, D_001D9830_003E3F08, func_003E7778_003E3F08);
        func_003E5518_003E3F08(D_00317890_003E3F08, D_001D9830_003E3F08, func_003E77E0_003E3F08);
        func_003E53E0_003E3F08(D_003178D8_003E3F08, D_001D9830_003E3F08, func_003E7848_003E3F08);
        func_003E57C0_003E3F08(D_003179B0_003E3F08, D_001D9830_003E3F08, func_003E78B0_003E3F08);
        func_003E7960_003E3F08(D_00317BF0_003E3F08, D_001D9830_003E3F08, func_003E7900_003E3F08);
        func_003E58F8_003E3F08(D_00317C80_003E3F08, D_001D9830_003E3F08, func_003E7A30_003E3F08);
        func_003E5A30_003E3F08(D_00317CC8_003E3F08, D_001D9830_003E3F08, func_003E7A98_003E3F08);
        func_003E58F8_003E3F08(D_00317D10_003E3F08, D_001D9830_003E3F08, func_003E7B00_003E3F08);
        func_003E5BD0_003E3F08(D_00317D58_003E3F08, D_001D9830_003E3F08, func_003E7B68_003E3F08);
        func_003E53E0_003E3F08(D_003179F8_003E3F08, D_001D9830_003E3F08, func_003E7BD0_003E3F08);
        func_003E71D8_003E3F08(D_00317C38_003E3F08, D_001D9830_003E3F08, func_003E7C38_003E3F08);
        func_003E5DE0_003E3F08(D_00317DA0_003E3F08, D_001D9830_003E3F08, func_003E7C90_003E3F08);
        func_003E7DF8_003E3F08(D_00317BA8_003E3F08, D_001D9740_003E3F08, func_003E7D68_003E3F08);
        func_003E57C0_003E3F08(D_00317B18_003E3F08, D_001D9740_003E3F08, func_003E7EC8_003E3F08);
        func_003E7F70_003E3F08(D_00317B60_003E3F08, D_001D9740_003E3F08, func_003E7F20_003E3F08);
        func_003E58F8_003E3F08(D_00317C80_003E3F08, D_001D9740_003E3F08, func_003E8040_003E3F08);
        func_003E5A30_003E3F08(D_00317CC8_003E3F08, D_001D9740_003E3F08, func_003E80A8_003E3F08);
        func_003E58F8_003E3F08(D_00317D10_003E3F08, D_001D9740_003E3F08, func_003E8110_003E3F08);
        func_003E5BD0_003E3F08(D_00317D58_003E3F08, D_001D9740_003E3F08, func_003E8178_003E3F08);
        func_003E53E0_003E3F08(D_003179F8_003E3F08, D_001D9740_003E3F08, func_003E81E0_003E3F08);
        func_003E53E0_003E3F08(D_00317848_003E3F08, D_001D9740_003E3F08, func_003E8248_003E3F08);
        func_003E5518_003E3F08(D_00317890_003E3F08, D_001D9740_003E3F08, func_003E82B8_003E3F08);
        func_003E53E0_003E3F08(D_003178D8_003E3F08, D_001D9740_003E3F08, func_003E8320_003E3F08);
    }
    return 1;
}
/* localdecomp:end func_003E3F08 */

LINKER_REMNANT("asm/remnants", func_003E4788);

/* localdecomp:start func_003E4790 */
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
extern u8 D_001DAA89;
void *func_003E4790(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA89) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4790 */

/* localdecomp:start func_003E4810 */
extern u8 D_001DAA8A;
void *func_003E4810(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA8A) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4810 */

/* localdecomp:start func_003E4890 */
typedef struct { u32 key; void *val; } HE_003E4890;
typedef struct { s32 f0; s32 n; HE_003E4890 e[3]; } HT_003E4890;
extern u8 D_001DAA8B_003E4890;
void *func_003E4890(HT_003E4890 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_001DAA8B_003E4890;
    off = 0;
    for (; i < 3; i++) {
        h = ((key % three) + off) % three;
        v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != sent) return v;
        u = off + 1;
        off = (key & 1) + u;
    }
    return 0;
}
/* localdecomp:end func_003E4890 */

/* localdecomp:start func_003E4918 */
typedef struct { u32 key; void *val; } HE_003E4918;
typedef struct { s32 f0; s32 n; HE_003E4918 e[3]; } HT_003E4918;
extern u8 D_001DAA8C_003E4918;
void *func_003E4918(HT_003E4918 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_001DAA8C_003E4918;
    off = 0;
    for (; i < 3; i++) {
        h = ((key % three) + off) % three;
        v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != sent) return v;
        u = off + 1;
        off = (key & 1) + u;
    }
    return 0;
}
/* localdecomp:end func_003E4918 */

/* localdecomp:start func_003E49A0 */
extern u8 D_001DAA8D;
void *func_003E49A0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA8D) return v;
    }
    return 0;
}
/* localdecomp:end func_003E49A0 */

/* localdecomp:start func_003E4A20 */
extern u8 D_001DAA8E;
void *func_003E4A20(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA8E) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4A20 */

/* localdecomp:start func_003E4AA0 */
extern u8 D_001DAA8F;
void *func_003E4AA0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA8F) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4AA0 */

/* localdecomp:start func_003E4B20 */
extern u8 D_001DAA90;
void *func_003E4B20(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA90) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4B20 */

/* localdecomp:start func_003E4BA0 */
extern u8 D_001DAA91;
void *func_003E4BA0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA91) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4BA0 */

/* localdecomp:start func_003E4C20 */
extern u8 D_001DAA92;
void *func_003E4C20(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA92) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4C20 */

/* localdecomp:start func_003E4CA0 */
extern u8 D_001DAA93;
void *func_003E4CA0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA93) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4CA0 */

/* localdecomp:start func_003E4D20 */
extern u8 D_001DAA94;
void *func_003E4D20(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA94) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4D20 */

/* localdecomp:start func_003E4DA0 */
typedef struct { u32 key; void *val; } HE_003E4DA0;
typedef struct { s32 f0; s32 n; HE_003E4DA0 e[3]; } HT_003E4DA0;
extern u8 D_001DAA95_003E4DA0;
void *func_003E4DA0(HT_003E4DA0 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_001DAA95_003E4DA0;
    off = 0;
    for (; i < 3; i++) {
        h = ((key % three) + off) % three;
        v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != sent) return v;
        u = off + 1;
        off = (key & 1) + u;
    }
    return 0;
}
/* localdecomp:end func_003E4DA0 */

/* localdecomp:start func_003E4E28 */
extern u8 D_001DAA96;
void *func_003E4E28(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA96) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4E28 */

/* localdecomp:start func_003E4EA8 */
extern u8 D_001DAA97;
void *func_003E4EA8(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA97) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4EA8 */

/* localdecomp:start func_003E4F28 */
extern u8 D_001DAA98;
void *func_003E4F28(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA98) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4F28 */

/* localdecomp:start func_003E4FA8 */
extern u8 D_001DAA99;
void *func_003E4FA8(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA99) return v;
    }
    return 0;
}
/* localdecomp:end func_003E4FA8 */

/* localdecomp:start func_003E5028 */
extern u8 D_001DAA9A;
void *func_003E5028(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA9A) return v;
    }
    return 0;
}
/* localdecomp:end func_003E5028 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E50A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E5210);
