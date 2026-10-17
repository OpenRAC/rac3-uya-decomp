#include "common.h"

extern s32 func_004C9A70(u8 *, s32);

typedef struct { s32 k, v; } E_3A6830;
s32 func_004C9A70(u8 *p, s32 k) {
    s32 n = *(s32 *)(p + 0x18);
    E_3A6830 *e = (E_3A6830 *)(p + 0x1C);
    s32 i;
    s32 r = 0;
    for (i = 0; i < n; i++) {
        if (e[i].k == k) {
            r = e[i].v;
            break;
        }
    }
    return r;
}
