#include "common.h"

extern s32 func_0011EE60(s32);
extern void func_0011EE40(s32);

typedef struct { long f0; long f8; s32 f10; s32 f14; } S_CCb;
typedef struct { u8 p0[0x40]; s32 f40; u8 p44[0xC]; S_CCb *f50; s32 f54; s32 f58; s32 f5C; } S_CCa;
extern s32 func_0011EE60(s32);
extern void func_0011EE40(s32);
extern s32 func_004D1408();
s32 func_004D1538(S_CCa *a, S_CCb *b) {
    s32 r = 0;
    func_0011EE60(a->f40);
    if (a->f58 < a->f54) {
        func_004D1408(a, b);
        if (b->f0 >= 0 || b->f8 >= 0) {
        a->f50[a->f5C].f0 = b->f0;
        a->f50[a->f5C].f8 = b->f8;
        a->f50[a->f5C].f10 = b->f10;
        a->f50[a->f5C].f14 = b->f14;
        a->f58 = a->f58 + 1;
        a->f5C = (a->f5C + 1) % a->f54;
        }
        r = 1;
    }
    func_0011EE40(a->f40);
    return r;
}
