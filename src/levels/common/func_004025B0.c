#include "common.h"

extern void func_004025B0(void);
extern s32 D_001E8A00[];

extern s32 D_001DFA10_00385890;
extern void (*D_001E8900[])(s32);
extern s32 D_001E8A00[];
void func_004025B0(void) {
    s32 i;
    for (i = 0; i < D_001DFA10_00385890; i++) D_001E8900[i](D_001E8A00[i]);
}
