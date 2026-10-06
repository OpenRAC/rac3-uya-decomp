#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/nonmatchings/text", func_0037E0F0);

/* localdecomp:start func_0037E1D8 */
extern s32 func_0013D3E0(void);
s32 func_0037E1D8(s32 a) {
    return func_0013D3E0() % a;
}
/* localdecomp:end func_0037E1D8 */

/* localdecomp:start func_0037E208 */
extern s32 func_0013D3E0(void);
s32 func_0037E208(s32 lo, s32 hi) {
    return func_0013D3E0() % (hi - lo + 1) + lo;
}
/* localdecomp:end func_0037E208 */

/* localdecomp:start func_0037E250 */
extern s32 func_13D3E0(void);
f32 func_0037E250(f32 a, f32 b) {
    return a + (f32)func_13D3E0() * (b - a) * (1.0f / 32768.0f);
}
/* localdecomp:end func_0037E250 */

/* localdecomp:start func_0037E2A8 */
extern s32 func_0013D3E0(void);
f32 func_0037E2A8(void) {
    return (f32)(func_0013D3E0() - 0x4000) * 3.1415927f * (1.0f / 16384.0f);
}
/* localdecomp:end func_0037E2A8 */

/* localdecomp:start func_0037E2F0 */
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
void func_0037E2F0(s32 a, f32 x, f32 y) {
    f32 p = func_0037E2A8();
    f32 q = func_0037E2A8();
    func_0037E4B8(a, func_0037E250(x, y), p, q);
}
/* localdecomp:end func_0037E2F0 */

/* localdecomp:start func_0037E368 */
extern s32 D_001D9AA8_0037E368[2];
extern s32 D_001D9AB0_0037E368[2];
extern s32 D_001D9D88_0037E368;
extern f32 func_00388960(f32);
extern void func_003894A0(s32, s32, f32);
void func_0037E368(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 *cur = &D_001D9AB0_0037E368[a3];
    s32 *cnt = &D_001D9AA8_0037E368[a3];
    f32 v;
    s32 h;
    f32 s;
    if (*cur != D_001D9D88_0037E368) {
        *cur = D_001D9D88_0037E368;
        *cnt += 1;
    }
    if (a4 != 0) {
        *cnt = 0;
    }
    switch (a5) {
    case 0:
        h = *cnt % (a2 * 2);
        if (h >= a2) {
            v = 1.0f - ((f32)(h - a2) / (f32)a2);
        } else {
            v = (f32)h / (f32)a2;
        }
        break;
    case 1:
        s = func_00388960(((f32)(*cnt % a2) / (f32)a2) * 3.1415925f);
        v = s * s;
        v = v * v;
        break;
    default:
        v = 0.5f;
        break;
    }
    func_003894A0(a1, a0, v);
}
/* localdecomp:end func_0037E368 */

/* localdecomp:start func_0037E4B8 */
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);

void func_0037E4B8(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f22;

    temp_f22 = func_00388960(fparg2);
    (*(f32 *)((u8 *)(arg0) + 0)) = (f32) (func_00388960(fparg1) * fparg0 * temp_f22);
    (*(f32 *)((u8 *)(arg0) + 4)) = (f32) (func_00388978(fparg1) * fparg0 * temp_f22);
    (*(f32 *)((u8 *)(arg0) + 8)) = (f32) (func_00388978(fparg2) * fparg0);
}
/* localdecomp:end func_0037E4B8 */

LINKER_REMNANT("asm/remnants", func_0037E548);

/* localdecomp:start func_0037E568 */
typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; u16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E568;
extern E_0037E568 D_00222500_0037E568[];
void func_0037E568(s32 idx, s32 b, s32 m, f32 x, f32 y, f32 z, f32 w) {
    E_0037E568 *e = &D_00222500_0037E568[idx];
    switch (m) {
    case 0:
        e->f424 = x;
        e->b439 = 1;
        e->b438 = 0;
        break;
    case 1:
    case 2:
        if (b == 0) {
            e->f424 = x;
            e->b438 = 0;
        } else {
            f32 t = e->f428;
            e->b438 = m;
            e->f440 = t;
            e->h43A = b;
            e->f43C = 1.0f / (f32)b;
        }
        e->b439 = 1;
        break;
    case 3:
        e->b438 = m;
        e->f424 = x;
        e->b439 = 1;
        e->f42C = y;
        e->f430 = z;
        e->f434 = w;
        break;
    }
}
/* localdecomp:end func_0037E568 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037E630);

LINKER_REMNANT("asm/remnants", func_0037E7C8);

/* localdecomp:start func_0037E7D8 */
void func_003885F0(void *, void *, s32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_00222500[];
extern u8 D_00224B90[];
extern u8 D_002254D0[];

void func_0037E7D8(s32 arg0) {
    s32 temp_s1;
    void *temp_s0;
    void *temp_s2;

    temp_s2 = (arg0 * 0xB0) + D_00224B90;
    { S_00222500_0037E7D8 *p = &D_00222500[arg0]; func_003885F0(temp_s2, p->f50, 0xB0); }
    temp_s1 = arg0 * 0x780;
    temp_s0 = temp_s1 + D_002254D0;
    func_003885F0(temp_s0, temp_s1 + (D_002254D0 - 0x500), 0x280);
    (*(void **)((u8 *)(temp_s2) + 0x70)) = temp_s0;
}
/* localdecomp:end func_0037E7D8 */
TEXT_PADDING(2);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E878);

/* localdecomp:start func_0037E920 */
f32 func_0037E920(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    f32 temp_f0;
    f32 temp_f13;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f13;
    f32 var_f16;

    var_f16 = fparg4;
    temp_f13 = fparg1 - fparg0;
    temp_f1 = *arg0;
    temp_f1_2 = temp_f1 + ((fparg2 * temp_f13) - (fparg3 * temp_f1));
    *arg0 = temp_f1_2;
    if ((var_f16 != 0.0f) && ((var_f16 < temp_f1_2) || (var_f16 = -var_f16, (temp_f1_2 < var_f16)))) {
        *arg0 = var_f16;
    }
    temp_f0 = *arg0;
    __asm__("abs.s %0, %1" : "=f"(var_f13) : "f"(temp_f13));
    if ((var_f13 < temp_f0) || (var_f13 = -var_f13, (temp_f0 < var_f13))) {
        *arg0 = var_f13;
    }
    return fparg0 + *arg0;
}
/* localdecomp:end func_0037E920 */

/* localdecomp:start func_0037E9B0 */
extern void func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
void func_0037E9B0(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 var_f0;
    f32 var_f16;

    var_f16 = fparg4;
    temp_f0 = func_003893C8(fparg1, fparg0);
    temp_f1 = *arg0;
    temp_f1_2 = temp_f1 + ((fparg2 * temp_f0) - (fparg3 * temp_f1));
    *arg0 = temp_f1_2;
    if (var_f16 != 0.0f) {
        if (var_f16 < temp_f1_2) {
            *arg0 = var_f16;
        } else {
            f32 n = -var_f16;
            if (temp_f1_2 < n) {
                *arg0 = n;
            }
        }
    }
    temp_f1_3 = *arg0;
    __asm__("abs.s %0, %1" : "=f"(var_f0) : "f"(temp_f0));
    if ((var_f0 < temp_f1_3) || (var_f0 = -var_f0, (temp_f1_3 < var_f0))) {
        *arg0 = var_f0;
    }
    func_00389380(fparg0, *arg0);
}
/* localdecomp:end func_0037E9B0 */

LINKER_REMNANT("asm/remnants", func_0037EA98);

/* localdecomp:start func_0037EAA0 */
s32 func_0037DD20(void *, s32, s32, s32);           /* extern */
extern void func_003BD360(s32 p);
extern u8 D_00222560[];

void func_0037EAA0(s32 arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_a2;
    void *temp_s0;

    temp_a2 = arg0 * 0x460;
    temp_s0 = temp_a2 + D_00222560;
    if ((*(s16 *)((u8 *)(arg1) + 0x86)) == 0) {
        if ((*(s32 *)((u8 *)(temp_s0) + 0xC4)) == 0) {
            (*(s32 *)((u8 *)(temp_s0) + 0xC4)) = func_0037DD20(temp_a2 + (D_00222560 - 0x60), arg0, temp_a2, arg0);
        }
    } else {
        temp_a0 = (*(s32 *)((u8 *)(temp_s0) + 0xC4));
        if (temp_a0 != 0) {
            func_003BD360(temp_a0);
            (*(s32 *)((u8 *)(temp_s0) + 0xC4)) = 0;
        }
    }
}
/* localdecomp:end func_0037EAA0 */
TEXT_PADDING(2);

/* localdecomp:start func_0037EB20 */
typedef struct { s32 a, b, c, d, e; } S_37D000;
extern S_37D000 D_0037D000[];
void func_0037EB20(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_0037D000[*(s16 *)(p + 0x8C)].c;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_0037EB20 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037EB68);

INCLUDE_ASM("asm/nonmatchings/text", func_0037EE80);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318080);

/* localdecomp:start func_0037F090 */
extern S_37D000 D_0037D000[];
void func_0037F090(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_0037D000[*(s16 *)(p + 0x8C)].e;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_0037F090 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037F0D8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F228);

/* localdecomp:start func_0037F420 */
typedef int u128_37F420 __attribute__((mode(TI)));
extern void func_00388830(s32 a, s32 b, f32 x);
extern void func_0037F228();
extern u8 D_00222500_0037F420[];
void func_0037F420(s32 idx) {
    u128_37F420 v[3];
    u8 *p = D_00222500_0037F420 + idx * 0x460;
    u8 *q = p + 0x150;
    func_00388830((s32)&v[0], *(s32 *)(q + 0xF0) + 0xC0, 1.0f);
    func_00388830((s32)&v[1], *(s32 *)(q + 0xF0) + 0xD0, 1.0f);
    func_00388830((s32)&v[2], *(s32 *)(q + 0xF0) + 0xE0, 1.0f);
    *(u128_37F420 *)(p + 0x330) = v[0];
    *(u128_37F420 *)(p + 0x340) = v[2];
    func_0037F228(p + 0x310, p + 0x360, p + 0x190, &v[0], &v[1], &v[2]);
    *(u128_37F420 *)(p + 0x350) = *(u128_37F420 *)(p + 0x370);
}
/* localdecomp:end func_0037F420 */

