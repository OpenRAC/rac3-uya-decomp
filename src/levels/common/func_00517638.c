#include "common.h"

extern s32 func_00517638(void *, s32, void *);

extern s32 D_001E24CC_003E67B8;
typedef struct { s32 key; s32 val; } E;
typedef struct { s32 pad; s32 n; E e[3]; } T;
extern s32 func_00515798();
s32 func_00517638(void *pp, s32 k, void *v) {
    T *p = pp;
    if (p->n < 3) {
        if (func_00515798() == 0) {
            s32 i;
            for (i = 0; i < 3; i++) {
                s32 t = (u32)k % 3; s32 b = k & 1;
                s32 idx = (u32)(t + i * (b + 1)) % 3;
                if (p->e[idx].val == 0 || p->e[idx].val == (s32)&D_001E24CC_003E67B8) {
                    p->e[idx].val = (s32)v;
                    p->e[idx].key = k;
                    p->n++;
                    return 1;
                }
            }
        }
    }
    return 0;
}
