#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012A948);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012A950);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012A9F0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012AA78);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012AAE0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012AB80);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012AB88);

/* localdecomp:start func_0012AC40 */
typedef struct {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    u32 attr;
    u32 option;
} SemaParam_12AC40;
extern volatile int D_0013F920;
extern volatile int D_0013F928;
extern volatile int D_0013F92C;
extern volatile int D_0013F930;
extern volatile int D_0013F934;
extern char D_00151300[];
extern char D_00151310[];
extern char D_00151320[];
extern char D_00151330[];
extern int func_0011EE20();

void func_0012AC40(void)
{
    SemaParam_12AC40 sp;

    if (D_0013F928 != -1 && D_0013F92C != -1 && D_0013F930 != -1) {
        return;
    }
    sp.init_count = 1;
    sp.max_count = 1;
    sp.option = (u32)D_00151300;
    D_0013F928 = func_0011EE20(&sp);
    sp.option = (u32)D_00151310;
    D_0013F92C = func_0011EE20(&sp);
    sp.option = (u32)D_00151320;
    D_0013F930 = func_0011EE20(&sp);
    sp.option = (u32)D_00151330;
    sp.init_count = 0;
    D_0013F920 = func_0011EE20(&sp);
    D_0013F934 = 0;
}
/* localdecomp:end func_0012AC40 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012AD28);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012ADC8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012AE20);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012AE98);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012AEA0);

/* localdecomp:start func_0012AEA8 */
/* libcdvd: init-style RPC bind under the sema (D_0013F928); 2.9-ee-991111 */
typedef struct { u8 pad[0x24]; s32 x24; } S_12AEA8;

extern void func_0012AC40_0012AEA8(void);
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_00121760_0012AEA8();
extern s32 func_0012B098(s32);
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern volatile s32 D_0013F928;
extern s32 D_0013F910;
extern s32 D_0013F91C;
extern s32 D_0013F93C;
extern S_12AEA8 D_00140AD0;
extern char D_001513B8[];
extern char D_001513E0[];

s32 func_0012AEA8(s32 mode) {
    func_0012AC40_0012AEA8();
    if (D_0013F928 != func_0011EE70(D_0013F928)) {
        if (D_0013F910 > 0) {
            func_00121760_0012AEA8(D_001513B8, mode, D_0013F91C);
        }
        return 0;
    }
    D_0013F91C = mode;
    if (func_0012B098(1) != 0) {
        func_0011EE40(D_0013F928);
        return 0;
    }
    func_00121FE8(0);
    if (D_0013F93C < 0) {
        while (1) {
            s32 i;
            if (func_00122630(&D_00140AD0, 0x80000595, 0) < 0) {
                if (D_0013F910 > 0) {
                    func_00121760_0012AEA8(D_001513E0);
                }
                i = 0x100000;
                while (--i != -1) {
                }
            } else if (D_00140AD0.x24 != 0) {
                D_0013F93C = 0;
                break;
            } else {
                i = 0x100000;
                while (--i != -1) {
                }
            }
        }
    }
    return 1;
}
/* localdecomp:end func_0012AEA8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012B000);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012B098);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012B138);

/* localdecomp:start func_0012B1A8 */
typedef struct {
    u8 pad[0x24];
    s32 serve;
} Cd_12B1A8;

extern volatile s32 D_0013F92C;
extern s32 D_0013F910;
extern s32 D_0013F918;
extern s32 D_0013F954;
extern Cd_12B1A8 D_00141480_0012B1A8;
extern char D_00151418[];
extern char D_00151440[];
extern void func_0012AC40_0012B1A8(void);
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_00121760_0012B1A8(const char *, ...);
extern s32 func_0012B138(s32);
extern void func_00121FE8(s32);
extern s32 func_00122630_0012B1A8(Cd_12B1A8 *, u32, s32);

s32 func_0012B1A8(s32 mode) {
    s32 i;

    func_0012AC40_0012B1A8();
    if (D_0013F92C != func_0011EE70(D_0013F92C)) {
        if (D_0013F910 > 0) {
            func_00121760_0012B1A8(D_00151418, mode, D_0013F918);
        }
        return 0;
    }
    D_0013F918 = mode;
    if (func_0012B138(1) != 0) {
        func_0011EE40(D_0013F92C);
        return 0;
    }
    func_00121FE8(0);
    if (D_0013F954 >= 0) {
        return 1;
    }
    while (1) {
        if (func_00122630_0012B1A8(&D_00141480_0012B1A8, 0x80000593, 0) < 0) {
            if (D_0013F910 > 0) {
                func_00121760_0012B1A8(D_00151440);
            }
            i = 0x100000;
            do {
                i--;
            } while (i != -1);
            continue;
        }
        if (D_00141480_0012B1A8.serve != 0) {
            break;
        }
        i = 0x100000;
        do {
            i--;
        } while (i != -1);
    }
    D_0013F954 = 0;
    return 1;
}
/* localdecomp:end func_0012B1A8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012B300);

/* localdecomp:start func_0012B5E8 */
/* libcdvd: mode command over the CD RPC (sema, bind loop, uncached reply); 2.9-ee-991111 */
typedef struct { u8 pad[0x24]; s32 x24; } S_12B5E8;

extern s32 func_0012B138(s32);
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern void func_00121760_0012B5E8();
extern void func_00121F38();
extern s32 func_00122810();
extern s32 func_00124920(void);
extern void func_00124970_0012B5E8(void);
extern void func_0012AC40_0012B5E8(void);
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern s32 D_0013F910;
extern volatile s32 D_0013F92C;
extern s32 D_0013F940;
extern s32 D_0013F950;
extern S_12B5E8 D_15A390;
extern s32 D_15A3D0;
extern s32 D_00140B00_0012B5E8[];
extern char D_00151488[];
extern char D_001514A0[];
extern char D_001514C0[];

s32 func_0012B5E8(s32 mode) {
    s32 ei;
    s32 r;

    if (D_0013F910 > 0) {
        func_00121760_0012B5E8(D_00151488);
    }
    ei = func_00124920();
    D_0013F940 = 1;
    if (ei) {
        func_00124970_0012B5E8();
    }
    func_0012AC40_0012B5E8();
    if (D_0013F92C != func_0011EE70(D_0013F92C)) {
        return 6;
    }
    if (func_0012B138(1) != 0) {
        func_0011EE40(D_0013F92C);
        return mode != 8 ? 6 : -1;
    }
    func_00121FE8(0);
    if (D_0013F950 < 0) {
        while (1) {
            s32 i;
            if (func_00122630(&D_15A390, 0x8000059A, 0) < 0) {
                if (D_0013F910 > 0) {
                    func_00121760_0012B5E8(D_001514A0);
                }
                i = 0x100000;
                while (--i != -1) {
                }
            } else if (D_15A390.x24 != 0) {
                D_0013F950 = 0;
                break;
            } else {
                i = 0x100000;
                while (--i != -1) {
                }
            }
        }
    }
    D_15A3D0 = mode;
    func_00121F38(&D_15A3D0, 4);
    if (func_00122810(&D_15A390, 0, 0, &D_15A3D0, 4, D_00140B00_0012B5E8, 4, 0, 0) < 0) {
        func_0011EE40(D_0013F92C);
        return mode != 8 ? 6 : -1;
    }
    if (D_0013F910 > 0) {
        func_00121760_0012B5E8(D_001514C0);
    }
    r = *(s32 *)((u32)D_00140B00_0012B5E8 | 0x20000000);
    func_0011EE40(D_0013F92C);
    return r;
}
/* localdecomp:end func_0012B5E8 */

