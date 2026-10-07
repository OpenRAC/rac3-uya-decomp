#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003958F0(void);
extern void func_00397490(void);
extern void func_00395FF0(void);
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_00399F90();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003958F0 */
extern void func_00388440(void *, s32, s32);
extern u8 D_0016C690[];
void func_003958F0(void) {
    s32 *p;
    s32 i;
    func_00388440(D_0016C690, 0, 0x35840);
    *(s16 *)(D_0016C690 + 0x14) = -1;
    p = (s32 *)(D_0016C690 + 0x3C);
    for (i = 2; i >= 0; i--) {
        *p-- = -1;
    }
}
/* localdecomp:end func_003958F0 */

/* localdecomp:start func_00395958 */
extern s32 D_001D600C;
typedef struct { u8 pad[0x34]; s32 arr[8]; } T_00395958;
extern T_00395958 D_0016C690_00395958;
typedef struct { s32 f0; s32 f4; } S_00395958;

void func_00395958(S_00395958 *arg0, s32 arg1) {
    if (arg1 != 0) {
        if (arg0->f4 >= 0) {
            D_0016C690_00395958.arr[arg0->f4] = arg0->f0;
            if (arg0->f4 == D_001D600C) {
                D_001D600C = arg0->f4 ^ 1;
            }
        }
    }
    arg0->f0 = -1;
}
/* localdecomp:end func_00395958 */

/* localdecomp:start func_003959A8 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_003959A8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_003959A8 el[0x30]; } S_003959A8;
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; } L_003959A8;
typedef struct { s32 f0; s32 f4; u8 *f8; } A_003959A8;
extern S_003959A8 D_160C40_003959A8;
extern void func_00395958();
extern void func_11F0A0();
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern s32 func_0039D5A8();
void func_003959A8(A_003959A8 *a, s32 flag) {
    s32 t;
    s32 off;
    s32 base;
    s32 h;
    u8 *o;
    s32 *r;
    L_003959A8 l;
    if (flag == 0) {
        a->f0 = -1;
        return;
    }
    t = D_160C40_003959A8.el[a->f0].f10;
    if (t != 0) {
        off = a->f4 * 0xC800;
        o = a->f8;
        base = *(s32 *)0x1D4B38 + off;
        l.w0 = (s32)o;
        l.w4 = base;
        l.w8 = t << 11;
        l.wC = 0;
        r = (s32 *)(o + 0x18);
        *(s32 *)(o + 0x14) = 0xC000;
        r[10] = 0xC000;
        r[11] = 0xC000;
        func_11F0A0(0);
        h = func_11F1E0(&l, 1);
        while (func_11F1C0(h) >= 0) {
        }
    }
    func_0039D5A8(a->f8, D_160C40_003959A8.el[a->f0].f4 + D_160C40_003959A8.g458C, D_160C40_003959A8.el[a->f0].f8, func_00395958, a);
}
/* localdecomp:end func_003959A8 */

/* localdecomp:start func_00395AC8 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_00395AC8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_00395AC8 el[0x30]; } S_00395AC8;
extern S_00395AC8 D_160C40_00395AC8;
typedef struct { u8 pad[0x34]; s32 f34[3]; } T_00395AC8;
extern T_00395AC8 D_16C690_00395AC8;
__asm__(".extern D_001D6000_00395AC8, 4");
extern s32 D_001D6000_00395AC8;
extern u8 D_001D6004_00395AC8;
extern u8 D_001D6008_00395AC8;
extern s32 func_0039D5A8();
extern void func_00395958();
extern void func_003959A8();
s32 func_00395AC8(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 t;
    if (D_160C40_00395AC8.el[a0].f8 != 0) {
        t = D_001D6000_00395AC8;
        if (t == -1) {
            *(volatile s32 *)&D_001D6000_00395AC8 = a0;
            *(volatile s32 *)&D_001D6004_00395AC8 = a1;
            *(volatile s32 *)&D_001D6008_00395AC8 = a2;
            if (a1 >= 0) {
                D_16C690_00395AC8.f34[a1] = t;
            }
            if (D_160C40_00395AC8.el[a0].f10 != 0 && a3 == 0) {
                return func_0039D5A8(a2, D_160C40_00395AC8.el[a0].fC + D_160C40_00395AC8.g458C, D_160C40_00395AC8.el[a0].f10, func_003959A8, &D_001D6000_00395AC8);
            }
            return func_0039D5A8(a2, D_160C40_00395AC8.el[a0].f4 + D_160C40_00395AC8.g458C, D_160C40_00395AC8.el[a0].f8, func_00395958, &D_001D6000_00395AC8);
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_00395AC8 */

/* localdecomp:start func_00395BC0 */
typedef struct { s32 k; u8 pad[0x10]; } E_395BC0;
typedef struct { u8 pad[0x4590]; E_395BC0 e[0x30]; } S_395BC0;
typedef struct { u8 d[0xC800]; } B_395BC0;
typedef struct { u8 pad[0x34]; s32 f34[3]; B_395BC0 blk[1]; } S_395BC0b;
extern S_395BC0 D_160C40_00395BC0;
extern S_395BC0b D_16C690_00395BC0;
void func_00395BC0(s32 a, s32 b) {
    s32 i;
    for (i = 0; i < 0x30; i++) {
        if (D_160C40_00395BC0.e[i].k == a) break;
    }
    if (i == 0x30) return;
    if (D_16C690_00395BC0.f34[b] == i) return;
    func_00395AC8(i, b, &D_16C690_00395BC0.blk[b], 0);
}
/* localdecomp:end func_00395BC0 */

INCLUDE_ASM("asm/nonmatchings/text", func_00395C48);

LINKER_REMNANT("asm/remnants", func_00395E10);

/* localdecomp:start func_00395E18 */
typedef struct { s32 id; s32 pad[4]; } E_395E18;
typedef struct { u8 pad[0x4590]; E_395E18 e[0x30]; } S_395E18;
typedef struct { u8 pad[0x34]; s32 v[3]; } T_395E18;
extern S_395E18 D_160C40[];
extern T_395E18 D_16C690[];
s32 func_00395E18(s32 id) {
    s32 i, j;
    for (i = 0; i < 0x30; i++) if (D_160C40[0].e[i].id == id) break;
    if (i == 0x30) return 1;
    for (j = 0; j < 3; j++) if (D_16C690[0].v[j] == i) break;
    return j != 3;
}
/* localdecomp:end func_00395E18 */

LINKER_REMNANT("asm/remnants", func_00395EA8);

/* localdecomp:start func_00395EB8 */
typedef struct { u8 *data; u8 *clut; u8 pad8[0xC]; s32 f14; u8 pad18[0x34]; s32 tw; s32 th; u8 pad54[4]; } T_395EB8;
typedef struct { u8 *data; s16 f4; s16 f6; u8 *clut; u8 tw; u8 th; s16 fE; } E_395EB8;
extern s32 D_001D4BB0;
extern s32 D_001D9C7C;
extern E_395EB8 D_00225C80[];
long func_00395EB8(u8 *p) {
    T_395EB8 t;
    s32 w, h, s, a, cbp, tbp;
    long r;
    E_395EB8 *e;
    w = *(s32 *)(p + 8);
    __asm__("plzcw %0, %1" : "=r"(w) : "r"(w));
    h = *(s32 *)(p + 0xC);
    __asm__("plzcw %0, %1" : "=r"(h) : "r"(h));
    t.tw = 0x1E - w;
    t.th = 0x1E - h;
    s = t.tw - 6;
    if (s < 0) s = 0;
    a = D_001D4BB0;
    cbp = a >> 8;
    a += 0x400;
    tbp = a >> 8;
    t.data = p + 0x20;
    t.clut = p + 0x420;
    t.f14 = 0x400;
    D_001D4BB0 = a + (1 << (t.tw + t.th));
    r = (long)tbp | ((long)(1 << s) << 14) | (0x13UL << 20) | ((long)t.tw << 26) | ((long)t.th << 30) | (1UL << 34) | ((long)cbp << 37) | (4UL << 61);
    if (D_001D9C7C < 0x40) {
        e = &D_00225C80[D_001D9C7C];
        e->data = t.data;
        e->f6 = cbp;
        e->f4 = 0;
        D_00225C80[D_001D9C7C].clut = t.clut;
        e->tw = t.tw;
        e->th = t.th;
        e->fE = tbp;
        D_001D9C7C++;
    }
    return r;
}
/* localdecomp:end func_00395EB8 */

LINKER_REMNANT("asm/remnants", func_00395FE0);

/* localdecomp:start func_00395FE8 */
void func_00395FE8(void) {
}
/* localdecomp:end func_00395FE8 */

/* localdecomp:start func_00395FF0 */
__asm__(".extern D_001D4CE8_g_00395FF0, 4");
__asm__(".extern D_001DA024_g_00395FF0, 4");
typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[0x10]; s32 f24; u8 p28[0x144]; s32 f16C; } S_395FF0;
extern S_395FF0 D_00142430_00395FF0[];
extern u8 D_001DA028_00395FF0;
extern s32 D_001D4CE8_g_00395FF0;
extern s32 D_001D4CE8_00395FF0;
extern volatile s32 D_001D4CEC_00395FF0;
extern s32 D_001DA024_g_00395FF0;
extern s32 D_001DA024;
extern void (*D_0032E338[])(void);
void func_00395FF0(void) {
    S_395FF0 *s = D_00142430_00395FF0;
    s32 old;
    s32 v;
    if (s->f16C != 0 || (s->f8 == 2 && s->f10 != 0) || s->f24 > 0) {
        D_001DA028_00395FF0 = 1;
    }
    old = D_001D4CE8_g_00395FF0;
    v = D_001D4CEC_00395FF0;
    if (v & 0x80) {
        D_001D4CE8_00395FF0 = 0x18;
        D_001D4CEC_00395FF0 = (v & -129) | 0x40;
        v = D_001D4CEC_00395FF0;
    }
    if (v & 0x100) {
        D_001D4CE8_00395FF0 = 0x16;
        D_001D4CEC_00395FF0 = (v & -257) | 0x40;
    }
    D_0032E338[D_001D4CE8_00395FF0]();
    D_001DA024_g_00395FF0 = D_001DA024 + 1;
    if (D_001D4CE8_00395FF0 != old) {
        D_001DA024 = 0;
    }
}
/* localdecomp:end func_00395FF0 */

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad1[0x150];
    s32 f164;
    s32 f168;
    u8 pad2[0x10];
    s32 f17c;
} S_142430;
extern S_142430 D_00142430;

extern s32 D_001D4CE8[];
/* localdecomp:start func_00396100 */
typedef struct { 
    u8 pad[0x10]; 
    s32 f10; 
    u8 pad2[0x150]; 
    s32 f164; 
    s32 f168; 
    u8 pad3[0x10]; 
    s32 f17C; 
} S_142430x;

extern S_142430x D_142430;
extern s32 D_001D4CE8_g;

void func_00396100(void) {
    S_142430x *p = &D_142430;
    D_001D4CE8_g = 4;
    p->f17C = 0;
    p->f10 = 0;
}
/* localdecomp:end func_00396100 */

/* localdecomp:start func_00396120 */
typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[0x168]; s32 f17C; } S_142430_00396120;
__asm__(".extern D_001D4CE8_00396122, 4");
__asm__(".extern D_001D4CEC_00396122, 4");
extern S_142430_00396120 D_142430_00396120;
extern s32 D_001D4CE8_00396122;
extern s32 D_001D4CEC_00396122;
extern s32 D_001D4CE8_00396120;
extern s32 D_001D4CEC_00396120;
void func_00396120(void) {
    if (D_142430_00396120.f17C == 0 && D_142430_00396120.f8 != 2) {
        D_001D4CE8_00396122 = 4;
        return;
    }
    if (D_142430_00396120.f17C != 0 && D_142430_00396120.f8 != 2) {
        D_142430_00396120.f17C = 0;
        D_001D4CE8_00396120 = 3;
        D_001D4CEC_00396122 = D_001D4CEC_00396122 | 1;
        return;
    }
    if (D_001D4CEC_00396120 & 4) {
        D_001D4CE8_00396122 = 0x1E;
        return;
    }
    if (D_001D4CEC_00396120 & 2) {
        D_001D4CE8_00396122 = 0x1D;
        return;
    }
    if (D_142430_00396120.f17C == 0 || (D_142430_00396120.f8 == 2 && D_142430_00396120.f10 != 0)) {
        D_001D4CE8_00396122 = 5;
        return;
    }
    if (D_001D4CEC_00396120 & 0x80) {
        D_001D4CE8_00396120 = 0x18;
        D_001D4CEC_00396122 = (D_001D4CEC_00396120 ^ 0x80) | 0x40;
        return;
    }
    if (D_001D4CEC_00396120 & 0x100) {
        D_001D4CE8_00396120 = 0x16;
        D_001D4CEC_00396122 = (D_001D4CEC_00396120 ^ 0x100) | 0x40;
        return;
    }
    if (D_001D4CEC_00396120 & 0x200) {
        D_001D4CEC_00396120 = D_001D4CEC_00396120 ^ 0x200;
        D_001D4CE8_00396120 = 0x1C;
    }
}
/* localdecomp:end func_00396120 */

/* localdecomp:start func_00396248 */
/* Ps2EeAs only uses $gp for this if it knows it is small before the use. */
__asm__(".extern D_001D6300_00396248, 4");
extern s32 D_001D4CE8_00396248;
extern s32 (*D_001D6300_00396248)();
typedef struct { u8 pad0[0x16C]; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00142430_00396248_00396248;
extern S_00142430_00396248_00396248 D_00142430_00396248[];

void func_00396248(void) {
    if (D_001D6300_00396248 != 0) {
        D_001D6300_00396248();
        D_001D6300_00396248 = 0;
    }
    if (D_00142430_00396248->f16C == 0) {
        D_00142430_00396248->f17C = 1;
    }
    D_001D4CE8_00396248 = 1;
}
/* localdecomp:end func_00396248 */

/* localdecomp:start func_00396298 */
extern u8 D_001D4CEC_00396298;
extern s32 D_001D4CE8_00396298;
void func_00396298(void) {
    if ((D_001D4CEC_00396298 ^ 1) & 1) {
        D_001D4CE8_00396298 = 4;
    }
}
/* localdecomp:end func_00396298 */

extern s32 D_001D4CE8[];
/* localdecomp:start func_003962C0 */

extern S_142430x D_142430;
extern s32 D_001D4CE8_g;

void func_003962C0(void) {
    S_142430x *p = &D_142430;
    p->f164 = -1;
    D_001D4CE8_g = 6;
    p->f168 = -1;
}
/* localdecomp:end func_003962C0 */

extern s32 D_001D4CE8[];
/* localdecomp:start func_003962E8 */
extern S_142430x D_142430;
extern s32 D_001D4CE8_g;
void func_003962E8(void) {
    S_142430x *p = &D_142430;
    p->f164 = -1;
    D_001D4CE8_g = 6;
    p->f168 = -1;
}
/* localdecomp:end func_003962E8 */

/* localdecomp:start func_00396310 */
extern s32 D_00142430_00396310[];
extern s32 D_001D4CE8_00396310;
extern s32 D_001D4CEC_00396310;
void func_00396310(void) {
    s32 *s = D_00142430_00396310;
    D_001D4CEC_00396310 &= ~0x20;
    if (s[2] == 2) {
        if (s[5] == 0) {
            D_001D4CE8_00396310 = 7;
            return;
        }
        if (s[4]) {
            s[4] = 0;
            D_001D4CE8_00396310 = 0xB;
            return;
        }
        D_001D4CE8_00396310 = 0xB;
    }
}
/* localdecomp:end func_00396310 */

/* localdecomp:start func_00396378 */
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC;
extern F_4CEC D_001D4CEC_f;
extern s32 D_00142438[];
extern u8 D_001D5BDD;
extern s32 D_001D4CE8_g;
void func_00396378(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8_g = 4;
        return;
    }
    if (D_001D5BDD != 0 || (*(s32 *)&D_001D4CEC_f & 0x12)) D_001D4CE8_g = 8;
}
/* localdecomp:end func_00396378 */

