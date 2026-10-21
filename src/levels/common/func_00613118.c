#include "common.h"

extern s32 func_00613118(void *, s32, void *);

extern u8 D_001E1FB4;
typedef struct { s32 key; s32 val; } E;
typedef struct { s32 pad; s32 n; E e[3]; } T;
extern s32 func_00611278();
s32 func_00613118(void *pp, s32 k, void *v) {
    T *p = pp;
    if (p->n < 3) {
        if (func_00611278() == 0) {
            s32 i;
            for (i = 0; i < 3; i++) {
                s32 t = (u32)k % 3; s32 b = k & 1;
                s32 idx = (u32)(t + i * (b + 1)) % 3;
                if (p->e[idx].val == 0 || p->e[idx].val == (s32)(&D_001E1FB4 + 2)) {
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
