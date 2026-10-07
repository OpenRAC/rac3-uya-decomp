#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern f32 func_003C3E68(f32, f32, f32);
extern void (*D_001D9AC0[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void func_003C4A60();
extern void func_003C4A60(void *, void *);
extern f32 func_003C43B8(f32 *, f32, f32);
extern void func_003C4B20();
extern f32 func_003C4308(f32, f32, f32);
extern void func_003C3B00(void);
extern void func_003C3450(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_003C3B00();
extern void func_003C3450();
extern void func_003C3288();
extern int func_003C3B80();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C3280);

/* localdecomp:start func_003C3288 */
typedef struct { f32 x, y, z, w; } V4_3BDAC8;
typedef struct { f32 m[12]; V4_3BDAC8 v; } M_3BDAC8;
typedef int Q_3BDAC8 __attribute__((mode(TI)));
extern void func_003CA6F0();
extern void func_0038D148(f32 *, void *, f32);
extern void func_0038D898();
extern void func_0038D968();
void func_003C3288(u8 *a, s32 n, s32 c, u8 *out) {
    f32 buf[16];
    f32 scale;
    u8 *p, *q;
    s32 i;
    M_3BDAC8 *o;
    Q_3BDAC8 x, y;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_0038D898(buf, a + 0xC0);
    func_003CA6F0(a, n, c, out);
    o = (M_3BDAC8 *)out;
    for (i = 0; i < n; i++) {
        func_0038D968(&o[i], buf, &o[i]);
        func_0038D148((f32 *)&o[i].v, &o[i].v, scale);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BDAC8 *)&o[i].v));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BDAC8 *)(a + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BDAC8 *)&o[i].v) : "j"(x));
    }

}
/* localdecomp:end func_003C3288 */

/* localdecomp:start func_003C3360 */
extern int D_001DA0D0_003C3360;
__asm__(".extern D_001DA0D0_003C3360, 16");
extern int D_001DA510_003C3360;
__asm__(".extern D_001DA510_003C3360, 16");
extern s32 D_001D4BB0_003C3360;
__asm__(".extern D_001D4BB0_003C3360, 4");
extern void func_003CB2A0();
extern void func_003A9888();
void func_003C3360(void) {
    u32 *s0, *t;
    u32 c;
    c = 0x20000000;
    t = ((u32 *)D_001DA0D0_003C3360);
    s0 = t;
    t += 4;
    D_001DA0D0_003C3360 = (int)t;
    ((u32 *)D_001DA510_003C3360)[0] = c;
    ((u32 *)D_001DA510_003C3360)[1] = D_001DA0D0_003C3360;
    ((u32 *)D_001DA510_003C3360)[2] = 0;
    ((u32 *)D_001DA510_003C3360)[3] = 0;
    func_003CB2A0(D_001D4BB0_003C3360);
    func_003A9888();
    ((u32 *)D_001DA0D0_003C3360)[0] = c;
    ((u32 *)D_001DA0D0_003C3360)[1] = D_001DA510_003C3360 + 0x10;
    ((u32 *)D_001DA0D0_003C3360)[2] = 0;
    ((u32 *)D_001DA0D0_003C3360)[3] = 0;
    D_001DA0D0_003C3360 = (int)(((u32 *)D_001DA0D0_003C3360) + 4);
    s0[0] = c;
    s0[1] = D_001DA0D0_003C3360;
    s0[2] = 0;
    s0[3] = 0;
}
/* localdecomp:end func_003C3360 */