/* localdecomp:start func_0012B800 */
typedef struct {
    u8 pad0[0x24];
    int serve;
    u8 pad28[0x40 - 0x28];
} Cd_12B800;
extern int D_0013F910;
extern volatile int D_0013F930;
extern int D_0013F940;
extern int D_0013F950;
extern char D_001514A0[];
extern char D_001514C0[];
extern char D_001514D8[];
extern Cd_12B800 D_15A390_0012B800;
extern int D_15A3D0;
extern int D_00141380[];
extern int func_00121760();
extern int func_0011EE40();
extern int func_0011EE70();
extern int func_00121FE8_0012B800();
extern void func_00121F38();
extern int func_0012AC40();
extern int func_0012B5E8();
extern int func_00124920();
extern int func_00124970_0012B800();
extern s32 func_00122630(void *, s32, s32);
extern s32 func_00122810();

int func_0012B800(int mode)
{
    int i;
    int j;
    int r;
    int k;

    if (D_0013F910 > 0) {
        func_00121760(D_001514D8);
    }
    func_0012AC40();
    if (D_0013F930 != func_0011EE70(D_0013F930)) {
        return mode != 8 ? 6 : -1;
    }
    func_00121FE8_0012B800(0);
    i = 0;
    if (D_0013F950 < 0) {
        for (;;) {
    bind:
        if (func_00122630(&D_15A390_0012B800, 0x8000059C, 0) < 0) {
            if (D_0013F910 > 0) {
                func_00121760(D_001514A0);
            }
            j = 0x100000;
            while (j--) {
            }
            goto bind;
        }
        if (D_15A390_0012B800.serve != 0) {
            D_0013F950 = 0;
            break;
        }
        if (i > 16) {
            func_0011EE40(D_0013F930);
            return func_0012B5E8(mode);
        }
        k = i + 1;
        j = 0x100000;
        while (j--) {
        }
        i = k;
        }
    }
    r = func_00124920();
    D_0013F940 = 0;
    if (r) {
        func_00124970_0012B800();
    }
    D_15A3D0 = mode;
    func_00121F38(&D_15A3D0, 4);
    if (func_00122810(&D_15A390_0012B800, 0, 0, &D_15A3D0, 4, D_00141380, 4, 0, 0) < 0) {
        func_0011EE40(D_0013F930);
        return mode != 8 ? 6 : -1;
    }
    if (D_0013F910 > 0) {
        func_00121760(D_001514C0);
    }
    r = *(int *)((u32)D_00141380 | 0x20000000);
    func_0011EE40(D_0013F930);
    return r;
}
/* localdecomp:end func_0012B800 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BA20);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BC00);

/* localdecomp:start func_0012BC98 */
extern volatile int D_0013F960;
extern u8 D_00141480[];
extern int D_00140B00_0012BC98[];
extern int func_0012B1A8(int n);

int func_0012BC98(void)
{
    int r;

    if (func_0012B1A8(0x1E) == 0) {
        return 0;
    }
    D_0013F960 = 8;
    if (func_00122810(D_00141480, 0x16, 0, 0, 0, D_00140B00_0012BC98, 4, 0, 0) < 0) {
        func_0011EE40(D_0013F92C);
        D_0013F960 = 0;
        return 0;
    }
    D_0013F960 = 0;
    r = *(int *)((u32)D_00140B00_0012BC98 | 0x20000000);
    func_0011EE40(D_0013F92C);
    return r;
}
/* localdecomp:end func_0012BC98 */

/* localdecomp:start func_0012BD50 */
extern s32 D_00140F40;
extern s32 D_001414A8;
extern s32 D_001414AC;
extern s32 D_001414B0;
extern u8 D_00140B00[];
extern u8 D_00141480[];
extern s32 D_0013F92C_0012BD50;
extern s32 func_0012B1A8(s32);
extern void func_00121F38(void *, s32);
extern s32 func_00122810();
extern s32 func_0011EE40(s32);

s32 func_0012BD50(s32 arg)
{
    s32 *buf = &D_00140F40;
    s32 r;

    if (func_0012B1A8(0x22) == 0) {
        return 0;
    }
    *buf = arg;
    func_00121F38(buf, 4);
    if (func_00122810(D_00141480, D_001414A8, 0, buf, D_001414AC, D_00140B00, D_001414B0, 0, 0) < 0) {
        func_0011EE40(D_0013F92C_0012BD50);
        return 0;
    }
    r = *(s32 *)((u32)D_00140B00 | 0x20000000);
    func_0011EE40(D_0013F92C_0012BD50);
    return r;
}
/* localdecomp:end func_0012BD50 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BE20);

/* localdecomp:start func_0012BE28 */
typedef struct {
    u8 b[8];
} Clock_12BE28;

extern u8 D_00140B00[];
extern s32 D_0013F92C_0012BE28;
extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);

s32 func_0012BE28(Clock_12BE28 *clock) {
    s32 r;

    if (func_0012B1A8(0xF) == 0) {
        return 0;
    }
    if (func_00122810(&D_00141480, 1, 0, 0, 0, D_00140B00, 0x10, 0, 0) < 0) {
        func_0011EE40(D_0013F92C_0012BE28);
        return 0;
    }
    *clock = *(Clock_12BE28 *)((u32)(D_00140B00 + 4) | 0x20000000);
    r = *(s32 *)((u32)D_00140B00 | 0x20000000);
    func_0011EE40(D_0013F92C_0012BE28);
    return r;
}
/* localdecomp:end func_0012BE28 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012BEE4);

/* localdecomp:start func_0012BEE8 */
typedef struct {
    s16 inter;
    s16 omode;
    s16 ffmode;
    u16 version;
    int vsc;
    int vscid;
} GParam_12BEE8;
GParam_12BEE8 *func_0012C078_0012BEE8(void);
u64 func_0011F160(u64 imr);
void func_0011F870(int n);
void func_0011EB20(int n, int id);
void func_0011EA20(int inter, int omode, int ffmode);

void func_0012BEE8(short mode, short inter, short omode, short ffmode)
{
    GParam_12BEE8 *gp;

    switch (mode) {
    case 0:
        gp = func_0012C078_0012BEE8();
        *(volatile u64 *)0x12001000 = 0x200;
        gp->inter = inter;
        gp->omode = omode;
        gp->version = (*(volatile u64 *)0x12001000 >> 16) & 0xFF;
        func_0011F160(0xFF00);
        gp->ffmode = ffmode != 0;
        if (gp->vsc) {
            func_0011F870(2);
            func_0011EB20(2, gp->vscid);
            gp->vsc = 0;
            gp->vscid = 0;
        }
        func_0011EA20(inter & 1, omode & 0xFF, ffmode & 1);
        break;
    case 1:
        *(volatile u64 *)0x12001000 = 0x100;
        break;
    case 5:
        gp = func_0012C078_0012BEE8();
        gp->inter = inter;
        gp->omode = omode;
        gp->ffmode = ffmode != 0;
        gp->version = (*(volatile u64 *)0x12001000 >> 16) & 0xFF;
        func_0011EA20(inter & 1, omode & 0xFF, ffmode & 1);
        break;
    }
}
/* localdecomp:end func_0012BEE8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C078);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C084);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C088);

ASM_FUNC("asm/boot_elf/handwritten", func_0012C128);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C138);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C4AC);

/* localdecomp:start func_0012C4B0 */
typedef struct {
    u64 pmode;
    u64 smode2;
    u64 dispfb;
    u64 display;
    u64 bgcolor;
} Disp_12C4B0;

typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
} Gs_12C4B0;

extern void *func_0012C078(void);

void func_0012C4B0(Disp_12C4B0 *disp)
{
    Gs_12C4B0 *gs = func_0012C078();

    if (gs->f6 == 1) {
        *(volatile u64 *)0x12000000 = disp->pmode;
        *(volatile u64 *)0x12000070 = disp->dispfb;
        *(volatile u64 *)0x12000080 = disp->display;
        *(volatile u64 *)0x120000C0 = disp->bgcolor;
    } else {
        *(volatile u64 *)0x12000000 = disp->pmode;
        *(volatile u64 *)0x12000020 = disp->smode2;
        *(volatile u64 *)0x12000090 = disp->dispfb;
        *(volatile u64 *)0x120000A0 = disp->display;
        *(volatile u64 *)0x120000E0 = disp->bgcolor;
    }
}
/* localdecomp:end func_0012C4B0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C56C);

/* localdecomp:start func_0012C570 */
extern void *func_0012C078(void);

s16 func_0012C570(s16 psm, s16 w, s16 h)
{
    u64 *gs;
    s32 bw;
    s32 bh;

    gs = func_0012C078();
    bw = (w + 63) / 64;
    if (psm & 2) {
        bh = (h + 63) / 64;
    } else {
        bh = (h + 31) / 32;
    }
    if ((*gs & 0x0000FFFF0000FFFFULL) == 1) {
        return bw * bh;
    }
    return bw * bh * 2;
}
/* localdecomp:end func_0012C570 */

/* localdecomp:start func_0012C638 */
typedef struct {
    u64 ATE : 1;
    u64 pad : 63;
} Bit_12C638;
typedef struct {
    u64 frame1;
    u64 frame1addr;
    u64 zbuf1;
    u64 zbuf1addr;
    u64 xyoffset1;
    u64 xyoffset1addr;
    u64 scissor1;
    u64 scissor1addr;
    Bit_12C638 prmodecont;
    u64 prmodecontaddr;
    Bit_12C638 colclamp;
    u64 colclampaddr;
    Bit_12C638 dthe;
    u64 dtheaddr;
    u64 test1;
    u64 test1addr;
} DrawEnv_12C638;
short func_0012C570(short psm, short w, short h);

int func_0012C638(DrawEnv_12C638 *draw, short psm, short w, short h, short ztest, short zpsm)
{
    draw->frame1addr = 0x4C;
    draw->frame1 = ((u64)(((w + 63) >> 6) & 0x3F) << 16) | ((u64)(psm & 0xF) << 24);
    draw->zbuf1addr = 0x4E;
    if (ztest == 0) {
        draw->zbuf1 = (u64)func_0012C570(psm, w, h) | ((u64)(zpsm & 0xF) << 24) | ((u64)1 << 32);
    } else {
        draw->zbuf1 = (u64)func_0012C570(psm, w, h) | ((u64)(zpsm & 0xF) << 24);
    }
    draw->xyoffset1addr = 0x18;
    draw->xyoffset1 = ((0x800L - (short)(w >> 1)) << 4) | ((0x800L - (short)(h >> 1)) << 36);
    draw->scissor1addr = 0x40;
    draw->scissor1 = ((u64)(w - 1) << 16) | ((u64)(h - 1) << 48);
    draw->prmodecontaddr = 0x1A;
    draw->prmodecont.ATE = 1;
    draw->colclampaddr = 0x46;
    draw->colclamp.ATE = 1;
    draw->dtheaddr = 0x45;
    if (psm & 2) {
        draw->dthe.ATE = 1;
    } else {
        draw->dthe.ATE = 0;
    }
    draw->test1addr = 0x47;
    if (ztest) {
        draw->test1 = ((u64)(ztest & 3) << 17) | 0x10000;
    } else {
        draw->test1 = 0x30000;
    }
    __asm__ __volatile__("sync");
    return 8;
}
/* localdecomp:end func_0012C638 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C81C);

/* localdecomp:start func_0012C820 */
extern char D_00151588[];
extern s32 func_00121760_0012C820(char *, ...);

s32 func_0012C820(u64 *tag)
{
    u32 i = 0;

    while (*(volatile u32 *)0x1000A000 & 0x100) {
        if (i++ > 0x1000000) {
            func_00121760_0012C820(D_00151588);
            return -1;
        }
    }
    *(volatile u32 *)0x1000A020 = (s32)(*tag & 0x7FFF) + 1;
    if (((u32)tag & 0x70000000) == 0x70000000) {
        *(volatile u32 *)0x1000A010 = ((u32)tag & 0x0FFFFFFF) | 0x80000000;
    } else {
        *(volatile u32 *)0x1000A010 = (u32)tag & 0x0FFFFFFF;
    }
    *(volatile u32 *)0x1000A000 = 0x101;
    return 0;
}
/* localdecomp:end func_0012C820 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C908);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C99C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012C9A0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012CB84);

/* localdecomp:start func_0012CCC8 */
extern int func_00121760();
extern char D_001516E0[];

int func_0012CCC8(u64 *p1, u64 *p2)
{
    u32 i;

    i = 0;
    while (*(volatile u32 *)0x1000A000 & 0x100) {
        if (i++ > 0x1000000) {
            goto timeout;
        }
    }
    *(volatile u32 *)0x1000A020 = 6;
    if (((u32)p1 & 0x70000000) == 0x70000000) {
        *(volatile u32 *)0x1000A010 = ((u32)p1 & 0x0FFFFFFF) | 0x80000000;
    } else {
        *(volatile u32 *)0x1000A010 = (u32)p1 & 0x0FFFFFFF;
    }
    *(volatile u32 *)0x1000A000 = 0x101;
    while (*(volatile u32 *)0x1000A000 & 0x100) {
        if (i++ > 0x1000000) {
            goto timeout;
        }
    }
    *(volatile u32 *)0x1000A020 = p1[10] & 0x7FFF;
    if (((u32)p2 & 0x70000000) != 0x70000000) {
        goto other;
    }
    *(volatile u32 *)0x1000A010 = ((u32)p2 & 0x0FFFFFFF) | 0x80000000;
    goto kick;
timeout:
    func_00121760(D_001516E0);
    return -1;
other:
    *(volatile u32 *)0x1000A010 = (u32)p2 & 0x0FFFFFFF;
kick:
    *(volatile u32 *)0x1000A000 = 0x101;
    return 0;
}
/* localdecomp:end func_0012CCC8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012CE44);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D4D4);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D4D8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D578);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012D5E8);

/* localdecomp:start func_0012D5F0 */
u32 func_0012D5F0(u32 a) {
    if ((a >> 28) == 7) {
        a &= 0x0FFFFFFF;
        a |= 0x80000000;
    }
    return a;
}
/* localdecomp:end func_0012D5F0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D618);

/* localdecomp:start func_0012D650 */
extern s32 D_00141500[];
s32 func_0012D650(u32 i) {
    if (i >= 10) {
        return 0;
    }
    return D_00141500[i];
}
/* localdecomp:end func_0012D650 */

