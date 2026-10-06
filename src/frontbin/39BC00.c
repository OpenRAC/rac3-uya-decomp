#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_0039BEC0(s32, s32, s32, s32, u8 *);
extern void func_0039C2A8(void);
extern s32 func_0039D510(s32, s32, s32);
extern void func_0039C1C8(s32 a, s32 idx);
extern void func_0039BD48(void);
extern void func_0039CEA8();
extern s32 func_0039BEA8(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_0039D4D0(void);
extern void func_0039CBA0(void);
extern s32 func_0039D668(s32, s32, s32);
extern s32 func_0039D5F8();
extern s32 func_0039D5A8();
extern s32 func_0039D668();
/* --- end of declarations from other files --- */

/* localdecomp:start func_0039BC00 */
void func_0039BC00(void) {
    __asm__ volatile (
        "lui $3, 0x8\n"
        "addi $3, $3, 0x200\n"
        "mtc0 $3, $25\n"
    );
}
/* localdecomp:end func_0039BC00 */

ASM_FUNC("asm/handwritten", func_0039BC18);

ASM_FUNC("asm/handwritten", func_0039BC40);

ASM_FUNC("asm/handwritten", func_0039BC70);

ASM_FUNC("asm/handwritten", func_0039BC80);

/* localdecomp:start func_0039BC90 */
void func_0039BC90(void) {
    __asm__ __volatile__(
        "sync.p\n"
    );
}
/* localdecomp:end func_0039BC90 */

/* localdecomp:start func_0039BCA0 */
void func_0039BCA0(void) {
    __asm__ volatile (
        "sync.p\n"
        "mfc0 $8, $24\n"
        "lui $9, 0x7fff\n"
        "ori $9, $9, 0xffff\n"
        "and $8, $8, $9\n"
        "mtc0 $8, $24\n"
        "sync.p\n"
    );
}
/* localdecomp:end func_0039BCA0 */

ASM_FUNC("asm/handwritten", func_0039BCC8);

ASM_FUNC("asm/handwritten", func_0039BD08);

/* localdecomp:start func_0039BD40 */
s32 func_0039BD40(void) {
}
/* localdecomp:end func_0039BD40 */

/* localdecomp:start func_0039BD48 */
extern s32 D_001D5B94_0039BD48;
extern s32 D_001D5B90_0039BD48;
extern s32 D_001D5B8C;
extern s32 D_001D6D98;
extern s32 D_001D6D9C_0039BD48;
extern s32 D_001D6DA0_0039BD48;
extern u8 *D_001D6DA8_0039BD48;
extern f32 D_00225A30[];
extern void func_003A3508(void);
extern void func_0037E568(s32, s32, s32, f32, f32, f32, f32);
extern void func_003830E8();
extern void func_003A3368();
extern void func_003ADC70();
void func_0039BD48(void) {
    s32 a = D_001D5B94_0039BD48;
    s32 t;
    u8 *v;
    s32 s;
    D_001D5B8C = a;
    if (D_001D5B90_0039BD48 == -2) return;
    t = D_001D6D98;
    if (t > 0) {
        D_001D6D98 = t - 1;
        return;
    }
    switch (a) {
    case 1:
        func_003A3508();
        D_00225A30[0] = 0.62f;
        func_0037E568(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_003830E8();
        break;
    case 0:
    case 2:
    case 4:
    case 18:
        break;
    }
    switch (D_001D5B90_0039BD48) {
    case 1:
        func_003A3368(D_001D6DA0_0039BD48);
        v = D_001D6DA8_0039BD48;
        break;
    case 18:
        func_003ADC70(D_001D6D9C_0039BD48);
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    default:
        v = D_001D6DA8_0039BD48;
        break;
    }
    if (v) *v = 1;
    s = D_001D5B90_0039BD48;
    D_001D5B90_0039BD48 = -2;
    D_001D5B94_0039BD48 = s;
    D_001D6DA8_0039BD48 = 0;
}
/* localdecomp:end func_0039BD48 */

LINKER_REMNANT("asm/remnants", func_0039BE90);

/* localdecomp:start func_0039BEA0 */
extern s32 D_001D6D98;
void func_0039BEA0(s32 a) {
    D_001D6D98 = a;
}
/* localdecomp:end func_0039BEA0 */

extern s32 D_001D5B90[];
/* localdecomp:start func_0039BEA8 */
extern s32 D_001D5B90[];

s32 func_0039BEA8(s32 a0) {
    return D_001D5B90[0] == a0;
}
/* localdecomp:end func_0039BEA8 */

extern s32 D_001D5B90[];
extern s32 D_001D5B94[];
extern s32 D_001D4CEC[];
extern u8  D_001D5B78[];
extern s32 D_001DA050[];
extern s32 D_001A7430[];
extern s32 D_001D6DA4[];
extern s32 D_001D6D9C[];
extern s32 D_001D6DA0[];
extern s32 D_001D6DA8[];

extern s32 D_001D5B90[];
extern s32 D_001D5B94[];
extern s32 D_001D4CEC[];
extern u8  D_001D5B78[];
extern s32 D_001DA050[];
extern s32 D_001A7430[];
extern s32 D_001D6DA4[];
extern s32 D_001D6D9C[];
extern s32 D_001D6DA0[];
extern s32 D_001D6DA8[];
INCLUDE_ASM("asm/nonmatchings/text", func_0039BEC0);

INCLUDE_ASM("asm/nonmatchings/text", func_0039BF98);

LINKER_REMNANT("asm/remnants", func_0039C020);

/* localdecomp:start func_0039C028 */
__asm__(".extern D_001DA0D0_0039C02A, 4");
extern u32 *D_001DA0D0_0039C028;
extern u32 *D_001DA0D0_0039C02A;
extern s32 D_00227480_0039C028[];
extern s32 D_00225780_0039C028[];
extern u32 D_001D4CF8_0039C028;
extern u8 D_001D0560[];
extern void func_00385CE0();
extern void func_00385E40();
void func_0039C028(u32 *a0) {
    D_001DA0D0_0039C028 = a0;
    a0[0] = 0x30000009;
    D_001DA0D0_0039C028[1] = (*(u32 *)0x1D4CF8 + 0xC0) & 0x0FFFFFFF;
    D_001DA0D0_0039C028[2] = 0;
    D_001DA0D0_0039C028[3] = 0x50000009;
    D_001DA0D0_0039C028[4] = 0x30000025;
    D_001DA0D0_0039C028[5] = (u32)D_001D0560;
    D_001DA0D0_0039C028[6] = 0;
    D_001DA0D0_0039C028[7] = 0x50000025;
    D_001DA0D0_0039C028 += 8;
    D_00225780_0039C028[13] += 1;
    if (D_00227480_0039C028[0] != 0) {
        func_00385CE0();
        a0 = D_001DA0D0_0039C02A;
    } else {
        func_00385E40();
        a0 = D_001DA0D0_0039C028;
    }
    a0[0] = 0x70000000;
    D_001DA0D0_0039C028[1] = 0;
    D_001DA0D0_0039C028 += 4;
}
/* localdecomp:end func_0039C028 */

/* localdecomp:start func_0039C158 */
void func_0039C158(s32 a0, long a1) {

    s32 *p = (s32 *)(u32)a1;
    if (p != 0) {
        *p = a0;
    }
}
/* localdecomp:end func_0039C158 */

/* localdecomp:start func_0039C170 */
extern s32 func_0039C158_0039C170();
extern void func_0013BAB8(s32, s32, void *, unsigned long, s32);
typedef struct { u8 p0[0x79A4]; s32 f79A4; u8 p1[0x10]; s32 f79B8; } S_C170a;
typedef struct { u8 p0[0x90]; u32 f90; } S_C170b;
extern S_C170a D_00160C40[];
extern S_C170b D_001A30B0_0039C170[];
void func_0039C170(void) {
    D_001A30B0_0039C170[0].f90 = 0xFFFFFFFF;
    func_0013BAB8(D_00160C40[0].f79B8 + D_00160C40[0].f79A4, 0, &func_0039C158_0039C170, (unsigned long) ((long) &D_001A30B0_0039C170[0].f90 << 0x20) >> 0x20, D_00160C40[0].f79A4);
}
/* localdecomp:end func_0039C170 */

/* localdecomp:start func_0039C1C8 */
typedef struct { u8 pad[0x90]; u32 a[1]; } S_39C1C8;
extern S_39C1C8 D_001A30B0_0039C1C8[];
extern void func_0039C158();
extern void func_13BC30(s32, void *, unsigned long);
void func_0039C1C8(s32 a, s32 idx) {
    S_39C1C8 *s = D_001A30B0_0039C1C8;
    u32 *q = s->a;
    u32 *p = q + idx;
    *p = 0xFFFFFFFF;
    func_13BC30(a, func_0039C158, (u32)p);
}
/* localdecomp:end func_0039C1C8 */

/* localdecomp:start func_0039C210 */
typedef struct { u8 pad[0x90]; u32 a[1]; u32 b[1]; } S_39C210;
typedef struct { s32 v; s32 w; } E_39C210;
typedef struct { u8 pad0[0x79A4]; s32 f79A4; u8 pad1[0x79E8 - 0x79A8]; E_39C210 e[1]; } G_39C210;
extern S_39C210 D_001A30B0_0039C210[];
extern G_39C210 D_00160C40_0039C210[];
extern void func_0039C158();
extern void func_13BAB8(s32, s32, void *, unsigned long);
void func_0039C210(s32 idx) {
    G_39C210 *g = D_00160C40_0039C210;
    s32 v = g->e[idx].v;
    S_39C210 *s;
    u32 *q;
    if (v) {
        s = D_001A30B0_0039C210;
        q = s->b;
        s->a[idx + 1] = 0xFFFFFFFF;
        func_13BAB8(v + g->f79A4, 0, func_0039C158, (u32)(q + idx));
    } else {
        D_001A30B0_0039C210->a[idx + 1] = 0;
    }
}
/* localdecomp:end func_0039C210 */

/* localdecomp:start func_0039C2A8 */
extern void func_13CF40(void (*)());
extern void func_0039D770();
 
void func_0039C2A8(void) {
    func_13CF40(func_0039D770);
}
/* localdecomp:end func_0039C2A8 */

/* localdecomp:start func_0039C2C8 */
void func_0039C2C8(s32 a0, s32 *a1) {
    if (a0 >= 0x1770) {
        *a1 = 6;
    } else {
        *a1 = 2;
    }
}
/* localdecomp:end func_0039C2C8 */

/* localdecomp:start func_0039C2E8 */
typedef struct { s32 a, b; } P_39C2E8;
typedef struct { P_39C2E8 l[0x29]; s32 pad; } R_39C2E8;
typedef union {
    struct { u8 p[0x1284]; s32 base; } d;
    struct { u8 p[0x1E78]; P_39C2E8 t[1]; } c;
    struct { u8 p[0x224C]; s32 base; s32 t[1]; } g;
    struct { u8 p[0x2648]; s32 t[1][400]; } a;
    struct { u8 p[0x7A04]; s32 base; P_39C2E8 e[1]; } b;
    struct { u8 p[0x921C]; s32 base; } h;
} S_160C40_39C2E8;
typedef struct { u8 p[0xB7]; u8 fB7; } S_143950_39C2E8;
extern S_160C40_39C2E8 D_160C40_0039C2E8;
extern R_39C2E8 D_1DBC0[];
extern R_39C2E8 D_169E60[];
extern R_39C2E8 D_169E64[];
extern R_39C2E8 D_1DBC4[];
extern S_143950_39C2E8 D_00143950_0039C2E8;
void func_0039C2E8(s32 id, s32 *out1, s32 *out2) {
    *out1 = 0;
    *out2 = 0;
    if (id >= 7000) {
        s32 v;
        s32 l = D_00143950_0039C2E8.fB7;
        if (l) l--;
        v = *(D_160C40_0039C2E8.a.t[l] - 7000 + id);
        if (v) *out1 = v + D_160C40_0039C2E8.g.base;
    } else if (id >= 6000) {
        s32 v;
        s32 l = D_00143950_0039C2E8.fB7;
        if (l) l--;
        l -= 6000;
        v = D_160C40_0039C2E8.b.e[id + l].a;
        if (v) *out1 = D_160C40_0039C2E8.b.base + v;
    } else if (id >= 5000) {
        s32 v;
        v = D_160C40_0039C2E8.c.t[id - 5000].a;
        if (v) *out1 = D_160C40_0039C2E8.d.base + v;
    } else if (id >= 4000) {
        s32 v;
        v = *(s32 *)((u8 *)&D_1DBC0[id] + D_00143950_0039C2E8.fB7 * 8);
        if (v) {
            s32 w;
            *out1 = D_160C40_0039C2E8.d.base + v;
            w = D_1DBC4[id].l[D_00143950_0039C2E8.fB7].a;
            if (w) *out2 = D_160C40_0039C2E8.d.base + w;
        }
    } else if (id >= 3000) {
        s32 v;
        v = D_160C40_0039C2E8.b.e[id - 3000].a;
        if (v) *out1 = D_160C40_0039C2E8.b.base + v;
    } else if (id >= 2000) {
        s32 v;
        s32 l = D_00143950_0039C2E8.fB7;
        if (l) l--;
        l -= 2000;
        v = D_160C40_0039C2E8.b.e[id + l].a;
        if (v) *out1 = D_160C40_0039C2E8.b.base + v;
    } else if (id >= 1000) {
        s32 v;
        s32 l = D_00143950_0039C2E8.fB7;
        if (l) l--;
        l -= 1000;
        v = D_160C40_0039C2E8.g.t[id + l];
        if (v) *out1 = D_160C40_0039C2E8.g.base + v;
    } else {
        s32 v;
        v = *(s32 *)((u8 *)&D_169E60[id] + D_00143950_0039C2E8.fB7 * 8);
        if (v) {
            s32 w;
            *out1 = D_160C40_0039C2E8.h.base + v;
            w = D_169E64[id].l[D_00143950_0039C2E8.fB7].a;
            if (w) *out2 = D_160C40_0039C2E8.h.base + w;
        }
    }
}
/* localdecomp:end func_0039C2E8 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039C548);

/* localdecomp:start func_0039C710 */
extern void func_00388440(void *, s32, s32);
extern void func_00388550(u8 *, u8 *, s32);
extern void func_0013CC40(s32);
typedef struct {
    u8 pad0[0x6C];
    s32 f6C;
    u8 pad1[0x76 - 0x70];
    s16 f76;
    u8 pad2[0x94 - 0x78];
    s32 f94;
    s16 f98;
    u8 pad3[0x9E - 0x9A];
    s16 f9E;
    u8 pad4[0xB4 - 0xA0];
    s32 fB4;
} S_001CCFD0_0039C710;
extern S_001CCFD0_0039C710 D_001CCFD0_0039C710[];
s32 func_0039C710(void) {
    S_001CCFD0_0039C710 *p = D_001CCFD0_0039C710;

    if (p->f76 == 0 && p->f9E == 3) {
        if (p->f94 != 0) {
            func_00388550((u8 *)&p->f6C, (u8 *)&p->f94, 0x28);
            func_00388440(&p->f94, 0, 0x28);
            p->f98 = -1;
            p->fB4 = -1;
            func_0013CC40(p->f6C);
            p->f76 = 4;
            return 1;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_0039C710 */

/* localdecomp:start func_0039C7B0 */
typedef struct { u8 pad0[0x44]; u32 f44; s16 f48; s16 f4A; s16 f4C; s16 f4E; u8 pad50[4]; s16 f54; u8 pad56[2]; s32 f58; s32 f5C; } S_1CCFD0_0039C7B0;
typedef struct { u8 pad[0x7A04]; s32 base; struct { s32 a; s32 b; } e[1]; } S_160C40_0039C7B0;
extern S_1CCFD0_0039C7B0 D_1CCFD0_0039C7B0;
extern S_160C40_0039C7B0 D_160C40_0039C7B0;
extern void func_0039D8B0(s32, long);
extern void func_13CB20(long,long,s32,s32,s16,s32,s32,s32,s32,s32,void*,unsigned long);
void func_0039C7B0(s32 a0, s32 a1, s32 a2) {
 long y4, y5;
 if (D_1CCFD0_0039C7B0.f44 == 0) {
 if (D_160C40_0039C7B0.e[a0].a != 0) {
D_1CCFD0_0039C7B0.f44 = 0xFFFFFFFF;
D_1CCFD0_0039C7B0.f4E = 1;
D_1CCFD0_0039C7B0.f48 = a0;
D_1CCFD0_0039C7B0.f4A = a2;
y5 = D_160C40_0039C7B0.e[a0 + 1].a + D_160C40_0039C7B0.base;
y4 = D_160C40_0039C7B0.e[a0].a + D_160C40_0039C7B0.base;
D_1CCFD0_0039C7B0.f4C = a1;
D_1CCFD0_0039C7B0.f58 = 10;
D_1CCFD0_0039C7B0.f5C = 0xBB80;
D_1CCFD0_0039C7B0.f54 = 0;
func_13CB20((s32)y4, (s32)y5, 0, 0, (s16)a2, 0, 1, 0, 0, 1, func_0039D8B0, (u32)&D_1CCFD0_0039C7B0.f44);
}}}
/* localdecomp:end func_0039C7B0 */

/* localdecomp:start func_0039C8A8 */
typedef struct { u8 p0[0x44]; u32 f44; s16 f48; s16 f4A; s16 f4C; s16 f4E; u8 p50[4]; s16 f54; u8 p56[2]; s32 f58; s32 f5C; } S_CFD0_8A8;
typedef struct { u8 p0[0x7A04]; s32 f7A04; s32 t[1]; } S_160_8A8;
extern S_CFD0_8A8 D_1CCFD0_0039C8A8;
extern S_160_8A8 D_00160C40_0039C8A8;
extern void func_0039D9C8();
extern void func_13CB20(long,long,s32,s32,s16,s32,s32,s32,s32,s32,void*,unsigned long);
void func_0039C8A8(s32 a, s32 b, s32 c) {
 long x, y; s32 t;
 if (a >= 0) { if (D_1CCFD0_0039C8A8.f44 == 0) { t = D_00160C40_0039C8A8.t[a*2]; if (t != 0) {
D_1CCFD0_0039C8A8.f48 = a;
x = t + D_00160C40_0039C8A8.f7A04;
D_1CCFD0_0039C8A8.f44 = 0xFFFFFFFF;
D_1CCFD0_0039C8A8.f4E = 1;
D_1CCFD0_0039C8A8.f4C = b;
D_1CCFD0_0039C8A8.f58 = 10;
D_1CCFD0_0039C8A8.f4A = c;
D_1CCFD0_0039C8A8.f5C = 0xBB80;
D_1CCFD0_0039C8A8.f54 = 0;
y = D_00160C40_0039C8A8.t[(a+1)*2] + D_00160C40_0039C8A8.f7A04;
func_13CB20((s32)x, (s32)y, 0, 0, c, 0, 1, 0, 0, 0, func_0039D9C8, (unsigned long)((long)&D_1CCFD0_0039C8A8.f44 << 0x20) >> 0x20);
}}}}
/* localdecomp:end func_0039C8A8 */

/* localdecomp:start func_0039C9A0 */
typedef struct { u8 p0[0x44]; u32 f44; s16 f48; s16 f4A; s16 f4C; s16 f4E; u8 p50[4]; s16 f54; u8 p56[2]; s32 f58; s32 f5C; } S_1CCFD0_39C9A0;
typedef struct { u8 p0[0x7A04]; s32 base; struct { s32 a; s32 b; } e[1]; } S_160C40_39C9A0;
extern S_1CCFD0_39C9A0 D_1CCFD0_0039C9A0;
extern S_160C40_39C9A0 D_160C40_0039C9A0;
extern void func_0039D970();
extern void func_13CB20(long,long,s32,s32,s16,s32,s32,s32,s32,s32,void*,unsigned long);
void func_0039C9A0(s32 a0, s32 a1, s32 a2) {
    u32 t; long x, y;
    if (D_1CCFD0_0039C9A0.f4E != 9) {
        t = D_1CCFD0_0039C9A0.f44;
        if (t != 0) {
          if (t != 0xFFFFFFFFu) {
            if (D_160C40_0039C9A0.e[a0 + 1].a != 0) {
                D_1CCFD0_0039C9A0.f48 = a0;
                y = D_160C40_0039C9A0.e[a0 + 2].a + D_160C40_0039C9A0.base;
                D_1CCFD0_0039C9A0.f4E = 9;
                x = D_160C40_0039C9A0.e[a0 + 3].a + D_160C40_0039C9A0.base;
                D_1CCFD0_0039C9A0.f58 = 10;
                D_1CCFD0_0039C9A0.f5C = 0xBB80;
                D_1CCFD0_0039C9A0.f4A = a2;
                D_1CCFD0_0039C9A0.f4C = a1;
                D_1CCFD0_0039C9A0.f54 = 0;
                func_13CB20((s32)x, (s32)y, 0, 0, (s16)a2, 0, 1, t, 0, (a1 & 1) << 2, func_0039D970, (u32)&D_1CCFD0_0039C9A0.f44);
            }
          }
        }
    }
}
/* localdecomp:end func_0039C9A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039CAB8);

/* localdecomp:start func_0039CBA0 */
typedef struct {
    u8 p0[0x2C]; s16 f2C; u8 p2E[0xE]; s16 f3C; s16 f3E; u8 p40[4];
    s32 f44; s16 f48; u8 p4A[2]; s16 f4C; s16 f4E; u8 p50[0x1C];
    s32 f6C; u8 p70[4]; s16 f74; s16 f76; u8 p78[0x1C];
    s32 f94; u8 p98[4]; s16 f9C; s16 f9E; u8 pA0[0x1C];
    s32 fBC; u8 pC0[4]; s16 fC4; s16 fC6;
} S_1CCFD0_39CBA0;
__asm__(".extern D_001D6DB8_0039CBA0, 4");
extern S_1CCFD0_39CBA0 D_1CCFD0_0039CBA0;
extern s32 D_001D6DB8_0039CBA0;
extern s32 D_001DA070_0039CBA0;
extern s32 func_13B620_0039CBA0();
extern void func_13CA28(void);
extern void func_13CAE8();
extern s32 func_12C908(s32);
extern void func_13CD00();
void func_0039CBA0(void) {
    S_1CCFD0_39CBA0 *s;
    s32 t;
    D_001D6DB8_0039CBA0 = 1;
    D_001DA070_0039CBA0 = 0xB4;
    func_13CA28();
    func_13CAE8();
    while (func_13B620_0039CBA0() != 0) {
        func_12C908(0);
        t = D_001DA070_0039CBA0;
        if (t == 0) {
            break;
        }
        D_001DA070_0039CBA0 = t - 1;
    }
    func_13CD00(1);
    s = &D_1CCFD0_0039CBA0;
    s->f4E = 0;
    s->f4C = 0;
    s->f44 = 0;
    if (s->f3C != -1) {
        s->f48 = s->f3C;
    }
    s->f76 = 0;
    s->f74 = 0;
    s->f6C = 0;
    s->f9E = 0;
    s->f9C = 0;
    s->f94 = 0;
    s->fC6 = 0;
    s->fC4 = 0;
    s->fBC = 0;
    s->f2C = 0;
    s->f3C = -1;
    s->f3E = -1;
    D_001D6DB8_0039CBA0 = 0;
}
/* localdecomp:end func_0039CBA0 */

LINKER_REMNANT("asm/remnants", func_0039CC70);

typedef struct {
    u8 pad0[0x24];
    s32 f24;
    s32 f28;
    u8 pad1[0x24];
    u16 f50;
    u8 pad2[0x78 - 0x52];
    u16 f78;
    u8 pad3[0xc8 - 0x7a];
    u16 fc8;
} S_1CCFD0;
extern S_1CCFD0 D_001CCFD0;

/* localdecomp:start func_0039CC78 */

// Apply a single-zero address suffix identity here
extern S_1CCFD0 D_1CCFD0_0039CC78;

void func_0039CC78(void) {
    // Route assignments to point directly to the single-zero alias target
    D_1CCFD0_0039CC78.f50 = 4;
    D_1CCFD0_0039CC78.fc8 = 4;
    D_1CCFD0_0039CC78.f78 = 4;
}
/* localdecomp:end func_0039CC78 */

/* localdecomp:start func_0039CC98 */
typedef struct { u32 f0; s16 f4; s16 f6; s16 f8; s16 fA; s16 fC; u8 fE[2]; } S_39CC98;
extern void func_13C118(s32);
extern void func_13CC10(s32);
extern void func_13CC40(s32);
extern void func_13CC70(s32, void *, unsigned long);
extern void func_13CCA0(s32, void *, unsigned long);
extern void func_13C200(s32, void *, unsigned long);
extern void func_13CCD0(s32, void *, unsigned long);
extern s32 func_003883C8(void *);
extern void func_0039DA48(s32, long);
extern void func_0039DA60(s32, long);
extern void func_0039DA08(s32, long);
extern void func_0039D800(s32, long);
void func_0039CC98(S_39CC98 *s) {
    s32 h;
    if (s->fA != 9 && s->f0 != 0 && s->f0 != 0xFFFFFFFF) {
        if (s->fA == 5) {
            if (s->f0 == 0) {
                s->fA = 0;
            } else {
                func_13C118(s->f0);
                s->fA = 6;
            }
        } else if (s->fA == 6) {
            if (s->f0 == 0) s->fA = 0;
        }
        if (s->f0 != 0) {
            if (s->fC & 0x8000) {
                if (!(s->fA & 0x8000)) {
                    func_13CC10(s->f0);
                    s->fA |= 0x8000;
                }
                if (func_003883C8(s->fE) == 2) s->fC = 4;
            } else if (s->fA & 0x8000) {
                func_13CC40(s->f0);
                s->fA ^= 0x8000;
            }
            if (!(s->fA & 0x8000)) {
                if (s->fA == 1 || s->fA == 8 || s->fA == 9) {
                } else if (s->fA != 2 && s->fA != 3) {
                    h = s->f0;
                    s->f0 = 0xFFFFFFFF;
                    func_13CC70(h, func_0039DA48, (u32)s);
                    func_13CCA0(h, func_0039DA60, (u32)s);
                    func_13C200(h, func_0039DA08, (u32)s);
                } else if (s->f0 != 0xFFFFFFFF && s->fA == 2) {
                    func_13CCD0(s->f0, func_0039D800, (u32)s);
                }
            }
        }
    } else if (s->fA == 7 || s->f0 == 0) {
        s->fA = 0;
    }
    if (s->fA == 0) s->f4 = -1;
}
/* localdecomp:end func_0039CC98 */

INCLUDE_ASM("asm/nonmatchings/text", func_0039CEA8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318510);

/* localdecomp:start func_0039D4D0 */
typedef struct { u8 pad0[4]; s16 h4; u8 b6; } S_39D4D0;
extern S_39D4D0 D_001CCFD0_0039D4D0[];
extern s32 func_13CEB0(void);
void func_0039D4D0(void) {
    if (D_001CCFD0_0039D4D0->h4 != 0) {
        func_13CEB0();
        D_001CCFD0_0039D4D0->b6 = 1;
    }
}
/* localdecomp:end func_0039D4D0 */

/* localdecomp:start func_0039D510 */
s32 func_13CD28(s32, s32, s32, void *);             /* extern */
typedef struct { u8 pad0[0x4]; s16 f4; u8 pad6[0x2]; s32 f8; u8 padC[0x4]; s32 f10; s32 f14; s32 f18; s32 f1C; } S_001CCFD0_0039D510_0039D510;
extern S_001CCFD0_0039D510_0039D510 D_001CCFD0_0039D510[];

s32 func_0039D510(s32 arg0, s32 arg1, s32 arg2) {
    if ((D_001CCFD0_0039D510->f4 == 0) && (arg2 != 0)) {
        D_001CCFD0_0039D510->f18 = 0;
        D_001CCFD0_0039D510->f1C = 0;
        if (func_13CD28(arg1, arg2, arg0, (u8 *)D_001CCFD0_0039D510 + 0x40) != 0) {
            D_001CCFD0_0039D510->f14 = arg0;
            D_001CCFD0_0039D510->f4 = 1;
            D_001CCFD0_0039D510->f8 = arg1;
            D_001CCFD0_0039D510->f10 = arg2;
            return arg2 << 0xB;
        }
    }
    return 0;
}
/* localdecomp:end func_0039D510 */

/* localdecomp:start func_0039D5A8 */
extern s32 func_0039D510(s32, s32, s32);
extern s32 D_001CCFD0_0039D5A8[];
s32 func_0039D5A8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 r = func_0039D510(a0, a1, a2);
    if (r != 0) {
    D_001CCFD0_0039D5A8[6] = a3;
    D_001CCFD0_0039D5A8[7] = a4;
    }
    return r;
}
/* localdecomp:end func_0039D5A8 */

/* localdecomp:start func_0039D5F8 */
__asm__(".extern D_001D4D04, 4");
typedef struct { u8 b[4]; } B4_0039D5F8;
extern B4_0039D5F8 D_001CD010[];
extern u8 D_001D52E0;
extern s32 D_001D4D00;
extern s32 D_001D4D04;
extern void func_0013CD28();
extern void func_0013CA28();
extern void func_0013B620();
s32 func_0039D5F8(s32 a, s32 b, s32 c) {
    B4_0039D5F8 buf;
    buf = D_001CD010[0];
    buf.b[1] = D_001D52E0;
    D_001D4D00 = 0;
    D_001D4D04 = 0;
    func_0013CD28(b, c, a, &buf);
    func_0013CA28();
    func_0013B620();
    return 1;
}
/* localdecomp:end func_0039D5F8 */

/* localdecomp:start func_0039D668 */
extern s32 func_0039D6C8(s32);
extern s32 func_0039D510(s32, s32, s32);
s32 func_0039D668(s32 a, s32 b, s32 c) {
    s32 r;
    func_0039D6C8(1);
    r = func_0039D510(a, b, c);
    func_0039D6C8(1);
    return r;
}
/* localdecomp:end func_0039D668 */

/* localdecomp:start func_0039D6C8 */
typedef struct { u8 pad[4]; s16 s; u8 pad2[0x10]; } S_39D6C8;
extern S_39D6C8 D_1CCFD0_0039D6C8;
extern void func_0039CEA8();
extern void func_13CA28();
extern s32 func_13B620(void);
extern void func_13CA20();
extern void func_00388418();
s32 func_0039D6C8(s32 a) {
    if (a) {
        do {
            func_0039CEA8();
            func_13CA28();
            func_13B620();
            func_13CA20();
            if (D_1CCFD0_0039D6C8.s == 0) break;
            func_00388418(0x2710);
        } while (D_1CCFD0_0039D6C8.s != 0);
    } else {
        func_0039CEA8();
        func_13CA28();
        func_13B620();
        func_13CA20();
    }
    return D_1CCFD0_0039D6C8.s;
}
/* localdecomp:end func_0039D6C8 */

/* localdecomp:start func_0039D770 */
s32 func_0011F0A0(s32);                       /* extern */
s32 func_13CEF8();                                  /* extern */
typedef struct { s32 x0; s16 h4; u8 b6; u8 b7; u8 pad[0x10]; void *f18; s32 f1C; } S_39D770;
extern S_39D770 D_001CCFD0_0039D770[];

void func_0039D770(s32 arg0) {
    s32 (*temp_v1)(s32, s32);
    s32 temp_a0;
    s32 temp_a1;

    if (arg0 == 1) {
        if (D_001CCFD0_0039D770->h4 == 0) {
            D_001CCFD0_0039D770->f18 = 0;
            D_001CCFD0_0039D770->f1C = 0;
            return;
        }
        if (func_13CEF8() != 0) {
            D_001CCFD0_0039D770->h4 = 2;
            return;
        }
        func_0011F0A0(0);
        temp_v1 = (s32 (*)(s32, s32))D_001CCFD0_0039D770->f18;
        D_001CCFD0_0039D770->h4 = 0;
        temp_a1 = D_001CCFD0_0039D770->b6 == 0;
        D_001CCFD0_0039D770->b6 = 0U;
        if (temp_v1 != 0) {
            temp_a0 = D_001CCFD0_0039D770->f1C;
            D_001CCFD0_0039D770->f18 = 0;
            D_001CCFD0_0039D770->f1C = 0;
            temp_v1(temp_a0, temp_a1);
        }
    }
}
/* localdecomp:end func_0039D770 */

/* localdecomp:start func_0039D800 */
void func_0039D800(s32 a, long l) {
    s16 *p = (s16 *)(u32)l; 
    if (p != 0 && a != 0 && p[5] == 2) {
        p[5] = 3;
    }
}
/* localdecomp:end func_0039D800 */

/* localdecomp:start func_0039D830 */
typedef struct { u8 pad[0x48]; s16 f48, f4A, f4C; u8 pad2[0x46]; s32 f94; s16 f98, f9A, f9C; u8 pad3[0x12]; s32 fB0; } S_1CCFD0b;
extern S_1CCFD0b D_1CCFD0;
extern u8 D_001A30B0[];
extern void func_0039C548(s32, s32, s32, s32 *, s32);
void func_0039D830(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    s32 i;
    if (p == 0) return;
    i = *(s32 *)(p + 0x20);
    *(s32 *)p = a;
    if (i >= 0) { u8 *e = D_001A30B0 + (i << 7); *(s32 *)(e + 0xC0) = a; };
    if (a != 0) {
        if (*(s16 *)(p + 0xA) == 1) *(s16 *)(p + 0xA) = 2;
    } else {
        func_0039C548(D_1CCFD0.f98, D_1CCFD0.f9C, D_1CCFD0.fB0, &D_1CCFD0.f94, D_1CCFD0.f9A);
    }
}
/* localdecomp:end func_0039D830 */

/* localdecomp:start func_0039D8B0 */
extern s32 D_001D6DB8;
extern void func_0039C7B0(s32, s32, s32);
void func_0039D8B0(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    if (p == 0) return;
    *(s32 *)p = a;
    if (a != 0) {
        if (*(s16 *)(p + 0xA) == 1) *(s16 *)(p + 0xA) = 2;
    } else if (D_001D6DB8 == 0) {
        func_0039C7B0(D_1CCFD0.f48, D_1CCFD0.f4C, D_1CCFD0.f4A);
    } else {
        *(s16 *)(p + 0xA) = 0;
    }
}
/* localdecomp:end func_0039D8B0 */

/* localdecomp:start func_0039D920 */
extern s16 D_001CCFFC[];
void func_0039D920(s32 a0, long a1) {
    u8 *p = (u8 *)(s32)a1;
    if (p != 0) {
        *(s32 *)p = a0;
        if (a0 != 0) {
            if (*(s16 *)(p + 0xA) == 1) {
                *(s16 *)(p + 0xA) = 4;
                if (*(s16 *)(p + 0x10) != 0) {
                    D_001CCFFC[0] = 1;
                }
            }
        } else {
            *(s16 *)(p + 0xA) = 0;
        }
    }
}
/* localdecomp:end func_0039D920 */

/* localdecomp:start func_0039D970 */
typedef struct { s32 x0; s16 pad4; s16 pad6; s16 pad8; s16 hA; s16 padC; s16 padE; s16 h10; } S_39D970;
extern s16 D_001CCFFC[];
void func_0039D970(s32 a, long b) {
    S_39D970 *p = (S_39D970 *)(s32)b;
    if (p) {
        if (a < 0) p->x0 = a;
        if (a != 0) {
            if (p->hA == 9) {
                p->hA = 4;
                if (p->h10) D_001CCFFC[0] = 1;
            }
        } else {
            p->hA = 0;
        }
    }
}
/* localdecomp:end func_0039D970 */

/* localdecomp:start func_0039D9C8 */
void func_0039D9C8(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    if (p == 0) return;
    *(s32 *)p = a;
    if (a != 0) {
        if (*(s16 *)(p + 0xA) == 1) *(s16 *)(p + 0xA) = 8;
    } else {
        *(s16 *)(p + 0xA) = 0;
    }
}
/* localdecomp:end func_0039D9C8 */

/* localdecomp:start func_0039DA08 */
void func_0039DA08(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    if (p == 0) return;
    if (*(u32 *)p == 0xFFFFFFFF) {
        *(s32 *)p = a;
        if (a == 0) *(s16 *)(p + 0xA) = 7;
    }
}
/* localdecomp:end func_0039DA08 */

/* localdecomp:start func_0039DA48 */
void func_0039DA48(s32 a0, long a1) {

    s32 *p = (s32 *)(u32)a1;
    if (p != 0) {
        p[5] = a0;
    }
}
/* localdecomp:end func_0039DA48 */

/* localdecomp:start func_0039DA60 */
typedef struct { u8 pad[0x10]; s16 h10; u8 pad2[6]; s32 x18; } S_39DA60;
typedef struct { u8 pad[0x2C]; s16 h2C; s16 pad2; s32 x30; s32 x34; } S2_39DA60;
extern S2_39DA60 D_001CCFD0_0039DA60[];
void func_0039DA60(s32 a, long b) {
    S_39DA60 *p = (S_39DA60 *)(s32)b;
    if (p) {
        p->x18 = a;
        if (p->h10) {
            S2_39DA60 *d = D_001CCFD0_0039DA60;
            if (d->h2C == 1 && a != 0) {
                d->h2C = 2;
                d->x30 = p->x18;
                d->x34 = p->x18 / 4;
            }
        }
    }
}
/* localdecomp:end func_0039DA60 */

LINKER_REMNANT("asm/remnants", func_0039DAD0);

extern s32 D_001D6DE8[];
/* localdecomp:start func_0039DAE0 */
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    s32 f28;
} S_1CCFD0u;
extern S_1CCFD0u D_001CCFD0_0039DAE0;
extern s32 D_001D6DE8_0039DAE0;
void func_0039DAE0(s32 a0, s32 a1) {
    if (D_001D6DE8_0039DAE0 == 0) {
        D_001CCFD0_0039DAE0.f24 = a0;
        D_001CCFD0_0039DAE0.f28 = a1;
    }
}
/* localdecomp:end func_0039DAE0 */

LINKER_REMNANT("asm/remnants", func_0039DB00);
