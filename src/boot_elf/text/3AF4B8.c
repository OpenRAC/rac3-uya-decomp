#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 D_001D5C78;
extern void (*D_001D9AC0[2])(s32);
extern void func_003AF878(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
extern void func_11F940(s32);
extern f32 func_003AF4B8(f32, f32, f32, f32, f32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AF4B8 */
extern u8 D_001D8798[];
extern u8 D_001D87B0[];
extern void func_00116F98(void *, s32, void *);
f32 func_003AF4B8(f32 t, f32 p0, f32 m0, f32 m1, f32 p1) {
    f32 t2, t3;
    if (!(t >= 0.0f && t <= 1.0f)) {
        func_00116F98(D_001D8798, 0x24, D_001D87B0);
    }
    t2 = t * t;
    t3 = t2 * t;
    p0 *= 1.0f + (2.0f * t3 - 3.0f * t2);
    m0 *= t3 - 2.0f * t2 + t;
    m1 *= t3 - t2;
    p1 *= -(2.0f * t3) + 3.0f * t2;
    return p0 + m0 + m1 + p1;
}
/* localdecomp:end func_003AF4B8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AF5A0);

/* localdecomp:start func_003AF5C0 */
extern void func_003AF280(void *, s32);
void func_003AF5C0(void) {
    s32 i;
    if (D_001D5C78 != 0) {
        for (i = 0; i < 1; i++) {
            func_003AF280((void *)(D_001D5C78 + 0x1FCA8), i);
        }
    }
}
/* localdecomp:end func_003AF5C0 */

/* localdecomp:start func_003AF620 */
extern void func_003AC3F0();
__asm__(".extern D_001D5C78, 16");
void func_003AF620(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, u8 a9) {
    if (D_001D5C78 != 0) {
        func_003AC3F0(D_001D5C78 + 0x1FCA8, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
}
/* localdecomp:end func_003AF620 */

/* localdecomp:start func_003AF6B0 */
typedef s32 (*FN_A9EF0)();
typedef struct { FN_A9EF0 a; s32 b; } E_A9EF0;
typedef struct { u8 pad[0x24DD0]; void (*cb24DD0)(); u8 padA[0x14]; FN_A9EF0 cb24DE8; u8 padB[4]; E_A9EF0 e1[4]; E_A9EF0 e2[3]; } P_A9EF0;
extern P_A9EF0 *D_001D5C78_003AF6B0;
extern s32 D_001D9F40;
extern s32 D_001D5B94;
extern s32 func_003E1660();
extern void func_003AF5C0();
void func_003AF6B0(void) {
    s32 r, i, t;
    E_A9EF0 *e;
    if (D_001D9F40 == 0) {
        if (D_001D5C78_003AF6B0 != 0) {
            if (D_001D5C78_003AF6B0->cb24DE8 != 0) {
                if (D_001D5C78_003AF6B0->cb24DE8() != 0) return;
            }
            r = 0;
            for (i = 0; i < 4; i++) {
                if (D_001D5C78_003AF6B0->e1[i].a != 0) {
                    E_A9EF0 *e2 = (E_A9EF0 *)(i * 8 + (s32)D_001D5C78_003AF6B0 + 0x24DF0);
                    r |= e2->a();
                }
            }
            if (r != 0) return;
            for (i = 0; i < 3; i++) {
                if (D_001D5C78_003AF6B0->e2[i].a != 0) {
                    E_A9EF0 *e3 = (E_A9EF0 *)(i * 8 + (s32)D_001D5C78_003AF6B0 + 0x24E10);
                    r |= e3->a();
                }
            }
            if (r != 0) return;
        }
        t = D_001D5B94;
        if (t != 0 && t != 5 && t == 4) {
            if (func_003E1660() != 7) return;
        }
        if (D_001D5C78_003AF6B0 != 0) {
            D_001D5C78_003AF6B0->cb24DD0();
            func_003AF5C0();
        }
    }
}
/* localdecomp:end func_003AF6B0 */

/* localdecomp:start func_003AF840 */
extern s32 D_001D5C78;
extern s32 D_001D52F0;
void func_003AF840(void) {
    if (D_001D5C78 != 0) {
        func_003AF2A8(D_001D5C78 + 0x1FCA8, D_001D52F0);
    }
}
/* localdecomp:end func_003AF840 */

/* localdecomp:start func_003AF878 */
typedef s32 (*FN_AA0B8)();
typedef struct { s32 a; FN_AA0B8 f; } E_AA0B8;
typedef struct { u8 pad[0x24DCC]; void (*cb24DCC)(); u8 pad2[0x1C]; FN_AA0B8 cb24DEC; E_AA0B8 e1[4]; E_AA0B8 e2[3]; } P_AA0B8;
extern P_AA0B8 *D_001D5C78_003AF878;
extern s32 D_001D9F40;
extern s32 D_001D5B94;
typedef struct { u8 p0[0xB0]; f32 fB0; } G_AA0B8;
extern G_AA0B8 D_00225980[];
extern void func_00397ED8();
extern s32 func_003E1660();
extern void func_00387778();
extern void func_003AF840();
void func_003AF878(void) {
    s32 r, i, t;
    E_AA0B8 *e;
    G_AA0B8 *g;
    f32 sv;
    if (D_001D9F40 == 0) {
        if (D_001D5C78_003AF878 != 0) {
            func_00397ED8();
            r = 0;
            if (D_001D5C78_003AF878->cb24DEC != 0) r = D_001D5C78_003AF878->cb24DEC() != 0;
            for (i = 0; i < 4; i++) {
                if (D_001D5C78_003AF878->e1[i].f != 0) {
                    E_AA0B8 *e2 = (E_AA0B8 *)(i * 8 + (s32)D_001D5C78_003AF878 + 0x24DF0);
                    r |= e2->f();
                }
            }
            for (i = 0; i < 3; i++) {
                if (D_001D5C78_003AF878->e2[i].f != 0) {
                    E_AA0B8 *e3 = (E_AA0B8 *)(i * 8 + (s32)D_001D5C78_003AF878 + 0x24E10);
                    r |= e3->f();
                }
            }
            if (r != 0) return;
        }
        t = D_001D5B94;
        if (t != 0x11 && t != 0 && t != 5 && t == 4) {
            if (func_003E1660() != 7) return;
        }
        if (D_001D5C78_003AF878 != 0) {
            D_001D5C78_003AF878->cb24DCC();
            g = D_00225980;
            sv = g->fB0;
            g->fB0 = 0.62f;
            func_00387778();
            func_003AF840();
            g->fB0 = sv;
            func_00387778();
        }
    }
}
/* localdecomp:end func_003AF878 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AFA38);

/* localdecomp:start func_003AFA50 */
extern s32 D_001D5C78;
extern s32 D_0031D0D0[];
extern void func_00396860();
extern void func_003AF6B0();
void func_003AFA50(void) {
    if (D_001D5C78 != 0 && D_0031D0D0[0] == 0) {
        func_00396860(1);
        func_003AF6B0();
    }
}
/* localdecomp:end func_003AFA50 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AFA90);

/* localdecomp:start func_003AFAA8 */
extern s32 D_001DA10C;
extern s32 D_001DA110;
extern s32 D_001DA114;
extern s32 D_001DA118;
extern s32 D_001DA120;
extern s32 D_001DA124;
extern s32 D_001DA128;
extern s32 D_001DA12C;
extern s32 D_001DA108_003AFAA8;
extern s32 D_001DA11C_003AFAA8;
extern s32 D_001DA130_003AFAA8;
extern s32 D_001DA134_003AFAA8;
extern s32 D_001DA138_003AFAA8;
extern s32 D_001DA140[];
extern s32 D_001D4D40;
extern void func_003917C0();
extern s32 func_003AFC70();
extern void func_003B01C0();
extern void func_003AFFE8();
s32 func_003AFAA8(s32 a, s32 b, s32 (*alloc)(s32, s32), s32 c, s32 flag) {
    s32 i;
    s32 *p;
    s32 r;
    D_001DA10C = alloc(0x1A0000, 0x40);
    p = D_001DA140;
    D_001DA110 = alloc(0x4FC80, 0x40);
    D_001DA114 = alloc(0x1010, 0x40);
    D_001DA108_003AFAA8 = alloc(0x14, 0x40);
    D_001DA118 = alloc(0xEC800, 0x40);
    D_001DA11C_003AFAA8 = alloc(0x5000C, 0x40);
    D_001DA120 = alloc(0xC000, 0x40);
    D_001DA124 = alloc(0x80000, 0x40);
    D_001DA128 = alloc(0x4000, 0x40);
    D_001DA12C = alloc(0x3000, 0x40);
    D_001DA130_003AFAA8 = alloc(0xC, 0x40);
    D_001DA134_003AFAA8 = alloc(0xB8, 0x40);
    D_001DA138_003AFAA8 = alloc(0x68, 0x40);
    for (i = 1; i >= 0; i--) {
        *p++ = alloc(0x4000, 0x80);
    }
    func_003917C0(flag != 0, flag != 0);
    func_003AFFE8(a, b, c);
    r = func_003AFC70(D_001DA134_003AFAA8, D_001DA11C_003AFAA8, D_001DA130_003AFAA8);
    func_003B01C0();
    D_001D4D40 = D_001D4D40 & ~0x80;
    return r;
}
/* localdecomp:end func_003AFAA8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AFC70);

/* localdecomp:start func_003AFFA0 */
// Declare the external game function target matching address 0x0011ECD0
extern void func_0011ECD0(s32 parameter);

// Signature must be void to eliminate the implicit return zero instruction (0x102d)
void func_003AFFA0(void) {
    // Calling this function with 1 triggers the 'li $a0, 1' optimization pass, 
    // which naturally slides directly into the jal branch delay slot at offset c:
    func_0011ECD0(1);
}
/* localdecomp:end func_003AFFA0 */

/* localdecomp:start func_003AFFC0 */
extern s32 func_003B05C0();
extern s32 D_001DA138[];

void func_003AFFC0(void) {
    func_003B05C0(D_001DA138[0]);
}
/* localdecomp:end func_003AFFC0 */

/* localdecomp:start func_003AFFE8 */
extern s32 D_001DA10C;
extern s32 D_001DA110;
extern s32 D_001DA108_003AFFE8;
extern s32 D_001DA114;
extern s32 D_001DA118;
extern s32 D_001DA11C_003AFFE8;
extern s32 D_001DA120;
extern s32 D_001DA124;
extern s32 D_001DA128;
extern s32 D_001DA12C;
extern s32 D_001DA130_003AFFE8;
extern s32 D_001DA134_003AFFE8;
extern s32 D_001DA138_003AFFE8;
extern s32 D_001DA148_003AFFE8;
extern u8 D_001DC8B0[1];
extern void func_003B1520();
extern void func_135B50();
extern s32 func_003B2690(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003B0288_003AFFE8();
extern void func_003B2798_003AFFE8();
extern void func_003B1208_003AFFE8();
extern void func_003B1320_003AFFE8();
extern void func_003B2E10();
extern void func_003B29E0();
extern s32 func_11EC20();
extern void func_11FD40();
extern void func_003B1618_003AFFE8();
extern void func_12D4D8();
extern void func_003B0F78();
extern s32 func_11EB30();
extern void func_003B1168();
extern void func_11F9A8();
typedef struct { s32 f0; void *f4; s32 f8; s32 fC; void *f10; s32 f14; s32 f18; s32 f1C; s32 f20; s32 pad[3]; } S_3AA828;
void func_003AFFE8(s32 a, s32 b, s32 c) {
    S_3AA828 s;
    s32 t;
    *(volatile u32 *)0x1000E000 |= 3;
    *(volatile u32 *)0x1000E010 = 4;
    func_003B1520(D_001DA11C_003AFFE8);
    func_135B50();
    func_003B2690(D_001DA134_003AFFE8, D_001DA118, 0xEC800, D_001DA124, D_001DA114, 0x100, D_001DA12C, 0x200);
    func_003B0288_003AFFE8(D_001DA138_003AFFE8, D_001DA120, 0xC000, 3);
    func_003B2798_003AFFE8(D_001DA134_003AFFE8, 0, 0, func_003B1208_003AFFE8, D_001DA11C_003AFFE8);
    func_003B2798_003AFFE8(D_001DA134_003AFFE8, 3, c, func_003B1320_003AFFE8, D_001DA11C_003AFFE8);
    func_003B2E10(D_001DA108_003AFFE8, (D_001DA10C & 0xFFFFFFF) | 0x20000000, D_001DA110, 2);
    s.f4 = func_003B29E0;
    s.fC = 0x4000;
    s.f14 = 1;
    s.f10 = D_001DC8B0;
    s.f20 = 0;
    s.f8 = D_001DA128;
    t = func_11EC20(&s);
    D_001DA148_003AFFE8 = t;
    func_11FD40(t, D_001DA134_003AFFE8);
    func_003B1618_003AFFE8(D_001DA130_003AFFE8, a, b);
    func_12D4D8(func_003B0F78);
    t = func_11EB30(2, func_003B1168, 0);
    *(s32 *)(D_001DA134_003AFFE8 + 0xB0) = t;
    func_11F9A8(2);
}
/* localdecomp:end func_003AFFE8 */

/* localdecomp:start func_003B01C0 */
typedef struct { u8 pad[0xB0]; s32 wB0; } S_AAA00;
extern void *D_001DA11C;
extern void *D_001DA108;
extern void *D_001DA148;
extern S_AAA00 *D_001DA134;
extern void *D_001DA138_003B01C0;
extern void *D_001DA130;
extern u8 D_0013D208[];
extern s32 func_003B1538();
extern s32 func_003B2E68();
extern void func_11EC70(void *);
extern void func_11EC30(void *);
extern void func_11EB50(s32, s32);
extern void func_12D4D8(u8 *);
extern s32 func_003B2800();
extern s32 func_003B0320();
extern s32 func_003B1630();
void func_003B01C0(void) {
    ((void (*)(void *))func_003B1538)(D_001DA11C);
    ((void (*)(void *))func_003B2E68)(D_001DA108);
    func_11EC70(D_001DA148);
    func_11EC30(D_001DA148);
    ((s32 (*)(s32))func_11F940)(2);  /* s32 return matters: keeps $v0 live */
    func_11EB50(2, D_001DA134->wB0);
    func_12D4D8(D_0013D208);
    ((void (*)(void *))func_003B2800)(D_001DA134);
    ((void (*)(void *))func_003B0320)(D_001DA138_003B01C0);
    ((void (*)(void *))func_003B1630)(D_001DA130);
    *(u32 *)0x1000E000 &= ~2;
}
/* localdecomp:end func_003B01C0 */

/* localdecomp:start func_003B0258 */
s32 func_003B0258(void) {
}
/* localdecomp:end func_003B0258 */
