#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003E8780(s32 arg0, s32 *arg1);
extern s32 func_003E8708(s32 a);
extern s32 func_003E8698(s32 arg0);
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003E8550();
extern s32 func_003E8620();
extern s32 func_003E9148(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9390(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8D40(s32, s32, s32, s32, s32, s32);
extern s32 func_003E95B0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9090(s32, s32, s32);
extern s32 func_003E8AF0(s32, f32, f32);
extern s32 func_003E8BB0(s32, s32);
extern s32 func_003E8C60(s32, s32, s32);
extern s32 func_003E9240(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7A90(s32, s32, s32);
extern s32 func_003E8888(s32, s32);
extern s32 func_003E85A0(s32, s32);
extern s32 func_003E7610(s32, f32, f32);
extern s32 func_003E8448(s32, f32, f32);
extern s32 func_003E7FC8(s32, s32);
extern s32 func_003E8800();
extern void func_003E75F8(s32);
extern s32 func_003E7600();
extern s32 func_003E7B80(s32, s32, s32);
extern s32 func_003E7C70(s32, s32);
extern s32 func_003E8968(s32, s32);
extern s32 func_003E80A0(s32, s32);
extern s32 func_003E8A10(s32, s32, s32);
extern void func_003E96A8();
extern s32 func_003E8FB0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003E94C8(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9310(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E78D8(s32, f32);
extern s32 func_003E77E8(s32, f32, f32);
extern s32 func_003E7C70(s32 arg0, s32 arg1);
extern s32 func_003E8178(s32, s32);
extern s32 func_003E7D20(s32, s32);
extern s32 func_003E8EC0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8CB0(s32, s32, s32, s32, s32);
extern s32 func_003E8DF0(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E79B8(s32, f32);
extern s32 func_003E7FC8();
extern s32 func_003E7A90();
extern s32 func_003E7EE8();
extern s32 func_003E8250(s32, s32, s32, s32, s32);
extern s32 func_003E8358(s32, s32, s32);
extern s32 func_003E7600(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E75F8 */
extern s32 D_001D96F8;
void func_003E75F8(s32 a) {
    D_001D96F8 = a;
}
/* localdecomp:end func_003E75F8 */

/* localdecomp:start func_003E7600 */
extern s32 D_001D96F8;
s32 func_003E7600(void) {
    return D_001D96F8;
}
/* localdecomp:end func_003E7600 */

/* localdecomp:start func_003E7608 */
s32 func_003E7608(void) {
}
/* localdecomp:end func_003E7608 */

/* localdecomp:start func_003E7610 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003E9F50_003E7610[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E1E50;
extern S_003E1E50 D_001DA9B8;
extern u8 D_0031B848[];
s32 func_003E7610(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E1E50 *q;

    r = 0;
    q = &D_001DA9B8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E9F50_003E7610)(D_0031B848, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E7610 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E76F8);

/* localdecomp:start func_003E7700 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003EA050_003E7700[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E1F40;
extern S_003E1F40 D_001DA9B8_003E7700;
extern s32 D_001DAA48[2];
s32 func_003E7700(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E1F40 *q;

    r = 0;
    q = &D_001DA9B8_003E7700;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA050_003E7700)(D_001DAA48, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E7700 */

/* localdecomp:start func_003E77E8 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003E9F50_003E77E8[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2028;
extern S_003E2028 D_001DA9B8_003E77E8;
extern u8 D_0031B9F8[];
s32 func_003E77E8(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E2028 *q;

    r = 0;
    q = &D_001DA9B8_003E77E8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E9F50_003E77E8)(D_0031B9F8, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E77E8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E78D0);

/* localdecomp:start func_003E78D8 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2118;
extern S_003E2118 D_001DA9B8_003E78D8;
extern u8 D_001DA9E8[];
s32 func_003E78D8(s32 arg0, f32 fa)
{
  s32 *base;
  unsigned char new_var;
  s32 (*cb)(void *, f32);
  s32 r;
  s32 t;
  void *p;
  S_003E2118 *q;
  r = 0;
  q = &D_001DA9B8_003E78D8;
  if (q->f4 != 0)
  {
    base = (s32 *) q;
  }
  else
  {
    base = (s32 *) func_003E6E78(q);
  }
  p = (void *) func_003E65E8(func_003E7058(base), arg0);
  new_var = p == 0;
  if (new_var || ((*((s32 (**)(void *, s32)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0x10)))(p, D_001D96A8) == 0))
  {
    p = 0;
  }
  if (p != 0)
  {
    t = (*((s32 (**)(void *)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0xC)))(p);
 do { } while (0);
    cb = (void *) func_003EA0D8(D_001DA9E8, t);
    if (cb != 0)
    {
      r = cb(p, fa);
    }
  }
  return r;
}
/* localdecomp:end func_003E78D8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E79B0);

/* localdecomp:start func_003E79B8 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003EA160_003E79B8[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E21F8;
extern S_003E21F8 D_001DA9B8_003E79B8;
extern u8 D_0031BC38[];
s32 func_003E79B8(s32 arg0, f32 fa) {
    s32 *base;
    s32 (*cb)(void *, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E21F8 *q;

    r = 0;
    q = &D_001DA9B8_003E79B8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA160_003E79B8)(D_0031BC38, t);
        if (cb != 0) {
            r = cb(p, fa);
        }
    }
    return r;
}
/* localdecomp:end func_003E79B8 */

/* localdecomp:start func_003E7A90 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003EA1E0_003E7A90[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E22D0;
extern S_003E22D0 D_001DA9B8_003E7A90;
extern u8 D_0031BC80[];
s32 func_003E7A90(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E22D0 *q;

    r = 0;
    q = &D_001DA9B8_003E7A90;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA1E0_003E7A90)(D_0031BC80, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_003E7A90 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7B78);

/* localdecomp:start func_003E7B80 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003EA1E0_003E7B80[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E23C0;
extern S_003E23C0 D_001DA9B8_003E7B80;
extern u8 D_0031BD10[];
s32 func_003E7B80(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E23C0 *q;

    r = 0;
    q = &D_001DA9B8_003E7B80;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA1E0_003E7B80)(D_0031BD10, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_003E7B80 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7C68);

/* localdecomp:start func_003E7C70 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E24B0;
extern S_003E24B0 D_001DA9B8_003E7C70[];
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E65E8();
extern s32 D_001D9710;
extern void func_003EDD28(void *p, s32, s32);
s32 func_003E7C70(s32 arg0, s32 arg1) {
    S_003E24B0 *q;
    S_003E24B0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA9B8_003E7C70;
    if (p->x4) q = p;
    else q = func_003E6E78(p);
    t = (void *)func_003E65E8(func_003E7058(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9710) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EDD28(v, 1, arg1);
    }
    return r;
}
/* localdecomp:end func_003E7C70 */

/* localdecomp:start func_003E7D20 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E2560;
extern S_003E2560 D_001DA9B8_003E7D20[];
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E65E8();
extern s32 D_001D9710;
extern void func_003EDD28(void *p, s32, s32);
s32 func_003E7D20(s32 arg0, s32 arg1) {
    S_003E2560 *q;
    S_003E2560 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA9B8_003E7D20;
    if (p->x4) q = p;
    else q = func_003E6E78(p);
    t = (void *)func_003E65E8(func_003E7058(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9710) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EDD28(v, 0x40, arg1);
    }
    return r;
}
/* localdecomp:end func_003E7D20 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7DD0);

/* localdecomp:start func_003E7DD8 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003EA360_003E7DD8[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2618;
extern S_003E2618 D_001DA9B8_003E7DD8;
extern u8 D_0031BDA0[];
s32 func_003E7DD8(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 *base;
    s32 (*cb)(void *, s32, s32, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2618 *q;

    r = 0;
    q = &D_001DA9B8_003E7DD8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA360_003E7DD8)(D_0031BDA0, t);
        if (cb != 0) {
            r = cb(p, a1, a2, a3, a4);
        }
    }
    return r;
}
/* localdecomp:end func_003E7DD8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7EE0);

/* localdecomp:start func_003E7EE8 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003EA3E0_003E7EE8[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_3E2728;
extern S_3E2728 D_001DA9B8_003E7EE8;
extern u8 D_0031B920[];
s32 func_003E7EE8(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_3E2728 *q;

    r = 0;
    q = &D_001DA9B8_003E7EE8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA3E0_003E7EE8)(D_0031B920, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_003E7EE8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E7FC0);

/* localdecomp:start func_003E7FC8 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003EA4E0_003E7FC8[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2808;
extern S_003E2808 D_001DA9B8_003E7FC8;
extern u8 D_0031B9B0[];
s32 func_003E7FC8(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2808 *q;

    r = 0;
    q = &D_001DA9B8_003E7FC8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA4E0_003E7FC8)(D_0031B9B0, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_003E7FC8 */

/* localdecomp:start func_003E80A0 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003EA4E0_003E80A0[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E28E0;
extern S_003E28E0 D_001DA9B8_003E80A0;
extern u8 D_0031BAD0[];
s32 func_003E80A0(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E28E0 *q;

    r = 0;
    q = &D_001DA9B8_003E80A0;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA4E0_003E80A0)(D_0031BAD0, t);
        if (cb != 0) {
            r = cb(p, arg1);
        }
    }
    return r;
}
/* localdecomp:end func_003E80A0 */

/* localdecomp:start func_003E8178 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern void *func_003EA560();
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E29B8;
extern S_003E29B8 D_001DA9B8_003E8178;
extern u8 D_001DAA68[];
s32 func_003E8178(s32 arg0, s32 arg1)
{
  s32 *base;
  s32 (*cb)(void *, s32);
  s32 r;
  s32 t;
  void *p;
  S_003E29B8 *q;
  r = 0;
  q = &D_001DA9B8_003E8178;
  if (q->f4 != 0)
  {
    base = (s32 *) q;
  }
  else
  {
    base = (s32 *) func_003E6E78(q);
  }
  p = (void *) func_003E65E8(func_003E7058(base), arg0);
  if ((p == 0) || ((*((s32 (**)(void *, s32)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0x10)))(p, D_001D96A8) == 0))
  {
    p = 0;
  }
  if (p != 0)
  {
 do { t = (*((s32 (**)(void *)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0xC)))(p); } while (0);
    cb = (void *) func_003EA560(D_001DAA68, t);
    if (cb != 0)
    {
      r = cb(p, arg1);
    }
  }
  return r;
}
/* localdecomp:end func_003E8178 */

/* localdecomp:start func_003E8250 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003EA5E8_003E8250[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2A90;
extern S_003E2A90 D_001DA9B8_003E8250;
extern u8 D_0031BDE8[];
s32 func_003E8250(s32 arg0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 *base;
    s32 (*cb)(void *, s32, s32, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2A90 *q;

    r = 0;
    q = &D_001DA9B8_003E8250;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA5E8_003E8250)(D_0031BDE8, t);
        if (cb != 0) {
            r = cb(p, a1, a2, a3, a4);
        }
    }
    return r;
}
/* localdecomp:end func_003E8250 */

/* localdecomp:start func_003E8358 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003EA668_003E8358[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2B98;
extern S_003E2B98 D_001DA9B8_003E8358;
extern u8 D_0031BBF0[];
s32 func_003E8358(s32 arg0, s32 a1, s32 a2) {
    s32 *base;
    s32 (*cb)(void *, s32, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E2B98 *q;

    r = 0;
    q = &D_001DA9B8_003E8358;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA668_003E8358)(D_0031BBF0, t);
        if (cb != 0) {
            r = cb(p, a1, a2);
        }
    }
    return r;
}
/* localdecomp:end func_003E8358 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8440);

/* localdecomp:start func_003E8448 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003E9F50_003E8448[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E2C88;
extern S_003E2C88 D_001DA9B8_003E8448;
extern u8 D_0031B8D8[];
s32 func_003E8448(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E2C88 *q;

    r = 0;
    q = &D_001DA9B8_003E8448;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E9F50_003E8448)(D_0031B8D8, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E8448 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8530);

/* localdecomp:start func_003E8550 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2D90;
extern S_3E2D90 D_001DA9B8_003E8550;
extern void *func_003E6E78();
extern void func_003E7080();
void func_003E8550(s32 a) {
    S_3E2D90 *q;
    if (D_001DA9B8_003E8550.x4) q = &D_001DA9B8_003E8550;
    else q = func_003E6E78(&D_001DA9B8_003E8550);
    func_003E7080(q, a);
}
/* localdecomp:end func_003E8550 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8598);

/* localdecomp:start func_003E85A0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2DE0;
extern S_3E2DE0 D_001DA9B8_003E85A0;
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E5F58(s32, s32, s32);
s32 func_003E85A0(s32 a, s32 b) {
    S_3E2DE0 *q;
    s32 r = 0;
    s32 t;
    if (D_001DA9B8_003E85A0.x4) q = &D_001DA9B8_003E85A0;
    else q = func_003E6E78(&D_001DA9B8_003E85A0);
    t = func_003E7058(q);
    if (t) r = func_003E5F58(t, a, b);
    return r;
}
/* localdecomp:end func_003E85A0 */

/* localdecomp:start func_003E8620 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2E60;
extern S_3E2E60 D_001DA9B8_003E8620;
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E6538();
s32 func_003E8620(s32 a) {
    S_3E2E60 *q;
    s32 r = 0;
    s32 t;
    if (D_001DA9B8_003E8620.x4) q = &D_001DA9B8_003E8620;
    else q = func_003E6E78(&D_001DA9B8_003E8620);
    t = func_003E7058(q);
    if (t) r = func_003E6538(t, a);
    return r;
}
/* localdecomp:end func_003E8620 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8690);

/* localdecomp:start func_003E8698 */
extern s32 func_003E6480(s32, s32);
s32 *func_003E6E78_003E8698(s32 *);                  /* extern */
s32 func_003E7058_003E8698(s32 *);                       /* extern */
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E2ED8;
extern S_001DA9B8_003E2ED8 D_001DA9B8_003E8698[];

s32 func_003E8698(s32 arg0) {
    s32 *var_v0;
    s32 temp_v0;
    s32 var_s1;

    var_s1 = -1;
    if (D_001DA9B8_003E8698->f4 != 0) {
        var_v0 = D_001DA9B8_003E8698;
    } else {
        var_v0 = func_003E6E78_003E8698(D_001DA9B8_003E8698);
    }
    temp_v0 = func_003E7058_003E8698(var_v0);
    if (temp_v0 != 0) {
        var_s1 = func_003E6480(temp_v0, arg0);
    }
    return var_s1;
}
/* localdecomp:end func_003E8698 */

/* localdecomp:start func_003E8708 */
typedef struct { s32 a; s32 b; } S_3E2F48;
extern S_3E2F48 D_001DA9B8_003E8708[];
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E6608(void *, s32);
static inline S_3E2F48 *get_3E2F48(void) {
    S_3E2F48 *p = D_001DA9B8_003E8708;
    if (p->b != 0) return p;
    return func_003E6E78();
}
s32 func_003E8708(s32 a) {
    s32 r = 0;
    void *q = func_003E7058(get_3E2F48());
    if (q != 0) r = func_003E6608(q, a);
    return r;
}
/* localdecomp:end func_003E8708 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8778);

/* localdecomp:start func_003E8780 */
s32 func_003E5F40(s32, s32);                        /* extern */
s32 *func_003E6E78_003E8780(s32 *);                  /* extern */
s32 func_003E7058_003E8780(s32 *);                       /* extern */
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E2FC0;
extern S_001DA9B8_003E2FC0 D_001DA9B8_003E8780[];

s32 func_003E8780(s32 arg0, s32 *arg1) {
    s32 *var_v0;
    s32 temp_v0;
    s32 var_s2;

    var_s2 = 0;
    if (D_001DA9B8_003E8780->f4 != 0) {
        var_v0 = D_001DA9B8_003E8780;
    } else {
        var_v0 = func_003E6E78_003E8780(D_001DA9B8_003E8780);
    }
    temp_v0 = func_003E7058_003E8780(var_v0);
    if (temp_v0 != 0) {
        var_s2 = 1;
        *arg1 = func_003E5F40(temp_v0, arg0);
    }
    return var_s2;
}
/* localdecomp:end func_003E8780 */

/* localdecomp:start func_003E8800 */
typedef struct { s32 a; s32 b; } S_3E3040;
extern S_3E3040 D_001DA9B8_003E8800[];
extern void *func_003E6E78();
extern s32 func_003E7058();
extern void func_003E6030(void *, s32);
s32 func_003E8800(s32 a) {
    S_3E3040 *p = D_001DA9B8_003E8800;
    void *q;
    s32 r = 0;
    { S_3E3040 *t; if (p->b != 0) t = p; else t = func_003E6E78(); q = func_003E7058(t); }
    if (q) { func_003E6030(q, a); r = 1; }
    return r;
}
/* localdecomp:end func_003E8800 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8870);

/* localdecomp:start func_003E8888 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern u8 func_003EA4E0_003E8888[];
extern s32 D_001D96A8;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E30C8;
extern S_003E30C8 D_001DA9B8_003E8888;
extern u8 D_0031BB18[];
s32 func_003E8888(s32 arg0, s32 arg1) {
    s32 *base;
    s32 (*cb)(void *, s32);
    s32 r;
    s32 t;
    void *p;
    S_003E30C8 *q;

    r = 0;
    q = &D_001DA9B8_003E8888;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D96A8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003EA4E0_003E8888)(D_0031BB18, t);
        if (cb != 0) {
            r = cb(p, arg1);
        } else {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_003E8888 */

/* localdecomp:start func_003E8968 */
extern s32 func_003E7058(void *);
extern s32 func_003E65E8();
extern void *func_003E6E78();
extern s32 D_001D97A0;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E31A8;
extern S_003E31A8 D_001DA9B8_003E8968;
s32 func_003E8968(s32 arg0, s32 arg1) {
    s32 *base;
    s32 r;
    void *p;
    void *o;
    S_003E31A8 *q;

    r = 0;
    q = &D_001DA9B8_003E8968;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6E78(q);
    }
    p = (void *)func_003E65E8(func_003E7058(base), arg0);
    o = (p != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D97A0) != 0) ? p : 0;
    if (o != 0) {
        *(s32 *)((u8 *)o + 0x50) = arg1;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003E8968 */

/* localdecomp:start func_003E8A10 */
void *func_003E65E8_003E8A10(s32, s32);                      /* extern */
s32 *func_003E6E78_003E8A10(s32 *);                  /* extern */
s32 func_003E7058_003E8A10(s32 *);                       /* extern */
s32 func_003E7A90(s32, s32, s32);
void func_003F00F0(void *, s32);
extern s32 D_001D97A0;
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003E3250;
extern S_001DA9B8_003E3250 D_001DA9B8_003E8A10[];

s32 func_003E8A10(s32 arg0, s32 arg1, s32 arg2) {
    s32 *var_v0;
    s32 var_s4;
    void *var_s0;

    var_s4 = 0;
    if (D_001DA9B8_003E8A10->f4 != 0) {
        var_v0 = D_001DA9B8_003E8A10;
    } else {
        var_v0 = func_003E6E78_003E8A10(D_001DA9B8_003E8A10);
    }
    var_s0 = func_003E65E8_003E8A10(func_003E7058_003E8A10(var_v0), arg0);
    if ((var_s0 == 0) || ((*(s32 (**)(void *, s32))((u8 *)((*(void **)((u8 *)(var_s0) + 8))) + 0x10))(var_s0, D_001D97A0) == 0)) {
        var_s0 = 0;
    }
    if (var_s0 != 0) {
        var_s4 = 1;
        func_003E7A90(arg0, 0x8000, arg1);
        func_003F00F0(var_s0, arg2);
    }
    return var_s4;
}
/* localdecomp:end func_003E8A10 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8AE0);

/* localdecomp:start func_003E8AF0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E3330;
extern S_003E3330 D_001DA9B8_003E8AF0[];
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E65E8();
extern s32 D_001D97D0;
extern void func_003F0240(void *p, f32, f32);
s32 func_003E8AF0(s32 arg0, f32 fparg0, f32 fparg1) {
    S_003E3330 *q;
    S_003E3330 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA9B8_003E8AF0;
    if (p->x4) q = p;
    else q = func_003E6E78(p);
    t = (void *)func_003E65E8(func_003E7058(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D97D0) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003F0240(v, fparg0, fparg1);
    }
    return r;
}
/* localdecomp:end func_003E8AF0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E8BA8);

/* localdecomp:start func_003E8BB0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E33F0;
extern S_003E33F0 D_001DA9B8_003E8BB0[];
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E65E8();
extern s32 D_001D97D0;
extern void func_003F01F8(u8 *p, u8, s32);
s32 func_003E8BB0(s32 arg0, s32 arg1) {
    S_003E33F0 *q;
    S_003E33F0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA9B8_003E8BB0;
    if (p->x4) q = p;
    else q = func_003E6E78(p);
    t = (void *)func_003E65E8(func_003E7058(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D97D0) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003F01F8(v, 1, arg1);
    }
    return r;
}
/* localdecomp:end func_003E8BB0 */

/* localdecomp:start func_003E8C60 */
s32 func_003E8888(s32, s32);
s32 func_003E8C60(s32 a, s32 b, s32 c) {
    s32 x = func_003E8888(a, b) != 0;
    s32 y = func_003E8888(a, c) != 0;
    return x & y;
}
/* localdecomp:end func_003E8C60 */

/* localdecomp:start func_003E8CB0 */
extern s32 func_003E8888();
s32 func_003E8CB0(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 r;
    s32 t;
    r = func_003E8888(a, b) != 0;
    t = func_003E8888(a, c) != 0;
    r = r & t;
    t = func_003E8888(a, d) != 0;
    r = r & t;
    t = func_003E8888(a, e) != 0;
    return r & t;
}
/* localdecomp:end func_003E8CB0 */

/* localdecomp:start func_003E8D40 */
extern s32 func_003E8888();
s32 func_003E8D40(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 r;
    s32 t;
    r = func_003E8888(a, b) != 0;
    t = func_003E8888(a, c) != 0;
    r = r & t;
    t = func_003E8888(a, d) != 0;
    r = r & t;
    t = func_003E8888(a, e) != 0;
    r = r & t;
    t = func_003E8888(a, f) != 0;
    return r & t;
}
/* localdecomp:end func_003E8D40 */

/* localdecomp:start func_003E8DF0 */
extern s32 func_003E8888();
s32 func_003E8DF0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    s32 r;
    s32 t;
    r = func_003E8888(a, b) != 0;
    t = func_003E8888(a, c) != 0;
    r = r & t;
    t = func_003E8888(a, d) != 0;
    r = r & t;
    t = func_003E8888(a, e) != 0;
    r = r & t;
    t = func_003E8888(a, f) != 0;
    r = r & t;
    t = func_003E8888(a, g) != 0;
    return r & t;
}
/* localdecomp:end func_003E8DF0 */

/* localdecomp:start func_003E8EC0 */
extern s32 func_003E8888(s32, s32);
s32 func_003E8EC0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s32 r;
    s32 t;
    r = func_003E8888(a0, a1) != 0;
    t = func_003E8888(a0, a2) != 0; r = r & t;
    t = func_003E8888(a0, a3) != 0; r = r & t;
    t = func_003E8888(a0, a4) != 0; r = r & t;
    t = func_003E8888(a0, a5) != 0; r = r & t;
    t = func_003E8888(a0, a6) != 0; r = r & t;
    t = func_003E8888(a0, a7) != 0; r = r & t;
    return r;
}
/* localdecomp:end func_003E8EC0 */

/* localdecomp:start func_003E8FB0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E37F0;
extern S_003E37F0 D_001DA9B8_003E8FB0[];
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E65E8();
extern s32 D_001D9740;
extern void func_003EE3B8(void *p, s32, s32);
s32 func_003E8FB0(s32 arg0, s32 arg1, s32 arg2) {
    S_003E37F0 *q;
    S_003E37F0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA9B8_003E8FB0;
    if (p->x4) q = p;
    else q = func_003E6E78(p);
    t = (void *)func_003E65E8(func_003E7058(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9740) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EE3B8(v, arg1, arg2);
    }
    return r;
}
/* localdecomp:end func_003E8FB0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E9068);

/* localdecomp:start func_003E9070 */
extern s32 func_003E8FB0(s32 arg0, s32 arg1, s32 arg2);
 
void func_003E9070(void *p, s32 arg1) {
    func_003E8FB0(p, 1, arg1);
}
/* localdecomp:end func_003E9070 */

/* localdecomp:start func_003E9090 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E38D0;
extern S_003E38D0 D_001DA9B8_003E9090[];
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E65E8();
extern s32 D_001D9800;
extern s32 func_003F0DE0(u8 *arg0, s32, s32);
s32 func_003E9090(s32 arg0, s32 arg1, s32 arg2) {
    S_003E38D0 *q;
    S_003E38D0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_001DA9B8_003E9090;
    if (p->x4) q = p;
    else q = func_003E6E78(p);
    t = (void *)func_003E65E8(func_003E7058(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D9800) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003F0DE0(v, arg1, arg2);
    }
    return r;
}
/* localdecomp:end func_003E9090 */

/* localdecomp:start func_003E9148 */
extern s32 func_003E5300();
extern s32 func_00392D38();
extern s32 func_003E8358(s32, s32, s32);
extern s32 func_003E7FC8(s32, s32);
extern s32 func_003E8448(s32, f32, f32);
extern s32 func_003E7610(s32, f32, f32);
extern s32 func_003E79B8(s32, f32);
s32 func_003E9148(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w, f32 u) {
    s32 f = func_003E5300(a);
    s32 ok = func_003E8358(a, func_00392D38(), b) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E7FC8(a, c) != 0;
    ok = ok & t;
    t = func_003E8448(a, z, w) != 0;
    ok = ok & t;
    t = func_003E7610(a, x, y) != 0;
    ok = ok & t;
    t = func_003E79B8(a, u) != 0;
    return ok & t;
}
/* localdecomp:end func_003E9148 */

/* localdecomp:start func_003E9240 */
extern s32 func_003E55D0();
extern s32 func_003E7EE8(s32, s32);
extern s32 func_003E7FC8(s32, s32);
extern s32 func_003E8448(s32, f32, f32);
extern s32 func_003E7610(s32, f32, f32);
s32 func_003E9240(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    s32 f = func_003E55D0(a);
    s32 ok = func_003E7EE8(a, b) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E7FC8(a, c) != 0;
    ok = ok & t;
    t = func_003E8448(a, z, w) != 0;
    ok = ok & t;
    t = func_003E7610(a, x, y) != 0;
    return ok & t;
}
/* localdecomp:end func_003E9240 */

/* localdecomp:start func_003E9310 */
extern s32 func_003E9240(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E77E8(s32, f32, f32);
s32 func_003E9310(s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g, f32 h, f32 i) {
    s32 r;
    s32 t;
    s32 u;
    u = func_003E9240(a, b, c, d, e, f, g);
    r = func_003E77E8(a, h, i) != 0;
    if (u == 0) r = 0;
    t = ((s32 (*)(s32, s32, s32))func_003E7A90)(a, 0x40, 1) != 0;
    return r & t;
}
/* localdecomp:end func_003E9310 */

/* localdecomp:start func_003E9390 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E3BD0;
extern S_003E3BD0 D_001DA9B8_003E9390[];
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E65E8();
extern s32 func_003E5468(s32);
extern s32 D_001D97A0;
s32 func_003E9390(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w) {
    S_003E3BD0 *p;
    S_003E3BD0 *q;
    void *t;
    void *v;
    s32 ok;
    s32 u;
    ok = func_003E5468(a);
    u = func_003E7610(a, x, y) != 0;
    if (!ok) u = 0;
    ok = u;
    u = func_003E7FC8(a, b) != 0;
    ok = ok & u;
    u = func_003E8448(a, z, w) != 0;
    ok = ok & u;
    u = func_003E80A0(a, c) != 0;
    ok = ok & u;
    p = D_001DA9B8_003E9390;
    if (p->x4) q = p;
    else q = func_003E6E78(p);
    t = (void *)func_003E65E8(func_003E7058(q), a);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D97A0) != 0) ? t : 0;
    *(s16 *)((u8 *)v + 0x4A) = 0;
    return ok;
}
/* localdecomp:end func_003E9390 */

/* localdecomp:start func_003E94C8 */
extern s32 func_003EA868();
extern s32 func_003E7610(s32, f32, f32);
extern s32 func_003E7FC8(s32, s32);
extern s32 func_003E8448(s32, f32, f32);
extern s32 func_003E7700(s32, f32, f32);
s32 func_003E94C8(s32 a, s32 b, f32 x, f32 y, f32 z, f32 w, f32 u, f32 v) {
    s32 f = func_003EA868(a);
    s32 ok = func_003E7610(a, x, y) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E7FC8(a, b) != 0;
    ok = ok & t;
    t = func_003E8448(a, z, w) != 0;
    ok = ok & t;
    t = func_003E7700(a, u, v) != 0;
    return ok & t;
}
/* localdecomp:end func_003E94C8 */

/* localdecomp:start func_003E95B0 */
extern s32 func_003EA9D0();
extern s32 func_003E7610(s32, f32, f32);
extern s32 func_003E7FC8(s32, s32);
extern s32 func_003E8448(s32, f32, f32);
extern s32 func_003E7EE8(s32, s32);
extern s32 func_003E78D8(s32, f32);
s32 func_003E95B0(s32 a, s32 b, s32 c, f32 x, f32 y, f32 z, f32 w, f32 u) {
    s32 f = func_003EA9D0(a);
    s32 ok = func_003E7610(a, x, y) != 0;
    s32 t;
    if (!f) ok = 0;
    t = func_003E7FC8(a, c) != 0;
    ok = ok & t;
    t = func_003E8448(a, z, w) != 0;
    ok = ok & t;
    t = func_003E7EE8(a, b) != 0;
    ok = ok & t;
    t = func_003E78D8(a, u) != 0;
    return ok & t;
}
/* localdecomp:end func_003E95B0 */

/* localdecomp:start func_003E96A8 */
extern void func_003B5268();
 
void func_003E96A8(void) {
    func_003B5268();
}
/* localdecomp:end func_003E96A8 */

/* localdecomp:start func_003E96C8 */
__asm__(".extern D_001D96FC, 1");
extern u8 D_001D96FC;
extern s32 D_001D9740;
extern s32 D_001D9770;
extern s32 D_001D97A0;
extern s32 D_001D97D0;
extern s32 D_001D9800;
extern s32 D_001D9830;
extern s32 D_001DA9C8[2];
extern s32 D_001DA9E8_003E96C8[2];
extern s32 D_001DAA08[2];
extern s32 D_001DAA28[2];
extern s32 D_001DAA48[2];
extern s32 D_001DAA68_003E96C8[2];
extern u8 D_0031B848[];
extern u8 D_0031B890[];
extern u8 D_0031B8D8[];
extern u8 D_0031B920[];
extern u8 D_0031B968[];
extern u8 D_0031B9B0[];
extern u8 D_0031B9F8[];
extern u8 D_0031BA40[];
extern u8 D_0031BA88[];
extern u8 D_0031BAD0[];
extern u8 D_0031BB18[];
extern u8 D_0031BB60[];
extern u8 D_0031BBA8[];
extern u8 D_0031BBF0[];
extern u8 D_0031BC38[];
extern u8 D_0031BC80[];
extern u8 D_0031BCC8[];
extern u8 D_0031BD10[];
extern u8 D_0031BD58[];
extern u8 D_0031BDA0[];
extern u8 D_0031BDE8[];
extern u8 D_0031BE30[];
extern s32 func_003EABA0_003E96C8(void *, s32, void *);
extern s32 func_003EACD8_003E96C8(void *, s32, void *);
extern s32 func_003EADF8_003E96C8(void *, s32, void *);
extern s32 func_003EAF80_003E96C8(void *, s32, void *);
extern s32 func_003EB0B8_003E96C8(void *, s32, void *);
extern s32 func_003EB1F0_003E96C8(void *, s32, void *);
extern s32 func_003EB390_003E96C8(void *, s32, void *);
extern s32 func_003EB5A0_003E96C8(void *, s32, void *);
extern s32 func_003EB6C0_003E96C8(void *, s32, void *);
extern s32 func_003EB958_003E96C8(void *, s32, void *);
extern s32 func_003EBE40_003E96C8(void *, s32, void *);
extern s32 func_003EBF78(void *, s32, void *);
extern s32 func_003EC178_003E96C8(void *, s32, void *);
extern s32 func_003EC870_003E96C8(void *, s32, void *);
extern s32 func_003EC998_003E96C8(void *, s32, void *);
extern s32 func_003ED120_003E96C8(void *, s32, void *);
extern s32 func_003ED5B8_003E96C8(void *, s32, void *);
extern s32 func_003ED730_003E96C8(void *, s32, void *);
extern s32 func_003EAB38(u8 *p, f32 a, f32 b);
extern s32 func_003EAC70(u8 *p, s32 a, s32 b);
extern s32 func_003EADA8(u8 *p, s32 a);
extern s32 func_003EAEC8(u8 *p, f32 a, f32 b);
extern s32 func_003EAF30(u8 *p, s32 a);
extern s32 func_003EB050(u8 *p, s32 a, s32 b);
extern s32 func_003EB188(u8 *p, s32 a, u8 *out);
extern s32 func_003EB2C0(u8 *p, s32 a, s32 b);
extern s32 func_003EB328(u8 *p, s32 a, s32 b);
extern s32 func_003EB460(u8 *p, f32 a, f32 b);
extern s32 func_003EB4C8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EB670(u8 *p, s32 a);
extern s32 func_003EB798(u8 *p, f32 a, f32 b);
extern s32 func_003EB808(u8 *p, s32 a, s32 b);
extern s32 func_003EB870(u8 *p, s32 a);
extern s32 func_003EB8C8(u8 *p, s32 a, s16 b, s16 c, s32 d);
extern s32 func_003EBA28(u8 *p, f32 a, f32 b);
extern s32 func_003EBA98(u8 *p, s32 a);
extern s32 func_003EBAF0(u8 *p, s32 a, s32 b);
extern s32 func_003EBB58(u8 *p, s32 a, u8 *out);
extern s32 func_003EBBC0(u8 *p, s32 a, s32 b);
extern s32 func_003EBC28(u8 *p, s32 a, s32 b);
extern s32 func_003EBC90(u8 *p, f32 a, f32 b);
extern s32 func_003EBCF8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EBDD0(u8 *p, f32 a, f32 b);
extern s32 func_003EBF18(u8 *p, f32 a);
extern s32 func_003EC050(u8 *p, f32 a);
extern s32 func_003EC0B0(u8 *p, f32 a, f32 b);
extern s32 func_003EC120(u8 *p, s32 a);
extern s32 func_003EC248(u8 *p, s32 a, s32 b);
extern s32 func_003EC2B0(u8 *p, s32 a);
extern s32 func_003EC308(u8 *p, f32 a, f32 b);
extern s32 func_003EC370(u8 *p, s32 a, s32 b);
extern s32 func_003EC3D8(u8 *p, f32 a, f32 b);
extern s32 func_003EC440();
extern s32 func_003EC4A8();
extern s32 func_003EC508(u8 *p, s32 a, s32 b);
extern s32 func_003EC570(u8 *p, s32 a, u8 *out);
extern s32 func_003EC5D8(u8 *p, s32 a, s32 b);
extern s32 func_003EC640(u8 *p, s32 a, s32 b);
extern s32 func_003EC6A8(u8 *p, f32 a, f32 b);
extern s32 func_003EC710(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003EC7E8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_003EC940(u8 *p, f32 a);
extern s32 func_003ECA68(u8 *p, f32 a, f32 b);
extern s32 func_003ECAD0(u8 *p, s32 a, s32 b);
extern s32 func_003ECB38(u8 *p, f32 a, f32 b);
extern s32 func_003ECBA0(u8 *p, s32 a);
extern s32 func_003ECBF0(u8 *p, s32 a, s32 b);
extern s32 func_003ECC58(u8 *p, s32 a, u8 *out);
extern s32 func_003ECCC0(u8 *p, s32 a, s32 b);
extern s32 func_003ECD28(u8 *p, s32 a, s32 b);
extern s32 func_003ECD90(u8 *p, f32 a, f32 b);
extern s32 func_003ECDF8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ECED0(u8 *p, f32 a, f32 b);
extern s32 func_003ECF38(u8 *p, f32 a, f32 b);
extern s32 func_003ECFA0(u8 *p, s32 a, s32 b);
extern s32 func_003ED008(u8 *p, f32 a, f32 b);
extern s32 func_003ED070(u8 *p, s32 a);
extern s32 func_003ED0C0();
extern s32 func_003ED1F0(u8 *p, s32 a, s32 b);
extern s32 func_003ED258(u8 *p, s32 a, u8 *out);
extern s32 func_003ED2C0(u8 *p, s32 a, s32 b);
extern s32 func_003ED328(u8 *p, s32 a, s32 b);
extern s32 func_003ED390(u8 *p, f32 a, f32 b);
extern s32 func_003ED3F8(u8 *p, f32 a);
extern s32 func_003ED450(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern s32 func_003ED528(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 func_003ED688();
extern s32 func_003ED6E0();
extern s32 func_003ED800(u8 *p, s32 a, s32 b);
extern s32 func_003ED868(u8 *p, s32 a, u8 *out);
extern s32 func_003ED8D0(u8 *p, s32 a, s32 b);
extern s32 func_003ED938(u8 *p, s32 a, s32 b);
extern s32 func_003ED9A0(u8 *p, f32 a, f32 b);
extern s32 func_003EDA08(u8 *p, f32 a, f32 b);
extern s32 func_003EDA78(u8 *p, s32 a, s32 b);
extern s32 func_003EDAE0(u8 *p, f32 a, f32 b);

s32 func_003E96C8(void) {
    if (D_001D96FC == 0) {
        D_001D96FC = 1;
        func_003EABA0_003E96C8(D_0031B848, D_001D97D0, func_003EAB38);
        func_003EACD8_003E96C8(D_0031B890, D_001D97D0, func_003EAC70);
        func_003EADF8_003E96C8(D_0031B920, D_001D97D0, func_003EADA8);
        func_003EABA0_003E96C8(D_0031B8D8, D_001D97D0, func_003EAEC8);
        func_003EAF80_003E96C8(D_0031B9B0, D_001D97D0, func_003EAF30);
        func_003EB0B8_003E96C8(D_0031BC80, D_001D97D0, func_003EB050);
        func_003EB1F0_003E96C8(D_0031BCC8, D_001D97D0, func_003EB188);
        func_003EB0B8_003E96C8(D_0031BD10, D_001D97D0, func_003EB2C0);
        func_003EB390_003E96C8(D_0031BD58, D_001D97D0, func_003EB328);
        func_003EABA0_003E96C8(D_0031B9F8, D_001D97D0, func_003EB460);
        func_003EB5A0_003E96C8(D_0031BDA0, D_001D97D0, func_003EB4C8);
        func_003EB6C0_003E96C8(D_001DAA68_003E96C8, D_001D97D0, func_003EB670);
        func_003EABA0_003E96C8(D_0031B848, D_001D9800, func_003EB798);
        func_003EACD8_003E96C8(D_0031B890, D_001D9800, func_003EB808);
        func_003EADF8_003E96C8(D_0031B920, D_001D9800, func_003EB870);
        func_003EB958_003E96C8(D_0031B968, D_001D9800, func_003EB8C8);
        func_003EABA0_003E96C8(D_0031B8D8, D_001D9800, func_003EBA28);
        func_003EAF80_003E96C8(D_0031B9B0, D_001D9800, func_003EBA98);
        func_003EB0B8_003E96C8(D_0031BC80, D_001D9800, func_003EBAF0);
        func_003EB1F0_003E96C8(D_0031BCC8, D_001D9800, func_003EBB58);
        func_003EB0B8_003E96C8(D_0031BD10, D_001D9800, func_003EBBC0);
        func_003EB390_003E96C8(D_0031BD58, D_001D9800, func_003EBC28);
        func_003EABA0_003E96C8(D_0031B9F8, D_001D9800, func_003EBC90);
        func_003EB5A0_003E96C8(D_0031BDA0, D_001D9800, func_003EBCF8);
        func_003EBE40_003E96C8(D_001DA9C8, D_001D9800, func_003EBDD0);
        func_003EBF78(D_001DA9E8_003E96C8, D_001D9800, func_003EBF18);
        func_003EBF78(D_001DAA08, D_001D9800, func_003EC050);
        func_003EBE40_003E96C8(D_001DAA28, D_001D9800, func_003EC0B0);
        func_003EC178_003E96C8(D_0031BA40, D_001D9800, func_003EC120);
        func_003EACD8_003E96C8(D_0031BA88, D_001D9800, func_003EC248);
        func_003EB6C0_003E96C8(D_001DAA68_003E96C8, D_001D9800, func_003EC2B0);
        func_003EABA0_003E96C8(D_0031B848, D_001D97A0, func_003EC308);
        func_003EACD8_003E96C8(D_0031B890, D_001D97A0, func_003EC370);
        func_003EABA0_003E96C8(D_0031B8D8, D_001D97A0, func_003EC3D8);
        func_003EAF80_003E96C8(D_0031B9B0, D_001D97A0, func_003EC440);
        func_003EAF80_003E96C8(D_0031BAD0, D_001D97A0, func_003EC4A8);
        func_003EB0B8_003E96C8(D_0031BC80, D_001D97A0, func_003EC508);
        func_003EB1F0_003E96C8(D_0031BCC8, D_001D97A0, func_003EC570);
        func_003EB0B8_003E96C8(D_0031BD10, D_001D97A0, func_003EC5D8);
        func_003EB390_003E96C8(D_0031BD58, D_001D97A0, func_003EC640);
        func_003EABA0_003E96C8(D_0031B9F8, D_001D97A0, func_003EC6A8);
        func_003EB5A0_003E96C8(D_0031BDA0, D_001D97A0, func_003EC710);
        func_003EC870_003E96C8(D_0031BDE8, D_001D97A0, func_003EC7E8);
        func_003EC998_003E96C8(D_0031BE30, D_001D97A0, func_003EC940);
        func_003EABA0_003E96C8(D_0031B848, D_001D9770, func_003ECA68);
        func_003EACD8_003E96C8(D_0031B890, D_001D9770, func_003ECAD0);
        func_003EABA0_003E96C8(D_0031B8D8, D_001D9770, func_003ECB38);
        func_003EAF80_003E96C8(D_0031B9B0, D_001D9770, func_003ECBA0);
        func_003EB0B8_003E96C8(D_0031BC80, D_001D9770, func_003ECBF0);
        func_003EB1F0_003E96C8(D_0031BCC8, D_001D9770, func_003ECC58);
        func_003EB0B8_003E96C8(D_0031BD10, D_001D9770, func_003ECCC0);
        func_003EB390_003E96C8(D_0031BD58, D_001D9770, func_003ECD28);
        func_003EABA0_003E96C8(D_0031B9F8, D_001D9770, func_003ECD90);
        func_003EB5A0_003E96C8(D_0031BDA0, D_001D9770, func_003ECDF8);
        func_003EBE40_003E96C8(D_001DAA48, D_001D9770, func_003ECED0);
        func_003EABA0_003E96C8(D_0031B848, D_001D9830, func_003ECF38);
        func_003EACD8_003E96C8(D_0031B890, D_001D9830, func_003ECFA0);
        func_003EABA0_003E96C8(D_0031B8D8, D_001D9830, func_003ED008);
        func_003EAF80_003E96C8(D_0031B9B0, D_001D9830, func_003ED070);
        func_003ED120_003E96C8(D_0031BBF0, D_001D9830, func_003ED0C0);
        func_003EB0B8_003E96C8(D_0031BC80, D_001D9830, func_003ED1F0);
        func_003EB1F0_003E96C8(D_0031BCC8, D_001D9830, func_003ED258);
        func_003EB0B8_003E96C8(D_0031BD10, D_001D9830, func_003ED2C0);
        func_003EB390_003E96C8(D_0031BD58, D_001D9830, func_003ED328);
        func_003EABA0_003E96C8(D_0031B9F8, D_001D9830, func_003ED390);
        func_003EC998_003E96C8(D_0031BC38, D_001D9830, func_003ED3F8);
        func_003EB5A0_003E96C8(D_0031BDA0, D_001D9830, func_003ED450);
        func_003ED5B8_003E96C8(D_0031BBA8, D_001D9740, func_003ED528);
        func_003EAF80_003E96C8(D_0031BB18, D_001D9740, func_003ED688);
        func_003ED730_003E96C8(D_0031BB60, D_001D9740, func_003ED6E0);
        func_003EB0B8_003E96C8(D_0031BC80, D_001D9740, func_003ED800);
        func_003EB1F0_003E96C8(D_0031BCC8, D_001D9740, func_003ED868);
        func_003EB0B8_003E96C8(D_0031BD10, D_001D9740, func_003ED8D0);
        func_003EB390_003E96C8(D_0031BD58, D_001D9740, func_003ED938);
        func_003EABA0_003E96C8(D_0031B9F8, D_001D9740, func_003ED9A0);
        func_003EABA0_003E96C8(D_0031B848, D_001D9740, func_003EDA08);
        func_003EACD8_003E96C8(D_0031B890, D_001D9740, func_003EDA78);
        func_003EABA0_003E96C8(D_0031B8D8, D_001D9740, func_003EDAE0);
    }
    return 1;
}
/* localdecomp:end func_003E96C8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E9F48);

/* localdecomp:start func_003E9F50 */
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
extern u8 D_001DAA89;
void *func_003E9F50(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA89) return v;
    }
    return 0;
}
/* localdecomp:end func_003E9F50 */

/* localdecomp:start func_003E9FD0 */
extern u8 D_001DAA8A;
void *func_003E9FD0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA8A) return v;
    }
    return 0;
}
/* localdecomp:end func_003E9FD0 */

/* localdecomp:start func_003EA050 */
typedef struct { u32 key; void *val; } HE_003E4890;
typedef struct { s32 f0; s32 n; HE_003E4890 e[3]; } HT_003E4890;
extern u8 D_001DAA8B;
void *func_003EA050(HT_003E4890 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_001DAA8B;
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
/* localdecomp:end func_003EA050 */

/* localdecomp:start func_003EA0D8 */
typedef struct { u32 key; void *val; } HE_003E4918;
typedef struct { s32 f0; s32 n; HE_003E4918 e[3]; } HT_003E4918;
extern u8 D_001DAA8C;
void *func_003EA0D8(HT_003E4918 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_001DAA8C;
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
/* localdecomp:end func_003EA0D8 */

/* localdecomp:start func_003EA160 */
extern u8 D_001DAA8D;
void *func_003EA160(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA8D) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA160 */

/* localdecomp:start func_003EA1E0 */
extern u8 D_001DAA8E;
void *func_003EA1E0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA8E) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA1E0 */

/* localdecomp:start func_003EA260 */
extern u8 D_001DAA8F;
void *func_003EA260(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA8F) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA260 */

/* localdecomp:start func_003EA2E0 */
extern u8 D_001DAA90;
void *func_003EA2E0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA90) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA2E0 */

/* localdecomp:start func_003EA360 */
extern u8 D_001DAA91;
void *func_003EA360(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA91) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA360 */

/* localdecomp:start func_003EA3E0 */
extern u8 D_001DAA92;
void *func_003EA3E0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA92) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA3E0 */

/* localdecomp:start func_003EA460 */
extern u8 D_001DAA93;
void *func_003EA460(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA93) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA460 */

/* localdecomp:start func_003EA4E0 */
extern u8 D_001DAA94;
void *func_003EA4E0(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA94) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA4E0 */

/* localdecomp:start func_003EA560 */
typedef struct { u32 key; void *val; } HE_003E4DA0;
typedef struct { s32 f0; s32 n; HE_003E4DA0 e[3]; } HT_003E4DA0;
extern u8 D_001DAA95;
void *func_003EA560(HT_003E4DA0 *t, u32 key) {
    s32 off;
    s32 three;
    void *sent;
    s32 i;
    s32 h;
    void * v;
    s32 u;
    i = 0;
    three = 3;
    sent = &D_001DAA95;
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
/* localdecomp:end func_003EA560 */

/* localdecomp:start func_003EA5E8 */
extern u8 D_001DAA96;
void *func_003EA5E8(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA96) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA5E8 */

/* localdecomp:start func_003EA668 */
extern u8 D_001DAA97;
void *func_003EA668(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA97) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA668 */

/* localdecomp:start func_003EA6E8 */
extern u8 D_001DAA98;
void *func_003EA6E8(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA98) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA6E8 */

/* localdecomp:start func_003EA768 */
extern u8 D_001DAA99;
void *func_003EA768(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA99) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA768 */

/* localdecomp:start func_003EA7E8 */
extern u8 D_001DAA9A;
void *func_003EA7E8(HT_8 *t, u32 key) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != &D_001DAA9A) return v;
    }
    return 0;
}
/* localdecomp:end func_003EA7E8 */

/* localdecomp:start func_003EA868 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E50A8;
extern S_003E50A8 D_001DA9B8_003EA868[];
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E6F30();
extern s32 func_003E5B68();
extern s32 func_003E65B8();
extern void *func_003EE9B8();
extern s32 func_003F2580();
extern void func_003E75F8(s32);
extern s32 func_003E7600();
s32 func_003EA868(s32 a) {
    S_003E50A8 *p;
    S_003E50A8 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA9B8_003EA868;
    if (!q->x4) q = func_003E6E78();
    obj = func_003E7058(q);
    func_003E75F8(0x3C);
    vv = func_003E7600();
    if (obj != 0) {
        if (func_003E5B68(obj, a) == 0) {
            p = D_001DA9B8_003EA868;
            if (p->x4) q = p;
            else q = func_003E6E78(p);
            t1 = func_003E6F30(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003EE9B8(func_003F2580(0x3C, e));
                r = func_003E65B8(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA9B8_003EA868;
                    if (p->x4) q = p;
                    else q = func_003E6E78(p);
                    w = func_003E6F30(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003EA868 */

/* localdecomp:start func_003EA9D0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E5210;
extern S_003E5210 D_001DA9B8_003EA9D0[];
extern void *func_003E6E78();
extern s32 func_003E7058();
extern s32 func_003E6F30();
extern s32 func_003E5B68();
extern s32 func_003E65B8();
extern void *func_003F0940();
extern s32 func_003F2580();
extern void func_003E75F8(s32);
extern s32 func_003E7600();
s32 func_003EA9D0(s32 a) {
    S_003E5210 *p;
    S_003E5210 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA9B8_003EA9D0;
    if (!q->x4) q = func_003E6E78();
    obj = func_003E7058(q);
    func_003E75F8(0x38);
    vv = func_003E7600();
    if (obj != 0) {
        if (func_003E5B68(obj, a) == 0) {
            p = D_001DA9B8_003EA9D0;
            if (p->x4) q = p;
            else q = func_003E6E78(p);
            t1 = func_003E6F30(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003F0940(func_003F2580(0x38, e));
                r = func_003E65B8(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA9B8_003EA9D0;
                    if (p->x4) q = p;
                    else q = func_003E6E78(p);
                    w = func_003E6F30(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003EA9D0 */