/* localdecomp:start func_0012D678 */
/* libdma: sceDmaReset; 2.9-ee-991111 */
typedef struct { u8 b[0x14]; } E_12D678;

extern void func_0012D618(void *, s32);
extern s32 func_0012D758_0012D678(void *);

extern s32 D_00151908[];

s32 func_0012D678(s32 mode) {
    E_12D678 env;
    s32 old;
    s32 i;

    old = *(volatile u32 *)0x1000E000 & 1;
    for (i = 0; i < 10; i++) {
        if (D_00151908[i] != 0) {
            u32 *c = (u32 *)D_00141500[i];
            c[0x00 / 4] = 0;
            c[0x30 / 4] = 0;
            c[0x10 / 4] = 0;
            c[0x50 / 4] = 0;
            c[0x40 / 4] = 0;
            c[0x80 / 4] = 0;
        }
    }
    *(volatile u32 *)0x1000E010 = 0xFF1F;
    *(u32 *)0x1000E010 &= 0xFF1F0000;
    func_0012D618(&env, 0x14);
    func_0012D758_0012D678(&env);
    if (mode == 1) {
        *(volatile u32 *)0x1000E000 |= 1;
    }
    return old;
}
/* localdecomp:end func_0012D678 */

/* localdecomp:start func_0012D758 */
typedef struct {
    u8 sts;
    u8 std;
    u8 mfd;
    u8 rcyc;
    u16 express;
    u16 notify;
    u16 sqwc;
    u16 tqwc;
    void *rbadr;
    u32 rbmsk;
} Env_12D758;

extern u8 D_00151930[];
extern u8 D_00151940[];
extern u8 D_00151950[];
extern Env_12D758 D_15A3D8;

s32 func_0012D758(Env_12D758 *env)
{
    u32 ctrl;
    u32 pcr;
    u32 sqwc;
    u32 rbor;
    u32 rbsr;

    ctrl = *(volatile u32 *)0x1000E000;
    pcr = *(volatile u32 *)0x1000E020;
    sqwc = *(volatile u32 *)0x1000E030;
    rbor = *(volatile u32 *)0x1000E050;
    rbsr = *(volatile u32 *)0x1000E040;
    if (env->sts >= 10) {
        return -1;
    }
    if (env->std >= 10) {
        return -2;
    }
    if (env->mfd >= 10) {
        return -3;
    }
    if (env->rcyc >= 7) {
        return -4;
    }
    ctrl = (ctrl & ~0x30) | (D_00151930[env->sts] << 4);
    ctrl = (ctrl & ~0xC0) | (D_00151940[env->std] << 6);
    ctrl = (ctrl & ~0xC) | (D_00151950[env->mfd] << 2);
    if (env->rcyc != 0) {
        ctrl |= 2;
        ctrl = (ctrl & ~0x300) | ((env->rcyc - 1) << 8);
    } else {
        ctrl &= ~2;
    }
    pcr = (env->express << 16) | env->notify;
    sqwc = (env->tqwc << 16) | env->sqwc;
    rbor = (u32)env->rbadr;
    rbsr = env->rbmsk;
    *(volatile u32 *)0x1000E000 = ctrl;
    *(volatile u32 *)0x1000E020 = pcr;
    *(volatile u32 *)0x1000E030 = sqwc;
    *(volatile u32 *)0x1000E050 = rbor;
    *(volatile u32 *)0x1000E040 = rbsr;
    D_15A3D8 = *env;
    return 0;
}
/* localdecomp:end func_0012D758 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0012D930);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D938);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012D9A0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012D9B8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012D9C0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012DA58);

/* localdecomp:start func_0012DA60 */
typedef struct {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    u32 attr;
    u32 option;
} SemaParam_12DA60;
typedef struct {
    u8 pad0[0x24];
    int serve;
    u8 pad28[0x80 - 0x28];
} Cd_12DA60;
extern int D_0014153C;
extern int D_00141540;
extern char D_00151960[];
extern char D_00151970[];
extern char D_00151988[];
extern char D_001519A0[];
extern char D_001519C8[];
extern Cd_12DA60 D_15A400;
extern u8 D_15A480[];
extern int D_15B9C0_0012DA60[];
extern int func_0011EE20();
extern int func_0011EE30();
extern int func_0011EE40();
extern int func_0011EE60();
extern int func_0012E2E0();
extern int func_00121FE8_0012DA60();
extern s32 func_00122630(void *, s32, s32);
extern s32 func_00122810();
extern int func_00121760();

int func_0012DA60(void)
{
    SemaParam_12DA60 sp;
    int i;
    int j;
    int r;

    i = 0;
    if (D_0014153C < 0) {
        sp.init_count = 1;
        sp.max_count = 1;
        sp.option = (u32)D_00151960;
        D_0014153C = func_0011EE20(&sp);
        if (D_0014153C == -1) {
            return -101;
        }
        sp.max_count = 1;
        sp.init_count = 0;
        sp.option = (u32)D_00151970;
        D_00141540 = func_0011EE20(&sp);
        if (D_00141540 == -1) {
            func_0011EE30(D_0014153C);
            D_0014153C = -1;
            return -101;
        }
    }
    func_0012E2E0(0, 0, 0);
    func_0011EE60(D_0014153C);
    func_00121FE8_0012DA60(0);
    for (;;) {
        if (func_00122630(&D_15A400, 0x80000400, 0) < 0) {
            func_00121760(D_00151988);
            for (;;) {
            }
        }
        if (D_15A400.serve != 0) {
            break;
        }
        j = 0x100000;
        while (--j) {
        }
        i++;
        if (i >= 0x200) {
            func_00121760(D_00151988);
            return -91;
        }
    }
    r = func_00122810(&D_15A400, 0xFE, 0, D_15A480, 0x30, D_15B9C0_0012DA60, 0xC, 0, 0);
    func_0011EE40(D_0014153C);
    if (r < 0) {
        D_15A400.serve = 0;
        return -91;
    }
    if (D_15B9C0_0012DA60[1] < 0x20A) {
        func_00121760(D_001519A0);
        D_15A400.serve = 0;
        return -120;
    }
    if (D_15B9C0_0012DA60[2] < 0x20E) {
        func_00121760(D_001519C8);
        D_15A400.serve = 0;
        return -121;
    }
    return D_15B9C0_0012DA60[0];
}
/* localdecomp:end func_0012DA60 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012DC88);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012DC98);

/* localdecomp:start func_0012DCA0 */
typedef struct {
    u8 pad0[0x24];
    s32 server;
} Cd_12DCA0;

typedef struct {
    s32 port;
    s32 slot;
    s32 mode;
    u8 padC[0x14 - 0xC];
    char name[0x400];
} Rpc_12DCA0;

extern Cd_12DCA0 D_15A400_12DCA0;
extern Rpc_12DCA0 D_15A4B0;
extern u8 D_15B9C0[];
extern s32 D_0014153C;
extern s32 D_00141538[];
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern char *func_0011BB58(char *, char *, s32);
extern s32 func_00122810();
extern void func_0012DC88();