/* localdecomp:start func_003963C8 */
extern s32 D_00142430_003963C8[];
extern s32 D_001D4CE8_003963C8;
extern s32 D_001D4CEC_003963C8;
extern u8 D_001D5BDC;
extern void func_00397238(void);
void func_003963C8(void) {
    s32 v;
    if (D_00142430_003963C8[2] != 2) {
        D_001D4CE8_003963C8 = 4;
        return;
    }
    v = D_001D4CEC_003963C8;
    if (v & 0x20) {
        func_00397238();
        if (D_001D5BDC) D_001D4CE8_003963C8 = 0x1A;
        else D_001D4CE8_003963C8 = 7;
    } else if (v & 8) {
        D_001D4CEC_003963C8 = v ^ 8;
        D_001D4CE8_003963C8 = 9;
    }
}
/* localdecomp:end func_003963C8 */

/* localdecomp:start func_00396458 */
extern S_142430x D_142430;
extern s32 D_001D4CE8_g;
void func_00396458(void) {
    S_142430x *p = &D_142430;
    p->f10 = 0;
    if (p->f164 < 0) {
        p->f168 = 0;
        p->f164 = 3;
    }
    D_001D4CE8_g = 10;
}
/* localdecomp:end func_00396458 */

/* localdecomp:start func_00396488 */
typedef struct { u8 pad[0x15C]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396488;
extern S_396488 D_00142430_00396488[];
extern s32 D_001D4CEC_00396488;
extern s32 D_001D4CE8_00396488;
void func_00396488(void) {
    S_396488 *p = D_00142430_00396488;
    if (p->x15C == 2 && p->x164 < 0) {
        if (p->x16C) {
            D_001D4CE8_00396488 = 0x13;
            D_001D4CEC_00396488 |= 0x40;
        } else {
            D_001D4CE8_00396488 = 0x10;
        }
    }
}
/* localdecomp:end func_00396488 */

/* localdecomp:start func_003964E8 */
extern s32 D_00142438[];
extern s32 D_001D4CEC_003964E8;
extern s32 D_001D4CE8_003964E8;
void func_003964E8(void) {
    s32 v;
    if (D_00142438[0] != 2) {
        D_001D4CE8_003964E8 = 4;
        return;
    }
    v = D_001D4CEC_003964E8;
    if (v & 0x806) {
        D_001D4CE8_003964E8 = 0xC;
        return;
    }
    if (v & 0x200) {
        D_001D4CE8_003964E8 = 0x1C;
    }
}
/* localdecomp:end func_003964E8 */

/* localdecomp:start func_00396538 */
typedef struct { u32 b0:11; u32 f11:1; u32 rest:20; } S_396538;
extern s32 D_00142430_00396538[];
extern s32 D_001D4CE8_00396538;
extern union { s32 i; S_396538 b; } D_001D4CEC_00396538;
void func_00396538(void) {
    s32 *p = D_00142430_00396538;
    if (p[0x15C/4] == 2 && p[0x164/4] < 0) {
        p[0x164/4] = 7;
        p[4] = 0;
p[0x168/4] = 0;
        D_001D4CE8_00396538 = 0xD;
        D_001D4CEC_00396538.b.f11 = 0;
    }
}
/* localdecomp:end func_00396538 */

/* localdecomp:start func_00396590 */
typedef struct { u8 p0[8]; s32 f8; s32 fC; u8 p10[8]; s16 h18; u8 p1A[6]; s32 f20; u8 p24[0x15C - 0x24]; s32 f15C; u8 p160[4]; s32 f164; u8 p168[4]; s32 f16C; } S_396590;
extern S_396590 D_00142430_00396590[];
extern s32 D_001D4CE8_00396590;
void func_00396590(void) {
    S_396590 *s = D_00142430_00396590;
    if (s->f15C != 2) return;
    if (s->f164 >= 0) return;
    if (s->f16C != 0) {
        D_001D4CE8_00396590 = 0xE;
        return;
    }
    if (s->f8 != 2) {
        D_001D4CE8_00396590 = 4;
        return;
    }
    if (s->h18 == -2) {
        if (s->fC + s->f20 < 0x258) {
            D_001D4CE8_00396590 = 0x15;
            return;
        }
        D_001D4CE8_00396590 = 0xE;
        return;
    }
    if (s->h18 >= -1) {
        D_001D4CE8_00396590 = 0x12;
    }
}
/* localdecomp:end func_00396590 */

/* localdecomp:start func_00396628 */
typedef struct { u8 pad0[0x10]; s32 x10; u8 pad[0x15C-0x14]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396628;
extern S_396628 D_00142430_00396628[];
extern s32 D_001D4CEC_00396628;
extern s32 D_001D4CE8_00396628;
void func_00396628(void) {
    S_396628 *p = D_00142430_00396628;
    if (p->x15C == 2 && p->x164 < 0) {
        p->x164 = 7;
        p->x10 = 0;
        p->x168 = 0;
        D_001D4CEC_00396628 &= ~0x800;
        D_001D4CE8_00396628 = 0x20;
    }
}
/* localdecomp:end func_00396628 */

/* localdecomp:start func_00396680 */
typedef struct { u8 p0[8]; s32 f8; s32 fC; u8 p10[8]; s16 f18; u8 p1A[2]; s32 f1C; s32 f20; u8 p24[0x138]; s32 f15C; u8 p160[4]; s32 f164; u8 p168[4]; s32 f16C; } S_142430_00396680;
__asm__(".extern D_001D4CEC_00396682, 4");
__asm__(".extern D_001D62F0_00396680, 4");
__asm__(".extern D_001D6304_00396680, 4");
extern S_142430_00396680 D_142430_00396680;
extern s32 D_001D4CEC_00396682;
extern s32 D_001D4CEC_00396680;
extern s32 D_001D4CE8_00396680;
extern void (*D_001D6304_00396680)(void);
extern s32 D_001D62F0_00396680;
void func_00396680(void) {
    s32 c;
    s32 a;
    s32 u;
    s32 w;
    a = D_142430_00396680.f15C;
    if (a == 2 && D_142430_00396680.f164 < 0) {
        if (D_142430_00396680.f16C != 0) {
            u = D_001D4CEC_00396682;
            c = 0x18; D_001D4CE8_00396680 = c; D_001D4CEC_00396682 = u | 0x40;
            goto cb;
        }
        if (D_142430_00396680.f8 != a) {
            D_001D4CE8_00396680 = 4;
        } else {
            a = D_142430_00396680.f18;
            if (a == -2) {
                if (D_142430_00396680.fC + D_142430_00396680.f20 >= 0x258) {
                    u = D_001D4CEC_00396680;
                    c = 0x18; D_001D4CE8_00396680 = c; D_001D4CEC_00396682 = u | 0x40;
                } else {
                    D_001D4CE8_00396680 = 0x15;
                }
            } else if (a < -1) {
            } else if (a != -1) {
                D_001D4CE8_00396680 = 0x12;
            } else {
                w = D_001D4CEC_00396680;
                if (w & 0x1000) {
                    s32 t = *(u16 *)&D_001D62F0_00396680;
                    D_001D62F0_00396680 = a;
                    D_142430_00396680.f18 = t;
                    D_001D4CEC_00396680 = w & ~0x1000;
                }
                D_001D4CE8_00396680 = 0x12;
            }
        }
cb:
        if (D_001D6304_00396680 != 0) {
            D_001D6304_00396680();
            D_001D6304_00396680 = 0;
        }
    }
}
/* localdecomp:end func_00396680 */

/* localdecomp:start func_00396780 */
extern s32 D_00142438[];
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_g;
void func_00396780(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8_g = 4;
        return;
    }
    if (D_001D4CEC_g & 0x12) D_001D4CE8_g = 15;
}
/* localdecomp:end func_00396780 */

/* localdecomp:start func_003967C0 */
extern s32 D_00142438[];
extern s32 D_001D4CEC_003967C0;
extern s32 D_001D4CE8_003967C0;
extern u8 D_001D5BDC;
void func_003967C0(void) {
    s32 f;
    if (D_00142438[0] != 2) { D_001D4CE8_003967C0 = 4; return; }
    f = D_001D4CEC_003967C0;
    if (f & 0x20) {
        D_001D4CEC_003967C0 = f ^ 0x20;
        if (D_001D5BDC != 0) { D_001D4CE8_003967C0 = 0x1B; } else { D_001D4CE8_003967C0 = 0xE; }
        return;
    }
    if (f & 0x2000) { D_001D4CE8_003967C0 = 0x10; }
}
/* localdecomp:end func_003967C0 */

/* localdecomp:start func_00396830 */
typedef struct { u8 pad[0x15C]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396830;
extern S_396830 D_00142430_00396830[];
extern s32 D_001D4CEC_00396830;
extern s32 D_001D4CE8_00396830;
void func_00396830(void) {
    S_396830 *p = D_00142430_00396830;
    if (p->x15C == 2 && p->x164 < 0) {
        p->x164 = 9;
        D_001D4CEC_00396830 &= ~2;
        D_001D4CEC_00396830 &= ~0x10;
        p->x168 = 0;
        D_001D4CE8_00396830 = 0x11;
    }
}
/* localdecomp:end func_00396830 */

/* localdecomp:start func_00396890 */
typedef struct { u8 pad[0x18]; s16 f18; u8 padA[0x12E]; s32 f148; u8 padB[0x10]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396890;
extern S_396890 D_142430_00396890;
extern s32 D_001D4CEC_00396890;
extern s32 D_001D4CE8_00396890;
void func_00396890(void) {
    S_396890 *s = &D_142430_00396890;
    if (s->f15C == 2 && s->f164 < 0) {
        if (s->f16C != 0) {
            D_001D4CE8_00396890 = 0x14;
            D_001D4CEC_00396890 |= 0x40;
        } else {
            s->f148 = 0;
            s->f18 = 0;
            D_001D4CE8_00396890 = 0x1F;
        }
    }
}
/* localdecomp:end func_00396890 */

/* localdecomp:start func_003968F8 */
__asm__(".extern D_001D6308, 2");
__asm__(".extern D_001D62F4_003968F8, 4");
typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x15C - 0x1A]; s32 x15C; s32 pad4; s32 x164; } S_3968F8;
extern S_3968F8 D_00142430_003968F8[];
extern void (*D_001D62F4_003968F8)(void);
extern u16 D_001D6308;
extern s32 D_001D4CE8_003968F8;
extern s32 D_001D4CEC_003968F8;
extern void func_00397238(void);
void func_003968F8(void) {
    S_3968F8 *p = D_00142430_003968F8;
    if (p->x15C == 2 && p->x164 < 0) {
        if (*(s32 *)((u8 *)p + *(s32 *)&D_001D6308 * 0x1C + 0x30) == -1 || (D_001D4CEC_003968F8 & 0x6000) != 0) {
            func_00397238();
            D_001D4CEC_003968F8 &= ~0x4000;
            if (D_001D62F4_003968F8) {
                D_001D62F4_003968F8();
                D_001D62F4_003968F8 = 0;
            }
            p->h18 = D_001D6308;
            D_001D4CE8_003968F8 = 0x19;
        } else {
            D_001D4CE8_003968F8 = 0x21;
        }
    }
}
/* localdecomp:end func_003968F8 */

/* localdecomp:start func_003969B8 */
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_001D62FC, 4");
__asm__(".extern D_001D6308, 2");
typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x148 - 0x1A]; s32 x148; u8 pad3[0x10]; s32 x15C; s32 pad4; s32 x164; } S_3969B8;
extern S_3969B8 D_00142430_003969B8[];
extern void (*D_001D62FC)(void);
extern u16 D_001D6308;
extern s32 D_001D4CE8_003969B8;
void func_003969B8(void) {
    S_3969B8 *p = D_00142430_003969B8;
    if (p->x15C == 2 && p->x164 < 0) {
        if (D_001D62FC) {
            D_001D62FC();
            D_001D62FC = 0;
        }
        p->h18 = D_001D6308;
        p->x148 = 0;
        D_001D4CE8_003969B8 = 0x17;
    }
}
/* localdecomp:end func_003969B8 */

/* localdecomp:start func_00396A28 */
typedef struct { u8 pad[8]; s32 f8; u8 pad2[0x170]; s32 f17C; } S_142430_396A28;
extern S_142430_396A28 D_142430_00396A28;
extern s32 D_001D4CE8_00396A28;
extern s32 D_001D4CEC_00396A28;
void func_00396A28(void) {
    s32 f = D_001D4CEC_00396A28;
    if (f & 4) D_001D4CE8_00396A28 = 0x1E;
    if (f & 2) D_001D4CE8_00396A28 = 0x1D;
    if (f & 0x800) D_001D4CE8_00396A28 = 0xC;
    if (f & 0x80) {
        D_001D4CE8_00396A28 = 0x18;
        D_001D4CEC_00396A28 = (f ^ 0x80) | 0x40;
        return;
    }
    if (f & 0x100) {
        D_001D4CE8_00396A28 = 0x16;
        D_001D4CEC_00396A28 = (f ^ 0x100) | 0x40;
        return;
    }
    if (D_142430_00396A28.f8 != 2) {
        D_001D4CE8_00396A28 = 4;
        return;
    }
    if (D_142430_00396A28.f17C) D_001D4CE8_00396A28 = 1;
}
/* localdecomp:end func_00396A28 */

/* localdecomp:start func_00396AE0 */
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];

void func_00396AE0(void) {
    if (!(D_001D4CEC[0] & 0x40)) D_001D4CE8[0] = 4;
}
/* localdecomp:end func_00396AE0 */

/* localdecomp:start func_00396B08 */
extern void (*D_001D6304)(void);
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];
void func_00396B08(void) {
    if (D_001D6304 != 0) {
        D_001D6304();
        D_001D6304 = 0;
    }
    if (!(D_001D4CEC[0] & 0x40)) D_001D4CE8[0] = 4;
}
/* localdecomp:end func_00396B08 */


/* localdecomp:start func_00396B50 */
extern s32 D_00142438[];
extern s32 D_001D4CE8_00396B50;
void func_00396B50(void) {
    if (D_00142438[0] != 2) D_001D4CE8_00396B50 = 4;
}
/* localdecomp:end func_00396B50 */

/* localdecomp:start func_00396B78 */
extern void (*D_001D6300)(void);
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];
void func_00396B78(void) {
    if (D_001D6300 != 0) {
        D_001D6300();
        D_001D6300 = 0;
    }
    if (!(D_001D4CEC[0] & 0x40)) D_001D4CE8[0] = 4;
}
/* localdecomp:end func_00396B78 */

