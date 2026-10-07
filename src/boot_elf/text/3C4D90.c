#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern long func_00389920(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003C4E68(f32 *v, f32 r);
extern void func_003C56B0(void *, s32, f32, f32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C4D90 */
s32 func_003C4D90(s32 arg0) {
    return (u32)(arg0 - 500) < 41;
}
/* localdecomp:end func_003C4D90 */

/* localdecomp:start func_003C4DA0 */
extern s32 func_003C4D90_003C4DA0(s16);
extern u32 D_001DA51C[];
extern u32 D_001DA524[];
s32 func_003C4DA0(u32 arg0) {
    if (arg0 == 0) return 0;
    if (arg0 < D_001DA51C[0]) return 0;
    if (D_001DA524[0] >= arg0) {
        return func_003C4D90_003C4DA0(*(s16 *)((u8 *)arg0 + 0xAA)) != 0;
    }
    return 0;
}
/* localdecomp:end func_003C4DA0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4DF0);

/* localdecomp:start func_003C4E00 */
extern f32 func_0038D1D0(s32 a);
extern void func_0038D290(s32 a, s32 b, f32 x);
void func_003C4E00(s32 a, f32 x) {
    if (x < func_0038D1D0(a)) func_0038D290(a, a, x);
}
/* localdecomp:end func_003C4E00 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4E50);

/* localdecomp:start func_003C4E68 */
extern f32 func_003828E0(f32, f32);
void func_003C4E68(f32 *v, f32 r) {
    v[0] += func_003828E0(-r, r);
    v[1] += func_003828E0(-r, r);
    v[2] += func_003828E0(-r, r);
}
/* localdecomp:end func_003C4E68 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4EE8);

/* localdecomp:start func_003C4F38 */
extern void func_0038D290(s32 a, s32 b, f32 x);
void func_003C4F38(void *a, f32 f) {
    f32 r;
    ((void (*)(void *, f32))func_0038D290)(a, f);
    r = 1.0f - f * f;
    __asm__("nop\n\tnop\n\tsqrt.s %0, %1" : "=f"(r) : "f"(r));
    *(f32*)((u8*)a + 0xC) = r;
}
/* localdecomp:end func_003C4F38 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4F88);

/* localdecomp:start func_003C4FA8 */
int func_003C4FA8(unsigned char *object) {
    unsigned char *link;
    int flags;

    if (object != 0)
        goto check_flags;
failure:
    return 0;
check_flags:
    flags = *(unsigned short *)(object + 0x34) & 0x20;
    __asm__ volatile(".word 0");
    if (flags == 0)
        goto failure;
    link = *(unsigned char **)(object + 0x68);
    if (link == 0)
        goto failure;
    return *(int *)(link + 8);
}
/* localdecomp:end func_003C4FA8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4FE0);

/* localdecomp:start func_003C4FF8 */
typedef int u128_3BF838 __attribute__((mode(TI)));
typedef struct { u128_3BF838 r[4]; } M_3BF838;
extern void func_0038D650();
extern void func_0038D8D8();
extern void func_0038D968();
extern void func_003C4B20();
void func_003C4FF8(u8 *p, u128_3BF838 *a1, u128_3BF838 *a2, void *a3) {
    M_3BF838 m0, m1, m2, m3;
    func_0038D650(&m0, a2);
    func_0038D8D8(&m1, &m0);
    func_0038D650(&m2, a3);
    func_0038D968(&m3, &m1, &m2);
    func_003C4B20(&m3, p);
    if (*(s32 *)(p + 0x3C) & 2) {
        *(u128_3BF838 *)(p + 0x20) = *a2;
    }
    *(u128_3BF838 *)(p + 0x10) = *a1;
}
/* localdecomp:end func_003C4FF8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C50B8);

/* localdecomp:start func_003C50D0 */
extern s32 func_0038D380(f32 *);
void func_003C50D0(void *a, void *b) {
    f32 *v = (f32 *)a;
    f32 t[4];
    f32 x, y, z, ax, ay, az, m, s;
    s32 n;
    x = v[0];
    y = v[1];
    z = v[2];
    __asm__("abs.s %0, %1" : "=f"(ax) : "f"(x));
    __asm__("abs.s %0, %1" : "=f"(ay) : "f"(y));
    __asm__("abs.s %0, %1" : "=f"(az) : "f"(z));
    if (ay < ax) ay = ax;
    m = ay;
    m = (az < m) ? m : az;
    n = (s32)(m * 10000.0f / 63.0f);
    if (n >= 256) n = 255;
    if (n <= 0) n = 1;
    t[3] = n;
    s = 1.0f / (t[3] * 0.0001f);
    t[0] = x * s + 127.0f;
    t[1] = y * s + 127.0f;
    t[2] = z * s + 127.0f;
    *(s32 *)b = func_0038D380(t);
}
/* localdecomp:end func_003C50D0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C51D8);

/* localdecomp:start func_003C52B8 */
typedef struct { u8 pad[0x40]; } M_3BFAF8;
void func_0038D8D8(M_3BFAF8 *, void *);
void func_0038D328(void *, void *, M_3BFAF8 *);
void func_003C52B8(u8 *a, void *b, void *c, M_3BFAF8 *d) {
M_3BFAF8 m; if (d == 0) { func_0038D8D8(&m, a + 0xC0); func_0038D328(b, c, &m); } else { func_0038D328(b, c, d); }
}
/* localdecomp:end func_003C52B8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C5320);

/* localdecomp:start func_003C5340 */
f32 func_003C5340(s32 a, s32 b, s32 c) {
    f32 v[4];
    func_003C52B8(a, v, b, c);
    return v[2];
}
/* localdecomp:end func_003C5340 */

/* localdecomp:start func_003C5368 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFBA8;
typedef int Q_3BFBA8 __attribute__((mode(TI)));
extern f32 D_001D5C00;
extern void func_0038D148(f32 *, void *, f32);
void func_003C5368(void *a, f32 *out, s32 f) {
    Q_3BFBA8 p, q, r;
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(D_001D5C00));
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(V4_3BFBA8 *)a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(p), "j"(q));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFBA8 *)out) : "j"(r));
    out[2] = 0;
    ((void (*)(void *, f32))func_0038D290)(out, 1.0f);
    if (f == 0) {
        func_0038D148(out, out, -1.0f);
    }
}
/* localdecomp:end func_003C5368 */

/* localdecomp:start func_003C53D8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFC18;
typedef int Q_3BFC18 __attribute__((mode(TI)));
extern s32 D_001D5BEC_003C53D8;
extern s32 D_001D5BF0;
typedef struct { u8 p0[0xB0]; V4_3BFC18 v; } S_3BFC18;
extern S_3BFC18 D_001A4BE0;
extern void func_0038D148(f32 *, void *, f32);
extern void func_003C5368(void *, void *, s32);
void func_003C53D8(void *a, f32 *out, s32 flag) {
    if (D_001D5BEC_003C53D8 == 0) {
        Q_3BFC18 r;
        __asm__("vmr32.xyzw %0, $vf0" : "=j"(r));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFC18 *)out) : "j"(r));
    } else if (D_001D5BF0 != 0) {
        func_003C5368(a, out, 1);
    } else {
        Q_3BFC18 p, q, r;
        S_3BFC18 *d = &D_001A4BE0;
        f32 s = 1.0f;
        if (d->v.w > 0.0f) {
            s = -1.0f;
        }
        __asm__("lqc2 %0, %1" : "=j"(p) : "m"(*(V4_3BFC18 *)a));
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(d->v));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(q), "j"(p));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFC18 *)out) : "j"(r));
        ((void (*)(void *, void *, f32))func_0038D290)(out, out, s);
    }
    if (flag == 0) {
        func_0038D148(out, out, -1.0f);
    }
}
/* localdecomp:end func_003C53D8 */

/* localdecomp:start func_003C54A8 */
extern void func_003C53D8(void *);
 
void func_003C54A8(void *p) {
    func_003C53D8((u8 *)p + 0x10);
}
/* localdecomp:end func_003C54A8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C54C8);

/* localdecomp:start func_003C54D0 */
extern s32 D_001D5BEC[];
extern void func_003C53D8_003C54D0();
extern void func_0038D290(s32, s32, f32);
void func_003C54D0(void *a0, f32 *out, f32 *in, f32 f) {
    f32 v[4];
    if (D_001D5BEC[0] == 0) {
        out[2] = in[2] - f;
    } else {
        func_003C53D8_003C54D0(a0, v, 0);
        func_0038D290((s32)v, (s32)v, f);
        __asm__ __volatile__(
            "lqc2 $vf1, 0(%1)\n"
            "lqc2 $vf2, 0(%2)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0(%0)\n"
            : : "r"(out), "r"(in), "r"(v) : "memory");
    }
}
/* localdecomp:end func_003C54D0 */

/* localdecomp:start func_003C5550 */
extern void func_003C54D0_003C5550(void *);
 
void func_003C5550(void *p) {
    func_003C54D0_003C5550((u8 *)p + 0x10);
}
/* localdecomp:end func_003C5550 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C5570);

/* localdecomp:start func_003C5578 */
extern void func_0038D148(f32 *, void *, f32);
extern void func_003C55C8(s32, f32 *, s32);
void func_003C5578(s32 a, s32 b, s32 c) {
    f32 buf[4];
    ((void (*)(f32 *, f32))func_0038D148)(buf, -1.0f);
    func_003C55C8(a, buf, c);
}
/* localdecomp:end func_003C5578 */

/* localdecomp:start func_003C55C8 */
extern void func_0038D1B8(f32 *, f32 *, s32);
extern void func_0038DB38(f32 *, f32 *);
extern void func_0038D918(s32, f32 *, s32);
extern void func_0038CFB0(s32, f32 *, s32);
void func_003C55C8(s32 a, f32 *unused, s32 c) {
    f32 m[12];
    f32 b[4];
    f32 v[4];
    f32 r;
    ((void (*)(f32 *, f32))func_0038D290)(v, 1.0f);
    func_0038D1B8(b, v, a + 0x20);
    ((void (*)(f32 *, f32 *, f32))func_0038D148)(b, b, 0.5f);
    r = func_0038D1D0((s32)b);
    r = 1.0f - r * r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(r));
    b[3] = -r;
    func_0038DB38(b, m);
    func_0038D918(a, m, a);
    if (c) func_0038CFB0(c, m, 0x30);
}
/* localdecomp:end func_003C55C8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C56A0);

/* localdecomp:start func_003C56B0 */
typedef int Q_3BFEF0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BFEF0;
typedef struct { f32 m[4][4]; s32 c[4]; f32 uv[8]; long gs[4]; } P_3BFEF0;
extern V_3BFEF0 D_00222480;
__asm__(".extern D_001D91B0, 8");
extern f32 D_001D91B0[2];
extern void func_0038D350();
extern void func_003D2FF0();
void func_003C56B0(void *pos, s32 color, f32 size, f32 off) {
    P_3BFEF0 d;
    V_3BFEF0 up;
    V_3BFEF0 b[4];
    V_3BFEF0 o;
    f32 *m;
    f32 *tbl = D_001D91B0;
    s32 i = 3;
    f32 one = 1.0f;
    *(Q_3BFEF0 *)&up = 0;
    up.z = one;
    up.w = one;
    d.gs[1] = func_00389920(0xB);
    d.gs[3] = 0x8000000048UL;
    d.gs[2] = 0xFF9000000260UL;
    d.gs[0] = 5;
    *(Q_3BFEF0 *)&b[3] = *(Q_3BFEF0 *)pos;
    d.uv[0] = 0.0f;
    d.uv[1] = 0.0f;
    d.uv[2] = 0.0f;
    d.uv[3] = one;
    d.uv[4] = one;
    d.uv[5] = 0.0f;
    d.uv[6] = one;
    d.uv[7] = one;
    {
        Q_3BFEF0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_00222480));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b[3]));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(b[0]) : "j"(y));
    }
    func_0038D290((s32)&b[0], (s32)&b[0], one);
    func_0038D1B8((f32 *)&b[1], (f32 *)&b[0], (s32)&up);
    func_0038D290((s32)&b[1], (s32)&b[1], one);
    func_0038D1B8((f32 *)&b[2], (f32 *)&b[1], (s32)&b[0]);
    func_0038D148((f32 *)&o, &b[0], off);
    {
        Q_3BFEF0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b[3]));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(b[3]) : "j"(x));
    }
    d.c[3] = color;
    d.c[2] = color;
    d.c[1] = color;
    d.c[0] = color;
    m = d.m[0];
    for (; i >= 0; i--) {
        func_0038D148(m, tbl, size);
        tbl += 4;
        func_0038D350(m, m, b);
        m += 4;
    }
    func_003D2FF0(&d, 0, 0);
}
/* localdecomp:end func_003C56B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C5878);

/* localdecomp:start func_003C5948 */
/* VU0 j-form: each VU0 instruction is a separate non-volatile __asm__ using the "j" (VU0
   register) constraint, which needs -mvu0-use-vf0-vfN. The original build used N = 2 on every
   file (tools/text_parts.txt carries -mvu0-use-vf0-vf2 on every line); see Matching-Patterns,
   "VU0 j-form: one asm statement per instruction". */
