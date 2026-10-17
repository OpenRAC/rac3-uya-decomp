#include "common.h"

extern s32 D_001D4BD0[];
extern s32 D_001D4BD4[];
extern void func_00404CB0(unsigned long *, s32);
void func_00404D78(s32 a, s32 b, s32 c, s32 d, unsigned long e, s32 g) {
    unsigned long v[4];
    s32 y = D_001D4BD4[0];
    s32 x = D_001D4BD0[0];
    s32 D = (d << 4) + y - 8;
    s32 C = (c << 4) + x - 8;
    s32 B = (b << 4) + y - 8;
    s32 A = (a << 4) + x - 8;
    v[0] = (unsigned long)A | ((unsigned long)B << 16) | (e << 32);
    v[1] = (unsigned long)C | ((unsigned long)B << 16) | (e << 32);
    v[2] = (unsigned long)A | ((unsigned long)D << 16) | (e << 32);
    v[3] = (unsigned long)C | ((unsigned long)D << 16) | (e << 32);
    func_00404CB0(v, g);
}
