#include "common.h"

typedef struct { s32 a; s32 b; s32 c; s32 d; } S_4C49E8;
extern S_4C49E8 D_0024FA60[];

void func_004C49E8(s32 v) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (D_0024FA60[i].b == v) {
            D_0024FA60[i].b = 0;
        }
    }
}
