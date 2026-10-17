#include "common.h"

extern void func_0012C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_0011F0A0(s32);
extern void func_0012CCC8(void *, void *);
extern s32 func_0012A9F0(s32, s32);
extern void func_0011F0A0();

typedef struct { u8 p0[0x20]; s32 x20; u8 p24[0x10]; s32 x34; } S_1A1ED0_003947B0;
extern S_1A1ED0_003947B0 D_001A1ED0_003947B0;
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
extern void func_0012C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
typedef s32 (*F12C9A0_3947B0)(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_0011F0A0(s32);
extern void func_0012CCC8(void *, void *);
extern s32 func_0012A9F0(s32, s32);
void func_00423B48(u8 *base, s32 n, s32 m, s32 *e) {
    u8 buf[0x60];
    s32 x, r, i, j;
    { S_1A1ED0_003947B0 *g = &D_001A1ED0_003947B0; x = g->x20; }
    D_001D4BB0 = x;
    D_001D4BB4 = x;
    if (n > 0) {
        s32 one = 1;
        i = n;
        do {
            u8 *off = base + e[3];
            s32 lo = e[1] & 0xFFFF;
            s32 hi = e[1] >> 16;
            s32 cur = D_001D4BB0;
            if (e[0] == 0x13) {
                s32 t = lo >> 6;
                s32 k;
                if (t == 0) t = one;
                ((F12C9A0_3947B0)func_0012C9A0)(buf, cur >> 8, t, 0x13, 0, 0, lo, hi);
                k = lo * hi;
                if (k <= 0xFF) k = 0x100;
                D_001D4BB0 += k;
            } else if (e[0] == 2) {
                ((F12C9A0_3947B0)func_0012C9A0)(buf, cur >> 8, 1, 2, 0, 0, 0x10, 0x10);
                D_001D4BB0 += 0x200;
            } else if (e[0] == 0) {
                ((F12C9A0_3947B0)func_0012C9A0)(buf, cur >> 8, 1, 0, 0, 0, 0x10, 0x10);
                D_001D4BB0 += 0x400;
            }
            func_0011F0A0(0);
            i--;
            e += 4;
            func_0012CCC8(buf, off);
            func_0012A9F0(0, 0);
        } while (i != 0);
    }
    r = D_001A1ED0_003947B0.x34;
    D_001D4BB4 = D_001D4BB0;
    if (m > 0) {
        j = m;
        do {
            s32 lo = e[1] & 0xFFFF;
            s32 hi = e[1] >> 16;
            u8 *off = base + e[2];
            s32 t = lo >> 6;
            if (t == 0) t = 1;
            ((F12C9A0_3947B0)func_0012C9A0)(buf, r >> 8, t, 0x1B, 0, 0, lo, hi);
            j--;
            e += 4;
            r += lo * hi * 4;
            func_0011F0A0(0);
            func_0012CCC8(buf, off);
            func_0012A9F0(0, 0);
        } while (j != 0);
    }
}
