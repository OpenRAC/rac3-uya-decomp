#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00382F90(void);
extern void func_003838C0(void);
extern void func_00383A90(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_0037E0F0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_37E0F0;
typedef int Q_37E0F0 __attribute__((mode(TI)));
extern u8 *D_001D9AA0;
extern void func_003888C8_0037E0F0(void *, void *, void *);
s32 func_0037E0F0(void *a, s32 idx, Q_37E0F0 *out) {
    V4_37E0F0 v;
    V4_37E0F0 r;
    u8 *e;
    Q_37E0F0 p, q, t;
    if (idx == -1) {
        return 0;
    }
    e = D_001D9AA0 + idx * 0x80;
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(*(V4_37E0F0 *)a));
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(V4_37E0F0 *)(e + 0x30)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(p), "j"(q));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(t));
    v.w = 0.0f;
    func_003888C8_0037E0F0(&r, &v, e + 0x40);
    if (out != 0) {
        *out = *(Q_37E0F0 *)&r;
    }
    if (r.x >= -1.0f && r.x <= 1.0f && r.y >= -1.0f && r.y <= 1.0f && r.z >= -1.0f && r.z <= 1.0f) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_0037E0F0 */

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

/* localdecomp:start func_0037E630 */
typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; s16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E630;
extern E_0037E630 D_00222500_0037E630[];
extern f32 D_00225A30[];
extern void func_0037E9B0(f32 *, f32, f32, f32, f32, f32);
extern s32 func_003883C8(void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003830E8();
void func_0037E630(s32 idx) {
    E_0037E630 *e = &D_00222500_0037E630[idx];
    f32 a; f32 b; f32 v;
    if (e->b439 == 1) {
        switch (e->b438) {
        case 0:
            e->b439 = 0;
            e->f428 = e->f424;
            break;
        case 3:
            v = ((f32 (*)(f32 *, f32, f32, f32, f32, f32))func_0037E9B0)(&e->f424 - 1, e->f428, e->f424, e->f42C, e->f430, e->f434);
            e->f428 = v;
            { f32 d = v - e->f424, r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(d)); if (r < 0.0001f) e->b439 = 0; }
            break;
        case 1:
            if (func_003883C8(&e->h43A) != 0) e->b439 = 0;
            { f32 t = (f32)e->h43A * e->f43C; e->f428 = e->f424 + (e->f440 - e->f424) * t; }
            break;
        case 2:
            if (func_003883C8(&e->h43A) != 0) e->b439 = 0;
            e->f428 = func_003BE6A8(e->f424, e->f440, (f32)e->h43A * e->f43C);
            break;
        }
        a = e->f428 * 0.5f;
        b = func_00388978(a);
        D_00225A30[0] = b / func_00388960(a);
        func_003830E8();
    }
}
/* localdecomp:end func_0037E630 */

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

/* localdecomp:start func_0037E878 */
extern s32 D_001D9B00[2];
extern void (*D_001D9AC0[2])(s32);
void func_0037E878(s32 a) {
    s32 i;
    s32 *c = D_001D9B00;
    for (i = 0; i < c[a]; i++) D_001D9AC0[a * 16 + i](a);
    D_001D9B00[a] = 0;
}
/* localdecomp:end func_0037E878 */

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

