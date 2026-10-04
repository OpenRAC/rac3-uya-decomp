#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/nonmatchings/text", func_0037E0F0);

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

INCLUDE_ASM("asm/nonmatchings/text", func_0037E368);

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

INCLUDE_ASM("asm/nonmatchings/text", func_0037E630);

LINKER_REMNANT("asm/remnants", func_0037E7C8);

/* localdecomp:start func_0037E7D8 */
void func_003885F0_0037E7D8(void *, void *, s32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_00222500[];
extern u8 D_00224B90[];
extern u8 D_002254D0[];

void func_0037E7D8(s32 arg0) {
    s32 temp_s1;
    void *temp_s0;
    void *temp_s2;

    temp_s2 = (arg0 * 0xB0) + D_00224B90;
    { S_00222500_0037E7D8 *p = &D_00222500[arg0]; func_003885F0_0037E7D8(temp_s2, p->f50, 0xB0); }
    temp_s1 = arg0 * 0x780;
    temp_s0 = temp_s1 + D_002254D0;
    func_003885F0_0037E7D8(temp_s0, temp_s1 + (D_002254D0 - 0x500), 0x280);
    (*(void **)((u8 *)(temp_s2) + 0x70)) = temp_s0;
}
/* localdecomp:end func_0037E7D8 */
TEXT_PADDING(2);

INCLUDE_ASM("asm/nonmatchings/text", func_0037E878);

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

INCLUDE_ASM("asm/nonmatchings/text", func_0037E9B0);

LINKER_REMNANT("asm/remnants", func_0037EA98);

/* localdecomp:start func_0037EAA0 */
s32 func_0037DD20_0037EAA0(void *, s32, s32, s32);           /* extern */
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
            (*(s32 *)((u8 *)(temp_s0) + 0xC4)) = func_0037DD20_0037EAA0(temp_a2 + (D_00222560 - 0x60), arg0, temp_a2, arg0);
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

INCLUDE_ASM("asm/nonmatchings/text", func_0037EB68);

INCLUDE_ASM("asm/nonmatchings/text", func_0037EE80);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_00318080);

/* localdecomp:start func_0037F090 */
extern S_37D000 D_0037D000[];
void func_0037F090(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_0037D000[*(s16 *)(p + 0x8C)].e;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_0037F090 */

INCLUDE_ASM("asm/nonmatchings/text", func_0037F0D8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F228);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F420);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F4F8);

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

INCLUDE_ASM("asm/nonmatchings/text", func_0037F588);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F7A8);

INCLUDE_ASM("asm/nonmatchings/text", func_0037F978);

/* localdecomp:start func_0037FEE8 */
extern u8 D_002227A0_0037FEE8[];
extern u8 D_00222500_0037FEE8[];
extern s32 func_0037F7A8_0037FEE8();
extern s32 func_0037F978_0037FEE8();
void func_0037FEE8(u8 *o) {
    u8 *e;
    u8 *d;
    s32 r;
    e = D_002227A0_0037FEE8 + *(s32 *)(o + 0x94) * 0x460;
    if (e[2] == 0) {
        r = func_0037F7A8_0037FEE8(o, e + 0x10);
    } else {
        r = func_0037F978_0037FEE8(o, e + 0x70);
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

INCLUDE_ASM("asm/nonmatchings/text", func_003801C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003804A0);

INCLUDE_ASM("asm/nonmatchings/text", func_00380600);
TEXT_PADDING(2);

INCLUDE_ASM("asm/nonmatchings/text", func_003807F0);
TEXT_PADDING(2);

INCLUDE_ASM("asm/nonmatchings/text", func_003808E0);

/* localdecomp:start func_003809F0 */
typedef struct { u128_t q0; u128_t q1; u8 pad[0x360]; f32 f380[4]; f32 f390[4]; f32 f3a0[4]; f32 f3b0[4]; f32 f3c0[4]; f32 f3d0[4]; u128_t q3e0; u8 pad2[0x70]; } E_003809F0;
extern E_003809F0 D_00222500_003809F0[];
extern u128_t D_00222480_003809F0[];
extern void func_003885F0_003809F0();
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
    D_00222480_003809F0[0] = v;
    D_00222480_003809F0[1] = D_00222500_003809F0[idx].q1;
    func_003885F0_003809F0(&D_00222480_003809F0[2], D_00222500_003809F0[idx].f380, 0x30);
}
/* localdecomp:end func_003809F0 */

INCLUDE_ASM("asm/nonmatchings/text", func_00380AB0);
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_00380D28);

