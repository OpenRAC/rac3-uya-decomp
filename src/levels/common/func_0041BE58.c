#include "common.h"

/* localdecomp:start func_0041BE58 */
typedef struct S_38EC18 {
    s32 pad0;
    s32 v4, v8, vC;
    void (*f10)(struct S_38EC18 *);
    s32 v14, v18, pad1C;
    s32 a20, a24, a28, a2C;
    void (*a30)(struct S_38EC18 *);
    s32 a34, a38;
    s32 pad3C[11];
    s32 x68;
} S_38EC18;
extern s32 D_001D680C;
extern s32 D_001DFE24;
extern s32 D_001DFE28;
extern s32 D_001DFE20;
extern void func_00416618(void);
extern void func_004165D0(void);
extern s32 func_004A7368(s32, s32, s32);
extern f32 func_0040C490(f32, f32);
extern s32 func_0041A370(s32);

/* func_0041BE58 (src/frontbin/3896E8.c, 0x4E8): MATCH with try_func.py and try_in_context.py.
 * Flags: S mode + @ps2as, a single-function override in an N range: text_parts lines
 *   0x00390730 -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as   # single-function override
 *   0x00390C18 -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses
 * Aliases (symbol_addrs_resolved.txt): D_001DFDE0_00390730 = 0x1D9F68; D_001DFDE8_00390730 = 0x1D9F70;
 *   D_001DF9C8_00390730 = 0x1D9C48; D_001A4BE0_00390730 = 0x1A4BE0;  (divs_nops.txt line already exists)
 * Fix over the 9-diff g2 draft: the angle statement without the do { } while (0) wrap, with the first
 * "ang + PI" as its own local before the D_001DFDE0 read: f32 a = ang + PI; s32 n = D_001DFDE0; p->f74 = ...
 * (gives retail's add.s/cvt/constant-load schedule and FP registers). Prototypes: func_004A7368 is s32 (as defined
 * in 39DB38.c), func_0041A370 is s32(s32). Volatile D_001D6880..2C reads kept from the earlier draft.
 */
typedef struct { u8 p0[0x64]; s32 f64; u8 p68[4]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_390730;
typedef struct { u8 p0[0x148]; f32 f148; f32 f14C; u8 p150[0x70]; s32 f1C0; s32 f1C4; s32 f1C8; s32 f1CC; } P_390730;
typedef struct { u8 p0[8]; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; } T_390730;
typedef struct { u8 p0[0x286C]; s32 f286C; } G_390730;
extern P_390730 *D_001D52FC_00390730;
extern s16 D_001DFDAC;
extern s16 D_001DFDB0;
extern s16 D_001DFDB2;
extern s16 D_001DFDB4;
extern s32 D_001DFDE0_00390730;
extern s32 D_001DFDE8_00390730;
extern s32 D_001DF9C8_00390730;
extern volatile s32 D_001D6880;
extern volatile s32 D_001D6884;
extern volatile s32 D_001D6888;
extern volatile s32 D_001D688C;
extern s32 D_001DFE20;
extern s32 D_001DFE24;
extern s32 D_001DFE28;
extern u8 D_00143A06[];
extern G_390730 D_001A4BE0_00390730;
extern void func_00416618(void);
extern f32 func_0040C490(f32, f32);
extern s32 func_00440BA8(s32, s32, s32, s32, s32, s32);
extern s32 func_004A7368(s32, s32, s32);
extern void func_004165D0(void);
extern s32 func_0041A370(s32);
void func_0041BE58(S_390730 *p) {
    u8 *b = p->b70;
    f32 x, y, len, ang;
    s32 old;
    func_00416618();
    p->f7C = 180;
    p->f6C = 24;
    {
        P_390730 *pd = D_001D52FC_00390730;
        pd->f1CC = 2;
        x = pd->f148;
        y = pd->f14C;
    }
    __asm__("sqrt.s %0, %1" : "=f"(len) : "f"(x * x + y * y));
    if (len != 0.0f) {
        x = x / len;
        y = y / len;
    }
    ang = func_0040C490(x, y);
    if ((p->f78 >> 24) == 0 && D_001DFDAC != 0) {
        if ((D_001D52FC_00390730->f1C4 & 0xF000) || len < 0.5f || (p->f78 = p->f78 - 1) == -1) {
            p->f74 = -1;
            p->f78 = 0x10000FF;
        }
    }
    old = p->f74;
    if (((s8 *)&p->f78)[3] == 1) {
        if (0.0f < len) {
            if (0.9f < len) {
                s32 n;
                f32 a;
                a = ang + 3.1415927f;
                n = D_001DFDE0_00390730;
                a = a + 3.1415927f;
                p->f74 = (s32)((a + 1.5707964f + 3.1415927f / (f32)n) * ((f32)n / 6.2831855f)) % n;
            }
        } else {
            if (D_001D52FC_00390730->f1C4 & 0xF000) {
                s32 sel = old;
                s32 t;
                if (D_001D52FC_00390730->f1C4 & 0x1000) {
                    if (sel == -1) t = D_001D6888; else t = ((T_390730 *)(((s32 *)D_001DFDE8_00390730)[D_001D680C] + sel * 0x1C))->f10; sel = t;
                }
                if (D_001D52FC_00390730->f1C4 & 0x4000) {
                    if (sel == -1) t = D_001D688C; else t = ((T_390730 *)(((s32 *)D_001DFDE8_00390730)[D_001D680C] + sel * 0x1C))->f14; sel = t;
                }
                if (D_001D52FC_00390730->f1C4 & 0x8000) {
                    if (sel == -1) t = D_001D6880; else t = ((T_390730 *)(((s32 *)D_001DFDE8_00390730)[D_001D680C] + sel * 0x1C))->f8; sel = t;
                }
                if (D_001D52FC_00390730->f1C4 & 0x2000) {
                    if (sel == -1) t = D_001D6884; else t = ((T_390730 *)(((s32 *)D_001DFDE8_00390730)[D_001D680C] + sel * 0x1C))->fC; sel = t;
                }
                p->f74 = sel;
            }
        }
    }
    if (p->f74 != old) {
        func_00440BA8(0, 0, 1, 0, 1, 0);
        b[1] = 0;
        func_004A7368(3, 0, 0);
    } else {
        if (b[1] < 8) b[1]++;
    }
    if (!(D_001D52FC_00390730->f1C0 & 0x10)) {
        if (D_001D52FC_00390730->f1C8 & 0x10) {
            if (p->f74 == -1) D_001A4BE0_00390730.f286C = 0;
            else D_001A4BE0_00390730.f286C = ((T_390730 *)(((s32 *)D_001DFDE8_00390730)[D_001D680C] + p->f74 * 0x1C))->f18;
        }
        if (D_00143A06[0] != 0) func_004165D0();
        if (b[0]) b[0]--;
    } else {
        if (b[0] < 8) b[0]++;
    }
    if (D_001A4BE0_00390730.f286C == 6 && D_001DFDB0 == 0) D_001A4BE0_00390730.f286C = 0;
    if (D_001A4BE0_00390730.f286C == 7 && D_001DFDB4 == 0) D_001A4BE0_00390730.f286C = 0;
    if (D_001A4BE0_00390730.f286C == 5 && D_001DFDB2 == 0) D_001A4BE0_00390730.f286C = 0;
    if (b[0] == 0) {
        D_001DFE28 = p->f74;
        D_001DFE24 = p->f78;
        func_0041A370(p->f64);
        p->f6C = -6;
        D_001DFE20 = D_001DF9C8_00390730;
    }
}
/* localdecomp:end func_0041BE58 */
