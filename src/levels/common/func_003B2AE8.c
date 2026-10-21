#include "common.h"

/* localdecomp:start func_003B2AE8 */
typedef struct {
    s32 x0;
    s32 x4;
    s16 x8;
    s16 xA;
    u16 xC;
    u16 xE;
    s16 x10;
    u16 x12;
    s32 x14;
    s16 x18;
    s16 x1A;
    s32 x1C;
} T_003B2AE8;

typedef struct {
    s32 x0;
    s32 x4;
    u8 pad[232];
} T_003B2AE8_tbl;

extern char *func_004181A0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern void func_004105D8(T_003B2AE8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0040EE10(T_003B2AE8 *, long, char *, s32, unsigned long, f32, f32);
extern void func_00404E18(s32, s32, s32, s32, s32, s32);
extern void func_00432FE8(s32, s32, f32, f32, f32, f32);
extern s32 D_001E1220;
extern f32 D_001E1224;
extern s32 D_001D4BC8;
extern s32 D_001D64E8;
extern char D_002A29F0[];
extern char D_001DE700[];
extern char D_001DE718[];
extern char D_001DE730[];
extern char D_001DE748[];
extern char D_001DE758[];
extern T_003B2AE8_tbl D_002C5640[];

void func_003B2AE8(s32 a0, s32 a1, s32 a2, s32 a3) {
    T_003B2AE8 s;
    u32 color = 0x8066CCFF;
    s32 w, h;
    s32 c;
    s32 x, y;
    s32 v = 256;
    char *t, *u, *m, *n;

    if (a1 || a2 || a3) {
        t = func_004181A0(4700);
        if (a1) {
            if (a3) {
                if (a2) {
                    u = func_004181A0(642);
                    m = func_004181A0(4788);
                    n = func_004181A0((&D_002C5640[a2])->x4);
                    func_0011B2E8(D_002A29F0, D_001DE700, func_004181A0(a0), m, t, n, t, a1, u);
                } else {
                    u = func_004181A0(642);
                    m = func_004181A0(4788);
                    func_0011B2E8(D_002A29F0, D_001DE718, func_004181A0(a0), m, t, a1, u);
                }
            } else {
                if (a2) {
                    u = func_004181A0(642);
                    n = func_004181A0((&D_002C5640[a2])->x4);
                    func_0011B2E8(D_002A29F0, D_001DE730, func_004181A0(a0), t, n, t, a1, u);
                } else {
                    u = func_004181A0(642);
                    func_0011B2E8(D_002A29F0, D_001DE748, func_004181A0(a0), t, a1, u);
                }
            }
        }
    } else {
        func_0011B2E8(D_002A29F0, D_001DE758, func_004181A0(a0));
    }
    {
        f32 z0 = 0.0f, z1 = 0.0f;
        x = (s32)((f32)v * D_001E1224 + 0.5f + (D_001E1220 == 1 ? z0 : z1));
    }
    {
        f32 vv = 384.0f;
        f32 z0 = 0.0f, z1 = 0.0f;
        y = (s32)(vv * D_001E1224 + 0.5f + (D_001E1220 == 1 ? z0 : z1));
    }
    c = D_001D4BC8;
    func_004105D8(&s, x, y, c - 144, c + 144, c, 320, 16, 39);
    s.x18 = 2;
    s.x1A = 2;
    func_0040EE10(&s, color, D_002A29F0, -1, 0x80000000, 1.0f, 1.0f);
    w = ((s16)s.xC / 2) + 8;
    h = ((s16)s.xE / 2) + 8;
    func_00404E18(s.xA - h, s.xA + h, s.x8 - w, s.x8 + w, 51, 0x331465B7);
    func_00432FE8(96, 0x332299DE, s.xA - h, s.xA + h, s.x8 - w, s.x8 + w);
    s.x12 &= 0xFFFB;
    func_0040EE10(&s, color, D_002A29F0, -1, 0x80000000, 1.0f, 1.0f);
    D_001D64E8 = 1;
}
/* localdecomp:end func_003B2AE8 */
