#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_0039FE80();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003C0E08);

/* localdecomp:start func_003C0E10 */
typedef int Q_3C0E10 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C0E10;
typedef struct { u8 p0[0x10]; V_3C0E10 pos; } O_3C0E10;
typedef struct { u8 p0[0x46]; u8 b46; } P_3C0E10;
typedef struct { u8 p0[0x10]; f32 f10; f32 f14; u8 p18[0xC]; P_3C0E10 *f24; } E_3C0E10;
extern E_3C0E10 *D_00227740[];
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern s32 func_003BF5E0();
extern f32 func_00389468(f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(f32 *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
s32 func_003C0E10(void *, f32 *, f32 *, f32, f32, f32);
s32 func_003C0E10(void *o, f32 *out, f32 *v, f32 a, f32 lim, f32 unused) {
    O_3C0E10 *obj = (O_3C0E10 *)o;
    f32 t[4] __attribute__((aligned(16)));
    f32 u[4] __attribute__((aligned(16)));
    f32 arr[16];
    f32 ang, d;
    s32 n, i, cnt;
    *(Q_3C0E10 *)out = *(Q_3C0E10 *)v;
    *(Q_3C0E10 *)t = *(Q_3C0E10 *)v;
    t[2] = 0.0f;
    func_00388830(t, t, a);
    __asm__(
        "lqc2 $vf2, %1\n"
        "lqc2 $vf1, %2\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        : "=m"(*(V_3C0E10 *)u) : "m"(*(V_3C0E10 *)t), "m"(obj->pos));
    ang = func_00388A28(t[0], t[1]);
    n = func_003CF790(u, 0, obj, 0, a);
    if (n != 0) {
    cnt = 0;
    for (i = 0; i < n && i < 16; i++) {
        if (func_003BF5E0(D_00227740[i]) != 0 || (D_00227740[i]->f24 != 0 && D_00227740[i]->f24->b46 == 0x16)) {
            d = func_00388A28(D_00227740[i]->f10 - obj->pos.x, D_00227740[i]->f14 - obj->pos.y);
            if (func_00389468(ang, d) < lim) {
                arr[cnt++] = d;
            }
        }
    }
    if (cnt != 0) {
        s32 j, k;
        for (j = 0; j < cnt - 1; j++) {
            s32 jj = j + 1;
            for (k = 0; k < cnt - jj; k++) {
                if (arr[k + 1] < arr[k]) {
                    f32 tmp = arr[k];
                    arr[k] = arr[k + 1];
                    arr[k + 1] = tmp;
                }
            }
        }
        d = arr[cnt >> 1];
        ang = func_003887A0(out);
        out[0] = func_00388960(d) * ang;
        out[1] = func_00388978(d) * ang;
    }
    return 1;
    }
    return 0;
}
/* localdecomp:end func_003C0E10 */

LINKER_REMNANT("asm/remnants", func_003C1070);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1130);

/* localdecomp:start func_003C1440 */
typedef int Q_3C1440 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C1440;
typedef struct { u8 p0[0x10]; V_3C1440 pos; u8 p20[0xA0]; u8 fC0[0x30]; V_3C1440 fF0; } O_3C1440;
typedef struct {
    V_3C1440 f0; V_3C1440 f10; u8 f20[0x10]; f32 f30[3]; f32 f3C[3]; f32 f48[3]; f32 f54[3];
    f32 f60; f32 f64; f32 f68; f32 f6C; f32 f70; f32 f74; f32 f78[3]; f32 f84[3]; f32 f90[3]; f32 f9C[3]; s32 fA8; s32 fAC;
} C_3C1440;
typedef struct { u8 p0[0x80]; V_3C1440 f80; u8 p90[0x2CC]; O_3C1440 *f35C; s32 f360; } W_3C1440;
extern W_3C1440 D_1A4BE0;
extern s32 func_0011A264(void *, s32, s32);
extern void func_003BFAF8();
extern s32 func_00388398(void *);
extern f32 func_00389380_003C1440(f32, f32);
extern f32 func_00388978(f32);
extern void func_00388BD0();
extern void func_00388EB8();
extern void func_003888C8(void *, void *, void *);
extern void func_003BFD90(void *, void *, void *, f32);
extern s32 func_003BF7E8();
extern void func_003BF838();
/* Both branches on one line: their asm_operands carry the same line, so cross-jumping merges the vsub/sqc2 tails. */
#define VSUB_3C1440(d, a, b) { Q_3C1440 p, q; __asm__("lqc2 %0, %1" : "=j"(p) : "m"(a)); __asm__("lqc2 %0, %1" : "=j"(q) : "m"(b)); __asm__("vsub.xyz %0, %1, %2" : "=j"(p) : "j"(p), "j"(q)); __asm__("sqc2 %1, %0" : "=m"(d) : "j"(p)); }
void func_003C1440(O_3C1440 *o, C_3C1440 *c, V_3C1440 *tgt) {
    V_3C1440 a, b;
    f32 cc[4] __attribute__((aligned(16)));
    V_3C1440 e, g, f, h, X1, Y1, i, k, l;
    s32 n;
    f32 *pe;
    Q_3C1440 x, y;
    s32 r;
    s32 m;
    a = o->pos;
    b = o->fF0;
    func_0011A264(cc, 0, 0x10);
    if (tgt != 0 || (D_1A4BE0.f35C == o && D_1A4BE0.f360 >= 2)) {
        if (tgt != 0) VSUB_3C1440(e, *tgt, o->pos) else VSUB_3C1440(e, D_1A4BE0.f80, o->pos)
        func_003BFAF8(o, &e, &e, 0);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(c->f10));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(x));
        cc[0] = -e.y * c->f6C;
        cc[1] = e.x * c->f70;
        cc[2] = -c->f74;
        if (c->fAC == 0) {
            for (m = 0; m < 3; m++) c->f3C[m] += cc[m] * c->f78[m];
            c->fAC = 10;
        }
    } else {
        func_00388398(&c->fAC);
    }
    pe = &e.x;
    for (n = 0; n < 3; n++) {
        c->f3C[n] += c->f48[n] * (cc[n] - c->f30[n]);
        c->f3C[n] -= c->f54[n] * c->f3C[n];
        c->f30[n] += c->f3C[n];
        c->f84[n] = func_00389380_003C1440(c->f84[n], c->f90[n]);
        pe[n] = c->f9C[n] * func_00388978(c->f84[n]);
    }
    *(Q_3C1440 *)&f = 0;
    f.x = c->f30[0] + e.x;
    f.y = c->f30[1] + e.y;
    g = f;
    if (c->f60 < g.x) g.x = c->f60;
    else if (g.x < -c->f60) g.x = -c->f60;
    if (g.y > c->f64) g.y = c->f64;
    else if (g.y < -c->f64) g.y = -c->f64;
    func_00388BD0(&h, &g);
    func_00388BD0(o->fC0, c->f20);
    func_00388EB8(o->fC0, o->fC0, &h);
    f = c->f10;
    f.z = f.z + e.z;
    func_003888C8(&i, &f, o->fC0);
    {
        Q_3C1440 t1, t2, t3, t4, w, t5, t6, t7, t8;
        __asm__("lqc2 %0, %1" : "=j"(t1) : "m"(i));
        __asm__("lqc2 %0, %1" : "=j"(t2) : "m"(o->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(t3) : "j"(t1), "j"(t2));
        __asm__("lqc2 %0, %1" : "=j"(t4) : "m"(c->f0));
        __asm__("sqc2 %1, %0" : "=m"(i) : "j"(t3));
        __asm__("lqc2 %0, %1" : "=j"(w) : "m"(o->pos));
        __asm__("lqc2 %0, %1" : "=j"(t5) : "m"(i));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(t6) : "j"(t4), "j"(t5));
        __asm__("sqc2 %1, %0" : "=m"(k) : "j"(t6));
        __asm__("lqc2 %0, %1" : "=j"(t7) : "m"(k));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(t8) : "j"(w), "j"(t7));
        __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(t8));
    }
    {
        f32 v = -c->f30[2];
        if (c->f68 < v) v = c->f68;
        else if (v < -c->f68) v = -c->f68;
        func_003BFD90(o, &o->pos, &o->pos, v);
    }
    r = func_003BF7E8(o);
    if (r != 0) {
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(l) : "j"(x));
        func_003BF838(r, &l, &b, &o->fF0);
    }
}
/* localdecomp:end func_003C1440 */