s32 func_0012DCA0(s32 port, s32 slot, char *name, s32 mode)
{
    if (D_15A400_12DCA0.server == 0) {
        return -100;
    }
    if (func_0011EE70(D_0014153C) < 0) {
        return -200;
    }
    if (name == 0 || *name == 0) {
        func_0011EE40(D_0014153C);
        return -210;
    }
    func_0011BB58(D_15A4B0.name, name, 0x3FF);
    D_15A4B0.port = port;
    D_15A4B0.mode = mode;
    D_15A4B0.slot = slot;
    D_15A4B0.name[0x3FF] = 0;
    if (func_00122810(&D_15A400_12DCA0, 2, 1, &D_15A4B0, 0x414, D_15B9C0, 4, func_0012DC88, 0) != 0) {
        func_0011EE40(D_0014153C);
        return -91;
    }
    D_00141538[0] = 2;
    return 0;
}
/* localdecomp:end func_0012DCA0 */

/* localdecomp:start func_0012DDC8 */
extern s32 func_0012DCA0();
extern s32 D_00141538[];
s32 func_0012DDC8(s32 a, s32 b, s32 c) {
    s32 r = func_0012DCA0(a, b, c, 0x40);
    if (r == 0) {
        D_00141538[0] = 0xB;
    }
    return r;
}
/* localdecomp:end func_0012DDC8 */

/* localdecomp:start func_0012DE00 */
extern void func_0012DC88();

int func_0012DE00(int port)
{
    if (D_15A400.serve == 0) {
        return -100;
    }
    if (func_0011EE70(D_0014153C) < 0) {
        return -200;
    }
    *(int *)D_15A480 = port;
    if (func_00122810(&D_15A400, 3, 1, D_15A480, 0x30, D_15B9C0, 4, func_0012DC88, 0)) {
        func_0011EE40(D_0014153C);
        return -91;
    }
    D_00141538[0] = 3;
    return 0;
}
/* localdecomp:end func_0012DE00 */

/* localdecomp:start func_0012DEC0 */
typedef struct {
    s32 x0;
    u8 pad4[0xC];
    s32 x10;
    s32 x14;
    u8 pad18[0x18];
} McCmd_12DEC0;

extern Cd_12B1A8 D_15A400_0012DEC0;
extern McCmd_12DEC0 D_15A480_0012DEC0;
extern s32 D_0014153C;
extern u8 D_15B9C0[];
extern void func_0012DC88(void);
extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);

s32 func_0012DEC0(s32 a, s32 b, s32 c) {
    if (D_15A400_0012DEC0.serve == 0) {
        return -100;
    }
    if (func_0011EE70(D_0014153C) < 0) {
        return -200;
    }
    D_15A480_0012DEC0.x0 = a;
    D_15A480_0012DEC0.x10 = b;
    D_15A480_0012DEC0.x14 = c;
    if (func_00122810(&D_15A400_0012DEC0, 4, 1, &D_15A480_0012DEC0, 0x30, D_15B9C0, 4, func_0012DC88, 0) != 0) {
        func_0011EE40(D_0014153C);
        return -91;
    }
    D_00141538[0] = 4;
    return 0;
}
/* localdecomp:end func_0012DEC0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012DFA0);

/* localdecomp:start func_0012E050 */
/* libmc: asynchronous memory card RPC (function 5); 2.9-ee-991111 */
typedef struct { u8 pad[0x24]; s32 x24; } C_12E050;
typedef struct {
    s32 x0;
    u8 pad4[0xC - 4];
    s32 xC;
    u8 pad10[0x18 - 0x10];
    void *x18;
    void *x1C;
} A_12E050;

extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_00121F38();
extern s32 func_00122810();
extern void func_0012DFA0();
extern C_12E050 D_15A400_0012E050;
extern A_12E050 D_15A480_0012E050;
extern u8 D_15A900[];
extern u8 D_15B9C0[];
extern s32 D_0014153C;


s32 func_0012E050(s32 a, void *buf, s32 size) {
    if (D_15A400_0012E050.x24 == 0) {
        return -100;
    }
    if (func_0011EE70(D_0014153C) < 0) {
        return -200;
    }
    D_15A480_0012E050.x0 = a;
    D_15A480_0012E050.x18 = buf;
    D_15A480_0012E050.xC = size;
    D_15A480_0012E050.x1C = D_15A900;
    func_00121F38(buf, size);
    func_00121F38(D_15A900, 0xC0);
    if (func_00122810(&D_15A400_0012E050, 5, 1, &D_15A480_0012E050, 0x30, D_15B9C0, 4, func_0012DFA0, D_15A900) != 0) {
        func_0011EE40(D_0014153C);
        return -91;
    }
    D_00141538[0] = 5;
    return 0;
}
/* localdecomp:end func_0012E050 */

/* localdecomp:start func_0012E168 */
typedef struct {
    u8 pad0[0x24];
    s32 server;
} Cd_12E168;

typedef struct {
    s32 fd;
    u8 pad4[0xC - 4];
    s32 rest;
    u8 pad10[0x14 - 0x10];
    u32 head;
    u8 *tail;
    u8 pad1C[0x20 - 0x1C];
    u8 data[16];
} Rpc_12E168;

extern Cd_12E168 D_15A400_12E168;
extern Rpc_12E168 D_15A480_12E168;
extern u8 D_15B9C0[];
extern s32 D_0014153C;
extern s32 D_00141538[];
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_0011F0A0(s32);
extern s32 func_00122810();
extern void func_0012DC88();

s32 func_0012E168(s32 fd, u8 *buf, s32 size)
{
    u32 i;
    s32 n;

    if (D_15A400_12E168.server == 0) {
        return -100;
    }
    if (func_0011EE70(D_0014153C) < 0) {
        return -200;
    }
    D_15A480_12E168.fd = fd;
    if (size < 0x11) {
        D_15A480_12E168.head = size;
        D_15A480_12E168.rest = 0;
        D_15A480_12E168.tail = 0;
    } else {
        {
            u8 *p = buf - 0x10;
            n = (u8 *)((u32)(buf - 1) & ~0xF) - p;
        }
        D_15A480_12E168.head = n;
        D_15A480_12E168.rest = size - n;
        D_15A480_12E168.tail = buf + n;
    }
    for (i = 0; i < D_15A480_12E168.head; i++) {
        D_15A480_12E168.data[i] = buf[i];
    }
    func_0011F0A0(0);
    if (func_00122810(&D_15A400_12E168, 6, 1, &D_15A480_12E168, 0x30, D_15B9C0, 4, func_0012DC88, 0) != 0) {
        func_0011EE40(D_0014153C);
        return -91;
    }
    D_00141538[0] = 6;
    return 0;
}
/* localdecomp:end func_0012E168 */

/* localdecomp:start func_0012E2E0 */
/* libmc: wait for or poll the pending memory card command (sceMcSync-style); 2.9-ee-991111 */
extern void func_0011EE60_0012E2E0(s32);
extern s32 D_00141540;

s32 func_0012E2E0(s32 mode, s32 *cmd, s32 *result) {
    s32 busy;

    if (D_00141538[0] == 0) {
        return -1;
    }
    busy = 0;
    if (func_0011EE70(D_00141540) < 0) {
        busy = 1;
    }
    if (mode == 0 && busy) {
        func_0011EE60_0012E2E0(D_00141540);
        busy = 0;
    }
    busy = !busy;
    if (cmd != 0) {
        *cmd = D_00141538[0];
    }
    if (busy != 0) {
        D_00141538[0] = 0;
        if (result != 0) {
            *result = *(s32 *)D_15B9C0;
        }
        func_0011EE40(D_0014153C);
    }
    return busy;
}
/* localdecomp:end func_0012E2E0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E3A8);

/* localdecomp:start func_0012E400 */
typedef struct {
    u8 pad0[0x24];
    s32 server;
} Cd_12E400;

