#include "common.h"

typedef struct {
    u8 pad0[0xA0];
    f32 fA0;
    u8 padA4[0xC];
    f32 fB0;
    u8 padB4[0x210 - 0xB4];
    f32 f210;
} S_30FC10;

extern unsigned long func_003DABB0(s32 id);
extern f32 func_003E4260(f32 x);
extern s32 D_001E0144;
extern s32 D_001E0148;
extern s32 D_001E014C;
extern s32 D_001E0150;
extern S_30FC10 D_001E5EC0;
extern unsigned long D_0026ECE0[];

void func_0030FC10(u8 *b) {
    s32 i;
    s32 w;
    unsigned long tex;
    unsigned long tbw;
    f32 f;
    unsigned long mm;

    D_0026ECE0[0] = 0x1000000000008000UL;
    D_0026ECE0[1] = 0xE;
    i = 2;
    D_0026ECE0[i++] = ((unsigned long)b[0x33] << 32) | (b[0x39] ? 0x68 : 0x64);
    D_0026ECE0[i++] = 0x42;
    D_0026ECE0[i++] = ((unsigned long)b[0x37] << 32) | 0x64;
    D_0026ECE0[i++] = 0x43;
    D_0026ECE0[i++] = 0x50000;
    D_0026ECE0[i++] = 0x47;
    D_0026ECE0[i++] = 0x51001;
    D_0026ECE0[i++] = 0x48;
    D_0026ECE0[i++] = 0;
    D_0026ECE0[i++] = 8;
    D_0026ECE0[i++] = 0;
    D_0026ECE0[i++] = 9;
    D_0026ECE0[i++] = 0x60;
    D_0026ECE0[i++] = 0x15;
    D_0026ECE0[i++] = b[0x3A] | ((unsigned long)b[0x3B] << 8) | ((unsigned long)b[0x3C] << 16);
    D_0026ECE0[i++] = 0x3D;
    D_001E0148 = 0;
    D_001E014C = 0;
    D_001E0150 = 0;
    w = 0;
    if (*(s32 *)b >= 0) {
        tex = func_003DABB0(*(s32 *)b + 100);
        w = 1 << ((tex >> 26) & 0xF);
        tbw = (tex >> 14) & 0x3F;
        if ((s8)b[0x64] >= 0) {
            tbw = (tbw + 1) >> 1;
            D_001E0148 = 1;
            D_001E014C |= (s32)tbw << 14;
            if ((s8)b[0x65] >= 0) {
                tbw = (tbw + 1) >> 1;
                D_001E0148 = 2;
                if ((s8)b[0x66] >= 0) {
                    tbw = (tbw + 1) >> 1;
                    D_001E0148 = 3;
                    if ((s8)b[0x67] >= 0) {
                        tbw = (tbw + 1) >> 1;
                        D_001E0148 = 4;
                        D_001E0150 |= (s32)tbw << 14;
                        if ((s8)b[0x68] >= 0) {
                            D_001E0148 = 5;
                            if ((s8)b[0x69] >= 0) {
                                D_001E0148 = 6;
                            }
                        }
                    }
                }
            }
        }
    }
    if (D_001E0148 > 0) {
        f = func_003E4260(*(f32 *)(b + 0x24) * D_001E5EC0.f210 * 1024.0f / ((f32)w * D_001E5EC0.fB0 * D_001E5EC0.fA0));
        mm = 4;
        if (b[0x6A]) {
            mm = 5;
        }
        D_0026ECE0[i++] = ((unsigned long)D_001E0148 << 2) | 0x20 | (mm << 6) | ((unsigned long)(s32)((*(f32 *)(b + 0x60) - f) * 16.0f) << 32);
        D_0026ECE0[i++] = 0x14;
    } else {
        D_0026ECE0[i++] = 0x60;
        D_0026ECE0[i++] = 0x14;
    }
    D_001E0144 = i >> 1;
    D_0026ECE0[0] |= (i >> 1) - 1;
}
