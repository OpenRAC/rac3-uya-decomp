#include "common.h"

typedef struct {
    f32 v[4];
} Vec4;

typedef struct {
    s32 count;
    s32 pad[3];
    Vec4 items[1];
} VecList;

extern f32 func_003F9190(Vec4 *, void *);

s32 func_00460468(void *a0, VecList *list, f32 target) {
    s32 i;
    s32 best;
    f32 bestVal;
    f32 d;

    best = 0;
    bestVal = 1e11f;
    for (i = 0; i < list->count; i++) {
        d = func_003F9190(&list->items[i], a0);
        if (__builtin_fabsf(d - target) < bestVal) {
            bestVal = d;
            best = i;
        }
    }
    return best;
}
