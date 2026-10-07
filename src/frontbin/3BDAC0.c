#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern f32 func_003BE6A8(f32, f32, f32);
extern void (*D_001D9AC0[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void func_003BF2A0();
extern void func_003BF2A0(void *, void *);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_003BF360();
extern void func_003BE340(void);
extern void func_003BDC90(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_003BE340();
extern void func_003BDC90();
extern void func_003BDAC8();
extern int func_003BE3C0();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003BDAC0);

/* localdecomp:start func_003BDAC8 */
typedef struct { f32 x, y, z, w; } V4_3BDAC8;
typedef struct { f32 m[12]; V4_3BDAC8 v; } M_3BDAC8;
typedef int Q_3BDAC8 __attribute__((mode(TI)));
extern void func_003C4F30();
extern void func_003886E8(f32 *, void *, f32);
extern void func_00388E38();
extern void func_00388F08();
void func_003BDAC8(u8 *a, s32 n, s32 c, u8 *out) {
    f32 buf[16];
    f32 scale;
    u8 *p, *q;
    s32 i;
    M_3BDAC8 *o;
    Q_3BDAC8 x, y;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_00388E38(buf, a + 0xC0);
    func_003C4F30(a, n, c, out);
    o = (M_3BDAC8 *)out;
    for (i = 0; i < n; i++) {
        func_00388F08(&o[i], buf, &o[i]);
        func_003886E8((f32 *)&o[i].v, &o[i].v, scale);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BDAC8 *)&o[i].v));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BDAC8 *)(a + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BDAC8 *)&o[i].v) : "j"(x));
    }

}
/* localdecomp:end func_003BDAC8 */

/* localdecomp:start func_003BDBA0 */
extern int D_001DA0D0_003BDBA0;
__asm__(".extern D_001DA0D0_003BDBA0, 16");
extern int D_001DA510_003BDBA0;
__asm__(".extern D_001DA510_003BDBA0, 16");
extern s32 D_001D4BB0_003BDBA0;
__asm__(".extern D_001D4BB0_003BDBA0, 4");
extern void func_003C5AE0();
extern void func_003A40C8();
void func_003BDBA0(void) {
    u32 *s0, *t;
    u32 c;
    c = 0x20000000;
    t = ((u32 *)D_001DA0D0_003BDBA0);
    s0 = t;
    t += 4;
    D_001DA0D0_003BDBA0 = (int)t;
    ((u32 *)D_001DA510_003BDBA0)[0] = c;
    ((u32 *)D_001DA510_003BDBA0)[1] = D_001DA0D0_003BDBA0;
    ((u32 *)D_001DA510_003BDBA0)[2] = 0;
    ((u32 *)D_001DA510_003BDBA0)[3] = 0;
    func_003C5AE0(D_001D4BB0_003BDBA0);
    func_003A40C8();
    ((u32 *)D_001DA0D0_003BDBA0)[0] = c;
    ((u32 *)D_001DA0D0_003BDBA0)[1] = D_001DA510_003BDBA0 + 0x10;
    ((u32 *)D_001DA0D0_003BDBA0)[2] = 0;
    ((u32 *)D_001DA0D0_003BDBA0)[3] = 0;
    D_001DA0D0_003BDBA0 = (int)(((u32 *)D_001DA0D0_003BDBA0) + 4);
    s0[0] = c;
    s0[1] = D_001DA0D0_003BDBA0;
    s0[2] = 0;
    s0[3] = 0;
}
/* localdecomp:end func_003BDBA0 */

/* localdecomp:start func_003BDC90 */
typedef struct { s16 a; s16 b; } T_BDC90;
typedef struct { u8 c[0xC]; s32 fC; } E_BDC90;
typedef struct { u8 p0[0x20]; E_BDC90 *f20; } O_BDC90;
extern s32 D_002DA070[];
extern O_BDC90 *D_002D67C0[];
extern T_BDC90 D_002D98B0[];
void func_003BDC90(void) {
    s32 *p;
    E_BDC90 *e;
    u8 *c;
    u8 *o;
    T_BDC90 *t;
    for (p = D_002DA070; *p >= 0; p++) {
        e = D_002D67C0[*p]->f20;
        for (;;) {
            o = (u8 *)(e->fC & 0x7FFFFFFF);
            c = e->c;
            if (*c != 0xFF) {
                do {
                    t = &D_002D98B0[*c];
                    if (t->a != 0) { *(u32 *)(o + 0x30) = (*(u32 *)(o + 0x30) & 0xFFFFC000) | t->a; }
                    if (t->b != 0) { *(u32 *)(o + 0x40) = (*(u32 *)(o + 0x40) & 0xFFFFC000) | t->b; }
                    c++;
                    o += 0x40;
                } while (*c != 0xFF);
            }
            if (e->fC < 0) break;
            e++;
        }
    }
}
/* localdecomp:end func_003BDC90 */