/* localdecomp:start func_0037EB68 */
typedef int u128_37EB68 __attribute__((mode(TI)));
typedef struct { u8 p0[0x2B8]; f32 f2B8; u8 p2BC[0xC]; f32 f2C8; u8 p2CC[0x58]; s32 f324; u8 p328[0x138]; } E_37EB68;
extern E_37EB68 D_00222500_0037EB68[];
extern u8 *D_001D9B04;
extern u8 D_00225250[];
extern void func_0037E7D8(s32);
extern void func_0037EB20(u8 *);
void func_0037EB68(u8 *o, s32 a1) {
    s32 idx = *(s32 *)(o + 0x94);
    s32 j = idx;
    u8 *e = (u8 *)D_00222500_0037EB68 + idx * 0x460;
    u8 *q = *(u8 **)(e + 0x50);
    s32 k = *(s16 *)(q + 0x7E);
    u8 *t;
    s32 m;
    s32 off;
    f32 f;
    if (a1 != 0 || *(s32 *)(e + 0x458) > 0) k = 4;
    t = *(u8 **)((u8 *)((*(s16 *)(o + 0x84) << 5) + (s32)D_001D9B04) + 0x1C);
    m = 0;
    if (t != 0) m = t[0x1D];
    if (k == 4) {
        *(s16 *)(e + 0x2A0) = 0;
        *(s16 *)(o + 0x8E) = 1;
    } else if (k == 2 || m == 1 || m == 5) {
        if (m == 1) {
            f = *(f32 *)(o + 0x78);
            e[0x2A3] = 0;
            if (0.0f < f) {
                ((E_37EB68 *)((u8 *)D_00222500_0037EB68 + j * 0x460))->f2C8 = f;
                ((E_37EB68 *)((u8 *)D_00222500_0037EB68 + j * 0x460))->f2B8 = f;
            } else {
                ((E_37EB68 *)((u8 *)D_00222500_0037EB68 + j * 0x460))->f2C8 = 0.018f;
                ((E_37EB68 *)((u8 *)D_00222500_0037EB68 + j * 0x460))->f2B8 = 0.018f;
            }
        } else if (m == 5) {
            f = *(f32 *)(o + 0x78);
            e[0x2A3] = 2;
            if (0.0f < f) {
                ((E_37EB68 *)((u8 *)D_00222500_0037EB68 + j * 0x460))->f324 = f;
            } else {
                ((E_37EB68 *)((u8 *)D_00222500_0037EB68 + j * 0x460))->f324 = 0x28;
            }
        }
        if (*(s16 *)(e + 0x2A0) == 0) {
            *(s16 *)(e + 0x2A0) = 1;
        } else {
            *(s16 *)(e + 0x2A0) = 2;
        }
    } else if (*(s16 *)(q + 0x7E) == 3 || *(s16 *)(q + 0x7E) == 5 || m == 3 || m == 6) {
        *(u128_37EB68 *)(o + 0x30) = *(u128_37EB68 *)(q + 0x30);
        *(u128_37EB68 *)(o + 0x00) = *(u128_37EB68 *)(q + 0x00);
        *(u128_37EB68 *)(o + 0x10) = *(u128_37EB68 *)(q + 0x10);
        *(u128_37EB68 *)(o + 0x20) = *(u128_37EB68 *)(q + 0x20);
        o[0x7D] = 2;
        if (*(s16 *)(q + 0x7E) == 5 || m == 6) {
            f = *(f32 *)(o + 0x78);
            e[0x2A3] = 0;
            if (0.0f < f) {
                ((E_37EB68 *)((u8 *)D_00222500_0037EB68 + j * 0x460))->f2C8 = f;
                ((E_37EB68 *)((u8 *)D_00222500_0037EB68 + j * 0x460))->f2B8 = f;
            } else {
                ((E_37EB68 *)((u8 *)D_00222500_0037EB68 + j * 0x460))->f2C8 = 0.018f;
                ((E_37EB68 *)((u8 *)D_00222500_0037EB68 + j * 0x460))->f2B8 = 0.018f;
            }
        }
    } else {
        *(s16 *)(o + 0x8E) = 1;
    }
    off = j * 0x780;
    *(s16 *)(q + 0x7E) = 0;
    q[0x7D] = 0;
    *(s16 *)(q + 0x8E) = 0;
    *(u8 **)(e + 0x54) = q;
    func_003885F0(D_00225250 + off, D_00225250 - 0x280 + off, 0x280);
    *(u8 **)(*(u8 **)(e + 0x54) + 0x70) = D_00225250 + off;
    *(u8 **)(e + 0x50) = o;
    *(u8 **)(o + 0x70) = D_00225250 - 0x280 + off;
    q = o;
    *(s32 *)(e + 0x454) = 0;
    func_0037EB20(q);
    func_0037E7D8(idx);
    *(u128_37EB68 *)e = *(u128_37EB68 *)(q + 0x30);
    {
        f32 *src = (f32 *)(q + 0x30);
        f32 *dst = (f32 *)(q + 0x64);
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
}
/* localdecomp:end func_0037EB68 */

/* localdecomp:start func_0037EE80 */
typedef struct { u8 p0[0xC]; s32 fC; u8 p10[0x24 - 0x10]; s32 f24; } T_37EE80;
typedef struct { u8 p0[0x1C]; T_37EE80 *f1C; } R_37EE80;
typedef struct { u8 p0[0x5D0]; s32 f5D0; u8 p5D4[0x5E0 - 0x5D4]; s32 f5E0; u8 p5E4[0x690 - 0x5E4]; s32 f690; u8 p694[0x6A0 - 0x694]; s32 f6A0; u8 p6A4[0x25CC - 0x6A4]; s32 f25CC; } A_37EE80;
typedef struct { u8 p0[0x24C]; s32 f24C; u8 p250[0x460 - 0x250]; } E_37EE80;
extern u8 *D_001D9B04_0037EE80;
typedef struct { u8 p0[0x10]; s32 f10; u8 p14[0xC]; } G2_37EE80;
extern G2_37EE80 *D_001D9ED0;
extern A_37EE80 D_001A4BE0_0037EE80;
extern E_37EE80 D_00222500_0037EE80[];
extern u8 D_00222650[];
extern s32 func_0037E0F0(void *, s32, s32);
s32 func_0037EE80(s32 idx, u8 *o, u8 *t) {
    u8 *s = o + 0x74;
    s32 (*f)(u8 *, u8 *);
    s32 r;
    if (o[0x7C] == 0) return 0;
    f = (s32 (*)(u8 *, u8 *))D_0037D000[*(s16 *)(o + 0x8C)].b;
    if (f != 0) {
        r = f(o, t);
        if (r == -1) return 0;
        if (r == 1) return 1;
    }
    switch (*(s32 *)s) {
    case 1:
    case 2:
        if (s[9] == 0) break;
    case 0:
        if (t == 0) return 1;
        if (*(s16 *)(t + 0x7E) != 0) return 1;
        if (s[8] > t[0x7C]) return 1;
        break;
    case 4: {
        T_37EE80 *e = ((R_37EE80 *)(D_001D9B04_0037EE80 + *(s16 *)(o + 0x84) * 32))->f1C;
        if (t != 0 && *(s16 *)(t + 0x7E) == 0 && !(s[8] > t[0x7C])) break;
        { u8 *p = D_00222650 + idx * 0x460; if (func_0037E0F0(p + 0x40, e->fC, 0) != 0) return 1; }
        break;
    }
    case 7: {
        s32 h = *(s16 *)(o + 0x86);
        T_37EE80 *e;
        s32 a5, a7, k;
        if (h != ((E_37EE80 *)(idx * 0x460 + (s32)D_00222500_0037EE80))->f24C) break;

        if (*(s16 *)(t + 0x7E) == 0 && !(s[8] > t[0x7C])) break;
        if (h != 3) return 1;
        e = ((R_37EE80 *)((s32)D_001D9B04_0037EE80 + (*(s16 *)(o + 0x84) << 5)))->f1C;
        if (D_001A4BE0_0037EE80.f25CC == 0x1A) {
            a5 = D_001A4BE0_0037EE80.f690;
            a7 = D_001A4BE0_0037EE80.f6A0;
        } else {
            a5 = D_001A4BE0_0037EE80.f5D0;
            a7 = D_001A4BE0_0037EE80.f5E0;
        }
        k = e->f24;
        if (k < 0) return 1;
        if (a5 != D_001D9ED0[k].f10) break;
        if (a7 == 0) return 1;
        break;
    }
    }
    return 0;
}
/* localdecomp:end func_0037EE80 */

/* localdecomp:start func_0037F090 */
extern S_37D000 D_0037D000[];
void func_0037F090(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_0037D000[*(s16 *)(p + 0x8C)].e;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_0037F090 */

/* localdecomp:start func_0037F0D8 */
extern u8 D_00222A90_0037F0D8[];
extern u8 D_001D9B90_0037F0D8[8];
extern void func_0037F090(u8 *);
extern s32 func_0037EE80(s32, u8 *, u8 *);
extern void func_0037EB68(u8 *, s32);
extern void func_0037EAA0(s32, void *);
extern void func_0037E878(s32);
s32 func_0037F0D8(s32 a) {
    s32 found = 0;
    s32 i;
    u8 *cur = (u8 *)((S_00222500_0037E7D8 *)(a * 0x460 + (s32)D_00222500))->f50;
    u8 *p;
    u8 *q;
    void (*f)(u8 *);
    f32 *src;
    f32 *dst;
    func_0037F090(cur);
    p = (u8 *)(a * 0x2100 + (s32)D_00222A90_0037F0D8);
    q = (u8 *)(a * 0x30 + (s32)D_001D9B90_0037F0D8);
    for (i = 0; i < 48; i++) {
        if (*q != 0 && p != cur && func_0037EE80(a, p, cur) != 0) {
            cur = p;
            found = 1;
        }
        p += 0xB0;
        q++;
    }
    if (found != 0) {
        func_0037EB68(cur, 0);
    }
    f = (void (*)(u8 *))D_0037D000[*(s16 *)(cur + 0x8C)].d;
    func_0037EAA0(a, cur);
    if (f != 0) {
        f(cur);
    }
    src = (f32 *)(cur + 0x30);
    dst = (f32 *)(cur + 0x64);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    func_0037E878(a);
    return -1;
}
/* localdecomp:end func_0037F0D8 */

/* localdecomp:start func_0037F228 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F228;
typedef int Q_37F228 __attribute__((mode(TI)));
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern f32 func_00388990(f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(s32 a, s32 b, f32 x);
void func_0037F228(f32 *out, V_37F228 *a, V_37F228 *b, V_37F228 *c, V_37F228 *d4, V_37F228 *n) {
    V_37F228 d, p, e, w, r;
    f32 t, l, ang, h;
    {
        Q_37F228 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
    }
    t = func_00388730(&d, n);
    func_00388830((s32)&p, (s32)n, t);
    {
        Q_37F228 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(x));
    }
    t = func_00388730(c, &e);
    l = func_00388770(&e);
    if (l == 0.0f) l = 0.0001f;
    h = 1.5707964f;
    ang = h - func_00388990(t / l);
    func_00388830((s32)&w, (s32)&e, 1.0f);
    if (func_00388730(d4, &w) < 0.0f) ang = -ang;
    out[0] = ang;
    func_00389158(&r, c, n, ang);
    t = func_00388730(&r, &d);
    l = func_00388770(&d);
    if (l == 0.0f) l = 0.0001f;
    h = h - func_00388990(t / l);
    func_00388830((s32)&w, (s32)&d, 1.0f);
    ang = -h;
    if (func_00388730(n, &w) < 0.0f) ang = h;
    out[1] = ang;
    out[2] = func_00388770(&d);
}
/* localdecomp:end func_0037F228 */

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

/* localdecomp:start func_0037F7A8 */
/* PROVISIONAL, VU0 j-constraint form (needs -mvu0-use-vf0-vf2, override in tools/text_parts.txt).
   The empty asm on e keeps combine from folding the -0x1C0 base offset into the sq (retail keeps
   &D_00222500 in its own register, $a2). */
typedef int Q_37F7A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F7A8;
typedef struct { f32 f0, f4; u8 p8[8]; f32 f10, f14; u8 p18[8]; V_37F7A8 v20; V_37F7A8 v30; u128_t q40; u8 m50[0x40]; } B_37F7A8;
typedef struct { u8 p0[0x30]; f32 f30, f34, f38; u8 p3C[0x94 - 0x3C]; s32 f94; } O_37F7A8;
typedef struct { u128_t q0; u8 p10[0x1C0 - 0x10]; V_37F7A8 v1C0; u8 p1D0[0x380 - 0x1D0]; u8 m380[0x40]; u8 p3C0[0x460 - 0x3C0]; } E_37F7A8;
extern E_37F7A8 D_00222500_0037F7A8[];
extern void func_003BF2A0(void *, void *);
extern void func_00388E58(void *, void *);
extern void func_00388F90_0037F7A8(void *, void *, void *, f32);
extern void func_003890F8_0037F7A8(void *, void *);
extern f32 func_003BE6A8(f32, f32, f32);
s32 func_0037F7A8(O_37F7A8 *o, B_37F7A8 *b) {
    V_37F7A8 m;
    u8 n[0x40];
    f32 t, s;
    V_37F7A8 *p;
    if (b->f10 == 1.0f && b->f0 == 1.0f) return 1;
    t = func_003BE6A8(0.0f, 1.0f, b->f10);
    p = &D_00222500_0037F7A8[o->f94].v1C0;
    {
        Q_37F7A8 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b->v30));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*p));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(b->v30) : "j"(x));
    }
    ((f32 *)&b->q40)[0] = b->v30.x + (o->f30 - b->v30.x) * t;
    ((f32 *)&b->q40)[1] = b->v30.y + (o->f34 - b->v30.y) * t;
    ((f32 *)&b->q40)[2] = b->v30.z + (o->f38 - b->v30.z) * t;
    {
        E_37F7A8 *e = &D_00222500_0037F7A8[o->f94];
        __asm__("" : "+r"(e));
        e->q0 = b->q40;
    }
    func_003BF2A0(&m, o);
    s = func_003BE6A8(0.0f, 1.0f, b->f0);
    func_00388F90_0037F7A8(b->m50, &b->v20, &m, s);
    func_003890F8_0037F7A8(b->m50, n);
    func_00388E58(D_00222500_0037F7A8[o->f94].m380, n);
    b->f10 = b->f10 + b->f14;
    if (1.0f < b->f10) b->f10 = 1.0f;
    b->f0 = b->f0 + b->f4;
    if (1.0f < b->f0) b->f0 = 1.0f;
    return 0;
}
/* localdecomp:end func_0037F7A8 */

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

/* localdecomp:start func_003801C0 */
/* PROVISIONAL, VU0 j-constraint form (needs -mvu0-use-vf0-vf2, override in tools/text_parts.txt).
   sq $zero through the documented non-volatile QZERO "=m" form. */
