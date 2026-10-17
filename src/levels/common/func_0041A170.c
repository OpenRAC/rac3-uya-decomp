#include "common.h"

typedef struct { s32 f0; s32 f4; u8 p8[0x18]; s32 f20; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; u8 p3C[0x28]; s32 f64; s32 f68; u8 p6C[4]; s32 f70; u8 p74[8]; s32 f7C; u8 p80[0x10]; } S_EB;
extern S_EB D_002E6110_0038EB10[];
extern s32 D_001D6694_0038EB10;
extern s32 D_001DFD80_0038EB10;
extern void func_0041A278();
s32 func_0041A170(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    S_EB *s = &D_002E6110_0038EB10[a & 0xF];
    s32 m = a & 0xFFF0;
    if (D_001D6694_0038EB10 == 5 && (a & 0xF) != 2 && (a & 0xF) != 0) return 0;
    if (s->f2C != f || s->f28 != g || s->f20 != b || s->f24 != m || s->f30 != c || s->f34 != d || s->f38 != e) {
        s->f2C = f;
        s->f28 = g;
        s->f20 = b;
        s->f30 = c;
        s->f34 = d;
        s->f38 = e;
        s->f64 = D_001DFD80_0038EB10++;
        s->f68 = 1;
        s->f24 = m;
        s->f7C = 0;
        s->f70 = 0;
        if (m & s->f4 & 0x20) func_0041A278(s);
    }
    return s->f64;
}
