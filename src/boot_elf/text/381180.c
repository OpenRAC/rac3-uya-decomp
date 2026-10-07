#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00381280(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_00381180 */
extern void func_00398040(s32, s32);

void func_00381180(void) {
    func_00398040(0, 0);
}
/* localdecomp:end func_00381180 */

/* localdecomp:start func_003811A0 */
extern void func_003BBA90(s32);
extern void func_003B3440(void *);
extern s32 func_003A1180(s32, s32, s32, s32, u8 *);
extern u8 D_001E2340[];

void func_003811A0(void) {
    func_003BBA90(1);
    func_003B3440(D_001E2340);
    func_003A1180(0x12, 1, 7, 0, 0);
}
/* localdecomp:end func_003811A0 */

/* localdecomp:start func_003811E0 */
extern void func_003BBA90(s32);
extern s32 func_003A1180(s32, s32, s32, s32, u8 *);

void func_003811E0(void) {
    func_003BBA90(1);
    func_003A1180(0x12, 1, 8, 0, 0);
}
/* localdecomp:end func_003811E0 */

/* localdecomp:start func_00381218 */
s32 func_00381218(void) {
}
/* localdecomp:end func_00381218 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00381220);

extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003F2580(s32, s32);
extern void * func_003AF2D0();
extern s32 D_001D5C78;

typedef struct {
    u8 pad[0x84];
    s32 f84;
} Struct227600;
extern Struct227600 D_00227600;

/* localdecomp:start func_00381228 */
extern s32 D_00227600_00381228[];
extern s32 D_001D5C78_00381228[];
extern void func_11A264(s32, s32, s32);
extern s32 func_003F2580(s32, s32);
extern void * func_003AF2D0();
void func_00381228(void) {
    s32 *p = D_00227600_00381228;
    func_11A264(p[0x84/4], 0xCD, 0x40000);
    D_001D5C78_00381228[0] = func_003AF2D0(func_003F2580(0x24F10, p[0x84/4]), 0x40000);
}
/* localdecomp:end func_00381228 */

/* localdecomp:start func_00381280 */
typedef struct { u8 p0[4]; s32 f4; u8 p8[4]; s32 fC; u8 p10[0x14]; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; } S_1A1ED0_37D200;
typedef struct { u8 p0[0x18]; u8 *f18; u8 p1C[0x5C]; s32 f78; } S_227600_37D200;
typedef struct { u8 p0[7]; u8 f7; u8 p8[0x1C]; s32 f24; u8 p28[0x14]; s16 f3C; u8 p3E[2]; u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; u8 p48[6]; s16 f4E; u8 p50[0x1C]; s32 f6C; u8 p70[6]; s16 f76; u8 p78[0x44]; s32 fBC; u8 pC0[6]; s16 fC6; } S_1CCFD0_37D200;
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x38]; s32 f688; s32 f68C; } S_160C40_37D200;
typedef struct { s32 f0; u8 p4[0xB3]; u8 fB7; } S_143950_37D200;
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_37D200;
typedef struct { u8 p0[0x2C]; s32 f2C; } S_318CC0_37D200;
typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } S_pad_37D200;
typedef struct { s32 a; s32 b; } E_37D200;
typedef struct { s32 off; s32 size; } H_37D200;

__asm__(".extern D_001D5750, 4");
__asm__(".extern D_001D574C, 4");
__asm__(".extern D_001D5758, 8");
__asm__(".extern D_001D5738, 8");
__asm__(".extern D_001D5680, 4");
__asm__(".extern D_001D5684, 4");
__asm__(".extern D_001D5688, 4");
__asm__(".extern D_001D568C, 4");
__asm__(".extern D_001D5690, 4");
__asm__(".extern D_001D5694, 4");