/* localdecomp:start func_00396BC0 */
typedef struct { u8 pad[0x15C]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396BC0;
extern S_396BC0 D_142430_00396BC0;
extern s32 D_001D4CEC_00396BC0;
extern s32 D_001D4CE8_00396BC0;
void func_00396BC0(void) {
    S_396BC0 *s = &D_142430_00396BC0;
    D_001D4CEC_00396BC0 &= ~4;
    if (s->f15C == 2 && s->f164 < 0) {
        if (s->f16C != 0) {
            D_001D4CEC_00396BC0 |= 0x40;
            D_001D4CE8_00396BC0 = 0x16;
        } else {
            D_001D4CE8_00396BC0 = s->f15C;
        }
    }
}
/* localdecomp:end func_00396BC0 */


/* localdecomp:start func_00396C20 */
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];

void func_00396C20(void) {
    if (!(D_001D4CEC[0] & 0x40)) D_001D4CE8[0] = 4;
}
/* localdecomp:end func_00396C20 */

/* localdecomp:start func_00396C48 */
__asm__(".extern D_001D62F8, 4");
typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[0x15C - 0x28]; s32 f15C; s32 pad160; s32 f164; s32 pad168; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00396C48;
extern S_00396C48 D_00142430_00396C48[];
extern void (*D_001D62F8)();
extern s32 D_001D4CE8_00396C48;
extern s32 D_001D4CEC_00396C48;
void func_00396C48(void) {
    S_00396C48 *p = D_00142430_00396C48;
    s32 v = D_001D4CEC_00396C48 & ~2;
    D_001D4CEC_00396C48 = v;
    if (p->f15C == 2) {
        if (p->f164 < 0) {
            if (p->f16C != 0 || p->f24 != 0) {
                p->f17C = 0;
                D_001D4CEC_00396C48 = v | 0x440;
                D_001D4CE8_00396C48 = 0x18;
            } else {
                p->f17C = 1;
                D_001D4CE8_00396C48 = 1;
            }
            if (D_001D62F8 != 0) {
                D_001D62F8();
                D_001D62F8 = 0;
            }
        }
    }
}
/* localdecomp:end func_00396C48 */

/* localdecomp:start func_00396CE8 */
typedef struct { u8 p0[8]; s32 f8; u8 p1[4]; s32 f10; u8 p2[0x15C-0x14]; s32 f15C; u8 p3[4]; s32 f164; u8 p4[4]; s32 f16C; u8 p5[0x17C-0x170]; s32 f17C; } S_396CE8;
extern S_396CE8 D_142430_00396CE8[];
extern s32 D_001D4CE8_00396CE8;
extern s32 D_001D4CEC_00396CE8;
#define P D_142430_00396CE8[0]
void func_00396CE8(void) {
    if (P.f15C != 2) return; if (P.f164 >= 0) return; if (P.f16C != 0 || (P.f8 == 2 && P.f10 != 0)) { P.f17C = 0; D_001D4CE8_00396CE8 = 3; D_001D4CEC_00396CE8 = (D_001D4CEC_00396CE8 & 0x40) | 1; } else { P.f17C = 1; D_001D4CE8_00396CE8 = 1; }
}
/* localdecomp:end func_00396CE8 */

/* localdecomp:start func_00396D70 */
typedef struct { u32 b0:5; u32 f5:1; u32 b6:7; u32 f13:1; u32 rest:18; } S_396D70;
extern s32 D_00142438[];
extern s32 D_001D4CE8_00396D70;
extern union { s32 i; S_396D70 b; } D_001D4CEC_00396D70;
void func_00396D70(void) {
    if (D_00142438[0] != 2) { D_001D4CE8_00396D70 = 4; return; }
    if (D_001D4CEC_00396D70.i & 0x2020) {
        D_001D4CE8_00396D70 = 7;
        D_001D4CEC_00396D70.b.f5 = 0;
        D_001D4CEC_00396D70.b.f13 = 0;
    }
}
/* localdecomp:end func_00396D70 */

/* localdecomp:start func_00396DC8 */
typedef struct { char pad0[8]; s32 x8; } S_396DC8;
extern S_396DC8 D_00142430_00396DC8;
extern s32 D_001D4CE8_00396DC8;
extern s32 D_001D4CEC_00396DC8;
void func_00396DC8(void) {
    s32 v;
    if (D_00142430_00396DC8.x8 != 2) { D_001D4CE8_00396DC8 = 4; return; }
    if (D_001D4CEC_00396DC8 & 0x2020) {
        D_001D4CE8_00396DC8 = 0xE;
        D_001D4CEC_00396DC8 &= ~0x20;
        D_001D4CEC_00396DC8 &= ~0x2000;
    }
}
/* localdecomp:end func_00396DC8 */

/* localdecomp:start func_00396E20 */
extern s32 D_00142438[];
extern u32 D_001D4CEC_00396E20;
extern s32 D_001D4CE8_00396E20;
extern void func_00397238(void);
void func_00396E20(void) {
    s32 v;
    if (D_00142438[0] != 2) {
        v = 4;
    } else {
        u32 f = D_001D4CEC_00396E20;
        if (f & 0x20) {
            func_00397238();
            v = 0x12;
        } else if (f & 0x2000) {
            v = 0x1D;
        } else {
            return;
        }
    }
    D_001D4CE8_00396E20 = v;
}
/* localdecomp:end func_00396E20 */

/* localdecomp:start func_00396E80 */
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x148 - 0x14]; s32 f148; } S_396E80;
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC_396E80;
extern S_396E80 D_00142430_00396E80[];
__asm__(".extern D_001D62FC_00396E80, 4");
__asm__(".extern D_001D6300_00396E80, 4");
__asm__(".extern D_001D62F4, 4");
__asm__(".extern D_001D62F8_00396E80, 4");
__asm__(".extern D_001D6304_00396E80, 4");
__asm__(".extern D_001DA020, 1");
extern s32 D_001D62FC_00396E80;
extern s32 D_001D6300_00396E80;
extern s32 D_001D62F4;
extern s32 D_001D62F8_00396E80;
extern s32 D_001D6304_00396E80;
extern s8 D_001DA020;
extern F_4CEC_396E80 D_001D4CEC_f_396E80;
extern s8 D_001DA028;
extern s32 func_00397058();
extern void func_00397238(void);
s32 func_00396E80(s32 a, s32 b) {
    s32 r = func_00397058(a);
    if (r) {
        S_396E80 *p = D_00142430_00396E80;
        D_001D4CEC_f_396E80.b4 = 1;
        D_001D4CEC_f_396E80.b2 = 0;
        D_001D4CEC_f_396E80.b1 = 0;
        D_001D4CEC_f_396E80.b6 = 0;
        D_001D6304_00396E80 = b;
        p->f148 = 0;
        p->f10 = 0;
        D_001D62F4 = 0;
        D_001D62F8_00396E80 = 0;
        D_001D62FC_00396E80 = 0;
        D_001D6300_00396E80 = 0;
        D_001DA028 = 0;
        D_001DA020 = 0;
        func_00397238();
    }
    return r;
}
/* localdecomp:end func_00396E80 */

/* localdecomp:start func_00396F18 */
__asm__(".extern D_001D62F4, 4");
__asm__(".extern D_001D62F8_00396F18, 4");
__asm__(".extern D_001D6308_00396F18, 4");
__asm__(".extern D_001D62FC_00396F18, 4");
__asm__(".extern D_001D6300_00396F18, 4");
__asm__(".extern D_001D6304_00396F18, 4");
__asm__(".extern D_001DA020, 1");
typedef struct { u8 pad[0x10]; s32 x10; u8 padA[0x134]; s32 x148; } S_a;
extern void func_00397238(void);
extern s32 D_001D62F4;
extern s32 D_001D62F8_00396F18;
extern s32 D_001D6308_00396F18;
extern s32 D_001D62FC_00396F18;
extern s32 D_001D6300_00396F18;
extern s32 D_001D6304_00396F18;
extern s8 D_001DA020;
extern s32 D_001D4CEC_00396F18;
extern s8 D_001DA028;
extern S_a D_00142430_00396F18[];
void func_00396F18(s32 arg0, s32 arg1, s32 arg2) {
    S_a *p = D_00142430_00396F18;
    s32 x;
    D_001D62F4 = arg0;
    D_001D62F8_00396F18 = arg2;
    D_001D6308_00396F18 = arg1;
    p->x148 = 0;
    D_001D62FC_00396F18 = 0;
    D_001D6300_00396F18 = 0;
    D_001D6304_00396F18 = 0;
    D_001DA028 = 0;
    D_001DA020 = 0;
    func_00397238();
    p->x10 = 0;
    D_001D4CEC_00396F18 &= ~4; D_001D4CEC_00396F18 |= 2; D_001D4CEC_00396F18 &= ~0x40; D_001D4CEC_00396F18 &= ~0x10; D_001D4CEC_00396F18 &= ~0x4000;
}
/* localdecomp:end func_00396F18 */

/* localdecomp:start func_00396FA0 */
extern void func_00396F18();
extern s32 D_001D4CEC_g;
void func_00396FA0(void *a, s32 b, void *c) {
    func_00396F18(a, b, c);
    D_001D4CEC_g |= 0x4000;
}
/* localdecomp:end func_00396FA0 */

/* localdecomp:start func_00396FD0 */
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x148 - 0x14]; s32 f148; } S_396FD0;
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC_396FD0;
extern S_396FD0 D_00142430_00396FD0[];
__asm__(".extern D_001D62FC_00396FD0, 4");
__asm__(".extern D_001D6300_00396FD0, 4");
__asm__(".extern D_001D6308_00396FD0, 4");
__asm__(".extern D_001D62F4, 4");
__asm__(".extern D_001D62F8_00396FD0, 4");
__asm__(".extern D_001D6304_00396FD0, 4");
__asm__(".extern D_001DA028, 1");
extern s32 D_001D62FC_00396FD0;
extern s32 D_001D6300_00396FD0;
extern s32 D_001D6308_00396FD0;
extern s32 D_001D62F4;
extern s32 D_001D62F8_00396FD0;
extern s32 D_001D6304_00396FD0;
extern s8 D_001DA028;
extern F_4CEC_396FD0 D_001D4CEC_f_396FD0;
extern s8 D_001DA020;
extern void func_00397238(void);
void func_00396FD0(s32 a, s32 b, s32 c) {
    S_396FD0 *p = D_00142430_00396FD0;
    D_001D62FC_00396FD0 = a;
    D_001D6300_00396FD0 = c;
    p->f148 = 0;
    p->f10 = 0;
    D_001D6308_00396FD0 = b;
    D_001D62F4 = 0;
    D_001D62F8_00396FD0 = 0;
    D_001D6304_00396FD0 = 0;
    D_001DA028 = 0;
    func_00397238();
    D_001DA020 = 1;
    D_001D4CEC_f_396FD0.b2 = 1;
    D_001D4CEC_f_396FD0.b1 = 0;
    D_001D4CEC_f_396FD0.b6 = 0;
    D_001D4CEC_f_396FD0.b4 = 0;
    D_001D4CEC_f_396FD0.b14 = 0;
}
/* localdecomp:end func_00396FD0 */

/* localdecomp:start func_00397058 */
extern s32 D_001D4CEC_g;
extern s32 D_001D62F0;
s32 func_00397058(u32 a) {
    if (a >= 4) return 0;
    D_001D62F0 = a;
    D_001D4CEC_g |= 0x1000;
    return 1;
}
/* localdecomp:end func_00397058 */

extern s32 D_001D4CEC[];
extern s32 D_00142578[];
/* localdecomp:start func_00397080 */
extern s32 D_001D4CEC_00397080;
extern s32 D_00142578[];
void func_00397080(void) {
    D_00142578[0] = 0;
    D_001D4CEC_00397080 |= 0x800;
}
/* localdecomp:end func_00397080 */

/* localdecomp:start func_003970A0 */
extern s32 D_001D4CEC_003970A0;
void func_003970A0(void) {
    D_001D4CEC_003970A0 |= 0x2000;
}
/* localdecomp:end func_003970A0 */

/* localdecomp:start func_003970B8 */
extern u8 D_001DA028_g;
u8 func_003970B8(void) {
    u8 v = D_001DA028_g;
    D_001DA028_g = 0;
    return v;
}
/* localdecomp:end func_003970B8 */

LINKER_REMNANT("asm/remnants", func_003970C8);

/* localdecomp:start func_003970D0 */
extern S_142430 D_00142430;
void func_003970D0(s16 v) {
    u8 *b = (u8 *)&D_00142430;
    s32 t = *(s32 *)(b + 0x164);
    *(s16 *)(b + 0x18) = v;
    *(s32 *)(b + 0x148) = 0;
    if (t < 0) {
        *(s32 *)(b + 0x168) = 0;
        *(s32 *)(b + 0x164) = 0xD;
    }
}
/* localdecomp:end func_003970D0 */

/* localdecomp:start func_00397100 */
__asm__(".extern D_001D6308, 2");
typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x148 - 0x1A]; s32 f148; u8 p14C[0x18]; s32 f164; s32 f168; u8 p16C[8]; s32 f174; } S_00397100;
extern S_00397100 D_00142430_00397100[];
extern u16 D_001D6308;
extern s32 D_001D545C_00397100;
extern s32 D_001D4BE0_00397100;
extern u8 D_001A9318_00397100[];
extern void func_12BE28();
extern void func_13AD58();
extern void func_0039AAF0();
extern void func_00399660();
void func_00397100(s32 a, s32 b) {
    S_00397100 *p = D_00142430_00397100;
    func_12BE28(&D_001D4BE0_00397100);
    func_13AD58(&D_001D4BE0_00397100);
    func_0039AAF0(D_001A9318_00397100 + (D_001D545C_00397100 << 11));
    func_00399660(a);
    p->f174 = a;
    p->h18 = D_001D6308;
    p->f148 = 0;
    if (b == -1) {
        *(s32 *)((u8 *)p + *(s32 *)&D_001D6308 * 0x1C + 0x30) = D_001D545C_00397100;
    } else {
        *(s32 *)((u8 *)p + *(s32 *)&D_001D6308 * 0x1C + 0x30) = b;
    }
    if (D_00142430_00397100->f164 < 0) {
        D_00142430_00397100->f168 = 0;
        D_00142430_00397100->f164 = 0x13;
    }
}
/* localdecomp:end func_00397100 */

extern s32 D_001D4CEC[];
/* localdecomp:start func_003971E8 */
extern F_4CEC D_001D4CEC_f;
void func_003971E8(void) {
    D_001D4CEC_f.b5 = 1;
}
/* localdecomp:end func_003971E8 */

/* localdecomp:start func_00397200 */
extern F_4CEC D_001D4CEC_f;
void func_00397200(void) {
    D_001D4CEC_f.b1 = 0;
    D_001D4CEC_f.b2 = 0;
    D_001D4CEC_f.b12 = 0;
    D_001D4CEC_f.b3 = 0;
    D_001D4CEC_f.b4 = 0;
}
/* localdecomp:end func_00397200 */