/* localdecomp:start func_003C3450 */
typedef struct { s16 a; s16 b; } T_BDC90;
typedef struct { u8 c[0xC]; s32 fC; } E_BDC90;
typedef struct { u8 p0[0x20]; E_BDC90 *f20; } O_BDC90;
extern s32 D_002DE070[];
extern O_BDC90 *D_002DA7C0[];
extern T_BDC90 D_002DD8B0[];
void func_003C3450(void) {
    s32 *p;
    E_BDC90 *e;
    u8 *c;
    u8 *o;
    T_BDC90 *t;
    for (p = D_002DE070; *p >= 0; p++) {
        e = D_002DA7C0[*p]->f20;
        for (;;) {
            o = (u8 *)(e->fC & 0x7FFFFFFF);
            c = e->c;
            if (*c != 0xFF) {
                do {
                    t = &D_002DD8B0[*c];
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
/* localdecomp:end func_003C3450 */

/* localdecomp:start func_003C3528 */
extern int D_001DA564_003C3528;
__asm__(".extern D_001DA564_003C3528, 16");
extern s32 D_001DA560;
__asm__(".extern D_001DA560, 16");
extern s32 D_001D9DB4_003C3528;
__asm__(".extern D_001D9DB4_003C3528, 4");
extern s32 D_001D5BA8_003C3528;
__asm__(".extern D_001D5BA8_003C3528, 16");
extern void func_003D1958();
extern void func_003D1600();
void func_003C3528(void) {
    u32 *s0, *t;
    u32 c;
    if (D_001DA560 == 0) {
        ((u32 *)D_001DA564_003C3528)[0] = 0x10000000;
        ((u32 *)D_001DA564_003C3528)[1] = 0;
        ((u32 *)D_001DA564_003C3528)[2] = 0;
        ((u32 *)D_001DA564_003C3528)[3] = 0;
    } else {
        c = 0x20000000;
        t = ((u32 *)D_001DA0D0_003C3360);
        s0 = t;
        t += 4;
        D_001DA0D0_003C3360 = (int)t;
        ((u32 *)D_001DA564_003C3528)[0] = c;
        ((u32 *)D_001DA564_003C3528)[1] = D_001DA0D0_003C3360;
        ((u32 *)D_001DA564_003C3528)[2] = 0;
        ((u32 *)D_001DA564_003C3528)[3] = 0;
        func_003D1958(D_001D9DB4_003C3528, D_001D5BA8_003C3528);
        func_003D1600(D_001D9DB4_003C3528);
        ((u32 *)D_001DA0D0_003C3360)[0] = c;
        ((u32 *)D_001DA0D0_003C3360)[1] = D_001DA564_003C3528 + 0x10;
        ((u32 *)D_001DA0D0_003C3360)[2] = 0;
        ((u32 *)D_001DA0D0_003C3360)[3] = 0;
        D_001DA0D0_003C3360 = (int)(((u32 *)D_001DA0D0_003C3360) + 4);
        s0[0] = c;
        s0[1] = D_001DA0D0_003C3360;
        s0[2] = 0;
        s0[3] = 0;
    }
}
/* localdecomp:end func_003C3528 */

/* localdecomp:start func_003C3668 */
typedef struct { u8 pB_[0xB]; u8 bB; u8 pC[0x14]; s32 f20; } T_3BDEA8;
typedef struct { u8 p0[0x24]; T_3BDEA8 *f24; } O_3BDEA8;
extern u8 *D_001DA5B0;
extern u8 D_002FC220[];
extern u8 D_003801B0[];
extern u8 D_001D7830[];
extern void func_0038D050();
void func_003C3668(void) {
    u32 *pkt;
    u8 *e;
    if (D_001DA5B0 == D_002FC220) return;
    pkt = (u32 *)D_001DA0D0_003C3360;
    D_001DA0D0_003C3360 = (int)(pkt + 4);
    for (e = D_002FC220; e < D_001DA5B0; e += 8) {
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
        a[1] = D_001DA0D0_003C3360;
        a[3] = 0x11000000;
        t = o->f24;
        hi = t->bB >> 4;
        lo = t->bB & 0xF;
        base = t->f20 - ((lo * hi) << 10) - 0x10;
        for (j = 0; j < hi; j++) {
            s16 h = ((s16 *)base)[j];
            func_0038D050(D_001DA0D0_003C3360, D_003801B0, 0x70);
            ((s16 *)D_001DA0D0_003C3360)[0x12] = h;
            ((u32 *)D_001DA0D0_003C3360)[0x19] = base + (idx << 10) + 0x10 + ((j * lo) << 10);
            D_001DA0D0_003C3360 = D_001DA0D0_003C3360 + 0x70;
        }
        ((u32 *)D_001DA0D0_003C3360)[0] = 0x30000003;
        ((u32 *)D_001DA0D0_003C3360)[1] = (u32)D_001D7830;
        ((u32 *)D_001DA0D0_003C3360)[2] = 0;
        ((u32 *)D_001DA0D0_003C3360)[3] = 0x50000003;
        D_001DA0D0_003C3360 = D_001DA0D0_003C3360 + 0x10;
        ((u32 *)D_001DA0D0_003C3360)[0] = 0x20000000;
        ((u32 *)D_001DA0D0_003C3360)[1] = (u32)(a + 4);
        ((u32 *)D_001DA0D0_003C3360)[2] = 0;
        ((u32 *)D_001DA0D0_003C3360)[3] = 0;
        D_001DA0D0_003C3360 = D_001DA0D0_003C3360 + 0x10;
    }
    pkt[0] = 0x20000000;
    pkt[1] = D_001DA0D0_003C3360;
    pkt[2] = 0;
    pkt[3] = 0;
}
/* localdecomp:end func_003C3668 */

/* localdecomp:start func_003C3890 */
extern u8 D_003802E0[];
extern s32 D_001D9DB0;
extern s32 D_001D9DB8;
extern void func_11F0A0(s32);
extern void func_0038D050(u32 *, s32, s32);
extern void func_003CB550();
void func_003C3890(void) {
    func_11F0A0(0);
    func_0038D050((u32 *)0x70003800, (s32)D_003802E0, 0x800);
    func_003CB550(D_001D9DB0, D_001D9DB8);
}
/* localdecomp:end func_003C3890 */

/* localdecomp:start func_003C38D8 */
extern void func_0038CEA0();
 
void func_003C38D8(void) {
    func_0038CEA0(0x70003A00, 0x40000000, 0x3C0);
}
/* localdecomp:end func_003C38D8 */

/* localdecomp:start func_003C3900 */
extern void func_0038D050();
extern u8 D_002DA400[];
 
void func_003C3900(void) {
    func_0038D050((s32)D_002DA400, 0x70003A00, 0x3C0);
}
/* localdecomp:end func_003C3900 */

/* localdecomp:start func_003C3930 */
extern void func_0038D050();
 extern u8 D_002DA400[];

void func_003C3930(void) {
    func_0038D050(0x70003A00, (s32)D_002DA400, 0x3C0);
}
/* localdecomp:end func_003C3930 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C3960);

/* localdecomp:start func_003C3A20 */
extern void *D_001DA518_003C3A20;
extern void func_003A96B0(s32, unsigned long);
extern void func_11F0A0(s32);
extern void func_003C3930(void);
extern void *func_003CB630(s32, void *, s32, s32);
extern void func_003C3900(void);
void func_003C3A20(s32 a0, s32 a1) {
    func_003A96B0(0x47, 0x5360B);
    func_11F0A0(0);
    func_003C3930();
    D_001DA518_003C3A20 = func_003CB630(a0, D_001DA518_003C3A20, a1, 0);
    func_003C3900();
    D_001DA518_003C3A20 = (u8 *)D_001DA518_003C3A20 - 0x10;
}
/* localdecomp:end func_003C3A20 */

/* localdecomp:start func_003C3AA0 */
extern void func_003C3360(void);
extern void func_003C3890(void);
extern void func_003C3528(void);
extern void func_003C3668(void);
extern s32 D_001DA564[];
extern u8 *D_001DA5B0;
extern u8 D_002FC220[];
void func_003C3AA0(void) {
    func_003C3360();
    func_003C3890();
    if (D_001DA564[0] != 0) {
        func_003C3528();
    }
    if (D_001DA5B0 > D_002FC220) {
        func_003C3668();
    }
}
/* localdecomp:end func_003C3AA0 */

/* localdecomp:start func_003C3B00 */
extern void func_003C38D8();
extern void func_003C3960();
extern void func_003C3AA0();
s32 func_003CB630_003C3B00(s32, s32, s32, s32);      /* extern */
extern s32 D_001DA518;
extern s32 D_001DA51C;
extern s32 D_001DA554;

void func_003C3B00(void) {
    s32 var_a3;

    func_003C3960();
    func_003C38D8();
    var_a3 = 1;
    if (D_001DA554 != 0) {
        D_001DA554 = 0;
        var_a3 = 3;
    }
    D_001DA518 = func_003CB630_003C3B00(D_001DA51C, D_001DA518, -1, var_a3);
    func_003C3AA0();
}
/* localdecomp:end func_003C3B00 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C3B60);

/* localdecomp:start func_003C3B80 */
extern int D_001DA51C;
extern int D_001DA524;
int func_003C3B80(void) {
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
/* localdecomp:end func_003C3B80 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C3BC0);

/* localdecomp:start func_003C3BD8 */
typedef struct { u8 p10[0x10]; u8 n; u8 f11; } T_3BE418;
typedef struct { u8 p0[0x48]; T_3BE418 *e[1]; } Q_3BE418;
typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; f32 f48; f32 f4C; u8 p50[8]; f32 *f58; u8 p5c[4]; u8 f60; u8 p61[0xB]; u8 f6C;
} S_3BE418;
extern void func_003C2C50();
void func_003C3BD8(S_3BE418 *p, s32 idx, s32 lim) {
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
    func_003C2C50(p);
    p->f4C = *p->f58;
    p->f60 &= 0xFD;
    p->f6C = p->f24->e[idx]->f11;
}
/* localdecomp:end func_003C3BD8 */

/* localdecomp:start func_003C3CB0 */
typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; f32 f44; f32 f48; f32 f4C; void *f50; void *f54; u8 p58[8]; u8 f60; u8 p61[0xB]; u8 f6C;
    u8 p6D[0x13]; u128_t f80; u8 p90[0x19]; u8 fA9;
} S_3BE4F0;
extern u128_t D_002DA180[];
extern void func_003C7110_003C3CB0();
extern s32 func_003C2FD0();
extern void func_003C8D68();
void func_003C3CB0(S_3BE4F0 *p, s32 idx, s32 lim, s32 dur) {
    s32 v;
    s32 r;
    s32 n;
    n = p->f24->e[idx]->n;
    if (lim >= n) lim = n - 1;
    if (dur <= 0) {
        func_003C3BD8(p, idx, lim);
        return;
    }
    if ((u32)(lim - 1) < 0xB) func_003C7110_003C3CB0(p, idx, (u16)lim);
    if (0.025f < p->f44 || p->f50 != 0 || p->f54 != 0) {
        r = func_003C2FD0(p);
        if (r >= 0) {
            func_003C8D68(p, r | 0x300);
            D_002DA180[r] = p->f80;
            if (p->f42 != 0xFF) p->fA9 = p->f42;
            p->f42 = 0xFF;
            p->f40 = r;
        }
    }
    p->f41 = lim;
    p->f43 = idx;
    func_003C2C50(p);
    p->f60 &= 0xFD;
    p->f48 = 1.0f;
    p->f44 = 0;
    p->f4C = 1.0f / (f32)dur;
    p->f6C = p->f24->e[idx]->f11;
}
/* localdecomp:end func_003C3CB0 */
TEXT_PADDING(4);

LINKER_REMNANT("asm/boot_elf/remnants", func_003C3E48);

/* localdecomp:start func_003C3E68 */
extern f32 func_0038D3C0(f32);
f32 func_003C3E68(f32 a, f32 b, f32 t) {
    if (t == 0.0f) return a;
    if (t == 1.0f) return b;
    return a + (b - a) * ((1.0f - func_0038D3C0(t * 3.14159274f)) * 0.5f);
}
/* localdecomp:end func_003C3E68 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C3F00);

/* localdecomp:start func_003C3FB0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
extern V_3BE7F0 D_002276E0;
s32 func_003D3F00(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);
f32 func_003C3FB0(V_3BE7F0 *p, s32 flags, s32 c, f32 dz) {
    V_3BE7F0 a = *p;
    V_3BE7F0 b = *p;
    a.z = 0.01f;
    b.z += dz;
    if (func_003D3F00(&b, &a, flags | 2, c, 0)) return D_002276E0.z;
    return 0.0f;
}
/* localdecomp:end func_003C3FB0 */

/* localdecomp:start func_003C4020 */
typedef int Q_3BE860 __attribute__((mode(TI)));
extern V_3BE7F0 D_001A4C90;
extern void func_003C53D8_003C4020();
s32 func_003C4020(V_3BE7F0 *out, void *obj, s32 flags, s32 c, f32 scale) {
    V_3BE7F0 a, b, d;
    Q_3BE860 x, y;
    func_003C53D8_003C4020(obj, &d, 1);
    a = D_001A4C90;
    func_0038D148((f32 *)&b, &d, scale);

    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_3BE7F0 *)obj));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(x));
    if (func_003D3F00(&b, &a, flags | 2, c, 0)) {
        *out = D_002276E0;
        return 1;
    }
    *out = a;
    return 0;
}
/* localdecomp:end func_003C4020 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4108);

/* localdecomp:start func_003C4148 */
extern s32 D_001D9A40;
extern s32 D_001D9A28;
extern f32 D_001D9A38;
extern f32 D_001D9A3C;
extern f32 D_001D9A30[];
extern s32 func_00381C88();
extern f32 func_0038D260();
f32 func_003C4148(f32 *p, void *out) {
    f32 t;
    if (D_001D9A40 != 0) {
        t = p[2];
        if (((s32 (*)(f32 *, f32, f32, f32))func_00381C88)(&t, p[0], p[1], p[2]) != 0) return t;
    }
    if (D_001D9A28 != 0) {
        if (__builtin_fabsf(p[2] - *(volatile f32 *)&D_001D9A38) < 0.5f && func_0038D260(p, D_001D9A30) < D_001D9A3C) {
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
/* localdecomp:end func_003C4148 */

/* localdecomp:start func_003C4240 */
extern s32 func_0038D9B0();
extern void func_0038DA78(void *, s32, f32);
void func_003C4240(s32 *arg0, void *arg1) {
    s32 spv[12];

    func_0038DA78(&spv[8], 0, (*(f32 *)((u8 *)arg1 + 0)));
    func_0038DA78(&spv[4], 1, (*(f32 *)((u8 *)arg1 + 4)));
    func_0038DA78(spv, 2, (*(f32 *)((u8 *)arg1 + 8)));
    ((s32 (*)())func_0038D9B0)(arg0, &spv[8], &spv[4]);
    ((s32 (*)())func_0038D9B0)(arg0, arg0, spv);
}
/* localdecomp:end func_003C4240 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C42D8);

/* localdecomp:start func_003C4308 */
f32 func_003C4308(f32 a, f32 b, f32 t) {
    return a + (b - a) * t;
}
/* localdecomp:end func_003C4308 */

/* localdecomp:start func_003C4318 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) Vector_003BEB58;
extern f32 func_003C4308(f32, f32, f32);
void func_003C4318(Vector_003BEB58 *output, Vector_003BEB58 first, Vector_003BEB58 second, f32 fraction) {
    output->x = func_003C4308(first.x, second.x, fraction);
    output->y = func_003C4308(first.y, second.y, fraction);
    output->z = func_003C4308(first.z, second.z, fraction);
    output->w = func_003C4308(first.w, second.w, fraction);
}
/* localdecomp:end func_003C4318 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C43B0);

/* localdecomp:start func_003C43B8 */
f32 func_003C43B8(f32 *arg0, f32 fparg0, f32 fparg1) {
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
/* localdecomp:end func_003C43B8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4408);

/* localdecomp:start func_003C4420 */
f32 func_003C4420(f32 *pos, f32 *vel, f32 target, f32 maxv, f32 acc, f32 lim) {
    f32 d = target - *pos;
    f32 v;
    if (*vel == 0.0f && d == 0.0f) return 0.0f;
    v = *vel;
    if (0.0f <= v * d) {
        f32 stop = v * v / acc * 0.5f;
        if (__builtin_fabsf(d) < stop) {
            if (stop < __builtin_fabsf(d) + __builtin_fabsf(v)) {
                v = acc;
                func_003C43B8(vel, 0.0f, v);
            } else {
                v = acc * 1.1f;
                func_003C43B8(vel, 0.0f, v);
            }
        } else {
            f32 s;
            __asm__("sqrt.s %0, %1" : "=f"(s) : "f"((acc + acc) * d));
            if (lim < s) s = lim;
            v = maxv;
            if (d < 0.0f) {
                func_003C43B8(vel, -s, v);
            } else {
                func_003C43B8(vel, s, v);
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
/* localdecomp:end func_003C4420 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C45C8);

/* localdecomp:start func_003C45E0 */
void func_003C45E0(f32 *vel, f32 d, f32 maxv, f32 acc, f32 lim) {
    f32 v;
    if (d == 0.0f && *vel == 0.0f) return;
    if (0.0f <= *vel * d && d != 0.0f) {
        f32 stop;
        stop = *vel * *vel / acc * 0.5f;
        v = *vel;
        if (__builtin_fabsf(d) < stop) {
            if (stop < __builtin_fabsf(d) + __builtin_fabsf(v)) {
                v = acc;
                func_003C43B8(vel, 0.0f, v);
            } else {
                v = acc * 1.1f;
                func_003C43B8(vel, 0.0f, v);
            }
        } else {
            f32 s;
            __asm__("sqrt.s %0, %1" : "=f"(s) : "f"((acc + acc) * d));
            if (lim < s) s = lim;
            v = maxv;
            if (d < 0.0f) {
                func_003C43B8(vel, -s, v);
            } else {
                func_003C43B8(vel, s, v);
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
/* localdecomp:end func_003C45E0 */
TEXT_PADDING(2);

LINKER_REMNANT("asm/boot_elf/remnants", func_003C47B8);

/* localdecomp:start func_003C4818 */
typedef struct { s32 v[3]; } N3_3BF058;
extern N3_3BF058 D_001D9148;
void func_003C4818(void *qv, void *mv) {
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
/* localdecomp:end func_003C4818 */

/* localdecomp:start func_003C4A60 */
extern void func_0038D898(void *, void *);
extern void func_003C4818(void *, void *);
extern void func_0038D8B8(void *, void *);
void func_003C4A60(void *a, void *b) {
    u8 m[0x40];
    func_0038D898(m, b);
    func_003C4818(a, m);
    func_0038D8B8(b, m);
}
/* localdecomp:end func_003C4A60 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4AB0);

/* localdecomp:start func_003C4AB8 */
extern f32 func_0038D3D8(f32);
extern f32 func_0038D3C0(f32);
extern void func_0038D148(f32 *, void *, f32);
void func_003C4AB8(f32 *q, void *axis, f32 angle) {
    f32 h = angle * 0.5f;
    func_0038D148(q, axis, func_0038D3D8(h));
    q[3] = func_0038D3C0(h);
}
/* localdecomp:end func_003C4AB8 */

/* localdecomp:start func_003C4B20 */
extern f32 func_0038D200(f32 *);
extern f32 func_0038D488(f32, f32);
void func_003C4B20(f32 *p, f32 *out) {
    f32 a, b, c, s, x, y, z, r;
    out[1] = func_0038D488(func_0038D200(p), -p[2]);
    out[2] = func_0038D488(p[0], p[1]);
    if (__builtin_fabsf(out[2]) > 1e-5f) {
        c = func_0038D3C0(-out[2]);
        s = func_0038D3D8(-out[2]);
        x = c * p[4] - s * p[5];
        y = s * p[4] + c * p[5];
    } else {
        x = p[4];
        y = p[5];
    }
    if (__builtin_fabsf(out[1]) > 1e-5f) {
        c = func_0038D3C0(-out[1]);
        s = func_0038D3D8(-out[1]);
        z = -s * x + c * p[6];
        x = c * x + s * p[6];
    } else {
        z = p[6];
    }
    {
        f32 q;
        __asm__("sqrt.s %0, %1" : "=f"(q) : "f"(x * x + y * y));
        r = func_0038D488(q, z);
    }
    out[0] = r;
    if (y < 0.0f) {
        if (r < 0.0f) out[0] = -3.14159274f - r;
        else out[0] = 3.14159274f - r;
    }
}
/* localdecomp:end func_003C4B20 */

/* localdecomp:start func_003C4CB8 */
extern void func_003C7220(s32, s32 *, s32 *, s32 *);
typedef struct { s16 x0; s16 x2; u8 x4, x5, x6; u8 p7[5]; u16 xC; s16 xE; } S_BF;
void func_003C4CB8(s32 a0, S_BF *a1) {
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
        func_003C7220(a0, &r, &g, &b);
        a1->x4 = r;
        a1->x5 = g;
        a1->x6 = b;
    }
}
/* localdecomp:end func_003C4CB8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C4D80);