/* localdecomp:start func_003BDD68 */
extern int D_001DA564_003BDD68;
__asm__(".extern D_001DA564_003BDD68, 16");
extern s32 D_001DA560;
__asm__(".extern D_001DA560, 16");
extern s32 D_001D9DB4_003BDD68;
__asm__(".extern D_001D9DB4_003BDD68, 4");
extern s32 D_001D5BA8_003BDD68;
__asm__(".extern D_001D5BA8_003BDD68, 16");
extern void func_003CC198();
extern void func_003CBE40();
void func_003BDD68(void) {
    u32 *s0, *t;
    u32 c;
    if (D_001DA560 == 0) {
        ((u32 *)D_001DA564_003BDD68)[0] = 0x10000000;
        ((u32 *)D_001DA564_003BDD68)[1] = 0;
        ((u32 *)D_001DA564_003BDD68)[2] = 0;
        ((u32 *)D_001DA564_003BDD68)[3] = 0;
    } else {
        c = 0x20000000;
        t = ((u32 *)D_001DA0D0_003BDBA0);
        s0 = t;
        t += 4;
        D_001DA0D0_003BDBA0 = (int)t;
        ((u32 *)D_001DA564_003BDD68)[0] = c;
        ((u32 *)D_001DA564_003BDD68)[1] = D_001DA0D0_003BDBA0;
        ((u32 *)D_001DA564_003BDD68)[2] = 0;
        ((u32 *)D_001DA564_003BDD68)[3] = 0;
        func_003CC198(D_001D9DB4_003BDD68, D_001D5BA8_003BDD68);
        func_003CBE40(D_001D9DB4_003BDD68);
        ((u32 *)D_001DA0D0_003BDBA0)[0] = c;
        ((u32 *)D_001DA0D0_003BDBA0)[1] = D_001DA564_003BDD68 + 0x10;
        ((u32 *)D_001DA0D0_003BDBA0)[2] = 0;
        ((u32 *)D_001DA0D0_003BDBA0)[3] = 0;
        D_001DA0D0_003BDBA0 = (int)(((u32 *)D_001DA0D0_003BDBA0) + 4);
        s0[0] = c;
        s0[1] = D_001DA0D0_003BDBA0;
        s0[2] = 0;
        s0[3] = 0;
    }
}
/* localdecomp:end func_003BDD68 */

/* localdecomp:start func_003BDEA8 */
typedef struct { u8 pB_[0xB]; u8 bB; u8 pC[0x14]; s32 f20; } T_3BDEA8;
typedef struct { u8 p0[0x24]; T_3BDEA8 *f24; } O_3BDEA8;
extern u8 *D_001DA5B0;
extern u8 D_002F8220[];
extern u8 D_0037C170[];
extern u8 D_001D7830[];
extern void func_003885F0();
void func_003BDEA8(void) {
    u32 *pkt;
    u8 *e;
    if (D_001DA5B0 == D_002F8220) return;
    pkt = (u32 *)D_001DA0D0_003BDBA0;
    D_001DA0D0_003BDBA0 = (int)(pkt + 4);
    for (e = D_002F8220; e < D_001DA5B0; e += 8) {
        u32 *a = *(u32 **)e;
        u32 b = *(u32 *)(e + 4);
        O_3BDEA8 *o;
        T_3BDEA8 *t;
        s32 lo, hi, idx;
        s32 base;
        s32 j;
        a[0] = 0x20000000;
        idx = b & 0xF;
        o = (O_3BDEA8 *)(b & ~0xF);
        a[1] = D_001DA0D0_003BDBA0;
        a[3] = 0x11000000;
        t = o->f24;
        hi = t->bB >> 4;
        lo = t->bB & 0xF;
        base = t->f20 - ((lo * hi) << 10) - 0x10;
        for (j = 0; j < hi; j++) {
            s16 h = ((s16 *)base)[j];
            func_003885F0(D_001DA0D0_003BDBA0, D_0037C170, 0x70);
            ((s16 *)D_001DA0D0_003BDBA0)[0x12] = h;
            ((u32 *)D_001DA0D0_003BDBA0)[0x19] = base + (idx << 10) + 0x10 + ((j * lo) << 10);
            D_001DA0D0_003BDBA0 = D_001DA0D0_003BDBA0 + 0x70;
        }
        ((u32 *)D_001DA0D0_003BDBA0)[0] = 0x30000003;
        ((u32 *)D_001DA0D0_003BDBA0)[1] = (u32)D_001D7830;
        ((u32 *)D_001DA0D0_003BDBA0)[2] = 0;
        ((u32 *)D_001DA0D0_003BDBA0)[3] = 0x50000003;
        D_001DA0D0_003BDBA0 = D_001DA0D0_003BDBA0 + 0x10;
        ((u32 *)D_001DA0D0_003BDBA0)[0] = 0x20000000;
        ((u32 *)D_001DA0D0_003BDBA0)[1] = (u32)(a + 4);
        ((u32 *)D_001DA0D0_003BDBA0)[2] = 0;
        ((u32 *)D_001DA0D0_003BDBA0)[3] = 0;
        D_001DA0D0_003BDBA0 = D_001DA0D0_003BDBA0 + 0x10;
    }
    pkt[0] = 0x20000000;
    pkt[1] = D_001DA0D0_003BDBA0;
    pkt[2] = 0;
    pkt[3] = 0;
}
/* localdecomp:end func_003BDEA8 */