extern S_1A1ED0_37D200 D_001A1ED0;
extern S_227600_37D200 D_00227600_00381280;
extern S_1CCFD0_37D200 D_001CCFD0;
extern S_160C40_37D200 D_00160C40;
extern S_143950_37D200 D_00143950;
extern S_142430_37D200 D_00142430;
extern S_318CC0_37D200 D_0031CD00_00381280;
extern u8 D_001D5BDC;
extern s32 D_001D4BB0;
extern void *D_001D4B50;
extern s32 D_001A7430[];
extern s32 D_001D5B90;
extern s32 D_001D5B94;
extern s32 D_001D5B8C;
extern s32 D_001D9D88;
extern s32 D_001D9C48;
extern s32 D_001D5B9C;
extern s32 D_001D9DAC;
extern u8 D_0031CD50[];
extern void *D_001D9A20;
extern s32 D_001D5B74;
extern unsigned long D_001D4AC0;
extern s32 D_001D5750;
extern s32 D_001D574C;
extern E_37D200 D_001D5758[1];
extern s32 D_001D575C[2];
extern s32 D_001D5738[2];
extern void *D_001D52FC;
extern s32 D_001D5680;
extern s32 D_001D5684;
extern s32 D_001D5688;
extern s32 D_001D568C;
extern s32 D_001D5690;
extern s32 D_001D5694;
extern s32 D_00227480[];
extern s32 D_001D4D40;
extern s32 D_00142BA4[];
extern s32 D_001D9D84;
extern f32 D_001D9D8C;
extern u8 D_001D5570[8];