extern s32 D_001D4CEC[];
/* localdecomp:start func_00397238 */
extern F_4CEC D_001D4CEC_f;
void func_00397238(void) {
    D_001D4CEC_f.b5 = 0;
    D_001D4CEC_f.b13 = 0;
}
/* localdecomp:end func_00397238 */

extern s32 D_001D4CEC[];
/* localdecomp:start func_00397258 */
extern s32 D_001D4CEC[];

s32 func_00397258(void) {
    return (D_001D4CEC[0] >> 6) & 1;
}
/* localdecomp:end func_00397258 */

extern s32 D_001D4CEC[];
/* localdecomp:start func_00397270 */
extern F_4CEC D_001D4CEC_f;
void func_00397270(void) {
    D_001D4CEC_f.b6 = 0;
}
/* localdecomp:end func_00397270 */

LINKER_REMNANT("asm/remnants", func_00397288);

/* localdecomp:start func_003972A0 */
extern u8 D_0032E3C8[];
extern u8 D_0032E658[];
extern s32 func_00399710();
extern void func_00399A00();
extern void func_00399F40();
void func_003972A0(u8 *arg) {
    s32 a, b, t, i;
    u8 *q;
    a = func_00399710(D_0032E3C8);
    b = func_00399710(D_0032E658);
    t = *(s32 *)arg;
    if (t == a) {
        if (*(s32 *)(arg + 4) == b) {
            arg += 8;
            q = arg + t;
            func_00399A00(arg, q, 0, D_0032E3C8);
            arg = q;
            for (i = 0; i < 0x25; i++) {
                func_00399A00(arg, arg + b, i, D_0032E658);
                arg += b;
            }
            func_00399F40();
        }
    }
}
/* localdecomp:end func_003972A0 */

/* localdecomp:start func_00397380 */
typedef struct { u8 pad[0x64C]; s32 f64C; u8 p650[0x10]; s32 f660; s32 f664; } S_160C40_00397380;
typedef struct { u8 pad[0x18]; s16 f18; u8 p1A[0x162]; s32 f17C; } S_142430_00397380;
typedef struct { u8 pad[0x18]; s32 f18; u8 p1C[0x14]; s32 f30; } S_16C580_00397380;
extern S_160C40_00397380 D_160C40_00397380;
extern S_142430_00397380 D_142430_00397380;
extern S_16C580_00397380 D_16C580_00397380;
extern u8 D_00143950_00397380[];
extern s32 D_001D545C_00397380;
extern s32 D_001D4B60_00397380, D_001D4CEC_00397380, D_001D4B90_00397380, D_001D4BA0_00397380;
extern void func_0038E6D0();
extern s32 func_0039D6C8();
extern s32 func_0039D668();
extern void func_00388550();
extern void func_003972A0();
void func_00397380(void) {
    u8 buf[0xBC];
    u8 *p;
    u8 *q;
    func_0038E6D0(D_160C40_00397380.f664 << 11, &p);
    func_0039D6C8(1);
    func_0039D668(p, D_160C40_00397380.f660 + D_160C40_00397380.f64C, D_160C40_00397380.f664);
    q = p + *(s32 *)(p + 0x10);
    func_00388550(buf, D_00143950_00397380, 0xBC);
    func_003972A0(q);
    func_00388550(D_00143950_00397380, buf, 0xBC);
    D_001D545C_00397380 = 1;
    if (D_142430_00397380.f17C != 0) D_142430_00397380.f17C = 0;
    if (D_142430_00397380.f18 >= 0) D_142430_00397380.f18 = -1;
    D_001D4CEC_00397380 &= ~0x200;
    D_001D4B60_00397380 = -1;
    D_001D4B90_00397380 = -1;
    D_001D4BA0_00397380 = -1;
    D_16C580_00397380.f30 = -1;
    D_16C580_00397380.f18 = -1;
}
/* localdecomp:end func_00397380 */

/* localdecomp:start func_00397490 */
typedef struct {
    s32 port;  s32 slot;  s32 type;  s32 free;
    s32 f10;   s32 f14;   s16 f18;   s16 f1A;   s32 f1C;
    s32 f20;   s32 f24;   s32 f28;   s32 f2C;   s32 f30;
    u8 p34[0x18]; s32 f4C; u8 p50[0x18]; s32 f68; u8 p6C[0x18]; s32 f84; u8 p88[0x18];
} MC_397490;
typedef struct {
    MC_397490 c[2];
    s32 f140, f144, f148, f14C, f150, f154, f158, f15C, f160, f164, f168, f16C, f170, f174, f178, f17C, f180, f184, f188;
} S_397490;
typedef struct { u8 p0[0x10]; s32 size; u8 p14[0xC]; u8 name[0x20]; } DE_397490;
typedef struct { s32 type; s32 size; u8 d[0x40]; } E_397490;
typedef struct { u8 p0[0x48]; s32 f48; } S_142660_397490;
extern S_397490 D_142430_00397490;
extern S_142660_397490 D_142660;
extern DE_397490 D_00228D40[];
extern u8 D_00228D60[];
extern char D_001D5378[], D_001D5390[], D_001D53A8[], D_001D53BD[], D_001D53C8[], D_001D53DD[], D_001D53E8[];
extern char D_001D53FD[], D_001D5418[], D_001D542D[], D_001D5438[];
extern u32 D_001D545C;
extern char D_001D6348[], D_001D6350[], D_001D6358[], D_001D6360[], D_001D6380[], D_001D63A0[];
extern char D_001D63C0[], D_001D63E0[], D_001D6400[], D_001D6420[];
__asm__(".extern D_001D6318, 4");
extern s32 D_001D6318;
extern s16 D_001CCFD4[];
extern u8 D_001C5BD0[], D_001C5BD8[], D_001CBBD0[];
extern s32 func_12E2E0(s32, s32 *, s32 *);
extern s32 func_12E400(s32, s32, s32 *, s32 *, s32 *);
extern s32 func_12E6D8(s32, s32);
extern s32 func_12E8D8(s32, s32);
extern s32 func_12E580(s32, s32, char *, s32, s32, void *);
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_11B610(u8 *, char *);
extern s32 func_11B9A0(u8 *, char *, s32);
extern void func_11B754();
extern s32 func_11B2E8();
extern s32 func_12DCA0(s32, s32, char *, s32);
extern s32 func_12E050(s32, void *, s32);
extern s32 func_12E168(s32, void *, s32);
extern s32 func_12DE00(s32);
extern s32 func_12DDC8(s32, s32, char *);
extern s32 func_12E7A8(s32, s32, char *);
extern s32 func_12DEC0(s32, s32, s32);
extern s32 func_0039D510(s32, s32, s32);
extern s32 func_00399830();
extern s32 func_003997F0();
extern void func_00399948();

