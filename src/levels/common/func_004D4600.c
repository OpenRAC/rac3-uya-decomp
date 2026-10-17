#include "common.h"

extern s32 D_001DB92C;
extern s32 D_001DB928;
extern s32 D_001E1318[];
extern s8 D_001E1340[];
void func_004D4600(s32 n, s32 *p, s32 v) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (i < n) D_001E1318[i] = p[i];
        else D_001E1318[i] = -1;
        D_001E1340[i] = 0;
        }
    D_001DB92C = v;
    D_001DB928 = n;
}
