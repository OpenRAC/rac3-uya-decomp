#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 x8;
    u8 pad1[284];
    s32 x128;
} S_1A5E50;

extern S_1A5E50 D_001A5E50;
extern s32 *func_006699B0(s32);
extern s32 func_00669978(s32, s32, s32, s32, s32 *);

void func_00669C50(s32 a0) {
    s32 *p = func_006699B0(a0);

    if (p) {
        S_1A5E50 *g = &D_001A5E50;
        *p = func_00669978(6, a0, g->x128, g->x8, p);
    }
}