void func_00397490(void) {
    s32 found[4];
    char path[0x40];
    s32 t;

    if (D_142430_00397490.f154 != 0) {
        D_142430_00397490.f154 = func_12E2E0(1, &D_142430_00397490.f140, &D_142430_00397490.f144) == 0;
        return;
    }
    D_142430_00397490.f154 = 1;
    switch (D_142430_00397490.f15C) {
    case 0:
        if ((u32)D_142430_00397490.f180 >= 2) D_142430_00397490.f180 = 0;
        if (func_12E400(D_142430_00397490.c[D_142430_00397490.f180].port, D_142430_00397490.c[D_142430_00397490.f180].slot, &D_142430_00397490.c[D_142430_00397490.f180].type, &D_142430_00397490.c[D_142430_00397490.f180].free, &D_142430_00397490.c[D_142430_00397490.f180].f14) == 0) D_142430_00397490.f15C = 1;
        break;
    case 1:
        if (D_142430_00397490.f144 != 0) {
            D_142430_00397490.c[D_142430_00397490.f180].f18 = -4;
            D_142430_00397490.c[D_142430_00397490.f180].f10 = D_142430_00397490.f144;
            D_142430_00397490.c[D_142430_00397490.f180].f24 = -1;
            D_142430_00397490.c[D_142430_00397490.f180].f20 = 0;
            D_142430_00397490.c[D_142430_00397490.f180].f30 = -1;
            D_142430_00397490.c[D_142430_00397490.f180].f4C = -1;
            D_142430_00397490.c[D_142430_00397490.f180].f68 = -1;
            D_142430_00397490.c[D_142430_00397490.f180].f84 = -1;
            D_142430_00397490.c[D_142430_00397490.f180].f1C = 0;
        }
        D_142430_00397490.f180++;
        if (D_142430_00397490.f168 < D_142430_00397490.f180 && D_142430_00397490.f164 >= 0) {
            D_142430_00397490.f15C = 2;
            if (D_142430_00397490.f168 >= 0) {
                if (D_142430_00397490.c[D_142430_00397490.f168].f10 == 0 || D_142430_00397490.f164 == 0x18) {
                    D_142430_00397490.f14C = D_142430_00397490.f168;
                    D_142430_00397490.f15C = D_142430_00397490.f164;
                    D_142430_00397490.f16C = 0;
                } else {
                    D_142430_00397490.f16C = 0x271A;
                }
            } else {
                D_142430_00397490.f16C = 0x271A;
            }
            D_142430_00397490.f164 = -1;
            D_142430_00397490.f168 = -1;
        } else {
            if (D_142430_00397490.f180 < 2) D_142430_00397490.f15C = 0; else D_142430_00397490.f15C = 2;
            D_142430_00397490.f154 = 0;
        }
        break;
    case 2:
        D_142430_00397490.f184++;
        if (D_142430_00397490.f164 >= 0 || D_142430_00397490.f184 > 10) {
            D_142430_00397490.f184 = 0;
            D_142430_00397490.f180 = 0;
            D_142430_00397490.f15C = 0;
        }
        D_142430_00397490.f154 = 0;
        break;
    case 3:
        if (D_142430_00397490.c[D_142430_00397490.f14C].f14 == 0) {
            if (func_12E6D8(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot) == 0) D_142430_00397490.f15C = 4;
        } else {
            D_142430_00397490.f154 = 0;
            D_142430_00397490.f15C = 2;
        }
        break;
    case 4:
        if (D_142430_00397490.f144 != 0) {
            D_142430_00397490.f16C = 1;
            D_142430_00397490.f170 = D_142430_00397490.f14C;
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            D_142430_00397490.f154 = 0;
            break;
        }
        D_142430_00397490.f15C = 0;
        D_142430_00397490.f14C = 0;
        D_142430_00397490.f154 = 0;
        break;
    case 5:
        if (D_142430_00397490.c[D_142430_00397490.f14C].f14 == 0) {
            if (func_12E8D8(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot) == 0) D_142430_00397490.f15C = 6;
        } else {
            D_142430_00397490.f154 = 0;
            D_142430_00397490.f15C = 2;
        }
        break;
    case 6:
        if (D_142430_00397490.f144 != 0) {
            D_142430_00397490.f16C = 2;
            D_142430_00397490.f170 = D_142430_00397490.f14C;
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            D_142430_00397490.f154 = 0;
            break;
        }
        D_142430_00397490.f15C = 0;
        D_142430_00397490.f14C = 0;
        D_142430_00397490.f154 = 0;
        break;
    case 7:
        if (func_12E580(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, D_001D5390, 0, 0xB, D_00228D40) == 0) {
            D_142430_00397490.f160 = 0;
            D_142430_00397490.f15C = 8;
        }
        break;
    case 8:
        switch (D_142430_00397490.f160) {
        case 0:
            if (D_142430_00397490.f144 > 0) {
                s32 i, total, fa, fb, fc, fd, n, total2;
                fa = 0;
                func_0011A264((s32)found, 0, 0x10);
                fb = 0;
                fc = 0;
                fd = 0;
                i = 0;
                total = 0;
                for (; i < D_142430_00397490.f144; i++) {
                    DE_397490 *de = &D_00228D40[i];
                    total += (u32)(de->size + 0x3FF) >> 10;
                    if (func_11B610(D_00228D40[i].name, D_001D53BD) == 0) fa = 1;
                    if (func_11B610(D_00228D40[i].name, D_001D53DD) == 0) fb = 1;
                    if (func_11B610(D_00228D40[i].name, D_001D53FD) == 0) fc = 1;
                    if (func_11B610(D_00228D40[i].name, D_001D542D) == 0) fd = 1;
                    if (func_11B9A0(D_00228D40[i].name, D_001D6348, 4) == 0 && func_11B9A0(D_00228D40[i].name + 5, D_001D6350, 4) == 0) {
                        n = de->name[4] - '0';
                        if (n >= 0) {
                            if (n < 4) found[n] = 1;
                        }
                    }
                }
                total2 = total + 1;
                total = total2 + (D_142430_00397490.f144 + 1) / 2;
                if ((total == 0x257 || total == 0x258) && D_142430_00397490.f144 == 10 && fa && fb && fc && fd
                    && found[0] && found[1] && found[2] && found[3]) {
                    D_142430_00397490.c[D_142430_00397490.f14C].f20 = 0;
                    D_142430_00397490.c[D_142430_00397490.f14C].f18 = -1;
                    D_142430_00397490.f160 = 1;
                    D_142430_00397490.f154 = 0;
                    break;
                }
                D_142430_00397490.c[D_142430_00397490.f14C].f20 = total;
                D_142430_00397490.c[D_142430_00397490.f14C].f18 = -2;
            } else {
                D_142430_00397490.c[D_142430_00397490.f14C].f18 = -2;
                if (D_142430_00397490.f144 == -2) {
                    D_142430_00397490.f16C = 3;
                    D_142430_00397490.f170 = D_142430_00397490.f14C;
                } else if (D_142430_00397490.f144 >= 0) {
                    D_142430_00397490.c[D_142430_00397490.f14C].f18 = -2;
                } else if (D_142430_00397490.f144 != -4) {
                    D_142430_00397490.f16C = 4;
                    D_142430_00397490.f170 = D_142430_00397490.f14C;
                }
            }
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            D_142430_00397490.f154 = 0;
            break;
        case 1:
            func_11B2E8(path, D_001D5438, 0);
            if (func_12DCA0(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, path, 1) == 0) D_142430_00397490.f160++;
            break;
        case 2:
            if (D_142430_00397490.f144 >= 0) {
                D_142430_00397490.f158 = D_142430_00397490.f144;
                D_142430_00397490.f160 = 3;
            } else {
                D_142430_00397490.c[D_142430_00397490.f14C].f18 = -2;
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 == -7) D_142430_00397490.f16C = 0x2710;
                else if (D_142430_00397490.f144 == -5) D_142430_00397490.f16C = 0x2711;
                else if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 0x2712;
                else if (D_142430_00397490.f144 == -3) D_142430_00397490.f16C = 0x2713;
                else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 3;
                else D_142430_00397490.f16C = 4;
                D_142430_00397490.f15C = 0;
                D_142430_00397490.f14C = 0;
            }
            D_142430_00397490.f154 = 0;
            break;
        case 3:
            D_142430_00397490.f178 = 8;
            if (func_12E050(D_142430_00397490.f158, &D_142430_00397490.c[D_142430_00397490.f14C].f28, 8) == 0) D_142430_00397490.f160 = 4;
            break;
        case 4:
            if (D_142430_00397490.f144 == D_142430_00397490.f178) {
                D_142430_00397490.c[D_142430_00397490.f14C].f24 = 0;
                if (D_142430_00397490.c[D_142430_00397490.f14C].f28 != func_00399710(D_0032E3C8)) D_142430_00397490.c[D_142430_00397490.f14C].f24++;
                if (D_142430_00397490.c[D_142430_00397490.f14C].f2C != func_00399710(D_0032E658)) D_142430_00397490.c[D_142430_00397490.f14C].f24++;
                D_142430_00397490.f154 = 0;
                D_142430_00397490.f160 = 5;
            } else {
                D_142430_00397490.c[D_142430_00397490.f14C].f18 = -2;
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 >= 0) {
                    D_142430_00397490.f16C = 0x2716;
                    if (func_12DE00(D_142430_00397490.f158) == 0) {
                        D_142430_00397490.f15C = 0;
                        D_142430_00397490.f14C = 0;
                        D_142430_00397490.f154 = 0;
                    }
                } else {
                    if (D_142430_00397490.f144 == -5) D_142430_00397490.f16C = 0x2711;
                    else if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 0x2714;
                    else if (D_142430_00397490.f144 == -3) D_142430_00397490.f16C = 0x2715;
                    else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 3;
                    else D_142430_00397490.f16C = 4;
                    D_142430_00397490.f15C = 0;
                    D_142430_00397490.f14C = 0;
                    D_142430_00397490.f154 = 0;
                }
            }
            break;
        case 5:
            if (func_12DE00(D_142430_00397490.f158) == 0) {
                D_142430_00397490.f154 = 0;
                D_142430_00397490.f15C = 0x15;
            }
            break;
        }
        break;
    case 9:
        D_142430_00397490.f15C = 10;
        D_142430_00397490.f188 = 6;
        D_142430_00397490.f160 = 0;
        D_142430_00397490.c[D_142430_00397490.f14C].f18 = 0;
    case 10:
        switch (D_142430_00397490.f160) {
        case 0:
            if (D_142430_00397490.c[D_142430_00397490.f14C].free + D_142430_00397490.c[D_142430_00397490.f14C].f20 >= 0x258) {
                D_142430_00397490.f160 = 1;
            } else {
                D_142430_00397490.f16C = 7;
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                D_142430_00397490.f15C = 0;
                D_142430_00397490.f14C = 0;
            }
            D_142430_00397490.f154 = 0;
            break;
        case 1:
            if (func_12DDC8(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, D_001D5378) == 0) D_142430_00397490.f160 = 2;
            break;
        case 2:
            if (D_142430_00397490.f144 == 0 || D_142430_00397490.f144 == -4) {
                D_142430_00397490.f160 = 3;
            } else {
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 == -3) D_142430_00397490.f16C = 7;
                else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 6;
                else D_142430_00397490.f16C = 0xD;
                D_142430_00397490.f15C = 0;
                D_142430_00397490.f14C = 0;
                D_142430_00397490.f154 = 0;
            }
            break;
        case 3: {
            s32 *ptr;
            ((s32 (*)())func_0038E6D0)(D_160C40_00397380.f664 << 11, &ptr);
            ((void (*)(s32, s32, s32))func_0039D510)((s32)ptr, D_160C40_00397380.f660 + D_160C40_00397380.f64C, D_160C40_00397380.f664);
            D_142430_00397490.f160 = 4;
            D_142430_00397490.f154 = 0;
            break;
        }
        case 4:
            if (D_001CCFD4[0] == 0) D_142430_00397490.f160 = 5;
            D_142430_00397490.f154 = 0;
            break;
        case 5: case 9: case 13: case 17: case 22:
            switch (D_142430_00397490.f160) {
            case 5: func_11B754(found, D_001D53A8); break;
            case 9: func_11B754(found, D_001D53C8); break;
            case 22: func_11B754(found, D_001D53E8); break;
            case 13: func_11B754(found, D_001D5418); break;
            case 17: func_11B2E8(found, D_001D5438, D_142430_00397490.c[D_142430_00397490.f14C].f18); break;
            }
            if (func_12DCA0(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, (char *)found, 0x203) == 0) {
                D_142430_00397490.f158 = -1;
                D_142430_00397490.f160++;
            }
            break;
        case 6: case 10: case 14: case 18: case 23:
            if (D_142430_00397490.f144 >= 0) {
                s32 *ptr;
                if (D_142430_00397490.f158 < 0) D_142430_00397490.f158 = D_142430_00397490.f144;
                ((s32 (*)())func_0038E6D0)(D_160C40_00397380.f664 << 11, &ptr);
                switch (D_142430_00397490.f160) {
                case 6:
                    D_142430_00397490.f178 = 0x3C4;
                    D_142430_00397490.f174 = (s32)ptr + ptr[0];
                    D_142430_00397490.f188++;
                    break;
                case 10:
                    D_142430_00397490.f178 = ptr[3];
                    D_142430_00397490.f174 = (s32)ptr + ptr[2];
                    D_142430_00397490.f188 += (D_142430_00397490.f178 + 0x3FF) >> 10;
                    break;
                case 23:
                    D_142430_00397490.f174 = (s32)&D_001D545C;
                    D_142430_00397490.f178 = (0x258 - D_142430_00397490.f188) << 10;
                    break;
                case 14: {
                    s32 n = func_00399830(D_001C5BD0, 0, &D_001D6318);
                    D_142430_00397490.f174 = (s32)D_001C5BD0;
                    D_142430_00397490.f178 = n;
                    D_142430_00397490.f188 += (D_142430_00397490.f178 + 0x3FF) >> 10;
                    break;
                }
                case 18: {
                    s32 n = func_00399710(D_0032E3C8);
                    n += func_00399710(D_0032E658) * 0x25;
                    D_142430_00397490.f178 = n + 8;
                    D_142430_00397490.f174 = (s32)ptr + ptr[4];
                    D_142430_00397490.f188 += (D_142430_00397490.f178 + 0x3FF) >> 10;
                    break;
                }
                }
                if (func_12E168(D_142430_00397490.f158, (void *)D_142430_00397490.f174, D_142430_00397490.f178) == 0) D_142430_00397490.f160++;
            } else {
                D_142430_00397490.f16C = 0xA;
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                D_142430_00397490.f15C = 0;
                D_142430_00397490.f14C = 0;
                D_142430_00397490.f154 = 0;
            }
            break;
        case 7: case 11: case 15: case 19: case 24:
            if (D_142430_00397490.f144 == D_142430_00397490.f178) {
                if (func_12DE00(D_142430_00397490.f158) == 0) D_142430_00397490.f160++;
            } else {
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 >= 0) {
                    D_142430_00397490.f16C = 0xB;
                    if (func_12DE00(D_142430_00397490.f158) == 0) {
                        D_142430_00397490.f15C = 0;
                        D_142430_00397490.f14C = 0;
                        D_142430_00397490.f154 = 0;
                    }
                } else {
                    if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 8;
                    else if (D_142430_00397490.f144 == -3) D_142430_00397490.f16C = 7;
                    else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 6;
                    else D_142430_00397490.f16C = 0xD;
                    D_142430_00397490.f15C = 0;
                    D_142430_00397490.f14C = 0;
                    D_142430_00397490.f154 = 0;
                }
            }
            break;
        case 8: case 12: case 16: case 20:
            if (D_142430_00397490.f144 == 0) {
                D_142430_00397490.f160++;
            } else {
                D_142430_00397490.f16C = 0xC;
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                D_142430_00397490.f15C = 0;
                D_142430_00397490.f14C = 0;
            }
            D_142430_00397490.f154 = 0;
            break;
        case 21:
            if (++D_142430_00397490.c[D_142430_00397490.f14C].f18 < 4) D_142430_00397490.f160 = 0x11;
            else D_142430_00397490.f160++;
            D_142430_00397490.f154 = 0;
            break;
        case 25:
            D_142430_00397490.c[D_142430_00397490.f14C].f28 = func_00399710(D_0032E3C8);
            D_142430_00397490.c[D_142430_00397490.f14C].f2C = func_00399710(D_0032E658);
            D_142430_00397490.c[D_142430_00397490.f14C].f18 = -1;
            D_142430_00397490.c[D_142430_00397490.f14C].f24 = 0;
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            break;
        }
        break;
    case 11:
        D_142430_00397490.f15C = 12;
        D_142430_00397490.f160 = 0;
        D_142430_00397490.c[D_142430_00397490.f14C].f18 = -2;
    case 12:
        switch (D_142430_00397490.f160) {
        case 0:
            if (func_12E580(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, D_001D5390, 0, 1, D_00228D40) == 0) D_142430_00397490.f160 = 1;
            break;
        case 1:
            if (D_142430_00397490.f144 == 1) {
                func_11B2E8(found, D_001D6358, D_001D5378, D_00228D60);
                if (func_12E7A8(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, (char *)found) == 0) D_142430_00397490.f160 = 2;
                break;
            }
            if (D_142430_00397490.f144 == 0) {
                D_142430_00397490.f160 = 3;
            } else {
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 == -5) D_142430_00397490.f16C = 0x10;
                else if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 0xF;
                else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 0xE;
                else D_142430_00397490.f16C = 0x12;
                D_142430_00397490.f15C = 0;
                D_142430_00397490.f14C = 0;
            }
            D_142430_00397490.f154 = 0;
            break;
        case 2:
            if (func_12E580(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, D_001D5390, 1, 1, D_00228D40) == 0) D_142430_00397490.f160 = 1;
            break;
        case 3:
            if (func_12E7A8(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, D_001D5378) == 0) D_142430_00397490.f160 = 4;
            break;
        case 4:
            if (D_142430_00397490.f144 != 0) {
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 == -6) D_142430_00397490.f16C = 0x11;
                else if (D_142430_00397490.f144 == -5) D_142430_00397490.f16C = 0x10;
                else if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 0xF;
                else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 0xE;
                else D_142430_00397490.f16C = 0x12;
            }
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            D_142430_00397490.f154 = 0;
            break;
        }
        break;
    case 21:
        D_142430_00397490.f15C = 0x16;
        D_142430_00397490.c[D_142430_00397490.f14C].f1A = -1;
        D_142430_00397490.f150 = 0;
        break;
    case 22:
        D_142430_00397490.c[D_142430_00397490.f14C].f1A++;
        if (D_142430_00397490.c[D_142430_00397490.f14C].f1A < 4) {
            D_142430_00397490.f160 = 0;
            D_142430_00397490.f15C = 0x17;
        } else {
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            D_142430_00397490.f154 = 0;
        }
        break;
    case 13:
        if (D_142430_00397490.c[D_142430_00397490.f14C].f18 < 0) {
            D_142430_00397490.f16C = 0x13;
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            D_142430_00397490.f154 = 0;
            break;
        }
        D_142430_00397490.f150 = 0;
        D_142430_00397490.f160 = 0;
        D_142430_00397490.f15C = 14;
    case 14:
    case 23:
        switch (D_142430_00397490.f160) {
        case 0:
            if (D_142430_00397490.f15C == 0x17) func_11B2E8(found, D_001D5438, D_142430_00397490.c[D_142430_00397490.f14C].f1A);
            else func_11B2E8(found, D_001D5438, D_142430_00397490.c[D_142430_00397490.f14C].f18);
            if (func_12DCA0(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, (char *)found, 1) == 0) D_142430_00397490.f160++;
            break;
        case 1:
            if (D_142430_00397490.f144 >= 0) {
                D_142430_00397490.f158 = D_142430_00397490.f144;
                D_142430_00397490.f160 = 2;
            } else {
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 == -7) D_142430_00397490.f16C = 0x14;
                else if (D_142430_00397490.f144 == -5) D_142430_00397490.f16C = 0x15;
                else if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 0x16;
                else if (D_142430_00397490.f144 == -3) D_142430_00397490.f16C = 0x17;
                else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 0x18;
                else D_142430_00397490.f16C = 0x1C;
                D_142430_00397490.f15C = 0;
                D_142430_00397490.f14C = 0;
            }
            D_142430_00397490.f154 = 0;
            break;
        case 2:
            D_142430_00397490.f178 = 8;
            if (func_12E050(D_142430_00397490.f158, &D_142430_00397490.c[D_142430_00397490.f14C].f28, 8) == 0) D_142430_00397490.f160 = 3;
            break;
        case 3:
            if (D_142430_00397490.f144 == D_142430_00397490.f178) {
                D_142430_00397490.f154 = 0;
                D_142430_00397490.f160 = 4;
            } else {
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 >= 0) {
                    D_142430_00397490.f16C = 0x1B;
                    if (func_12DE00(D_142430_00397490.f158) == 0) {
                        D_142430_00397490.f15C = 0;
                        D_142430_00397490.f14C = 0;
                        D_142430_00397490.f154 = 0;
                    }
                } else {
                    if (D_142430_00397490.f144 == -5) D_142430_00397490.f16C = 0x15;
                    else if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 0x19;
                    else if (D_142430_00397490.f144 == -3) D_142430_00397490.f16C = 0x1A;
                    else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 0x18;
                    else D_142430_00397490.f16C = 0x1C;
                    D_142430_00397490.f15C = 0;
                    D_142430_00397490.f14C = 0;
                    D_142430_00397490.f154 = 0;
                }
            }
            break;
        case 4:
            D_142430_00397490.f178 = D_142430_00397490.c[D_142430_00397490.f14C].f28;
            if (func_12E050(D_142430_00397490.f158, D_001C5BD0, D_142430_00397490.f178) == 0) D_142430_00397490.f160 = 5;
            break;
        case 5:
            if (D_142430_00397490.f144 == D_142430_00397490.f178) {
                if (D_142430_00397490.f15C == 0x17) {
                    func_00399948(D_001C5BD0, D_142430_00397490.f14C, D_142430_00397490.c[D_142430_00397490.f14C].f1A);
                    D_142430_00397490.f160 = 8;
                } else {
                    D_142430_00397490.c[D_142430_00397490.f14C].f24 = ((s32 (*)())func_00399A00)(D_001C5BD0, D_001C5BD0 + D_142430_00397490.f144, 0, D_0032E3C8);
                    D_142430_00397490.f160 = 6;
                }
                D_142430_00397490.f154 = 0;
            } else {
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 >= 0) {
                    D_142430_00397490.f16C = 0x1B;
                    if (func_12DE00(D_142430_00397490.f158) == 0) {
                        D_142430_00397490.f15C = 0;
                        D_142430_00397490.f14C = 0;
                        D_142430_00397490.f154 = 0;
                    }
                } else {
                    if (D_142430_00397490.f144 == -5) D_142430_00397490.f16C = 0x15;
                    else if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 0x19;
                    else if (D_142430_00397490.f144 == -3) D_142430_00397490.f16C = 0x1A;
                    else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 0x18;
                    else D_142430_00397490.f16C = 0x1C;
                    D_142430_00397490.f15C = 0;
                    D_142430_00397490.f14C = 0;
                    D_142430_00397490.f154 = 0;
                }
            }
            break;
        case 6:
            D_142430_00397490.f178 = D_142430_00397490.c[D_142430_00397490.f14C].f2C;
            if (func_12E050(D_142430_00397490.f158, D_001CBBD0, D_142430_00397490.f178) == 0) D_142430_00397490.f160 = 7;
            break;
        case 7:
            if (D_142430_00397490.f144 == D_142430_00397490.f178) {
                D_142430_00397490.c[D_142430_00397490.f14C].f24 += ((s32 (*)())func_00399A00)(D_001CBBD0, D_001CBBD0 + D_142430_00397490.f144, D_142430_00397490.f150, D_0032E658);
                D_142430_00397490.f150++;
                if (D_142430_00397490.f150 < 0x25) D_142430_00397490.f160 = 6;
                else D_142430_00397490.f160 = 8;
                D_142430_00397490.f154 = 0;
            } else {
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 >= 0) {
                    D_142430_00397490.f16C = 0x1B;
                    if (func_12DE00(D_142430_00397490.f158) == 0) {
                        D_142430_00397490.f15C = 0;
                        D_142430_00397490.f14C = 0;
                        D_142430_00397490.f154 = 0;
                    }
                } else {
                    if (D_142430_00397490.f144 == -5) D_142430_00397490.f16C = 0x15;
                    else if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 0x19;
                    else if (D_142430_00397490.f144 == -3) D_142430_00397490.f16C = 0x1A;
                    else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 0x18;
                    else D_142430_00397490.f16C = 0x1C;
                    D_142430_00397490.f15C = 0;
                    D_142430_00397490.f14C = 0;
                    D_142430_00397490.f154 = 0;
                }
            }
            break;
        case 8:
            if (func_12DE00(D_142430_00397490.f158) == 0) {
                if (D_142430_00397490.f15C == 0x17) {
                    D_142430_00397490.f154 = 0;
                    D_142430_00397490.f15C = 0x16;
                } else {
                    func_00399F40();
                    if (D_142430_00397490.c[D_142430_00397490.f14C].f24 != 0) D_142430_00397490.f16C = 0x1C;
                    D_142430_00397490.f15C = 0;
                    D_142430_00397490.f14C = 0;
                }
            }
            break;
        }
        break;
    case 15:
        if (D_142430_00397490.c[D_142430_00397490.f14C].f24 != 0) {
            D_142430_00397490.f16C = 0x2717;
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            D_142430_00397490.f154 = 0;
            break;
        }
        if (D_142430_00397490.c[D_142430_00397490.f14C].f18 < 0) {
            D_142430_00397490.f16C = 0x1D;
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            D_142430_00397490.f154 = 0;
            break;
        }
        D_142430_00397490.f160 = 0;
        D_142430_00397490.f15C = 0x10;
    case 16:
        switch (D_142430_00397490.f160) {
        case 0:
            func_11B2E8(found, D_001D5438, D_142430_00397490.c[D_142430_00397490.f14C].f18);
            if (func_12DCA0(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, (char *)found, 2) == 0) D_142430_00397490.f160 = 1;
            break;
        case 1:
            if (D_142430_00397490.f144 >= 0) {
                D_142430_00397490.f158 = D_142430_00397490.f144;
                D_142430_00397490.f160 = 2;
            } else {
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 == -7) D_142430_00397490.f16C = 0x1E;
                else if (D_142430_00397490.f144 == -5) D_142430_00397490.f16C = 0x1F;
                else if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 0x20;
                else if (D_142430_00397490.f144 == -3) D_142430_00397490.f16C = 0x21;
                else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 0x22;
                else D_142430_00397490.f16C = 0x26;
                D_142430_00397490.f15C = 0;
                D_142430_00397490.f14C = 0;
            }
            D_142430_00397490.f154 = 0;
            break;
        case 2:
            if (func_12DEC0(D_142430_00397490.f158, 8, 0) == 0) D_142430_00397490.f160 = 3;
            break;
        case 3:
            if (D_142430_00397490.f144 >= 0) {
                D_142430_00397490.f160 = 4;
            } else if (func_12DE00(D_142430_00397490.f158) == 0) {
                D_142430_00397490.f16C = 0x26;
                D_142430_00397490.f15C = 0;
                D_142430_00397490.f14C = 0;
                D_142430_00397490.f154 = 0;
            }
            break;
        case 4:
            if (func_12E168(D_142430_00397490.f158, D_001C5BD0, func_00399710(D_0032E3C8)) == 0) D_142430_00397490.f160 = 5;
            break;
        case 5:
            if (D_142430_00397490.f144 == func_00399710(D_0032E3C8)) {
                D_142430_00397490.f160 = 6;
            } else {
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 >= 0) {
                    D_142430_00397490.f16C = 0x25;
                    if (func_12DE00(D_142430_00397490.f158) == 0) {
                        D_142430_00397490.f15C = 0;
                        D_142430_00397490.f14C = 0;
                        D_142430_00397490.f154 = 0;
                    }
                } else {
                    if (D_142430_00397490.f144 == -5) D_142430_00397490.f16C = 0x1F;
                    else if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 0x23;
                    else if (D_142430_00397490.f144 == -3) D_142430_00397490.f16C = 0x24;
                    else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 0x22;
                    else D_142430_00397490.f16C = 0x26;
                    D_142430_00397490.f15C = 0;
                    D_142430_00397490.f14C = 0;
                    D_142430_00397490.f154 = 0;
                }
            }
            break;
        case 6:
            if (func_12DEC0(D_142430_00397490.f158, D_142430_00397490.c[0].f28 + 8 + D_142430_00397490.f150 * D_142430_00397490.c[0].f2C, 0) == 0) D_142430_00397490.f160 = 7;
            break;
        case 7:
            if (D_142430_00397490.f144 == D_142430_00397490.c[0].f28 + 8 + D_142430_00397490.f150 * D_142430_00397490.c[0].f2C) {
                D_142430_00397490.f160 = 8;
            } else if (func_12DE00(D_142430_00397490.f158) == 0) {
                D_142430_00397490.f15C = 0;
                D_142430_00397490.f14C = 0;
                D_142430_00397490.f154 = 0;
            }
            break;
        case 8:
            if (func_12E168(D_142430_00397490.f158, D_001CBBD0, func_00399710(D_0032E658)) == 0) D_142430_00397490.f160 = 9;
            break;
        case 9:
            if (D_142430_00397490.f144 == func_00399710(D_0032E658)) {
                D_142430_00397490.f160 = 0xA;
            } else {
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 >= 0) {
                    D_142430_00397490.f16C = 0x25;
                    if (func_12DE00(D_142430_00397490.f158) == 0) {
                        D_142430_00397490.f15C = 0;
                        D_142430_00397490.f14C = 0;
                        D_142430_00397490.f154 = 0;
                    }
                } else {
                    if (D_142430_00397490.f144 == -5) D_142430_00397490.f16C = 0x1F;
                    else if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 0x23;
                    else if (D_142430_00397490.f144 == -3) D_142430_00397490.f16C = 0x24;
                    else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 0x18;
                    else D_142430_00397490.f16C = 0x1C;
                    D_142430_00397490.f15C = 0;
                    D_142430_00397490.f14C = 0;
                    D_142430_00397490.f154 = 0;
                }
            }
            break;
        case 10:
            if (func_12DE00(D_142430_00397490.f158) == 0) {
                D_142430_00397490.f15C = 0;
                D_142430_00397490.f14C = 0;
            }
            break;
        }
        break;
    case 17: {
        s32 *ptr;
        ((s32 (*)())func_0038E6D0)(D_160C40_00397380.f664 << 11, &ptr);
        ((void (*)(s32, s32, s32))func_0039D510)((s32)ptr, D_160C40_00397380.f660 + D_160C40_00397380.f64C, D_160C40_00397380.f664);
        D_142430_00397490.f160 = 0x12;
        D_142430_00397490.f154 = 0;
        break;
    }
    case 18:
        if (D_001CCFD4[0] == 0) {
            s32 *ptr;
            ((s32 (*)())func_0038E6D0)(D_160C40_00397380.f664 << 11, &ptr);
            D_142430_00397490.f160 = 0x13;
            D_142430_00397490.f174 = (s32)ptr + ptr[4];
        }
        D_142430_00397490.f154 = 0;
        break;
    case 19:
        if (D_142430_00397490.c[D_142430_00397490.f14C].f24 != 0) {
            D_142430_00397490.f16C = 0x2718;
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            D_142430_00397490.f154 = 0;
            break;
        }
        if (D_142430_00397490.c[D_142430_00397490.f14C].f18 < 0) {
            D_142430_00397490.f16C = 0x27;
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            D_142430_00397490.f154 = 0;
            break;
        }
        D_142430_00397490.f150 = 0;
        D_142430_00397490.f160 = 0;
        D_142430_00397490.f15C = 0x14;
    case 20:
        switch (D_142430_00397490.f160) {
        case 0:
            func_11B2E8(found, D_001D5438, D_142430_00397490.c[D_142430_00397490.f14C].f18);
            if (func_12DCA0(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, (char *)found, 2) == 0) D_142430_00397490.f160 = 1;
            break;
        case 1:
            if (D_142430_00397490.f144 >= 0) {
                D_142430_00397490.f158 = D_142430_00397490.f144;
                t = func_00399710(D_0032E3C8);
                t += func_00399710(D_0032E658) * 0x25;
                D_142430_00397490.f178 = t + 8;
                if (func_12E168(D_142430_00397490.f158, (void *)D_142430_00397490.f174, D_142430_00397490.f178) == 0) D_142430_00397490.f160 = 2;
            } else {
                D_142430_00397490.f16C = 0x2B;
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                D_142430_00397490.f15C = 0;
                D_142430_00397490.f14C = 0;
                D_142430_00397490.f154 = 0;
            }
            break;
        case 2:
            if (D_142430_00397490.f144 == D_142430_00397490.f178) {
                if (func_12DE00(D_142430_00397490.f158) == 0) D_142430_00397490.f160 = 3;
            } else {
                D_142430_00397490.f170 = D_142430_00397490.f14C;
                if (D_142430_00397490.f144 >= 0) {
                    D_142430_00397490.f16C = 0xB;
                    if (func_12DE00(D_142430_00397490.f158) == 0) {
                        D_142430_00397490.f15C = 0;
                        D_142430_00397490.f14C = 0;
                        D_142430_00397490.f154 = 0;
                    }
                } else {
                    if (D_142430_00397490.f144 == -4) D_142430_00397490.f16C = 0x28;
                    else if (D_142430_00397490.f144 == -3) D_142430_00397490.f16C = 0x29;
                    else if (D_142430_00397490.f144 == -2) D_142430_00397490.f16C = 0x2A;
                    else D_142430_00397490.f16C = 0x2D;
                    D_142430_00397490.f15C = 0;
                    D_142430_00397490.f14C = 0;
                    D_142430_00397490.f154 = 0;
                }
            }
            break;
        case 3:
            if (D_142430_00397490.f144 != 0) {
                D_142430_00397490.f16C = 0x2C;
                D_142430_00397490.f170 = D_142430_00397490.f14C;
            }
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            D_142430_00397490.f154 = 0;
            break;
        }
        break;
    case 24:
        D_142430_00397490.f15C = 0x19;
        D_142430_00397490.f160 = 0;
        D_142430_00397490.c[D_142430_00397490.f14C].f1C = 1;
    case 25: {
        s32 q = D_142430_00397490.f160 / 5;
        s32 m = D_142430_00397490.f160 % 5;
        switch (q) {
        case 0: func_11B2E8(found, D_001D6360, m); break;
        case 1: func_11B2E8(found, D_001D6380, m); break;
        case 2: func_11B2E8(found, D_001D63A0, m); break;
        case 3: *(u8 *)found = 0; break;
        }
        if (*(u8 *)found == 0) {
            D_142430_00397490.f15C = 0x1C;
            D_142430_00397490.f154 = 0;
        } else if (func_12DCA0(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, (char *)found, 1) == 0) {
            D_142430_00397490.f15C = 0x1A;
        }
        break;
    }
    case 26:
        if (D_142430_00397490.f144 >= 0) {
            D_142430_00397490.f158 = D_142430_00397490.f144;
            if (func_12E050(D_142430_00397490.f158, D_001C5BD0, 0x2800) == 0) D_142430_00397490.f15C = 0x1B;
        } else {
            D_142430_00397490.f154 = 0;
            D_142430_00397490.f15C = 0x19;
            D_142430_00397490.f160 = (D_142430_00397490.f160 / 5 + 1) * 5;
        }
        break;
    case 27:
        if (D_142430_00397490.f144 >= 0x2800) {
            E_397490 *ent;
            if (func_12DE00(D_142430_00397490.f158) != 0) return;
            if (func_003997F0(D_001C5BD8) != 0) {
                ent = (E_397490 *)(D_001C5BD8 + 8);
                while (ent->type != -1) {
                    if (ent->type == 10) {
                        D_142660.f48 |= 0x40;
                        if (ent->d[0x1F] != 0) {
                            D_142660.f48 |= 1;
                            D_142430_00397490.c[D_142430_00397490.f14C].f1C++;
                        }
                        break;
                    }
                    ent = (E_397490 *)((u8 *)ent + ((ent->size + 3) / 4 * 4 + 8));
                }
            }
            D_142430_00397490.f160++;
        } else {
            D_142430_00397490.f160 = (D_142430_00397490.f160 / 5 + 1) * 5;
        }
        D_142430_00397490.f15C = 0x19;
        D_142430_00397490.f154 = 0;
        break;
    case 28:
        D_142430_00397490.f15C = 0x1D;
        D_142430_00397490.f160 = 0;
        D_142430_00397490.c[D_142430_00397490.f14C].f1C++;
    case 29:
        switch (D_142430_00397490.f160 / 5) {
        case 0: func_11B2E8(found, D_001D63C0, D_142430_00397490.f160 % 4); break;
        case 1: func_11B2E8(found, D_001D63E0, D_142430_00397490.f160 % 4); break;
        case 2: func_11B2E8(found, D_001D6400, D_142430_00397490.f160 % 4); break;
        case 3: func_11B2E8(found, D_001D6420, D_142430_00397490.f160 % 4); break;
        case 4: *(u8 *)found = 0; break;
        }
        if (*(u8 *)found == 0) {
            D_142430_00397490.f15C = 0;
            D_142430_00397490.f14C = 0;
            D_142430_00397490.f154 = 0;
        } else if (func_12DCA0(D_142430_00397490.c[D_142430_00397490.f14C].port, D_142430_00397490.c[D_142430_00397490.f14C].slot, (char *)found, 1) == 0) {
            D_142430_00397490.f15C = 0x1E;
        }
        break;
    case 30:
        if (D_142430_00397490.f144 >= 0) {
            D_142430_00397490.f158 = D_142430_00397490.f144;
            if (func_12E050(D_142430_00397490.f158, D_001C5BD0, 0x2800) == 0) D_142430_00397490.f15C = 0x1F;
        } else {
            D_142430_00397490.f154 = 0;
            D_142430_00397490.f15C = 0x1D;
            D_142430_00397490.f160 = (D_142430_00397490.f160 / 5 + 1) * 5;
        }
        break;
    case 31:
        if (D_142430_00397490.f144 >= 0x2800) {
            E_397490 *ent;
            if (func_12DE00(D_142430_00397490.f158) != 0) return;
            if (func_003997F0(D_001C5BD8) != 0) {
                ent = (E_397490 *)(D_001C5BD8 + 8);
                while (ent->type != -1) {
                    if (ent->type == 10) {
                        u8 *d = ent->d;
                        D_142660.f48 |= 0x80;
                        if (d[0x29] != 0) { D_142660.f48 |= 2; D_142430_00397490.c[D_142430_00397490.f14C].f1C++; }
                        if (d[0x1D] != 0) { D_142660.f48 |= 4; D_142430_00397490.c[D_142430_00397490.f14C].f1C++; }
                        if (d[0x25] != 0) { D_142660.f48 |= 8; D_142430_00397490.c[D_142430_00397490.f14C].f1C++; }
                        if (d[0x2D] != 0) { D_142660.f48 |= 0x10; D_142430_00397490.c[D_142430_00397490.f14C].f1C++; }
                        if (d[0x1C] != 0) { D_142660.f48 |= 0x20; D_142430_00397490.c[D_142430_00397490.f14C].f1C++; }
                        break;
                    }
                    ent = (E_397490 *)((u8 *)ent + ((ent->size + 3) / 4 * 4 + 8));
                }
            }
            D_142430_00397490.f160++;
        } else {
            D_142430_00397490.f160 = (D_142430_00397490.f160 / 5 + 1) * 5;
        }
        D_142430_00397490.f15C = 0x1D;
        D_142430_00397490.f154 = 0;
        break;
    }
}
/* localdecomp:end func_00397490 */