/* localdecomp:start func_003BE0D0 */
extern u8 D_0037C2A0[];
extern s32 D_001D9DB0;
extern s32 D_001D9DB8;
extern void func_11F0A0(s32);
extern void func_003885F0(u32 *, s32, s32);
extern void func_003C5D90();
void func_003BE0D0(void) {
    func_11F0A0(0);
    func_003885F0((u32 *)0x70003800, (s32)D_0037C2A0, 0x800);
    func_003C5D90(D_001D9DB0, D_001D9DB8);
}
/* localdecomp:end func_003BE0D0 */

/* localdecomp:start func_003BE118 */
extern void func_00388440();
 
void func_003BE118(void) {
    func_00388440(0x70003A00, 0x40000000, 0x3C0);
}
/* localdecomp:end func_003BE118 */

/* localdecomp:start func_003BE140 */
extern void func_003885F0();
extern u8 D_002D6400[];
 
void func_003BE140(void) {
    func_003885F0((s32)D_002D6400, 0x70003A00, 0x3C0);
}
/* localdecomp:end func_003BE140 */

/* localdecomp:start func_003BE170 */
extern void func_003885F0();
 extern u8 D_002D6400[];

void func_003BE170(void) {
    func_003885F0(0x70003A00, (s32)D_002D6400, 0x3C0);
}
/* localdecomp:end func_003BE170 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BE1A0);

/* localdecomp:start func_003BE260 */
extern void *D_001DA518_003BE260;
extern void func_003A3EF0(s32, unsigned long);
extern void func_11F0A0(s32);
extern void func_003BE170(void);
extern void *func_003C5E70(s32, void *, s32, s32);
extern void func_003BE140(void);
void func_003BE260(s32 a0, s32 a1) {
    func_003A3EF0(0x47, 0x5360B);
    func_11F0A0(0);
    func_003BE170();
    D_001DA518_003BE260 = func_003C5E70(a0, D_001DA518_003BE260, a1, 0);
    func_003BE140();
    D_001DA518_003BE260 = (u8 *)D_001DA518_003BE260 - 0x10;
}
/* localdecomp:end func_003BE260 */

/* localdecomp:start func_003BE2E0 */
extern void func_003BDBA0(void);
extern void func_003BE0D0(void);
extern void func_003BDD68(void);
extern void func_003BDEA8(void);
extern s32 D_001DA564[];
extern u8 *D_001DA5B0;
extern u8 D_002F8220[];
void func_003BE2E0(void) {
    func_003BDBA0();
    func_003BE0D0();
    if (D_001DA564[0] != 0) {
        func_003BDD68();
    }
    if (D_001DA5B0 > D_002F8220) {
        func_003BDEA8();
    }
}
/* localdecomp:end func_003BE2E0 */

