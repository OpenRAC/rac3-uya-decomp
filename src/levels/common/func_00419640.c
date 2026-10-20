#include "common.h"

extern s32 D_001D5598;
extern u16 D_001A8EC8[];

void func_00419640(u16 id) {
    s32 i;

    for (i = 0; D_001A8EC8[i] != id && i < D_001D5598; i++) {
    }
    if (i < D_001D5598) {
        for (; i < D_001D5598 - 1; i++) {
            D_001A8EC8[i] = D_001A8EC8[i + 1];
        }
        D_001A8EC8[i] = 0;
        D_001D5598--;
    }
    D_001A8EC8[D_001D5598++] = id;
}