/* localdecomp:start func_00399660 */
extern u8 D_0032E3C8[];
extern u8 D_0032E658[];
extern s32 func_00399710();
extern s32 func_00399830();
void func_00399660(u8 *p) {
    s32 i;
    *(s32 *)p = func_00399710(D_0032E3C8);
    *(s32 *)(p + 4) = func_00399710(D_0032E658);
    p += 8;
    p += func_00399830(p, 0, D_0032E3C8);
    for (i = 0; i < 0x25; i++) {
        p += func_00399830(p, i, D_0032E658);
    }
}
/* localdecomp:end func_00399660 */

LINKER_REMNANT("asm/remnants", func_00399708);

/* localdecomp:start func_00399710 */
s32 func_00399710(s32 *p) {
    s32 n = 8;
    if (p[0] != 0) {
        do {
            n += 8;
            n += p[1];
            p += 4;
            n = (n + 3) & ~3;
        } while (p[0] != 0);
    }
    return n + 8;
}
/* localdecomp:end func_00399710 */

/* localdecomp:start func_00399748 */
extern u8 D_0032E3C8[];
u16 func_00399748(u8 *p, u32 n) {
    u8 *end;
    s32 r;
    s32 k;
    if ((u32)func_00399710((s32 *)D_0032E3C8) < n) return 0;
    end = p + n;
    r = 0xEDB88320;
    for (; p < end; p++) {
        r ^= *p << 8;
        for (k = 7; k >= 0; k--) {
            if (r & 0x8000) r = (r << 1) ^ 0x1F45;
            else r = r << 1;
        }
    }
    return r;
}
/* localdecomp:end func_00399748 */

