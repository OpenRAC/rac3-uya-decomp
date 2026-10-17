#include "common.h"

extern s32 D_0024D690[];

void func_00557268(s32 x) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_0024D690[i] == x) {
            D_0024D690[i] = 0;
            return;
        }
    }
}
