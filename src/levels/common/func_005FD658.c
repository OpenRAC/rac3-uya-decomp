#include "common.h"

typedef struct {
    u8 pad[16];
    s32 w10;
} S_5FD658a;

typedef struct {
    u8 pad[36];
    S_5FD658a *p24;
    u8 pad2[152 - 40];
    s32 w98;
} S_5FD658;

extern S_5FD658 *D_002C2940[][4];
extern u8 *D_0024CF20;

void func_005FD658(s32 id) {
    s32 i;
    s32 j;
    S_5FD658 *e;

    for (i = 0; i < 8; i++) {
        if ((&D_0024CF20)[i] == 0 || *(s32 *)((&D_0024CF20)[i] + 9544) != id) {
            for (j = 0; j < 4; j++) {
                e = D_002C2940[i][j];
                if (e != 0) {
                    e->w98 = e->p24->w10;
                }
            }
        }
    }
}