/* localdecomp:start func_0037F4F8 */
typedef int u128_37F4F8 __attribute__((mode(TI)));
typedef struct { u8 p0[2]; u8 b2; u8 b3; u8 p4[0x50 - 4]; u128_37F4F8 q50; u128_37F4F8 q60; u8 p70[0xC0 - 0x70]; u128_37F4F8 qC0; u128_37F4F8 qD0; u8 pE0[0x460 - 0xE0]; } E_37F4F8;
extern E_37F4F8 D_002227A0_0037F4F8[];
void func_0037F4F8(s32 idx) {
    s32 off = idx * 0x460;
    E_37F4F8 *e = (E_37F4F8 *)((u8 *)D_002227A0_0037F4F8 + off);
    u8 *b;
    if (e->b2 == 0) {
        e->qC0 = e->q50;
        if (e->b3 == 2) {
            b = (u8 *)D_002227A0_0037F4F8 - 0xE0;
            __asm__ __volatile__("lqc2 $vf2, 0xC0(%0)" : : "r"(e));
            __asm__ __volatile__("lqc2 $vf1, 0(%0)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0xC0(%1)" : : "r"((u8 *)(off + (s32)b)), "r"(e) : "memory");
        }
        e->qD0 = e->q60;
    }
}
/* localdecomp:end func_0037F4F8 */

/* localdecomp:start func_0037F550 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_002227A0[];
void func_0037F550(s32 arg0) {
    u8 *p = D_002227A0 + arg0 * 0x460;
    if (p[2] != 0) {
        *(u128_t *)(p + 0x50) = *(u128_t *)(p + 0xC0);
        *(u128_t *)(p + 0x60) = *(u128_t *)(p + 0xD0);
    }
}
/* localdecomp:end func_0037F550 */

/* localdecomp:start func_0037F588 */
typedef struct { f32 f0, f4, f8, fC, f10, f14, f18, f1C; } A_37F588;
typedef struct { s32 p0[3]; s32 fC; f32 f10; s32 f14; } R_37F588;
typedef struct {
    s16 f0; u8 b2; u8 b3; u8 p4[0xC]; A_37F588 a; u128_t q30; u128_t q40; u128_t q50; u128_t q60; R_37F588 r;
} E_37F588;
extern u8 D_00222500_0037F588[];
extern void func_003BF2A0();
void func_0037F588(u8 *o) {
    s32 idx = *(s32 *)(o + 0x94);
    u8 *p = D_00222500_0037F588 + idx * 0x460;
    E_37F588 *e = (E_37F588 *)(p + 0x2A0);
    u128_t v[3];
    if (e->f0 == 1) {
        if (e->b3 == 0) {
            *(u128_t *)(p + 0x2F0) = *(u128_t *)(o + 0x30);
            func_003BF2A0(p + 0x300, o);
        } else if (e->b3 == 2) {
            *(u128_t *)(p + 0x360) = *(u128_t *)(o + 0x30);
            func_003BF2A0(p + 0x370, o);
            func_0037F420(idx);
        } else {
            func_00388830((s32)&v[0], *(s32 *)(p + 0x240) + 0xC0, 1.0f);
            func_00388830((s32)&v[1], *(s32 *)(p + 0x240) + 0xD0, 1.0f);
            func_00388830((s32)&v[2], *(s32 *)(p + 0x240) + 0xE0, 1.0f);
            func_0037F228(p + 0x310, o + 0x30, *(s32 *)(p + 0x50) + 0x30, &v[0], &v[1], &v[2]);
            func_003BF2A0(p + 0x350, o);
            *(u128_t *)(p + 0x370) = *(u128_t *)(p + 0x350);
        }
    } else if (e->b3 == 2) {
        func_0037F4F8(idx);
        func_0037F420(idx);
    } else if (e->b3 == 1) {
        func_0037F4F8(idx);
        *(u128_t *)(p + 0x350) = *(u128_t *)(p + 0x370);
    } else if (e->b3 == 0) {
        func_0037F550(idx);
    }
    e->f0 = 3;
    e->b2 = e->b3;
    if (e->b2 == 0) {
        A_37F588 *q = &e->a;
        q->f10 = q->f1C;
        q->f14 = q->f18;
        q->f1C = 0;
        e->q40 = e->q50;
        e->a.f0 = q->fC;
        q->fC = 0;
        q->f4 = q->f8;
        e->q30 = e->q60;
    } else {
        R_37F588 *r = &e->r;
        s32 n = r->f14 + 1;
        r->f14 = n;
        r->fC = n;
        r->f10 = 1.0f / (f32)n;
    }
}
/* localdecomp:end func_0037F588 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037F7A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F978);

/* localdecomp:start func_0037FEE8 */
extern u8 D_002227A0[];
extern u8 D_00222500_0037FEE8[];
extern s32 func_0037F7A8();
extern s32 func_0037F978();
void func_0037FEE8(u8 *o) {
    u8 *e;
    u8 *d;
    s32 r;
    e = D_002227A0 + *(s32 *)(o + 0x94) * 0x460;
    if (e[2] == 0) {
        r = func_0037F7A8(o, e + 0x10);
    } else {
        r = func_0037F978(o, e + 0x70);
    }
    if (r) {
        d = D_00222500_0037FEE8 + *(s32 *)(o + 0x94) * 0x460;
        *(u128_t *)(d + 0x380) = *(u128_t *)(o + 0x00);
        *(u128_t *)(d + 0x390) = *(u128_t *)(o + 0x10);
        *(u128_t *)(d + 0x3A0) = *(u128_t *)(o + 0x20);
        *(volatile u128_t *)(d + 0x000) = *(u128_t *)(o + 0x30);
        *(volatile u8 *)(e + 2) = 0;
        *(volatile u16 *)e = 0;
    }
}
/* localdecomp:end func_0037FEE8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037FF90);

INCLUDE_ASM("asm/nonmatchings/text", func_003801C0);

/* localdecomp:start func_003804A0 */
typedef struct { f32 x, y, z, w; } V_3804A0;
typedef union { u128_t q; V_3804A0 v; } Q_3804A0;
typedef struct { Q_3804A0 q0; u8 pad10[0x40]; u8 *f50; u8 pad54[0x3FC]; s32 f450; u8 pad454[0xC]; } E_3804A0;
extern E_3804A0 D_00222500_003804A0[];
extern s32 D_001D5B94;
extern u128_t D_002276E0[];
extern s32 func_003CE740();
extern s32 func_003D00C0(void);
extern f32 func_003BE988(void *, s32);
void func_003804A0(s32 idx) {
    E_3804A0 *e = &D_00222500_003804A0[idx];
    Q_3804A0 a, b;
    s32 i;
    if (*(s16 *)(e->f50 + 0x86) == 6 || D_001D5B94 != 0) {
        e->f450 = 0;
        return;
    }
    a.q = e->q0.q;
    b.q = e->q0.q;
    b.v.z -= 0.75f;
    a.v.z += 0.75f;
    i = 0;
    while (i < 6 && func_003CE740(&a, &b, 0x12, 0, 0)) {
        if (func_003D00C0() == 0) {
            f32 r = func_003BE988(D_002276E0, 0);
            if (D_00222500_003804A0[idx].q0.v.z < r + 0.04f) {
                D_00222500_003804A0[idx].f450 = 1;
            } else {
                D_00222500_003804A0[idx].f450 = 0;
            }
            return;
        }
        i++;
        a.q = D_002276E0[0];
        a.v.z -= 0.01f;
    }
}
/* localdecomp:end func_003804A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_00380600);
TEXT_PADDING(2);

/* localdecomp:start func_003807F0 */
extern f32 D_001D9C50_003807F0; __asm__(".extern D_001D9C50_003807F0, 16");
typedef struct { u8 pad[0xC8]; f32 fC8; f32 fCC; u8 fD0[0x460 - 0xD0]; } S_3807F0;
extern f32 func_003BEBF8(f32 *, f32, f32);
extern s32 func_00388398(void *);
void func_003807F0(s32 a) {
    S_3807F0 *s = (S_3807F0 *)(D_00222560 + a * 0x460);
    if (s->fC8 != 0.0f) {
        func_003BEBF8(&D_001D9C50_003807F0 + a, s->fCC, s->fC8);
        if ((&D_001D9C50_003807F0)[a] == s->fCC) {
            if (func_00388398(s->fD0) == 1) {
                s->fCC = 0.0f;
            }
        }
        if (s->fCC <= 0.0f && (&D_001D9C50_003807F0)[a] <= 0.0f) {
            s->fC8 = 0.0f;
        }
    }
}
/* localdecomp:end func_003807F0 */
TEXT_PADDING(2);

/* localdecomp:start func_003808E0 */
extern f32 D_001D9C58_003808E0; __asm__(".extern D_001D9C58_003808E0, 16");
typedef struct { u8 pad[0xD4]; f32 fD4; f32 fD8; f32 fDC; u8 fE0[0x460 - 0xE0]; } S_3808E0;
extern f32 func_003BEBF8(f32 *, f32, f32);
extern s32 func_00388398(void *);
void func_003808E0(s32 a) {
    S_3808E0 *s = (S_3808E0 *)(D_00222560 + a * 0x460);
    if (s->fD4 != 0.0f) {
        if (s->fDC != 0.0f) {
            func_003BEBF8(&D_001D9C58_003808E0 + a, s->fDC, s->fD4);
        } else {
            func_003BEBF8(&D_001D9C58_003808E0 + a, s->fDC, s->fD8);
        }
        if ((&D_001D9C58_003808E0)[a] == s->fDC) {
            if (func_00388398(s->fE0) == 1) {
                s->fDC = 0.0f;
            }
        }
        if (s->fDC <= 0.0f && (&D_001D9C58_003808E0)[a] <= 0.0f) {
            s->fD4 = 0.0f;
        }
    }
}
/* localdecomp:end func_003808E0 */

/* localdecomp:start func_003809F0 */
typedef struct { u128_t q0; u128_t q1; u8 pad[0x360]; f32 f380[4]; f32 f390[4]; f32 f3a0[4]; f32 f3b0[4]; f32 f3c0[4]; f32 f3d0[4]; u128_t q3e0; u8 pad2[0x70]; } E_003809F0;
extern E_003809F0 D_00222500_003809F0[];
extern u128_t D_00222480[];
extern void func_003885F0();
void func_003809F0(s32 idx) {
    E_003809F0 *e = &D_00222500_003809F0[idx];
    u128_t v;
    e->f3b0[0] = -e->f390[0];
    e->f3c0[0] = -e->f390[1];
    e->f3d0[0] = -e->f390[2];
    e->f3b0[1] = -e->f3a0[0];
    e->f3c0[1] = -e->f3a0[1];
    e->f3d0[1] = -e->f3a0[2];
    e->f3b0[2] = e->f380[0];
    e->f3c0[2] = e->f380[1];
    e->f3d0[2] = e->f380[2];
    v = e->q0;
    e->q3e0 = v;
    D_00222480[0] = v;
    D_00222480[1] = D_00222500_003809F0[idx].q1;
    func_003885F0(&D_00222480[2], D_00222500_003809F0[idx].f380, 0x30);
}
/* localdecomp:end func_003809F0 */