typedef struct {
    u8 p0[7]; u8 f7; u8 p8[9]; u8 f11; u8 f12; u8 p13; u8 f14; u8 p15; u8 f16; u8 f17; u8 p18[4];
    f32 f1C; f32 f20; f32 f24; f32 f28; f32 f2C; f32 f30; f32 f34; u16 f38; u8 p3A[0x12];
    f32 f4C; f32 f50; f32 f54; u8 p58[8]; f32 f60; f32 f64; u8 p68[4]; s8 f6C; s8 f6D; s8 f6E; s8 f6F;
    u8 p70[2]; s8 f72; s8 f73; u8 p74[2]; u8 f76; u8 p77; u8 f78; u8 f79; u8 f7A; u8 p7B[5];
    f32 f80; f32 f84; f32 f88; u8 p8C[4]; f32 f90; f32 f94;
} E_3C0188;
typedef struct { u8 p0[0x1C]; f32 *f1C; } T_3C0188;
typedef struct {
    u8 p0[0x34]; u16 f34; u8 p36[0xE]; f32 f44; u8 p48[4]; f32 f4C; u8 p50[0x18]; T_3C0188 *f68; u8 p6C[0x2C]; s32 f98;
} O_3C0188;

extern s32 D_001D5BEC_003C5948;
extern void func_003C3CB0(void *, s32, s32, s32);
extern void func_003C50D0(void *, void *);
extern f32 func_0038D190(void *, void *);
extern void func_003C65D0(void *, f32 *, f32 *, f32, f32, f32);
extern f32 func_0038D200(f32 *);
extern f32 func_003C5340(s32, s32, s32);
extern s32 func_003C62D0();
extern void func_003C6530();
extern void func_003C4CB8();
extern f32 func_0038D488(f32, f32);
extern void func_0038DDE0(f32, f32);
extern void func_0038D2E0(void);