typedef int Q_3801C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3801C0;
typedef union { V_3801C0 v; u128_t q; f32 f[4]; } U_3801C0;
typedef struct { u8 p0[0x86]; s16 h86; } P_3801C0;
typedef struct {
    f32 f0, f4, f8, fC;
    f32 f10[4];
    U_3801C0 u20;
    u128_t q30;
    u128_t q40;
    U_3801C0 u50;
    U_3801C0 u60;
    V_3801C0 v70;
    V_3801C0 v80;
    u128_t q90;
    f32 fA0, fA4, fA8;
    f32 fAC[5];
    u8 pC0[0x30];
} B_3801C0;
typedef struct {
    u8 p0[0x40];
    U_3801C0 u40;
    u8 p50[8];
    f32 f58;
    u8 p5C[0x24];
    V_3801C0 v80;
    u8 p90[0x6C];
    s32 iFC;
    s32 i100;
    u8 p104[0x460 - 0x150 - 0x104];
} A_3801C0;
typedef struct {
    u8 p0[0x50];
    P_3801C0 *f50;
    u8 p54[0xC];
    B_3801C0 b;
    A_3801C0 a;
} E_3801C0;
__asm__(".extern D_001D57B8, 4");
__asm__(".extern D_001D57BC, 4");
__asm__(".extern D_001D57C4, 4");
extern f32 D_001D57B8, D_001D57BC, D_001D57C4;
extern E_3801C0 D_00222500_003801C0[];
extern void func_003886E8(f32 *, void *, f32);
extern f32 func_0037E920(f32 *, f32, f32, f32, f32, f32);
void func_003801C0(s32 idx, s32 flag) {
    E_3801C0 *e = &D_00222500_003801C0[idx];
    A_3801C0 *a = &e->a;
    B_3801C0 *b = &e->b;
    U_3801C0 t;
    U_3801C0 u;
    f32 l;
    s32 i;
    func_00388830((s32)&t, (s32)&a->v80, -1.0f);
    e->b.q40 = e->b.q30;
    e->b.q30 = t.q;
    if (flag != 0) {
        e->b.u20.q = t.q;
        __asm__("sq $0,%0" : "=m"(e->b.u50.q));
    } else {
        f32 k1, k2;
        if (func_00388730(&e->b.u20, &t) < -0.98f) {
            t.v.x += 0.2f;
            t.v.y += 0.2f;
            t.v.z += 0.2f;
        }
        k1 = D_001D57BC;
        k2 = D_001D57B8;
        if (e->f50->h86 == 0x20) {
            k2 = D_001D57C4;
            k1 = k2;
        }
        b->u20.v.x = func_0037E920(&e->b.u50.f[0], b->u20.v.x, t.v.x, k1, k2, 0.0f);
        b->u20.v.y = func_0037E920(&e->b.u50.f[1], b->u20.v.y, t.v.y, k1, k2, 0.0f);
        b->u20.v.z = func_0037E920(&e->b.u50.f[2], b->u20.v.z, t.v.z, k1, k2, 0.0f);
        func_00388830((s32)&e->b.u20, (s32)&e->b.u20, 1.0f);
    }
    {
        Q_3801C0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b->u60));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a->u40));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(b->v70) : "j"(x));
    }
    b->fA0 = func_00388770(&b->v70);
    l = func_00388730(&b->v70, &t);
    b->fA8 = l;
    func_00388830((s32)&u, (s32)&t, l);
    b->q90 = u.q;
    {
        Q_3801C0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(u));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b->v70));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(b->v80) : "j"(x));
    }
    l = func_00388770(&b->v80);
    b->fA4 = l;
    func_003886E8(&b->v80.x, &b->v80, 1.0f / l);
    b->u60.q = a->u40.q;
    if (a->iFC != 0x50 || a->i100 == 0x11) {
        b->f0 = a->u40.v.x;
        b->f4 = a->u40.v.y;
        b->f8 = func_0037E920(b->f10, b->f8, a->u40.v.z, 0.0075f, 0.175f, 0.0f);
        b->fC = a->u40.v.z;
    } else {
        b->f0 = a->u40.v.x;
        b->f4 = a->u40.v.y;
    }
    for (i = 0; i < 4; i++) b->fAC[i] = b->fAC[i + 1];
    b->fAC[i] = a->f58;
}
/* localdecomp:end func_003801C0 */

/* localdecomp:start func_003804A0 */
typedef struct { f32 x, y, z, w; } V_3804A0;
typedef union { u128_t q; V_3804A0 v; } Q_3804A0;
typedef struct { Q_3804A0 q0; u8 pad10[0x40]; u8 *f50; u8 pad54[0x3FC]; s32 f450; u8 pad454[0xC]; } E_3804A0;
extern E_3804A0 D_00222500_003804A0[];
extern s32 D_001D5B94;
extern u128_t D_002276E0[];
extern s32 func_003CE740();
extern s32 func_003D00C0(void);
extern f32 func_003BE988_003804A0(void *, s32);
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
            f32 r = func_003BE988_003804A0(D_002276E0, 0);
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

/* localdecomp:start func_00380600 */
typedef struct { u8 p0[8]; f32 f8; u8 pC[0x460 - 0xC]; } E_00380600;
typedef struct { u8 p0[0x40]; f32 f40, f44; u8 p48[0x100 - 0x48]; s32 f100, f104; u8 p108[0x118 - 0x108]; f32 f118; u8 p11C[0x12E - 0x11C]; u8 b12E, b12F, b130, b131, b132; } R_00380600;
typedef struct { u8 p0[0xC0]; s32 fC0; } Q_00380600;
extern E_00380600 D_00222500_00380600[];
extern s32 D_001D9B10_00380600[2];
extern s32 D_001D9B18_00380600[2];
extern s32 D_001D9B20_00380600[2];
void func_00380600(s32 a) {
    E_00380600 *e = (E_00380600 *)(a * 0x460 + (s32)D_00222500_00380600);
    R_00380600 *r = (R_00380600 *)((u8 *)e + 0x150);
    Q_00380600 *q = (Q_00380600 *)((u8 *)e + 0x60);
    s32 v;
    s32 *t = &D_001D9B18_00380600[a];

    *t = 0x14;
    if ((u32)(r->f104 - 0x11) < 2 || r->f100 == 0x75) {
        *t = 0x34;
    }
    if (r->f104 != 0x11 && r->f118 < e->f8) {
        D_001D9B18_00380600[a] = 0x14;
    }
    if (*(s32 *)0x1D545C == 6) {
        if (r->f40 > 485.7f && r->f40 < 570.7f) {
            if (r->f44 > 250.0f && r->f44 < 334.5f) {
                D_001D9B18_00380600[a] = 0x34;
            }
        }
    }
    v = D_001D9B18_00380600[a];
    D_001D9B18_00380600[a] = v | 0x80;
    D_001D9B20_00380600[a] = v;
    D_001D9B10_00380600[a] = 0xB4;
    if (r->b12E != 0) {
        q->fC0 = 0x100;
        D_001D9B10_00380600[a] = 0x100 | 0xB4;
    } else if (r->b12F != 0) {
        q->fC0 = 0xB00;
        D_001D9B10_00380600[a] = 0xB00 | 0xB4;
    } else if (r->b130 != 0) {
        q->fC0 = 0x300;
        D_001D9B10_00380600[a] = 0x300 | 0xB4;
    } else if (r->b131 != 0) {
        q->fC0 = 0xD00;
        D_001D9B10_00380600[a] = 0xD00 | 0xB4;
    } else if (r->b132 != 0) {
        D_001D9B10_00380600[a] = 0xB4;
        q->fC0 = 0;
    } else {
        D_001D9B10_00380600[a] = q->fC0 | 0xB4;
    }
}
/* localdecomp:end func_00380600 */
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

/* localdecomp:start func_00380AB0 */
extern u8 D_00222500_0037F588[];
extern u8 *D_001D9BC0[2];
extern s32 D_001D9B80[2];
extern s32 D_001D5B98;
extern s32 D_001D90E8;
extern s32 D_001D90E0;
extern void func_00380600(s32);
extern void func_003801C0(s32, s32);
extern void func_0037F0D8(s32);
extern void func_003BF360();
extern void func_0037FF90();
extern void func_00381C18();
extern void func_0037E630(s32);
void func_00380AB0(void) {
    s32 saved[16];
    s32 i;
    u8 *o;
    u8 *e;
    u8 *s;
    u8 *t;
    {
        s32 j;
        for (j = 0; j < 16; j++) {
            u8 *c = D_001D9BC0[j];
            if (c != 0) {
                if (c[0x20] == 0xFE) {
                    D_001D9BC0[j] = 0;
                } else if (c[0x20] == 0xFD) {
                    D_001D9BC0[j] = 0;
                } else {
                    saved[j] = *(s32 *)(c + 0x98);
                    *(s32 *)(c + 0x98) = 0;
                }
            }
        }
    }
    for (i = 0; i < 1; i++) {
        e = D_00222500_0037F588 + i * 0x460;
        s = e + 0x150;
        if (*(s32 *)(s + 0x100) == 0x31) {
            u8 *t0 = *(u8 **)(s + 0xF4);
            if (t0 != 0) *(s32 *)(t0 + 0x98) = 0;
        }
        *(s32 *)(e + 0x454) += 1;
        func_003807F0(i);
        func_003808E0(i);
        func_00380600(i);
        func_003801C0(i, 0);
        func_0037F0D8(i);
        o = *(u8 **)(e + 0x50);
        if (*(s32 *)(e + 0x458) > 0) *(s16 *)(e + 0x2A0) = 0;
        if ((u16)(*(u16 *)(e + 0x2A0) - 1) < 2) func_0037F588(*(u8 **)(e + 0x54));
        if (*(s16 *)(e + 0x2A0) == 3) {
            func_0037FEE8(o);
        } else {
            *(u128_t *)(e + 0x000) = *(u128_t *)(o + 0x30);
            *(u128_t *)(e + 0x380) = *(u128_t *)(o + 0x00);
            *(u128_t *)(e + 0x390) = *(u128_t *)(o + 0x10);
            *(u128_t *)(e + 0x3A0) = *(u128_t *)(o + 0x20);
        }
        func_003BF360(e + 0x380, e + 0x10);
        func_0037FF90(i, e + 0x20, 0);
        func_0037FF90(i, e + 0x30, 1);
        func_0037FF90(i, e + 0x40, 2);
        func_003804A0(i);
        func_00381C18(e);
        func_0037E630(i);
        __asm__ __volatile__("sq $0,%0" : "=m"(*(u128_t *)(e + 0x410)));
        if (*(s32 *)(s + 0x100) == 0x31) {
            t = *(u8 **)(s + 0xF4);
            if (t != 0) *(s32 *)(t + 0x98) = *(s32 *)(*(u8 **)(t + 0x24) + 0x10);
        }
        ((u128_t *)D_001D9B80)[i] = *(u128_t *)e;
        func_00388398(e + 0x458);
    }
    if (D_001D5B98 == 0) {
        D_001D90E0 = *(volatile s32 *)&D_001D90E8;
        func_003809F0(0);
    }
    {
        s32 j;
        for (j = 0; j < 16; j++) {
            u8 *c = D_001D9BC0[j];
            if (c != 0) *(s32 *)(c + 0x98) = saved[j];
        }
    }
}
/* localdecomp:end func_00380AB0 */
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_00380D28);