INCLUDE_ASM("asm/nonmatchings/text", func_00380AB0);
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_00380D28);

INCLUDE_ASM("asm/nonmatchings/text", func_00380D48);

INCLUDE_ASM("asm/nonmatchings/text", func_003810C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003813E0);

LINKER_REMNANT("asm/remnants", func_00381A48);

INCLUDE_ASM("asm/nonmatchings/text", func_00381A50);

INCLUDE_ASM("asm/nonmatchings/text", func_00381C18);

LINKER_REMNANT("asm/remnants", func_00381D90);

/* localdecomp:start func_00381DD0 */
typedef struct { u8 p0[0x140]; f32 f140, f144, f148; } S_222340_381DD0;
typedef struct { u8 p0[0x1A0]; f32 f1A0, f1A4; u8 p1A8[0x220 - 0x1A8]; f32 f220; } S_225980_381DD0;
extern S_222340_381DD0 D_00222340_00381DD0;
extern S_225980_381DD0 D_00225980_00381DD0;
extern void func_00388B68();
extern void func_00388F08();
extern void func_003886E8(f32 *, void *, f32);
extern void func_003888F0();
void func_00381DD0(f32 *out, void *arg1) {
    f32 m[16];
    f32 r[16];
    f32 v[4];
    f32 w[4];
    f32 t;
    func_00388B68(m);
    m[12] = -D_00222340_00381DD0.f140 * 1024.0f;
    m[13] = -D_00222340_00381DD0.f144 * 1024.0f;
    m[14] = -D_00222340_00381DD0.f148 * 1024.0f;
    func_00388F08(r, (u8 *)&D_00222340_00381DD0 + 0x40, m);
    func_003886E8(v, arg1, 1024.0f);
    v[3] = 1.0f;
    func_003888F0(w, v, r);
    t = D_00225980_00381DD0.f220 / w[3];
    w[0] = w[0] * t + D_00225980_00381DD0.f1A0;
    w[1] = w[1] * t + D_00225980_00381DD0.f1A4;
    out[2] = w[2] * 0.0009765625f;
    out[1] = w[1] * 16.0f;
    out[0] = w[0] * 16.0f;
}
/* localdecomp:end func_00381DD0 */

LINKER_REMNANT("asm/remnants", func_00381F10);

/* localdecomp:start func_00381F18 */
typedef struct { f32 x, y, z, w; } V_381F18;
typedef union { u128_t q; V_381F18 v; } Q_381F18;
extern u8 D_00222340_00381F18[];
extern u8 D_00225980_00381F18[];
extern u8 D_00225C00[];
extern u8 D_001D5477_00381F18;
extern void func_00388758();
extern void func_00388718_00381F18(void *, void *, f32);
void func_00381F18(void) {
    Q_381F18 r[4];
    f32 *m;
    f32 sx, sy, sz;
    u8 *s;
    if (D_001D5477_00381F18 != 0) {
        func_00388758(D_00222340_00381F18 + 0x170, D_00222340_00381F18 + 0x180, D_00222340_00381F18 + 0x160);
    }
    r[0].q = *(u128_t *)(D_00222340_00381F18 + 0x160);
    r[1].q = *(u128_t *)(D_00222340_00381F18 + 0x170);
    r[2].q = *(u128_t *)(D_00222340_00381F18 + 0x180);
    m = (f32 *)D_00222340_00381F18;
    m[0] = -r[1].v.x;
    m[4] = -r[1].v.y;
    m[8] = -r[1].v.z;
    m[1] = -r[2].v.x;
    m[5] = -r[2].v.y;
    m[9] = -r[2].v.z;
    m[2] = r[0].v.x;
    m[6] = r[0].v.y;
    m[10] = r[0].v.z;
    m[15] = 1.0f;
    m[12] = 0;
    m[13] = 0;
    m[14] = 0;
    m[3] = 0;
    m[7] = 0;
    m[11] = 0;
    func_00388F08(D_00222340_00381F18 + 0x40, D_00225980_00381F18 + 0xC0, m);
    func_00388F08(D_00222340_00381F18 + 0x80, D_00225980_00381F18 + 0x100, m);
    s = D_00225980_00381F18;
    sx = *(f32 *)(s + 0x1A0);
    sy = *(f32 *)(s + 0x1A4);
    sz = *(f32 *)(s + 0x1A8);
    m[32] += m[35] * sx;
    m[33] += m[35] * sy;
    m[34] += m[35] * sz;
    m[36] += m[39] * sx;
    m[37] += m[39] * sy;
    m[38] += m[39] * sz;
    m[40] += m[43] * sx;
    m[41] += m[43] * sy;
    m[42] += m[43] * sz;
    m[44] += m[47] * sx;
    m[45] += m[47] * sy;
    m[46] += m[47] * sz;
    func_00388F08(D_00222340_00381F18 + 0xC0, D_00225980_00381F18 + 0x140, m);
    func_00388718_00381F18(D_00222340_00381F18 + 0x100, D_00225980_00381F18 + 0x140, *(f32 *)(s + 0x1C0));
    func_00388718_00381F18(D_00222340_00381F18 + 0x110, D_00225980_00381F18 + 0x150, *(f32 *)(s + 0x1C4));
    *(u128_t *)((u8 *)m + 0x120) = *(u128_t *)(s + 0x160);
    *(u128_t *)((u8 *)m + 0x130) = *(u128_t *)(s + 0x170);
    func_00388F08(D_00222340_00381F18 + 0x100, D_00222340_00381F18 + 0x100, m);
    *(u128_t *)(D_00225C00 + 0x00) = *(u128_t *)(D_00222340_00381F18 + 0x00);
    *(u128_t *)(D_00225C00 + 0x10) = *(u128_t *)(D_00222340_00381F18 + 0x10);
    *(u128_t *)(D_00225C00 + 0x20) = *(u128_t *)(D_00222340_00381F18 + 0x20);
    func_003886E8((f32 *)(D_00225C00 + 0x30), D_00222340_00381F18 + 0x140, 1024.0f);
    *(f32 *)(D_00225C00 + 0x3C) = 1024.0f;
}
/* localdecomp:end func_00381F18 */

/* localdecomp:start func_003821E8 */
typedef struct { u8 pad[0x450]; s32 f450; } E_3821E8;
extern u8 D_00222500_003821E8[];
typedef struct { u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C; u8 p240[0x10]; s32 f250; s32 f254; s32 f258; } S_3821E8;
extern S_3821E8 D_00225980;
extern u8 D_001D9A2C, D_001D9A2D, D_001D9A2E, D_001D9CC4, D_001D9CC5, D_001D9CC6;
extern f32 D_001D9A44, D_001D9A48, D_001D9A4C, D_001D9A50, D_001D9CC8, D_001D9CCC, D_001D9CD0, D_001D9CD4;
extern s32 D_001DA650, D_001D9CD8;
extern void func_003830E8();
void func_003821E8(s32 a) {
    s32 c;
    if (((E_3821E8 *)(a * 0x460 + (s32)D_00222500_003821E8))->f450 != 0) {
        D_00225980.f250 = D_001D9A2C;
        D_00225980.f254 = D_001D9A2D;
        D_00225980.f258 = D_001D9A2E;
        D_00225980.f228 = D_001D9A44;
        D_00225980.f22C = D_001D9A48;
        D_00225980.f238 = D_001D9A4C;
        D_00225980.f23C = D_001D9A50;
        c = 0x40000;
    } else {
        D_00225980.f250 = D_001D9CC4;
        D_00225980.f254 = D_001D9CC5;
        D_00225980.f258 = D_001D9CC6;
        D_00225980.f228 = D_001D9CC8;
        D_00225980.f22C = D_001D9CCC;
        D_00225980.f238 = D_001D9CD0;
        D_00225980.f23C = D_001D9CD4;
        c = 0x7D0000;
    }
    D_001DA650 = c;
    func_003830E8();
    D_001D9CD8 = 0;
}
/* localdecomp:end func_003821E8 */

/* localdecomp:start func_003822C8 */
extern u8 *D_001D9DC0[];
s32 func_003822C8(s32 a0, s32 a1, s32 a2) {
    u8 *b = D_001D9DC0[0];
    u8 *res = b + *(s32 *)b;
    u16 *p = (u16 *)(b + 4);
    s32 y = a2 - p[0];
    s32 x, z;
    if (y < 0 || y >= p[1]) return 0;
    if ((*(volatile u16 *)&p[2 + y]) == 0) return 0;
    p = (u16 *)(b + p[2 + y] * 4);
    x = a1 - p[0];
    if (x < 0 || x >= p[1]) return 0;
    if ((*(volatile u16 *)&p[2 + x]) == 0) return 0;
    p = (u16 *)(b + p[2 + x] * 4);
    z = a0 - p[0];
    if (z < 0 || z >= p[1]) return 0;
    if (p[2 + z] == 0xFFFF) return 0;
    return (s32)(res + (p[2 + z] << 7));
}
/* localdecomp:end func_003822C8 */

/* localdecomp:start func_003823A0 */
extern s32 func_003822C8();
void func_003823A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 fparg0) {
    s32 var_4;
    s32 var_5;
    s32 var_6;

    if (fparg0 < 0.5f) {
        if (((s32 (*)())func_003822C8)() == 0) {
            var_4 = arg3;
            var_5 = arg4;
            var_6 = arg5;
            goto block_5;
        }
    } else if (((s32 (*)())func_003822C8)(arg3, arg4, arg5) == 0) {
        var_4 = arg0;
        var_5 = arg1;
        var_6 = arg2;
block_5:
        ((s32 (*)())func_003822C8)(var_4, var_5, var_6);
    }
}
/* localdecomp:end func_003823A0 */

/* localdecomp:start func_00382458 */
typedef struct { u8 pad[0x140]; f32 x, y, z; } S_382458;
typedef struct { f32 x, y, z, w; u8 d[1][0x80]; } G_382458;
extern S_382458 D_00222340;
extern G_382458 *D_001D9DC4, *D_001D9DC8, *D_001D9DCC;
extern u8 *D_001D9DE0[2];
extern s32 D_001D9DD8;
extern s32 D_001D9DD0_00382458;
extern s32 D_001D52F0;
extern u8 D_00227580[];
extern s32 D_00227500[];
extern void func_003823A0(s32, s32, s32, s32, s32, s32, f32);
extern void func_00388440();
extern void func_00388468();
extern void func_00388618();
extern f32 func_00388800();
extern f32 func_00388A28(f32, f32);

