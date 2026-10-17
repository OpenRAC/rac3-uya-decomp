#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 f8;
    u8 pad1[288];
    s32 f300;
} S_1A5E50;

extern S_1A5E50 D_001A5E50;
extern s32 func_004EC750(s32);
extern s32 func_0053D4F8(s32);

s32 func_0053CF40(s32 a0) {
    S_1A5E50 *p = &D_001A5E50;
    s32 r = a0 % p->f300;
    if (r == p->f8) {
        return 1;
    }
    if (func_004EC750(r) != 0) {
        return 0;
    }
    return func_0053D4F8(r);
}