INCLUDE_ASM("asm/nonmatchings/text", func_00380D48);

/* localdecomp:start func_003810C0 */
typedef struct {
    u8 p0[0x10]; f32 f10; s32 f14; s32 f18; f32 f1C; u8 p20[6]; s16 h26; f32 f28; s32 f2C;
    u8 p30[8]; f32 f38; f32 f3C;
} S_3810C0;
extern void func_003875A0(f32, f32, f32, f32, f32, s32, s32, long, s32, s32, s32, s32, f32, f32);
extern long func_00384EC0(s32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
void func_003810C0(S_3810C0 *o, f32 x, f32 y) {
    long tex;
    f32 w, h, a;
    f32 p[4], q[4];
    s32 i;
    if (o == 0) return;
    w = o->f38;
    h = o->f3C;
    tex = func_00384EC0(o->f18);
    a = o->f1C;
    switch (o->f2C) {
    case 0:
        for (i = 0; i < o->h26; i++) {
            func_003875A0(x, y, w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 0, 0.0f, 0.0f);
            a = ((f32 (*)(f32, f32))func_00389380)(a, o->f28);
        }
        break;
    case 1:
        p[0] = h * func_00388978(a) * o->f10;
        p[1] = h * func_00388960(a) * o->f10;
        q[0] = w * func_00388960(a) * o->f10;
        q[1] = -w * func_00388978(a) * o->f10;
        func_003875A0(x, y, w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 0, 0.0f, 0.0f);
        func_003875A0(x + q[0], y + q[1], w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 1, 0, 0.0f, 0.0f);
        func_003875A0(x - p[0], y - p[1], w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 1, 0.0f, 0.0f);
        func_003875A0(x + q[0] - p[0], y + q[1] - p[1], w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 1, 1, 0.0f, 0.0f);
        break;
    case 2:
        func_003875A0(x, y, w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 0, 0.5f, 0.5f);
        break;
    }
}
/* localdecomp:end func_003810C0 */

/* localdecomp:start func_003813E0 */
/* PROVISIONAL, VU0 j-constraint form: each VU0 instruction is a separate non-volatile __asm__
   using the "j" (VU0 register) constraint, which needs -mvu0-use-vf0-vfN (override in
   tools/text_parts.txt). Kept for further exploration: the original's N is unknown (vf2 and up
   all give these bytes, vf1 does not compile). See Matching-Patterns, "VU0 instructions as
   separate asm statements". */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3813E0;
typedef int Q_3813E0 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x1430];
    s32 f1430;
    u8 p1434[0x2C];
    u8 *f1460;
    f32 f1464;
    f32 f1468;
} S_3813E0;
typedef struct { f32 f0; s16 h4; u8 p6[0xA]; f32 f10; } P_3813E0;
extern S_3813E0 D_001A4BE0;
__asm__(".extern D_001D57C8, 4");
__asm__(".extern D_001D57CC, 4");
__asm__(".extern D_001D57D0, 4");
__asm__(".extern D_001D57D4, 4");
__asm__(".extern D_001D57D8, 4");
__asm__(".extern D_001D57E8, 4");
__asm__(".extern D_001D57F8, 4");
__asm__(".extern D_001D5804, 4");
__asm__(".extern D_001D5808, 4");
__asm__(".extern D_001D580C, 4");
__asm__(".extern D_001D5810, 4");
__asm__(".extern D_001D5814, 4");
__asm__(".extern D_001D5818, 4");
__asm__(".extern D_001D581C, 4");
__asm__(".extern D_001D5820, 4");
__asm__(".extern D_001D5824, 4");
__asm__(".extern D_001D5828, 4");
__asm__(".extern D_001D582C, 4");
__asm__(".extern D_001D5830, 4");
__asm__(".extern D_001D5834, 4");
extern f32 D_001D57C8, D_001D57CC, D_001D57D0, D_001D57D4, D_001D5804, D_001D5808, D_001D5830, D_001D5834;
extern s32 D_001D57D8, D_001D57E8;
extern f32 D_001D57F8;
extern s32 D_001D580C, D_001D5810, D_001D5814, D_001D5818, D_001D581C, D_001D5820, D_001D5824, D_001D5828, D_001D582C;
extern s32 D_001D4BD0_003813E0, D_001D4BD4_003813E0;
extern P_3813E0 *func_0037E0B8(u8 *);
extern void func_00381DD0(f32 *, void *);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388A28(f32, f32);
extern void func_003875A0(f32, f32, f32, f32, f32, s32, s32, long, s32, s32, s32, s32, f32, f32);
extern void func_00387DC8(s32, s32, s32, s32, s32 *, s32 *, s32, s32, f32, f32);
extern long func_00384EC0(s32);
void func_003813E0(void) {
    f32 scr[4];
    f32 pos[2];
    V4_3813E0 v;
    s32 rgb4[4];
    s32 clr2[4];
    u8 *obj;
    P_3813E0 *info;
    f32 total, part, zoom, size;
    s32 i;
    if (D_001A4BE0.f1430 == 0 && D_001A4BE0.f1464 == 0.0f) return;
    if (D_001A4BE0.f1430 != (s32)D_001A4BE0.f1460) {
        func_003BEBF8(&D_001A4BE0.f1464, 0.0f, D_001D57D4 * 0.016666668f);
        if (D_001A4BE0.f1464 <= 0.0f) D_001A4BE0.f1460 = (u8 *)D_001A4BE0.f1430;
    } else if (D_001A4BE0.f1430 != 0 && D_001A4BE0.f1464 < 1.0f) {
        func_003BEBF8(&D_001A4BE0.f1464, 1.0f, D_001D57D4 * 0.016666668f);
        D_001A4BE0.f1468 = ((f32 (*)(f32, f32))func_00389380)(D_001A4BE0.f1468, D_001D5808 * 0.017453292f * 0.016666668f);
    }
    D_001A4BE0.f1468 = ((f32 (*)(f32, f32))func_00389380)(D_001A4BE0.f1468, D_001D5808 * 0.017453292f * 0.016666668f);
    obj = D_001A4BE0.f1460;
    if (obj == 0) return;
    if (D_001A4BE0.f1464 == 0.0f) return;
    part = 0.0f;
    info = func_0037E0B8(obj);
    total = part;
    if (info != 0) {
        Q_3813E0 qa, qb;
        func_00388830((s32)&v, (s32)(obj + 0xE0), info->f10);
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(V4_3813E0 *)(obj + 0x10)));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(qa) : "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qa));
        total = (f32)info->h4;
        part = info->f0;
    } else {
        v = *(V4_3813E0 *)(obj + 0x10);
    }
    zoom = 0.75f;
    func_00381DD0(scr, &v);
    pos[0] = (scr[0] - (f32)D_001D4BD0_003813E0) * 0.0625f;
    pos[1] = (scr[1] - (f32)D_001D4BD4_003813E0) * 0.0625f;
    if (info != 0) zoom = info->f10;
    if (zoom > 2.0f) zoom = 2.0f;
    size = func_00388A28(func_003887C8(D_00222500, obj + 0x10), zoom) * D_001D57C8;
    if (size > D_001D57CC) size = D_001D57CC;
    else if (size < D_001D57D0) size = D_001D57D0;
    for (i = 0; i < 3; i++) {
        f32 ang, sc;
        long tex;
        s32 rgba;
        switch (i) {
        case 0: ang = D_001A4BE0.f1468; break;
        case 1: ang = -D_001A4BE0.f1468; break;
        case 2: default: ang = D_001D5804 * 0.017453292f; break;
        }
        tex = func_00384EC0(i + 0x33);
        rgba = ((s32 (*)(s32, s32, f32))func_003894A0)((&D_001D57E8)[i], (&D_001D57D8)[i], D_001A4BE0.f1464);
        sc = (((&D_001D57F8)[i] - 1.0f) * (1.0f - D_001A4BE0.f1464) + 1.0f) * size;
        func_003875A0(pos[0], pos[1], sc, sc, ang, 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_003875A0(pos[0], pos[1], sc, sc, ((f32 (*)(f32, f32))func_00389380)(ang, 1.5707964f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_003875A0(pos[0], pos[1], sc, sc, ((f32 (*)(f32, f32))func_00389380)(ang, 3.1415927f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_003875A0(pos[0], pos[1], sc, sc, func_003893C8(ang, 1.5707964f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
    }
    if (total != 0.0f) {
        long x, y;
        f32 half;
        f32 half2;
        s32 rgba;
        clr2[0] = D_001D5810;
        clr2[1] = D_001D5814;
        clr2[2] = D_001D5818;
        clr2[3] = D_001D581C;
        rgba = ((s32 (*)(s32, s32, f32))func_003894A0)(D_001D5828 & 0xFFFFFF, D_001D5828, D_001A4BE0.f1464);
        rgb4[3] = rgba;
        rgb4[2] = rgba;
        rgb4[1] = rgba;
        rgb4[0] = rgba;
        x = (s32)scr[0];
        y = (s32)scr[1];
        half = D_001D5834 * func_00388A28(D_001D5830, total);
        func_00387DC8(x, y, (s32)(size * (f32)D_001D5820), (s32)(size * (f32)D_001D5824), rgb4, clr2, D_001D580C, 0x10, half, -half);
        rgba = ((s32 (*)(s32, s32, f32))func_003894A0)(D_001D582C & 0xFFFFFF, D_001D582C, D_001A4BE0.f1464);
        rgb4[3] = rgba;
        rgb4[2] = rgba;
        rgb4[1] = rgba;
        rgb4[0] = rgba;
        half2 = half - (half + half) * (part / total);
        func_00387DC8(x, y, (s32)(size * (f32)D_001D5820), (s32)(size * (f32)D_001D5824), rgb4, clr2, D_001D580C, 0x10, half, half2);
    }
}
/* localdecomp:end func_003813E0 */

LINKER_REMNANT("asm/remnants", func_00381A48);

/* localdecomp:start func_00381A50 */
typedef struct { u8 p0[0x20]; u8 b20; } H_381A50;
typedef struct { u8 p0[0x10]; f32 f10; u8 p14[0xC]; H_381A50 *f20; u8 b24; u8 b25; u8 p26[0xA]; f32 f30, f34; u8 p38[8]; } E_381A50;
typedef struct { E_381A50 e[14]; s32 n; } T_381A50;
extern T_381A50 D_00224C40_00381A50;
extern s32 D_001A71A4_00381A50[];
extern s32 D_001D5B98;
extern s32 D_001D4BC0_00381A50, D_001D4BC4_00381A50, D_001D4BD0_00381A50, D_001D4BD4_00381A50;
extern void func_003813E0(void);
extern void func_00381DD0(f32 *, void *);
extern void func_003810C0(void *, f32, f32);
void func_00381A50(s32 a) {
    f32 v[2];
    s32 i;
    E_381A50 *p;
    if (D_001A71A4_00381A50[0] == 0x74) {
        D_00224C40_00381A50.n = 0;
        return;
    }
    func_003813E0();
    if (D_00224C40_00381A50.n == 0) return;
    for (i = 0; i < D_00224C40_00381A50.n; i++) {
        p = &D_00224C40_00381A50.e[i];
        if (p->b25 != a || p->f20 == 0 || p->f20->b20 == 0xFE || p->f20->b20 == 0xFD) continue;
        if (p->b24 != 0) {
            func_00381DD0(v, p);
            v[0] = (v[0] - (f32)D_001D4BD0_00381A50) * 0.0625f;
            v[1] = (v[1] - (f32)D_001D4BD4_00381A50) * 0.0625f;
        } else {
            v[0] = (f32)D_001D4BC0_00381A50 * p->f30;
            v[1] = (f32)D_001D4BC4_00381A50 * p->f34;
        }
        if (D_001D5B98 != 0) p->f10 *= 0.75f;
        func_003810C0(p, v[0], v[1]);
    }
    if (D_001D5B98 == 0) D_00224C40_00381A50.n = 0;
}
/* localdecomp:end func_00381A50 */

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

/* localdecomp:start func_00384DA0 */
typedef int Q_384DA0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_384DA0;
typedef struct { u8 p0[0x220]; f32 f220; } S_225980_384DA0;
extern V4_384DA0 D_00222480_00384DA0;
extern S_225980_384DA0 D_00225980_00384DA0;
extern s32 D_001D4BC0_00384DA0, D_001D4BC4_00384DA0;
extern void func_003886E8(f32 *, void *, f32);
extern void func_003888F0();
void func_00384DA0(V4_384DA0 *in, f32 *ox, f32 *oy) {
    V4_384DA0 v;
    Q_384DA0 a, b, r;
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(D_00222480_00384DA0));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*in));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(r));
    func_003886E8(&v.x, &v, 1024.0f);
    v.w = 1.0f;
    func_003888F0(&v, &v, (u8 *)&D_00222480_00384DA0 - 0x100);
    func_003886E8(&v.x, &v, D_00225980_00384DA0.f220 / v.w);
    *ox = v.x + (f32)(D_001D4BC0_00384DA0 >> 1);
    *ox = *ox / (f32)D_001D4BC0_00384DA0;
    *oy = v.y + (f32)(D_001D4BC4_00384DA0 >> 1);
    *oy = *oy / (f32)D_001D4BC4_00384DA0;
}
/* localdecomp:end func_00384DA0 */
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_00384EB0);

/* localdecomp:start func_00384EC0 */
typedef struct { unsigned long v; u16 h8; u16 hA; u8 bC; u8 bD; s16 hE; } T_384EC0;
typedef struct { s32 w0; s16 h4; s16 h6; s32 w8; u8 bC; u8 bD; s16 hE; } C_384EC0;
extern T_384EC0 D_00226080[];
extern C_384EC0 D_00225C80[];
extern s32 D_001A1ED0[];
extern s32 D_001D4BB0;
extern s32 D_001D9C7C;
extern s32 D_001D9C84;
__asm__(".extern D_001D58E0, 8");
__asm__(".extern D_001D58E8, 8");
__asm__(".extern D_001D58F0, 4");
extern unsigned long D_001D58E0;
extern unsigned long D_001D58E8;
extern s32 D_001D58F0;
/* the packet pointer, reloaded after every store */
extern u32 *D_001DA0D0_00384EC0[1];
extern u8 D_141AD0[];
extern u8 D_141DC0[];
long func_00384EC0(s32 i) {
    if (i < 0) {
        if (i == -5) {
            return ((unsigned long)(D_001A1ED0[2] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0x30) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
        } else if (i == -8) {
            return ((unsigned long)(D_001A1ED0[1] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0x1B) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(D_001D58F0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(1) << 61));
        } else if (i == -7) {
            return ((unsigned long)(D_001A1ED0[0] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
        } else if (i == -6) {
            return ((unsigned long)(D_001A1ED0[1] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
        } else if (i == -2 || i == -1) {
            s32 a;
            unsigned long t;
            if (D_001D58E0 != 0) return D_001D58E0;
            a = (D_001D4BB0 + 0x1FFF) & ~0x1FFF;
            D_001D4BB0 = a + 0x20000;
            D_001DA0D0_00384EC0[0][0] = 0x10000003;
            D_001DA0D0_00384EC0[0][1] = 0;
            D_001DA0D0_00384EC0[0][2] = 0;
            D_001DA0D0_00384EC0[0][3] = 0x50000003;
            D_001DA0D0_00384EC0[0][4] = 0x8001;
            D_001DA0D0_00384EC0[0][5] = 0x20000000;
            D_001DA0D0_00384EC0[0][6] = 0xEE;
            D_001DA0D0_00384EC0[0][7] = 0;
            *(unsigned long *)&D_001DA0D0_00384EC0[0][8] = (long)(a >> 13) | 0x2040000;
            D_001DA0D0_00384EC0[0][10] = 0x4D;
            D_001DA0D0_00384EC0[0][11] = 0;
            *(unsigned long *)&D_001DA0D0_00384EC0[0][12] = ((unsigned long)(D_001A1ED0[1] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
            D_001DA0D0_00384EC0[0][14] = 7;
            D_001DA0D0_00384EC0[0][15] = 0;
            D_001DA0D0_00384EC0[0][16] = 0x3000002F;
            D_001DA0D0_00384EC0[0][17] = (u32)D_141AD0;
            D_001DA0D0_00384EC0[0][18] = 0;
            D_001DA0D0_00384EC0[0][19] = 0x5000002F;
            t = ((unsigned long)(a >> 8) | ((unsigned long)(4) << 14) | ((unsigned long)(2) << 20) | ((unsigned long)(8) << 26) |
                ((unsigned long)(8) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
            D_001D58E0 = t;
            D_001DA0D0_00384EC0[0] += 0x14;
            return t;
        } else if (i == -4 || i == -3) {
            s32 a;
            unsigned long t;
            if (D_001D58E8 != 0) return D_001D58E8;
            a = (D_001D4BB0 + 0x1FFF) & ~0x1FFF;
            D_001D4BB0 = a + 0x2000;
            D_001DA0D0_00384EC0[0][0] = 0x10000003;
            D_001DA0D0_00384EC0[0][1] = 0;
            D_001DA0D0_00384EC0[0][2] = 0;
            D_001DA0D0_00384EC0[0][3] = 0x50000003;
            D_001DA0D0_00384EC0[0][4] = 0x8002;
            D_001DA0D0_00384EC0[0][5] = 0x10000000;
            D_001DA0D0_00384EC0[0][6] = 0xEE;
            D_001DA0D0_00384EC0[0][7] = 0;
            *(unsigned long *)&D_001DA0D0_00384EC0[0][8] = (long)(a >> 13) | 0x2010000;
            D_001DA0D0_00384EC0[0][10] = 0x4D;
            D_001DA0D0_00384EC0[0][11] = 0;
            *(unsigned long *)&D_001DA0D0_00384EC0[0][12] = ((unsigned long)(D_001A1ED0[1] >> 8) | ((unsigned long)(8) << 14) | ((unsigned long)(0) << 20) | ((unsigned long)(9) << 26) |
                ((unsigned long)(9) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
            D_001DA0D0_00384EC0[0][14] = 7;
            D_001DA0D0_00384EC0[0][15] = 0;
            D_001DA0D0_00384EC0[0][16] = 0x3000002F;
            D_001DA0D0_00384EC0[0][17] = (u32)D_141DC0;
            D_001DA0D0_00384EC0[0][18] = 0;
            D_001DA0D0_00384EC0[0][19] = 0x5000002F;
            t = ((unsigned long)(a >> 8) | ((unsigned long)(1) << 14) | ((unsigned long)(2) << 20) | ((unsigned long)(6) << 26) |
                ((unsigned long)(6) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(0) << 61));
            D_001D58E8 = t;
            D_001DA0D0_00384EC0[0] += 0x14;
            return t;
        }
    } else {
        T_384EC0 *e = &D_00226080[i];
        if (e->v == 0) {
            s32 base = D_001D4BB0;
            s32 w;
            s32 b0, b1, n;
            unsigned long t;
            w = e->bC;
            w -= 6;
            if (w < 0) w = 0;
            b0 = base >> 8;
            base += 0x400;
            b1 = base >> 8;
            t = ((unsigned long)(b1) | ((unsigned long)(1 << w) << 14) | ((unsigned long)(e->hE) << 20) | ((unsigned long)(e->bC) << 26) |
                ((unsigned long)(e->bD) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(b0) << 37) |
                ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(4) << 61));
            D_001D4BB0 = base + (1 << (e->bC + e->bD));
            e->v = t;
            if (0x3FF000 - D_001D938C < D_001D4BB0) return t;
            n = D_001D9C7C;
            if (n < 0x40) {
                C_384EC0 *c = &D_00225C80[n];
                c->w0 = D_001D9C84 + (e->hA << 6);
                c->h4 = 0;
                c->h6 = b0;
                D_00225C80[n].w8 = D_001D9C84 + (e->h8 << 6);
                c->bC = e->bC;
                c->bD = e->bD;
                c->hE = b1;
                D_001D9C7C = n + 1;
            }
        }
    }
    return D_00226080[i].v;
}
/* localdecomp:end func_00384EC0 */

/* localdecomp:start func_00385438 */
extern s32 D_001D4BB0;
extern s32 D_001DA0D0;
extern u8 D_00331400[];
extern u8 D_00331470[];
extern void func_00388550();
extern void func_003A40C8();
s32 func_00385438(s32 a, s32 p, s32 q, s32 type) {
    s32 e = p - 6;
    s32 v;
    s32 h;
    s32 r;
    u8 *d;
    if (e < 0) e = 0;
    v = (1 << (p + q)) >> 4;
    e = 1 << e;
    if (type == 0x14) {
        v = (1 << (p + q)) >> 5;
        func_00388550(D_001DA0D0, D_00331400, 0x70);
    } else {
        func_00388550(D_001DA0D0, D_00331470, 0x70);
    }
    h = D_001D4BB0;
    r = h >> 8;
    D_001D4BB0 = h + (v << 4);
    d = (u8 *)D_001DA0D0;
    *(u8 *)(d + 0x26) = e;
    *(s32 *)(d + 0x64) = a;
    *(s16 *)(d + 0x24) = r;
    *(s32 *)(d + 0x30) = 1 << p;
    *(s32 *)(d + 0x34) = 1 << q;
    *(s32 *)(d + 0x50) = v | 0x8000;
    *(s32 *)(d + 0x60) = v | 0x30000000;
    *(s32 *)(d + 0x6C) = v | 0x50000000;
    D_001DA0D0 = D_001DA0D0 + 0x70;
    func_003A40C8();
    return r;
}
/* localdecomp:end func_00385438 */

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

/* localdecomp:start func_00385628 */
unsigned long func_00385628(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 w = c - 6;
    if (w < 0) w = 0;
    w = 1 << w;
    return ((unsigned long)(a) | ((unsigned long)(w) << 14) | ((unsigned long)(e) << 20) | ((unsigned long)(c) << 26) |
        ((unsigned long)(d) << 30) | ((unsigned long)(1) << 34) | ((unsigned long)(0) << 35) | ((unsigned long)(b) << 37) |
        ((unsigned long)(0) << 51) | ((unsigned long)(0) << 55) | ((unsigned long)(0) << 56) | ((unsigned long)(4) << 61));
}
/* localdecomp:end func_00385628 */

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

/* localdecomp:start func_00385CE0 */
extern s32 D_001D4D40_00385CE0;
extern s32 D_002257B4_00385CE0[];
extern s32 D_001D55E8_00385CE0;
extern s32 D_00143950[];
extern f32 func_00388960(f32);
extern void func_003894A0(s32, s32, f32);
extern void func_00389920(s32);
extern s32 func_0037DF98(s32);
extern void func_00389FB8_00385CE0(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
void func_00385CE0(void) {
    f32 f, y;
    s32 old, n;
    if (D_001D4D40_00385CE0 == 1) {
        n = ((u8 *)D_00143950)[0xAD] ? 0x30 : 0x5A;
        f = (f32)(D_002257B4_00385CE0[0] % 100) / 50.0f - 1.0f;
        if (f < -1.0f) f = -1.0f;
        if (1.0f < f) f = 1.0f;
        y = n;
        f = func_00388960(f * 3.1415927f);
        n = ((s32 (*)(s32, s32, f32))func_003894A0)(0x7FE0E0E0, 0x5F66CCFF, (f + 1.0f) * 0.5f);
        old = D_001D55E8_00385CE0;
        func_00389920(0);
        func_00389FB8_00385CE0(480.0f, y, 1.0f, n, func_0037DF98(0x244), -1, 1.0f, 2, 1, 0x80000000, 1.0f, 1.0f);
        func_00389920(old);
    }
}
/* localdecomp:end func_00385CE0 */

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

/* localdecomp:start func_003869E8 */
/* PROVISIONAL, VU0 j-constraint form (needs -mvu0-use-vf0-vf2, override in tools/text_parts.txt).
   Saves $ra and $s0-$s6 with sq (tools/sq_ra_funcs.txt), so the override also drops -fopt-stack. */
typedef int Q_3869E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3869E8;
extern s32 D_001DA0D0;
extern Q_3869E8 D_001D76C0_003869E8[];
extern s32 D_001D4BD0_003869E8, D_001D4BD4_003869E8;
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
static __inline__ void vadd_3869E8(V_3869E8 *d, V_3869E8 *a, V_3869E8 *b) {
    Q_3869E8 x, y;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(x));
}
static __inline__ void vsub_3869E8(V_3869E8 *d, V_3869E8 *a, V_3869E8 *b) {
    Q_3869E8 x, y;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(x));
}
void func_003869E8(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 du, s32 dv, f32 ang, long col, long tex) {
    V_3869E8 a, b, c, p[4];
    s32 hw, hh, u1, v1, u4, uw4, v20, vh20;
    long z;
    long *q;
    hh = h >> 1;
    hw = w >> 1;
    c.x = x + hw;
    c.y = y + hh;
    u4 = u << 4;
    u1 = (u + du) << 4;
    v1 = v + dv;
    a.x = (f32)hh * func_00388978(ang);
    a.y = (f32)hh * func_00388960(ang);
    b.x = (f32)-hw * func_00388960(ang);
    b.y = (f32)hw * func_00388978(ang);
    v20 = v << 20;
    vh20 = v1 << 20;
    z = 0xFFFFF000000000UL;
    vadd_3869E8(&p[3], &c, &a);
    vsub_3869E8(&p[3], &p[3], &b);
    vadd_3869E8(&p[2], &c, &a);
    vadd_3869E8(&p[2], &p[2], &b);
    vsub_3869E8(&p[1], &c, &a);
    vsub_3869E8(&p[1], &p[1], &b);
    vsub_3869E8(&p[0], &c, &a);
    vadd_3869E8(&p[0], &p[0], &b);
    *(s32 *)(D_001DA0D0 + 0) = 0x10000007;
    *(s32 *)(D_001DA0D0 + 4) = 0;
    *(s32 *)(D_001DA0D0 + 8) = 0;
    *(s32 *)(D_001DA0D0 + 0xC) = 0x50000007;
    D_001DA0D0 += 0x10;
    *(Q_3869E8 *)D_001DA0D0 = D_001D76C0_003869E8[0];
    D_001DA0D0 += 0x10;
    q = (long *)D_001DA0D0;
    q[0] = tex;
    q[1] = 0x154;
    q[2] = col;
    q[3] = v20 + u4;
    q[4] = (long)(((s32)p[0].x << 4) + D_001D4BD0_003869E8 - 8) | (long)(((s32)p[0].y << 4) + D_001D4BD4_003869E8 - 8) << 16 | z;
    q[5] = v20 + u1;
    q[6] = (long)(((s32)p[1].x << 4) + D_001D4BD0_003869E8 - 8) | (long)(((s32)p[1].y << 4) + D_001D4BD4_003869E8 - 8) << 16 | z;
    q[7] = vh20 + u4;
    q[8] = (long)(((s32)p[2].x << 4) + D_001D4BD0_003869E8 - 8) | (long)(((s32)p[2].y << 4) + D_001D4BD4_003869E8 - 8) << 16 | z;
    q[9] = vh20 + u1;
    q[10] = (long)(((s32)p[3].x << 4) + D_001D4BD0_003869E8 - 8) | (long)(((s32)p[3].y << 4) + D_001D4BD4_003869E8 - 8) << 16 | z;
    q[11] = 0;
    D_001DA0D0 += 0x60;
}
/* localdecomp:end func_003869E8 */

/* localdecomp:start func_00386D98 */
extern s32 D_001D4BD0_00386D98;
extern s32 D_001D4BD4_00386D98;
extern u8 D_001D76C0[];
void func_00386D98(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, long a8, long a9)
{
  u8 *r;
  u8 *p;
  u8 *q;
  s32 ox;
  s32 oy;
  long x0;
  long y0;
  long x1;
  long y1;
  long k;
  s32 u0;
  s32 u1;
  s32 v0;
  s32 v1;
  ox = D_001D4BD0_00386D98;
  oy = D_001D4BD4_00386D98;
  *((s32 *) (D_001DA0D0 + 0)) = 0x10000007;
  u1 = (u + uw) << 4;
  x1 = (((x + w) << 4) + ox) - 8;
  y0 = ((long) (((y << 4) + oy) - 8)) << 16;
  *((s32 *) (D_001DA0D0 + 4)) = 0;
  *((s32 *) (D_001DA0D0 + 8)) = 0;
  *((s32 *) (D_001DA0D0 + 0xC)) = 0x50000007;
  r = (u8 *) D_001DA0D0;
  k = 0xFFFFF000000000UL;
  D_001DA0D0 = ((s32) r) + 0x10;
  x0 = ((x << 4) + ox) - 8;
  v1 = (v + vh) << 20;
  u0 = u << 4;
  v0 = v << 20;
  *((u128_t *) (r + 0x10)) = *((u128_t *) D_001D76C0);
  y1 = ((long) ((((y + h) << 4) + oy) - 8)) << 16;
  p = (u8 *) D_001DA0D0;
  q = p + 0x10;
  D_001DA0D0 = (s32) q;
  *((long *) (p + 0x10)) = a9;
  *((long *) (q + 8)) = 0x154;
  *((long *) (q + 0x18)) = v0 + u0;
  *((long *) (q + 0x20)) = (x0 | y0) | k;
  *((long *) (q + 0x28)) = v0 + u1;
  *((long *) (q + 0x30)) = (x1 | y0) | k;
  *((long *) (q + 0x38)) = v1 + u0;
  *((long *) (q + 0x40)) = (x0 | y1) | k;
  *((long *) (q + 0x48)) = v1 + u1;
  *((long *) (q + 0x10)) = a8;
  *((long *) (q + 0x50)) = (x1 | y1) | k;
  *((long *) (q + 0x58)) = 0;
  D_001DA0D0 = D_001DA0D0 + 0x60;
}
/* localdecomp:end func_00386D98 */

LINKER_REMNANT("asm/remnants", func_00386F28);

/* localdecomp:start func_00386F38 */
extern s32 D_001D4BD0_00386F38, D_001D4BD4_00386F38;
extern s32 D_001DA0D0;
s32 func_00386F38(s32 u, s32 v, s32 w, s32 h, long t0, long t1, s32 flag, f32 x, f32 y, f32 fw, f32 fh) {
    s32 u1 = u + w;
    s32 v1 = v + h;
    s32 x0 = (s32)(x * 16.0f) + D_001D4BD0_00386F38 - 8;
    s32 x1 = (s32)((x + fw) * 16.0f) + D_001D4BD0_00386F38 - 9;
    s32 y0 = (s32)(y * 16.0f) + D_001D4BD4_00386F38 - 8;
    s32 y1 = (s32)((y + fh) * 16.0f) + D_001D4BD4_00386F38 - 9;
    s32 u4 = u << 4;
    s32 uw4 = u1 << 4;
    long *p;
    if (x0 > 0x9000 || x1 < 0x7000 || y0 > 0x9000 || y1 < 0x7000) return 0;
    if (flag) {
        x0 = (x0 & 0xFFF0) + 8;
        x1 = (x1 & 0xFFF0) + 8;
        y0 = (y0 & 0xFFF0) + 8;
        y1 = (y1 & 0xFFF0) + 8;
    }
    p = (long *)D_001DA0D0;
    p[0] = t1;
    p[1] = 0x154;
    p[2] = 0xA | (long)u << 4 | (long)(u1 - 1) << 14 | (long)v << 24 | (long)(v1 - 1) << 34;
    p[3] = t0;
    p[4] = (v << 20) + u4;
    p[5] = (long)x0 | (long)y0 << 16;
    p[6] = (v << 20) + uw4;
    p[7] = (long)x1 | (long)y0 << 16;
    p[8] = (v1 << 20) + u4;
    p[9] = (long)x0 | (long)y1 << 16;
    p[10] = (v1 << 20) + uw4;
    p[11] = (long)x1 | (long)y1 << 16;
    D_001DA0D0 += 0x60;
    return 1;
}
/* localdecomp:end func_00386F38 */

/* localdecomp:start func_00387118 */
extern s32 D_001D4BD0_00387118, D_001D4BD4_00387118;
extern s32 D_001DA0D0;
s32 func_00387118(s32 u, s32 v, s32 w, s32 h, long *c, long t1, s32 flag, f32 x, f32 y, f32 fw, f32 fh) {
    s32 u1 = u + w;
    s32 v1 = v + h;
    s32 x0 = (s32)(x * 16.0f) + D_001D4BD0_00387118 - 8;
    s32 x1 = (s32)((x + fw) * 16.0f) + D_001D4BD0_00387118 - 9;
    s32 y0 = (s32)(y * 16.0f) + D_001D4BD4_00387118 - 8;
    s32 y1 = (s32)((y + fh) * 16.0f) + D_001D4BD4_00387118 - 9;
    s32 u4 = u << 4;
    s32 uw4 = u1 << 4;
    long *p;
    if (x0 > 0x9000 || x1 < 0x7000 || y0 > 0x9000 || y1 < 0x7000) return 0;
    if (flag) {
        x0 = (x0 & 0xFFF0) + 8;
        x1 = (x1 & 0xFFF0) + 8;
        y0 = (y0 & 0xFFF0) + 8;
        y1 = (y1 & 0xFFF0) + 8;
    }
    p = (long *)D_001DA0D0;
    p[0] = t1;
    p[1] = 0x154;
    p[2] = 0xA | (long)u << 4 | (long)(u1 - 1) << 14 | (long)v << 24 | (long)(v1 - 1) << 34;
    p[3] = c[0];
    p[4] = (v << 20) + u4;
    p[5] = (long)x0 | (long)y0 << 16;
    p[6] = c[1];
    p[7] = (v << 20) + uw4;
    p[8] = (long)x1 | (long)y0 << 16;
    p[9] = c[2];
    p[10] = (v1 << 20) + u4;
    p[11] = (long)x0 | (long)y1 << 16;
    p[12] = c[3];
    p[13] = (v1 << 20) + uw4;
    p[14] = (long)x1 | (long)y1 << 16;
    p[15] = 0;
    D_001DA0D0 += 0x80;
    return 1;
}
/* localdecomp:end func_00387118 */

/* localdecomp:start func_003872F8 */
extern s32 D_001D4BD0_003872F8;
extern s32 D_001D4BD4_003872F8;
s32 func_003872F8(s32 x, s32 y, s32 w, s32 h, long t0, long t1, long t2, s32 snap,
                  f32 sx, f32 sy, f32 sw, f32 sh, f32 dx, f32 dy) {
    s32 x2, y2;
    s32 U0, U1, V0, V1, U0d, U1d, V0d, V1d;
    long clamp;
    long *p;
    s32 ox, oy, ddx, ddy;
    s32 tx0, tx1;
    f32 ex, ey;
    ex = sx + sw;
    dy = dy * 16.0f;
    dx = dx * 16.0f;
    ox = D_001D4BD0_003872F8;
    U0 = (s32)(sx * 16.0f) + ox - 8;
    ddx = (s32)dx;
    tx0 = x << 4;
    U0d = U0 + ddx;
    U1 = (s32)(ex * 16.0f) + ox - 8;
    oy = D_001D4BD4_003872F8;
    U1d = U1 + ddx;
    ddy = (s32)dy;
    x2 = x + w;
    ey = sy + sh;
    V0 = (s32)(sy * 16.0f) + oy - 8;
    y2 = y + h;
    V1 = (s32)(ey * 16.0f) + oy - 8;
    V0d = V0 + ddy;
    V1d = V1 + ddy;
    tx1 = x2 << 4;
    if (U0 > 0x9000 || U1 < 0x7000 || V0 > 0x9000 || V1 < 0x7000) return 0;
    if (snap) {
        U0 = (U0 & 0xFFF0) + 8;
        U1 = (U1 & 0xFFF0) + 8;
        V0 = (V0 & 0xFFF0) + 8;
        V1 = (V1 & 0xFFF0) + 8;
        U0d = (U0d & 0xFFF0) + 8;
        U1d = (U1d & 0xFFF0) + 8;
        V0d = (V0d & 0xFFF0) + 8;
        V1d = (V1d & 0xFFF0) + 8;
    }
    clamp = 0xA | ((long)x << 4) | ((long)(x2 - 1) << 14) | ((long)y << 24) | ((long)(y2 - 1) << 34);
    p = (long *)D_001DA0D0;
    p[0] = t2;
    p[1] = 0x154;
    p[2] = clamp;
    p[3] = t1;
    p[4] = (y << 20) + tx0;
    p[5] = (long)U0d | ((long)V0d << 16);
    p[6] = (y << 20) + tx1;
    p[7] = (long)U1d | ((long)V0d << 16);
    p[8] = (y2 << 20) + tx0;
    p[9] = (long)U0d | ((long)V1d << 16);
    p[10] = (y2 << 20) + tx1;
    p[11] = (long)U1d | ((long)V1d << 16);
    p[12] = t2;
    p[13] = 0x154;
    p[14] = clamp;
    p[15] = t0;
    p[16] = (y << 20) + tx0;
    p[17] = (long)U0 | ((long)V0 << 16);
    p[18] = (y << 20) + tx1;
    p[19] = (long)U1 | ((long)V0 << 16);
    p[20] = (y2 << 20) + tx0;
    p[21] = (long)U0 | ((long)V1 << 16);
    p[22] = (y2 << 20) + tx1;
    p[23] = (long)U1 | ((long)V1 << 16);
    D_001DA0D0 += 0xC0;
    return 1;
}
/* localdecomp:end func_003872F8 */

/* localdecomp:start func_003875A0 */
typedef int Q_3875A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3875A0;
extern s32 D_001D4BD0_003875A0;
extern s32 D_001D4BD4_003875A0;
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003886E8(f32 *, void *, f32);
void func_003875A0(f32 px, f32 py, f32 sx, f32 sy, f32 ang, s32 w, s32 h, long tex, s32 z, s32 rgba,
                   s32 fx, s32 fy, f32 ax, f32 ay) {
    V4_3875A0 a, b, c, t, p0, p1, p2, p3;
    s32 u0, u1, v0, v1;
    f32 bx, by, sn;
    long zz;
    u8 bfx = fx;
    u8 bfy = fy;
    if (bfx) {
        u0 = w << 4;
        u1 = 0x10;
    } else {
        u1 = w << 4;
        u0 = 0x10;
    }
    if (bfy) {
        v0 = h << 20;
        v1 = 0x100000;
    } else {
        v1 = h << 20;
        v0 = 0x100000;
    }
    c.x = px;
    c.y = py;
    sn = func_00388978(ang);
    bx = 1.0f;
    by = bx - ay;
    bx = bx - ax;
    a.x = sy * sn;
    a.y = sy * func_00388960(ang);
    b.x = sx * func_00388960(ang);
    b.y = -sx * func_00388978(ang);
    func_003886E8(&t.x, &a, by);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(c));
      __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(r1)); }
    func_003886E8(&t.x, &b, bx);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(p0));
      __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(r1)); }
    func_003886E8(&t.x, &a, by);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(c));
      __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(r1)); }
    func_003886E8(&t.x, &b, ax);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(p1));
      __asm__("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(r1)); }
    func_003886E8(&t.x, &a, ay);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(c));
      __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(r1)); }
    func_003886E8(&t.x, &b, bx);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(p2));
      __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(r1)); }
    func_003886E8(&t.x, &a, ay);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(t));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(c));
      __asm__("vsub.xyz %0, %1, %2" : "=j"(r1) : "j"(r1), "j"(r2));
      __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(r1)); }
    func_003886E8(&t.x, &b, ax);
    { Q_3875A0 r1, r2;
      __asm__("lqc2 %0, %1" : "=j"(r2) : "m"(p3));
      __asm__("lqc2 %0, %1" : "=j"(r1) : "m"(t));
      __asm__("vadd.xyz %0, %1, %2" : "=j"(r2) : "j"(r2), "j"(r1));
      __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(r2)); }
    *(u32 *)(D_001DA0D0 + 0) = 0x10000007;
    *(u32 *)(D_001DA0D0 + 4) = 0;
    *(u32 *)(D_001DA0D0 + 8) = 0;
    *(u32 *)(D_001DA0D0 + 0xC) = 0x50000007;
    zz = (long)z << 32;
    {
        long *t2 = (long *)(D_001DA0D0 + 0x10);
        D_001DA0D0 = (s32)t2;
        t2[0] = 0xB400000000008001UL;
        t2[2] = tex;
        t2[1] = (0xA6A6A6A6UL << 11) | 0x106;
        t2[4] = rgba;
        t2[3] = 0x154;
        t2[5] = u0 | v0;
        t2[6] = ((s32)(p0.x * 16.0f) + D_001D4BD0_003875A0 - 8) | ((long)((s32)(p0.y * 16.0f) + D_001D4BD4_003875A0 - 8) << 16) | zz;
        t2[7] = u1 | v0;
        t2[8] = ((s32)(p1.x * 16.0f) + D_001D4BD0_003875A0 - 8) | ((long)((s32)(p1.y * 16.0f) + D_001D4BD4_003875A0 - 8) << 16) | zz;
        t2[9] = u0 | v1;
        t2[10] = ((s32)(p2.x * 16.0f) + D_001D4BD0_003875A0 - 8) | ((long)((s32)(p2.y * 16.0f) + D_001D4BD4_003875A0 - 8) << 16) | zz;
        t2[11] = u1 | v1;
        t2[12] = ((s32)(p3.x * 16.0f) + D_001D4BD0_003875A0 - 8) | ((long)((s32)(p3.y * 16.0f) + D_001D4BD4_003875A0 - 8) << 16) | zz;
        t2[13] = 0;
    }
    D_001DA0D0 += 0x70;
}
/* localdecomp:end func_003875A0 */

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