INCLUDE_ASM("asm/nonmatchings/text", func_00380D48);

INCLUDE_ASM("asm/nonmatchings/text", func_003810C0);

INCLUDE_ASM("asm/nonmatchings/text", func_003813E0);

LINKER_REMNANT("asm/remnants", func_00381A48);

INCLUDE_ASM("asm/nonmatchings/text", func_00381A50);

INCLUDE_ASM("asm/nonmatchings/text", func_00381C18);

LINKER_REMNANT("asm/remnants", func_00381D90);

INCLUDE_ASM("asm/nonmatchings/text", func_00381DD0);

LINKER_REMNANT("asm/remnants", func_00381F10);

INCLUDE_ASM("asm/nonmatchings/text", func_00381F18);

INCLUDE_ASM("asm/nonmatchings/text", func_003821E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003822C8);

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

INCLUDE_ASM("asm/nonmatchings/text", func_00382458);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_003180A0);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003838C0);

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
__asm__(".extern D_001D58D0_00384420, 4");
__asm__(".extern D_001D5884_00384420, 1");

typedef int u128_00384420 __attribute__((mode(TI)));
typedef struct { u8 pad[0x450]; s32 x450; u8 pad454[0xC]; } P_00384420;
typedef struct { u8 pad0[4]; s16 x4; } C_00384420;
typedef struct { u128_00384420 q[4]; } Q_00384420;

extern C_00384420 *D_001DA670_00384420;
extern s32 D_001D9C44_00384420;
extern s32 D_001D9D9C_00384420;
extern s32 D_001D9388_00384420;
extern s32 D_001D938C_00384420;
extern s32 D_001D9C90_00384420;
extern s32 D_001D9C94_00384420;
extern u8 D_001D58D0_00384420;
extern s32 D_001D5B94_00384420;
extern s32 D_001D9C88_00384420;
extern s32 D_001D9C8C_00384420;
extern s32 D_001D93A4_00384420;
extern s32 D_001D93A8_00384420;
extern s32 D_001D9CB8_00384420;
extern volatile s32 D_001D9F40_00384420;
extern s32 D_001D52F0_00384420;
extern P_00384420 D_00222500_00384420[];
extern u8 D_001D5780_00384420;
extern u8 D_001D5781_00384420;
extern u8 D_001D5782_00384420;
extern u8 D_001D5783_00384420;
extern f32 D_001D9C50_00384420;
extern f32 D_001D9C58_00384420[2];
extern s32 D_001D5B98_00384420;
extern u8 D_001D5884_00384420;
extern s32 D_001D58B8_00384420;
extern u8 D_100AE0_00384420[];
extern s32 D_00143950_00384420[];
extern f32 D_001D9D90_00384420;
extern s32 D_001D9DD0_00384420;
extern u8 D_002F9C80_00384420[];
extern u8 D_00302540_00384420[];
extern Q_00384420 D_00225B20_00384420;
extern Q_00384420 D_00330F00_00384420;