typedef struct {
    s32 f0;
    s32 port;
    s32 slot;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    void *f1C;
} Rpc_12E400;

extern Cd_12E400 D_15A400_0012E400;
extern Rpc_12E400 D_15A480_0012E400;
extern u8 D_15A900[];
extern u8 D_15B9C0[];
extern s32 *D_15A428;
extern s32 *D_15A42C;
extern s32 *D_15A430;
extern s32 D_0014153C;
extern s32 D_00141538[];
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_00121F38(void *, s32);
extern s32 func_00122810();
extern void func_0012E3A8();

s32 func_0012E400(s32 port, s32 slot, s32 *type, s32 *free, s32 *format)
{
    if (D_15A400_0012E400.server == 0) {
        return -100;
    }
    if (func_0011EE70(D_0014153C) < 0) {
        return -200;
    }
    D_15A480_0012E400.port = port;
    D_15A480_0012E400.slot = slot;
    D_15A480_0012E400.f1C = D_15A900;
    if (type != 0) {
        D_15A480_0012E400.f14 = 1;
    } else {
        D_15A480_0012E400.f14 = 0;
    }
    if (free != 0) {
        D_15A480_0012E400.f10 = 1;
    } else {
        D_15A480_0012E400.f10 = 0;
    }
    if (format != 0) {
        D_15A480_0012E400.fC = 1;
    } else {
        D_15A480_0012E400.fC = 0;
    }
    D_15A428 = type;
    D_15A42C = free;
    D_15A430 = format;
    func_00121F38(D_15A900, 0xC0);
    if (func_00122810(&D_15A400_0012E400, 1, 1, &D_15A480_0012E400, 0x30, D_15B9C0, 4, func_0012E3A8, D_15A900) != 0) {
        func_0011EE40(D_0014153C);
        return -91;
    }
    D_00141538[0] = 1;
    return 0;
}
/* localdecomp:end func_0012E400 */

/* localdecomp:start func_0012E580 */
typedef struct {
    int port;
    int slot;
    int mode;
    int maxent;
    void *table;
    char name[0x400];
} McDir_12E580;
extern McDir_12E580 D_15A4B0_0012E580;
extern int func_0011EE70();
extern int func_0011BB58_0012E580();
extern void func_00121F38();
extern void func_0012DC88();

int func_0012E580(int port, int slot, char *name, int mode, int maxent, void *table)
{
    if (D_15A400.serve == 0) {
        return -100;
    }
    if (func_0011EE70(D_0014153C) < 0) {
        return -200;
    }
    if (name == 0 || *name == 0) {
        func_0011EE40(D_0014153C);
        return -210;
    }
    D_15A4B0_0012E580.port = port;
    D_15A4B0_0012E580.slot = slot;
    D_15A4B0_0012E580.mode = mode;
    D_15A4B0_0012E580.maxent = maxent;
    D_15A4B0_0012E580.table = table;
    func_0011BB58_0012E580(D_15A4B0_0012E580.name, name, 0x3FF);
    D_15A4B0_0012E580.name[0x3FF] = 0;
    if (maxent >= 0) {
        func_00121F38(table, maxent << 6);
    }
    if (func_00122810(&D_15A400, 0xD, 1, &D_15A4B0_0012E580, 0x414, D_15B9C0, 4, func_0012DC88, 0)) {
        func_0011EE40(D_0014153C);
        return -91;
    }
    D_00141538[0] = 0xD;
    return 0;
}
/* localdecomp:end func_0012E580 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0012E6D0);

/* localdecomp:start func_0012E6D8 */
typedef struct {
    u8 pad0[0x24];
    s32 server;
} Cd_12E6D8;

typedef struct {
    s32 f0;
    s32 port;
    s32 slot;
} Rpc_12E6D8;

extern Cd_12E6D8 D_15A400_12E6D8;
extern Rpc_12E6D8 D_15A480_12E6D8;
extern u8 D_15B9C0[];
extern s32 D_0014153C;
extern s32 D_00141538[];
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern s32 func_00122810();
extern void func_0012DC88();

s32 func_0012E6D8(s32 port, s32 slot)
{
    if (D_15A400_12E6D8.server == 0) {
        return -100;
    }
    if (func_0011EE70(D_0014153C) < 0) {
        return -200;
    }
    D_15A480_12E6D8.port = port;
    D_15A480_12E6D8.slot = slot;
    if (func_00122810(&D_15A400_12E6D8, 0x10, 1, &D_15A480_12E6D8, 0x30, D_15B9C0, 4, func_0012DC88, 0) != 0) {
        func_0011EE40(D_0014153C);
        return -91;
    }
    D_00141538[0] = 0x10;
    return 0;
}
/* localdecomp:end func_0012E6D8 */

/* localdecomp:start func_0012E7A8 */
typedef struct {
    u8 pad0[0x24];
    s32 server;
} Cd_12E7A8;

typedef struct {
    s32 port;
    s32 slot;
    s32 mode;
    u8 padC[0x14 - 0xC];
    char name[0x400];
} Rpc_12E7A8;

extern Cd_12E7A8 D_15A400_12E7A8;
extern Rpc_12E7A8 D_15A4B0_12E7A8;
extern u8 D_15B9C0[];
extern s32 D_0014153C;
extern s32 D_00141538[];
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern char *func_0011BB58(char *, char *, s32);
extern s32 func_00122810();
extern void func_0012DC88();

s32 func_0012E7A8(s32 port, s32 slot, char *name)
{
    if (D_15A400_12E7A8.server == 0) {
        return -100;
    }
    if (func_0011EE70(D_0014153C) < 0) {
        return -200;
    }
    if (name == 0 || *name == 0) {
        func_0011EE40(D_0014153C);
        return -210;
    }
    func_0011BB58(D_15A4B0_12E7A8.name, name, 0x3FF);
    D_15A4B0_12E7A8.port = port;
    D_15A4B0_12E7A8.slot = slot;
    D_15A4B0_12E7A8.name[0x3FF] = 0;
    D_15A4B0_12E7A8.mode = 0;
    if (func_00122810(&D_15A400_12E7A8, 0xF, 1, &D_15A4B0_12E7A8, 0x414, D_15B9C0, 4, func_0012DC88, 0) != 0) {
        func_0011EE40(D_0014153C);
        return -91;
    }
    D_00141538[0] = 0xF;
    return 0;
}
/* localdecomp:end func_0012E7A8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0012E8C8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012E8D0);

/* localdecomp:start func_0012E8D8 */
typedef struct {
    u8 pad0[0x24];
    s32 server;
} Cd_12E8D8;

typedef struct {
    s32 f0;
    s32 port;
    s32 slot;
} Rpc_12E8D8;

extern Cd_12E8D8 D_15A400_12E8D8;
extern Rpc_12E8D8 D_15A480_12E8D8;
extern u8 D_15B9C0[];
extern s32 D_0014153C;
extern s32 D_00141538[];
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern s32 func_00122810();
extern void func_0012DC88();