/* localdecomp:start func_003BE340 */
extern void func_003BE118();
extern void func_003BE1A0();
extern void func_003BE2E0();
s32 func_003C5E70_003BE340(s32, s32, s32, s32);      /* extern */
extern s32 D_001DA518;
extern s32 D_001DA51C;
extern s32 D_001DA554;

void func_003BE340(void) {
    s32 var_a3;

    func_003BE1A0();
    func_003BE118();
    var_a3 = 1;
    if (D_001DA554 != 0) {
        D_001DA554 = 0;
        var_a3 = 3;
    }
    D_001DA518 = func_003C5E70_003BE340(D_001DA51C, D_001DA518, -1, var_a3);
    func_003BE2E0();
}
/* localdecomp:end func_003BE340 */

LINKER_REMNANT("asm/remnants", func_003BE3A0);

/* localdecomp:start func_003BE3C0 */
extern int D_001DA51C;
extern int D_001DA524;
int func_003BE3C0(void) {
    unsigned char *current = (unsigned char *)(*(volatile int *)&D_001DA51C);
    unsigned char *end = (unsigned char *)(*(volatile int *)&D_001DA524);
    int result = (int)end;

    if (current != end) {
        do {
            result = *(int *)(current + 0x24);
            current += 0x100;
        } while (current != end);
    }
    return result;
}
/* localdecomp:end func_003BE3C0 */

LINKER_REMNANT("asm/remnants", func_003BE400);

/* localdecomp:start func_003BE418 */
typedef struct { u8 p10[0x10]; u8 n; u8 f11; } T_3BE418;
typedef struct { u8 p0[0x48]; T_3BE418 *e[1]; } Q_3BE418;
typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; f32 f48; f32 f4C; u8 p50[8]; f32 *f58; u8 p5c[4]; u8 f60; u8 p61[0xB]; u8 f6C;
} S_3BE418;
extern void func_003BD490();
void func_003BE418(S_3BE418 *p, s32 idx, s32 lim) {
    s32 v;
    s32 n;
    v = lim;
    if (!(lim < p->f24->e[idx]->n)) v = p->f24->e[idx]->n - 1;
    p->f42 = idx;
    p->f40 = v;
    p->f41 = v + 1;
    n = p->f24->e[idx]->n - 1;
    if (n < p->f41) p->f41 = n;
    p->f43 = idx;
    p->f44 = 0;
    if (!(p->f41 < p->f24->e[idx]->n)) p->f41 = 0;
    func_003BD490(p);
    p->f4C = *p->f58;
    p->f60 &= 0xFD;
    p->f6C = p->f24->e[idx]->f11;
}
/* localdecomp:end func_003BE418 */

/* localdecomp:start func_003BE4F0 */
typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; f32 f44; f32 f48; f32 f4C; void *f50; void *f54; u8 p58[8]; u8 f60; u8 p61[0xB]; u8 f6C;
    u8 p6D[0x13]; u128_t f80; u8 p90[0x19]; u8 fA9;
} S_3BE4F0;
extern u128_t D_002D6180[];
extern void func_003C1950_003BE4F0();
extern s32 func_003BD810();
extern void func_003C35A8();
void func_003BE4F0(S_3BE4F0 *p, s32 idx, s32 lim, s32 dur) {
    s32 v;
    s32 r;
    s32 n;
    n = p->f24->e[idx]->n;
    if (lim >= n) lim = n - 1;
    if (dur <= 0) {
        func_003BE418(p, idx, lim);
        return;
    }
    if ((u32)(lim - 1) < 0xB) func_003C1950_003BE4F0(p, idx, (u16)lim);
    if (0.025f < p->f44 || p->f50 != 0 || p->f54 != 0) {
        r = func_003BD810(p);
        if (r >= 0) {
            func_003C35A8(p, r | 0x300);
            D_002D6180[r] = p->f80;
            if (p->f42 != 0xFF) p->fA9 = p->f42;
            p->f42 = 0xFF;
            p->f40 = r;
        }
    }
    p->f41 = lim;
    p->f43 = idx;
    func_003BD490(p);
    p->f60 &= 0xFD;
    p->f48 = 1.0f;
    p->f44 = 0;
    p->f4C = 1.0f / (f32)dur;
    p->f6C = p->f24->e[idx]->f11;
}
/* localdecomp:end func_003BE4F0 */
TEXT_PADDING(4);

LINKER_REMNANT("asm/remnants", func_003BE688);