extern void func_003982E0(void);
extern s32 func_003A2858(s32, s32, s32);
extern void func_00392580(s32, long, long);
extern void func_003925D8(void);
extern void func_00392670(s32);
extern void func_00388320(void);
extern s32 func_12C908(s32);
extern void func_003925B0(void);
extern s32 func_003A2A10(s32);
extern void func_003A0A20(u8 *, u32);
extern void func_003A14B0(s32 a, s32 idx);
extern void func_00399118(void);
extern void func_003A1008(void);
extern void func_00381228(void);
extern s32 func_003B3068(void);
extern void func_003A9440(void);
extern void func_003A93C0(void);
extern void func_003926F0(void);
extern void func_00392A68(s32);
extern void func_003A3E30(void);
extern void func_00381CC0(void);
extern s32 func_13D3C8(void);
extern void func_13D3C0(s32);
extern s32 func_00392E40();
extern s32 func_00392F98();
extern void func_0038E478(s32);
extern void func_003B3268(void);
extern void func_003B32A0();
extern void func_003A9AA0_00381280(u8 *, s32, s32, s32);
extern void func_0038B148(s32, s32, s32, s32);
extern void func_003BB390(void);
extern s32 func_003E8780(s32 arg0, s32 *arg1);
extern s32 func_003E7258();
extern s32 func_003E8708(s32 a);
extern void *func_003B51D8();
extern void func_003E7250(void *);
extern s32 func_003E8698(s32 arg0);
extern s32 func_003A4548(void);
extern void func_003A96B0(s32, unsigned long);
extern void func_003895C8(s32);
extern void func_003B3300(void);
extern void func_003B3370(s32);
extern void func_003B3338(void);
extern s32 func_003823F0(s32);
extern void func_0038EB10_00381280(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
extern void func_003896F8(void);
extern void func_003A8D80(void);
extern void func_003A21F0();
extern void func_003B3B28(void);
extern void func_0039C6D8(void);
extern void func_0039B0A8(void);
extern void func_003A9560(s32);
extern void func_003884F0(void);
extern void func_003A7B40(void);

void func_00381280(void) {
    u8 *base;
    u8 *buf;
    s32 cur;
    s32 obj;

    D_001D5BDC = 1;
    func_003982E0();
    base = D_00227600_00381280.f18 + 0x400000;
    func_003A2858((s32)base, D_00160C40.f688 + D_00160C40.f64C, D_00160C40.f68C);
    buf = base + 0x200000;
    func_00392580(0, 0, 0);
    func_003925D8();
    func_00392670(0);
    func_00388320();
    D_001A7430[0] = 1;
    D_001CCFD0.f7 = 0;
    D_001D5B90 = -2;
    D_001D5B94 = 0;
    D_001D5B8C = 0;
    D_001D9D88 = 0;
    D_001D9C48 = 0;
    func_12C908(0);
    func_003925B0();
    D_001D9C48 = 0;
    func_12C908(0);
    func_003925B0();
    func_003A2A10(1);
    func_003A0A20(base + ((H_37D200 *)base)[12].off, (u32)buf);
    func_003A14B0((s32)buf, 0);
    D_001D5B9C = 0x13;
    D_001D9DAC = (s32)D_0031CD50;
    buf += 0x32000;
    func_003A0A20(base + ((H_37D200 *)base)[11].off, (u32)buf);
    {
        s32 i;
        for (i = 5; i < 11; i++) {
            ((H_37D200 *)base)[i].off -= 0x10;
        }
    }
    *(void * volatile *)&D_001D4B50 = base + 0x10;
    func_00399118();
    {
        u8 *p = 0;
        switch (D_00143950.fB7) {
        case 0:
        case 1:
            p = base + ((H_37D200 *)base)[0].off;
            break;
        case 2:
            p = base + ((H_37D200 *)base)[1].off;
            break;
        case 3:
            p = base + ((H_37D200 *)base)[2].off;
            break;
        case 4:
            p = base + ((H_37D200 *)base)[3].off;
            break;
        case 5:
            p = base + ((H_37D200 *)base)[4].off;
            break;
        }
        func_003A0A20(p, (u32)D_00227600_00381280.f18);
    }
    {
        u8 *q = D_00227600_00381280.f18;
        s32 i;
        u32 n = *(u32 *)q >> 4;
        D_001D9A20 = q;
        D_0031CD00_00381280.f2C = n;
        for (i = 0; i < D_0031CD00_00381280.f2C; i++) {
            *(u32 *)(q + i * 16) += (u32)q;
        }
    }
    func_003A1008();
    func_00381228();
    func_003B3068();
    while (D_001D5B74 == 0) {
        D_001D4AC0 += *(volatile u32 *)0x10000800;
        *(volatile u32 *)0x10000800 = 0;
        func_003A9440();
        func_003A93C0();
        func_003926F0();
        func_00392A68(1);
        func_003925D8();
        func_00392670(0);
        cur = D_001D5B94;
        obj = 0;
        D_001D4BB0 = D_001A1ED0.fC;
        switch (cur) {
        case -1:
        case 0:
            func_003A3E30();
            if (D_001D5750 >= 0) {
            if (D_001D5750 > 0 && (((S_pad_37D200 *)D_001D52FC)->f1A4 & 4)) {
                D_001D5750 = D_001D5750 - 1;
            } else {
                s32 n = D_001D5750 + 1;
                if (D_001D5758[n].a > 0 && (((S_pad_37D200 *)D_001D52FC)->f1A4 & 8)) {
                    D_001D5750 = n;
                }
            }
            } else {
                S_pad_37D200 *pad = D_001D52FC;
                if ((pad->f1A0 & 0x600) == 0x600) {
                    if (pad->f1A4 != 0) {
                        s32 k = D_001D574C;
                        if ((pad->f1A4 & D_001D5738[k]) == D_001D5738[k]) {
                            D_001D574C = k + 1;
                            if (D_001D5738[k + 1] == -1) {
                                D_001D5750 = 0;
                            }
                        } else {
                            D_001D574C = 0;
                        }
                    }
                } else {
                    D_001D574C = 0;
                }
            }
            if (((S_pad_37D200 *)D_001D52FC)->f1A0 != 0 || D_00142430.f15C >= 3 || D_00142430.f164 >= 0) {
                D_001D5688 = 0;
            }
            if (D_001D568C != 0) {
                func_00381CC0();
            } else {
                s32 t = D_001D5680;
                if (t < 0) t = 0;
                t = t - 1;
                D_001D5680 = t;
                if (t <= 0 && (((S_pad_37D200 *)D_001D52FC)->f1A0 & 0xF) == 0xF) {
                    D_001D568C = 1;
                    D_001D5690 = 9;
                    D_001D5680 = 0;
                    D_001D5694 = 0;
                } else {
                    s32 st;
                    if (func_13D3C8() == 7) {
                        func_13D3C0(5);
                        D_001D4D40 = 1;
                        D_00227480[0] = 1;
                        func_00392E40(D_00227480, 0);
                        func_00392F98(D_00227480);
                        func_13D3C0(9);
                        D_001D5688 = 0;
                    } else if (D_001D5688++ > 0x1C20 && func_13D3C8() == 0) {
                        func_13D3C0(5);
                    }
                    st = func_13D3C8();
                    func_0038E478(0);
                    func_003B3268();
                    func_003B32A0(0);
                    switch (st) {
                    case 0:
                        func_003A9AA0_00381280(buf + 0x10, D_001A1ED0.f4, 0x200, 0x1A0);
                        func_0038B148(0, 0, 0, 0x60);
                        break;
                    case 1:
                        func_13D3C0(2);
                        break;
                    case 3:
                        {
                            unsigned long t = D_00142BA4[0];
                            if (!((t >> 6) & 1)) break;
                        }
                    case 2:
                        func_13D3C0(4);
                        break;
                    case 4:
                        D_001D5B74 = 1;
                        D_001D9D84 = 1;
                        func_13D3C0(0);
                        break;
                    case 5:
                        func_003BB390();
                        func_13D3C0(6);
                        break;
                    case 6:
                        func_003A9AA0_00381280(buf + 0x10, D_001A1ED0.f4, 0x200, 0x1A0);
                        func_0038B148(0, 0, 0, 0x60);
                        func_003E8780(D_001D5684, &obj);
                        if (obj == 0 || func_003E7258(obj) == 0) {
                            func_13D3C0(7);
                        }
                        break;
                    case 10:
                        func_003E8780(D_001D5684, &obj);
                        if (obj != 0 && func_003E7258(obj) != 0) {
                            func_003E8708(D_001D5684);
                        }
                        func_13D3C0(8);
                        break;
                    case 8:
                        func_003E8780(D_001D5684, &obj);
                        if (obj == 0 || func_003E7258(obj) == 0) {
                            func_003E7250(func_003B51D8());
                            D_001D5684 = func_003E8698((s32)func_003B51D8());
                            func_13D3C0(0);
                        }
                        D_001D5688 = 0;
                        break;
                    case 9:
                        D_001D5688 = 0;
                        func_13D3C0(10);
                        break;
                    case 7:
                        break;
                    }
                }
            }
            func_003A4548();
            if (D_001D568C == 0 || D_001D5690 != 9) {
                func_00388320();
                func_003A96B0(0x47, 0x33001);
                func_003895C8(0);
                func_003B3300();
                func_003B3370(0);
                func_003B3338();
                if (D_001D5750 >= 0) {
                    f32 s = 32.0f;
                    s32 r = func_003823F0(D_001D575C[D_001D5750 * 2]);
                    func_0038EB10_00381280(s, s, 1.0f, 0x80808080, r, -1, 1.0f, 0, 0, 0x80000000, 0.0f, 0.0f);
                }
                func_003896F8();
            }
            break;
        case 1:
            func_003A8D80();
            break;
        case 3:
        case 4:
        case 18:
            func_003A3E30();
            func_003A2A10(0);
            func_003A21F0();
            func_003B3B28();
            break;
        }
        D_001D9D88++;
        func_003A4548();
        func_0039C6D8();
        func_0039B0A8();
        func_003A9560(1);
        {
            D_001D9D8C = (f32)*(volatile u32 *)0x10000800 / (D_00143950.f0 != 0 ? 11520.0f : 9600.0f);
        }
        func_003884F0();
        func_003A1008();
        if (D_001D5B94 != cur) {
            D_001D9D88 = 0;
        }
        D_001D9C48++;
        func_12C908(0);
    }
    if (D_001D5750 >= 0) {
        s32 v = D_001D5758[D_001D5750].a;
        if (D_001D5570[v] != 0) {
            D_001D9D84 = v;
        }
    }
    func_003A7B40();
}
/* localdecomp:end func_00381280 */

/* localdecomp:start func_00381BC0 */
s32 func_00381BC0(void) {
    return 0;
}
/* localdecomp:end func_00381BC0 */

/* localdecomp:start func_00381BC8 */
s32 func_00381BC8(void) {
}
/* localdecomp:end func_00381BC8 */

/* localdecomp:start func_00381BD0 */
s32 func_00381BD0(void) {
}
/* localdecomp:end func_00381BD0 */

/* localdecomp:start func_00381BD8 */
s32 func_00381BD8(void) {
}
/* localdecomp:end func_00381BD8 */

/* localdecomp:start func_00381BE0 */
s32 func_00381BE0(void) {
}
/* localdecomp:end func_00381BE0 */

/* localdecomp:start func_00381BE8 */
extern u8 D_001427AB[];
u8 func_00381BE8(void) {
    return D_001427AB[0];
}
/* localdecomp:end func_00381BE8 */

extern s32 func_003E7210(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

/* localdecomp:start func_00381BF8 */
extern s32 func_003E7210(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001D9918;
extern s32 D_001D9900[2];
s32 *func_00381BF8(void) {
    if (D_001D9918 == 0) {
        func_003E7210(D_001D9900, 0, 0, 0, 0, 0);
        D_001D9918 = 1;
    }
    return D_001D9900;
}
/* localdecomp:end func_00381BF8 */

/* localdecomp:start func_00381C40 */
extern s32 * func_00381BF8();
void func_00381C40(void) {
    func_00381BF8();
}
/* localdecomp:end func_00381C40 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00381C60);

/* localdecomp:start func_00381C68 */
s32 func_00381C68(void) {
}
/* localdecomp:end func_00381C68 */

/* localdecomp:start func_00381C70 */
s32 func_00381C70(void) {
}
/* localdecomp:end func_00381C70 */

/* localdecomp:start func_00381C78 */
s32 func_00381C78(void) {
}
/* localdecomp:end func_00381C78 */

/* localdecomp:start func_00381C80 */
s32 func_00381C80(void) {
    return 0;
}
/* localdecomp:end func_00381C80 */

/* localdecomp:start func_00381C88 */
s32 func_00381C88(void) {
    return 0;
}
/* localdecomp:end func_00381C88 */

/* localdecomp:start func_00381C90 */
s32 func_00381C90(void) {
}
/* localdecomp:end func_00381C90 */

/* localdecomp:start func_00381C98 */
s32 func_00381C98(void) {
}
/* localdecomp:end func_00381C98 */

/* localdecomp:start func_00381CA0 */
s32 func_00381CA0(void) {
}
/* localdecomp:end func_00381CA0 */

/* localdecomp:start func_00381CA8 */
s32 func_00381CA8(void) {
}
/* localdecomp:end func_00381CA8 */

/* localdecomp:start func_00381CB0 */
s32 func_00381CB0(void) {
    return 0;
}
/* localdecomp:end func_00381CB0 */

/* localdecomp:start func_00381CB8 */
s32 func_00381CB8(void) {
    return 1;
}
/* localdecomp:end func_00381CB8 */

/* localdecomp:start func_00381CC0 */
__asm__(".extern D_001D568C, 4");
__asm__(".extern D_001D5690, 4");
__asm__(".extern D_001D5694, 4");
__asm__(".extern D_001D5784, 4");
typedef struct { u8 p0[0xAD]; u8 bAD; } S_143950_381CC0;
typedef struct { u8 p0[8]; s32 f8; s32 fC; s32 f10; s32 f14; s16 h18; u8 p1A[0x15C - 0x1A]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; } S_142430_381CC0;
typedef struct { u8 p0[0x1A4]; s32 f1A4; } S_1D52FC_381CC0;
extern S_143950_381CC0 D_00143950_00381CC0;
extern S_142430_381CC0 D_00142430_00381CC0;
extern S_1D52FC_381CC0 *D_001D52FC_00381CC0;
extern s32 D_001D568C;
extern s32 D_001D5690;
extern s32 D_001D5694;
extern s32 D_001D5784;
extern s32 D_001D4D40;
extern s32 D_001D4BC0;
extern s32 D_00227480[];
extern void func_0038E478(s32);
extern void func_0013D3C0(s32);
extern s32 func_00392E40();
extern s32 func_00392F98();
extern s32 func_003823F0(s32);
extern void func_003824C8(void);
extern void func_003913E0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_0038FD40_00381CC0(s16 *, unsigned long, s32, s32, f32, unsigned long, f32);
extern void func_0038EB10_00381CC0(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);

void func_00381CC0(void) {
    s16 buf[16];
    s32 x;
    f32 one;
    if (D_001D5694 < 0x5A) x = (D_001D5694 - 0xF) * 0xE0 / 0x1E;
    else x = (0xA5 - D_001D5694) * 0xE0 / 0x1E;
    if (x < 0) x = 0;
    if (x > 0xE0) x = 0xE0;
    D_001D5694++;
    x = (x | (((x << 16) | 0x80000000) | (x << 8)));
    func_0038E478(1);
    switch (D_001D5690) {
    case 0:
        D_001D568C = 1;
        if (D_00142430_00381CC0.f15C != 2 || D_00142430_00381CC0.f164 >= 0) D_001D5690 = 1;
        break;
    case 1:
    case 2:
    case 3:
        D_001D568C = 1;
        if (D_00142430_00381CC0.f15C == 2 && D_00142430_00381CC0.f164 < 0) {
            if (D_00142430_00381CC0.f8 != 2 || (D_00142430_00381CC0.f14 != 0 && D_00142430_00381CC0.h18 < -1 && D_00142430_00381CC0.fC < 0x258)) {
                if (D_00142430_00381CC0.f8 != 2) D_001D5690 = 2;
                else if (D_00142430_00381CC0.h18 != -4) D_001D5690 = 3;
            D_00142430_00381CC0.f10 = 0;
            if (D_00142430_00381CC0.f164 < 0) {
                D_00142430_00381CC0.f168 = 0;
                D_00142430_00381CC0.f164 = 7;
            }
            } else {
            D_00142430_00381CC0.f10 = 0;
            if (D_00142430_00381CC0.f164 < 0) {
                D_00142430_00381CC0.f168 = 0;
                D_00142430_00381CC0.f164 = 7;
            }
            D_001D5694 = 0;
            D_001D5690 = 4;
            }
        }
    check:
        if (D_001D5694 >= 0x5B) {
            if (D_001D52FC_00381CC0->f1A4 & 0xFFFF0FFF) {
                D_00142430_00381CC0.f10 = 0;
                if (D_00142430_00381CC0.f164 < 0) {
                    D_00142430_00381CC0.f168 = 0;
                    D_00142430_00381CC0.f164 = 7;
                }
                D_001D5694 = 0;
                D_001D5690 = 4;
            }
        }
        if (D_001D5690 == 2) {
            one = 1.0f;
            func_003913E0(buf, 0, 0x1E0, 0x2C, 0x1D4, 0x100, 0xC8, 0x10, 3);
            func_0038FD40_00381CC0(buf, 0x80E0E0E0UL, func_003823F0(0x19D), -1, one, 0x80000000UL, one);
            if (D_001D5694 >= 0x5B) {
                f32 f = (f32)(D_001D4BC0 >> 1);
                func_0038EB10_00381CC0(f, 272.0f, one, 0x80E0E0E0UL, func_003823F0(0x24F), -1, one, 1, 0, 0x80000000UL, 0.0f, 0.0f);
            }
        } else if (D_001D5690 == 3) {
            one = 1.0f;
            func_003913E0(buf, 0, 0x1E0, 0x2C, 0x1D4, 0x100, 0xC8, 0x10, 3);
            func_0038FD40_00381CC0(buf, 0x80E0E0E0UL, func_003823F0(0x198), -1, one, 0x80000000UL, one);
            if (D_001D5694 >= 0x5B) {
                f32 f = (f32)(D_001D4BC0 >> 1);
                func_0038EB10_00381CC0(f, 272.0f, one, 0x80E0E0E0UL, func_003823F0(0x24F), -1, one, 1, 0, 0x80000000UL, 0.0f, 0.0f);
            }
        }
        break;
    case 4:
        func_003913E0(buf, 0, 0x1E0, 0x2C, 0x1D4, 0x100, 0x168, 0x10, 3);
        func_0038FD40_00381CC0(buf, x, func_003823F0(0x243), -1, 1.0f, 0x80000000UL, 1.0f);
        func_003913E0(buf, 0, 0x1E0, 0xC, 0x1F4, 0x100, 0xC8, 0x12, 3);
        func_0038FD40_00381CC0(buf, x, func_003823F0(0x1827), -1, 1.25f, 0x80000000UL, 1.25f);
        if (D_00142430_00381CC0.h18 == -1) {
            if (D_001D52FC_00381CC0->f1A4 & 0xFFFF0FFF) D_001D5784 = 1;
        }
        D_001D568C = 1;
        if (D_001D5694 >= 0xB5) {
            if (D_001D5784 != 0) { D_001D5694 = 0; D_001D5690 = 8; }
            else { D_001D5694 = 0; D_001D5690 = 6; }
        }
        break;
    case 6:
        D_001D568C = 1;
        func_003913E0(buf, 0, 0x1E0, 0x20, 0x1E0, 0x100, 0xC8, 0x12, 3);
        func_0038FD40_00381CC0(buf, x, func_003823F0(0x1B75), -1, 1.2f, 0x80000000UL, 1.2f);
        if (D_00142430_00381CC0.h18 == -1 && (D_001D52FC_00381CC0->f1A4 & 0xFFFF0FFF)) {
            D_001D5694 = 0;
            D_001D5690 = 8;
            break;
        }
        if (D_001D5694 >= 0xB5) {
            if (D_00142430_00381CC0.h18 == -1) D_001D4D40 = 0;
            else D_001D4D40 = 0x80;
            D_00227480[0] = 3;
            if (D_00143950_00381CC0.bAD != 0) func_00392E40(D_00227480, 0x1D);
            else func_00392E40(D_00227480, 0x1F);
            func_00392F98(D_00227480);
            D_001D5694 = 0;
            D_001D5690 = 8;
        }
        break;
    case 7:
        D_001D4D40 = 0;
        if (D_00143950_00381CC0.bAD != 0) func_00392E40(D_00227480, 0x1D);
        else func_00392E40(D_00227480, 0x1F);
        D_00227480[0] = 4;
        func_00392F98(D_00227480);
        D_001D5694 = 0;
        D_001D5690 = 8;
        break;
    case 8:
        D_001D568C = 0;
        func_0013D3C0(10);
        if (D_00142430_00381CC0.f15C == 2 && D_00142430_00381CC0.f164 < 0) {
            D_00142430_00381CC0.f168 = 0;
            D_00142430_00381CC0.f164 = 0x18;
        }
        break;
    case 9:
        D_001D568C = 1;
        func_003913E0(buf, 0, 0x1E0, 0x20, 0x1E0, 0x100, 0xC8, 0x10, 3);
        func_0038FD40_00381CC0(buf, x, func_003823F0(0x1700), -1, 1.0f, 0x80000000UL, 1.0f);
        if (D_001D5694 >= 0xB5) func_003824C8();
        break;
    }
}
/* localdecomp:end func_00381CC0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00382378);

/* localdecomp:start func_00382380 */
extern void *D_001D9A20;
typedef struct { u8 pad0[0x2C]; s32 f2C; } S_00318CC0_0037DF28;
extern S_00318CC0_0037DF28 D_0031CD00[];

s32 func_00382380(s32 arg0) {
    s32 var_a1;
    s32 var_a2;

    var_a2 = -1;
    var_a1 = 0;
    if (D_0031CD00->f2C > 0) {
        if ((*(s32 *)((u8 *)(D_001D9A20) + 4)) == arg0) {
            var_a2 = 0;
        } else {
loop_4:
            var_a1 += 1;
            if (var_a1 < D_0031CD00->f2C) {
                if ((*(s32 *)((u8 *)(((var_a1 * 0x10) + D_001D9A20)) + 4)) == arg0) {
                    var_a2 = var_a1;
                } else {
                    goto loop_4;
                }
            }
        }
    }
    return var_a2;
}
/* localdecomp:end func_00382380 */

/* localdecomp:start func_003823F0 */
extern s32 func_00382380(s32);

s32 func_003823F0(s32 id) {
    register u8 *gp __asm__("gp");
    s32 index;
    s32 fallback;
    s32** basePtr;

    index = func_00382380(id);
    fallback = (s32)(gp - 0x7128);
    
    // Pattern Library Scheduling Fence: Passing both operands forces the 
    // compiler to completely materialize row 14 BEFORE executing the branch check.
    __asm__ volatile("" : : "r"(index), "r"(fallback));

    if (index < 0) {
        return fallback;
    }
    
    basePtr = (s32**)0x1D9A20; // 0x001E0000 - 0x65E0
    return (*basePtr)[index * 4];
}
/* localdecomp:end func_003823F0 */

/* localdecomp:start func_00382430 */
__asm__(".extern D_001D9A20, 16");
__asm__(".extern D_001D52FC, 16");
extern void *D_001D52FC;
s32 func_00382430(fallback)
s32 fallback;
{
    s32 index = func_00382380(fallback);
    register s32 value __asm__("$4") = *(s16 *)((u8 *)D_001D9A20 + (index * 0x10) + 0xC);
    register s32 result __asm__("$2") = fallback;
    if (value > 0) {
        register u8 flag __asm__("$3");
        result = (s32)D_001D52FC;
        flag = *(volatile u8 *)(result + 0x550);
        result = value;
        __asm__ volatile("" : "+r"(result));
        if (flag == 0) {
            result = fallback;
        }
    }
    return result;
}
/* localdecomp:end func_00382430 */

/* localdecomp:start func_00382488 */
extern s32 func_00382430();
void func_00382488(void) {
    func_003823F0(func_00382430());
}
/* localdecomp:end func_00382488 */

/* localdecomp:start func_003824B0 */
extern s32 D_001D5688;
void func_003824B0(void) { D_001D5688 = 0; }
/* localdecomp:end func_003824B0 */

extern s32 D_001D5680;

/* localdecomp:start func_003824B8 */
extern s32 D_001D5680;
void func_003824B8(void) { D_001D5680 = 10; }
/* localdecomp:end func_003824B8 */

/* localdecomp:start func_003824C8 */
extern void func_00397FB8();
extern u8 D_001D5790[];
 
void func_003824C8(void) {
    func_00397FB8(D_001D5790, 0, 0);
}
/* localdecomp:end func_003824C8 */

/* localdecomp:start func_003824F0 */
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; u8 pE[6]; s32 f14; } Img_3824F0;
typedef struct {
    u8 *f0; u8 *f4; u8 p8[0xC]; s32 f14; s32 f18; u8 p1C[0x10]; s32 f2C; u8 p30[0xC]; s32 f3C;
    u8 p40[0xC]; s32 f4C; s32 f50;
} Tex_3824F0;
extern void func_0038CEA0(void *, s32, s32);
extern void func_12C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_003824F0(Img_3824F0 *img, unsigned long *out, s32 tbp, s32 cbp) {
    Tex_3824F0 t;
    u8 buf[0x60];
    s32 w, h, lz, lz2, c;
    func_0038CEA0(&t, 0, sizeof(t));
    t.f0 = (u8 *)img + 0x20;
    if (img->f14 == 0) t.f14 = 0x400; else t.f14 = 0x200;
    w = *(s32 *)((u8 *)img + 8);
    h = *(s32 *)((u8 *)img + 0xC);
    __asm__("plzcw %0, %1" : "=r"(lz) : "r"(w));
    t.f4C = 30 - lz;
    __asm__("plzcw %0, %1" : "=r"(lz2) : "r"(h));
    t.f50 = 30 - lz2;
    t.f4 = (u8 *)img + (t.f14 + 0x20);
    t.f18 = w * h;
    c = cbp >> 8;
    func_12C9A0(buf, c, 1, img->f14, 0, 0, 0x10, 0x10);
    func_11F0A0(0);
    func_12CCC8(buf, t.f0);
    func_12A9F0(0, 0);
    t.f3C = *(s32 *)((u8 *)img + 8) >> 6;
    if (t.f3C <= 0) t.f3C = 1;
    t.f2C = tbp >> 8;
    func_12C9A0(buf, t.f2C, t.f3C, 0x1B, 0, 0, img->h8, img->hC);
    func_11F0A0(0);
    func_12CCC8(buf, t.f4);
    func_12A9F0(0, 0);
    out[0] = ((unsigned long)t.f2C << 0) | ((unsigned long)t.f3C << 14) | ((unsigned long)0x1B << 20)
        | ((unsigned long)t.f4C << 26) | ((unsigned long)t.f50 << 30) | ((unsigned long)1 << 34)
        | ((unsigned long)0 << 35) | ((unsigned long)c << 37) | ((unsigned long)img->f14 << 51)
        | ((unsigned long)0 << 55) | ((unsigned long)0 << 56) | ((unsigned long)4 << 61);
    out[1] = 1;
    out[2] = 0;
}
/* localdecomp:end func_003824F0 */

/* localdecomp:start func_003826C8 */
typedef struct { u8 p0[0x64C]; s32 f64C; s32 f650; s32 f654; } S_160C40_3826C8;
extern S_160C40_3826C8 D_160C40_003826C8;
extern u8 D_2D2180[];
extern s32 D_1A1F0C[];
extern s32 func_003A29B0(s32, s32, s32);
extern void func_003824F0_003826C8(void *, unsigned long *, s32, s32);
void func_003826C8(void) {
    unsigned long out[4];
    S_160C40_3826C8 *g = &D_160C40_003826C8;
    func_003A29B0((s32)D_2D2180, g->f650 + g->f64C, g->f654);
    func_003824F0_003826C8(D_2D2180, out, D_1A1F0C[0], 0x3FFC00);
    *(unsigned long *)0x1D4D38 = out[0];
}
/* localdecomp:end func_003826C8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00382734);

/* localdecomp:start func_00382748 */
s32 func_00382748(u8 *p) {
    s32 *q;
    if (p == 0 || (q = *(s32 **)(p + 0x68)) == 0 || !(*(u16 *)(p + 0x34) & 0x20)) {
        return 0;
    }
    return *q;
}
/* localdecomp:end func_00382748 */