typedef struct { f32 x, y, z, w; } V4_3C0188;
typedef int Q_3C0188 __attribute__((mode(TI)));
s32 func_003C5948(O_3C0188 *obj, E_3C0188 *e, f32 *v, s32 mode, s32 idx) {
    u8 cc[2];
    f32 m30[4] __attribute__((aligned(16)));
    f32 m40[4] __attribute__((aligned(16)));
    f32 m50[4] __attribute__((aligned(16)));
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 ee;
    f32 f;
    f32 g;
    s32 k;
    s32 ok;
    f32 *t;

    t = obj->f68->f1C;
    if (idx != -1) {
        k = idx;
    }
    c = e->f24;
    d = e->f28;
    a = e->f1C;
    b = e->f20;
    g = e->f2C;
    if (t != 0) {
        e->f30 = *t;
        e->f34 = *t;
    }
    e->f14 = 0;
    ok = 1;
    switch (mode) {
    case 1:
    default:
        ok = 0;
        e->f7 = 0xFF;
        break;
    case 2:
        e->f7 = 0xFF;
        if (idx != -1) {
            func_003C6530(obj, idx, &a, &b, &c, &d, &ee, &f, &g, &e->f78);
            func_003C3CB0(obj, idx, e->f78, 3);
            obj->f44 = obj->f4C;
        } else if (func_003C62D0((void *)obj, 0, &k, &a, &b, &c, &d, &ee, &f, &g, &e->f78)) {
            func_003C3CB0(obj, k, e->f78, 3);
            obj->f44 = obj->f4C;
        } else if (!func_003C62D0((void *)obj, 1, &k, &a, &b, &c, &d, &ee, &f, &g, &e->f78)) {
            if (e->f11 != 0xFF) {
                a *= 0.5f;
                b *= 0.5f;
                ee = e->f6C;
                f = e->f6D;
                func_003C3CB0(obj, e->f11, e->f78, 3);
                obj->f44 = obj->f4C;
            } else {
                ok = 0;
            }
        }
        break;
    case 3:
        e->f7 = 0xFF;
        if (idx != -1) {
            func_003C6530(obj, idx, &a, &b, &c, &d, &ee, &f, &g, &e->f79);
            func_003C3CB0(obj, idx, e->f79, 3);
            obj->f44 = obj->f4C;
        } else if (func_003C62D0((void *)obj, 1, &k, &a, &b, &c, &d, &ee, &f, &g, &e->f79)) {
            func_003C3CB0(obj, k, e->f79, 3);
            obj->f44 = obj->f4C;
        } else if (func_003C62D0((void *)obj, 0, &k, &a, &b, &c, &d, &ee, &f, &g, &e->f79)) {
            func_003C3CB0(obj, k, e->f79, 3);
            obj->f44 = obj->f4C;
        } else if (e->f12 != 0xFF) {
            a *= 0.75f;
            b *= 0.75f;
            ee = e->f6E;
            f = e->f6F;
            func_003C3CB0(obj, e->f12, e->f79, 3);
            obj->f44 = obj->f4C;
        } else {
            ok = 0;
        }
        break;
    case 6:
        e->f7 = 0xFF;
        if (idx != -1) {
            func_003C6530(obj, idx, &a, &b, &c, &d, &ee, &f, &g, &cc[0]);
            func_003C3CB0(obj, k, 0, 3);
            obj->f44 = obj->f4C;
        } else if (func_003C62D0((void *)obj, 5, &k, &a, &b, &c, &d, &ee, &f, &g, &cc[0])) {
            func_003C3CB0(obj, k, 0, 3);
            obj->f44 = obj->f4C;
        } else {
            ok = 0;
        }
        break;
    case 4:
        e->f7 = 0xFF;
        e->f38 |= 1;
        obj->f98 = 0;
        obj->f34 &= 0xEFFF;
        if (idx != -1) {
            func_003C6530(obj, idx, &a, &b, &c, &d, &ee, &f, &g, &e->f7A);
            func_003C3CB0(obj, k, e->f7A, 3);
            obj->f44 = obj->f4C;
        } else if (func_003C62D0((void *)obj, 3, &k, &a, &b, &c, &d, &ee, &f, &g, &e->f7A)) {
            func_003C3CB0(obj, k, e->f7A, 3);
            obj->f44 = obj->f4C;
        } else if (e->f16 != 0xFF) {
            ee = e->f72;
            f = e->f73;
            func_003C3CB0(obj, e->f16, e->f7A, 3);
            obj->f44 = obj->f4C;
        } else {
            ok = 0;
        }
        break;
    case 5:
        e->f7 = 0xFF;
        e->f38 |= 2;
        obj->f98 = 0;
        obj->f34 &= 0xEFFF;
        if (idx != -1) {
            func_003C6530(obj, idx, &a, &b, &c, &d, &ee, &f, &g, &cc[1]);
            func_003C3CB0(obj, k, 0, 3);
            obj->f44 = obj->f4C;
        } else if (func_003C62D0((void *)obj, 4, &k, &a, &b, &c, &d, &ee, &f, &g, &cc[1])) {
            func_003C3CB0(obj, k, 0, 3);
            obj->f44 = obj->f4C;
        } else if (e->f17 != 0xFF) {
            a *= 1.5f;
            b *= 1.5f;
            ee = e->f72;
            f = e->f73;
            func_003C3CB0(obj, e->f17, 0, 3);
            obj->f44 = obj->f4C;
        } else {
            ok = 0;
        }
        e->f90 = 0.104719765f;
        e->f94 = 0.41887906f;
        break;
    }
    func_003C4CB8((s32)obj, (void *)e);
    if (ok) {
        if (mode != 1) {
            if (D_001D5BEC_003C5948 != 0) {
                f32 s = func_003C5340((s32)obj, (s32)v, 0);
                if (s < 1.0f) s = 1.0f;
                func_003C53D8_003C54D0((u8 *)obj + 0x10, m30, 0);
                func_0038D290((s32)m50, (s32)v, -1.0f);
                func_003C50D0(m50, &e->f64);
                {
                    f32 t = func_0038D190(m30, v);
                    func_0038D290((s32)m40, (s32)m30, t);
                }
                {
                    Q_3C0188 x, y;
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3C0188 *)v));
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3C0188 *)m40));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(*(V4_3C0188 *)v) : "j"(x));
                }
                if (func_0038D1D0((s32)v) < 1.0f) {
                    func_0038D290((s32)v, (s32)v, 1.0f);
                }
                func_0038D148(&e->f80, v, a);
                func_0038D290((s32)m40, (s32)m30, -b * s);
                {
                    Q_3C0188 x, y;
                    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3C0188 *)&e->f80));
                    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3C0188 *)m40));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                    __asm__("sqc2 %1, %0" : "=m"(*(V4_3C0188 *)&e->f80) : "j"(x));
                }
            } else {
                func_003C65D0(obj, v, v, 5.0f, 0.7853982f, 4.0f);
                if (func_0038D200(v) < 1.0f) {
                    ((void (*)(f32 *, f32 *, f32))func_0038D2E0)(v, v, 1.0f);
                }
                if (v[2] < 1.0f) {
                    v[2] = 1.0f;
                }
                e->f80 = v[0] * a;
                e->f84 = v[1] * a;
                e->f88 = v[2] * b;
                e->f64 = ((f32 (*)(f32, f32))func_0038DDE0)(func_0038D488(v[0], v[1]), 3.1415901f);
            }
            if (e->f76 != 0 && mode < 4) {
                e->f4C = 0.0f;
                e->f50 = 0.0f;
                e->f54 = -1.0f;
                e->f60 = -1.0f;
            } else {
                e->f54 = ee;
                e->f60 = f;
                e->f4C = c;
                e->f50 = d;
                e->f2C = g;
            }
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003C5948 */