s32 func_00382458(void) {
    f32 v[4];
    f32 d[4];
    s32 x = D_00222340.x * 0.25f;
    s32 y = D_00222340.y * 0.25f;
    s32 z = D_00222340.z * 0.25f;
    u8 *r = (u8 *)func_003822C8(x, y, z);
    if (r != 0) {
        D_001D9DD8 = 0;
        func_003885F0(D_00227500, r, 0x80);
        D_001D9DE0[D_001D52F0] = r;
    } else {
        D_001D9DD8 = 1;
        if (D_001D9DD0_00382458 == 0) {
            s32 a = ((s32 (*)(s32, s32, s32, s32, s32, s32, f32))func_003823A0)(x - 1, y, z, x + 1, y, z, D_00222340.x * 0.25f - x);
            s32 b = ((s32 (*)(s32, s32, s32, s32, s32, s32, f32))func_003823A0)(x, y - 1, z, x, y + 1, z, D_00222340.y * 0.25f - y);
            s32 c = ((s32 (*)(s32, s32, s32, s32, s32, s32, f32))func_003823A0)(x, y, z - 1, x, y, z + 1, D_00222340.z * 0.25f - z);
            if (a != 0 || b != 0 || c != 0) {
                func_00388468(D_00227580, 0x80);
                if (a != 0) func_00388618(D_00227580, D_00227580, a, 0x80);
                if (b != 0) func_00388618(D_00227580, D_00227580, b, 0x80);
                if (c != 0) func_00388618(D_00227580, D_00227580, c, 0x80);
                r = D_00227580;
                D_001D9DE0[D_001D52F0] = r;
                func_003885F0(D_00227500, r, 0x80);
            }
        }
        if (r == 0) {
            switch (D_001D9DD0_00382458) {
            case 2:
                if (D_001D9DC4 != 0) {
                    G_382458 *p = D_001D9DC4;
                    s32 a = D_00222340.x - p->x > 0.0f;
                    s32 b = D_00222340.y - p->y > 0.0f;
                    s32 c = D_00222340.z - p->z > 0.0f;
                    func_003885F0(D_00227500, p->d[c + b * 2 + a * 4], 0x80);
                    break;
                }
                goto case0;
            case 3:
                if (D_001D9DC8 != 0) {
                    s32 idx = 0;
                    v[0] = D_001D9DC8->x;
                    v[1] = D_001D9DC8->y;
                    v[2] = D_001D9DC8->z;
                    v[3] = 0.0f;
                    d[0] = D_00222340.x - v[0];
                    d[1] = D_00222340.y - v[1];
                    d[2] = D_00222340.z - v[2];
                    d[3] = 0.0f;
                    if (d[0] > 0.0f && d[1] > 0.0f) {
                        idx = (s32)(func_00388A28(d[0], d[1]) * 32.0f / 3.1415927f) << 6;
                        d[0] = func_00388800(&D_00222340.x, v);
                    } else if (d[0] <= 0.0f && d[1] > 0.0f) {
                        idx = 0x400;
                        if (d[0] == 0.0f) d[0] = d[1];
                        else {
                            idx = ((s32)(func_00388A28(d[1], 0.0f - d[0]) * 32.0f / 3.1415927f) << 6) + 0x400;
                            d[0] = func_00388800(D_00222480, v);
                        }
                    } else if (d[0] < 0.0f && d[1] < 0.0f) {
                        idx = (s32)(func_00388A28(0.0f - d[0], 0.0f - d[1]) * 32.0f / 3.1415927f) << 6;
                        d[0] = 0.0f - func_00388800(D_00222480, v);
                    } else if (d[0] >= 0.0f && d[1] < 0.0f) {
                        idx = 0x400;
                        if (d[0] == 0.0f) d[0] = d[1];
                        else {
                            idx = ((s32)(func_00388A28(0.0f - d[1], d[0]) * 32.0f / 3.1415927f) << 6) + 0x400;
                            d[0] = 0.0f - func_00388800(D_00222480, v);
                        }
                    }
                    if (d[2] > 0.0f && d[0] > 0.0f) {
                        idx += (s32)(func_00388A28(d[2], d[0]) * 32.0f / 3.1415927f);
                    } else if (d[2] <= 0.0f && d[0] > 0.0f) {
                        idx += 0x10;
                        if (d[2] != 0.0f) idx += (s32)(func_00388A28(d[0], 0.0f - d[2]) * 32.0f / 3.1415927f);
                    } else if (d[2] < 0.0f && d[0] <= 0.0f) {
                        idx += 0x20;
                        if (d[0] != 0.0f) idx += (s32)(func_00388A28(0.0f - d[2], 0.0f - d[0]) * 32.0f / 3.1415927f);
                    } else if (d[2] >= 0.0f && d[0] < 0.0f) {
                        idx += 0x30;
                        if (d[2] != 0.0f) idx += (s32)(func_00388A28(0.0f - d[0], d[2]) * 32.0f / 3.1415927f);
                    }
                    func_003885F0(D_00227500, D_001D9DC8->d[idx], 0x80);
                    break;
                }
            case0:
            case 0:
                if (D_001D9DE0[D_001D52F0] != 0) {
                    func_003885F0(D_00227500, D_001D9DE0[D_001D52F0], 0x80);
                    break;
                }
            case 1:
                func_00388440(D_00227500, -1, 0x80);
                break;
            case 4:
                if (D_001D9DCC != 0) {
                    s32 idx = 0;
                    v[0] = D_001D9DCC->x;
                    v[1] = D_001D9DCC->y;
                    v[2] = D_001D9DCC->z;
                    v[3] = 0.0f;
                    d[0] = D_00222340.x - v[0];
                    d[1] = D_00222340.y - v[1];
                    d[2] = D_00222340.z - v[2];
                    d[3] = 0.0f;
                    if (d[0] > 0.0f && d[1] > 0.0f) {
                        idx = (s32)(func_00388A28(d[0], d[1]) * 32.0f / 3.1415927f) << 6;
                        d[0] = func_00388800(&D_00222340.x, v);
                    } else if (d[0] <= 0.0f && d[1] > 0.0f) {
                        idx = 0x400;
                        if (d[0] == 0.0f) d[0] = d[1];
                        else {
                            idx = ((s32)(func_00388A28(d[1], 0.0f - d[0]) * 32.0f / 3.1415927f) << 6) + 0x400;
                            d[0] = func_00388800(D_00222480, v);
                        }
                    } else if (d[0] < 0.0f && d[1] < 0.0f) {
                        idx = (s32)(func_00388A28(0.0f - d[0], 0.0f - d[1]) * 32.0f / 3.1415927f) << 6;
                        d[0] = 0.0f - func_00388800(D_00222480, v);
                    } else if (d[0] >= 0.0f && d[1] < 0.0f) {
                        idx = 0x400;
                        if (d[0] == 0.0f) d[0] = d[1];
                        else {
                            idx = ((s32)(func_00388A28(0.0f - d[1], d[0]) * 32.0f / 3.1415927f) << 6) + 0x400;
                            d[0] = 0.0f - func_00388800(D_00222480, v);
                        }
                    }
                    if (d[2] > 0.0f && d[0] > 0.0f) {
                        idx += (s32)(func_00388A28(d[2], d[0]) * 32.0f / 3.1415927f);
                    } else if (d[2] <= 0.0f && d[0] > 0.0f) {
                        idx += 0x10;
                        if (d[2] != 0.0f) idx += (s32)(func_00388A28(d[0], 0.0f - d[2]) * 32.0f / 3.1415927f);
                    } else if (d[2] < 0.0f && d[0] <= 0.0f) {
                        idx += 0x20;
                        if (d[0] != 0.0f) idx += (s32)(func_00388A28(0.0f - d[2], 0.0f - d[0]) * 32.0f / 3.1415927f);
                    } else if (d[2] >= 0.0f && d[0] < 0.0f) {
                        idx += 0x30;
                        if (d[2] != 0.0f) idx += (s32)(func_00388A28(0.0f - d[0], d[2]) * 32.0f / 3.1415927f);
                    }
                    func_003885F0(D_00227500, D_001D9DCC->d[idx], 0x80);
                } else if (D_001D9DE0[D_001D52F0] != 0) {
                    func_003885F0(D_00227500, D_001D9DE0[D_001D52F0], 0x80);
                } else {
                    func_00388440(D_00227500, -1, 0x80);
                }
                break;
            }
        }
    }
    {
        u8 *q = (u8 *)D_00227500;
        q[0x7F] |= 0x80;
    }
}
/* localdecomp:end func_00382458 */

/* localdecomp:start func_00382F40 */
extern s32 func_00382458();
extern void func_00388440();
extern s32 D_001D9DD4;
extern s32 D_00227500[];

void func_00382F40(void) {
    if (D_001D9DD4 == 0) {
        func_00388440(D_00227500, -1, 0x80);
    } else if (D_001D9DD4 == 2) {
        func_00382458();
    }
}
/* localdecomp:end func_00382F40 */

INCLUDE_ASM("asm/nonmatchings/text", func_00382F90);

INCLUDE_ASM("asm/nonmatchings/text", func_003830E8);

LINKER_REMNANT("asm/remnants", func_00383840);

/* localdecomp:start func_00383848 */
extern s32 D_001D9C88[], D_001D9C90[], D_001D9C94[], D_001D9C8C[], D_001D9CB8[], D_001D9CC0[], D_001D9C5C[], D_001D9C60[];
extern s32 D_001D9DD0[], D_001D9A54[], D_001D9A58[], D_001D9A40[];
extern u8 D_001D5884, D_001D58C0, D_001D58D0;
extern s32 D_001D9A28;
void func_00383848(void) {
    D_001D9C88[0] = 0;
    D_001D9C90[0] = 0;
    D_001D9C94[0] = 0;
    D_001D9C8C[0] = 0;
    D_001D9CB8[0] = 0;
    D_001D9CC0[0] = 0;
    D_001D9C5C[0] = 0;
    D_001D9C60[0] = 0;
    D_001D5884 = 0;
    D_001D58C0 = 0;
    D_001D58D0 = 0;
    D_001D9DD0[0] = 0;
    D_001D9A54[0] = 0;
    D_001D9A58[0] = 0;
    D_001D9A40[0] = 0;
    D_001D9A28 = 0;
}
/* localdecomp:end func_00383848 */

