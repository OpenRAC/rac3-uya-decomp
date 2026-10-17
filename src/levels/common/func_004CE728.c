#include "common.h"

extern s32 D_001D545C[];
extern void func_004CD1D0(u8 *, s32);
extern void func_004CE7B0(u8 *, s32);
extern void func_004CADA8(u8 *);

void func_004CE728(u8 *m) {
    s32 i;

    if (D_001D545C[0] != -2) {
        for (i = 0; i < 1; i++) {
            func_004CD1D0(m + 6304 + i * 2896, i);
            func_004CE7B0(m, i);
        }
        func_004CADA8(m + 20176);
    }
}
