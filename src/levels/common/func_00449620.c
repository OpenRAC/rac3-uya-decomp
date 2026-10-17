#include "common.h"

typedef struct { s32 f0; s16 h4; s16 h6; s32 f8; s32 fC; } S_449620;
extern S_449620 D_002580C0[];

s32 func_00449620(s32 id, s32 *out) {
    s32 i = id & 0x2F;
    if (D_002580C0[i].f8 == id && D_002580C0[i].h6 == -1) {
        *out = D_002580C0[i].fC;
        return 1;
    }
    return 0;
}
