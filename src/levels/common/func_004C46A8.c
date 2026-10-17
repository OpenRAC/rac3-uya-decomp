#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
    s32 pad8[2];
} E_4C46A8;

extern E_4C46A8 D_0024FA60[];

s32 func_004C46A8(s32 a0, s32 a1) {
    s32 i;
    s32 r = 1;
    for (i = 0; i < 32; i++) {
        if (D_0024FA60[i].w4 == a0 && D_0024FA60[i].w0 == a1) {
            r = 0;
            break;
        }
    }
    return r;
}