/* localdecomp:start func_003838C0 */
extern u32 *D_001DA0D0_003838C0;
__asm__(".extern D_001DA0D0_g, 4");
extern u32 *D_001DA0D0_g;
extern u8 D_001421B0[];
extern u8 D_00142120[];
extern long D_001D5330_003838C0[];
typedef struct { u8 p0[0x240]; s32 f240, f244, f248, f24C, f250, f254, f258; } S_225980_3838C0;
extern S_225980_3838C0 D_00225980_003838C0;
extern void func_00388550();
extern void func_003A3EF0(s32, unsigned long);
void func_003838C0(void) {
    D_001DA0D0_003838C0[0] = 0x30000013;
    D_001DA0D0_003838C0[1] = (u32)D_001421B0;
    D_001DA0D0_003838C0[2] = 0;
    D_001DA0D0_003838C0[3] = 0x50000013;
    D_001DA0D0_003838C0 += 4;
    D_001DA0D0_003838C0[0] = 0x30000009;
    D_001DA0D0_003838C0[1] = (u32)D_00142120;
    D_001DA0D0_003838C0[2] = 0;
    D_001DA0D0_003838C0[3] = 0x50000009;
    D_001DA0D0_003838C0 += 4;
    D_001DA0D0_003838C0[0] = 0x10000003;
    D_001DA0D0_003838C0[1] = 0;
    D_001DA0D0_003838C0[2] = 0;
    D_001DA0D0_003838C0[3] = 0x50000003;
    D_001D5330_003838C0[2] = (long)D_00225980_003838C0.f240 | ((long)D_00225980_003838C0.f244 << 16) | ((long)D_00225980_003838C0.f248 << 32) | ((long)D_00225980_003838C0.f24C << 48);
    D_001DA0D0_003838C0 += 4;
    D_001D5330_003838C0[4] = (long)D_00225980_003838C0.f240 | ((long)D_00225980_003838C0.f244 << 16) | ((long)D_00225980_003838C0.f248 << 32) | ((long)D_00225980_003838C0.f24C << 48);
    func_00388550(D_001DA0D0_003838C0, D_001D5330_003838C0, 0x30);
    D_001DA0D0_g = (u32 *)((u8 *)D_001DA0D0_003838C0 + 0x30);
    func_003A3EF0(0x3D, (long)D_00225980_003838C0.f250 | ((long)D_00225980_003838C0.f254 << 8) | ((long)D_00225980_003838C0.f258 << 16));
    func_003A3EF0(0x51, 0);
}
/* localdecomp:end func_003838C0 */

/* localdecomp:start func_00383A90 */
extern unsigned long D_001CFEC8[];
void func_00383A90(void) {
    *(volatile unsigned long *)0x120000E0 = 0;
    *(volatile unsigned long *)0x12000000 = 0xFFA1;
    *(volatile unsigned long *)0x12000020 = D_001CFEC8[0];
    *(volatile unsigned long *)0x12000070 = D_001CFEC8[1];
    *(volatile unsigned long *)0x12000090 = D_001CFEC8[1];
    *(volatile unsigned long *)0x12000080 = D_001CFEC8[2];
    *(volatile unsigned long *)0x120000A0 = D_001CFEC8[2];
    *(volatile unsigned long *)0x120000D0 = 0;
}
/* localdecomp:end func_00383A90 */

/* localdecomp:start func_00383B08 */
extern void func_0038DC08(s32, s32, s32, s32);
extern void func_003A3EF0(s32, unsigned long);
extern void func_0038E030(s32, s32);
void func_00383B08(s32 a0, s32 a1) {
    s32 n = a0 + a1;
    if (n > 16) {
        n = 16;
    }
    func_0038DC08(a0, a1, ((0x3FF000 - (4 << n)) >> 13) << 13, 1);
    func_003A3EF0(0x47, 0x30000);
    func_003A3EF0(0x42, 0x8000000044);
    func_0038E030(0x100, 0x100);
    func_003A3EF0(0x42, 0x8000000044);
}
/* localdecomp:end func_00383B08 */

/* localdecomp:start func_00383B90 */
extern void func_0038DA80(void);
void func_00383B90(void) {
    func_0038DA80();
}
/* localdecomp:end func_00383B90 */

INCLUDE_ASM("asm/nonmatchings/text", func_00383BB0);

INCLUDE_ASM("asm/nonmatchings/text", func_00383FD8);

LINKER_REMNANT("asm/remnants", func_00384418);

/* localdecomp:start func_00384420 */
__asm__(".extern D_001D58D0, 4");
__asm__(".extern D_001D5884, 1");

typedef int u128_00384420 __attribute__((mode(TI)));
typedef struct { u8 pad[0x450]; s32 x450; u8 pad454[0xC]; } P_00384420;
typedef struct { u8 pad0[4]; s16 x4; } C_00384420;
typedef struct { u128_00384420 q[4]; } Q_00384420;

extern C_00384420 *D_001DA670;
extern s32 D_001D9C44;
extern s32 D_001D9D9C;
extern s32 D_001D9388;
extern s32 D_001D938C;
extern s32 D_001D9C90_00384420;
extern s32 D_001D9C94_00384420;
extern u8 D_001D58D0;
extern s32 D_001D5B94;
extern s32 D_001D9C88_00384420;
extern s32 D_001D9C8C_00384420;
extern s32 D_001D93A4;
extern s32 D_001D93A8;
extern s32 D_001D9CB8_00384420;
extern volatile s32 D_001D9F40;
extern s32 D_001D52F0;
extern P_00384420 D_00222500_00384420[];
extern u8 D_001D5780;
extern u8 D_001D5781;
extern u8 D_001D5782;
extern u8 D_001D5783;
extern f32 D_001D9C50;
extern f32 D_001D9C58[2];
extern s32 D_001D5B98;
extern u8 D_001D5884;
extern s32 D_001D58B8;
extern u8 D_100AE0[];
extern s32 D_00143950[];
extern f32 D_001D9D90;
extern s32 D_001D9DD0_00384420;
extern u8 D_002F9C80[];
extern u8 D_00302540[];
extern Q_00384420 D_00225B20;
extern Q_00384420 D_00330F00;

extern void func_0038DB18(s32);
extern void func_00381F18(void);
extern void func_003BD8A0(void);
extern void func_00382F40(void);
extern void func_003838C0(void);
extern void func_00388278(void);
extern void func_003C9B80(void);
extern void func_003A4720_00384420(s32);
extern void func_003D47A0(void);
extern void func_003A4188(void);
extern void func_00384B68(s32);
extern void func_00385750(void);
extern void func_00384C98(void);
extern void func_003A4128(void);
extern void func_003D99D8(void);
extern void func_00386608_00384420(u8 *);
extern void func_003857C8(void);
extern void func_00383FD8(void);
extern void func_003BE340(void);
extern void func_003856D8(void);
extern void func_003A3EF0(s32, unsigned long);
extern void func_00380D48(void);
extern void func_00385980(void);
extern void func_11F0A0(s32);
extern void func_003C7E68(void);
extern void func_00385890(void);
extern void func_003D3050_00384420(s32);
extern void func_003D30D0(void);
extern void func_003D3CF0_00384420(s32);
extern void func_00385908(void);
extern void func_00381A50(s32);
extern void func_0038DEB0(void);
extern s32 func_0039BEA8(s32);
extern void func_00386210(void);
extern void func_003A4758_00384420(s32);
extern void func_003AA0B8(void);
extern void func_00391FD8(void);
extern void func_003ADB40(void);
extern void func_003ADBB0(s32);
extern void func_003ADB78(void);
extern void func_0037DD08(void);
extern void func_00385E40(void);
extern void func_003866E8(s32, s32, s32, s32);
extern void func_00386488(void);
extern void func_003A3A40_00384420(void *);
extern void func_003A3DA0(s32);
extern void func_003CAC10(void *);
extern void func_003C9AE0(void);
extern void func_003D8218(void);
extern void func_003D46E0(void);
extern void func_003DB5C0(void *);
extern void func_003D98D0(void);
extern void func_003BDC90(void);
extern void func_003821E8(s32);

