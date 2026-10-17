#include "common.h"

typedef struct {
    u8 pad0[0x180];
    s32 w180;
    u8 pad184[0x4];
    s8 c188;
    u8 pad189[0x6];
    s8 c18F;
    u8 pad190[0x4];
    s8 c194;
    u8 pad195[0x5];
    s8 c19A;
    s8 c19B;
    s8 c19C;
    u8 pad19D[0x2];
    u8 b19F;
} S_675DC8;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 padB[0x6A4 - 0xB];
    s32 w6A4;
} D_00352DE0_t;

extern S_675DC8 *D_002417C0;
extern D_00352DE0_t D_00352DE0;

void func_00675DC8(void) {
    S_675DC8 *s = D_002417C0;

    switch (s->w180) {
    case 0:
        D_00352DE0.b0 = 0;
        D_00352DE0.b1 = 0;
        D_00352DE0.b2 = 1;
        D_00352DE0.b3 = D_00352DE0.w6A4 == 0;
        D_00352DE0.b4 = s->b19F != 0;
        D_00352DE0.b5 = s->c188 != 0;
        D_00352DE0.b6 = s->c18F != 0;
        D_00352DE0.b7 = s->c194 != 0;
        D_00352DE0.b8 = s->c19B == 0;
        D_00352DE0.b9 = s->c19A == 0;
        D_00352DE0.bA = s->c19C == 0;
        break;
    case 1:
        D_00352DE0.b0 = 0;
        D_00352DE0.b1 = 0;
        D_00352DE0.b2 = 0;
        D_00352DE0.b3 = D_00352DE0.w6A4 == 0;
        D_00352DE0.b4 = s->b19F != 0;
        D_00352DE0.b5 = s->c188 != 0;
        D_00352DE0.b6 = s->c18F != 0;
        D_00352DE0.b7 = s->c194 == 0;
        D_00352DE0.b8 = s->c19B == 0;
        D_00352DE0.b9 = s->c19A == 0;
        D_00352DE0.bA = s->c19C == 0;
        break;
    case 2:
        D_00352DE0.b0 = 0;
        D_00352DE0.b1 = 0;
        D_00352DE0.b2 = 0;
        D_00352DE0.b3 = D_00352DE0.w6A4 == 0;
        D_00352DE0.b4 = s->b19F != 0;
        D_00352DE0.b5 = s->c188 != 0;
        D_00352DE0.b6 = s->c18F == 0;
        D_00352DE0.b7 = s->c194 == 0;
        D_00352DE0.b8 = s->c19B == 0;
        D_00352DE0.b9 = s->c19A == 0;
        D_00352DE0.bA = s->c19C == 0;
        break;
    }
}