s32 func_0012E8D8(s32 port, s32 slot)
{
    if (D_15A400_12E8D8.server == 0) {
        return -100;
    }
    if (func_0011EE70(D_0014153C) < 0) {
        return -200;
    }
    D_15A480_12E8D8.port = port;
    D_15A480_12E8D8.slot = slot;
    if (func_00122810(&D_15A400_12E8D8, 0x11, 1, &D_15A480_12E8D8, 0x30, D_15B9C0, 4, func_0012DC88, 0) != 0) {
        func_0011EE40(D_0014153C);
        return -91;
    }
    D_00141538[0] = 0x11;
    return 0;
}
/* localdecomp:end func_0012E8D8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E9A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E9B0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012E9D8);

/* localdecomp:start func_0012EA38 */
typedef struct {
    u8 pad0[0x24];
    int serve;
    u8 pad28[0x28 - 0x28];
} Cd_12EA38;
extern Cd_12EA38 D_15BA00;
extern u8 D_15BAC0[];
extern char D_00151A10[];
extern char D_00151A28[];
extern char D_00151A50[];
extern int func_0012EC28(void);
extern void func_0012E9B0();
extern void func_0012E9D8();
extern s32 func_0011A264();

int func_0012EA38(void)
{
    int i;
    int ver;

    func_00121FE8(0);
    for (;;) {
        if (func_00122630(&D_15BA00, 0x80000900, 0) < 0) {
            func_0012E9B0(D_00151A10);
            return 0;
        }
        if (D_15BA00.serve != 0) {
            break;
        }
        i = 0x10000;
        while (i--) {
        }
    }
    ver = func_0012EC28();
    if ((ver >> 4) != 0x31) {
        func_00121760(D_00151A28);
        func_00121760(D_00151A50, 3, 0x10, ver >> 8, ver & 0xFF);
        return 0;
    }
    func_0011A264(D_15BAC0, 0, 0x80);
    func_0012E9D8(D_15BAC0);
    return 1;
}
/* localdecomp:end func_0012EA38 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0012EB38);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EB40);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012EBB0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EBB8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EC28);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EC8C);

/* localdecomp:start func_0012EC90 */
typedef struct {
    u8 pad[0x24];
    s32 serve;
} Cd_12EC90;

extern s32 D_00141558;
extern s32 D_0014155C;
extern Cd_12EC90 D_15BB40_0012EC90[];
extern char D_00151B60[];
extern char D_00151B88[];
extern s32 func_0012FCE8(void);
extern s32 func_0012EE18(s32);

s32 func_0012EC90(s32 mode) {
    s32 i;
    s32 r;

    D_00141558 = 1;
    while (1) {
        func_00122630((Cd_12B1A8 *)&D_15BB40_0012EC90[0], 0x80000100, 0);
        if (D_15BB40_0012EC90[0].serve != 0) {
            break;
        }
        i = 0x10000;
        do {
            i--;
        } while (i != -1);
    }
    while (1) {
        func_00122630((Cd_12B1A8 *)&D_15BB40_0012EC90[1], 0x80000101, 0);
        if (D_15BB40_0012EC90[1].serve != 0) {
            break;
        }
        i = 0x10000;
        do {
            i--;
        } while (i != -1);
    }
    r = func_0012FCE8();
    if ((r >> 8) != 4) {
        if (D_0014155C != 0) {
            func_00121760(D_00151B60);
            func_00121760(D_00151B88, 4, 0, r >> 8, r & 0xFF);
        }
        return 0;
    }
    return func_0012EE18(mode);
}
/* localdecomp:end func_0012EC90 */

ASM_FUNC("asm/boot_elf/handwritten", func_0012EDD0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EE18);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EF10);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012EFA0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F0B8);

/* localdecomp:start func_0012F2A0 */
typedef struct {
    u8 data[0x58];
    s32 frame;
    u8 pad5C[0x80 - 0x5C];
} Pd_12F2A0;

typedef struct {
    Pd_12F2A0 *area;
    u8 pad4[0x1C - 4];
} St_12F2A0;

extern St_12F2A0 D_15BB90[2][4];
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern void func_0011F848(void *, void *);

Pd_12F2A0 *func_0012F2A0(s32 port, s32 slot, Pd_12F2A0 *out)
{
    s32 r;
    Pd_12F2A0 *pd;
    s32 i;

    r = func_00124920();
    pd = D_15BB90[port][slot].area;
    func_0011F848(pd, (u8 *)pd + 0xFF);
    i = pd[0].frame < pd[1].frame;
    if (out != 0) {
        *out = pd[i];
    }
    if (r == 1) {
        func_00124970();
    }
    return &pd[i];
}
/* localdecomp:end func_0012F2A0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F3F8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F470);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012F4E8);

/* localdecomp:start func_0012F4F0 */
typedef struct {
    u8 pad0[0x10];
    s32 open;
    u8 pad14[0x1C - 0x14];
} St_12F4F0;

extern St_12F4F0 D_15BB90_12F4F0[2][4];
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern Pd_12F2A0 *func_0012F2A0(s32, s32, Pd_12F2A0 *);
extern void func_0011F698(void *, void *);

s32 func_0012F4F0(s32 port, s32 slot, s32 state)
{
    s32 r;
    u8 *pd;

    if (D_15BB90_12F4F0[port][slot].open == 0) {
        return 0;
    }
    r = func_00124920();
    pd = (u8 *)func_0012F2A0(port, slot, 0);
    pd[0x71] = state;
    func_0011F698(pd, pd + 0x7F);
    if (r == 1) {
        func_00124970();
    }
    return 1;
}
/* localdecomp:end func_0012F4F0 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012F5A8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012F600);

/* localdecomp:start func_0012F608 */
typedef struct {
    u8 pad[0x30];
    u8 act[8][4];
    u8 pad50[0x14];
    u8 x64;
    u8 pad65[5];
    u8 x6A;
    u8 pad6B[7];
    u8 x72;
    u8 pad73[0xD];
} Info_12F608;

typedef struct {
    u8 pad[0x10];
    s32 x10;
    u8 pad2[0x8];
} Slot_12F608;

extern Slot_12F608 D_15BB90_0012F608[][4];
extern void func_0012F2A0_0012F608(s32, s32, void *);

s32 func_0012F608(s32 port, s32 slot, s32 actno, s32 term) {
    Info_12F608 info;

    if (D_15BB90_0012F608[port][slot].x10 == 0) {
        return 0;
    }
    func_0012F2A0_0012F608(port, slot, &info);
    if (info.x72 != 1) {
        return 0;
    }
    if (info.x64 < 2) {
        return 0;
    }
    if (actno >= info.x6A) {
        return 0;
    }
    if (actno == -1) {
        return info.x6A;
    }
    switch (term) {
    case 1:
        return info.act[actno][0];
    case 2:
        return info.act[actno][1];
    case 3:
        return info.act[actno][2];
    case 4:
        return info.act[actno][3];
    }
    return 0;
}
/* localdecomp:end func_0012F608 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0012F720);

/* localdecomp:start func_0012F728 */
typedef struct {
    u8 pad[0x10];
    s32 x10;
    u8 pad2[0x8];
} Slot_12F728;

typedef struct {
    u8 pad[0x50];
    u16 act[0xA];
    u8 x64;
    u8 x65;
    u8 pad66[2];
    u8 x68;
    u8 x69;
    u8 pad6A[7];
    u8 x71;
    u8 x72;
    u8 pad73[0xD];
} Info_12F728;


