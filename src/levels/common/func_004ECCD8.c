#include "common.h"

typedef int s128_004ECCD8 __attribute__((mode(TI)));

typedef struct {
    u8 pad[128];
    s128_004ECCD8 out;
    u8 pad2[9972 - 144];
    s32 idx;
    s32 count;
} St_004ECCD8;

extern St_004ECCD8 D_001A4BE0;
extern s128_004ECCD8 D_001A6C20[];
extern s32 func_004EC868(s32);

void func_004ECCD8(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (func_004EC868(i) == 1) {
            return;
        }
        if (D_001A4BE0.count > 1) {
            D_001A4BE0.count--;
            D_001A4BE0.idx = (D_001A4BE0.idx + 31) % 32;
        }
        D_001A4BE0.out = D_001A6C20[D_001A4BE0.idx];
    }
}
