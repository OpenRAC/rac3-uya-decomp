#include "common.h"

typedef struct {
    u8 pad0[34];
    s16 h22;
    s16 h24;
} S_3FE1F0;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    u8 padC[28];
} E_3FE1F0;

typedef struct {
    E_3FE1F0 arr[32];
    s32 n;
} T_3FE1F0;

extern S_3FE1F0 D_001E6540;
extern T_3FE1F0 D_001E68D0;

s32 func_003FE1F0(s32 a0, s32 *a1, s32 *a2) {
    s32 t;
    s32 i;

    *a1 = D_001E6540.h22;
    t = D_001E6540.h24 + a0;
    *a2 = t;
    i = *a1;
    if (i >= 0 && i < D_001E68D0.n) {
        return !(D_001E68D0.arr[i].w8 < D_001E68D0.arr[i].w4 + t);
    }
    return 0;
}