extern void func_0038DB18_00384420(s32);
extern void func_00381F18_00384420(void);
extern void func_003BD8A0_00384420(void);
extern void func_00382F40_00384420(void);
extern void func_003838C0_00384420(void);
extern void func_00388278_00384420(void);
extern void func_003C9B80_00384420(void);
extern void func_003A4720_00384420(s32);
extern void func_003D47A0_00384420(void);
extern void func_003A4188_00384420(void);
extern void func_00384B68_00384420(s32);
extern void func_00385750_00384420(void);
extern void func_00384C98_00384420(void);
extern void func_003A4128_00384420(void);
extern void func_003D99D8_00384420(void);
extern void func_00386608_00384420(u8 *);
extern void func_003857C8_00384420(void);
extern void func_00383FD8_00384420(void);
extern void func_003BE340_00384420(void);
extern void func_003856D8_00384420(void);
extern void func_003A3EF0_00384420(s32, unsigned long);
extern void func_00380D48_00384420(void);
extern void func_00385980_00384420(void);
extern void func_11F0A0_00384420(s32);
extern void func_003C7E68_00384420(void);
extern void func_00385890_00384420(void);
extern void func_003D3050_00384420(s32);
extern void func_003D30D0_00384420(void);
extern void func_003D3CF0_00384420(s32);
extern void func_00385908_00384420(void);
extern void func_00381A50_00384420(s32);
extern void func_0038DEB0_00384420(void);
extern s32 func_0039BEA8_00384420(s32);
extern void func_00386210_00384420(void);
extern void func_003A4758_00384420(s32);
extern void func_003AA0B8_00384420(void);
extern void func_00391FD8_00384420(void);
extern void func_003ADB40_00384420(void);
extern void func_003ADBB0_00384420(s32);
extern void func_003ADB78_00384420(void);
extern void func_0037DD08_00384420(void);
extern void func_00385E40_00384420(void);
extern void func_003866E8_00384420(s32, s32, s32, s32);
extern void func_00386488_00384420(void);
extern void func_003A3A40_00384420(void *);
extern void func_003A3DA0_00384420(s32);
extern void func_003CAC10_00384420(void *);
extern void func_003C9AE0_00384420(void);
extern void func_003D8218_00384420(void);
extern void func_003D46E0_00384420(void);
extern void func_003DB5C0_00384420(void *);
extern void func_003D98D0_00384420(void);
extern void func_003BDC90_00384420(void);
extern void func_003821E8_00384420(s32);