/* localdecomp:start func_003BE6A8 */
extern f32 func_00388960(f32);
f32 func_003BE6A8(f32 a, f32 b, f32 t) {
    if (t == 0.0f) return a;
    if (t == 1.0f) return b;
    return a + (b - a) * ((1.0f - func_00388960(t * 3.14159274f)) * 0.5f);
}
/* localdecomp:end func_003BE6A8 */

LINKER_REMNANT("asm/remnants", func_003BE740);

/* localdecomp:start func_003BE7F0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
extern V_3BE7F0 D_002276E0;
s32 func_003CE740(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);
f32 func_003BE7F0(V_3BE7F0 *p, s32 flags, s32 c, f32 dz) {
    V_3BE7F0 a = *p;
    V_3BE7F0 b = *p;
    a.z = 0.01f;
    b.z += dz;
    if (func_003CE740(&b, &a, flags | 2, c, 0)) return D_002276E0.z;
    return 0.0f;
}
/* localdecomp:end func_003BE7F0 */

/* localdecomp:start func_003BE860 */
typedef int Q_3BE860 __attribute__((mode(TI)));
extern V_3BE7F0 D_001A4C90;
extern void func_003BFC18_003BE860();
s32 func_003BE860(V_3BE7F0 *out, void *obj, s32 flags, s32 c, f32 scale) {
    V_3BE7F0 a, b, d;
    Q_3BE860 x, y;
    func_003BFC18_003BE860(obj, &d, 1);
    a = D_001A4C90;
    func_003886E8((f32 *)&b, &d, scale);

    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_3BE7F0 *)obj));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(x));
    if (func_003CE740(&b, &a, flags | 2, c, 0)) {
        *out = D_002276E0;
        return 1;
    }
    *out = a;
    return 0;
}
/* localdecomp:end func_003BE860 */

LINKER_REMNANT("asm/remnants", func_003BE948);

/* localdecomp:start func_003BE988 */
extern s32 D_001D9A40;
extern s32 D_001D9A28;
extern f32 D_001D9A38;
extern f32 D_001D9A3C;
extern f32 D_001D9A30[];
extern s32 func_0037DCF8();
extern f32 func_00388800();
f32 func_003BE988(f32 *p, void *out) {
    f32 t;
    if (D_001D9A40 != 0) {
        t = p[2];
        if (((s32 (*)(f32 *, f32, f32, f32))func_0037DCF8)(&t, p[0], p[1], p[2]) != 0) return t;
    }
    if (D_001D9A28 != 0) {
        if (__builtin_fabsf(p[2] - *(volatile f32 *)&D_001D9A38) < 0.5f && func_00388800(p, D_001D9A30) < D_001D9A3C) {
            if (out != 0) {
                __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
            }
            return *(volatile f32 *)&D_001D9A38;
        }
    }
    if (out != 0) {
        __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
    }
    return p[2];
}
/* localdecomp:end func_003BE988 */

/* localdecomp:start func_003BEA80 */
extern s32 func_00388F50();
extern void func_00389018(void *, s32, f32);
void func_003BEA80(s32 *arg0, void *arg1) {
    s32 spv[12];

    func_00389018(&spv[8], 0, (*(f32 *)((u8 *)arg1 + 0)));
    func_00389018(&spv[4], 1, (*(f32 *)((u8 *)arg1 + 4)));
    func_00389018(spv, 2, (*(f32 *)((u8 *)arg1 + 8)));
    ((s32 (*)())func_00388F50)(arg0, &spv[8], &spv[4]);
    ((s32 (*)())func_00388F50)(arg0, arg0, spv);
}
/* localdecomp:end func_003BEA80 */

LINKER_REMNANT("asm/remnants", func_003BEB18);

/* localdecomp:start func_003BEB48 */
f32 func_003BEB48(f32 a, f32 b, f32 t) {
    return a + (b - a) * t;
}
/* localdecomp:end func_003BEB48 */

/* localdecomp:start func_003BEB58 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) Vector_003BEB58;
extern f32 func_003BEB48(f32, f32, f32);
void func_003BEB58(Vector_003BEB58 *output, Vector_003BEB58 first, Vector_003BEB58 second, f32 fraction) {
    output->x = func_003BEB48(first.x, second.x, fraction);
    output->y = func_003BEB48(first.y, second.y, fraction);
    output->z = func_003BEB48(first.z, second.z, fraction);
    output->w = func_003BEB48(first.w, second.w, fraction);
}
/* localdecomp:end func_003BEB58 */

