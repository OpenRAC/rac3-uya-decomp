#include "common.h"
extern u8 *D_001E009C[];
void func_00448BD8(u8 *a0, s16 *list, s16 max) {
    s16 id = (a0 - D_001E009C[0]) >> 8;
    s32 i;

    for (i = 1; i <= list[0]; i++) {
        if (list[i] == id) {
            return;
        }
    }
    if (list[0] < max) {
        list[0]++;
        list[list[0]] = id;
    }
}
