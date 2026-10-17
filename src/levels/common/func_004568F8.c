#include "common.h"

extern s32 D_001E0280[2];
extern s32 D_0021FFB8[][156];

void func_004568F8(s32 id, s32 k, f32 amt)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        if (D_001E0280[i] == id) {
            D_0021FFB8[i][k] += (s32)(amt * 32.0f);
        }
    }
}