LINKER_REMNANT("asm/remnants", func_003C18F8);

/* localdecomp:start func_003C1950 */
typedef struct { u16 id; u16 t; } E_C1950;
typedef struct { u8 p0[0x10]; u8 k; u8 p11; u8 n; u8 p13[9]; E_C1950 e[1]; } Y_C1950;
typedef struct { u8 p0[0xC]; u8 cnt; u8 pD[0x3B]; Y_C1950 *y[1]; } X_C1950;
typedef struct { u8 p0[0x24]; X_C1950 *x; } O_C1950;
void func_003C1950(O_C1950 *o, s32 idx, u16 t) {
    X_C1950 *x = o->x;
    Y_C1950 *y;
    E_C1950 *e;
    s32 i;
    if (x != 0 && idx < x->cnt) {
        y = x->y[idx];
        if (y->n != 0) {
            e = (E_C1950 *)((u8 *)y + (y->k * 4 + 0x1C));
            for (i = 0; i < y->n && (t << 4) >= e[i].t; i++) {
                func_0039FE80(e[i].id, 0, o);
            }
        }
    }
}
/* localdecomp:end func_003C1950 */

LINKER_REMNANT("asm/remnants", func_003C1A28);

/* localdecomp:start func_003C1A40 */
unsigned long func_003C1A40(u8 *p, unsigned long a, unsigned long b, unsigned long c, unsigned long d) {
    register unsigned long shifted __asm__("$5") = a << 32;
    __asm__ volatile("" : "+r"(shifted));
    c <<= 8;
    d <<= 16;
    __asm__ volatile("" : "+r"(d));
    return *(unsigned long *)(p + 0x38) = shifted | b | c | d;
}
/* localdecomp:end func_003C1A40 */