void func_00384420(s32 arg0) {
    s32 t;
    s32 t2;
    f32 d, n;
    u128_00384420 *src, *dst;

    if (D_001DA670 == 0 || D_001DA670->x4 != 0 || ((*(u8 *)&D_001D9C44 ^ 1) & 1)) {
        func_0038DB18(0);
    }
    func_00381F18();
    func_003BD8A0();
    func_00382F40();
    func_003838C0();
    D_001D9D9C = -1;
    D_001D9388 = 0;
    D_001D938C = 0;
    if (D_001DA670 != 0 && (D_001D9C44 & 1)) {
        func_00388278();
    }
    if (D_001D9C44 & 2) {
        func_003C9B80();
    }
    func_003A4720_00384420(0x2010000);
    if (D_001D9C44 & 4) {
        func_003D47A0();
    }
    func_003A4720_00384420(0x2020000);
    if ((D_001D9C44 & 0x20) && D_001D9C90_00384420 != 0) {
        func_003A4188();
        func_00384B68(1);
        func_00385750();
        func_00384C98();
        func_003A4128();
    }
    if (D_001D9C44 & 8) {
        func_003D99D8();
    }
    func_003A4720_00384420(0x2040000);
    if (D_001D58D0) {
        func_00386608_00384420(&D_001D58D0);
    }
    if ((D_001D9C44 & 0x20) && D_001D9C94_00384420 != 0) {
        func_003A4188();
        func_00384B68(1);
        func_003857C8();
        func_00384C98();
        func_003A4128();
    }
    if (D_001D9C44 & 0x10) {
        if (D_001D5B94 == 2) {
            func_00383FD8();
        } else {
            func_003BE340();
        }
    }
    func_003A4720_00384420(0x2080000);
    func_00384B68(0);
    if (D_001D9C44 & 0x20) {
        func_003A4188();
        if (D_001D9C88_00384420 != 0) {
            func_003856D8();
        }
        func_003A3EF0(0x42, 0x8000000048);
        func_00380D48();
        func_003A4188();
        func_00385980();
        func_003A3EF0(8, 5);
        func_003A4188();
        func_003A3EF0(0x47, 0x53001);
        func_11F0A0(0);
        func_003C7E68();
        D_001D9D9C = 9;
        func_003A3EF0(0x47, 0x5360B);
        if (D_001D9C8C_00384420 != 0) {
            func_003A4188();
            func_00385890();
        }
        func_00384C98();
        if (D_001D9388 != 0) {
            func_003D3050_00384420(0);
            if (D_001D9388 != 0) {
                func_003D30D0();
            }
        }
        if (D_001D93A4 != 0) {
            func_003D3CF0_00384420(0);
        }
        t2 = D_001D93A4;
        D_001D93A4 = 0;
        D_001D93A8 = t2;
        func_00384B68(0);
        if (D_001D9CB8_00384420 != 0) {
            func_003A4188();
            func_00385908();
        }
        func_003A3EF0(0x42, 0x8000000044);
        func_00381A50(arg0);
        func_00384C98();
    }
    func_0038DEB0();
    func_00384B68(0);
    func_003A4188();
    if ((D_001D9C44 & 0x180) && func_0039BEA8(3) == 0) {
        func_003A3EF0(0x47, 0x33001);
        func_00386210();
        if (D_001D9C44 & 0x80) {
            func_003A4758_00384420(0);
            func_003AA0B8();
            t = D_001D9F40;
            func_00391FD8();
            D_001D9F40 = t;
            func_003ADB40();
            func_003ADBB0(D_001D52F0);
            func_003ADB78();
            func_0037DD08();
        }
    }
    if (D_001D5B94 == 2) {
        func_00385E40();
    }
    func_00384C98();
    if (D_001D9C44 & 0x40) {
        func_003A3EF0(0x42, 0x8000000044);
        if (((P_00384420 *)((u8 *)D_00222500_00384420 + arg0 * sizeof(P_00384420)))->x450 != 0) {
            func_003866E8(D_001D5780, D_001D5781, D_001D5782, D_001D5783);
        }
        if (D_001D9C50 > 0.0f && D_001D5B98 == 0) {
            if (D_001D9C50 > 1.0f) {
                D_001D9C50 = 1.0f;
            }
            func_003866E8(0, 0, 0, D_001D9C50 * 128.0f);
        }
        if (D_001D9C58[0] > 0.0f && D_001D5B98 == 0) {
            if (D_001D9C58[0] > 1.0f) {
                D_001D9C58[0] = 1.0f;
            }
            func_003866E8(0xFF, 0xFF, 0xFF, D_001D9C58[arg0] * 128.0f);
        }
        if (D_001D5884 && D_001D58B8 != 0) {
            func_00386488();
        }
    }
    func_003A3A40_00384420(D_100AE0);
    func_11F0A0(0);
    n = *(volatile u32 *)0x10000800;
    D_001D9D90 = n / (D_00143950[0] != 0 ? 11520.0f : 9600.0f);
    func_003A3DA0(2);
    if (D_001D9C44 & 2) {
        func_003CAC10(D_002F9C80);
        func_003C9AE0();
    }
    func_003A3DA0(4);
    if (D_001D9C44 & 4) {
        src = (u128_00384420 *)&D_00225B20;
        dst = (u128_00384420 *)&D_00330F00;
        dst[0] = src[0];
        dst[1] = src[-1];
        dst[2] = src[2];
        func_003D8218();
        func_003D46E0();
    }
    func_003A3DA0(8);
    if (D_001D9C44 & 8) {
        func_003DB5C0(D_00302540);
        func_003D98D0();
    }
    func_003A3DA0(0x10);
    if (D_001D9C44 & 0x10) {
        func_003BDC90();
    }
    func_003821E8(arg0);
    D_001D9DD0_00384420 = 0;
}
/* localdecomp:end func_00384420 */

LINKER_REMNANT("asm/remnants", func_00384B48);

INCLUDE_ASM("asm/nonmatchings/text", func_00384B68);

/* localdecomp:start func_00384C98 */
extern u32 *D_001DA0D0_00384C98;
extern u32 *D_001D9C74_00384C98;
extern u32 *D_001D9C78_00384C98;
extern void func_0039B2E8();
extern s32 func_003A40C8_00384C98();
void func_00384C98(void) {
    D_001D9C78_00384C98 = D_001DA0D0_00384C98;
    D_001DA0D0_00384C98 += 4;
    D_001D9C74_00384C98[0] = 0x20000000;
    D_001D9C74_00384C98[1] = (u32)D_001DA0D0_00384C98;
    D_001D9C74_00384C98[2] = 0;
    D_001D9C74_00384C98[3] = 0;
    func_0039B2E8();
    func_003A40C8_00384C98();
    D_001DA0D0_00384C98[0] = 0x20000000;
    D_001DA0D0_00384C98[1] = (u32)(D_001D9C74_00384C98 + 4);
    D_001DA0D0_00384C98[2] = 0;
    D_001DA0D0_00384C98[3] = 0;
    D_001DA0D0_00384C98 += 4;
    D_001D9C78_00384C98[0] = 0x20000000;
    D_001D9C78_00384C98[1] = (u32)D_001DA0D0_00384C98;
    D_001D9C78_00384C98[2] = 0;
    D_001D9C78_00384C98[3] = 0;
}
/* localdecomp:end func_00384C98 */

INCLUDE_ASM("asm/nonmatchings/text", func_00384DA0);
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_00384EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_00384EC0);

INCLUDE_ASM("asm/nonmatchings/text", func_00385438);

/* localdecomp:start func_00385570 */
extern s32 D_001D4BB0;
extern s32 D_001DA0D0;
extern u8 D_003314E0[];
extern u8 D_00331550[];
extern void func_00388550();
extern void func_003A40C8();
s32 func_00385570(s32 a, s32 b) {
    u8 *p;
    s32 h = D_001D4BB0 >> 8;
    if (b == 0x14) {
        func_00388550(D_001DA0D0, D_003314E0, 0x70);
        D_001D4BB0 = D_001D4BB0 + 0x100;
    } else {
        func_00388550(D_001DA0D0, D_00331550, 0x70);
        D_001D4BB0 = D_001D4BB0 + 0x400;
    }
    p = (u8 *)D_001DA0D0;
    *(s32 *)(p + 0x64) = a;
    *(s16 *)(p + 0x24) = h;
    D_001DA0D0 = D_001DA0D0 + 0x70;
    func_003A40C8();
    return h;
}
/* localdecomp:end func_00385570 */

INCLUDE_ASM("asm/nonmatchings/text", func_00385628);

/* localdecomp:start func_00385688 */
extern s32 D_001D9C88_00385688;
extern s32 D_00226880_00385688[];
extern s32 D_00226980[];
void func_00385688(s32 a, s32 b) {
    if (D_001D9C88_00385688 < 64) {
        D_00226880_00385688[D_001D9C88_00385688] = a;
        D_00226980[D_001D9C88_00385688] = b;
        D_001D9C88_00385688++;
    }
}
/* localdecomp:end func_00385688 */

/* localdecomp:start func_003856D8 */
extern s32 D_001D9C88_003856D8;
extern void (*D_00226880[])(s32);
extern s32 D_00226980[];
void func_003856D8(void) {
    s32 i;
    for (i = 0; i < D_001D9C88_003856D8; i++) D_00226880[i](D_00226980[i]);
}
/* localdecomp:end func_003856D8 */

/* localdecomp:start func_00385750 */
extern s32 D_001D9C90_00385750;
extern void (*D_00226C80[])(s32);
extern s32 D_00226D80[];
void func_00385750(void) {
    s32 i;
    for (i = 0; i < D_001D9C90_00385750; i++) D_00226C80[i](D_00226D80[i]);
}
/* localdecomp:end func_00385750 */

/* localdecomp:start func_003857C8 */
extern s32 D_001D9C94_003857C8;
extern void (*D_00226E80[])(s32);
extern s32 D_00226F80[];
void func_003857C8(void) {
    s32 i;
    for (i = 0; i < D_001D9C94_003857C8; i++) D_00226E80[i](D_00226F80[i]);
}
/* localdecomp:end func_003857C8 */

/* localdecomp:start func_00385840 */
extern s32 D_001D9C8C_00385840;
extern s32 D_00226B80[];
extern s32 D_00226A80_00385840[];
void func_00385840(s32 a, s32 b) {
    s32 n = D_001D9C8C_00385840;
    if (n < 0x40) {
        D_00226A80_00385840[n] = a;
        D_00226B80[n] = b;
        D_001D9C8C_00385840 = n + 1;
    }
}
/* localdecomp:end func_00385840 */

/* localdecomp:start func_00385890 */
extern s32 D_001D9C8C_00385890;
extern void (*D_00226A80[])(s32);
extern s32 D_00226B80[];
void func_00385890(void) {
    s32 i;
    for (i = 0; i < D_001D9C8C_00385890; i++) D_00226A80[i](D_00226B80[i]);
}
/* localdecomp:end func_00385890 */

/* localdecomp:start func_00385908 */
extern int D_001D9CB8_00385908;
extern void (*D_001D9C98[])(int);
extern int D_001D9CA8[];

void func_00385908(void) {
    int index;
    register void (**callbacks)(int) __asm__("$17");
    register int *arguments __asm__("$18");

    index = 0;
    if (D_001D9CB8_00385908 > 0) {
        arguments = D_001D9CA8;
        __asm__ volatile("" : "+r"(arguments));
        callbacks = D_001D9C98;
        do {
            index++;
            (*callbacks)(*arguments);
            callbacks++;
            arguments++;
        } while (index < D_001D9CB8_00385908);
    }
}
/* localdecomp:end func_00385908 */

/* localdecomp:start func_00385980 */
typedef struct { f32 x, y, z, w; } V_385980;
typedef union { u128_t q; V_385980 v; } Q_385980;
typedef struct { f32 x, y, u, v; } T_385980;
typedef struct { Q_385980 v[4]; s32 col[4]; f32 uv[4][2]; long f70, f78, f80, f88; } S_385980;
extern long func_00384EC0(s32);
extern void func_003CD830();
__asm__(".extern D_001D5900, 8");
extern s32 D_001D5900[2];
extern s32 D_001D9CC0_00385980;
extern Q_385980 D_00227090[];
void func_00385980(void) {
    S_385980 s;
    Q_385980 t;
    s32 i, j, k;
    f32 dot, w;
    if (D_001D9CC0_00385980 == 0) return;
    s.f78 = func_00384EC0(0);
    s.f80 = 0xFF9000000260UL;
    s.f70 = 5;
    s.f88 = 0x8000000044UL;
    for (j = 0; j < 4; j++) {
        s.uv[j][0] = ((T_385980 *)D_001D5900)[j].u;
        s.uv[j][1] = ((T_385980 *)D_001D5900)[j].v;
        s.col[j] = 0x40808080;
    }
    for (i = 0; i < D_001D9CC0_00385980; i++) {
        t.q = D_00227090[i * 2].q;
        func_00388830((s32)&t, (s32)&t, 1.0f);
        w = ((Q_385980 *)((u8 *)D_00227090 + i * 32 - 16))->v.w;
        for (k = 0; k < 4; k++) {
            T_385980 *src = &((T_385980 *)D_001D5900)[k];
            dot = src->x * t.v.x + src->y * t.v.y;
            s.v[k].q = ((Q_385980 *)((u8 *)D_00227090 + i * 32 - 16))->q;
            s.v[k].v.x += (src->x - t.v.x * dot) * w;
            s.v[k].v.y += (src->y - t.v.y * dot) * w;
            s.v[k].v.z -= t.v.z * dot * w;
        }
        func_003CD830(&s, 0, 0);
    }
}
/* localdecomp:end func_00385980 */