/* localdecomp:start func_00387B10 */
typedef int u128_387B10 __attribute__((mode(TI)));
extern s32 D_001DA0D0;
extern u8 D_001D7740[];
void func_00387B10(long *a, s32 *b) {
    u8 *p;
    u8 *q;
    u8 *r;
    *(s32 *)(D_001DA0D0 + 0) = 0x10000005;
    *(s32 *)(D_001DA0D0 + 4) = 0;
    *(s32 *)(D_001DA0D0 + 8) = 0;
    *(s32 *)(D_001DA0D0 + 0xC) = 0x50000005;
    r = (u8 *)D_001DA0D0;
    D_001DA0D0 = (s32)r + 0x10;
    *(u128_387B10 *)(r + 0x10) = *(u128_387B10 *)D_001D7740;
    p = (u8 *)D_001DA0D0;
    q = p + 0x10;
    D_001DA0D0 = (s32)q;
    *(long *)(p + 0x10) = 0x4C;
    *(long *)(q + 8) = b[0];
    *(long *)(q + 0x10) = a[0];
    *(long *)(q + 0x18) = a[2];
    *(long *)(q + 0x20) = b[1];
    *(long *)(q + 0x28) = a[1];
    *(long *)(q + 0x30) = a[3];
    *(long *)(q + 0x38) = 0;
    D_001DA0D0 = D_001DA0D0 + 0x40;
}
/* localdecomp:end func_00387B10 */

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

