#include "common.h"

extern s32 D_001DF880[2];
extern void (*D_001DF840[2])(s32);
void func_003F12C0(s32 a) {
    s32 i;
    s32 *c = D_001DF880;
    for (i = 0; i < c[a]; i++) D_001DF840[a * 16 + i](a);
    D_001DF880[a] = 0;
}