/* localdecomp:start func_00385B60 */
extern u32 *D_001DA0D0_00385B60;
__asm__(".extern D_001DA0D0_g, 4");
extern u32 *D_001DA0D0_g;
__asm__(".extern D_001D9C48_g, 4");
extern s32 D_001D9C48_g;
extern s32 D_001D9C48_00385B60;
extern u8 D_00141990[];
extern void func_003A3DA0(s32);
extern s32 func_12C908(s32);
extern void func_003A3BB8(void);
extern void func_003A3C80(void);
extern void func_003A3C00();
extern void func_0038DA80(void);
extern void func_0038DB18(s32);
extern void func_0038DB98(void);
extern void func_003A3EF0(s32, unsigned long);
void func_00385B60(s32 arg0) {
    s32 i;
    s32 t;
    func_003A3DA0(1);
    i = arg0 - 1;
    func_12C908(0);
    D_001D9C48_g = D_001D9C48_00385B60 + 1;
    func_003A3BB8();
    while (i >= 0) {
        func_0038DA80();
        func_0038DB18(1);
        func_0038DB98();
        func_003A3EF0(0x42, 0x8000000044UL);
        t = (i << 7) / (i + 1);
        i--;
        func_003A3EF0(1, (long)(0x80 - t) << 24);
        D_001DA0D0_00385B60[0] = 0x30000014;
        D_001DA0D0_00385B60[1] = (u32)D_00141990;
        D_001DA0D0_00385B60[2] = 0;
        D_001DA0D0_00385B60[3] = 0x50000014;
        D_001DA0D0_g = D_001DA0D0_00385B60 + 4;
        func_003A3DA0(1);
        func_12C908(0);
        D_001D9C48_g = D_001D9C48_00385B60 + 1;
        func_003A3C80();
        func_003A3C00();
    }
    func_003A3DA0(1);
    func_12C908(0);
    D_001D9C48_g = D_001D9C48_00385B60 + 1;
    func_003A3BB8();
    func_0038DA80();
    func_0038DB18(1);
}
/* localdecomp:end func_00385B60 */

INCLUDE_ASM("asm/nonmatchings/text", func_00385CE0);

INCLUDE_ASM("asm/nonmatchings/text", func_00385E40);

/* localdecomp:start func_00386210 */
extern s32 D_001D9C60_00386210;
extern s32 D_001D9C5C_00386210;
extern s32 D_001D4BD0_00386210;
extern s32 D_001D4BD4_00386210;
extern s32 D_001D4BD8;
extern s32 D_001D4BDC;
extern u8 D_001439FD[];
extern u8 D_001D76A0[];
extern u8 D_001D76B0[];
void func_00386210(void) {
    s32 n, t, n4;
    u8 *r;
    u8 *p;
    u8 *q0;
    u8 *s;
    u8 *u;
    u8 *q;
    if (D_001D9C5C_00386210 != 0) {
        if (D_001D9C60_00386210 < 0x34) D_001D9C60_00386210 = D_001D9C60_00386210 + 1;
    } else {
        if (D_001D9C60_00386210 == 0) return;
        D_001D9C60_00386210 = D_001D9C60_00386210 - 1;
    }
    n = D_001D9C60_00386210;
    if (n == 0) return;
    if (D_001439FD[0] != 0) return;
    *(s32 *)(D_001DA0D0 + 0) = 0x10000007;
    *(s32 *)(D_001DA0D0 + 4) = 0;
    *(s32 *)(D_001DA0D0 + 8) = 0;
    *(s32 *)(D_001DA0D0 + 0xC) = 0x50000007;
    r = (u8 *)D_001DA0D0;
    D_001DA0D0 = (s32)r + 0x10;
    *(u128_t *)(r + 0x10) = *(u128_t *)D_001D76A0;
    *(s16 *)D_001DA0D0 = -0x7FFF;
    p = (u8 *)D_001DA0D0;
    q0 = p + 0x10;
    D_001DA0D0 = (s32)q0;
    *(long *)(p + 0x10) = 0x104;
    *(long *)(q0 + 8) = 0x80000000UL;
    s = (u8 *)D_001DA0D0;
    D_001DA0D0 = (s32)s + 0x10;
    *(u128_t *)(s + 0x10) = *(u128_t *)D_001D76B0;
    *(s16 *)D_001DA0D0 = -0x7FF8;
    n4 = n << 4;
    u = (u8 *)D_001DA0D0;
    q = u + 0x10;
    D_001DA0D0 = (s32)q;
    *(long *)(u + 0x10) = D_001D4BD0_00386210 | ((long)D_001D4BD4_00386210 << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 8) = D_001D4BD0_00386210 | ((long)(D_001D4BD4_00386210 + n4) << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x10) = D_001D4BD8 | ((long)D_001D4BD4_00386210 << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x18) = D_001D4BD8 | ((long)(D_001D4BD4_00386210 + n4) << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x20) = D_001D4BD8 | ((long)D_001D4BDC << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x28) = D_001D4BD8 | ((long)(D_001D4BDC - n4) << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x30) = D_001D4BD0_00386210 | ((long)D_001D4BDC << 16) | 0xFFFFF300000000UL;
    *(long *)(q + 0x38) = D_001D4BD0_00386210 | ((long)(D_001D4BDC - n4) << 16) | 0xFFFFF300000000UL;
    D_001DA0D0 = D_001DA0D0 + 0x40;
}
/* localdecomp:end func_00386210 */

/* localdecomp:start func_00386488 */
typedef struct { s32 f0; u32 f4; unsigned long f8; s32 f10; u32 f14; unsigned long f18; s32 f20; u32 f24; unsigned long f28; } P_00386488;
__asm__(".extern D_001D58B8_00386488, 4");
extern P_00386488 *D_001D58B8_00386488;
extern void func_003A3EF0(s32, unsigned long);
extern void func_003867F8(s32, s32, s32, s32, unsigned long);
typedef struct { u8 p0[0x150]; s16 f150, f152; } C_00386488;
extern C_00386488 D_001CFEC0_00386488;
void func_00386488(void) {
    s32 i = 0;
    s32 h = D_001CFEC0_00386488.f152;
    s32 y;
    if (D_001D58B8_00386488->f8) {
        func_003A3EF0(0x42, D_001D58B8_00386488->f8 & 0xFF000000FFUL);
    }
    if (D_001D58B8_00386488->f4 & 0xFF000000) {
        func_003867F8(0, h, 0, D_001CFEC0_00386488.f150, D_001D58B8_00386488->f4);
    }
    if (h > 0) {
        do {
            if (D_001D58B8_00386488->f18) {
                func_003A3EF0(0x42, D_001D58B8_00386488->f18 & 0xFF000000FFUL);
            }
            if (D_001D58B8_00386488->f14 & 0xFF000000) {
                y = (i + D_001D58B8_00386488->f10 >= h - 1) ? h - 1 : i + D_001D58B8_00386488->f10;
                func_003867F8(i, y, 0, D_001CFEC0_00386488.f150, D_001D58B8_00386488->f14);
            }
            i += D_001D58B8_00386488->f10;
            if (D_001D58B8_00386488->f28) {
                func_003A3EF0(0x42, D_001D58B8_00386488->f28 & 0xFF000000FFUL);
            }
            if (D_001D58B8_00386488->f24 & 0xFF000000) {
                y = (i + D_001D58B8_00386488->f20 >= h - 1) ? h - 1 : i + D_001D58B8_00386488->f20;
                func_003867F8(i, y, 0, D_001CFEC0_00386488.f150, D_001D58B8_00386488->f24);
            }
            i += D_001D58B8_00386488->f20;
        } while (i < h);
    }
}
/* localdecomp:end func_00386488 */

/* localdecomp:start func_00386608 */
extern void func_003A3EF0(s32, unsigned long);
extern void func_003867F8(s32, s32, s32, s32, unsigned long);
extern s32 D_001A1ED0[];
extern s16 D_001CFEC0[];
typedef struct { s32 f0; u32 f4; unsigned long f8; } S;
void func_00386608(S *a) {
    if (a->f8) {
        func_003A3EF0(0x42, a->f8 & 0xFF000000FFUL);
    }
    if (a->f4 & 0xFF000000) {
        func_003A3EF0(0x4E, ((D_001A1ED0[2] >> 13) | 0x1000000) | 0x100000000UL);
        func_003867F8(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], a->f4);
        func_003A3EF0(0x4E, 0x1000000 | (D_001A1ED0[2] >> 13));
    }
    if (a->f8) {
        func_003A3EF0(0x42, 0x8000000044UL);
    }
}
/* localdecomp:end func_00386608 */

/* localdecomp:start func_003866E8 */
extern u32 *D_001DA0D0_003866E8;
extern u8 D_00141850[];
void func_003866E8(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_003A3EF0(0x4E, ((D_001A1ED0[2] >> 13) | 0x31000000) | (0x8000UL << 17));
    func_003A3EF0(1, (long)a0 | ((long)a1 << 8) | ((long)a2 << 16) | ((long)a3 << 24));
    D_001DA0D0_003866E8[0] = 0x30000014;
    D_001DA0D0_003866E8[1] = (u32)D_00141850;
    D_001DA0D0_003866E8[2] = 0;
    D_001DA0D0_003866E8[3] = 0x50000014;
    D_001DA0D0_003866E8 += 4;
    func_003A3EF0(0x4E, 0x31000000 | (D_001A1ED0[2] >> 13));
}
/* localdecomp:end func_003866E8 */