void func_00384420(s32 arg0) {
    s32 t;
    s32 t2;
    f32 d, n;
    u128_00384420 *src, *dst;

    if (D_001DA670_00384420 == 0 || D_001DA670_00384420->x4 != 0 || ((*(u8 *)&D_001D9C44_00384420 ^ 1) & 1)) {
        func_0038DB18_00384420(0);
    }
    func_00381F18_00384420();
    func_003BD8A0_00384420();
    func_00382F40_00384420();
    func_003838C0_00384420();
    D_001D9D9C_00384420 = -1;
    D_001D9388_00384420 = 0;
    D_001D938C_00384420 = 0;
    if (D_001DA670_00384420 != 0 && (D_001D9C44_00384420 & 1)) {
        func_00388278_00384420();
    }
    if (D_001D9C44_00384420 & 2) {
        func_003C9B80_00384420();
    }
    func_003A4720_00384420(0x2010000);
    if (D_001D9C44_00384420 & 4) {
        func_003D47A0_00384420();
    }
    func_003A4720_00384420(0x2020000);
    if ((D_001D9C44_00384420 & 0x20) && D_001D9C90_00384420 != 0) {
        func_003A4188_00384420();
        func_00384B68_00384420(1);
        func_00385750_00384420();
        func_00384C98_00384420();
        func_003A4128_00384420();
    }
    if (D_001D9C44_00384420 & 8) {
        func_003D99D8_00384420();
    }
    func_003A4720_00384420(0x2040000);
    if (D_001D58D0_00384420) {
        func_00386608_00384420(&D_001D58D0_00384420);
    }
    if ((D_001D9C44_00384420 & 0x20) && D_001D9C94_00384420 != 0) {
        func_003A4188_00384420();
        func_00384B68_00384420(1);
        func_003857C8_00384420();
        func_00384C98_00384420();
        func_003A4128_00384420();
    }
    if (D_001D9C44_00384420 & 0x10) {
        if (D_001D5B94_00384420 == 2) {
            func_00383FD8_00384420();
        } else {
            func_003BE340_00384420();
        }
    }
    func_003A4720_00384420(0x2080000);
    func_00384B68_00384420(0);
    if (D_001D9C44_00384420 & 0x20) {
        func_003A4188_00384420();
        if (D_001D9C88_00384420 != 0) {
            func_003856D8_00384420();
        }
        func_003A3EF0_00384420(0x42, 0x8000000048);
        func_00380D48_00384420();
        func_003A4188_00384420();
        func_00385980_00384420();
        func_003A3EF0_00384420(8, 5);
        func_003A4188_00384420();
        func_003A3EF0_00384420(0x47, 0x53001);
        func_11F0A0_00384420(0);
        func_003C7E68_00384420();
        D_001D9D9C_00384420 = 9;
        func_003A3EF0_00384420(0x47, 0x5360B);
        if (D_001D9C8C_00384420 != 0) {
            func_003A4188_00384420();
            func_00385890_00384420();
        }
        func_00384C98_00384420();
        if (D_001D9388_00384420 != 0) {
            func_003D3050_00384420(0);
            if (D_001D9388_00384420 != 0) {
                func_003D30D0_00384420();
            }
        }
        if (D_001D93A4_00384420 != 0) {
            func_003D3CF0_00384420(0);
        }
        t2 = D_001D93A4_00384420;
        D_001D93A4_00384420 = 0;
        D_001D93A8_00384420 = t2;
        func_00384B68_00384420(0);
        if (D_001D9CB8_00384420 != 0) {
            func_003A4188_00384420();
            func_00385908_00384420();
        }
        func_003A3EF0_00384420(0x42, 0x8000000044);
        func_00381A50_00384420(arg0);
        func_00384C98_00384420();
    }
    func_0038DEB0_00384420();
    func_00384B68_00384420(0);
    func_003A4188_00384420();
    if ((D_001D9C44_00384420 & 0x180) && func_0039BEA8_00384420(3) == 0) {
        func_003A3EF0_00384420(0x47, 0x33001);
        func_00386210_00384420();
        if (D_001D9C44_00384420 & 0x80) {
            func_003A4758_00384420(0);
            func_003AA0B8_00384420();
            t = D_001D9F40_00384420;
            func_00391FD8_00384420();
            D_001D9F40_00384420 = t;
            func_003ADB40_00384420();
            func_003ADBB0_00384420(D_001D52F0_00384420);
            func_003ADB78_00384420();
            func_0037DD08_00384420();
        }
    }
    if (D_001D5B94_00384420 == 2) {
        func_00385E40_00384420();
    }
    func_00384C98_00384420();
    if (D_001D9C44_00384420 & 0x40) {
        func_003A3EF0_00384420(0x42, 0x8000000044);
        if (((P_00384420 *)((u8 *)D_00222500_00384420 + arg0 * sizeof(P_00384420)))->x450 != 0) {
            func_003866E8_00384420(D_001D5780_00384420, D_001D5781_00384420, D_001D5782_00384420, D_001D5783_00384420);
        }
        if (D_001D9C50_00384420 > 0.0f && D_001D5B98_00384420 == 0) {
            if (D_001D9C50_00384420 > 1.0f) {
                D_001D9C50_00384420 = 1.0f;
            }
            func_003866E8_00384420(0, 0, 0, D_001D9C50_00384420 * 128.0f);
        }
        if (D_001D9C58_00384420[0] > 0.0f && D_001D5B98_00384420 == 0) {
            if (D_001D9C58_00384420[0] > 1.0f) {
                D_001D9C58_00384420[0] = 1.0f;
            }
            func_003866E8_00384420(0xFF, 0xFF, 0xFF, D_001D9C58_00384420[arg0] * 128.0f);
        }
        if (D_001D5884_00384420 && D_001D58B8_00384420 != 0) {
            func_00386488_00384420();
        }
    }
    func_003A3A40_00384420(D_100AE0_00384420);
    func_11F0A0_00384420(0);
    n = *(volatile u32 *)0x10000800;
    D_001D9D90_00384420 = n / (D_00143950_00384420[0] != 0 ? 11520.0f : 9600.0f);
    func_003A3DA0_00384420(2);
    if (D_001D9C44_00384420 & 2) {
        func_003CAC10_00384420(D_002F9C80_00384420);
        func_003C9AE0_00384420();
    }
    func_003A3DA0_00384420(4);
    if (D_001D9C44_00384420 & 4) {
        src = (u128_00384420 *)&D_00225B20_00384420;
        dst = (u128_00384420 *)&D_00330F00_00384420;
        dst[0] = src[0];
        dst[1] = src[-1];
        dst[2] = src[2];
        func_003D8218_00384420();
        func_003D46E0_00384420();
    }
    func_003A3DA0_00384420(8);
    if (D_001D9C44_00384420 & 8) {
        func_003DB5C0_00384420(D_00302540_00384420);
        func_003D98D0_00384420();
    }
    func_003A3DA0_00384420(0x10);
    if (D_001D9C44_00384420 & 0x10) {
        func_003BDC90_00384420();
    }
    func_003821E8_00384420(arg0);
    D_001D9DD0_00384420 = 0;
}
/* localdecomp:end func_00384420 */