/* localdecomp:start func_003997F0 */
s32 func_00399748_003997F0(void *, s32);

s32 func_003997F0(s32 *arg0) {
    s32 ret = 0;
    s32 v = arg0[1];
    s32 key = arg0[0];

    if (v != 0) {
        ret = func_00399748_003997F0(arg0 + 2, key) == v;
    }
    return ret;
}
/* localdecomp:end func_003997F0 */

/* localdecomp:start func_00399830 */
extern void func_00388440(void *, s32, s32);
extern void func_00388550();
extern u16 func_00399748(u8 *p, u32 n);
s32 func_00399830(u8 *dst, s32 n, s32 *e) {
    s32 off = 0;
    u8 *p = dst + 8;
    s32 *q;
    s32 t, u, w;
    if (e[0] != 0) {
        q = e;
        do {
            off += 8;
            w = n * q[1];
            u = q[0];
            t = u + w;
            *(s32 *)p = q[2];
            *(s32 *)(p + 4) = q[1];
            p += 8;
            if (q[2] == 0x1770) {
                func_00388440(p, 0, q[1]);
            } else {
                func_00388550(p, t, q[1]);
            }
            p += q[1];
            off += q[1];
            q += 4;
            p = (u8 *)((s32)p + 3 & ~3);
            off = (off + 3) & ~3;
        } while (q[0] != 0);
    }
    off += 8;
    *(s32 *)(p + 4) = 0;
    *(s32 *)p = -1;
    *(s32 *)(dst + 4) = func_00399748(dst + 8, off);
    *(s32 *)dst = off;
    return off + 8;
}
/* localdecomp:end func_00399830 */

/* localdecomp:start func_00399948 */
typedef struct { u8 b[8]; } V8_399948;
typedef struct { s32 f0, f4, f8, fC; V8_399948 f10; s32 f18; } E_399948;
typedef struct { u8 p0[0x30]; E_399948 e[4]; } R_399948;
extern R_399948 D_00142430_00399948[];
extern s32 func_003997F0();
void func_00399948(u8 *a, s32 i, s32 j) {
    s32 r = func_003997F0(a) == 0;
    a += 0x10;
    D_00142430_00399948[i].e[j].f18 = r;
    D_00142430_00399948[i].e[j].f0 = *(s32 *)a;
    a += 0xC;
    D_00142430_00399948[i].e[j].f4 = *(s32 *)a;
    D_00142430_00399948[i].e[j].f8 = a[0x32];
    a += 0x88;
    D_00142430_00399948[i].e[j].fC = *(s32 *)a;
    *(V8_399948 *)((u8 *)D_00142430_00399948 + 0x40 + j * 0x1C + i * 0xA0) = *(V8_399948 *)(a + 0xC);
}
/* localdecomp:end func_00399948 */

INCLUDE_ASM("asm/nonmatchings/text", func_00399A00);

/* localdecomp:start func_00399C90 */
extern s32 func_00399C90(s32, s32);
typedef struct { u8 b[8]; } V8_399C90;
typedef struct { s32 f0, f4, f8, fC; V8_399C90 f10; s32 f18; } E_399C90;
typedef struct { u8 p0[0x18]; s16 h18; u8 p1a[0x16]; E_399C90 e[4]; u8 pA0[0xA8]; s32 f148; s32 f14C; s32 f150; u8 p154[8]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; u8 p16C[0x10]; s32 f17C; } S_399C90;
typedef struct { s32 f0; u8 p4[0x2E]; u8 b32; } T_399C90;
extern S_399C90 D_142430_00399C90;
extern T_399C90 D_142660_00399C90;
extern s32 D_001D4CF0;
extern u32 D_001D545C;
extern s32 D_001D5528;
extern s32 D_001D4CEC_00399C90;
extern V8_399C90 D_1D4BE0;
extern u8 D_1A9318[];
extern u8 D_001D5570[8];
extern u8 D_001C5BD0[];
extern u8 D_001CBBD0[];
extern u8 D_0032E3C8[];
extern u8 D_0032E658[];
extern void func_0039B0F8();
s32 func_00399C90(s32 a, s32 b) {
    u8 *q;
    s32 old;
    if ((u32)(D_001D4CF0 - 0x1E) < 7) return 0;
    if (b == 0x18) return 0;
    if ((u32)(b - 0x1F) < 5) b = 3;
    if (D_001D545C == 0x1E) return 0;
    if (D_001D545C == 0x24) return 0;
    if (b == 0x1E) return 0;
    if (b == 0x24) return 0;
    func_12BE28(&D_1D4BE0);
    func_13AD58(&D_1D4BE0);
    func_0039B0F8();
    func_0039AAF0(D_1A9318 + (D_001D545C << 11));
    if (D_142430_00399C90.f148 == -1 || ((S_399C90 *)((u8 *)&D_142430_00399C90 + D_142430_00399C90.f148 * 0xA0))->h18 < 0) return a == 0;
    D_142430_00399C90.f17C |= a;
    if (D_142430_00399C90.f17C != 0) {
        if (a == 0) D_001D4CEC_00399C90 |= 0x200;
        if (D_142430_00399C90.f15C < 3 && D_142430_00399C90.f164 < 0) {
            D_142430_00399C90.f150 = D_001D545C;
            old = 0;
            if (b >= 0) {
                D_001D545C = b;
                q = &D_001D5570[b];
                old = *q;
                if (old == 0) *q = 1;
            }
            D_142430_00399C90.e[D_142430_00399C90.h18].f4 = D_142660_00399C90.f0;
            D_142430_00399C90.e[D_142430_00399C90.h18].f0 = D_001D545C;
            D_142430_00399C90.e[D_142430_00399C90.h18].fC = D_001D5528;
            *(V8_399C90 *)((u8 *)&D_142430_00399C90 + D_142430_00399C90.h18 * 0x1C + 0x40) = D_1D4BE0;
            D_142430_00399C90.e[D_142430_00399C90.h18].f8 = D_142660_00399C90.b32;
            func_00399830(D_001C5BD0, 0, D_0032E3C8);
            func_00399830(D_001CBBD0, D_142430_00399C90.f150, D_0032E658);
            if (b >= 0) {
                D_001D5570[D_001D545C] = old;
                D_001D545C = D_142430_00399C90.f150;
            }
            if (D_142430_00399C90.f164 < 0) {
                D_142430_00399C90.f164 = 0xF;
                D_142430_00399C90.f168 = D_142430_00399C90.f148;
            }
        }
    }
    return D_142430_00399C90.f164 == 0xF;
}
/* localdecomp:end func_00399C90 */

/* localdecomp:start func_00399F40 */
extern s32 D_001D4B60[];
extern s32 D_001D4B90[];
extern s32 D_001D4BA0[];
extern u8 D_0016C580[];
void func_00399F40(void)
{
  u8 *new_var;
 do { new_var = (u8 *) D_0016C580; D_001D4B60[0] = -1; *((s32 *) (new_var + 0x18)) = -1; D_001D4B90[0] = -1; D_001D4BA0[0] = -1; } while (0);
  *((s32 *) (new_var + 0x30)) = -1;
}
/* localdecomp:end func_00399F40 */

/* localdecomp:start func_00399F70 */
extern u8 D_001D6580;
u8 func_00399F70(void) { return D_001D6580; }
/* localdecomp:end func_00399F70 */

/* localdecomp:start func_00399F78 */
extern u8 D_001D6580;
void func_00399F78(void) {
    D_001D6580 = 0;
}
/* localdecomp:end func_00399F78 */

/* localdecomp:start func_00399F80 */
extern u8 D_001D6580;
void func_00399F80(void) {
    D_001D6580 = 1;
}
/* localdecomp:end func_00399F80 */

/* localdecomp:start func_00399F90 */
typedef struct { u8 pad[0x410]; s32 f410; } S_399F90;
extern S_399F90 D_00229000;
extern s32 func_0039A170();
extern s32 func_0039A130();
s32 func_00399F90(void) {
    s32 i = 5;
    s32 j;
    s32 k;
    s32 r;
    for (;;) {
        j = i - 1;
        func_00399F78();
        r = func_0039A170(D_00229000.f410);
        for (k = 0; k < 60; k++) {
            if (k != D_00229000.f410) func_0039A170(k);
        }
        i = j;
        if (i < 0) break;
        if (func_00399F70() == 0) break;
    }
    func_0039A130(D_00229000.f410);
    return r;
}
/* localdecomp:end func_00399F90 */

/* localdecomp:start func_0039A040 */
typedef struct { s16 f0; u8 p0[0x16]; u16 f18; u8 p1[0x12]; s16 f2c; u8 p2[2]; } E39A040;
extern E39A040 *D_0032FB08_0039A040[];
extern u8 D_143B30_0039A040[];
extern u8 D_143BF0_0039A040[];
extern u8 D_143CB0_0039A040[];
extern s32 func_0039A7F8(u8 *, s32, s32);
extern s32 func_0039A980(u8 *, s32, s32);
void func_0039A040(s32 a, s32 b) {
    E39A040 *p = &D_0032FB08_0039A040[a][b];
    if (!(p->f18 & 2)) {
        if (p->f2c == 1) {
            func_0039A7F8(((p->f0 & 0xFF00) >> 8) == 1 ? D_143B30_0039A040 : D_143BF0_0039A040, a, b);
        } else if (p->f2c == 2) {
            func_0039A980(((p->f0 & 0xFF00) >> 8) == 1 ? D_143B30_0039A040 : D_143BF0_0039A040, a, b);
            func_0039A7F8(D_143CB0_0039A040, a, b);
        }
    }
}
/* localdecomp:end func_0039A040 */

/* localdecomp:start func_0039A130 */
extern s32 D_0032FB08[];
extern s32 D_001DA040;
s32 func_0039A130(u32 i) {
    s32 r = 0;
    if (i < 0x3C) {
        s32 v = D_0032FB08[i];
        if (v != 0) {
            D_001DA040 = v;
            r = 1;
        }
    }
    return r;
}
/* localdecomp:end func_0039A130 */

/* localdecomp:start func_0039A170 */
typedef struct { u8 p0[0x8]; s16 h8; s16 hA; s32 fC; s16 h10; u8 p1[2]; s32 f14; u16 f18; u8 p2[0xA]; s32 (*f24)(s32); s32 f28; s16 f2c; s16 f2e; } E_39A170;
extern E_39A170 *D_0032FB08_0039A170[];
extern E_39A170 *D_001DA040_0039A170;
extern s32 D_001DA03C;
extern u8 D_001D5570[8];
extern s32 func_0039A3B0(s32, s32, s32);
extern void func_00399F80();
static __inline__ u8 isEnd_39A170(E_39A170 *e) {
    s32 r = 1;
    if (e != 0 && e->h8 != 0) r = 0;
    return r;
}
s32 func_0039A170(u32 i) {
    E_39A170 *e, *f, *g;
    s32 j;
    s32 r;
    if (i >= 0x3C) return 0;
    if (D_0032FB08_0039A170[i] == 0) return 0;
    func_0039A130(i);
    if (D_001DA040_0039A170 == 0) return 0;
    for (j = 0; isEnd_39A170(e = &D_0032FB08_0039A170[i][j]) == 0; j++) {
        if ((e->f18 & 4) && D_001D5570[i] == 0) {
            e->f2c = 0;
            continue;
        }
        if (func_0039A3B0(i, e->hA, e->fC) == 0) {
            if (e->f2c != 0) func_00399F80();
            e->f2c = 0;
            continue;
        }
        if (func_0039A3B0(i, e->h10, e->f14) == 0) {
            if (e->f2c != 1) {
                e->f2c = 1;
                func_0039A040(i, j);
                func_00399F80();
            }
            continue;
        }
        if (e->f2c != 2) {
            func_00399F80();
            e->f2c = 2;
            func_0039A040(i, j);
        }
    }
    for (j = 0; isEnd_39A170(f = &D_001DA040_0039A170[j]) == 0; j++) {
        if (f->f24 != 0) {
            r = f->f24(f->f28);
            D_001DA040_0039A170[j].f2e = r;
        }
    }
    D_001DA03C = 0;
    for (g = D_001DA040_0039A170; isEnd_39A170(g) == 0; g++) {
        if (g->f2c == 1 && !(g->f18 & 2)) D_001DA03C++;
    }
    return *(volatile s32 *)&D_001DA03C == 0;
}
/* localdecomp:end func_0039A170 */