/* localdecomp:start func_003867F8 */
extern s32 D_001D4BD0_003867F8;
extern s32 D_001D4BD4_003867F8;
extern u8 D_001D76A0[];
extern u8 D_001D76B0[];
void func_003867F8(s32 y0, s32 y1, s32 x0, s32 x1, unsigned long c) {
    u8 *r;
    u8 *p;
    u8 *q;
    u8 *s;
    u8 *t;
    u8 *q0;
    *(s32 *)(D_001DA0D0 + 0) = 0x10000005;
    *(s32 *)(D_001DA0D0 + 4) = 0;
    *(s32 *)(D_001DA0D0 + 8) = 0;
    *(s32 *)(D_001DA0D0 + 0xC) = 0x50000005;
    r = (u8 *)D_001DA0D0;
    D_001DA0D0 = (s32)r + 0x10;
    *(u128_t *)(r + 0x10) = *(u128_t *)D_001D76A0;
    *(s16 *)D_001DA0D0 = -0x7FFF;
    p = (u8 *)D_001DA0D0;
    q0 = p + 0x10;
    D_001DA0D0 = (s32)q0;
    *(long *)(p + 0x10) = 0x144;
    *(unsigned long *)(q0 + 8) = c;
    s = (u8 *)D_001DA0D0;
    D_001DA0D0 = (s32)s + 0x10;
    *(u128_t *)(s + 0x10) = *(u128_t *)D_001D76B0;
    *(s16 *)D_001DA0D0 = -0x7FFC;
    t = (u8 *)D_001DA0D0;
    q = t + 0x10;
    D_001DA0D0 = (s32)q;
    *(long *)(t + 0x10) = ((x0 << 4) + D_001D4BD0_003867F8 - 8) | ((long)((y0 << 4) + D_001D4BD4_003867F8 - 8) << 16) | 0xFFFFF000000000UL;
    *(long *)(q + 8) = ((x1 << 4) + D_001D4BD0_003867F8 - 8) | ((long)((y0 << 4) + D_001D4BD4_003867F8 - 8) << 16) | 0xFFFFF000000000UL;
    *(long *)(q + 0x10) = ((x0 << 4) + D_001D4BD0_003867F8 - 8) | ((long)((y1 << 4) + D_001D4BD4_003867F8 - 8) << 16) | 0xFFFFF000000000UL;
    *(long *)(q + 0x18) = ((x1 << 4) + D_001D4BD0_003867F8 - 8) | ((long)((y1 << 4) + D_001D4BD4_003867F8 - 8) << 16) | 0xFFFFF000000000UL;
    D_001DA0D0 = D_001DA0D0 + 0x20;
}
/* localdecomp:end func_003867F8 */

LINKER_REMNANT("asm/remnants", func_003869E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003869E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00386D98);

LINKER_REMNANT("asm/remnants", func_00386F28);

INCLUDE_ASM("asm/nonmatchings/text", func_00386F38);

INCLUDE_ASM("asm/nonmatchings/text", func_00387118);

INCLUDE_ASM("asm/nonmatchings/text", func_003872F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003875A0);

/* localdecomp:start func_00387A00 */
typedef int u128_387A00 __attribute__((mode(TI)));
extern s32 D_001DA0D0;
extern u8 D_001D7770[];
void func_00387A00(long *a, s32 *b, s32 *c, long d, s32 e) {
    u8 *r;
    u8 *p;
    u8 *q;
    *(s32 *)(D_001DA0D0 + 0) = 0x10000009;
    *(s32 *)(D_001DA0D0 + 4) = 0;
    *(s32 *)(D_001DA0D0 + 8) = 0;
    *(s32 *)(D_001DA0D0 + 0xC) = 0x50000009;
    r = (u8 *)D_001DA0D0;
    D_001DA0D0 = (s32)r + 0x10;
    *(u128_387A00 *)(r + 0x10) = *(u128_387A00 *)D_001D7770;
    p = (u8 *)D_001DA0D0;
    q = p + 0x10;
    D_001DA0D0 = (s32)q;
    if (e) {
        *(long *)(p + 0x10) = 5;
    } else {
        *(long *)(p + 0x10) = 0;
    }
    *(long *)(q + 8) = d;
    *(long *)(q + 0x10) = 0x154;
    *(long *)(q + 0x18) = c[0];
    *(long *)(q + 0x20) = b[0];
    *(long *)(q + 0x28) = a[0];
    *(long *)(q + 0x30) = c[1];
    *(long *)(q + 0x38) = b[1];
    *(long *)(q + 0x40) = a[1];
    *(long *)(q + 0x48) = c[2];
    *(long *)(q + 0x50) = b[2];
    *(long *)(q + 0x58) = a[2];
    *(long *)(q + 0x60) = c[3];
    *(long *)(q + 0x68) = b[3];
    *(long *)(q + 0x70) = a[3];
    *(long *)(q + 0x78) = 0;
    D_001DA0D0 = D_001DA0D0 + 0x80;
}
/* localdecomp:end func_00387A00 */

INCLUDE_ASM("asm/nonmatchings/text", func_00387B10);

/* localdecomp:start func_00387BD8 */
extern s32 D_001D4BD0[];
extern s32 D_001D4BD4[];
extern void func_00387B10(unsigned long *, s32);
void func_00387BD8(s32 a, s32 b, s32 c, s32 d, unsigned long e, s32 g) {
    unsigned long v[4];
    s32 y = D_001D4BD4[0];
    s32 x = D_001D4BD0[0];
    s32 D = (d << 4) + y - 8;
    s32 C = (c << 4) + x - 8;
    s32 B = (b << 4) + y - 8;
    s32 A = (a << 4) + x - 8;
    v[0] = (unsigned long)A | ((unsigned long)B << 16) | (e << 32);
    v[1] = (unsigned long)C | ((unsigned long)B << 16) | (e << 32);
    v[2] = (unsigned long)A | ((unsigned long)D << 16) | (e << 32);
    v[3] = (unsigned long)C | ((unsigned long)D << 16) | (e << 32);
    func_00387B10(v, g);
}
/* localdecomp:end func_00387BD8 */

/* localdecomp:start func_00387C78 */
void func_00387C78(s32 x, s32 y, s32 w, s32 z, s32 a, s32 b) {
    s32 c = (a << 24) | b;
    func_003867F8(x, y, w, z, c);
    func_003867F8(x + 1, y - 1, w - 2, w, c);
    func_003867F8(x + 2, y - 2, w - 3, w - 2, c);
    func_003867F8(x + 4, y - 4, w - 4, w - 3, c);
    func_003867F8(x + 1, y - 1, z, z + 2, c);
    func_003867F8(x + 2, y - 2, z + 2, z + 3, c);
    func_003867F8(x + 4, y - 4, z + 3, z + 4, c);
}
/* localdecomp:end func_00387C78 */

LINKER_REMNANT("asm/remnants", func_00387DB8);

INCLUDE_ASM("asm/nonmatchings/text", func_00387DC8);
TEXT_PADDING(2);

/* localdecomp:start func_00388018 */
typedef struct { u8 p0[0x190]; u128_t q190; u128_t q1A0; u8 p1B0[0x70]; f32 f220; u8 p224[0x14]; f32 f238; f32 f23C; s32 f240; s32 f244; s32 f248; s32 f24C; } S_388018;
__asm__(".extern D_001D5880, 4");
extern f32 D_001D5880;
extern s32 D_001D9D9C;
extern S_388018 D_00225980_00388018;
extern long D_001D5330[];
extern u8 D_0010F500[];
extern void func_00388B98_00388018(f32 *, f32);
extern u16 D_0010F4F0[];
extern void func_003A3DE8(s32, u32);
extern void func_003A41F0(void);
void func_00388018(void) {
    f32 m[12];
    f32 v[4];
    u8 *p;
    u8 *q;
    u8 *d;
    S_388018 *s;
    func_00388B98_00388018(m, 1024.0f);
    func_003886E8(v, D_00222480, -1024.0f);
    v[3] = 1.0f;
    if (D_001D9D9C != 8) {
        func_003A3DE8((s32)D_0010F500, D_0010F4F0[0]);
        D_001D9D9C = 8;
    }
    *(s32 *)(D_001DA0D0 + 0) = 0x10000000;
    *(s32 *)(D_001DA0D0 + 4) = 0;
    *(s32 *)(D_001DA0D0 + 8) = 0x11000000;
    *(s32 *)(D_001DA0D0 + 0xC) = 0x1000404;
    p = (u8 *)D_001DA0D0;
    *(s32 *)(p + 0x10) = 0;
    *(s32 *)(p + 0x14) = 0;
    *(s32 *)(p + 0x18) = 0;
    *(s32 *)(p + 0x1C) = 0x6C0C43A4;
    q = p + 0x20;
    func_00388F08(q, (u8 *)D_00222480 - 0x100, m);
    *(f32 *)(q + 0x38) += D_001D5880;
    q = p + 0x60;
    func_00388F08(q, (u8 *)D_00222480 - 0x80, m);
    *(f32 *)(q + 0x38) += D_001D5880;
    s = &D_00225980_00388018;
    *(s32 *)(p + 0xA0) = 0x8000;
    *(s32 *)(p + 0xA4) = 0x303EC000;
    *(s32 *)(p + 0xA8) = 0x412;
    *(f32 *)(p + 0xAC) = s->f220;
    *(u128_t *)(p + 0xB0) = s->q190;
    *(u128_t *)(p + 0xC0) = s->q1A0;
    *(f32 *)(p + 0xD0) = s->f23C;
    *(f32 *)(p + 0xD4) = s->f238;
    *(s32 *)(p + 0xE0) = 0x3000000;
    *(s32 *)(p + 0xE4) = 0x20001D2;
    *(s32 *)(p + 0xE8) = 0x15000000;
    *(s32 *)(p + 0xD8) = 0;
    *(s32 *)(p + 0xDC) = 0;
    *(s32 *)(p + 0xEC) = 0;
    q = p + 0xF0;
    d = (u8 *)D_001DA0D0;
    *(s32 *)d |= ((q - d) >> 4) - 1;
    D_001DA0D0 = (s32)q;
    D_001D5330[2] = (long)s->f240 | ((long)s->f244 << 16) | ((long)s->f248 << 32) | ((long)s->f24C << 48);
    D_001D5330[4] = (long)s->f240 | ((long)s->f244 << 16) | ((long)s->f248 << 32) | ((long)s->f24C << 48);
    func_003A41F0();
}
/* localdecomp:end func_00388018 */

LINKER_REMNANT("asm/remnants", func_00388258);

/* localdecomp:start func_00388278 */
extern void func_003C8CE0(void);
extern void func_003C8C40(void);
extern void func_003C8D50(void);
extern void func_003A3EF0(s32, unsigned long);
extern s32 D_001A1ED8[];
void func_00388278(void) {
    func_003C8CE0();
    func_003C8C40();
    func_003C8D50();
    func_003A3EF0(0x47, 0x5360B);
    func_003A3EF0(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_00388278 */
