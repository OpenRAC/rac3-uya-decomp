#include "common.h"

s32 func_003596C0(u8 **arr, s32 *n, u8 *o) {
    if (*n >= 15) {
        return 0;
    }
    arr[*n] = o;
    (*n)++;
    *(s32 *)(o + 152) = 0;
    return 1;
}
