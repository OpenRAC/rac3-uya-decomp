#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void func_0038CEA0();
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_0038CEA0(void *, s32, s32);
extern s32 func_003E5950(void);
extern s32 *func_003E5B88(s32 *);
extern s32 func_003E5B68();
extern void func_003E65B8();
extern void func_0038CEA0(void *, int, int);
extern void func_003E65B8(void **, s32, s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E5950 */
typedef int u128_3E0190 __attribute__((mode(TI)));
typedef struct { u128_3E0190 q0; f32 f10; f32 f14; f32 f18; f32 f1C; } P_3E0190;
typedef struct { u8 pad[0x38]; s32 f38; u8 pad2[0x28]; u8 *f64; } G_3E0190;
typedef struct { u8 pad[0xB0]; f32 fB0; } H_3E0190;
typedef struct { f32 v[4]; } V4_3E0190;
typedef struct { V4_3E0190 v0; u8 pad[0x370]; f32 f380[4]; f32 f390[4]; f32 f3A0[4]; } M_3E0190;
extern G_3E0190 D_00225780;
extern H_3E0190 D_00225980;
extern M_3E0190 D_00222500;
extern u8 D_00222520[];
extern f32 D_001D5BC8;
extern f32 D_001D5BCC;
extern void func_00387778();
extern void func_12FF40(f32 *);
extern void func_130088(f32 *, f32 *, f32);
extern void func_130130(f32 *, f32 *, f32);
extern void func_12FFE0(f32 *, f32 *, f32);
extern void func_0038D290(void *, void *, f32);
extern void func_00384620(s32, void *, s32);
extern void func_00385080(s32);
s32 func_003E5950(void) {
    f32 m[16];
    u128_3E0190 v;
    P_3E0190 *p;
    f32 *q;
    u8 r;
    f32 f, s;
    p = (P_3E0190 *)(D_00225780.f64 + (D_00225780.f38 << 5));
    q = &p->f10;
    r = ((u8 *)p)[0xC];
    f = q[3];
    D_00225980.fB0 = f;
    if (*(u8 *)0x1D5471) D_00225980.fB0 = f * D_001D5BC8;
    func_00387778();
    *(u128_3E0190 *)&D_00222500.v0 = p->q0;
    func_12FF40(m);
    func_130088(m, m, p->f10);
    func_130130(m, m, q[1]);
    func_12FFE0(m, m, q[2]);
    D_00222500.f380[0] = -m[8];
    D_00222500.f390[0] = -m[0];
    D_00222500.f3A0[0] = m[4];
    D_00222500.f380[1] = -m[9];
    D_00222500.f390[1] = -m[1];
    D_00222500.f3A0[1] = m[5];
    D_00222500.f380[2] = -m[10];
    D_00222500.f390[2] = -m[2];
    D_00222500.f3A0[2] = m[6];
    if (*(u8 *)0x1D5471) {
        s = D_001D5BCC;
        if (s != 0.0f) {
            v = *(u128_3E0190 *)D_00222500.f380;
            func_0038D290(&v, &v, s);
            __asm__ __volatile__(
                "lqc2 $vf1, %1\n"
                "lqc2 $vf2, %2\n"
                "vsub.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, %0\n"
                : "=m"(D_00222500.v0) : "m"(D_00222500.v0), "m"(*(V4_3E0190 *)&v));
        }
    }
    func_00384620(0, D_00222520, 0);
    func_00384620(0, D_00222520 + 0x10, 1);
    func_00384620(0, D_00222520 + 0x20, 2);
    func_00385080(0);
    return r;
}
/* localdecomp:end func_003E5950 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E5B18);

/* localdecomp:start func_003E5B30 */
void func_003E5B30(f32 *p, f32 lo, f32 hi) {
    *p = (*p < lo) ? lo : *p;
    *p = (hi < *p) ? hi : *p;
}
/* localdecomp:end func_003E5B30 */

/* localdecomp:start func_003E5B68 */
extern s32 func_003E65E8();
 
s32 func_003E5B68(void **p) {
    return func_003E65E8(p) != 0;
}
/* localdecomp:end func_003E5B68 */

/* localdecomp:start func_003E5B88 */
s32 *func_003E5B88(s32 *p) {
    *p = 0;
    return p;
}
/* localdecomp:end func_003E5B88 */

/* localdecomp:start func_003E5B98 */
typedef struct { u8 p0[0x50]; s32 *arr[35]; u8 pad[0x41DC - 0xDC]; } O_3E03D8;
extern O_3E03D8 D_00306E80_003E5B98[];
extern O_3E03D8 D_0031B7CC[];
extern s32 func_003E7388();
void func_003E5B98(void) {
    O_3E03D8 *s = D_00306E80_003E5B98;
    O_3E03D8 *p;
    s32 **q;
    if (s != 0) {
        p = D_0031B7CC;
        if (p != s) {
            do {
                p--;
                if (p->arr != 0) {
                    q = p->arr + 35;
                    if (p->arr != q) {
                        do {
                            q--;
                            if (*q) func_003E7388(*q);
                            *q = 0;
                        } while (p->arr != q);
                    }
                }
            } while (p != D_00306E80_003E5B98);
        }
    }
}
/* localdecomp:end func_003E5B98 */

/* localdecomp:start func_003E5C38 */
extern u8 D_00306E80[];
extern s32 D_001DA8F8;
extern void *func_003E68E0();
extern void func_116FD0();
extern void func_003E5B98();
void *func_003E5C38(s32 idx) {
    u8 *q;
    s32 *w;
    s32 n, j;
    if (D_001DA8F8 == 0) {
        q = D_00306E80;
        n = 4;
        do {
            w = (s32 *)(q + 0x50);
            for (j = 0x22; j != -1; j--) *w++ = 0;
            func_003E68E0(q + 0x1C4);
            func_003E68E0(q + 0x21CC);
            q += 0x41DC;
            n--;
        } while (n != -1);
        D_001DA8F8 = 1;
        func_116FD0(func_003E5B98);
    }
    return D_00306E80 + idx * 0x41DC;
}
/* localdecomp:end func_003E5C38 */

/* localdecomp:start func_003E5D10 */
typedef struct { u8 b[16]; } B16_003E0550;
typedef struct { B16_003E0550 hdr; s32 a[16]; s32 b[16]; u8 p90[0x4C]; s32 c[16]; s32 d[16]; s32 e[16]; u8 f[16]; u8 g[16]; s32 f1BC; u32 f1C0; u8 p1C4[0x41D4 - 0x1C4]; s32 f41D4; s32 f41D8; } O_003E0550;
extern void func_003E60F0();
s32 func_003E5D10(O_003E0550 **o, u32 mode) {
    B16_003E0550 tmp;
    s32 i;
    if (mode < 5) {
        *o = func_003E5C38(mode);
        (*o)->hdr = tmp;
        for (i = 0; i < 16; i++) (*o)->a[i] = 0;
        for (i = 0; i < 16; i++) *(s32 *)((u8 *)(*o) + i * 4 + 0x50) = 0;
        for (i = 0; i < 16; i++) {
            (*o)->c[i] = 0;
            (*o)->d[i] = 0;
            (*o)->e[i] = 0;
            (*o)->f[i] = 0;
            (*o)->g[i] = 0;
        }
        (*o)->f1BC = 0;
        (*o)->f1C0 = 0;
        (*o)->f41D4 = 0;
        (*o)->f1C0 = mode;
        (*o)->f41D8 = 0;
        func_003E60F0(o);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E5D10 */

/* localdecomp:start func_003E5E40 */
s32 func_003E5E40(void **p) {
    return *(s32 *)((u8 *)*p + 0x1C0);
}
/* localdecomp:end func_003E5E40 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E5E50);

/* localdecomp:start func_003E5E60 */
typedef struct { u8 pad[0x10]; s32 a[16]; } S_3E06A0;
void func_003E5E60(S_3E06A0 **p) {
    s32 i;
    for (i = 0; i < 16; i++) (*p)->a[i] = 0;
}
/* localdecomp:end func_003E5E60 */

/* localdecomp:start func_003E5E90 */
extern void func_003E7250(void *);

void func_003E5E90(s32 *arg0) {
    s32 temp_s0;
    s32 temp_v1;
    s32 var_s2;
    void *temp_v0;

    var_s2 = 0;
    do {
        temp_s0 = var_s2 * 4;
        temp_v1 = (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0xDC));
        if (temp_v1 != 0) {
            func_003E7250(temp_v1);
        }
        (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0xDC)) = 0;
        (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0x11C)) = 0;
        (*(s32 *)((u8 *)((*arg0 + temp_s0)) + 0x15C)) = 0;
        (*(s8 *)((u8 *)((*arg0 + var_s2)) + 0x1AC)) = 0;
        temp_v0 = *arg0 + var_s2;
        var_s2 += 1;
        (*(s8 *)((u8 *)(temp_v0) + 0x19C)) = 0;
    } while (var_s2 < 0x10);
}
/* localdecomp:end func_003E5E90 */

