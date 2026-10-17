#include "common.h"

typedef int u128_4F1068 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x10];
    u128_4F1068 v10;
} S_4F1068b;

typedef struct {
    u8 pad0[0x80];
    u128_4F1068 v80;
    u8 pad90[0xBF8 - 0x90];
    S_4F1068b *pBF8;
    u8 padBFC[0x25C0 - 0xBFC];
    S_4F1068b *p25C0;
    u8 pad25C4[0x25E4 - 0x25C4];
    u8 b25E4;
} S_4F1068;

extern S_4F1068 D_001A4BE0[];
extern s32 func_004A7200(s32 a0, s32 a1, S_4F1068b *a2);

s32 func_004F1068(s32 a0, s32 a1) {
    S_4F1068 *s = D_001A4BE0;
    if (s->b25E4 == 3) {
        if (s->pBF8 != 0) {
            s->pBF8->v10 = s->v80;
            return func_004A7200(a0, a1, s->pBF8);
        }
    } else {
        return func_004A7200(a0, a1, s->p25C0);
    }
    return -1;
}
