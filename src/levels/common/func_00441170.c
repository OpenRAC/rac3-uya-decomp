#include "common.h"

typedef struct {
    s16 ids[12];
} Entry_00441170;

extern Entry_00441170 D_001DA5E8[];
extern u16 D_001A1F18[];

void func_00441170(u8 *a0, s32 a1) {
    s32 found = -1;
    s32 i;
    s32 j;
    u16 *p;

    for (i = 0; i < 64; i++) {
        for (j = 0; j < 4; j++) {
            if (*(s16 *)(a0 + 170) == D_001DA5E8[i].ids[j]) {
                found = i;
                break;
            }
        }
        if (found != -1) {
            break;
        }
    }
    if (found == -1) {
        return;
    }
    if (a1 == 0) {
        p = D_001A1F18 + found * 2;
    } else if (a1 == 1) {
        p = D_001A1F18 + found * 2 + a1;
    } else {
        return;
    }
    if (*p < 9999) {
        *p = *p + 1;
    }
}