LINKER_REMNANT("asm/remnants", func_00384B48);

INCLUDE_ASM("asm/nonmatchings/text", func_00384B68);

INCLUDE_ASM("asm/nonmatchings/text", func_00384C98);

INCLUDE_ASM("asm/nonmatchings/text", func_00384DA0);
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_00384EB0);

INCLUDE_ASM("asm/nonmatchings/text", func_00384EC0);

INCLUDE_ASM("asm/nonmatchings/text", func_00385438);

/* localdecomp:start func_00385570 */
extern s32 D_001D4BB0_00385570;
extern s32 D_001DA0D0_00385570;
extern u8 D_003314E0_00385570[];
extern u8 D_00331550_00385570[];
extern void func_00388550();
extern void func_003A40C8();
s32 func_00385570(s32 a, s32 b) {
    u8 *p;
    s32 h = D_001D4BB0_00385570 >> 8;
    if (b == 0x14) {
        func_00388550(D_001DA0D0_00385570, D_003314E0_00385570, 0x70);
        D_001D4BB0_00385570 = D_001D4BB0_00385570 + 0x100;
    } else {
        func_00388550(D_001DA0D0_00385570, D_00331550_00385570, 0x70);
        D_001D4BB0_00385570 = D_001D4BB0_00385570 + 0x400;
    }
    p = (u8 *)D_001DA0D0_00385570;
    *(s32 *)(p + 0x64) = a;
    *(s16 *)(p + 0x24) = h;
    D_001DA0D0_00385570 = D_001DA0D0_00385570 + 0x70;
    func_003A40C8();
    return h;
}
/* localdecomp:end func_00385570 */

INCLUDE_ASM("asm/nonmatchings/text", func_00385628);

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

INCLUDE_ASM("asm/nonmatchings/text", func_00385980);

INCLUDE_ASM("asm/nonmatchings/text", func_00385B60);

INCLUDE_ASM("asm/nonmatchings/text", func_00385CE0);

INCLUDE_ASM("asm/nonmatchings/text", func_00385E40);

INCLUDE_ASM("asm/nonmatchings/text", func_00386210);

INCLUDE_ASM("asm/nonmatchings/text", func_00386488);

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

INCLUDE_ASM("asm/nonmatchings/text", func_003866E8);

INCLUDE_ASM("asm/nonmatchings/text", func_003867F8);

LINKER_REMNANT("asm/remnants", func_003869E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003869E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00386D98);

LINKER_REMNANT("asm/remnants", func_00386F28);

INCLUDE_ASM("asm/nonmatchings/text", func_00386F38);

INCLUDE_ASM("asm/nonmatchings/text", func_00387118);

INCLUDE_ASM("asm/nonmatchings/text", func_003872F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003875A0);

INCLUDE_ASM("asm/nonmatchings/text", func_00387A00);

INCLUDE_ASM("asm/nonmatchings/text", func_00387B10);

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

INCLUDE_ASM("asm/nonmatchings/text", func_00387DC8);
TEXT_PADDING(2);

INCLUDE_ASM("asm/nonmatchings/text", func_00388018);

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