/* localdecomp:start func_0039A3B0 */
typedef struct { s32 p[3]; s32 fC; } E_39A3B0;
extern u8 D_1D5530[8];
extern u8 D_142CA0[];
extern u8 D_142D40[];
extern E_39A3B0 D_143230_0039A3B0[];
extern u8 D_1426E0[];
extern u32 D_142BA0[];
extern u8 D_1BBB18[];
extern u8 D_1D5570[];
extern s32 func_0037DCF0_0039A3B0(s32, s32);
s32 func_0039A3B0(a0, kind, a2)
    s32 a0;
    s16 kind;
    s32 a2;
{
    switch (kind) {
    case 1:
        return D_1D5530[a2] != 0;
    case 2:
        return D_142CA0[a2] != 0;
    case 3:
        return D_142D40[a2] != 0;
    case 4:
        if (a2 < 0x72) return D_143230_0039A3B0[a2].fC != 0;
        return 0;
    case 5:
        if (a2 < 0x72) return D_143230_0039A3B0[a2].fC >= 2;
        return 0;
    case 6:
        return D_1426E0[a2] != 0;
    case 7:
        if (a2 != 0) return ((s32 (*)())a2)() != 0;
    case 9:
        return (D_142BA0[(u32)a2 >> 2] & (1 << (a2 & 0x1F))) != 0;
    case 8:
        return D_1BBB18[(a2 & 0xFFFF) + (a2 >> 16) * 8] != 0;
    case 10:
        return func_0037DCF0_0039A3B0(a0, a2);
    case 11:
        return D_1D5570[a2] != 0;
    case 12:
        break;
    }
    return 0;
}
/* localdecomp:end func_0039A3B0 */

/* localdecomp:start func_0039A518 */
s32 func_0039A518(u8 *p) {
    return *p == 0;
}
/* localdecomp:end func_0039A518 */

LINKER_REMNANT("asm/remnants", func_0039A528);

/* localdecomp:start func_0039A550 */
extern u8 D_00142734[];

s32 func_0039A550(s32 k) {
    if ((u32)(k - 0x1F) < 5) {
        k -= 0x1E;
        if ((u32)k < 8) {
            return (D_00142734[0] >> k) & 1;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_0039A550 */

/* localdecomp:start func_0039A590 */
extern u8 D_00142734[];
s32 func_0039A590(void) {
    s32 v = D_00142734[0] & 0x1e;
    return v == 0x1e;
}
/* localdecomp:end func_0039A590 */

/* localdecomp:start func_0039A5A8 */
extern s32 func_0039A550();
void func_0039A5A8(void) {
    func_0039A550(0x21);
}
/* localdecomp:end func_0039A5A8 */

/* localdecomp:start func_0039A5C8 */
extern s32 func_0039A550();
s32 func_0039A5C8(void) {
    return func_0039A550(0x22);
}
/* localdecomp:end func_0039A5C8 */

/* localdecomp:start func_0039A5E8 */
extern u8 D_001D5550[];
extern s32 func_0039A5C8();
s32 func_0039A5E8(void) {
    s32 r = 0;
    if (D_001D5550[0] != 0) r = func_0039A5C8() != 0;
    return r;
}
/* localdecomp:end func_0039A5E8 */

/* localdecomp:start func_0039A620 */
extern s32 func_0039A550();
void func_0039A620(void) {
    func_0039A550(0x20);
}
/* localdecomp:end func_0039A620 */

/* localdecomp:start func_0039A640 */
extern s32 D_001D68B8[2];
extern u8 D_00142CA0[];
extern u32 D_00142C34[];
extern s32 func_0039A6E0();
extern s32 func_0037DC30(s32, s32);
s32 func_0039A640(void) {
    s32 i;
    s32 *p;
    if ((D_00142C34[0] & 0x200000) == 0) return 0;
    if (func_0039A6E0()) return 1;
    i = 0;
    p = D_001D68B8;
    for (; i < 5; i++, p++) {
        if (func_0037DC30(*p, -1) && D_00142CA0[*p] == 0) return 1;
    }
    return 0;
}
/* localdecomp:end func_0039A640 */

/* localdecomp:start func_0039A6E0 */
extern u8 D_142CA0[];
extern s32 D_001D68B8[2];
s32 func_0039A6E0(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (D_142CA0[D_001D68B8[i]] == 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_0039A6E0 */

/* localdecomp:start func_0039A720 */
extern u8 D_001427B2[];
 
s32 func_0039A720(void) {
    return D_001427B2[0] & 1;
}
/* localdecomp:end func_0039A720 */

/* localdecomp:start func_0039A730 */
extern u8 D_001427B2[];
 
s32 func_0039A730(void) {
    return D_001427B2[0] & 2;
}
/* localdecomp:end func_0039A730 */

/* localdecomp:start func_0039A740 */
typedef struct { u8 pad[0x25]; u8 f25; u8 pad2[0x0d]; u8 f33; } S_1426E0;
extern S_1426E0 D_001426E0;
s32 func_0039A740(void) {
    return D_001426E0.f25 != 0 && D_001426E0.f33 != 0;
}
/* localdecomp:end func_0039A740 */

/* localdecomp:start func_0039A768 */
extern s32 D_00142C4C[];
s32 func_0039A768(void) {
    s32 v = D_00142C4C[0] & 0x4000;
    return v != 0;
}
/* localdecomp:end func_0039A768 */

/* localdecomp:start func_0039A780 */
extern u16 D_001A8E74[];
extern u8 D_00142CBF[];
s32 func_0039A780(void) {
    if (D_001A8E74[0] != 0) {
        return D_00142CBF[0] == 0;
    }
    return 0;
}
/* localdecomp:end func_0039A780 */

LINKER_REMNANT("asm/remnants", func_0039A7A8);

/* localdecomp:start func_0039A7B0 */
s32 func_0039A7B0(u8 *p, s32 a, s32 b, s32 i) {
    for (; i < 0x60; i++) {
        if (p[i * 2] - 1 == a && p[i * 2 + 1] == b) return i;
    }
    return -1;
}
/* localdecomp:end func_0039A7B0 */

/* localdecomp:start func_0039A7F8 */
extern s32 func_0039A518(u8 *);
extern s32 func_0039A7B0(u8 *, s32, s32, s32);
extern void func_00388550(u8 *, u8 *, s32);
s32 func_0039A7F8(u8 *p, s32 a, s32 b) {
    s32 i;
    s32 j;
    u8 *q;
    for (i = 0; i < 0x5F && !(p[i * 2] - 1 == a && p[i * 2 + 1] == b); i++) {
        j = i * 2;
        q = p + j;
        if (func_0039A518(q) == 0) {
            if (func_0039A518(q) != 0) continue;
            if ((D_0032FB08_0039A040[q[0] - 1][q[1]].f0 & 0xFF) < (D_0032FB08_0039A040[a][b].f0 & 0xFF)) continue;
        }
        if (func_0039A7B0(p, a, b, i) != -1) continue;
        func_00388550((u8 *)0x70000000, q, (0x5F - i) * 2);
        q[1] = b;
        q[0] = a + 1;
        func_00388550(&p[j + 2], (u8 *)0x70000000, (0x5F - i) * 2);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_0039A7F8 */

/* localdecomp:start func_0039A980 */
extern s32 func_0039A7B0(u8 *, s32, s32, s32);
extern void func_00388550(u8 *, u8 *, s32);
s32 func_0039A980(u8 *p, s32 a, s32 b) {
    s32 r = func_0039A7B0(p, a, b, 0);
    if (r >= 0) {
        func_00388550(&p[r * 2], &p[r * 2 + 2], (0x5F - r) * 2);
        p[0xBE] = 0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_0039A980 */

/* localdecomp:start func_0039A9E0 */
extern u8 D_001426E0_0039A9E0[];
extern s32 func_00399F90();
s32 func_0039A9E0(s32 bit) {
    s32 b = bit % 8;
    s32 i = bit / 8;
    s32 r;
    if ((u32)b < 8) { r = (D_001426E0_0039A9E0[0x40 + i] >> b) & 1; } else { r = 0; }
    if ((u32)b < 8) { D_001426E0_0039A9E0[0x40 + i] |= 1 << b; }
    func_00399F90();
    return r;
}
/* localdecomp:end func_0039A9E0 */

LINKER_REMNANT("asm/remnants", func_0039AA80);

/* localdecomp:start func_0039AAF0 */
typedef struct { u8 p0[0xC]; s32 fC; s32 f10; s32 f14; u8 p1[0x10]; s32 f28; } S_39AAF0;
extern S_39AAF0 D_00229000_0039AAF0;
extern u32 D_001D545C;
extern s32 D_00143140[];
extern s32 func_003895E8();
extern void func_0039ABB0();
void func_0039AAF0(void *arg0) {
    S_39AAF0 *p = &D_00229000_0039AAF0;
    s32 r;
    if (p->f10 != 0) {
        if (p->f28 == 0) {
            func_00388440(arg0, 0, 0x800);
            return;
        }
        func_0039A9E0(D_001D545C);
        r = func_003895E8(arg0, 0x800, p->f14, p->fC);
        if (r == -1) func_0039ABB0(arg0);
        if (D_00143140[D_001D545C] < r) D_00143140[D_001D545C] = r;
    }
}
/* localdecomp:end func_0039AAF0 */

LINKER_REMNANT("asm/remnants", func_0039ABA0);

/* localdecomp:start func_0039ABB0 */
typedef struct { u8 b[0x40]; } T_39ABB0;
extern T_39ABB0 D_001D6CF8;
extern u8 *D_0022900C[];
void func_0039ABB0(u8 *out) {
    s32 acc[0x80];
    s32 tbl2[16];
    u8 *src;
    u8 *o;
    s32 i, j, k, m;
    src = D_0022900C[0];
    o = out;
    *(T_39ABB0 *)tbl2 = D_001D6CF8;
    for (i = 0; i < 0x200; i++) {
        if (i % 4 == 0) func_00388440(acc, 0, 0x200);
        for (k = 0; k < 0x80; k += 2) {
            u8 b = *src++;
            acc[k] += tbl2[b & 0xF];
            acc[k + 1] += tbl2[b >> 4];
        }
        if (i % 4 == 3) {
            for (j = 0; j < 0x80; j++) {
                if (acc[j] < 8) acc[j] = 0;
                else acc[j] = 1 << (j % 8);
            }
            for (m = 0; m < 0x80; m += 8) {
                *o++ = (u8)acc[m] | (u8)acc[m + 1] | (u8)acc[m + 2] | (u8)acc[m + 3] | (u8)acc[m + 4] | (u8)acc[m + 5] | (u8)acc[m + 6] | (u8)acc[m + 7];
            }
        }
    }
    out[0] &= 0xFE;
}
/* localdecomp:end func_0039ABB0 */
TEXT_PADDING(2);

/* localdecomp:start func_0039AE08 */
typedef struct { u8 b[0x20]; } R_39AE08;
typedef struct { u8 p0[0x80]; f32 f80; f32 f84; f32 f88; } S_39AE08;
__asm__(".extern D_001D68E0, 8");
__asm__(".extern D_001D6900, 8");
__asm__(".extern D_001D6920, 8");
__asm__(".extern D_001D6960, 8");
__asm__(".extern D_001D69A0, 8");
__asm__(".extern D_001D69E0, 8");
__asm__(".extern D_001D6A20, 8");
__asm__(".extern D_001D6A40, 8");
__asm__(".extern D_001D6A60, 8");
extern u8 D_001D68E0[8];
extern u8 D_001D6900[8];
extern u8 D_001D6920[8];
extern u8 D_001D6960[8];
extern u8 D_001D6980[8];
extern u8 D_001D69A0[8];
extern u8 D_001D69C0[8];
extern u8 D_001D69E0[8];
extern u8 D_001D6A00[8];
extern u8 D_001D6A20[8];
extern u8 D_001D6A40[8];
extern u8 D_001D6A60[8];
extern R_39AE08 D_0032FBF8[];
extern R_39AE08 D_003303D8;
extern R_39AE08 D_003303B8;
extern R_39AE08 D_00330398;
extern R_39AE08 D_0032FD18;
extern R_39AE08 D_0032FE58;
extern R_39AE08 D_0032FE98;
extern R_39AE08 D_0032FED8;
extern s32 D_00228CD0[];
extern f32 D_001A4C60[];
extern S_39AE08 D_1A4BE0_0039AE08;
extern u8 D_001A71C4[];
R_39AE08 *func_0039AE08(s32 lvl, s32 sub) {
    s32 k;
    f32 x, y;
    if (sub == -1) k = D_00228CD0[0] - 1; else k = sub;
    if (sub == -1) sub = D_00228CD0[0];
    switch (lvl) {
    case 1:
        if (D_001A4C60[0] <= 300.0f) return (R_39AE08 *)D_001D68E0;
        return &D_0032FBF8[lvl];
    case 2:
        x = D_1A4BE0_0039AE08.f80;
        if (116.91f <= x) {
            y = D_1A4BE0_0039AE08.f84;
            if (y <= 331.38f && x <= 276.94f && 155.16f <= y) return (R_39AE08 *)D_001D6900;
        }
        return &D_0032FBF8[lvl];
    case 3:
        x = D_001A4C60[0];
        if (452.0f < x) return &D_003303D8;
        if (261.0f < x) return &D_003303B8;
        return &D_00330398;
    case 4:
        if (sub > 0) return (R_39AE08 *)D_001D6920 + k;
        break;
    case 7:
        if (D_1A4BE0_0039AE08.f88 < 130.0f) return (R_39AE08 *)D_001D6980;
        if (600.0f < D_1A4BE0_0039AE08.f84) return (R_39AE08 *)D_001D6960;
        return &D_0032FBF8[lvl];
    case 9:
        if (sub == 2) return (R_39AE08 *)D_001D69A0;
        if (sub == 1) return (R_39AE08 *)D_001D69C0;
        return &D_0032FD18;
    case 10:
        if (sub > 0) return (R_39AE08 *)D_001D6A00;
        return (R_39AE08 *)D_001D69E0;
    case 19:
        if (sub > 0) return (R_39AE08 *)D_001D6A20;
        return &D_0032FE58;
    case 21:
        if (525.0f < D_001A4C60[0]) return (R_39AE08 *)D_001D6A40;
        return &D_0032FE98;
    case 23:
        if (D_001A71C4[0] == 2) return (R_39AE08 *)D_001D6A60;
        return &D_0032FED8;
    case 5: case 6: case 8: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 20: case 22:
        break;
    }
    return &D_0032FBF8[lvl];
}
/* localdecomp:end func_0039AE08 */

LINKER_REMNANT("asm/remnants", func_0039B0E8);

/* localdecomp:start func_0039B0F8 */
typedef struct { u8 pad[0x10]; f32 f10; f32 f14; u8 pad2[0xE0]; f32 fF8; } O_39B0F8;
typedef struct { f32 x, y, z, w; } V_39B0F8;
extern u32 D_001D545C;
extern s32 D_00333530[];
extern O_39B0F8 *D_00228960[];
extern V_39B0F8 D_143230[];
void func_0039B0F8(void) {
    s32 i;
    if (D_001D545C < 0x13) {
        for (i = D_00333530[D_001D545C]; i < D_00333530[D_001D545C + 1]; i++) {
            O_39B0F8 *o = D_00228960[i];
            if (o) {
                D_143230[i].x = o->f10;
                D_143230[i].y = o->f14;
                D_143230[i].z = o->fF8;
            }
        }
    }
}
/* localdecomp:end func_0039B0F8 */