LINKER_REMNANT("asm/remnants", func_003BEBF0);

/* localdecomp:start func_003BEBF8 */
f32 func_003BEBF8(f32 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f1;
    f32 var_f0;
    f32 var_f13;

    var_f13 = fparg1;
    var_f0 = fparg0 - *arg0;
    if ((var_f13 < var_f0) || (var_f13 = -var_f13, (var_f0 < var_f13))) {
        var_f0 = var_f13;
    }
    temp_f1 = *arg0 + var_f0;
    *arg0 = temp_f1;
    { f32 r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(fparg0 - temp_f1)); return r; }
}
/* localdecomp:end func_003BEBF8 */

LINKER_REMNANT("asm/remnants", func_003BEC48);

/* localdecomp:start func_003BEC60 */
f32 func_003BEC60(f32 *pos, f32 *vel, f32 target, f32 maxv, f32 acc, f32 lim) {
    f32 d = target - *pos;
    f32 v;
    if (*vel == 0.0f && d == 0.0f) return 0.0f;
    v = *vel;
    if (0.0f <= v * d) {
        f32 stop = v * v / acc * 0.5f;
        if (__builtin_fabsf(d) < stop) {
            if (stop < __builtin_fabsf(d) + __builtin_fabsf(v)) {
                v = acc;
                func_003BEBF8(vel, 0.0f, v);
            } else {
                v = acc * 1.1f;
                func_003BEBF8(vel, 0.0f, v);
            }
        } else {
            f32 s;
            __asm__("sqrt.s %0, %1" : "=f"(s) : "f"((acc + acc) * d));
            if (lim < s) s = lim;
            v = maxv;
            if (d < 0.0f) {
                func_003BEBF8(vel, -s, v);
            } else {
                func_003BEBF8(vel, s, v);
            }
        }
        if (__builtin_fabsf(*vel) < __builtin_fabsf(d)) {
            *pos = *pos + *vel;
            return *vel;
        }
        *pos = target;
        return d;
    } else {
        if (v < 0.0f) v = v + acc;
        else v = v - acc;
        *vel = v;
        *pos = *pos + v;
        return *vel;
    }
}
/* localdecomp:end func_003BEC60 */

LINKER_REMNANT("asm/remnants", func_003BEE08);

/* localdecomp:start func_003BEE20 */
void func_003BEE20(f32 *vel, f32 d, f32 maxv, f32 acc, f32 lim) {
    f32 v;
    if (d == 0.0f && *vel == 0.0f) return;
    if (0.0f <= *vel * d && d != 0.0f) {
        f32 stop;
        stop = *vel * *vel / acc * 0.5f;
        v = *vel;
        if (__builtin_fabsf(d) < stop) {
            if (stop < __builtin_fabsf(d) + __builtin_fabsf(v)) {
                v = acc;
                func_003BEBF8(vel, 0.0f, v);
            } else {
                v = acc * 1.1f;
                func_003BEBF8(vel, 0.0f, v);
            }
        } else {
            f32 s;
            __asm__("sqrt.s %0, %1" : "=f"(s) : "f"((acc + acc) * d));
            if (lim < s) s = lim;
            v = maxv;
            if (d < 0.0f) {
                func_003BEBF8(vel, -s, v);
            } else {
                func_003BEBF8(vel, s, v);
            }
        }
        if (__builtin_fabsf(*vel) < __builtin_fabsf(d)) return;
        *vel = d;
    } else {
        v = *vel;
        if (v < 0.0f) v = v + acc;
        else v = v - acc;
        *vel = v;
        if (d < 0.0f && v < d) *vel = d;
        else if (0.0f < d && d < *vel) *vel = d;
    }
}
/* localdecomp:end func_003BEE20 */
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_003BEFF8);