s32 func_0012F728(s32 port, s32 slot, s32 term, s32 offs) {
    Info_12F728 info;
    u8 b;

    if (D_15BB90_0012F608[port][slot].x10 == 0) {
        return 0;
    }
    func_0012F2A0_0012F608(port, slot, &info);
    if (info.x72 != 1) {
        return 0;
    }
    if (info.x71 == 2) {
        return 0;
    }
    switch (term) {
    case 1:
        b = info.x65;
        if (b == 0xF3) {
            return 0;
        }
        return b >> 4;
    case 2:
        if (info.x64 == 1) {
            return 0;
        }
        return info.act[info.x69];
    case 3:
        if (info.x64 == 1) {
            return 0;
        }
        return info.x69;
    case 4:
        if (info.x64 == 1) {
            return 0;
        }
        if (offs == -1) {
            return info.x68;
        }
        if (offs < info.x68) {
            return info.act[offs];
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_0012F728 */

/* localdecomp:start func_0012F860 */
typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    u8 pad18[0x80 - 0x18];
} PadBuf_12F860;
extern PadBuf_12F860 D_15BD80;
extern u8 D_15BB40[];
extern void func_0012F4F0_0012F860(int port, int slot, int n);

int func_0012F860(int port, int slot, int a, int b)
{
    PadBuf_12F860 *p;
    int r;

    p = &D_15BD80;
    p->fC = a;
    p->f10 = b;
    D_15BD80.f0 = 6;
    p->f4 = port;
    p->f8 = slot;
    if (func_00122810(D_15BB40, 1, 0, p, 0x80, p, 0x80, 0, 0) < 0) {
        return 0;
    }
    r = p->f14;
    if (r == 1) {
        func_0012F4F0_0012F860(port, slot, 2);
        r = p->f14;
    }
    return r;
}
/* localdecomp:end func_0012F860 */

/* localdecomp:start func_0012F918 */
/* libpad: set the actuator alignment (scePadSetActAlign-style); 2.9-ee-991111 */
typedef struct { u8 pad0[4]; s32 x4; s32 x8; u8 act[6]; } B_12F918;
typedef struct { u8 pad0[4]; B_12F918 *x4; u8 pad8[0x1C - 8]; } P_12F918;

extern void func_0012F2A0_0012F918(s32, s32, u8 *);
extern s32 func_0012EFA0(s32, s32);
extern P_12F918 D_15BB90_0012F918[][4];

s32 func_0012F918(s32 port, s32 slot, u8 *data) {
    u8 info[0x80];
    B_12F918 *buf;
    s32 i;

    func_0012F2A0_0012F918(port, slot, info);
    if (info[0x72] != 1) {
        return 0;
    }
    buf = D_15BB90_0012F918[port][slot].x4;
    for (i = 0; i < 6; i++) {
        buf->act[i] = data[i];
    }
    buf->x4 = 1;
    buf->x8 = 6;
    if (func_0012EFA0(port, slot) != 1) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_0012F918 */

/* localdecomp:start func_0012F9E0 */
typedef struct {
    s32 cmd;
    s32 port;
    s32 slot;
    u8 data[8];
    s32 result;
    u8 pad18[0x80 - 0x18];
} Rb_12F9E0;

extern Rb_12F9E0 D_15BD80_0012F9E0;
extern u8 D_15BB40[];
extern s32 func_00122810();
extern s32 func_0012F4F0_0012F9E0(s32, s32, s32);

s32 func_0012F9E0(s32 port, s32 slot, u8 *data)
{
    s32 i;
    Rb_12F9E0 *b = &D_15BD80_0012F9E0;

    b->cmd = 8;
    b->port = port;
    b->slot = slot;
    for (i = 0; i < 6; i++) {
        b->data[i] = data[i];
    }
    if (func_00122810(D_15BB40, 1, 0, b, 0x80, b, 0x80, 0, 0) < 0) {
        return 0;
    }
    if (b->result == 1) {
        func_0012F4F0_0012F9E0(port, slot, 2);
    }
    return b->result;
}
/* localdecomp:end func_0012F9E0 */

/* localdecomp:start func_0012FAB8 */
typedef struct {
    u8 pad0[0x10];
    s32 open;
    u8 pad14[0x1C - 0x14];
} St_12FAB8;

extern St_12FAB8 D_15BB90_12FAB8[2][4];
extern Pd_12F2A0 *func_0012F2A0(s32, s32, Pd_12F2A0 *);

s32 func_0012FAB8(s32 port, s32 slot)
{
    u8 buf[0x80];

    if (D_15BB90_12FAB8[port][slot].open == 0) {
        return 0;
    }
    func_0012F2A0(port, slot, (Pd_12F2A0 *)buf);
    if (buf[0x72] != 1) {
        return 0;
    }
    if (buf[0x64] < 2) {
        return 0;
    }
    if (buf[0x66] < 2) {
        return 0;
    }
    return (u64)buf[0x79] + ((u64)buf[0x7A] << 8) + ((u64)buf[0x7B] << 16) + ((u64)buf[0x7C] << 24);
}
/* localdecomp:end func_0012FAB8 */

/* localdecomp:start func_0012FB68 */
/* libpad: pad RPC command 10 for a port/slot, then follow-up when it answers 1; 2.9-ee-991111 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; s32 x10; } Q_12FB68;

extern s32 func_00122810();
extern void func_0012F4F0_0012FB68(s32, s32, s32);
extern Q_12FB68 D_15BD80_0012FB68;
extern u8 D_15BB40[];

s32 func_0012FB68(s32 port, s32 slot, s32 arg) {
    D_15BD80_0012FB68.x0 = 10;
    D_15BD80_0012FB68.x4 = port;
    D_15BD80_0012FB68.x8 = slot;
    D_15BD80_0012FB68.xC = arg;
    if (func_00122810(D_15BB40, 1, 0, &D_15BD80_0012FB68, 0x80, &D_15BD80_0012FB68, 0x80, 0, 0) < 0) {
        return 0;
    }
    if (D_15BD80_0012FB68.x10 == 1) {
        func_0012F4F0_0012FB68(port, slot, 2);
    }
    return D_15BD80_0012FB68.x10;
}
/* localdecomp:end func_0012FB68 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FC18);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FC78);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012FCD0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012FCE0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FCE8);

/* localdecomp:start func_0012FD50 */
typedef struct {
    s32 x0;
    s32 x4;
} Cmd_12FD50;

extern s32 D_00141560;
extern Cmd_12FD50 D_15BD80_0012FD50;
extern void *D_15BE00;
extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern s32 func_00124920(void);
extern s32 func_00124970(void);

s32 func_0012FD50(s32 en) {
    register void *gp __asm__("$28");
    s32 old;
    s32 i;
    Cmd_12FD50 *p;

    old = D_00141560;
    if (en == 0) {
        p = &D_15BD80_0012FD50;
        p->x0 = 0x18;
        D_00141560 = 0;
        p->x4 = 0;
        while (func_00122810(D_15BB40, 1, 0, p, 0x80, p, 0x80, 0, 0) < 0) {
        }
        return old;
    }
    if (old == 0) {
        p = &D_15BD80_0012FD50;
        p->x0 = 0x18;
        p->x4 = 1;
        while (func_00122810(D_15BB40, 1, 0, p, 0x80, p, 0x80, 0, 0) < 0) {
        }
    }
    i = func_00124920();
    D_15BE00 = gp;
    D_00141560 = en;
    if (i == 1) {
        func_00124970();
    }
    return old;
}
/* localdecomp:end func_0012FD50 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FE78);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FED8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FF08);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FF24);

LINKER_REMNANT("asm/boot_elf/remnants", func_0012FF28);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FF40);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FF64);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012FF68);
