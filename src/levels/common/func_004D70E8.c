#include "common.h"

typedef struct {
    s32 ids[64];
    s32 count;
} S_4D70E8;

typedef struct {
    u8 pad[0xAA];
    s16 id;
} S_4D70E8_Moby;

extern S_4D70E8 D_0024EBF0[];

void func_004D70E8(S_4D70E8_Moby *moby) {
    s32 i;
    s32 found = 0;
    for (i = 0; i < D_0024EBF0->count; i++) {
        if (D_0024EBF0->ids[i] == moby->id) {
            found = 1;
            break;
        }
    }
    if (!found) {
        D_0024EBF0->ids[D_0024EBF0->count] = moby->id;
        D_0024EBF0->count++;
    }
}