/* localdecomp:start func_003E5F30 */
s32 func_003E5F30(void **p) {
    return *(s32 *)((u8 *)*p + 0x1BC);
}
/* localdecomp:end func_003E5F30 */

/* localdecomp:start func_003E5F40 */
typedef struct { u8 pad[0xDC]; s32 arr[1]; } S_3E0780;
 
s32 func_003E5F40(S_3E0780 **p, s32 i) {
    return (*p)->arr[i];
}
/* localdecomp:end func_003E5F40 */

/* localdecomp:start func_003E5F58 */
extern s32 D_001D9710[];
extern s32 func_003E65E8();
extern s32 func_003E7388();
extern void func_003E7378();
s32 func_003E5F58(s32 *a0, u32 a1, s32 a2) {
    s32 *p;
    s32 *obj;
    s32 *s1;
    if (a1 < 0x23) {
        if (*(s32 *)(a1 * 4 + *a0 + 0x50) == 0) {
            obj = (s32 *)func_003E65E8(a0, a2);
            if (obj != 0 && ((s32 (*)())(*(s32 *)(obj[2] + 0x10)))(obj, D_001D9710[0]) != 0) s1 = obj; else s1 = 0;
            if (s1 != 0) {
                p = (s32 *)(a1 * 4 + *a0); p += 0x14;
                if (*p != 0) func_003E7388(*p);
                *p = (s32)s1;
                func_003E7378(s1);
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_003E5F58 */

/* localdecomp:start func_003E6030 */
extern s32 func_003E7388();
extern s32 func_003E5E40();
extern s32 func_003E6788(s32);
extern s32 func_003E7110();
s32 func_003E6030(s32 *p, u32 idx) {
    s32 *q;
    s32 i;
    if (idx < 0x23) {
        q = (s32 *)((u8 *)(idx * 4) + *p);
        q += 0x14;
        if (*q) func_003E7388(*q);
        *q = 0;
        for (i = 3; i >= 0; i--) {
            func_003E7110(func_003E6788(func_003E5E40(p)));
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6030 */

/* localdecomp:start func_003E60C0 */
void func_003E60C0(s32 **p) {
    s32 i;
    for (i = 0; i < 35; i++) (*p)[i + 20] = 0;
}
/* localdecomp:end func_003E60C0 */

/* localdecomp:start func_003E60F0 */
typedef struct { u8 b[16]; } B16_003E0930;
extern B16_003E0930 D_001D9680;
extern void func_003E68A8();
extern void func_003E5E90();
extern void func_003E60C0();
extern void func_003E5E60();
void func_003E60F0(u8 **o) {
    B16_003E0930 tmp;
    func_003E68A8(*o + 0x1C4);
    func_003E68A8(*o + 0x21CC);
    func_003E5E90(o);
    func_003E60C0(o);
    func_003E5E60(o);
    tmp = D_001D9680;
    *(B16_003E0930 *)*o = tmp;
    *(s32 *)(*o + 0x1BC) = -1;
}
/* localdecomp:end func_003E60F0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E6198);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E6338);

/* localdecomp:start func_003E6480 */
typedef struct { u8 pad[0xDC]; s32 A[16]; s32 B[16]; } O_003E0CC0;
extern s32 func_003E7258();
s32 func_003E6480(O_003E0CC0 **pp, s32 b) {
    s32 r = -1;
    s32 i;
    if (func_003E7258(b) == 0) {
        for (i = 0; i < 16; i++) {
            if ((*pp)->A[i] == 0 && (*pp)->B[i] == 0) {
                (*pp)->B[i] = b;
                r = i;
                break;
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E6480 */

/* localdecomp:start func_003E6538 */
typedef struct { u8 pad[0x11C]; s32 slots[36]; u8 used[1]; } T_3E0D78;
typedef struct { T_3E0D78 *t; } S_3E0D78;
s32 func_003E6538(S_3E0D78 *s, s32 v) {
    s32 i = func_003E5F30(s);
    T_3E0D78 *t;
    if (i < 0) return 0;
    t = s->t;
    if (t->slots[i] != 0) return 0;
    if (t->used[i] != 0) return 0;
    t->slots[i] = v;
    return 1;
}
/* localdecomp:end func_003E6538 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E65B0);

/* localdecomp:start func_003E65B8 */
extern s32 func_003E6990();
 
void func_003E65B8(void **p, s32 a, s32 b) {
    func_003E6990((u8 *)*p + 0x1C4, b, a);
}
/* localdecomp:end func_003E65B8 */

/* localdecomp:start func_003E65E8 */
extern void *func_003E6910();
 
s32 func_003E65E8(void **p) {
    return func_003E6910((u8 *)*p + 0x1C4);
}
/* localdecomp:end func_003E65E8 */

/* localdecomp:start func_003E6608 */
typedef struct {
    u8 pad0[0xDC];
    s32 a[16];
    s32 b[16];
    u8 pad1[0x50];
    u8 c[16];
} S_3E0E48;
s32 func_003E6608(void *a0, s32 a1) {
    S_3E0E48 *s = *(S_3E0E48 **)a0;
    s32 r = 0;
    if (s->a[a1] != 0 && s->c[a1] == 0) {
        s->b[a1] = 0;
        (*(S_3E0E48 **)a0)->c[a1] = 1;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_003E6608 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E6650);

/* localdecomp:start func_003E6788 */
extern s32 D_001D9690_003E6788;
extern s32 D_001DA900_003E6788;
extern s32 D_001DA914_003E6788;
extern s32 D_001DA918_003E6788;
extern s32 D_001DA92C_003E6788;
extern s32 D_001DA930_003E6788;
extern s32 D_001DA944_003E6788;
extern s32 D_001DA948_003E6788;
extern s32 D_001DA95C_003E6788;
extern s32 D_001DA960_003E6788;
extern s32 D_001DA974_003E6788;

extern s32 *func_003E70F0();
extern void func_003E6650();
s32 func_003E6788(s32 a) {
    if (D_001DA914_003E6788 == 0) {
        func_003E70F0(&D_001DA900_003E6788, 0, 0x3FF, 0, func_003E6650);
        D_001DA914_003E6788 = 1;
    }
    if (D_001DA92C_003E6788 == 0) {
        func_003E70F0(&D_001DA918_003E6788, 0, 0x3FF, 1, func_003E6650);
        D_001DA92C_003E6788 = 1;
    }
    if (D_001DA944_003E6788 == 0) {
        func_003E70F0(&D_001DA930_003E6788, 0, 0x3FF, 2, func_003E6650);
        D_001DA944_003E6788 = 1;
    }
    if (D_001DA95C_003E6788 == 0) {
        func_003E70F0(&D_001DA948_003E6788, 0, 0x3FF, 3, func_003E6650);
        D_001DA95C_003E6788 = 1;
    }
    if (D_001DA974_003E6788 == 0) {
        func_003E70F0(&D_001DA960_003E6788, 0, 0x3FF, 3, func_003E6650);
        D_001DA974_003E6788 = 1;
    }
    return ((s32 *)&D_001D9690_003E6788)[a];
}
/* localdecomp:end func_003E6788 */

/* localdecomp:start func_003E68A8 */
void func_003E68A8(u8 *p) {
    func_0038CEA0((s32)(p + 8), 0, 0x2000);
    *(s32 *)(p + 4) = 0;
}
/* localdecomp:end func_003E68A8 */

/* localdecomp:start func_003E68E0 */
extern s32 *func_003F2588(s32 *);
void *func_003E68E0(void *p) {
    func_003F2588((s32 *)p);
    func_003E68A8(p);
    return p;
}
/* localdecomp:end func_003E68E0 */