/* localdecomp:start func_003C62D0 */
typedef struct { u8 key; u8 b1; u8 pad[2]; f32 f4, f8, fC, f10, f14, f18, f1C; } E3C;
typedef struct { u8 pad[0x14]; E3C *e; } P3C;
typedef struct { u8 pad[0xC]; u8 n; u8 pad2[0x3B]; P3C *arr[1]; } S3C;
typedef struct { u8 pad[0x24]; S3C *set; } O3C;
extern s32 func_00382868();
extern f32 func_003828E0(f32, f32);
s32 func_003C62D0(O3C *obj, s32 key, s32 *idx, f32 *o1, f32 *o2, f32 *o3, f32 *o4, f32 *o5, f32 *o6, f32 *o7, u8 *o8) {
    E3C *e;
    s32 cnt = 0;
    s32 r;
    s32 i;
    s32 j;
    for (j = 0; j < obj->set->n; j++) {
        if (obj->set->arr[j]->e) {
            if (obj->set->arr[j]->e->key == key) cnt++;
        }
    }
    if (cnt == 0) return 0;
    r = func_00382868(cnt);
    for (i = 0; i < obj->set->n; i++) {
        e = obj->set->arr[i]->e;
        if (e && e->key == key) {
            if (r != 0) {
                r--;
            } else {
                *o1 = e->f8 * 0.016666668f;
                *o2 = e->fC * 0.016666668f;
                *o3 = e->f10 * 0.00027777778f;
                *o4 = e->f14 * 0.00027777778f;
                *o7 = e->f4 * 0.00027777778f;
                *o5 = e->f18;
                *o6 = e->f1C;
                if (e->b1) *o8 = e->b1;
                *o1 = func_003828E0(*o1 * 0.87f, *o1 * 1.13f);
                *o2 = func_003828E0(*o2 * 0.85f, *o2 * 1.15f);
                *o3 = func_003828E0(*o3 * 0.85f, *o3 * 1.15f);
                *o7 = func_003828E0(*o7 * 0.9f, *o7 * 1.1f);
                *idx = i;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003C62D0 */

/* localdecomp:start func_003C6530 */
typedef struct { u8 pad[0x48]; void *a[1]; } S_3C0D70;
void func_003C6530(void *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6, f32 *arg7, f32 *arg_sp0, u8 *arg_sp8) {
    u8 temp_3_2;
    void *temp_3;
    S_3C0D70 *s;

    s = *(S_3C0D70 **)((u8 *)arg0 + 0x24);
    temp_3 = (*(void **)((u8 *)s->a[arg1] + 0x14));
    if (temp_3 != 0) {
        *arg2 = (*(f32 *)((u8 *)temp_3 + 8)) * 0.016666668f;
        *arg3 = (*(f32 *)((u8 *)temp_3 + 0xC)) * 0.016666668f;
        *arg4 = (*(f32 *)((u8 *)temp_3 + 0x10)) * 0.00027777778f;
        *arg5 = (*(f32 *)((u8 *)temp_3 + 0x14)) * 0.00027777778f;
        *arg_sp0 = (*(f32 *)((u8 *)temp_3 + 4)) * 0.00027777778f;
        *arg6 = (*(f32 *)((u8 *)temp_3 + 0x18));
        *arg7 = (*(f32 *)((u8 *)temp_3 + 0x1C));
        temp_3_2 = (*(u8 *)((u8 *)temp_3 + 1));
        if (temp_3_2 != 0) {
            *arg_sp8 = temp_3_2;
        }
    }
}
/* localdecomp:end func_003C6530 */