/* localdecomp:start func_00387DC8 */
typedef struct { f32 x, y, z, w; } V_387DC8;
extern void func_00387A00(long *, s32 *, s32 *, long, s32);
void func_00387DC8(s32 x, s32 y, s32 rx, s32 ry, s32 *a4, s32 *a5, s32 col, s32 n, f32 a0, f32 a1) {
    long base = 0xFFFFF000000000;
    long pts[4];
    V_387DC8 v0, v1;
    long c;
    f32 step, ang, ang2;
    s32 i;
    c = func_00384EC0(col);
    step = (a1 - a0) / (f32)n;
    ang = ((f32 (*)(f32, f32))func_00389380)(a0, 1.5707964f);
    ang2 = ((f32 (*)(f32, f32))func_00389380)(ang, step);
    for (i = 15; i >= 0; i--) {
        v0.x = func_00388960(ang);
        v0.y = func_00388978(ang);
        v0.z = 0.0f;
        v1.x = func_00388960(ang2);
        v1.y = func_00388978(ang2);
        v1.z = 0.0f;
        ang = ang2;
        pts[0] = ((long)(s32)(v0.x * (f32)rx) + x) + (((long)(s32)(v0.y * (f32)rx) + y) << 16) + base;
        pts[1] = ((long)(s32)(v0.x * (f32)ry) + x) + (((long)(s32)(v0.y * (f32)ry) + y) << 16) + base;
        pts[2] = ((long)(s32)(v1.x * (f32)rx) + x) + (((long)(s32)(v1.y * (f32)rx) + y) << 16) + base;
        pts[3] = ((long)(s32)(v1.x * (f32)ry) + x) + (((long)(s32)(v1.y * (f32)ry) + y) << 16) + base;
        func_00387A00(pts, a5, a4, c, 1);
        ang2 = ((f32 (*)(f32, f32))func_00389380)(ang, step);
    }
}
/* localdecomp:end func_00387DC8 */
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
