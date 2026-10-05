#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern s32 func_00399F90();
extern void func_00399C90(s32, s32);
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

INCLUDE_ASM("asm/nonmatchings/text", func_003959A8);

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

INCLUDE_ASM("asm/nonmatchings/text", func_00395EB8);

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

INCLUDE_ASM("asm/nonmatchings/text", func_00397490);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318190);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318210);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318230);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_003182A0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_003182F0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318340);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318360);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318390);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_003183C0);

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

INCLUDE_ASM("asm/nonmatchings/text", func_00399C90);

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
extern void func_0039A7F8(u8 *, s32, s32);
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

INCLUDE_ASM("asm/nonmatchings/text", func_0039A170);

INCLUDE_ASM("asm/nonmatchings/text", func_0039A3B0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_003183E0);

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

INCLUDE_ASM("asm/nonmatchings/text", func_0039A7F8);

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

INCLUDE_ASM("asm/nonmatchings/text", func_0039ABB0);
TEXT_PADDING(2);

INCLUDE_ASM("asm/nonmatchings/text", func_0039AE08);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318410);

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