/* localdecomp:start func_003BF058 */
typedef struct { s32 v[3]; } N3_3BF058;
extern N3_3BF058 D_001D9148;
void func_003BF058(void *qv, void *mv) {
    f32 *q = (f32 *)qv;
    f32 *m = (f32 *)mv;
    N3_3BF058 nxt;
    f32 mm[3][3];
    f32 tr, s;
    s32 i, j, k;
    nxt = D_001D9148;
    tr = m[0] + m[5] + m[10];
    if (tr > 0.0f) {
        __asm__("sqrt.s %0, %1" : "=f"(s) : "f"(tr + 1.0f));
        q[3] = s * 0.5f;
        s = 0.5f / s;
        q[0] = (m[9] - m[6]) * s;
        q[1] = (m[2] - m[8]) * s;
        q[2] = (m[4] - m[1]) * s;
    } else {
        mm[0][1] = m[1];
        mm[0][2] = m[2];
        mm[1][0] = m[4];
        mm[1][2] = m[6];
        mm[2][0] = m[8];
        mm[2][1] = m[9];
        mm[0][0] = m[0];
        mm[1][1] = m[5];
        mm[2][2] = m[10];
        i = 0;
        if (mm[0][0] < mm[1][1]) i = 1;
        if (mm[i][i] < mm[2][2]) i = 2;
        j = nxt.v[i];
        k = nxt.v[j];
        __asm__("sqrt.s %0, %1" : "=f"(s) : "f"(mm[i][i] - (mm[j][j] + mm[k][k]) + 1.0f));
        q[i] = s * 0.5f;
        if (s != 0.0f) s = 0.5f / s;
        q[3] = (mm[k][j] - mm[j][k]) * s;
        q[j] = (mm[j][i] + mm[i][j]) * s;
        q[k] = (mm[k][i] + mm[i][k]) * s;
    }
}
/* localdecomp:end func_003BF058 */

/* localdecomp:start func_003BF2A0 */
extern void func_00388E38(void *, void *);
extern void func_003BF058(void *, void *);
extern void func_00388E58(void *, void *);
void func_003BF2A0(void *a, void *b) {
    u8 m[0x40];
    func_00388E38(m, b);
    func_003BF058(a, m);
    func_00388E58(b, m);
}
/* localdecomp:end func_003BF2A0 */

LINKER_REMNANT("asm/remnants", func_003BF2F0);

/* localdecomp:start func_003BF2F8 */
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern void func_003886E8(f32 *, void *, f32);
void func_003BF2F8(f32 *q, void *axis, f32 angle) {
    f32 h = angle * 0.5f;
    func_003886E8(q, axis, func_00388978(h));
    q[3] = func_00388960(h);
}
/* localdecomp:end func_003BF2F8 */

/* localdecomp:start func_003BF360 */
extern f32 func_003887A0(f32 *);
extern f32 func_00388A28(f32, f32);
void func_003BF360(f32 *p, f32 *out) {
    f32 a, b, c, s, x, y, z, r;
    out[1] = func_00388A28(func_003887A0(p), -p[2]);
    out[2] = func_00388A28(p[0], p[1]);
    if (__builtin_fabsf(out[2]) > 1e-5f) {
        c = func_00388960(-out[2]);
        s = func_00388978(-out[2]);
        x = c * p[4] - s * p[5];
        y = s * p[4] + c * p[5];
    } else {
        x = p[4];
        y = p[5];
    }
    if (__builtin_fabsf(out[1]) > 1e-5f) {
        c = func_00388960(-out[1]);
        s = func_00388978(-out[1]);
        z = -s * x + c * p[6];
        x = c * x + s * p[6];
    } else {
        z = p[6];
    }
    {
        f32 q;
        __asm__("sqrt.s %0, %1" : "=f"(q) : "f"(x * x + y * y));
        r = func_00388A28(q, z);
    }
    out[0] = r;
    if (y < 0.0f) {
        if (r < 0.0f) out[0] = -3.14159274f - r;
        else out[0] = 3.14159274f - r;
    }
}
/* localdecomp:end func_003BF360 */

/* localdecomp:start func_003BF4F8 */
extern void func_003C1A60(s32, s32 *, s32 *, s32 *);
typedef struct { s16 x0; s16 x2; u8 x4, x5, x6; u8 p7[5]; u16 xC; s16 xE; } S_BF;
void func_003BF4F8(s32 a0, S_BF *a1) {
    s32 r, g, b;
    s32 v = a1->x0;
    if (v != 0 && a1->x2 == 0) {
        return;
    }
    a1->x2 = 0;
    a1->x0 = a1->xC;
    if (v != 0) {
        a1->x0 = (f32)(s16)a1->xC * ((f32)v / (f32)a1->xE);
        if (a1->x0 <= 0) {
            a1->x0 = 1;
        }
    } else {
        func_003C1A60(a0, &r, &g, &b);
        a1->x4 = r;
        a1->x5 = g;
        a1->x6 = b;
    }
}
/* localdecomp:end func_003BF4F8 */

LINKER_REMNANT("asm/remnants", func_003BF5C0);
