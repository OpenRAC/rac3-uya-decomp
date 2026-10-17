#include "common.h"

typedef struct {
    float f0, f4, f8, fC, f10, f14;
    unsigned char b18, b19;
    short h1A;
    unsigned char b1C, b1D, b1E, b1F;
    char pad20[0x10];
    short h30;
    short h32;
    int w34;
    int w38;
    int w3C;
} Unk3F08D8;

extern Unk3F08D8 D_001E5D10[][32];

Unk3F08D8 *func_003F08D8(int group, int type) {
    Unk3F08D8 *p = D_001E5D10[group];
    int i;
    for (i = 0; i < 32; i++, p++) {
        if (p->b1D == 0) {
            p->f0 = -1.0f;
            p->f4 = -1.0f;
            p->f8 = -1.0f;
            p->fC = -1.0f;
            p->f10 = -1.0f;
            p->f14 = -1.0f;
            p->b1C = type;
            p->w34 = 6;
            p->h32 = 120;
            p->b1D = 1;
            p->w38 = -1;
            p->b18 = 0;
            p->b19 = 0;
            p->h1A = 0;
            p->b1E = 0;
            p->b1F = 0;
            p->w3C = 0;
            p->h30 = 0;
            return p;
        }
    }
    return 0;
}
